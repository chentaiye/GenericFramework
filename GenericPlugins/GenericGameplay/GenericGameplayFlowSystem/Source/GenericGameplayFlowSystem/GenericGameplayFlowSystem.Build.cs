using UnrealBuildTool;

public class GenericGameplayFlowSystem : ModuleRules
{
	public GenericGameplayFlowSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GameplayTags",
				"StateTreeModule",
				"GenericCoreFramework",
				"GenericSettingsFramework",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
