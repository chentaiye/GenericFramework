using UnrealBuildTool;

public class VoiceWakeupDoubao : ModuleRules
{
	public VoiceWakeupDoubao(ReadOnlyTargetRules Target) : base(Target)
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

