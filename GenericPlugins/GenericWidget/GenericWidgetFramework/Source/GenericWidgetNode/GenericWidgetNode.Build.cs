using UnrealBuildTool;

public class GenericWidgetNode : ModuleRules
{
    public GenericWidgetNode(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GenericWidgetFramework",
                "CoreUObject",
                "Engine",
                "UMG",
                "Slate",
                "SlateCore",
                "BlueprintGraph",
                "KismetCompiler",
                "UnrealEd",
                "GraphEditor",
                "ToolMenus",
                "GameplayTags",
                "InputCore",
                "EnhancedInput",
            }
        );
    }
}
