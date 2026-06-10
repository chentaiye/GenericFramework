using System;
using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class VoiceWakeupSdk : ModuleRules
{
	private bool IsArmArchitecture()
	{
		string Architecture = Target.Architecture.ToString().ToLowerInvariant();
		return Architecture.Contains("arm") || Architecture.Contains("aarch");
	}

	private string GetPlatformLibsSubDirectory()
	{
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			return Path.Combine("libs", "Win");
		}

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			return Path.Combine("libs", "Android");
		}

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			return Path.Combine("libs", "iOS");
		}

		string ArchSubDir = IsArmArchitecture() ? "Arm64" : "x64";
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			return Path.Combine("libs", "Mac", ArchSubDir);
		}

		if (Target.Platform.ToString().ToLowerInvariant().Contains("linux"))
		{
			return Path.Combine("libs", "Linux", ArchSubDir);
		}

		return "UNDEFINED_DIRECTORY";
	}

	private string GetPlatformLibsAbsoluteDirectory() => Path.Combine(ModuleDirectory, GetPlatformLibsSubDirectory());
	private string GetRuntimesSubDirectory() => GetPlatformLibsSubDirectory();
	private string GetRuntimesAbsoluteDirectory() => Path.Combine(ModuleDirectory, GetRuntimesSubDirectory());

	private List<string> GetStaticLibraries()
	{
		List<string> Output = new List<string>();
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			Output.Add("msc_x64.lib");
		}
		return Output;
	}

	private List<string> GetDynamicLibraries()
	{
		List<string> Output = new List<string>();
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			Output.Add("msc_x64.dll");
		}
		return Output;
	}

	private bool IsRuntimePlatform()
	{
		return Target.Platform == UnrealTargetPlatform.Win64
			|| Target.Platform == UnrealTargetPlatform.Mac
			|| Target.Platform.ToString().ToLowerInvariant().Contains("linux");
	}

	private void InitializeRuntimeDefinitions()
	{
		List<string> DynamicLibraries = GetDynamicLibraries();
		if (!IsRuntimePlatform() || DynamicLibraries.Count <= 0)
		{
			return;
		}

		PublicDefinitions.Add($"VOICEWAKEUP_WHITELISTED_BINARIES=\"{string.Join(";", DynamicLibraries)}\"");
		if (Target.Type == TargetType.Editor && Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDefinitions.Add($"VOICEWAKEUP_THIRDPARTY_BINARY_SUBDIR=\"{GetRuntimesSubDirectory().Replace(@"\", @"\\")}\"");
			PublicDefinitions.Add($"VOICEWAKEUP_THIRDPARTY_RESOURCE_FILE=\"{Path.Combine("res", "wakeupresource.jet").Replace(@"\", @"\\")}\"");
		}
	}

	public VoiceWakeupSdk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnableExceptions = true;

		PrivateDependencyModuleNames.Add("Core");

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
		InitializeRuntimeDefinitions();

		foreach (string StaticLib in GetStaticLibraries())
		{
			PublicAdditionalLibraries.Add(Path.Combine(GetPlatformLibsAbsoluteDirectory(), StaticLib));
		}

		foreach (string DynamicLib in GetDynamicLibraries())
		{
			PublicDelayLoadDLLs.Add(DynamicLib);
			RuntimeDependencies.Add(Path.Combine(@"$(BinaryOutputDir)", DynamicLib), Path.Combine(GetRuntimesAbsoluteDirectory(), DynamicLib));
		}

		RuntimeDependencies.Add($"{Path.Combine(ModuleDirectory, "res")}/*");
	}
}
