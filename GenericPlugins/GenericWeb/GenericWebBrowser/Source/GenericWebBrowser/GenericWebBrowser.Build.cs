using UnrealBuildTool;

public class GenericWebBrowser : ModuleRules
{
	public GenericWebBrowser(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"GenericWebFramework",
				"UMG"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"Slate",
				"SlateCore",
				"GenericWebBrowserCore"
			});

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("WebBrowser");
		}
	}
}
