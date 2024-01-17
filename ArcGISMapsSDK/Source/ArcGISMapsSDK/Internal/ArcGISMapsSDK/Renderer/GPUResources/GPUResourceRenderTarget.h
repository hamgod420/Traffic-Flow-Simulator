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
#include "Engine/TextureRenderTarget2D.h"

#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceTexture.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class ARCGISMAPSSDK_API FGPUResourceRenderTarget final : public FGPUResourceTexture
{
public:
	FGPUResourceRenderTarget(uint32 Width, uint32 Height, EPixelFormat Format, bool bUseMipMaps);
	FGPUResourceRenderTarget(UTextureRenderTarget2D* InNativeRenderTarget);

	uint32 GetHeight() const;
	uint32 GetWidth() const;

	UTextureRenderTarget2D* GetNativeRenderTarget2D() const;
};
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
