// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenericMessageFramework : ModuleRules
{
	public GenericMessageFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;				

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GameplayTags",
				"StateTreeModule"
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
			});
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			});
	}
}
