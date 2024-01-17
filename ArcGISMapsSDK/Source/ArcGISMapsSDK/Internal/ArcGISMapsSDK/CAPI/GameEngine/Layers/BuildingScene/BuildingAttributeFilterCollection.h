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

#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Mapping/Layers/BuildingAttributeFilterHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/BuildingAttributeFilterCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_BuildingAttributeFilterCollection_destroy(RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_BuildingAttributeFilterCollectionHandle RT_BuildingAttributeFilterCollection_create(const RT_ErrorHandler* errorHandler);

size_t RT_BuildingAttributeFilterCollection_getSize(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_BuildingAttributeFilterCollection_add(RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_BuildingAttributeFilterHandle value, const RT_ErrorHandler* errorHandler);
size_t RT_BuildingAttributeFilterCollection_addArray(RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_BuildingAttributeFilterCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_BuildingAttributeFilterHandle RT_BuildingAttributeFilterCollection_at(const RT_BuildingAttributeFilterCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_BuildingAttributeFilterCollection_contains(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_BuildingAttributeFilterHandle value, const RT_ErrorHandler* errorHandler);
bool RT_BuildingAttributeFilterCollection_equals(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_BuildingAttributeFilterCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_BuildingAttributeFilterHandle RT_BuildingAttributeFilterCollection_first(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_BuildingAttributeFilterCollection_indexOf(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_BuildingAttributeFilterHandle value, const RT_ErrorHandler* errorHandler);
void RT_BuildingAttributeFilterCollection_insert(RT_BuildingAttributeFilterCollectionHandle thisHandle, size_t position, const RT_BuildingAttributeFilterHandle value, const RT_ErrorHandler* errorHandler);
bool RT_BuildingAttributeFilterCollection_isEmpty(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_BuildingAttributeFilterHandle RT_BuildingAttributeFilterCollection_last(const RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_BuildingAttributeFilterCollection_move(RT_BuildingAttributeFilterCollectionHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler);
size_t RT_BuildingAttributeFilterCollection_npos(const RT_ErrorHandler* errorHandler);
void RT_BuildingAttributeFilterCollection_remove(RT_BuildingAttributeFilterCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
void RT_BuildingAttributeFilterCollection_removeAll(RT_BuildingAttributeFilterCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif