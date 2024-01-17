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

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISDataBuffer.h"
#include "ArcGISMapsSDK/Renderer/ArcGISRenderCommand.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
class FArcGISRenderCommandIterator
{
public:
	FArcGISRenderCommandIterator() = default;
	FArcGISRenderCommandIterator(Unreal::ArcGISDataBuffer<uint8> InRawRenderCommands);
	virtual ~FArcGISRenderCommandIterator() = default;

	FArcGISRenderCommand* GetNextCommand();
	GameEngine::RCQ::ArcGISRenderCommandType GetCommandType();

private:
	template <typename T>
	FArcGISRenderCommand* GetRenderCommand();

	Unreal::ArcGISDataBuffer<uint8> RawRenderCommands{};
	uint32 CurrentOffset{0};
};
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
