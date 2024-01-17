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

#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthorizationCredentialHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/DateTimeHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEOAuthAuthorizationCredential_destroy(RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEOAuthAuthorizationCredentialHandle RT_GEOAuthAuthorizationCredential_create(const char* accessToken, const RT_DateTimeHandle expirationDate, const char* refreshToken, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_GEOAuthAuthorizationCredential_getAccessToken(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DateTimeHandle RT_GEOAuthAuthorizationCredential_getExpirationDate(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEOAuthAuthorizationCredential_getRefreshToken(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif