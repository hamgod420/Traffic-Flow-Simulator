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

#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceRenderTarget.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceTexture2D.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUComputing
{
struct FComposableImage
{
	FVector4f Extent;
	TSharedPtr<const GPUResources::FGPUResourceTexture2D> Image;
	float Opacity;
};

class IImageComposer
{
public:
	virtual ~IImageComposer() = default;

	virtual void Compose(const std::vector<FComposableImage>& InputImages, const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output) = 0;

	// Used by tile blending
	virtual void Compose(const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& SourceA,
						 const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& SourceB,
						 float Alpha,
						 const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output,
						 const FVector4f& Extent) = 0;

	// Used by tile blending
	virtual void Copy(const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Source,
					  const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output,
					  const FVector4f& Extent) = 0;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
