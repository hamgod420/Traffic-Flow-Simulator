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

#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMaterialScalarProperty.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMaterialVectorProperty.h"
#include "ArcGISMapsSDK/Renderer/ArcGISRenderCommand.h"

class IArcGISMapComponentInterface;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUComputing
{
class IImageComposer;
class INormalMapGenerator;
} // namespace GPUComputing

namespace GPUResources
{
class IGPUResourceProvider;
} // namespace GPUResources

namespace Renderables
{
class IRenderableProvider;
} // namespace Renderables

class ARCGISMAPSSDK_API FArcGISRenderCommandClient
{
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FExtentChangedDelegate, FVector3d, FVector3d, Esri::GameEngine::Extent::ArcGISExtentType);

public:
	FArcGISRenderCommandClient(IArcGISMapComponentInterface* InMap,
							   TSharedPtr<GPUResources::IGPUResourceProvider> InGPUResourceProvider,
							   TSharedPtr<Renderables::IRenderableProvider> InRenderableProvider,
							   TSharedPtr<GPUComputing::IImageComposer> InImageComposer,
							   TSharedPtr<GPUComputing::INormalMapGenerator> InNormalMapGenerator);
	virtual ~FArcGISRenderCommandClient() = default;

	void ExecuteRenderCommand(const FArcGISRenderCommand& InRenderCommand);

	FExtentChangedDelegate OnExtentChanged;

private:
	TSharedPtr<GPUResources::IGPUResourceProvider> GPUResourceProvider;
	TSharedPtr<GPUComputing::IImageComposer> ImageComposer;
	IArcGISMapComponentInterface* Map{nullptr};
	TSharedPtr<GPUComputing::INormalMapGenerator> NormalMapGenerator;
	TSharedPtr<Renderables::IRenderableProvider> RenderableProvider;

	TMap<Esri::GameEngine::RCQ::ArcGISMaterialVectorProperty, FVector4d> GlobalVectorProperties;
	TMap<Esri::GameEngine::RCQ::ArcGISMaterialScalarProperty, float> GlobalScalarProperties;
};
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
