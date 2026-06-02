using UnrealBuildTool;

public class GenericButtonFramework : ModuleRules
{
    public GenericButtonFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "UMG",
                "SlateCore",
                "GameplayTags",
                "GenericMessageFramework",
                "GenericWidgetFramework",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "InputCore",
                "Slate",
                "UnrealMisc",
            }
        );
    }
}
