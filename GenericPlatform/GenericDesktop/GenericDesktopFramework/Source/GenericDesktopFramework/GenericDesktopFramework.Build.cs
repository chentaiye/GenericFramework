// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenericDesktopFramework : ModuleRules
{
	public GenericDesktopFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"RenderCore"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"ApplicationCore",
				"CoreUObject",
				"Engine",
				"ImageWrapper",
				"Projects",
				"RHI",
				"Slate",
				"SlateCore"
			}
		);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicSystemLibraries.AddRange(
				new string[]
				{
					"iphlpapi.lib",
					"ole32.lib",
					"psapi.lib",
					"shell32.lib",
					"shlwapi.lib",
					"user32.lib",
					"uuid.lib"
				}
			);
		}
	}
}