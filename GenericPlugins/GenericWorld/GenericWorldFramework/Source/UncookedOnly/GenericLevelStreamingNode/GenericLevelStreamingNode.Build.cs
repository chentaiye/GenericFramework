using UnrealBuildTool;

public class GenericLevelStreamingNode : ModuleRules
{
    public GenericLevelStreamingNode(ReadOnlyTargetRules Target) : base(Target)
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
                "GenericLevelStreamingFramework",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "BlueprintGraph",
                "KismetCompiler",
                "UnrealEd",
                "GraphEditor",
                "ToolMenus"
            }
        );
    }
}
