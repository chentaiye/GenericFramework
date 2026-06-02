using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class VoiceVolcEngineRTC : ModuleRules
{
	private string GetPlatformLibsSubDirectory()
	{
		return Target.Platform == UnrealTargetPlatform.Win64 ? Path.Combine("lib", "x64") : "UNDEFINED_DIRECTORY";
	}

	private string GetPlatformLibsAbsoluteDirectory() => Path.Combine(ModuleDirectory, GetPlatformLibsSubDirectory());
	private string GetRuntimesSubDirectory() => Target.Platform == UnrealTargetPlatform.Win64 ? Path.Combine("bin", "x64") : "UNDEFINED_DIRECTORY";
	private string GetRuntimesAbsoluteDirectory() => Path.Combine(ModuleDirectory, GetRuntimesSubDirectory());

	private List<string> GetStaticLibraries()
	{
		List<string> Output = new List<string>();
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			Output.Add("VolcEngineRTC.lib");
		}
		return Output;
	}

	private List<string> GetDynamicLibraries()
	{
		List<string> Output = new List<string>();
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			Output.AddRange(new[]
			{
				"bdaudioeffect-mt.dll",
				"bytertc_fdk-aac_extension.dll",
				"bytertc_ffmpeg_audio_extension.dll",
				"bytertc_nico_extension.dll",
				"bytertc_vp8codec_extension.dll",
				"effect.dll",
				"libEGL.dll",
				"libGLESv2.dll",
				"openh264-4.dll",
				"pthreadVC2.dll",
				"RTCFFmpeg.dll",
				"VolcEngineRTC.dll"
			});
		}
		return Output;
	}

	private bool IsRuntimePlatform()
	{
		return Target.Platform == UnrealTargetPlatform.Win64;
	}

	private void InitializeRuntimeDefinitions()
	{
		List<string> DynamicLibraries = GetDynamicLibraries();
		if (!IsRuntimePlatform() || DynamicLibraries.Count <= 0)
		{
			return;
		}

		PublicDefinitions.Add($"VOLCENGINERTC_WHITELISTED_BINARIES=\"{string.Join(";", DynamicLibraries)}\"");
		if (Target.Type == TargetType.Editor && Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDefinitions.Add($"VOLCENGINERTC_THIRDPARTY_BINARY_ABSOLUTEDIR=\"{GetRuntimesAbsoluteDirectory().Replace(@"\", @"\\")}\"");
		}
	}

	public VoiceVolcEngineRTC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		Type = ModuleType.External;
		bEnableExceptions = true;

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

		RuntimeDependencies.Add($"{Path.Combine(ModuleDirectory, "bin")}/*");
	}
}
