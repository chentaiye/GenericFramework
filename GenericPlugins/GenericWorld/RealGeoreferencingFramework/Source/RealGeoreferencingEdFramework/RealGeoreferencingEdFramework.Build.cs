using UnrealBuildTool;

public class RealGeoreferencingEdFramework : ModuleRules
{
	public RealGeoreferencingEdFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"PropertyEditor",
				"RealGeoreferencingFramework",
				"Slate",
				"SlateCore"
			}
		);
	}
}
