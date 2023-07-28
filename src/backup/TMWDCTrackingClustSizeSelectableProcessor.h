/**
 * @file   TMWDCTrackingClustSizeSelectableProcessor.h
 * @brief
 *
 * @date   Created:       2013-10-19 16:59:46
 *         Last Modified: 2023-03-02 21:22:20 JST
 * @author KAWASE Shoichiro <kawase@cns.s.u-tokyo.ac.jp>
 *
 *    Copyright (C) 2013 KAWASE Shoichiro All rights reserved
 */

#ifndef TMWDCTRACKINGCLUSTSIZESELECTABLEPROCESSOR_H
#define TMWDCTRACKINGCLUSTSIZESELECTABLEPROCESSOR_H

#include <vector>

#include <TProcessor.h>

#include "TMultiHitCombinator.h"

namespace art {
   class TMWDCTrackingClustSizeSelectableProcessor;
   class TMWDCPlaneInfo;
   class TMWDCHitData;
   class TMWDCTrackingResult;
}

class TClonesArray;
class TStopwatch;
template <typename T> class TMatrixT;
typedef TMatrixT<double> TMatrixD;

class art::TMWDCTrackingClustSizeSelectableProcessor : public TProcessor {
public:
   typedef std::vector< std::vector<TMWDCHitData*> > planeSet_t;
   // Default constructor
   TMWDCTrackingClustSizeSelectableProcessor();
   virtual ~TMWDCTrackingClustSizeSelectableProcessor();

   virtual void Init(TEventCollection *col);
   virtual void Process();
   virtual void ProcessOne(const planeSet_t& planeData);
   
protected:
   StringVec_t fInputColName;
   TString fOutputColName;
   std::vector<TClonesArray**> *fPlaneIn; //!
   std::vector<TMWDCPlaneInfo*> *fPlaneInfo; //! TODO: separate this vector into small ones
   TClonesArray *fMWDCTrackOut;
   Int_t fTrackingMethod;
   Int_t fNPlane;
   Int_t fNPlaneValid;
   Int_t fNParameter;
   TMatrixD *fGMatrix;
   TMatrixD *fHMatrix;
   TMatrixD *fCovariantMatrix;
   const TMWDCHitData **fPlaneData; //!
   Int_t fUseLocalPos;

   FloatVec_t fTimingGate;
   FloatVec_t fChargeGate;

   Float_t fSSRMax;

   Double_t *fCos; //[fNPlane]
   Double_t *fSin; //[fNPlane]
   Double_t *fZ;   //[fNPlane]

   Double_t *fX;   //[fNPlane]
   Double_t *fY;   //[fNPlane]

   TStopwatch *fStopwatch; //!

   Bool_t fUseAllCombination;
   Float_t fSignificanceLevel;

   TMultiHitCombinator *fCombinator;

   virtual void GenerateMatrix();
   virtual void FindTrack(TMWDCTrackingResult*, Bool_t);
   virtual Double_t CalcSSR(const std::vector<Double_t>&,
			    const std::vector<Double_t>&,
			    std::vector<Double_t>&) const;
//   virtual void FillCombinator();
   virtual Int_t FindBestCombination(TMWDCTrackingResult*);
   virtual Bool_t DataIsValid(const TMWDCHitData*) const;
   virtual Bool_t CombinationIsValid() const;

   static const Int_t MIN_NPLANE = 3;
   static const Int_t CRITICAL_NPLANE = 4;

private:
   // Copy constructor (prohibited)
   TMWDCTrackingClustSizeSelectableProcessor(const TMWDCTrackingClustSizeSelectableProcessor&);
   // Assignment operator (prohibited)
   TMWDCTrackingClustSizeSelectableProcessor& operator=(const TMWDCTrackingClustSizeSelectableProcessor&);


   ClassDef(TMWDCTrackingClustSizeSelectableProcessor,0) // processor for MWDC tracking
};

#endif // TMWDCTRACKINGCLUSTSIZESELECTABLEPROCESSOR_H
