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

#include "GlobalShader.h"
#include "PipelineStateCache.h"
#include "ShaderParameterMacros.h"
#include "ShaderParameterStruct.h"

#include "ArcGISMapsSDK/Utils/UnrealVersionComparison.h"

#if IS_UE_VERSION_GREATER_THAN(5, 1)
#include "DataDrivenShaderPlatformInfo.h"
#endif

class FNormalMapGeneratorGlobalViewModeCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNormalMapGeneratorGlobalViewModeCS);
	SHADER_USE_PARAMETER_STRUCT(FNormalMapGeneratorGlobalViewModeCS, FGlobalShader);

	// clang-format off
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_TEXTURE(Texture2D, Input)
		SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
		SHADER_PARAMETER(FVector4f, InputOffsetAndScale)
		SHADER_PARAMETER(float, CircleLongitude)
		SHADER_PARAMETER(float, MinLatitude)
		SHADER_PARAMETER(float, LatitudeAngleDelta)
		SHADER_PARAMETER(float, LongitudeArc)
		SHADER_PARAMETER(float, LatitudeLength)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, Output)
	END_SHADER_PARAMETER_STRUCT()
	// clang-format on

public:
	static const uint32 THREADGROUP_SIZE_X;
	static const uint32 THREADGROUP_SIZE_Y;

#if IS_UE_VERSION_LESS_THAN(5, 1)
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return RHISupportsComputeShaders(Parameters.Platform);
	}
#endif
};

class FNormalMapGeneratorLocalViewModeCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNormalMapGeneratorLocalViewModeCS);
	SHADER_USE_PARAMETER_STRUCT(FNormalMapGeneratorLocalViewModeCS, FGlobalShader);

	// clang-format off
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_TEXTURE(Texture2D, Input)
		SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
		SHADER_PARAMETER(FVector4f, InputOffsetAndScale)
		SHADER_PARAMETER(float, LatitudeLength)
		SHADER_PARAMETER(float, LongitudeLength)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, Output)
	END_SHADER_PARAMETER_STRUCT()
	// clang-format on

public:
	static const uint32 THREADGROUP_SIZE_X;
	static const uint32 THREADGROUP_SIZE_Y;

#if IS_UE_VERSION_LESS_THAN(5, 1)
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return RHISupportsComputeShaders(Parameters.Platform);
	}
#endif
};

struct FNormalMapGeneratorElementVertex
{
	FVector4f Position;
	FVector2f TextureCoordinate;

	FNormalMapGeneratorElementVertex()
	{
	}

	FNormalMapGeneratorElementVertex(const FVector4f& InPosition, const FVector2D& InTextureCoordinate)
	: Position(InPosition),
	  TextureCoordinate(InTextureCoordinate)
	{
	}
};

class FNormalMapGeneratorGlobalViewModePSResources : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;
	FBufferRHIRef VertexBufferRHI;

	virtual ~FNormalMapGeneratorGlobalViewModePSResources()
	{
	}

#if IS_UE_VERSION_GREATER_THAN(5, 2)
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#else
	virtual void InitRHI() override
#endif
	{
		FVertexDeclarationElementList Elements;
		uint16 Stride = sizeof(FNormalMapGeneratorElementVertex);
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FNormalMapGeneratorElementVertex, Position), VET_Float4, 0, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FNormalMapGeneratorElementVertex, TextureCoordinate), VET_Float2, 1, Stride));
		VertexDeclarationRHI = PipelineStateCache::GetOrCreateVertexDeclaration(Elements);

		TResourceArray<FNormalMapGeneratorElementVertex> Vertices;
		Vertices.AddUninitialized(4);

		Vertices[0].Position.Set(-1.0f, +1.0f, 1.0f, 1.0f); // Top Left
		Vertices[1].Position.Set(+1.0f, +1.0f, 1.0f, 1.0f); // Top Right
		Vertices[2].Position.Set(-1.0f, -1.0f, 1.0f, 1.0f); // Bottom Left
		Vertices[3].Position.Set(+1.0f, -1.0f, 1.0f, 1.0f); // Bottom Right

		Vertices[0].TextureCoordinate.Set(0.0f, 0.0f);
		Vertices[1].TextureCoordinate.Set(1.0f, 0.0f);
		Vertices[2].TextureCoordinate.Set(0.0f, 1.0f);
		Vertices[3].TextureCoordinate.Set(1.0f, 1.0f);

		FRHIResourceCreateInfo CreateInfo(TEXT("FNormalMapGeneratorGlobalViewModePSResources"), &Vertices);
