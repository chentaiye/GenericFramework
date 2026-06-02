using UnrealBuildTool;

public class VoiceConversationDify : ModuleRules
{
	public VoiceConversationDify(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework", "GenericVoiceConversationFramework" });
	}
}

