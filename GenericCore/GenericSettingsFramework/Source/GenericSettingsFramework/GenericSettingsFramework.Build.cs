// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenericSettingsFramework : ModuleRules
{
	public GenericSettingsFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
				"GenericCoreFramework",
			}
		);
	}
}
