using UnrealBuildTool;

public class GenericAuthorization : ModuleRules
{
	public GenericAuthorization(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GenericCoreFramework",
				"GenericAuthorizationCore"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"ApplicationCore",
				"InputCore",
				"Slate",
				"SlateCore"
			});
	}
}
