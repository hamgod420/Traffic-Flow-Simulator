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
using System;
using System.IO;
using UnrealBuildTool;

public class ArcGISMapsSDK : ModuleRules
{
    private string GetWindowsTargetArchitecture(ReadOnlyTargetRules Target)
    {
#if UE_5_2_OR_LATER
        return Target.Architecture.WindowsName;
#else
        return Target.Architecture;
#endif
    }

    public ArcGISMapsSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        bEnableExceptions = true;
#if UE_5_2_OR_LATER
        IWYUSupport = IWYUSupport.None;
#else
        bEnforceIWYU = false;
#endif

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivatePCHHeaderFile = "Private/ArcGISMapsSDKPrivatePCH.h";

        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Internal"));

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "Engine",
            "GeoReferencing"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Chaos",
            "CoreUObject",
            "EngineSettings",
            "HTTP",
            "Projects",
            "RenderCore",
            "RHI"
        });

        if (Target.Type == TargetType.Editor)
        {
            PrivateDependencyModuleNames.Add("UnrealEd");
        }

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "AndroidLowMemoryHandlerUPL.xml"));

            // Copy library files to the building folder
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "ArcGISMapsSDK_APL.xml"));

            // Add the library
            PublicAdditionalLibraries.Add("$(PluginDir)/Source/ThirdParty/ArcGISMapsSDK/Android/arm64/libruntimecore.so");
        }

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            // Add the import library
            PublicAdditionalFrameworks.Add(
                new Framework(
                    "Runtimecore",
                    Path.Combine(ModuleDirectory, "..", "..", "Source/ThirdParty/ArcGISMapsSDK/IOS/Runtimecore.framework"),
                    null,
                    true
                )
            );

            PublicFrameworks.AddRange(new string[] {
                "CoreText"
            });
        }

        if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            string BinariesSubFolder = Path.Combine("Source", "ThirdParty", "ArcGISMapsSDK", "Mac");
            string BinariesName = "libruntimecore.dylib";

            // If the universal binary is not present, try to find the individual ones
            if (!File.Exists(Path.Combine(PluginDirectory, BinariesSubFolder, BinariesName)))
            {
                if (File.Exists(Path.Combine(PluginDirectory, BinariesSubFolder, "x86_64", BinariesName)))
                {
                    BinariesSubFolder = Path.Combine(BinariesSubFolder, "x86_64");
                }
                else if (File.Exists(Path.Combine(PluginDirectory, BinariesSubFolder, "arm64", BinariesName)))
                {
                    BinariesSubFolder = Path.Combine(BinariesSubFolder, "arm64");
                }
            }

            PublicDefinitions.Add(string.Format("THIRDPARTY_BINARY_SUBFOLDER=\"{0}\"", BinariesSubFolder.Replace(@"\", @"\\")));
            PublicDefinitions.Add(string.Format("THIRDPARTY_BINARY_NAME=\"{0}\"", BinariesName));

            RuntimeDependencies.Add(Path.Combine(PluginDirectory, BinariesSubFolder, BinariesName));
        }

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicDefinitions.AddRange(new string[] {
                "_CRT_SECURE_NO_WARNINGS"
            });

            // Add the import library
            PublicAdditionalLibraries.Add("$(PluginDir)/Source/ThirdParty/ArcGISMapsSDK/Win64/runtimecore.lib");

            RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/ArcGISMapsSDK/Win64/runtimecore.dll");

            PublicDelayLoadDLLs.Add("runtimecore.dll");
        }

#if !UE_5_3_OR_LATER
        if (Target.Platform == UnrealTargetPlatform.HoloLens)
        {
            PublicDefinitions.AddRange(new string[] {
                "_CRT_SECURE_NO_WARNINGS"
            });

            string BinariesSubFolder = Path.Combine("Source", "ThirdParty", "ArcGISMapsSDK", "HoloLens", GetWindowsTargetArchitecture(Target));
            string BinariesName = "runtimecore.dll";

            PublicDefinitions.Add(string.Format("THIRDPARTY_BINARY_SUBFOLDER=\"{0}\"", BinariesSubFolder.Replace(@"\", @"\\")));
            PublicDefinitions.Add(string.Format("THIRDPARTY_BINARY_NAME=\"{0}\"", BinariesName));

            RuntimeDependencies.Add(Path.Combine(PluginDirectory, BinariesSubFolder, BinariesName));
        }
#endif
    }
}
