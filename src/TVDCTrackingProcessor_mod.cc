/**
 * @file   TVDCTrackingProcessor_mod.h
 * @brief based on TMWDCTrackingProcessor
 *
 * @date   Created:       2023-03-02 19:01:37 JST
 *         Last Modified: 2023-03-03 00:09:00 JST
 * @author Shinsuke OTA <ota@rcnp.osaka-u.ac.jp>
 *
 *    Copyright (C) 2023 OTA Shinsuke All rights reserved
 */

#include "TVDCTrackingProcessor_mod.h"
#include "TMWDCTrackingResult.h"
#include "TMWDCParameter.h"
#include "TMWDCPlaneInfo.h"
#include "TVDCCluster.h"


#include "TStopwatch.h"
#include "TClonesArray.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TVector3.h"

#include <numeric>

ClassImp(art::TVDCTrackingProcessor_mod)

art::TVDCTrackingProcessor_mod::TVDCTrackingProcessor_mod()
{
   Register(fSearchTimeWidth("SearchTimeWidth","search window width of timestamp",10));
   Register(fTiltedAngleX("TiltedAngleX","tilted angle of whole system along x axis in deg",0));
   Register(fTiltedAngleY("TiltedAngleY","tilted angle of whole system along y axis in deg",45));
   Register(fTiltedAngleZ("TiltedAngleZ","tilted angle of whole system along z axis in deg",0));
}

art::TVDCTrackingProcessor_mod::~TVDCTrackingProcessor_mod()
{
}



void art::TVDCTrackingProcessor_mod::Process()
{


  //   Info("Process","========== New Event ==========");
   fStopwatch->Start();
   fMWDCTrackOut->Clear("C");
   /* modified by Ryotaro Tsuji*/   

   std::vector<std::vector<TVDCCluster*>> planeSets;


   //int nHit_max=0;

   //for (int iPlane = 0; iPlane < fNPlane; ++iPlane) {
   //TClonesArray* plane = *(fPlaneIn->at(iPlane));
   //int nHits = plane->GetEntriesFast();
   //nHit_max=std::max(nHit_max,nHits);
   // }

   //std::vector<std::vector<TVDCCluster*>> planeSets(nHit_max);
   //planeSets.resize(5);
   /* end */
   
   // find cluster combination
   for (int iPlane = 0; iPlane < fNPlane; ++iPlane) {
     TClonesArray* plane = *(fPlaneIn->at(iPlane));
     if (fVerboseLevel > 2) printf("=== %d clusters ===\n",plane->GetEntries());
     for (int iHit = 0, nHits = plane->GetEntriesFast(); iHit < nHits; ++iHit) {


       TVDCCluster* planeCluster = (TVDCCluster*)plane->At(iHit);
       //	 printf("iPlane = %d, iHit = %d, %p\n",iPlane,iHit,planeCluster);
       planeCluster->SetAuxID(iPlane);
       //planeCluster->SetAuxID(AuxID);
       
       if (fVerboseLevel > 2)  printf("Hit Pos = %10f,  Timestamp = %20f\n",planeCluster->GetHitPos(),planeCluster->GetTimestamp());
       
       /* modified by Ryotaro Tsuji*/
       //printf("before first hit");
       //if (iPlane == 0) {
       if (iPlane == 0 && planeCluster->GetClustnum()>3) {
	 //this is the first hit
	 planeSets.push_back(std::vector<TVDCCluster*>(1,planeCluster));
     	 continue;
       }
	 
       for (auto& aSet : planeSets) {
	 if (fVerboseLevel > 2)  printf("iPlane[%d] Timestamp = %20f %20f Width = %20f\n",iPlane,planeCluster->GetTimestamp(),aSet[0]->GetTimestamp(),fSearchTimeWidth.Value());
	 //if (abs(planeCluster->GetTimestamp() - aSet[0]->GetTimestamp()) < fSearchTimeWidth.Value()) {
	 if (abs(planeCluster->GetTimestamp() - aSet[0]->GetTimestamp()) < fSearchTimeWidth.Value() && planeCluster->GetClustnum() > 3) {
	   aSet.push_back(planeCluster);
	   break;
	 }
       }
     }
   }

   
   if (fVerboseLevel > 2) Info("Process","num of sets = %d",planeSets.size());
   
   // check required planes
   for (auto it = planeSets.begin(); it != planeSets.end(); ) {
     // Info("Process","size of sets = %d",it->size());
     if (it->size() < 4) {
       it = planeSets.erase(it);
     } else {
       ++it;
     }
   }
   
   for (auto& planes : planeSets) {
     //      Info("Process","planes size = %d",planes.size());
     ProcessOne(planes);
   }

}


