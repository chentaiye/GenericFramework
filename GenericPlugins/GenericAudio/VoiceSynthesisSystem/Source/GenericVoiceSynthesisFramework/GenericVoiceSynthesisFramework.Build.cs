using UnrealBuildTool;

public class GenericVoiceSynthesisFramework : ModuleRules
{
	public GenericVoiceSynthesisFramework(ReadOnlyTargetRules Target) : base(Target)
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

