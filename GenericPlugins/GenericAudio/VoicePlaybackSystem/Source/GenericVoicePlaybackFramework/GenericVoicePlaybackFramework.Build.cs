using UnrealBuildTool;

public class GenericVoicePlaybackFramework : ModuleRules
{
	public GenericVoicePlaybackFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "GenericVoiceFramework" });
		PrivateDependencyModuleNames.AddRange(new[] { "DeveloperSettings" });
	}
}

