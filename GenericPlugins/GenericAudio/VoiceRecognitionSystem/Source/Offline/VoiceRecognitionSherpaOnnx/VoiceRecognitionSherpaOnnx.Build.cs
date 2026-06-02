using UnrealBuildTool;

public class VoiceRecognitionSherpaOnnx : ModuleRules
{
	public VoiceRecognitionSherpaOnnx(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GenericVoiceFramework",
				"GenericVoiceRecognitionFramework"
			});
	}
}