void art::TVDCTrackingProcessor_mod::ProcessOne(const std::vector<TVDCCluster*>& planes)
{
   TMWDCTrackingResult *tr = (TMWDCTrackingResult*)fMWDCTrackOut->ConstructedAt(fMWDCTrackOut->GetEntriesFast());

   //tr->Init(fNPlane);
   //tr->SetNPlaneValid(fNPlane);
   int plane_size=planes.size();
   tr->Init(plane_size);
   tr->SetNPlaneValid(plane_size);
   tr->SetTimestamp(planes[0]->GetTimestamp());
   tr->SetNParameter(fNParameter);
   tr->SetNCombination(1);

   FindTrack(planes,tr,true);
   
}

void art::TVDCTrackingProcessor_mod::FindTrack(const std::vector<TVDCCluster*>& planes, TMWDCTrackingResult *tr, bool doFillStat)
{

  // Info("FindTrack","enter");
  int Plane_size=planes.size();
  //int Plane_size=fNPlane; 
  std::vector<Double_t> pos(Plane_size), trackPrm(fNParameter);
  std::vector<Double_t> bestTrackPrm(fNParameter,0);
  std::vector<Double_t> residual(Plane_size,0);
  std::vector<Double_t> bestResidual(Plane_size,0);
   
   //   for (int iPlane = 0; iPlane != fNPlane; ++iPlane) {
   for (int i = 0, n = planes.size(); i < n; ++i) {
      TVDCCluster* planeData = planes[i];
      int iPlane = planeData->GetAuxID();
      const Double_t cos = fCos[iPlane];
      const Double_t sin = fSin[iPlane];
      const Double_t x   = fX[iPlane];
      const Double_t y   = fY[iPlane];
      
      //const TMWDCPlaneInfo &planeInfo = *fPlaneInfo->at(iPlane);
      const TMWDCPlaneInfo &planeInfo = *fPlaneInfo->at(iPlane);
      const Double_t cellSize = planeInfo.GetCellSize();
      const Double_t center   = planeInfo.GetCenter();
      // printf("[%d] planeData = %p\n",iPlane,planeData);
      pos[iPlane] = (planeData->GetHitPos() - center) * cellSize + x * cos + y * sin;
      //pos[i] = (planeData->GetHitPos() - center) * cellSize + x * cos + y * sin;
   }
   
   // Info("FindTrack","plane info done");
   const TMatrixD &g = *fGMatrix;
   // Info("FindTrack","matrix is prepared");
   for (Int_t iParameter = 0; iParameter!=fNParameter; ++iParameter) {
      // calculate pos[] \dot g[iParameter][]
      trackPrm[iParameter] = std::inner_product(pos.begin(),pos.end(),
                                                g[iParameter].GetPtr(),0.);
   }

   // Info("FindTrack","trackprm is calculated");
   
   const Double_t SSR = CalcSSR(pos,trackPrm,residual);
   std::copy(trackPrm.begin(),trackPrm.end(),bestTrackPrm.begin());
   std::copy(residual.begin(),residual.end(),bestResidual.begin());
   

   if (fNParameter == 2) {
       tr->SetTrack(bestTrackPrm[0],bestTrackPrm[1],0,0,0);
   } else {

      TVector3 vec(bestTrackPrm[2],bestTrackPrm[3],1);
//      vec.Print();
      vec.RotateX(fTiltedAngleY*TMath::DegToRad());
      vec.RotateY(fTiltedAngleY*TMath::DegToRad());
      vec.RotateZ(fTiltedAngleY*TMath::DegToRad());
//      vec.Print();
      
      tr->SetTrack(bestTrackPrm[0],bestTrackPrm[1],0,
                   vec.X()/vec.Z(),
                   vec.Y()/vec.Z());
   }
   tr->SetSSR(SSR);

   //for(Int_t i=0;i!=fNPlane;++i){
   // tr->SetWireIDAdopted(i,->GetDetID());
   // tr->SetDriftLengthAdopted(i,fPlaneData[i]->GetDriftLength());
   // tr->SetResidual(i,bestResidual[i]);
   //}
   

   if (SSR < fSSRMax) {
      tr->SetTrackingID(TMWDCTrackingResult::kGood);
      if (doFillStat) { /* fill statistical information */
	 const Int_t ndf = fNPlaneValid - fNParameter;
	 const Double_t standardCI = fNPlaneValid > CRITICAL_NPLANE + 1 ?  TMath::StudentQuantile(1.- fSignificanceLevel/2., ndf) : 0;
	 const Double_t usv = SSR/ndf; // sample variance
	 const TMatrixD &cov = *fCovariantMatrix;
	 for (Int_t i = 0; i != fNParameter; ++i) {
	    const Double_t var   = cov[i][i] * usv;
	    const Double_t sigma = TMath::Sqrt(var);
	    const Double_t CI    = standardCI * sigma;
	    tr->SetSigma(i,sigma);
	    tr->SetVar(i,var);
	    tr->SetCI(i,CI);
	 }
      }
   } else {
      tr->SetTrackingID(TMWDCTrackingResult::kLargeSSR);
   }
   
}
