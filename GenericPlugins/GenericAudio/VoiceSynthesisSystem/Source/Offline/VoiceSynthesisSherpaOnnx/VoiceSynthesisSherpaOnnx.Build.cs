using UnrealBuildTool;

public class VoiceSynthesisSherpaOnnx : ModuleRules
{
	public VoiceSynthesisSherpaOnnx(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceSynthesisFramework" });
	}
}

