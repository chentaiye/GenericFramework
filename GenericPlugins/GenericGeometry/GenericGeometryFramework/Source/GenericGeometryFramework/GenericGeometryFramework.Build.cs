using UnrealBuildTool;

public class GenericGeometryFramework : ModuleRules
{
    public GenericGeometryFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
                "ProceduralMeshComponent"
            });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(
                new[]
                {
                    "AssetRegistry",
                    "MaterialEditor",
                    "UnrealEd"
                });
        }
    }
}
