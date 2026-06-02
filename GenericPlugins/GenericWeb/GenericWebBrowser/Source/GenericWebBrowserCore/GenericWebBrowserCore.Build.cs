//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//

using System;
using System.IO;
using UnrealBuildTool;

public class GenericWebBrowserCore : ModuleRules
{
    public GenericWebBrowserCore(ReadOnlyTargetRules Target) : base(Target)
    {
        Console.WriteLine("======= UCefView:UCefView Rules =======");

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrecompileForTargets = PrecompileTargetsType.Any;

        PublicIncludePaths.AddRange(
            new string[] {
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "UMG",
                "Projects",
            }
        );

        PublicDefinitions.Add("UCEFVIEW_API=GENERICWEBBROWSERCORE_API");

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "CefViewCore",

                "TraceLog",
                "CoreUObject",
                "DeveloperSettings",
                "Engine",
                "Json",
                "InputCore",
                "Slate",
                "SlateCore",
                "RenderCore",
                "RHI",
                "RHICore",
                "ApplicationCore",
            }
        );

        if (Target.Type == TargetType.Editor)
        {
            PrivateDependencyModuleNames.Add("SettingsEditor");
        }

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // private dependencies from engine
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                    "D3D11RHI",
                    "D3D12RHI",
                }
            );

            // third-party dependencies
            AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11", "DX12");

            // private include paths from engine
#if UE_5_1_OR_LATER
            // no need private include paths for UE 5.1 or later
#else
            // need private include paths for UE below 5.1
            var EngineFullPath = Path.GetFullPath(Target.RelativeEnginePath);
            PrivateIncludePaths.AddRange(
                new string[] {
                    Path.Combine(EngineFullPath, "Source/Runtime/Windows/D3D11RHI/Private"),
                    Path.Combine(EngineFullPath, "Source/Runtime/Windows/D3D11RHI/Private/Windows"),
                    Path.Combine(EngineFullPath, "Source/Runtime/D3D12RHI/Private"),
                    Path.Combine(EngineFullPath, "Source/Runtime/D3D12RHI/Private/Windows"),
                    Path.Combine(EngineFullPath, "Source/ThirdParty/Windows/D3DX12/Include"),
                }
            );
#endif
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            // private dependencies from engine
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                    "MetalRHI",
                }
            );


            // thirdparty dependencies
#if UE_5_4_OR_LATER
            AddEngineThirdPartyPrivateStaticDependencies(Target, "MetalCPP", "MetalShaderConverter");
#else
            AddEngineThirdPartyPrivateStaticDependencies(Target, "MTLPP");
#endif

            // private include paths from engine
            var EngineFullPath = Path.GetFullPath(Target.RelativeEnginePath);
            PrivateIncludePaths.AddRange(
                new string[] {
                    Path.Combine(EngineFullPath, "Source/Runtime/Apple/MetalRHI/Private"),
                }
            );

            // system dependencies
            PublicFrameworks.AddRange(
                new string[] {
                    "IOSurface",
                    "Metal",
                    "QuartzCore",
                }
            );
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PCHUsage = PCHUsageMode.NoPCHs;
            // Fab does not distribute compiled binaries on Linux platform
            // so we need to turn the bUsePrecompiled switch off
            bUsePrecompiled = false;
        }
        else if (Target.Platform == UnrealTargetPlatform.LinuxArm64)
        {
            PCHUsage = PCHUsageMode.NoPCHs;
            // Fab does not distribute compiled binaries on LinuxArm64 platform
            // so we need to turn the bUsePrecompiled switch off
            bUsePrecompiled = false;
        }
        else
        {
            throw new NotSupportedException($"UCefView:UCefView:Unsupported target platform {Target.Platform.ToString()}");
        }

        // trial build 
        if (Environment.GetEnvironmentVariable("UCEFVIEW_BUILD_TRIAL") == "1")
        {
            Console.WriteLine($"UCEFVIEW_BUILD_TRIAL=1 build trial version");
            PrivateDefinitions.Add("ENABLE_TRIAL_WATERMARK=1");
        }
    }
}
