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

#include "GlobalShader.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class FGPUResourceRenderTarget;
class FGPUResourceTexture2D;
} // namespace GPUResources
namespace GPUComputing
{
class GPUComputingUtils
{
public:
	static FTextureRHIRef GetRHITexture(const TSharedPtr<GPUResources::FGPUResourceTexture2D>& Input);
	static FTexture2DRHIRef GetRHITexture2D(const TSharedPtr<const GPUResources::FGPUResourceRenderTarget>& Texture);

	/// <summary>
	/// Retrieve instance of shader of the specified type
	/// </summary>
	/// <typeparam name="TShader"></typeparam>
	/// <returns></returns>
	template <typename TShader>
	static TShaderMapRef<TShader> GetShader();
};

template <typename TShader>
TShaderMapRef<TShader> GPUComputingUtils::GetShader()
{
	auto ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	return TShaderMapRef<TShader>(ShaderMap);
}
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
