using UnrealBuildTool;

public class GenericWidgetFramework : ModuleRules
{
	public GenericWidgetFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UMG",
				"InputCore",
				"GameplayTags",
				"GenericMessageFramework",
				"EnhancedInput",
				"StateTreeModule",
				"GenericCoreFramework",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
			}
		);
	}
}
