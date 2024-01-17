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

#include "ArcGISMapsSDK/Renderer/GPUComputing/INormalMapGenerator.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
class ArcGISView;
} // namespace View
} // namespace GameEngine

namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUComputing
{
class FNormalMapGeneratorBase : public INormalMapGenerator
{
public:
	FNormalMapGeneratorBase(TSharedPtr<Esri::GameEngine::View::ArcGISView> InView);
	virtual ~FNormalMapGeneratorBase();

	void Compute(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& InputElevation,
				 const FVector4f& TileExtent,
				 const FVector4f& TextureExtent,
				 const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output) override;

protected:
	virtual void DrawGlobalViewMode(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& InputElevation,
									const FVector4f& InputOffsetAndScale,
									float CircleLongitude,
									float MinLatitude,
									float LatitudeAngleDelta,
									float LongitudeArc,
									float LatitudeLength,
									const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Output) = 0;

	virtual void DrawLocalViewMode(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& InputElevation,
								   const FVector4f& InputOffsetAndScale,
								   float LatitudeLength,
								   float LongitudeLength,
								   const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Output) = 0;

	TSharedPtr<Esri::GameEngine::View::ArcGISView> View;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
