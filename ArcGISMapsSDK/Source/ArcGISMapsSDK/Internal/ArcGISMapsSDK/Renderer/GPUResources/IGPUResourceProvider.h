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

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
enum class ArcGISRenderableType;
enum class ArcGISTextureFormat;
} // namespace RCQ
} // namespace GameEngine

namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class FGPUResourceMaterial;
class FGPUResourceRenderTarget;
class FGPUResourceTexture2D;

class IGPUResourceProvider
{
public:
	virtual ~IGPUResourceProvider() = default;

	virtual TSharedPtr<FGPUResourceMaterial> CreateMaterial(uint32 RenderableId,
															GameEngine::RCQ::ArcGISRenderableType RenderableType,
															UMaterialInterface* CustomMaterial = nullptr) = 0;

	virtual TSharedPtr<FGPUResourceRenderTarget> CreateRenderTarget(uint32 Id,
																	uint32 Width,
																	uint32 Height,
																	GameEngine::RCQ::ArcGISTextureFormat Format,
																	bool bUseMipMaps) = 0;

	virtual TSharedPtr<FGPUResourceTexture2D> CreateTexture(uint32 Id,
															uint32 Width,
															uint32 Height,
															GameEngine::RCQ::ArcGISTextureFormat Format,
															bool bInIsSRGB) = 0;

	virtual TSharedPtr<FGPUResourceMaterial> GetMaterial(uint32 Id) const = 0;
	virtual TSharedPtr<FGPUResourceRenderTarget> GetRenderTarget(uint32 Id) const = 0;
	virtual TSharedPtr<FGPUResourceTexture2D> GetTexture(uint32 Id) const = 0;

	virtual void DestroyMaterial(uint32 Id) = 0;
	virtual void DestroyRenderTarget(uint32 Id) = 0;
	virtual void DestroyTexture(uint32 Id) = 0;

	virtual void SetOcclusionRenderTarget(UTextureRenderTarget2D* InOcclusionRenderTarget) = 0;

	virtual const TSharedPtr<FGPUResourceTexture2D>& GetBlackFloatTexture() const = 0;
};
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
