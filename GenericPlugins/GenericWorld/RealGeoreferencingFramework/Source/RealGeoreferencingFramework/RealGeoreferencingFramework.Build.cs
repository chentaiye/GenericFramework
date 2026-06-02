using UnrealBuildTool;

public class RealGeoreferencingFramework : ModuleRules
{
	public RealGeoreferencingFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GameplayTags",
				"GenericCoreFramework",
				"GenericSettingsFramework"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"GeoReferencing",
				"Projects",
				"PROJ",
				"SQLiteCore"
			}
		);
	}
}
