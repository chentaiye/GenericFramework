using UnrealBuildTool;

public class GenericVoiceWakeupFramework : ModuleRules
{
	public GenericVoiceWakeupFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GenericVoiceFramework"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"DeveloperSettings"
			});
	}
}

