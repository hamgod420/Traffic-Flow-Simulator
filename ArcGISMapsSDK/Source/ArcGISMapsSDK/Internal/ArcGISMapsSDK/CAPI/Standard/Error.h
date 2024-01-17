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

#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Error_destroy(RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_Error_getAdditionalMessage(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_Error_getCode(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Error_getMessage(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_Error_getUnderlyingError(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);
void* RT_Error_getUserDefinedFailure(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif