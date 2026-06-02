using UnrealBuildTool;

public class GenericVoiceRecognitionFramework : ModuleRules
{
	public GenericVoiceRecognitionFramework(ReadOnlyTargetRules Target) : base(Target)
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

