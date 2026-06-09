using UnrealBuildTool;

public class FlyLineSystem : ModuleRules
{
    public FlyLineSystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GenericCoreFramework",
                "GameplayTags",
                "GenericGeometryFramework"
            });
    }
}
