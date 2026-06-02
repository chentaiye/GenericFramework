using UnrealBuildTool;

public class VoiceSynthesisDoubao : ModuleRules
{
	public VoiceSynthesisDoubao(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceSynthesisFramework" });
	}
}

