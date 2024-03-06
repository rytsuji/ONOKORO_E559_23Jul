/**
 * @file   TVDCCluster.cc
 * @brief
 *
 * @date   Created:       2013-08-14 10:34:09
 *         Last Modified: 2014-01-08 12:56:45
 * @author KAWASE Shoichiro <kawase@cns.s.u-tokyo.ac.jp>
 *
 *    Copyright (C) 2013 KAWASE Shoichiro All rights reserved.
 */

#include "TVDCClusterMeanCharge.h"
#include "constant.h"

#include <iostream>
#include <TClass.h>

using art::TVDCClusterMeanCharge;

ClassImp(art::TVDCClusterMeanCharge)

Int_t TVDCClusterMeanCharge::fSortType  = TVDCClusterMeanCharge::kID;
Int_t TVDCClusterMeanCharge::fSortOrder = TVDCClusterMeanCharge::kDESC;

// Default constructor
TVDCClusterMeanCharge::TVDCClusterMeanCharge() 
   : fTiming(kInvalidD), fCharge(kInvalidD),Clust_ID(kInvalidD),valid_cluster2(kInvalidD),valid_cluster(kInvalidD),fClust_Size(kInvalidD),fHitID(0),fHitDL(0),fHitTiming(0),fHitLR(0){
   TDataObject::SetID(kInvalidI);
}

TVDCClusterMeanCharge::~TVDCClusterMeanCharge() {
}

// Copy constructor
TVDCClusterMeanCharge::TVDCClusterMeanCharge(const TVDCClusterMeanCharge& rhs)
   : TDataObject(rhs), fTiming(rhs.fTiming), fCharge(rhs.fCharge) {
}
void TVDCClusterMeanCharge::Print(Option_t*) const {
/*  std::cout << "OBJ: " << IsA()->GetName() << "\t"
	 << "TrackingID: " << GetID() << "\t"
	 << "nParameter: " << GetNParameter() << "\t"
	 << "SSR: " << GetSSR() << "\t"
	 << "TimeCost: " << GetTimeCost() << std::endl;
	 */
  printf("aaa\n");
}

void TVDCClusterMeanCharge::Init() {


	 fHitID.resize(20);
	 fHitDL.resize(20);
	 fHitTiming.resize(20);
	 fHitLR.resize(20);
  Clear();
}
void TVDCClusterMeanCharge::Init2(int size) {


	 fHitID.resize(size);
	 fHitDL.resize(size);
	 fHitTiming.resize(size);
	 fHitLR.resize(size);
  Clear();
}
// Assignment operator
/*TVDCClusterMeanCharge& TVDCClusterMeanCharge::operator=(const TVDCClusterMeanCharge& rhs) {
   if (this != &rhs) {
      ((TVDCClusterMeanCharge&)rhs).Copy(*this);
   }
   return *this;
}
*/
/*

void TVDCClusterMeanCharge::Clear(Option_t *opt) {
   TDataObject::Clear(opt);
   TDataObject::SetID(kInvalidI);
   this->SetTiming(kInvalidD);
   this->SetCharge(kInvalidD);
}
*/
