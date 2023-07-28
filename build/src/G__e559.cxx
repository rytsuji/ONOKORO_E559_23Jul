// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__e559
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "TVDCClusterizationSizeSelectableProcessor.h"
#include "TVDCTrackingXZRotatableProcessor.h"
#include "TTimingChargeMultiHitMappingProcessor.h"
#include "TTimeTrefValidator.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p = nullptr);
   static void *newArray_artcLcLTVDCClusterizationSizeSelectableProcessor(Long_t size, void *p);
   static void delete_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p);
   static void deleteArray_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p);
   static void destruct_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TVDCClusterizationSizeSelectableProcessor*)
   {
      ::art::TVDCClusterizationSizeSelectableProcessor *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TVDCClusterizationSizeSelectableProcessor >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TVDCClusterizationSizeSelectableProcessor", ::art::TVDCClusterizationSizeSelectableProcessor::Class_Version(), "TVDCClusterizationSizeSelectableProcessor.h", 24,
                  typeid(::art::TVDCClusterizationSizeSelectableProcessor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TVDCClusterizationSizeSelectableProcessor::Dictionary, isa_proxy, 4,
                  sizeof(::art::TVDCClusterizationSizeSelectableProcessor) );
      instance.SetNew(&new_artcLcLTVDCClusterizationSizeSelectableProcessor);
      instance.SetNewArray(&newArray_artcLcLTVDCClusterizationSizeSelectableProcessor);
      instance.SetDelete(&delete_artcLcLTVDCClusterizationSizeSelectableProcessor);
      instance.SetDeleteArray(&deleteArray_artcLcLTVDCClusterizationSizeSelectableProcessor);
      instance.SetDestructor(&destruct_artcLcLTVDCClusterizationSizeSelectableProcessor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TVDCClusterizationSizeSelectableProcessor*)
   {
      return GenerateInitInstanceLocal((::art::TVDCClusterizationSizeSelectableProcessor*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TVDCClusterizationSizeSelectableProcessor*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_artcLcLTVDCTrackingXZRotatableProcessor(void *p = nullptr);
   static void *newArray_artcLcLTVDCTrackingXZRotatableProcessor(Long_t size, void *p);
   static void delete_artcLcLTVDCTrackingXZRotatableProcessor(void *p);
   static void deleteArray_artcLcLTVDCTrackingXZRotatableProcessor(void *p);
   static void destruct_artcLcLTVDCTrackingXZRotatableProcessor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TVDCTrackingXZRotatableProcessor*)
   {
      ::art::TVDCTrackingXZRotatableProcessor *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TVDCTrackingXZRotatableProcessor >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TVDCTrackingXZRotatableProcessor", ::art::TVDCTrackingXZRotatableProcessor::Class_Version(), "TVDCTrackingXZRotatableProcessor.h", 26,
                  typeid(::art::TVDCTrackingXZRotatableProcessor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TVDCTrackingXZRotatableProcessor::Dictionary, isa_proxy, 4,
                  sizeof(::art::TVDCTrackingXZRotatableProcessor) );
      instance.SetNew(&new_artcLcLTVDCTrackingXZRotatableProcessor);
      instance.SetNewArray(&newArray_artcLcLTVDCTrackingXZRotatableProcessor);
      instance.SetDelete(&delete_artcLcLTVDCTrackingXZRotatableProcessor);
      instance.SetDeleteArray(&deleteArray_artcLcLTVDCTrackingXZRotatableProcessor);
      instance.SetDestructor(&destruct_artcLcLTVDCTrackingXZRotatableProcessor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TVDCTrackingXZRotatableProcessor*)
   {
      return GenerateInitInstanceLocal((::art::TVDCTrackingXZRotatableProcessor*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TVDCTrackingXZRotatableProcessor*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_artcLcLTTimingChargeMultiHitMappingProcessor(void *p = nullptr);
   static void *newArray_artcLcLTTimingChargeMultiHitMappingProcessor(Long_t size, void *p);
   static void delete_artcLcLTTimingChargeMultiHitMappingProcessor(void *p);
   static void deleteArray_artcLcLTTimingChargeMultiHitMappingProcessor(void *p);
   static void destruct_artcLcLTTimingChargeMultiHitMappingProcessor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TTimingChargeMultiHitMappingProcessor*)
   {
      ::art::TTimingChargeMultiHitMappingProcessor *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TTimingChargeMultiHitMappingProcessor >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TTimingChargeMultiHitMappingProcessor", ::art::TTimingChargeMultiHitMappingProcessor::Class_Version(), "TTimingChargeMultiHitMappingProcessor.h", 24,
                  typeid(::art::TTimingChargeMultiHitMappingProcessor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TTimingChargeMultiHitMappingProcessor::Dictionary, isa_proxy, 4,
                  sizeof(::art::TTimingChargeMultiHitMappingProcessor) );
      instance.SetNew(&new_artcLcLTTimingChargeMultiHitMappingProcessor);
      instance.SetNewArray(&newArray_artcLcLTTimingChargeMultiHitMappingProcessor);
      instance.SetDelete(&delete_artcLcLTTimingChargeMultiHitMappingProcessor);
      instance.SetDeleteArray(&deleteArray_artcLcLTTimingChargeMultiHitMappingProcessor);
      instance.SetDestructor(&destruct_artcLcLTTimingChargeMultiHitMappingProcessor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TTimingChargeMultiHitMappingProcessor*)
   {
      return GenerateInitInstanceLocal((::art::TTimingChargeMultiHitMappingProcessor*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TTimingChargeMultiHitMappingProcessor*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_artcLcLTTimeTrefValidator(void *p = nullptr);
   static void *newArray_artcLcLTTimeTrefValidator(Long_t size, void *p);
   static void delete_artcLcLTTimeTrefValidator(void *p);
   static void deleteArray_artcLcLTTimeTrefValidator(void *p);
   static void destruct_artcLcLTTimeTrefValidator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TTimeTrefValidator*)
   {
      ::art::TTimeTrefValidator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TTimeTrefValidator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TTimeTrefValidator", ::art::TTimeTrefValidator::Class_Version(), "TTimeTrefValidator.h", 23,
                  typeid(::art::TTimeTrefValidator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TTimeTrefValidator::Dictionary, isa_proxy, 4,
                  sizeof(::art::TTimeTrefValidator) );
      instance.SetNew(&new_artcLcLTTimeTrefValidator);
      instance.SetNewArray(&newArray_artcLcLTTimeTrefValidator);
      instance.SetDelete(&delete_artcLcLTTimeTrefValidator);
      instance.SetDeleteArray(&deleteArray_artcLcLTTimeTrefValidator);
      instance.SetDestructor(&destruct_artcLcLTTimeTrefValidator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TTimeTrefValidator*)
   {
      return GenerateInitInstanceLocal((::art::TTimeTrefValidator*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TTimeTrefValidator*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TVDCClusterizationSizeSelectableProcessor::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TVDCClusterizationSizeSelectableProcessor::Class_Name()
{
   return "art::TVDCClusterizationSizeSelectableProcessor";
}

//______________________________________________________________________________
const char *TVDCClusterizationSizeSelectableProcessor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationSizeSelectableProcessor*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TVDCClusterizationSizeSelectableProcessor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationSizeSelectableProcessor*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVDCClusterizationSizeSelectableProcessor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationSizeSelectableProcessor*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVDCClusterizationSizeSelectableProcessor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationSizeSelectableProcessor*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace art
namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TVDCTrackingXZRotatableProcessor::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TVDCTrackingXZRotatableProcessor::Class_Name()
{
   return "art::TVDCTrackingXZRotatableProcessor";
}

//______________________________________________________________________________
const char *TVDCTrackingXZRotatableProcessor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingXZRotatableProcessor*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TVDCTrackingXZRotatableProcessor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingXZRotatableProcessor*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVDCTrackingXZRotatableProcessor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingXZRotatableProcessor*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVDCTrackingXZRotatableProcessor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingXZRotatableProcessor*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace art
namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TTimingChargeMultiHitMappingProcessor::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TTimingChargeMultiHitMappingProcessor::Class_Name()
{
   return "art::TTimingChargeMultiHitMappingProcessor";
}

//______________________________________________________________________________
const char *TTimingChargeMultiHitMappingProcessor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TTimingChargeMultiHitMappingProcessor*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TTimingChargeMultiHitMappingProcessor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TTimingChargeMultiHitMappingProcessor*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTimingChargeMultiHitMappingProcessor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TTimingChargeMultiHitMappingProcessor*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTimingChargeMultiHitMappingProcessor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TTimingChargeMultiHitMappingProcessor*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace art
namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TTimeTrefValidator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TTimeTrefValidator::Class_Name()
{
   return "art::TTimeTrefValidator";
}

//______________________________________________________________________________
const char *TTimeTrefValidator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TTimeTrefValidator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TTimeTrefValidator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TTimeTrefValidator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTimeTrefValidator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TTimeTrefValidator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTimeTrefValidator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TTimeTrefValidator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace art
namespace art {
//______________________________________________________________________________
void TVDCClusterizationSizeSelectableProcessor::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TVDCClusterizationSizeSelectableProcessor.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TVDCClusterizationSizeSelectableProcessor::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TVDCClusterizationSizeSelectableProcessor::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p) {
      return  p ? new(p) ::art::TVDCClusterizationSizeSelectableProcessor : new ::art::TVDCClusterizationSizeSelectableProcessor;
   }
   static void *newArray_artcLcLTVDCClusterizationSizeSelectableProcessor(Long_t nElements, void *p) {
      return p ? new(p) ::art::TVDCClusterizationSizeSelectableProcessor[nElements] : new ::art::TVDCClusterizationSizeSelectableProcessor[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p) {
      delete ((::art::TVDCClusterizationSizeSelectableProcessor*)p);
   }
   static void deleteArray_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p) {
      delete [] ((::art::TVDCClusterizationSizeSelectableProcessor*)p);
   }
   static void destruct_artcLcLTVDCClusterizationSizeSelectableProcessor(void *p) {
      typedef ::art::TVDCClusterizationSizeSelectableProcessor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TVDCClusterizationSizeSelectableProcessor

namespace art {
//______________________________________________________________________________
void TVDCTrackingXZRotatableProcessor::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TVDCTrackingXZRotatableProcessor.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TVDCTrackingXZRotatableProcessor::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TVDCTrackingXZRotatableProcessor::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTVDCTrackingXZRotatableProcessor(void *p) {
      return  p ? new(p) ::art::TVDCTrackingXZRotatableProcessor : new ::art::TVDCTrackingXZRotatableProcessor;
   }
   static void *newArray_artcLcLTVDCTrackingXZRotatableProcessor(Long_t nElements, void *p) {
      return p ? new(p) ::art::TVDCTrackingXZRotatableProcessor[nElements] : new ::art::TVDCTrackingXZRotatableProcessor[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTVDCTrackingXZRotatableProcessor(void *p) {
      delete ((::art::TVDCTrackingXZRotatableProcessor*)p);
   }
   static void deleteArray_artcLcLTVDCTrackingXZRotatableProcessor(void *p) {
      delete [] ((::art::TVDCTrackingXZRotatableProcessor*)p);
   }
   static void destruct_artcLcLTVDCTrackingXZRotatableProcessor(void *p) {
      typedef ::art::TVDCTrackingXZRotatableProcessor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TVDCTrackingXZRotatableProcessor

namespace art {
//______________________________________________________________________________
void TTimingChargeMultiHitMappingProcessor::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TTimingChargeMultiHitMappingProcessor.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TTimingChargeMultiHitMappingProcessor::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TTimingChargeMultiHitMappingProcessor::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTTimingChargeMultiHitMappingProcessor(void *p) {
      return  p ? new(p) ::art::TTimingChargeMultiHitMappingProcessor : new ::art::TTimingChargeMultiHitMappingProcessor;
   }
   static void *newArray_artcLcLTTimingChargeMultiHitMappingProcessor(Long_t nElements, void *p) {
      return p ? new(p) ::art::TTimingChargeMultiHitMappingProcessor[nElements] : new ::art::TTimingChargeMultiHitMappingProcessor[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTTimingChargeMultiHitMappingProcessor(void *p) {
      delete ((::art::TTimingChargeMultiHitMappingProcessor*)p);
   }
   static void deleteArray_artcLcLTTimingChargeMultiHitMappingProcessor(void *p) {
      delete [] ((::art::TTimingChargeMultiHitMappingProcessor*)p);
   }
   static void destruct_artcLcLTTimingChargeMultiHitMappingProcessor(void *p) {
      typedef ::art::TTimingChargeMultiHitMappingProcessor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TTimingChargeMultiHitMappingProcessor

namespace art {
//______________________________________________________________________________
void TTimeTrefValidator::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TTimeTrefValidator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TTimeTrefValidator::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TTimeTrefValidator::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTTimeTrefValidator(void *p) {
      return  p ? new(p) ::art::TTimeTrefValidator : new ::art::TTimeTrefValidator;
   }
   static void *newArray_artcLcLTTimeTrefValidator(Long_t nElements, void *p) {
      return p ? new(p) ::art::TTimeTrefValidator[nElements] : new ::art::TTimeTrefValidator[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTTimeTrefValidator(void *p) {
      delete ((::art::TTimeTrefValidator*)p);
   }
   static void deleteArray_artcLcLTTimeTrefValidator(void *p) {
      delete [] ((::art::TTimeTrefValidator*)p);
   }
   static void destruct_artcLcLTTimeTrefValidator(void *p) {
      typedef ::art::TTimeTrefValidator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TTimeTrefValidator

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 339,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      ::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<float>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)nullptr)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace {
  void TriggerDictionaryInitialization_libe559_Impl() {
    static const char* headers[] = {
"TVDCClusterizationSizeSelectableProcessor.h",
"TVDCTrackingXZRotatableProcessor.h",
"TTimingChargeMultiHitMappingProcessor.h",
"TTimeTrefValidator.h",
nullptr
    };
    static const char* includePaths[] = {
"/home/quser/local/root/v6.26.10/include",
"/home/tsuji/work/art_analysis/e559_23jul/src",
"/home/quser/local/root/v6.26.10/include",
"/home/tsuji/work/art_analysis/e559_23jul/src",
"/home/quser/local/artemis/artemis-e559/include/.",
"/home/quser/local/artemis/artemis-e559/include",
"/home/quser/local/yaml-cpp/yaml-cpp-0.6.3/include",
"/home/quser/local/root/v6.26.10/include/",
"/home/tsuji/work/art_analysis/e559_23jul/build/src/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libe559 dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace art{class __attribute__((annotate(R"ATTRDUMP(processor for MWDC plane division)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVDCClusterizationSizeSelectableProcessor.h")))  TVDCClusterizationSizeSelectableProcessor;}
namespace art{class __attribute__((annotate(R"ATTRDUMP(vdc tracking processor)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVDCTrackingXZRotatableProcessor.h")))  TVDCTrackingXZRotatableProcessor;}
namespace art{class __attribute__((annotate(R"ATTRDUMP(processor for mapping timine and charge data for multi hit data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTimingChargeMultiHitMappingProcessor.h")))  TTimingChargeMultiHitMappingProcessor;}
namespace art{class __attribute__((annotate(R"ATTRDUMP(validate time in certain window)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTimeTrefValidator.h")))  TTimeTrefValidator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libe559 dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TVDCClusterizationSizeSelectableProcessor.h"
#include "TVDCTrackingXZRotatableProcessor.h"
#include "TTimingChargeMultiHitMappingProcessor.h"
#include "TTimeTrefValidator.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"art::TTimeTrefValidator", payloadCode, "@",
"art::TTimingChargeMultiHitMappingProcessor", payloadCode, "@",
"art::TVDCClusterizationSizeSelectableProcessor", payloadCode, "@",
"art::TVDCTrackingXZRotatableProcessor", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libe559",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libe559_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libe559_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libe559() {
  TriggerDictionaryInitialization_libe559_Impl();
}
