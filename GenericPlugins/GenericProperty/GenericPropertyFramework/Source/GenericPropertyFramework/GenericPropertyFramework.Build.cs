using UnrealBuildTool;

public class GenericPropertyFramework : ModuleRules
{
	public GenericPropertyFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GenericWidgetFramework",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"DeveloperSettings",
				"Slate",
				"SlateCore",
				"CoreUObject",
				"Engine",
				"GameplayTags",
				"UMG",
				"ModelViewViewModel"
			}
		);
	}
}
