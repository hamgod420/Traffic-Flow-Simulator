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

#include "ArcGISMapsSDK/Renderer/IArcGISRenderCommandThrottler.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
class FArcGISRenderCommandNoThrottler final : public IArcGISRenderCommandThrottler
{
public:
	void BeginFrame() override;
	bool DoThrottle(const FArcGISRenderCommand& InRenderCommand) override;
};
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
