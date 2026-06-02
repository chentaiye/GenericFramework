using UnrealBuildTool;

public class GenericMenuFramework : ModuleRules
{
    public GenericMenuFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
                "GenericMessageFramework",
                "StateTreeModule",
                "SlateCore",
                "UMG",
                "GenericCoreFramework",
                "GenericButtonFramework",
                "GenericWidgetFramework",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
            }
        );
    }
}
