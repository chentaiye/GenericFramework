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
                "AssetTools",
                "BlueprintGraph",
                "ContentBrowser",
                "GraphEditor",
                "Kismet",
                "KismetCompiler",
                "PropertyEditor",
                "Slate",
                "SlateCore",
                "UnrealEd",
            }
        );
    }
}
