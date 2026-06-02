using UnrealBuildTool;

public class GenericWorldWidgetEdFramework : ModuleRules
{
	public GenericWorldWidgetEdFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UMG",
				"GenericCoreFramework",
				"GenericWidgetFramework",
				"GenericWorldWidgetFramework",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				"UnrealEd",
				"LevelEditor",
				"InputCore",
			}
		);
	}
}
