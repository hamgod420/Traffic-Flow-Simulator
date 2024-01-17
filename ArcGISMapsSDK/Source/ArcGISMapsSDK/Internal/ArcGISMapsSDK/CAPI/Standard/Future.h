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

#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/FutureCompletedEvent.h"
#include "ArcGISMapsSDK/CAPI/Standard/FutureHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/FutureStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Task_destroy(RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_Task_cancel(RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Task_get(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_Task_getError(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Task_isCanceled(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Task_isDone(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_TaskStatus RT_Task_wait(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_Task_setTaskCompletedCallback(RT_TaskHandle thisHandle, RT_TaskCompletedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif