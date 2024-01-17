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
#include "ArcGISMapsSDK/CAPI/Standard/ArrayType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Array_destroy(RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ArrayType RT_Array_getObjectType(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_Array_getSize(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementType RT_Array_getValueType(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ElementHandle RT_Array_at(const RT_ArrayHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_Array_contains(const RT_ArrayHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
RT_ArrayBuilderHandle RT_Array_createBuilder(RT_ElementType valueType, const RT_ErrorHandler* errorHandler);
bool RT_Array_equals(const RT_ArrayHandle thisHandle, const RT_ArrayHandle array2, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Array_first(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_Array_indexOf(const RT_ArrayHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
bool RT_Array_isEmpty(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Array_last(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif