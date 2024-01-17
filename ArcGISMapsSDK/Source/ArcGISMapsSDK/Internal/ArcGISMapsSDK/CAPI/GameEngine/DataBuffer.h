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

#include "ArcGISMapsSDK/CAPI/GameEngine/DataBufferHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_DataBuffer_destroy(RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler);

void* RT_DataBuffer_getData(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_DataBuffer_getItemSize(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_DataBuffer_getSizeBytes(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif