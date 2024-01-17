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

#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadStatus.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Mapping/Layers/BuildingSceneSublayerDiscipline.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneSublayerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/BuildingScene/GEBuildingSceneSublayerImmutableCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEBuildingSceneSublayer_destroy(RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_BuildingSceneSublayerDiscipline RT_GEBuildingSceneSublayer_getDiscipline(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GEBuildingSceneSublayer_getIsVisible(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneSublayer_setIsVisible(RT_GEBuildingSceneSublayerHandle thisHandle, bool isVisible, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_GEBuildingSceneSublayer_getLoadError(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LoadStatus RT_GEBuildingSceneSublayer_getLoadStatus(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEBuildingSceneSublayer_getName(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
float RT_GEBuildingSceneSublayer_getOpacity(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneSublayer_setOpacity(RT_GEBuildingSceneSublayerHandle thisHandle, float opacity, const RT_ErrorHandler* errorHandler);
int64_t RT_GEBuildingSceneSublayer_getSublayerId(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneSublayerImmutableCollectionHandle RT_GEBuildingSceneSublayer_getSublayers(const RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEBuildingSceneSublayer_cancelLoad(RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneSublayer_load(RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneSublayer_retryLoad(RT_GEBuildingSceneSublayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEBuildingSceneSublayer_setDoneLoadingCallback(RT_GEBuildingSceneSublayerHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEBuildingSceneSublayer_setLoadStatusChangedCallback(RT_GEBuildingSceneSublayerHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif