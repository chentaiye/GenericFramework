using UnrealBuildTool;

public class VoiceConversationLocal : ModuleRules
{
	public VoiceConversationLocal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceConversationFramework" });
	}
}

