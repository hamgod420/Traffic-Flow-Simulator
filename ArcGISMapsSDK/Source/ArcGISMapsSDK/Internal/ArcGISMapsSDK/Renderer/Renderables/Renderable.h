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

class FDynamicMeshIndexBuffer32;
class FPositionVertexBuffer;
class UMeshComponent;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class FGPUResourceMaterial;
struct FGPUResourceMesh;
} // namespace GPUResources

namespace Renderables
{
struct FRenderableRenderBuffers;

class FRenderable : public TSharedFromThis<FRenderable>
{
public:
	FRenderable(USceneComponent* InRootComponent, uint32 InLayerId, uint64 InCallbackToken, bool bInUseStaticMesh);
	virtual ~FRenderable();

	virtual bool HasGPUResources() const;

	uint64 GetCallbackToken() const;

	uint32 GetLayerId() const;
	const UMeshComponent* GetMeshComponent() const;
	TOptional<FRenderableRenderBuffers> GetRenderBuffers() const;
	const FTransform& GetTransform() const;

	void SetMesh(TSharedPtr<const GPUResources::FGPUResourceMesh> InGPUResourceMesh);

	void SetToEngineTransform(const FTransform& InToEngineTransform);

	bool GetIsMeshColliderEnabled() const;
	void SetIsMeshColliderEnabled(bool bInIsMeshColliderEnabled);

	bool GetIsVisible() const;
	void SetIsVisible(bool bInIsVisible);

	bool GetMasksTerrain() const;
	void SetMasksTerrain(bool bInMasksTerrain);

	const TSharedPtr<const GPUResources::FGPUResourceMaterial>& GetMaterial() const;
	void SetMaterial(const TSharedPtr<const GPUResources::FGPUResourceMaterial>& InGPUResourceMaterial);

	const FTransform& GetObbTransform() const;
	void SetObbTransform(FTransform InObbTransform);

	const FVector3d& GetPivot() const;
	void SetPivot(const FVector3d& InPivot);

protected:
	void CreateMeshComponent();
	void UpdateCollisionsAndVisibility();
	void UpdateTransform();

	bool bMasksTerrain{false};
	bool bIsMeshColliderEnabled{false};
	bool bIsVisible{false};
	bool bUseStaticMesh{false};

	uint64 CallbackToken{0};
	TSharedPtr<const GPUResources::FGPUResourceMaterial> GPUResourceMaterial;
	uint32 LayerId{0};
	UMeshComponent* MeshComponent{nullptr};
	FTransform ObbTransform{FTransform::Identity};
	FVector3d Pivot{FVector3d::ZeroVector};
	USceneComponent* RootComponent{nullptr};
	FTransform ToEngineTransform{FTransform::Identity};
};
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
