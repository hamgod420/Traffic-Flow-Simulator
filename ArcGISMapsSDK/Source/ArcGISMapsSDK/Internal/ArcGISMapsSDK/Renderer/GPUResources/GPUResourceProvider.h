// COPYRIGHT 1995-2022 ESRI
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

#include "ArcGISMapsSDK/Renderer/GPUResources/IGPUResourceProvider.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class ARCGISMAPSSDK_API FGPUResourceProvider : public IGPUResourceProvider
{
public:
	FGPUResourceProvider();

	TSharedPtr<FGPUResourceMaterial> CreateMaterial(uint32 RenderableId,
													GameEngine::RCQ::ArcGISRenderableType RenderableType,
													UMaterialInterface* CustomMaterial = nullptr) override;

	TSharedPtr<FGPUResourceRenderTarget> CreateRenderTarget(uint32 Id,
															uint32 Width,
															uint32 Height,
															GameEngine::RCQ::ArcGISTextureFormat Format,
															bool bUseMipMaps) override;

	TSharedPtr<FGPUResourceTexture2D> CreateTexture(uint32 Id,
													uint32 Width,
													uint32 Height,
													GameEngine::RCQ::ArcGISTextureFormat Format,
													bool bInIsSRGB) override;

	TSharedPtr<FGPUResourceMaterial> GetMaterial(uint32 Id) const override;
	TSharedPtr<FGPUResourceRenderTarget> GetRenderTarget(uint32 Id) const override;
	TSharedPtr<FGPUResourceTexture2D> GetTexture(uint32 Id) const override;

	void DestroyMaterial(uint32 Id) override;
	void DestroyRenderTarget(uint32 Id) override;
	void DestroyTexture(uint32 Id) override;

	void SetOcclusionRenderTarget(UTextureRenderTarget2D* InOcclusionRenderTarget) override;

	const TSharedPtr<FGPUResourceTexture2D>& GetBlackFloatTexture() const override;

private:
	TMap<uint32, TSharedPtr<FGPUResourceMaterial>> Materials;
	TMap<uint32, TSharedPtr<FGPUResourceTexture2D>> Textures;
	TMap<uint32, TSharedPtr<FGPUResourceRenderTarget>> RenderTargets;

	TSharedPtr<FGPUResourceTexture2D> BlackFloatTexture;
	TSharedPtr<FGPUResourceRenderTarget> OcclusionRenderTarget;
};
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
