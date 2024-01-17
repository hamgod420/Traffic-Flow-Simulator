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

#include "ArcGISMapsSDK/CAPI/Platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum RT_GELayerType
{
    RT_GELayerType_GEImageLayer = 0,
    RT_GELayerType_GE3DObjectSceneLayer = 1,
    RT_GELayerType_GEIntegratedMeshLayer = 2,
    RT_GELayerType_GEUnsupportedLayer = 4,
    RT_GELayerType_GEUnknownLayer = 5,
    RT_GELayerType_GEVectorTileLayer = 6,
    RT_GELayerType_GEBuildingSceneLayer = 7
} RT_GELayerType;

#ifdef __cplusplus
} // extern "C"
#endif