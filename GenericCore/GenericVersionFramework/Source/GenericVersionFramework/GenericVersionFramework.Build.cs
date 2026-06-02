// Copyright ChenTaiye 2026. All Rights Reserved.

using UnrealBuildTool;

public class GenericVersionFramework : ModuleRules
{
	public GenericVersionFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
				"GameplayTags",
				"GenericCoreFramework",
				"GenericSettingsFramework",
			}
		);
	}
}
