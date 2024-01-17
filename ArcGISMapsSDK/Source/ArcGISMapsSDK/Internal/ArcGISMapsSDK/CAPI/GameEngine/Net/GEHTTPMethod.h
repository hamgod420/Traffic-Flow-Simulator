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

#include "ArcGISMapsSDK/CAPI/Platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum RT_GEHTTPMethod
{
    RT_GEHTTPMethod_delete = 0,
    RT_GEHTTPMethod_get = 1,
    RT_GEHTTPMethod_head = 2,
    RT_GEHTTPMethod_options = 3,
    RT_GEHTTPMethod_patch = 4,
    RT_GEHTTPMethod_post = 5,
    RT_GEHTTPMethod_put = 6,
    RT_GEHTTPMethod_unknown = -1
} RT_GEHTTPMethod;

#ifdef __cplusplus
} // extern "C"
#endif