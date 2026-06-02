using UnrealBuildTool;

public class ExtraProc : ModuleRules
{
	public ExtraProc(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"UnrealMisc",
				"GenericCoreFramework",
				"GenericSettingsFramework"
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
				"DeveloperSettings",
				"GenericThreadSystem"
			}
		);

		if (Target.bBuildEditor) PrivateDependencyModuleNames.Add("UnrealEd");

		RuntimeDependencies.Add("$(ProjectDir)/Extras/...", StagedFileType.NonUFS);
	}
}
