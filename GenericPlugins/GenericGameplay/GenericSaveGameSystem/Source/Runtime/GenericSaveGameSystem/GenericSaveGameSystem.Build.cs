using UnrealBuildTool;

public class GenericSaveGameSystem : ModuleRules
{
	public GenericSaveGameSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
				"GameplayTags",
				"GenericMessageFramework",
				"GenericCoreFramework",
				"GenericSettingsFramework",
				"GenericVersionFramework",
			}
		);
	}
}
