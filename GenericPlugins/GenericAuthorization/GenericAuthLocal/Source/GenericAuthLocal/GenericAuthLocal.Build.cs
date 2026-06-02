// Copyright ChenTaiye 2026. All Rights Reserved.

using UnrealBuildTool;

public class GenericAuthLocal : ModuleRules
{
	public GenericAuthLocal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"GenericAuthorizationCore"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine"
			});
	}
}
