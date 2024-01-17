// COPYRIGHT 1995-2023 ESRI
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

#include "DynamicMeshBuilder.h"
#include "Rendering/PositionVertexBuffer.h"

struct FArcGISViewportProperties;
class FPostOpaqueRenderParameters;
class UArcGISMapComponent;
class UMaterialParameterCollection;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class IGPUResourceProvider;
class FGPUResourceRenderTarget;
} // namespace GPUResources

namespace Renderables
{
class IRenderableProvider;
} // namespace Renderables

namespace GPUComputing
{
class FTerrainOcclusionDepthMapRenderer
{
public:
	FTerrainOcclusionDepthMapRenderer(TSharedPtr<Renderables::IRenderableProvider> InRenderableProvider,
									  TSharedPtr<GPUResources::IGPUResourceProvider> InGPUResourceProvider,
									  UArcGISMapComponent* InMapComponent);
	~FTerrainOcclusionDepthMapRenderer();

	void Update(const FArcGISViewportProperties& InViewportProperties);

	void BeginRendering();
	void EndRendering();

private:
	void ClearDepthToZero(FRHICommandListImmediate& InRHICmdList);
	void InitializeCubeAndQuad();
	bool IsCameraInsideAnyOBB(const FVector3d& InCameraPosition);
	void RecreateClippingDepthStencil(uint32 InSizeX, uint32 InSizeY);
	void Render(FPostOpaqueRenderParameters& InPostOpaqueRenderParameters);
	void RenderOBBDepth(FRHICommandListImmediate& InRHICmdList, const FMatrix44d& InView, const FMatrix44d& InProj);
	void RenderStencilMask(FRHICommandListImmediate& InRHICmdList, const FMatrix44d& InView, const FMatrix44d& InProj);

	FDelegateHandle OnPostOpaqueRenderHandle;

	UMaterialParameterCollection* MaterialParameterCollection{nullptr};

	FDynamicMeshIndexBuffer32 CubeIndexBuffer;
	FPositionVertexBuffer CubePositionVertexBuffer;
	FDynamicMeshIndexBuffer32 QuadIndexBuffer;
	FPositionVertexBuffer QuadPositionVertexBuffer;

	UTextureRenderTarget2D* ClippingRenderTarget{nullptr};
	FTexture2DRHIRef ClippingDepthStencil;
	TSharedPtr<Renderables::IRenderableProvider> RenderableProvider;

	UArcGISMapComponent* MapComponent{nullptr};

	struct FCachedRenderableRenderData
	{
		FBufferRHIRef IndexBufferRHI;
		FBufferRHIRef VertexBufferRHI;

		uint32 NumPrimitives;
		uint32 NumVertices;

		FMatrix44d ObbTransform;
		FMatrix44d RenderableTransform;
	};

	TArray<FCachedRenderableRenderData> RThreadRenderableRenderData;

	FIntPoint ViewportSize;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
