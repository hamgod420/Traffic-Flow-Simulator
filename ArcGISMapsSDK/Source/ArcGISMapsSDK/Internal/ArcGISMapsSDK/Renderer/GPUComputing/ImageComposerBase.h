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

#include "ArcGISMapsSDK/Renderer/GPUComputing/IImageComposer.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUComputing
{
class FImageComposerBase : public IImageComposer
{
public:
	FImageComposerBase();
	virtual ~FImageComposerBase();

	void Compose(const std::vector<FComposableImage>& InputImages, const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output) override;

	// Used by tile blending
	void Compose(const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& SourceA,
				 const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& SourceB,
				 float Alpha,
				 const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output,
				 const FVector4f& Extent) override;

	// Used by tile blending
	void Copy(const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Source,
			  const TSharedPtr<GPUResources::FGPUResourceRenderTarget>& Output,
			  const FVector4f& Extent) override;

private:
	virtual void Draw(std::vector<TSharedPtr<const GPUResources::FGPUResourceTexture>> Inputs,
					  std::vector<FVector4f> OffsetScaleOpacity,
					  const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Output) = 0;

	TSharedPtr<GPUResources::FGPUResourceRenderTarget> TempRenderTarget;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
