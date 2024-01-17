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
#include "Materials/MaterialInstanceDynamic.h"

#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceRenderTarget.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceTexture2D.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class ARCGISMAPSSDK_API FGPUResourceMaterial final
{
public:
	FGPUResourceMaterial(UMaterialInterface* Material);
	FGPUResourceMaterial(const FString& Name);
	~FGPUResourceMaterial();

	UMaterialInstanceDynamic* GetInstance() const;

	void SetFloat(const FString& Name, float Value);
	void SetVector(const FString& Name, const FVector4f& Value);

	TSharedPtr<const FGPUResourceTexture> GetTexture(const FString& Name) const;
	void SetTexture(const FString& Name, const TSharedPtr<const FGPUResourceTexture>& Value);

protected:
	UMaterialInstanceDynamic* MaterialInstance;
	TMap<FString, TSharedPtr<const FGPUResourceTexture>> Textures;
};
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
