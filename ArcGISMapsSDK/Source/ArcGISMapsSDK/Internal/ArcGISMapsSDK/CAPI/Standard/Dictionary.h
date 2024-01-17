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

#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Dictionary_destroy(RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_DictionaryHandle RT_Dictionary_create(RT_ElementType keyType, RT_ElementType valueType, const RT_ErrorHandler* errorHandler);

RT_ArrayHandle RT_Dictionary_getKeys(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementType RT_Dictionary_getKeyType(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_Dictionary_getSize(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementType RT_Dictionary_getValueType(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ElementHandle RT_Dictionary_at(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler);
bool RT_Dictionary_contains(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler);
bool RT_Dictionary_equals(const RT_DictionaryHandle thisHandle, const RT_DictionaryHandle dictionary2, const RT_ErrorHandler* errorHandler);
RT_ElementType RT_Dictionary_getTypeForKey(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler);
void RT_Dictionary_insert(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler);
bool RT_Dictionary_isEmpty(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_Dictionary_remove(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler);
void RT_Dictionary_removeAll(RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_Dictionary_replace(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ElementHandle newValue, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif