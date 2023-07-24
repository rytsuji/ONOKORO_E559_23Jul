/**
 * @file   TVDCTrackingProcessor_mod.h
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
   class TVDCTrackingProcessor_mod;
   class TMWDCTrackingResult;
   class TVDCCluster;
}


class art::TVDCTrackingProcessor_mod: public art::TMWDCTrackingProcessor {
public:
   using planeSet_t = std::vector<TVDCCluster*>;
   virtual void Process();
   virtual void ProcessOne(const planeSet_t& planeData);
   virtual void FindTrack(const std::vector<TVDCCluster*>& planes, TMWDCTrackingResult *tr, bool doFillStatus);
   
   TVDCTrackingProcessor_mod();
   virtual ~TVDCTrackingProcessor_mod();

protected:
   Parameter<Double_t> fSearchTimeWidth;
   Parameter<Double_t> fTiltedAngleX; // unit of deg  
   Parameter<Double_t> fTiltedAngleY; // unit of deg
   Parameter<Double_t> fTiltedAngleZ; // unit of deg

   ClassDef(TVDCTrackingProcessor_mod,0) // vdc tracking processor
};



#endif //TVDCTRACKINGPROCESSOR_H
