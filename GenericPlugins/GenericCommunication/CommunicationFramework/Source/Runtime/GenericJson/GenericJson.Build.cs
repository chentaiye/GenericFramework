using UnrealBuildTool;

public class GenericJson : ModuleRules
{
	public GenericJson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GenericCoreFramework",
				"UnrealMisc"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"GenericDesktopFramework",
				"Slate",
				"SlateCore",

				"Json",
				"JsonUtilities",
			}
		);
	}
}
