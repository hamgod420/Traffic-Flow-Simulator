// COPYRIGHT 1995-2021 ESRI
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

#include "CoreMinimal.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
struct FUVChannel
{
	TArrayView<float> Elements;
	uint32 Dimensions;
};

struct FGPUResourceMesh
{
	TArrayView<FVector3f> Normals;
	TArrayView<FVector4f> Tangents;
	TArrayView<uint32> Indices;
	TArray<FUVChannel> UVs;
	TArrayView<uint32> Colors;
	TArrayView<FVector3f> Positions;
	bool bUseFullPrecisionUVs{false};
};
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
