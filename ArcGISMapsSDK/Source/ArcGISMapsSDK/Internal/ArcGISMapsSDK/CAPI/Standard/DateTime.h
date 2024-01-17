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

#include "ArcGISMapsSDK/CAPI/Standard/DateTimeHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_DateTime_destroy(RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_DateTimeHandle RT_DateTime_create(const RT_ErrorHandler* errorHandler);

bool RT_DateTime_add(RT_DateTimeHandle thisHandle, int64_t milliseconds, const RT_ErrorHandler* errorHandler);
bool RT_DateTime_equals(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_fromFileTime(int64_t time, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_fromOLE(double time, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_fromString(const char* time, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_fromUnixMilliseconds(int64_t time, const RT_ErrorHandler* errorHandler);
bool RT_DateTime_greaterThan(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler);
bool RT_DateTime_greaterThanOrEqual(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler);
bool RT_DateTime_lessThan(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler);
bool RT_DateTime_lessThanOrEqual(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_max(const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_min(const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_DateTime_now(const RT_ErrorHandler* errorHandler);
bool RT_DateTime_subtract(RT_DateTimeHandle thisHandle, int64_t milliseconds, const RT_ErrorHandler* errorHandler);
int64_t RT_DateTime_toFileTime(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_DateTime_toOLE(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_DateTime_toString(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler);
int64_t RT_DateTime_toUnixMilliseconds(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif