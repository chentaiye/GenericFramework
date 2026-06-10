using UnrealBuildTool;

public class LevelSequenceSystem : ModuleRules
{
	public LevelSequenceSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GenericCameraSystem",
				"GenericCoreFramework",
				"GenericMessageFramework",
				"GenericMovieSceneSystem",
				"GameplayTags",
				"LevelSequence",
				"MovieScene",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
			}
		);
	}
}
