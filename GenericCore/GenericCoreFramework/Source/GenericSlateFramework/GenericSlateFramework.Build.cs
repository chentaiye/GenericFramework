using UnrealBuildTool;

public class GenericSlateFramework : ModuleRules
{
	public GenericSlateFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrecompileForTargets = PrecompileTargetsType.Any;
		bUsePrecompiled = false;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"SlateCore",
				"UnrealMisc"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"InputCore",
				"Projects",
				"UMG",
				"GameplayTags"
			}
		);

		if (Target.bBuildEditor) PrivateDependencyModuleNames.Add("UnrealEd");
	}
}
