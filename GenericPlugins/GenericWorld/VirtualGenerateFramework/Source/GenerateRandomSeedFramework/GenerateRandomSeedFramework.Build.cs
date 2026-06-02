using UnrealBuildTool;

public class GenerateRandomSeedFramework : ModuleRules
{
    public GenerateRandomSeedFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GenericCoreFramework", "GenericSettingsFramework" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
