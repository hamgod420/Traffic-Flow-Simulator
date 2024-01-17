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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Filters/GESpatialFeatureFilterHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/BuildingAttributeFilterCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneLayerActiveBuildingAttributeFilterChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneSublayerImmutableCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEBuildingSceneLayerHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/FutureHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEBuildingSceneLayer_destroy(RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEBuildingSceneLayerHandle RT_GEBuildingSceneLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneLayerHandle RT_GEBuildingSceneLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler);

RT_BuildingAttributeFilterHandle RT_GEBuildingSceneLayer_getActiveBuildingAttributeFilter(const RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneLayer_setActiveBuildingAttributeFilter(RT_GEBuildingSceneLayerHandle thisHandle, RT_BuildingAttributeFilterHandle activeBuildingAttributeFilter, const RT_ErrorHandler* errorHandler);
RT_BuildingAttributeFilterCollectionHandle RT_GEBuildingSceneLayer_getBuildingAttributeFilters(const RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GESpatialFeatureFilterHandle RT_GEBuildingSceneLayer_getFeatureFilter(const RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneLayer_setFeatureFilter(RT_GEBuildingSceneLayerHandle thisHandle, RT_GESpatialFeatureFilterHandle featureFilter, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneSublayerImmutableCollectionHandle RT_GEBuildingSceneLayer_getSublayers(const RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_TaskHandle RT_GEBuildingSceneLayer_fetchStatisticsAsync(RT_GEBuildingSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEBuildingSceneLayer_setActiveBuildingAttributeFilterChangedCallback(RT_GEBuildingSceneLayerHandle thisHandle, RT_GEBuildingSceneLayerActiveBuildingAttributeFilterChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif