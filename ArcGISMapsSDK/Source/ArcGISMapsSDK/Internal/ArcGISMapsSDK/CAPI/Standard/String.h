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

#include "ArcGISMapsSDK/CAPI/Standard/ByteArrayStruct.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_String_destroy(RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_String_create(const char* string, const RT_ErrorHandler* errorHandler);

size_t RT_String_getSize(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler);

char* RT_String_cStr(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ByteArray RT_String_getByteArray(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif