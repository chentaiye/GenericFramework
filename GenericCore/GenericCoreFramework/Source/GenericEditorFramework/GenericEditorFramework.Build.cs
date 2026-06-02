using UnrealBuildTool;

public class GenericEditorFramework : ModuleRules
{
	public GenericEditorFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrecompileForTargets = PrecompileTargetsType.Any;
		bUsePrecompiled = false;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GenericCoreFramework",
				"GenericSlateFramework",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",

				"EditorSubsystem",
				"UnrealEd",
				"ToolMenus",
				"Blutility",
				"LevelEditor",
				"AssetTools",
				"ClassViewer",
				"Settings",
				"SettingsEditor",
				"GraphEditor",
				"BlueprintGraph",
				"SubobjectEditor",
				"AssetDefinition",
				"InputCore",
				"Projects",
				"GameplayTags"
			}
		);
	}
}
