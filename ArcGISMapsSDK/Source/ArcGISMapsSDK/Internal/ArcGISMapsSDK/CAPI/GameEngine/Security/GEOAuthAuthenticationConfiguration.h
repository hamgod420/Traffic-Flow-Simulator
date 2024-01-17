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

#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthenticationConfigurationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthorizationCredentialHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthorizationCredentialIssuedEvent.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEOAuthAuthenticationConfiguration_destroy(RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEOAuthAuthenticationConfigurationHandle RT_GEOAuthAuthenticationConfiguration_create(const char* clientId, const char* clientSecret, const char* redirectURI, const RT_ErrorHandler* errorHandler);
RT_GEOAuthAuthenticationConfigurationHandle RT_GEOAuthAuthenticationConfiguration_createWithCredential(const char* clientId, const char* clientSecret, const char* redirectURI, const RT_GEOAuthAuthorizationCredentialHandle authenticationCredential, const RT_ErrorHandler* errorHandler);

RT_GEOAuthAuthorizationCredentialHandle RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getClientId(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getClientSecret(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getRedirectURI(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback(RT_GEOAuthAuthenticationConfigurationHandle thisHandle, RT_GEOAuthAuthorizationCredential_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif