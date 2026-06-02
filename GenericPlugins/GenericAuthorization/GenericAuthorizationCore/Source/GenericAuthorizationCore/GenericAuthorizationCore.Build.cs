using UnrealBuildTool;

public class GenericAuthorizationCore : ModuleRules
{
	public GenericAuthorizationCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"GenericSettingsFramework"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"DeveloperSettings",
				"Json",
				"JsonUtilities",
				"Projects"
			});
	}
}
