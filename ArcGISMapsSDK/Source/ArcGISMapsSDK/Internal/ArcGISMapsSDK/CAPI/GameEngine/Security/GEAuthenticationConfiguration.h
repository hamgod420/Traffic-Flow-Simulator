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

#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfigurationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfigurationType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEAuthenticationConfiguration_destroy(RT_GEAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEAuthenticationConfigurationType RT_GEAuthenticationConfiguration_getObjectType(const RT_GEAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif