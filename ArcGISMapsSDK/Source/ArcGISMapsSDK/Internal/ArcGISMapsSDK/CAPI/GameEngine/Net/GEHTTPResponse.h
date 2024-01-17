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

#include "ArcGISMapsSDK/CAPI/GameEngine/Net/GEHTTPResponseHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ByteArrayStruct.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEHTTPResponse_destroy(RT_GEHTTPResponseHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEHTTPResponseHandle RT_GEHTTPResponse_create(uint16_t statusCode, RT_ByteArray body, const RT_ErrorHandler* errorHandler);

RT_ByteArray RT_GEHTTPResponse_getBody(const RT_GEHTTPResponseHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DictionaryHandle RT_GEHTTPResponse_getHeaders(const RT_GEHTTPResponseHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint16_t RT_GEHTTPResponse_getStatusCode(const RT_GEHTTPResponseHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif