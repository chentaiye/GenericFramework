// Copyright ChenTaiye 2025. All Rights Reserved.

using UnrealBuildTool;

public class NativeAPI : ModuleRules
{
	public NativeAPI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...

				"Core",
				"GenericCoreFramework",
				"GenericSettingsFramework",
				"GenericJson",
				"GenericProtocol"
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	

				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"WebSockets",
				"HTTPServer",
				"Json",
				"JsonUtilities",
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		if (Target.bBuildEditor) PrivateDependencyModuleNames.Add("UnrealEd");
	}
}
