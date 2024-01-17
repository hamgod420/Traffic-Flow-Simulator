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

#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Geometry/DatumTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Geometry/GeographicTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Geometry/GeometryHandle.h"
#include "ArcGISMapsSDK/CAPI/ArcGISRuntime/Geometry/HorizontalVerticalTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/GEAttributeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/GEBuildingSceneLayerAttributeStatisticsHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/GEVisualizationAttributeDescriptionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/GEVisualizationAttributeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfigurationHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Element_destroy(RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ElementHandle RT_Element_fromDatumTransformation(const RT_DatumTransformationHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromDictionary(const RT_DictionaryHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromFloat64(double value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEAttribute(const RT_GEAttributeHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEAuthenticationConfiguration(const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEBuildingSceneLayerAttributeStatistics(const RT_GEBuildingSceneLayerAttributeStatisticsHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGeographicTransformationStep(const RT_GeographicTransformationStepHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGeometry(const RT_GeometryHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEVisualizationAttribute(const RT_GEVisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEVisualizationAttributeDescription(const RT_GEVisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromHorizontalVerticalTransformationStep(const RT_HorizontalVerticalTransformationStepHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromString(const char* value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromUInt32(uint32_t value, const RT_ErrorHandler* errorHandler);
RT_DatumTransformationHandle RT_Element_getValueAsDatumTransformation(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DictionaryHandle RT_Element_getValueAsDictionary(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Element_getValueAsFloat64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEAttributeHandle RT_Element_getValueAsGEAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEAuthenticationConfigurationHandle RT_Element_getValueAsGEAuthenticationConfiguration(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEBuildingSceneLayerAttributeStatisticsHandle RT_Element_getValueAsGEBuildingSceneLayerAttributeStatistics(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GeographicTransformationStepHandle RT_Element_getValueAsGeographicTransformationStep(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_Element_getValueAsGeometry(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEVisualizationAttributeHandle RT_Element_getValueAsGEVisualizationAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEVisualizationAttributeDescriptionHandle RT_Element_getValueAsGEVisualizationAttributeDescription(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_HorizontalVerticalTransformationStepHandle RT_Element_getValueAsHorizontalVerticalTransformationStep(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Element_getValueAsString(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint32_t RT_Element_getValueAsUInt32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromDatumTransformation(RT_ElementHandle thisHandle, const RT_DatumTransformationHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromDictionary(RT_ElementHandle thisHandle, const RT_DictionaryHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromFloat64(RT_ElementHandle thisHandle, double value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGEAttribute(RT_ElementHandle thisHandle, const RT_GEAttributeHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGEAuthenticationConfiguration(RT_ElementHandle thisHandle, const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGeographicTransformationStep(RT_ElementHandle thisHandle, const RT_GeographicTransformationStepHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGeometry(RT_ElementHandle thisHandle, const RT_GeometryHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGEVisualizationAttribute(RT_ElementHandle thisHandle, const RT_GEVisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGEVisualizationAttributeDescription(RT_ElementHandle thisHandle, const RT_GEVisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromHorizontalVerticalTransformationStep(RT_ElementHandle thisHandle, const RT_HorizontalVerticalTransformationStepHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromString(RT_ElementHandle thisHandle, const char* value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromUInt32(RT_ElementHandle thisHandle, uint32_t value, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif