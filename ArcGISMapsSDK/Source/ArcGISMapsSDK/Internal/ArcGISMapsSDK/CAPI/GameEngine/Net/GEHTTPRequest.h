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

#include "ArcGISMapsSDK/CAPI/GameEngine/Net/GEHTTPMethod.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Net/GEHTTPRequestHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Net/GEHTTPResponseHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ByteArrayStruct.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEHTTPRequest_destroy(RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ByteArray RT_GEHTTPRequest_getBody(const RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GEHTTPRequest_getCanceled(const RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DictionaryHandle RT_GEHTTPRequest_getHeaders(const RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEHTTPMethod RT_GEHTTPRequest_getMethod(const RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEHTTPRequest_getURI(const RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEHTTPRequest_handleError(RT_GEHTTPRequestHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEHTTPRequest_handleResponse(RT_GEHTTPRequestHandle thisHandle, const RT_GEHTTPResponseHandle response, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif