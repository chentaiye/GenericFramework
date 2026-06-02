using UnrealBuildTool;

public class GenericAssetLoadSystem : ModuleRules
{
	public GenericAssetLoadSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GenericCoreFramework",
				"GenericWidgetFramework"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG",
				"ModelViewViewModel",
				"GameplayTags"
			}
		);
	}
}
