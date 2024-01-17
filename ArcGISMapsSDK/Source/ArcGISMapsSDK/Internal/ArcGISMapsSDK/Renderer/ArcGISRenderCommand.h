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

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
class FArcGISRenderCommand
{
public:
	template <typename T>
	const T& GetParameters() const
	{
		return *reinterpret_cast<const T*>(reinterpret_cast<const uint8*>(this) + sizeof(GameEngine::RCQ::ArcGISRenderCommandType));
	}

	GameEngine::RCQ::ArcGISRenderCommandType GetType() const
	{
		return *reinterpret_cast<const GameEngine::RCQ::ArcGISRenderCommandType*>(this);
	}
};
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
