#include "TOpticsCalibrationProcessor.h"
//#include "TDataObject.h"
#include "constant.h"
#include <TClonesArray.h>
#include <TClass.h>
#include <fstream>
#include <sstream>

using art::TOpticsCalibrationProcessor;


ClassImp(TOpticsCalibrationProcessor)

TOpticsCalibrationProcessor::TOpticsCalibrationProcessor()
: fOutput(NULL)
{

  Register(fInputFileDelta("InputFileDelta","input file for optics matrix element of delta",""));
  Register(fInputFileA("InputFileA","input file for optics matrix element of A",""));
  Register(fInputFileB("InputFileB","input file for optics matrix element of B",""));



  RegisterInputCollection("InputCollection",
                           "input collection",
                           fNameInput, "mwdc_track",
			  &fInput, TClonesArray::Class_Name(),
			  art::TMWDCTrackingResult::Class_Name());

  RegisterOutputCollection("OutputCollection","output collection",
                            fNameOutput,"optics",
                            &fOutput, TClonesArray::Class_Name(),
                            art::TOpticsData::Class_Name());
}


TOpticsCalibrationProcessor::~TOpticsCalibrationProcessor()
{
  delete fOutput;
}

void TOpticsCalibrationProcessor::Init(TEventCollection*){

  std::ifstream infileDelta((std::string) ((TString) fInputFileDelta));
  std::ifstream infileA((std::string) ((TString) fInputFileA));
  std::ifstream infileB((std::string) ((TString) fInputFileB));
  std::string iline;
  
  while(getline(infileDelta,iline)){
    if(iline[0] == '#'){
      //skip
    }
    else{
      std::istringstream iss(iline);
      std::string str[5];
      iss >> str[0] >> str[1] >> str[2] >> str[3] >> str[4];
      order_delta_x.push_back(std::stod(str[0]));
      order_delta_y.push_back(std::stod(str[1]));
      order_delta_a.push_back(std::stod(str[2]));
      order_delta_b.push_back(std::stod(str[3]));
      prm_delta.push_back(std::stod(str[4]));
    }    
  }


  
  
}

void TOpticsCalibrationProcessor::Process(){

  fOutput->Clear("C");
  //(*fInput)->Sort();
  Bool_t kProcessed = kFALSE;
  const Int_t nData = (*fInput)->GetEntriesFast();

  
  
  
  if (nData < 1) {
    //if (fVerbose) std::cout << "Multiplicity is" << nData << ", cannot process" << std::endl;
    kProcessed = kFALSE;    
  }
  else {
    kProcessed = kTRUE;
    Double_t Delata=0;
    Double_t A=0;
    Double_t B=0;
    
    for (Int_t iData = 0; iData != nData; ++iData) {
      
      //TOpticsData *const outData = fOutData->ConstructedAt(iData);
      TOpticsData *outData = NULL;
      outData = static_cast<TOpticsData*>(fOutput->ConstructedAt(iData));
      const TMWDCTrackingResult *const inData = static_cast<TMWDCTrackingResult*>((*fInput)->At(iData));
      const TTrack *const track= dynamic_cast<const TTrack*> (inData->GetTrack());
      
      Double_t fX = track->GetX();
      Double_t fY = track->GetY();
      Double_t fA = (track->GetA())*1000;
      Double_t fB = (track->GetB())*1000;
      
      
      Double_t Delta;
      Double_t A;
      Double_t B;
      
      for(int i=0; i<prm_delta.size(); i++){
	Delta+=prm_delta[i]*pow(fX,order_delta_x[i])*pow(fY,order_delta_y[i])*pow(fA,order_delta_a[i])*pow(fB,order_delta_b[i]);
      }
      
      
      
      
      outData->SetDelta(Delta);
      outData->SetA(A);
      outData->SetB(B);
      outData->SetProcessed(kProcessed);
    }
  }
  
  return;
}
