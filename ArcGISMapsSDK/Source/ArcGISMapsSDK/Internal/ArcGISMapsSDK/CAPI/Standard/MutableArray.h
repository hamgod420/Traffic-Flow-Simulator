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

#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArrayElementAddedEvent.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArrayElementRemovedEvent.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArrayHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Vector_destroy(RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_VectorHandle RT_Vector_create(RT_ElementType valueType, const RT_ErrorHandler* errorHandler);

size_t RT_Vector_getSize(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementType RT_Vector_getValueType(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_Vector_addArray(RT_VectorHandle thisHandle, const RT_VectorHandle vector2, const RT_ErrorHandler* errorHandler);
size_t RT_Vector_add(RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Vector_at(const RT_VectorHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_Vector_contains(const RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
bool RT_Vector_equals(const RT_VectorHandle thisHandle, const RT_VectorHandle vector2, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Vector_first(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_Vector_indexOf(const RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
void RT_Vector_insert(RT_VectorHandle thisHandle, size_t position, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
bool RT_Vector_isEmpty(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Vector_last(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_Vector_move(RT_VectorHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler);
size_t RT_Vector_npos(const RT_ErrorHandler* errorHandler);
void RT_Vector_remove(RT_VectorHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
void RT_Vector_removeAll(RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_Vector_setElementAddedCallback(RT_VectorHandle thisHandle, RT_VectorElementAddedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_Vector_setElementRemovedCallback(RT_VectorHandle thisHandle, RT_VectorElementRemovedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif