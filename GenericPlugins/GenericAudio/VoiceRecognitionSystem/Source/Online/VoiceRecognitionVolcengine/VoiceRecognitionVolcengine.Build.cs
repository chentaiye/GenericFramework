using UnrealBuildTool;

public class VoiceRecognitionVolcengine : ModuleRules
{
	public VoiceRecognitionVolcengine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Projects",
				"GenericVoiceFramework",
				"GenericVoiceRecognitionFramework",
				"VoiceVolcEngineRTC"
			});
	}
}

