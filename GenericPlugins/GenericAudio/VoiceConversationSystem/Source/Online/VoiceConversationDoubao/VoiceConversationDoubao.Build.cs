using UnrealBuildTool;

public class VoiceConversationDoubao : ModuleRules
{
	public VoiceConversationDoubao(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceConversationFramework" });
	}
}

