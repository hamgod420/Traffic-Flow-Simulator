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

#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneSublayerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneSublayerImmutableCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEBuildingSceneSublayerImmutableCollection_destroy(RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_GEBuildingSceneSublayerImmutableCollection_getSize(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEBuildingSceneSublayerHandle RT_GEBuildingSceneSublayerImmutableCollection_at(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_GEBuildingSceneSublayerImmutableCollection_contains(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_GEBuildingSceneSublayerHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GEBuildingSceneSublayerImmutableCollection_equals(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_GEBuildingSceneSublayerImmutableCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneSublayerHandle RT_GEBuildingSceneSublayerImmutableCollection_first(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_GEBuildingSceneSublayerImmutableCollection_indexOf(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_GEBuildingSceneSublayerHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GEBuildingSceneSublayerImmutableCollection_isEmpty(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneSublayerHandle RT_GEBuildingSceneSublayerImmutableCollection_last(const RT_GEBuildingSceneSublayerImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_GEBuildingSceneSublayerImmutableCollection_npos(const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif