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
#include "TVDCClusterizationProcessor_mod.h"
#include "TVDCTrackingProcessor_mod.h"
#include "TTimingChargeMultiHitMappingProcessor.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_artcLcLTVDCClusterizationProcessor_mod(void *p = nullptr);
   static void *newArray_artcLcLTVDCClusterizationProcessor_mod(Long_t size, void *p);
   static void delete_artcLcLTVDCClusterizationProcessor_mod(void *p);
   static void deleteArray_artcLcLTVDCClusterizationProcessor_mod(void *p);
   static void destruct_artcLcLTVDCClusterizationProcessor_mod(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TVDCClusterizationProcessor_mod*)
   {
      ::art::TVDCClusterizationProcessor_mod *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TVDCClusterizationProcessor_mod >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TVDCClusterizationProcessor_mod", ::art::TVDCClusterizationProcessor_mod::Class_Version(), "TVDCClusterizationProcessor_mod.h", 24,
                  typeid(::art::TVDCClusterizationProcessor_mod), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TVDCClusterizationProcessor_mod::Dictionary, isa_proxy, 4,
                  sizeof(::art::TVDCClusterizationProcessor_mod) );
      instance.SetNew(&new_artcLcLTVDCClusterizationProcessor_mod);
      instance.SetNewArray(&newArray_artcLcLTVDCClusterizationProcessor_mod);
      instance.SetDelete(&delete_artcLcLTVDCClusterizationProcessor_mod);
      instance.SetDeleteArray(&deleteArray_artcLcLTVDCClusterizationProcessor_mod);
      instance.SetDestructor(&destruct_artcLcLTVDCClusterizationProcessor_mod);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TVDCClusterizationProcessor_mod*)
   {
      return GenerateInitInstanceLocal((::art::TVDCClusterizationProcessor_mod*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TVDCClusterizationProcessor_mod*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_artcLcLTVDCTrackingProcessor_mod(void *p = nullptr);
   static void *newArray_artcLcLTVDCTrackingProcessor_mod(Long_t size, void *p);
   static void delete_artcLcLTVDCTrackingProcessor_mod(void *p);
   static void deleteArray_artcLcLTVDCTrackingProcessor_mod(void *p);
   static void destruct_artcLcLTVDCTrackingProcessor_mod(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::art::TVDCTrackingProcessor_mod*)
   {
      ::art::TVDCTrackingProcessor_mod *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::art::TVDCTrackingProcessor_mod >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("art::TVDCTrackingProcessor_mod", ::art::TVDCTrackingProcessor_mod::Class_Version(), "TVDCTrackingProcessor_mod.h", 24,
                  typeid(::art::TVDCTrackingProcessor_mod), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::art::TVDCTrackingProcessor_mod::Dictionary, isa_proxy, 4,
                  sizeof(::art::TVDCTrackingProcessor_mod) );
      instance.SetNew(&new_artcLcLTVDCTrackingProcessor_mod);
      instance.SetNewArray(&newArray_artcLcLTVDCTrackingProcessor_mod);
      instance.SetDelete(&delete_artcLcLTVDCTrackingProcessor_mod);
      instance.SetDeleteArray(&deleteArray_artcLcLTVDCTrackingProcessor_mod);
      instance.SetDestructor(&destruct_artcLcLTVDCTrackingProcessor_mod);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::art::TVDCTrackingProcessor_mod*)
   {
      return GenerateInitInstanceLocal((::art::TVDCTrackingProcessor_mod*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::art::TVDCTrackingProcessor_mod*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
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

namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TVDCClusterizationProcessor_mod::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TVDCClusterizationProcessor_mod::Class_Name()
{
   return "art::TVDCClusterizationProcessor_mod";
}

//______________________________________________________________________________
const char *TVDCClusterizationProcessor_mod::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationProcessor_mod*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TVDCClusterizationProcessor_mod::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationProcessor_mod*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVDCClusterizationProcessor_mod::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationProcessor_mod*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVDCClusterizationProcessor_mod::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCClusterizationProcessor_mod*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace art
namespace art {
//______________________________________________________________________________
atomic_TClass_ptr TVDCTrackingProcessor_mod::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TVDCTrackingProcessor_mod::Class_Name()
{
   return "art::TVDCTrackingProcessor_mod";
}

//______________________________________________________________________________
const char *TVDCTrackingProcessor_mod::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingProcessor_mod*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TVDCTrackingProcessor_mod::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingProcessor_mod*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVDCTrackingProcessor_mod::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingProcessor_mod*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVDCTrackingProcessor_mod::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::art::TVDCTrackingProcessor_mod*)nullptr)->GetClass(); }
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
void TVDCClusterizationProcessor_mod::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TVDCClusterizationProcessor_mod.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TVDCClusterizationProcessor_mod::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TVDCClusterizationProcessor_mod::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTVDCClusterizationProcessor_mod(void *p) {
      return  p ? new(p) ::art::TVDCClusterizationProcessor_mod : new ::art::TVDCClusterizationProcessor_mod;
   }
   static void *newArray_artcLcLTVDCClusterizationProcessor_mod(Long_t nElements, void *p) {
      return p ? new(p) ::art::TVDCClusterizationProcessor_mod[nElements] : new ::art::TVDCClusterizationProcessor_mod[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTVDCClusterizationProcessor_mod(void *p) {
      delete ((::art::TVDCClusterizationProcessor_mod*)p);
   }
   static void deleteArray_artcLcLTVDCClusterizationProcessor_mod(void *p) {
      delete [] ((::art::TVDCClusterizationProcessor_mod*)p);
   }
   static void destruct_artcLcLTVDCClusterizationProcessor_mod(void *p) {
      typedef ::art::TVDCClusterizationProcessor_mod current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TVDCClusterizationProcessor_mod

namespace art {
//______________________________________________________________________________
void TVDCTrackingProcessor_mod::Streamer(TBuffer &R__b)
{
   // Stream an object of class art::TVDCTrackingProcessor_mod.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(art::TVDCTrackingProcessor_mod::Class(),this);
   } else {
      R__b.WriteClassBuffer(art::TVDCTrackingProcessor_mod::Class(),this);
   }
}

} // namespace art
namespace ROOT {
   // Wrappers around operator new
   static void *new_artcLcLTVDCTrackingProcessor_mod(void *p) {
      return  p ? new(p) ::art::TVDCTrackingProcessor_mod : new ::art::TVDCTrackingProcessor_mod;
   }
   static void *newArray_artcLcLTVDCTrackingProcessor_mod(Long_t nElements, void *p) {
      return p ? new(p) ::art::TVDCTrackingProcessor_mod[nElements] : new ::art::TVDCTrackingProcessor_mod[nElements];
   }
   // Wrapper around operator delete
   static void delete_artcLcLTVDCTrackingProcessor_mod(void *p) {
      delete ((::art::TVDCTrackingProcessor_mod*)p);
   }
   static void deleteArray_artcLcLTVDCTrackingProcessor_mod(void *p) {
      delete [] ((::art::TVDCTrackingProcessor_mod*)p);
   }
   static void destruct_artcLcLTVDCTrackingProcessor_mod(void *p) {
      typedef ::art::TVDCTrackingProcessor_mod current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::art::TVDCTrackingProcessor_mod

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

namespace {
  void TriggerDictionaryInitialization_libe559_Impl() {
    static const char* headers[] = {
"TVDCClusterizationProcessor_mod.h",
"TVDCTrackingProcessor_mod.h",
"TTimingChargeMultiHitMappingProcessor.h",
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
namespace art{class __attribute__((annotate(R"ATTRDUMP(processor for MWDC plane division)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVDCClusterizationProcessor_mod.h")))  TVDCClusterizationProcessor_mod;}
namespace art{class __attribute__((annotate(R"ATTRDUMP(vdc tracking processor)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TVDCTrackingProcessor_mod.h")))  TVDCTrackingProcessor_mod;}
namespace art{class __attribute__((annotate(R"ATTRDUMP(processor for mapping timine and charge data for multi hit data)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TTimingChargeMultiHitMappingProcessor.h")))  TTimingChargeMultiHitMappingProcessor;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libe559 dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TVDCClusterizationProcessor_mod.h"
#include "TVDCTrackingProcessor_mod.h"
#include "TTimingChargeMultiHitMappingProcessor.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"art::TTimingChargeMultiHitMappingProcessor", payloadCode, "@",
"art::TVDCClusterizationProcessor_mod", payloadCode, "@",
"art::TVDCTrackingProcessor_mod", payloadCode, "@",
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
