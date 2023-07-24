/**
 * @file   TTimeTrefValidator.h
 * @brief  validate time or timestamp  in certain window
 *
 * @date   Created       : 2015-11-17 13:51:53 JST
 *         Last Modified : 2018-02-04 13:15:23 JST (ota)
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *
 *
 *    (C) 2015 Shinsuke OTA
 */

#ifndef TTIMETREFVALIDATOR_H
#define TTIMETREFVALIDATOR_H

#include "TProcessor.h"

namespace art {
   class TTimeTrefValidator;
}
class TClonesArray;

class art::TTimeTrefValidator : public TProcessor {
public:
   TTimeTrefValidator();
   virtual ~TTimeTrefValidator();

   TTimeTrefValidator(const TTimeTrefValidator& rhs);
   TTimeTrefValidator& operator=(const TTimeTrefValidator& rhs);

protected:
   virtual void Init(TEventCollection *col);
   virtual void Process();
private:
  TString fInputName1; // name of input collection
  TString fInputName2; // name of input collection
  TString fOutputName; // name of output collection
  TClonesArray **fInput1; //! input
  TClonesArray **fInput2; //! input
  TClonesArray  *fOutput; //! output
  
  //   Int_t fTimeVariable; // 0 time 1 timestamp
  FloatVec_t fValidTimeRange;
  Float_t fValidTimeMin;
  Float_t fValidTimeMax;
   
  
  ClassDef(TTimeTrefValidator,1) // validate time in certain window
};

#endif // TTIMETREFVALIDATOR_H

