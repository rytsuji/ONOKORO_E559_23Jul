#ifndef TOPTICSCALIBRATIONROCESSOR_H
#define TOPTICSCALIBRATIONROCESSOR_H


#include "TProcessor.h"
#include "TEventCollection.h"
#include "TOpticsData.h"
#include "TMWDCTrackingResult.h"
#include "TTrack.h"
#include <vector>

namespace art {
  class TOpticsCalibrationProcessor;
}

class TClonesArray;

class art::TOpticsCalibrationProcessor : public TProcessor {
public:
  TOpticsCalibrationProcessor();
  virtual ~TOpticsCalibrationProcessor();
  
  virtual void Init(TEventCollection *col);
  virtual void Process();

protected:  
  TString fNameInput;
  TString fNameOutput;
  //TString fParameterName;
  TClonesArray **fInput;//!                                                                                                                                 
  TClonesArray *fOutput;//!                                                                                                                                  
  Int_t fVerbose;

  Parameter<TString> fInputFileDelta;
  Parameter<TString> fInputFileA;
  Parameter<TString> fInputFileB;

  Bool_t kInputFileDelta;
  Bool_t kInputFileA;
  Bool_t kInputFileB;
  
  std::vector<Double_t> prm_delta;
  std::vector<Double_t> order_delta_x;
  std::vector<Double_t> order_delta_y;
  std::vector<Double_t> order_delta_a;
  std::vector<Double_t> order_delta_b;

  std::vector<Double_t> prm_a;
  std::vector<Double_t> order_a_x;
  std::vector<Double_t> order_a_y;
  std::vector<Double_t> order_a_a;
  std::vector<Double_t> order_a_b;

  std::vector<Double_t> prm_b;
  std::vector<Double_t> order_b_x;
  std::vector<Double_t> order_b_y;
  std::vector<Double_t> order_b_a;
  std::vector<Double_t> order_b_b;
  
private:
  
  ClassDef(TOpticsCalibrationProcessor,1) 
};

#endif
