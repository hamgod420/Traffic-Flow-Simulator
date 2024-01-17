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

#include "ArcGISMapsSDK/Renderer/GPUComputing/NormalMapGeneratorBase.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUComputing
{
class FGraphicsNormalMapGenerator : public FNormalMapGeneratorBase
{
public:
	using FNormalMapGeneratorBase::FNormalMapGeneratorBase;

protected:
	void DrawGlobalViewMode(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& inputElevation,
							const FVector4f& inputOffsetAndScale,
							float circleLongitude,
							float minLatitude,
							float latitudeAngleDelta,
							float longitudeArc,
							float latitudeLength,
							const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& output) override;

	void DrawLocalViewMode(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& InputElevation,
						   const FVector4f& InputOffsetAndScale,
						   float LatitudeLength,
						   float LongitudeLength,
						   const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Output) override;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
