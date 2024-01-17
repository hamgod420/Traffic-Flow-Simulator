// COPYRIGHT 1995-2023 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Attn: Contracts and Legal Department
// Environmental Systems Research Institute, Inc.
// 380 New York Street
// Redlands, California 92373
// USA
//
// email: legal@esri.com
#pragma once

#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallengeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallengeType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEAuthenticationChallenge_destroy(RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEAuthenticationChallengeType RT_GEAuthenticationChallenge_getObjectType(const RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEAuthenticationChallenge_cancel(RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif