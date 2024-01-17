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

class UMeshComponent;

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
enum class ArcGISRenderableType;
} // namespace RCQ
} // namespace GameEngine

namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
class FRenderable;

class IRenderableProvider
{
public:
	virtual ~IRenderableProvider() = default;

	virtual TSharedPtr<FRenderable> CreateRenderable(uint32 InId,
													 GameEngine::RCQ::ArcGISRenderableType InRenderableType,
													 uint32 InLayerId,
													 uint64 InCallbackToken) = 0;
	virtual void DestroyRenderable(uint32 InId) = 0;

	virtual TSharedPtr<FRenderable> GetRenderable(uint32 InId) const = 0;
	virtual const TSharedPtr<const FRenderable> GetRenderableFrom(const UMeshComponent* InMeshComponent) const = 0;
	virtual const TMap<uint32, TSharedPtr<FRenderable>>& GetRenderables() const = 0;
	virtual const TArray<TSharedPtr<FRenderable>>& GetUnavailableRenderables() const = 0;

	virtual void SetAreMeshCollidersEnabled(bool bInAreMeshCollidersEnabled) = 0;
	virtual void SetRenderableAsAvailable(const TSharedPtr<FRenderable>& InRenderable) = 0;
};
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
