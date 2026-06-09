using UnrealBuildTool;

public class AspectSystem : ModuleRules
{
    public AspectSystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GenericCoreFramework",
                "GenericGeometryFramework",
                "ProceduralMeshComponent"
            });
    }
}
