using UnrealBuildTool;

public class GenericSettingsEdFramework : ModuleRules
{
	public GenericSettingsEdFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"EditorSubsystem",
				"GenericSettingsFramework",
				"Settings",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AppFramework",
				"DeveloperSettings",
				"GenericEditorFramework",
				"GenericSlateFramework",
				"AssetRegistry",
				"InputCore",
				"PropertyEditor",
				"Projects",
				"SettingsEditor",
				"Slate",
				"SlateCore",
				"ToolMenus",
				"UnrealEd",
			}
		);
	}
}
