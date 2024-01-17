// COPYRIGHT 1995-2021 ESRI
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
#if PLATFORM_ANDROID
#include "jni.h"

#include "ArcGISMapsSDK/Memory/ArcGISAndroidDefaultMemorySystemHandler.h"

extern "C" {
JNIEXPORT void Java_com_epicgames_unreal_GameActivity_nativeArcGISOnLowMemory(JNIEnv* /*jni*/, jclass /*javaClass*/)
{
	FArcGISAndroidDefaultMemorySystemHandler::NotifyLowMemoryWarning();
}

JNIEXPORT void Java_com_epicgames_unreal_GameActivity_nativeArcGISOnTrimMemory(JNIEnv* /*jni*/, jclass /*javaClass*/, jint level)
{
	if (level == /* TRIM_MEMORY_RUNNING_CRITICAL */ 15)
	{
		FArcGISAndroidDefaultMemorySystemHandler::NotifyLowMemoryWarning();
	}
}
} // extern "C"
#endif
