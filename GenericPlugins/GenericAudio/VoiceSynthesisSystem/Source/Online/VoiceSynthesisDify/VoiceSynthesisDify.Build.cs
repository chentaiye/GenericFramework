using UnrealBuildTool;

public class VoiceSynthesisDify : ModuleRules
{
	public VoiceSynthesisDify(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceSynthesisFramework" });
	}
}

