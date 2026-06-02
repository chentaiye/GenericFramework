using UnrealBuildTool;

public class VoiceSynthesisWenxin : ModuleRules
{
	public VoiceSynthesisWenxin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceSynthesisFramework" });
	}
}

