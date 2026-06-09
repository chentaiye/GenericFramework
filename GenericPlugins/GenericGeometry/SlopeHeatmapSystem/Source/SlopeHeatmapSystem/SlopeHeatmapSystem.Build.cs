using UnrealBuildTool;

public class SlopeHeatmapSystem : ModuleRules
{
    public SlopeHeatmapSystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GenericCoreFramework",
                "GenericGeometryFramework"
            });
    }
}
