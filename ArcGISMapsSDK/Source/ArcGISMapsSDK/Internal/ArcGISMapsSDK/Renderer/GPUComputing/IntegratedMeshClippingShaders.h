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

#include "GlobalShader.h"
#include "PipelineStateCache.h"
#include "ShaderParameterMacros.h"
#include "ShaderParameterStruct.h"

#include "ArcGISMapsSDK/Utils/UnrealVersionComparison.h"

// Vertex shader
class FIntegratedMeshClippingVS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FIntegratedMeshClippingVS);
	SHADER_USE_PARAMETER_STRUCT(FIntegratedMeshClippingVS, FGlobalShader);

	// clang-format off
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FMatrix44f, MV)
		SHADER_PARAMETER(FMatrix44f, MVP)
	END_SHADER_PARAMETER_STRUCT()
	// clang-format on
};

// Resources
struct FIntegratedMeshClippingElementVertex
{
	FVector3f Position;

	FIntegratedMeshClippingElementVertex()
	{
	}

	FIntegratedMeshClippingElementVertex(const FVector3f& InPosition) : Position(InPosition)
	{
	}
};

class FIntegratedMeshClippingPSResources : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;

	virtual ~FIntegratedMeshClippingPSResources()
	{
	}

#if IS_UE_VERSION_GREATER_THAN(5, 2)
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#else
	virtual void InitRHI() override
#endif
	{
		FVertexDeclarationElementList Elements;
		uint16 Stride = sizeof(FIntegratedMeshClippingElementVertex);
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FIntegratedMeshClippingElementVertex, Position), VET_Float3, 0, Stride));
		VertexDeclarationRHI = PipelineStateCache::GetOrCreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

// Pixel Shader
class FIntegratedMeshClippingOBBDepthPassPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FIntegratedMeshClippingOBBDepthPassPS);
	SHADER_USE_PARAMETER_STRUCT(FIntegratedMeshClippingOBBDepthPassPS, FGlobalShader);

	using FParameters = FEmptyShaderParameters;
};

class FIntegratedMeshClippingStencilPassPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FIntegratedMeshClippingStencilPassPS);
	SHADER_USE_PARAMETER_STRUCT(FIntegratedMeshClippingStencilPassPS, FGlobalShader);

	using FParameters = FEmptyShaderParameters;
};

class FIntegratedMeshClippingClearToZeroPassPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FIntegratedMeshClippingClearToZeroPassPS);
	SHADER_USE_PARAMETER_STRUCT(FIntegratedMeshClippingClearToZeroPassPS, FGlobalShader);

	using FParameters = FEmptyShaderParameters;
};

extern TGlobalResource<FIntegratedMeshClippingPSResources> GIntegratedMeshClippingPSResources;
