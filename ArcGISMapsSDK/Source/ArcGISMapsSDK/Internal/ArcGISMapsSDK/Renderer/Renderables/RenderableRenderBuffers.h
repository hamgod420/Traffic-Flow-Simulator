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

class FColorVertexBuffer;
class FDynamicMeshIndexBuffer32;
class FPositionVertexBuffer;
class FStaticMeshVertexBuffer;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
struct FRenderableRenderBuffers
{
	const FColorVertexBuffer* ColorVertexBuffer;
	const FDynamicMeshIndexBuffer32* IndexBuffer;
	const FPositionVertexBuffer* PositionVertexBuffer;
	const FStaticMeshVertexBuffer* StaticMeshVertexBuffer;

	uint32 NumIndices;
	uint32 NumVertices;
};
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
