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

#include "ArcGISMapsSDK/CAPI/Standard/ArrayBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_ArrayBuilder_destroy(RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ElementType RT_ArrayBuilder_getValueType(const RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_ArrayBuilder_add(RT_ArrayBuilderHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_ArrayBuilder_moveToArray(RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif