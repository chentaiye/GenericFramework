using UnrealBuildTool;

public class VoiceWakeupPicovoice : ModuleRules
{
	public VoiceWakeupPicovoice(ReadOnlyTargetRules Target) : base(Target)
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

