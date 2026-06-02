using UnrealBuildTool;

public class GenericVoiceConversationFramework : ModuleRules
{
	public GenericVoiceConversationFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework" });
		PrivateDependencyModuleNames.AddRange(new[] { "DeveloperSettings" });
	}
}