#if IS_UE_VERSION_GREATER_THAN(5, 2)
		VertexBufferRHI = RHICmdList.CreateVertexBuffer(sizeof(FNormalMapGeneratorElementVertex) * 4, BUF_Static, CreateInfo);
#else
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FNormalMapGeneratorElementVertex) * 4, BUF_Static, CreateInfo);
#endif
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
		VertexBufferRHI.SafeRelease();
	}
};

extern TGlobalResource<FNormalMapGeneratorGlobalViewModePSResources> GNormalMapGeneratorGlobalViewModePSResources;

class FNormalMapGeneratorLocalViewModePSResources : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;
	FBufferRHIRef VertexBufferRHI;

	virtual ~FNormalMapGeneratorLocalViewModePSResources()
	{
	}

#if IS_UE_VERSION_GREATER_THAN(5, 2)
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#else
	virtual void InitRHI() override
#endif
	{
		FVertexDeclarationElementList Elements;
		uint16 Stride = sizeof(FNormalMapGeneratorElementVertex);
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FNormalMapGeneratorElementVertex, Position), VET_Float4, 0, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FNormalMapGeneratorElementVertex, TextureCoordinate), VET_Float2, 1, Stride));
		VertexDeclarationRHI = PipelineStateCache::GetOrCreateVertexDeclaration(Elements);

		TResourceArray<FNormalMapGeneratorElementVertex> Vertices;
		Vertices.AddUninitialized(4);

		Vertices[0].Position.Set(-1.0f, +1.0f, 1.0f, 1.0f); // Top Left
		Vertices[1].Position.Set(+1.0f, +1.0f, 1.0f, 1.0f); // Top Right
		Vertices[2].Position.Set(-1.0f, -1.0f, 1.0f, 1.0f); // Bottom Left
		Vertices[3].Position.Set(+1.0f, -1.0f, 1.0f, 1.0f); // Bottom Right

		Vertices[0].TextureCoordinate.Set(0.0f, 0.0f);
		Vertices[1].TextureCoordinate.Set(1.0f, 0.0f);
		Vertices[2].TextureCoordinate.Set(0.0f, 1.0f);
		Vertices[3].TextureCoordinate.Set(1.0f, 1.0f);

		FRHIResourceCreateInfo CreateInfo(TEXT("FNormalMapGeneratorLocalViewModePSResources"), &Vertices);
#if IS_UE_VERSION_GREATER_THAN(5, 2)
		VertexBufferRHI = RHICmdList.CreateVertexBuffer(sizeof(FNormalMapGeneratorElementVertex) * 4, BUF_Static, CreateInfo);
#else
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FNormalMapGeneratorElementVertex) * 4, BUF_Static, CreateInfo);
#endif
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
		VertexBufferRHI.SafeRelease();
	}
};

extern TGlobalResource<FNormalMapGeneratorLocalViewModePSResources> GNormalMapGeneratorLocalViewModePSResources;

class FNormalMapGeneratorVS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNormalMapGeneratorVS);

public:
	FNormalMapGeneratorVS();
	FNormalMapGeneratorVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer);

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}
};

class FNormalMapGeneratorGlobalViewModePS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNormalMapGeneratorGlobalViewModePS);
	SHADER_USE_PARAMETER_STRUCT(FNormalMapGeneratorGlobalViewModePS, FGlobalShader);

	// clang-format off
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_TEXTURE(Texture2D, Input)
		SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
		SHADER_PARAMETER(FVector4f, InputOffsetAndScale)
		SHADER_PARAMETER(float, CircleLongitude)
		SHADER_PARAMETER(float, MinLatitude)
		SHADER_PARAMETER(float, LatitudeAngleDelta)
		SHADER_PARAMETER(float, LongitudeArc)
		SHADER_PARAMETER(float, LatitudeLength)
		SHADER_PARAMETER(float, OutputWidth)
		SHADER_PARAMETER(float, OutputHeight)
	END_SHADER_PARAMETER_STRUCT()
	// clang-format on

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}
};

class FNormalMapGeneratorLocalViewModePS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNormalMapGeneratorLocalViewModePS);
	SHADER_USE_PARAMETER_STRUCT(FNormalMapGeneratorLocalViewModePS, FGlobalShader);

	// clang-format off
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_TEXTURE(Texture2D, Input)
		SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
		SHADER_PARAMETER(FVector4f, InputOffsetAndScale)
		SHADER_PARAMETER(float, LatitudeLength)
		SHADER_PARAMETER(float, LongitudeLength)
		SHADER_PARAMETER(float, OutputWidth)
		SHADER_PARAMETER(float, OutputHeight)
	END_SHADER_PARAMETER_STRUCT()
	// clang-format on

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}
};
