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

#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/GEAttributeProcessorHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Filters/GESpatialFeatureFilterHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GE3DObjectSceneLayerHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GE3DObjectSceneLayer_destroy(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GE3DObjectSceneLayerHandle RT_GE3DObjectSceneLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler);
RT_GE3DObjectSceneLayerHandle RT_GE3DObjectSceneLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler);

RT_GESpatialFeatureFilterHandle RT_GE3DObjectSceneLayer_getFeatureFilter(const RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GE3DObjectSceneLayer_setFeatureFilter(RT_GE3DObjectSceneLayerHandle thisHandle, RT_GESpatialFeatureFilterHandle featureFilter, const RT_ErrorHandler* errorHandler);
void* RT_GE3DObjectSceneLayer_getMaterialReference(const RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GE3DObjectSceneLayer_setMaterialReference(RT_GE3DObjectSceneLayerHandle thisHandle, void* materialReference, const RT_ErrorHandler* errorHandler);

void RT_GE3DObjectSceneLayer_setAttributesToVisualize(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ArrayHandle layerAttributes, const RT_ErrorHandler* errorHandler);
void RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ArrayHandle layerAttributes, const RT_ArrayHandle visualizationAttributeDescriptions, const RT_GEAttributeProcessorHandle attributeProcessor, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif