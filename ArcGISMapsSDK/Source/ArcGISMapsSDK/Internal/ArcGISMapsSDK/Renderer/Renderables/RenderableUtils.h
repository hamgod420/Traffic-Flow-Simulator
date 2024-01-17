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

class UMaterialInterface;
class UObject;
class UStaticMesh;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
struct FGPUResourceMesh;
} // namespace GPUResources

namespace Renderables
{
UStaticMesh* BuildStaticMesh(TSharedPtr<const GPUResources::FGPUResourceMesh> InGPUResourceMesh, UObject* InOuter, UMaterialInterface* InMaterial);
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
