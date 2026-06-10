using UnrealBuildTool;

public class GenericMenuEdFramework : ModuleRules
{
    public GenericMenuEdFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GenericMenuFramework",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "AssetDefinition",
                "AssetRegistry",
                "AssetTools",
                "BlueprintGraph",
                "ContentBrowser",
                "GameplayTags",
                "GraphEditor",
                "InputCore",
                "Kismet",
                "KismetCompiler",
                "PropertyEditor",
                "Slate",
                "SlateCore",
                "ToolMenus",
                "UnrealEd",
            }
        );
    }
}
