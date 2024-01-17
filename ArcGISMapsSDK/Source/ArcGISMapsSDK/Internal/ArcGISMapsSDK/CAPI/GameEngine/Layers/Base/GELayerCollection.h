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

#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GELayerCollection_destroy(RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GELayerCollectionHandle RT_GELayerCollection_create(const RT_ErrorHandler* errorHandler);

size_t RT_GELayerCollection_getSize(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_GELayerCollection_add(RT_GELayerCollectionHandle thisHandle, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler);
size_t RT_GELayerCollection_addArray(RT_GELayerCollectionHandle thisHandle, const RT_GELayerCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_GELayerHandle RT_GELayerCollection_at(const RT_GELayerCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_GELayerCollection_contains(const RT_GELayerCollectionHandle thisHandle, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GELayerCollection_equals(const RT_GELayerCollectionHandle thisHandle, const RT_GELayerCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_GELayerHandle RT_GELayerCollection_first(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_GELayerCollection_indexOf(const RT_GELayerCollectionHandle thisHandle, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler);
void RT_GELayerCollection_insert(RT_GELayerCollectionHandle thisHandle, size_t position, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GELayerCollection_isEmpty(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GELayerHandle RT_GELayerCollection_last(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayerCollection_move(RT_GELayerCollectionHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler);
size_t RT_GELayerCollection_npos(const RT_ErrorHandler* errorHandler);
void RT_GELayerCollection_remove(RT_GELayerCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
void RT_GELayerCollection_removeAll(RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif