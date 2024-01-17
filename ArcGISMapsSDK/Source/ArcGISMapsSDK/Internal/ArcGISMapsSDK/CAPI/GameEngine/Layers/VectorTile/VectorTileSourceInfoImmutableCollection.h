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

#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Mapping/Layers/VectorTiles/VectorTileSourceInfoHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfoImmutableCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_VectorTileSourceInfoImmutableCollection_destroy(RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_VectorTileSourceInfoImmutableCollection_getSize(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_at(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_VectorTileSourceInfoImmutableCollection_contains(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_VectorTileSourceInfoHandle value, const RT_ErrorHandler* errorHandler);
bool RT_VectorTileSourceInfoImmutableCollection_equals(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_VectorTileSourceInfoImmutableCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_first(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_VectorTileSourceInfoImmutableCollection_indexOf(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_VectorTileSourceInfoHandle value, const RT_ErrorHandler* errorHandler);
bool RT_VectorTileSourceInfoImmutableCollection_isEmpty(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_last(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_VectorTileSourceInfoImmutableCollection_npos(const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif