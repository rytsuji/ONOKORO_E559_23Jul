#ifndef TVDCTRAKINGSORTPROCESSOR_H 
#define TVDCTRAKINGSORTPROCESSOR_H

#include "TProcessor.h"
#include "TMWDCTrackingResult.h"

namespace art{
  class TVDCTrackingSortProcessor;
}

class TConesArray;

class art::TVDCTrackingSortProcessor : public TProcessor{
 public:
  TVDCTrackingSortProcessor();
  virtual ~TVDCTrackingSortProcessor();
  
  virtual void Init();
  virtual void Process();

 protectd:
  TString fNameInput1;
  TString fNameInput2;
  TString fNameInput3;
  TString fNameInput4;
  TString fNameOutput;

 private:

  ClassDef(TVDCTrackingSortProcessor,1)

}

#endif
