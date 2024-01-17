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

#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadStatus.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/LoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentRectangleHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GELayer_destroy(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GELayerHandle RT_GELayer_create(const char* source, RT_GELayerType type, const char* APIKey, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_GELayer_getAPIKey(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEExtentRectangleHandle RT_GELayer_getExtent(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GELayer_getIsVisible(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayer_setIsVisible(RT_GELayerHandle thisHandle, bool isVisible, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_GELayer_getLoadError(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LoadStatus RT_GELayer_getLoadStatus(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GELayer_getName(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayer_setName(RT_GELayerHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler);
RT_GELayerType RT_GELayer_getObjectType(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
float RT_GELayer_getOpacity(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayer_setOpacity(RT_GELayerHandle thisHandle, float opacity, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GELayer_getSource(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_GELayer_getSpatialReference(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GELayer_cancelLoad(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayer_load(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GELayer_retryLoad(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GELayer_setDoneLoadingCallback(RT_GELayerHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GELayer_setLoadStatusChangedCallback(RT_GELayerHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif