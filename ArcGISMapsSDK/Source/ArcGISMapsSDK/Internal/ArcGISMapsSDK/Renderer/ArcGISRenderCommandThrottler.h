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

#include "CoreMinimal.h"

#include "ArcGISMapsSDK/Renderer/IArcGISRenderCommandThrottler.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
class FArcGISRenderCommandThrottler final : public IArcGISRenderCommandThrottler
{
public:
	static constexpr bool bEnableThrottle{true};
	static constexpr uint32 MaxExecTimeMicroseconds{5000};
	static constexpr uint64 MaxResourceMemory{8 * 1024 * 1024}; // bytes
	static constexpr uint32 MaxComposeCommands{100};
	static constexpr uint32 MaxTriangles{25000};

	FArcGISRenderCommandThrottler();
	FArcGISRenderCommandThrottler(const FArcGISRenderCommandThrottler&) = delete;
	FArcGISRenderCommandThrottler(FArcGISRenderCommandThrottler&&) = delete;
	FArcGISRenderCommandThrottler& operator=(const FArcGISRenderCommandThrottler&) = delete;
	FArcGISRenderCommandThrottler& operator=(FArcGISRenderCommandThrottler&&) = delete;
	~FArcGISRenderCommandThrottler();

	void BeginFrame() override;
	bool DoThrottle(const FArcGISRenderCommand& InRenderCommand) override;

private:
	struct FStats
	{
		uint32 CommandCount{0};
		uint32 ComposeCount{0};
		uint64 ResourceMemory{0}; // bytes
		uint32 Triangles{0};
		bool bIsExecutingGroup{false};
	};
	FStats Stats{};
	std::chrono::steady_clock::time_point StartTime;
	static uint32 ThrottleCount; // Debugging
};
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
