/**
 * @file   TVDCTrackingPlaneSelectableProcessor.h
 * @brief based on TMWDCTrackingProcessor
 *
 * @date   Created:       2023-03-02 19:01:37 JST
 *         Last Modified: 2023-03-02 23:52:11 JST
 * @author Shinsuke OTA <ota@rcnp.osaka-u.ac.jp>
 *
 *    Copyright (C) 2023 OTA Shinsuke All rights reserved
 */

#ifndef TVDCTRACKINPLANESELECTABLEPROCESSOR_H
#define TVDCTRACKINPLANESELECTABLEPROCESSOR_H

//#include "TMWDCTrackingProcessor.h"
#include "TMWDCTrackingClustSizeSelectableProcessor.h"

namespace art {
   class TVDCTrackingPlaneSelectableProcessor;
   class TMWDCTrackingResult;
   class TVDCCluster;
}



//class art::TVDCTrackingPlaneSelectableProcessor: public art::TMWDCTrackingProcessor {
class art::TVDCTrackingPlaneSelectableProcessor: public art::TMWDCTrackingClustSizeSelectableProcessor {
public:
   using planeSet_t = std::vector<TVDCCluster*>;
   virtual void Process();
   virtual void ProcessOne(const planeSet_t& planeData);
   virtual void FindTrack(const std::vector<TVDCCluster*>& planes, TMWDCTrackingResult *tr, bool doFillStatus);
   
   TVDCTrackingPlaneSelectableProcessor();
   virtual ~TVDCTrackingPlaneSelectableProcessor();

protected:
  Parameter<Double_t> fSearchTimeWidth;
  Parameter<Double_t> fTiltedAngleX; // unit of deg
  Parameter<Double_t> fTiltedAngleY; // unit of deg
  Parameter<Double_t> fTiltedAngleZ; // unit of deg
  ClassDef(TVDCTrackingPlaneSelectableProcessor,0) // vdc tracking processor
};



#endif // TVDCTRACKINPLANESELECTABLEPROCESSOR_H
