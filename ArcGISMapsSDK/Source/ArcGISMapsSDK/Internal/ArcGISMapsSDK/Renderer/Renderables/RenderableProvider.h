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

#include "ArcGISMapsSDK/Renderer/Renderables/IRenderableProvider.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
class FRenderableProvider : public IRenderableProvider
{
public:
	FRenderableProvider(USceneComponent* InRootComponent, bool bInUseStaticMesh = false);

	TSharedPtr<FRenderable> CreateRenderable(uint32 InId,
											 GameEngine::RCQ::ArcGISRenderableType InRenderableType,
											 uint32 InLayerId,
											 uint64 InCallbackToken) override;
	void DestroyRenderable(uint32 InId) override;

	TSharedPtr<FRenderable> GetRenderable(uint32 InId) const override;
	const TSharedPtr<const FRenderable> GetRenderableFrom(const UMeshComponent* InMeshComponent) const override;
	const TMap<uint32, TSharedPtr<FRenderable>>& GetRenderables() const override;
	const TArray<TSharedPtr<FRenderable>>& GetUnavailableRenderables() const override;

	void SetAreMeshCollidersEnabled(bool bInAreMeshCollidersEnabled) override;
	void SetRenderableAsAvailable(const TSharedPtr<FRenderable>& InRenderable) override;

private:
	bool bAreMeshCollidersEnabled{false};
	bool bUseStaticMesh{false};

	TMap<uint32, TSharedPtr<FRenderable>> Renderables;
	TMap<const UMeshComponent*, TSharedPtr<FRenderable>> RenderablesByMeshComponent;
	USceneComponent* RootComponent{nullptr};
	TArray<TSharedPtr<FRenderable>> UnavailableRenderables;
};
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
