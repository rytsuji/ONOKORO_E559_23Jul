/**
 * @file   TVDCFPTrackingProcessor.h
 * @brief based on TMWDCTrackingProcessor
 *
 * @date   Created:       2023-03-02 19:01:37 JST
 *         Last Modified: 2023-03-02 23:52:11 JST
 * @author Shinsuke OTA <ota@rcnp.osaka-u.ac.jp>
 *
 *    Copyright (C) 2023 OTA Shinsuke All rights reserved
 */

#ifndef TVDCTRACKINGPROCESSOR_H
#define TVDCTRACKINGPROCESSOR_H

#include "TMWDCTrackingProcessor.h"

namespace art {
   class TVDCFPTrackingProcessor;
   class TMWDCTrackingResult;
   class TVDCCluster;
}


class art::TVDCFPTrackingProcessor: public art::TMWDCTrackingProcessor {
public:
   using planeSet_t = std::vector<TVDCCluster*>;
   virtual void Process();
   virtual void ProcessOne(const planeSet_t& planeData);
   virtual void FindTrack(const std::vector<TVDCCluster*>& planes, TMWDCTrackingResult *tr, bool doFillStatus);
   
   TVDCFPTrackingProcessor();
   virtual ~TVDCFPTrackingProcessor();

protected:
  Parameter<Double_t> fSearchTimeWidth; 
  Parameter<Double_t> fOffsetX; // unit of mm                                                                                                           
  Parameter<Double_t> fOffsetY; // unit of mm                                                                                                           
  Parameter<Double_t> fOffsetZ; // unit of mm                                                                                                           
  Parameter<Double_t> fFPTiltedAngleY; // unit of deg                                                                                                   
  //Parameter<Double_t> fVDCTiltedAngleX; // unit of deg                                                                                               
  Parameter<Double_t> fVDCTiltedAngleY; // unit of deg                                                                                                  
  //Parameter<Double_t> fVDCTiltedAngleZ; // unit of deg   
   ClassDef(TVDCFPTrackingProcessor,0) // vdc tracking processor
};



#endif //TVDCTRACKINGPROCESSOR_H
