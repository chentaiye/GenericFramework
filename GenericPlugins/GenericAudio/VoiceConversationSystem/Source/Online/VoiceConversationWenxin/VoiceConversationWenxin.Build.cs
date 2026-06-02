using UnrealBuildTool;

public class VoiceConversationWenxin : ModuleRules
{
	public VoiceConversationWenxin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceConversationFramework" });
	}
}

