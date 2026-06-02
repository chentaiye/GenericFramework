using UnrealBuildTool;

public class VoiceWakeupSherpaOnnx : ModuleRules
{
	public VoiceWakeupSherpaOnnx(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GenericVoiceFramework",
				"GenericVoiceWakeupFramework"
			});
	}
}

