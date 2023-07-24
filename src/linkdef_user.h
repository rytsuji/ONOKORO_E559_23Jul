/**
 * @file   linkdef_user.h
 * @brief
 *
 * @date   Created:       2022.07.18
 *         Last Modified: 2023.01.03
 * @author Yuto HIJIKATA
 *
 *    Copyright (C) 2022 Yuto HIJIKATA
 */
#ifndef LINKDEF_USER_H
#define LINKDEF_USER_H


#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class art::TVDCClusterizationSizeSelectableProcessor+;
#pragma link C++ class art::TVDCTrackingProcessor_mod+;
#pragma link C++ class art::TTimingChargeMultiHitMappingProcessor+;
#pragma link C++ class art::TTimeTrefValidator+;

#endif // __CINT__

#endif // LINKDEF_USER_H
