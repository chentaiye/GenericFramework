using UnrealBuildTool;

public class GenericWorldWidgetFramework : ModuleRules
{
    public GenericWorldWidgetFramework(ReadOnlyTargetRules Target) : base(Target)
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
                "EnhancedInput",
                "GameplayTags",
                "GenericMessageFramework",
                "GenericCoreFramework",
                "GenericWidgetFramework",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
                "UnrealMisc",
            }
        );
    }
}
