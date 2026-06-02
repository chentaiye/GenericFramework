using UnrealBuildTool;

public class VoiceWakeupXfyun : ModuleRules
{
	public VoiceWakeupXfyun(ReadOnlyTargetRules Target) : base(Target)
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
				"GenericVoiceWakeupFramework",
				"VoiceWakeupSdk"
			});

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicSystemLibraries.Add("winmm.lib");
		}
	}
}

