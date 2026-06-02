using UnrealBuildTool;

public class VoiceSynthesisVolcengine : ModuleRules
{
	public VoiceSynthesisVolcengine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceSynthesisFramework" });
	}
}

