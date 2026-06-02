using UnrealBuildTool;

public class SkylineSystem : ModuleRules
{
    public SkylineSystem(ReadOnlyTargetRules Target) : base(Target)
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

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
