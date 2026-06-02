//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//

using System;
using System.Diagnostics;
using System.IO;
using UnrealBuildTool;

public class CefViewCore : ModuleRules
{
    public CefViewCore(ReadOnlyTargetRules Target) : base(Target)
    {
        Console.WriteLine("======= UCefView:CefViewCore Rules =======");
        Type = ModuleType.External;

        // add definitions
        PublicDefinitions.AddRange(
            new string[]{
                "USING_CEF_SHARED=0",
            });

        var TargetPlatform = Target.Platform.ToString();
        var SourceIncDir = Path.Combine(ModuleDirectory, "include", TargetPlatform);
        var SourceLibDir = Path.Combine(ModuleDirectory, "lib", TargetPlatform);
        var SourceBinDir = Path.Combine(ModuleDirectory, "bin", TargetPlatform);
        var OutputBinDir = Path.Combine(
                new string[] {
                    Path.GetFullPath(PluginDirectory),
                    "Binaries",
                    "ThirdParty",
                    "CefViewCore",
                    TargetPlatform
                }
            );

        SyncRuntimeDependencyDirectory(SourceBinDir, OutputBinDir);

        // add runtime dependencies
        RuntimeDependencies.Add(Path.Combine(OutputBinDir, "..."));

        // add include directories
        PublicIncludePaths.Add(Path.Combine(SourceIncDir, "cef"));
        PublicIncludePaths.Add(Path.Combine(SourceIncDir, "CefViewCore"));

        // platform configuration
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // add definitions
            PublicDefinitions.AddRange(
                new string[]{
                    "OS_WINDOWS=1",
                });

            // add the import libraries
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libcef_dll_wrapper.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libcef.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "CefViewCore.lib"));

            // make libcef.dll delay load
            PublicDelayLoadDLLs.Add("libcef.dll");

            // restore UCefViewHelper.exe in the output directory when needed
            RestoreWindowsUCefViewHelperExe(OutputBinDir);
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            // add definitions
            PublicDefinitions.AddRange(
                new string[]{
                    "OS_MACOS=1",
                    "OS_POSIX=1",
                });

            // add the import libraries and framework
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libcef_dll_wrapper.a"));
            PublicFrameworks.Add(Path.Combine(SourceLibDir, "CefViewCore.framework"));

            // ensure file permission
            EnsureUnixFileExecutePermission(OutputBinDir);
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            // add definitions
            PublicDefinitions.AddRange(
                new string[]{
                    "OS_LINUXS=1",
                    "OS_POSIX=1",
                });

            // add the import libraries and framework
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libcef_dll_wrapper.a"));
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libCefViewCore.a"));
            PublicAdditionalLibraries.Add(Path.Combine(OutputBinDir, "libcef.so"));

            // add run path
            PublicRuntimeLibraryPaths.Add(OutputBinDir);

            // ensure file permission
            EnsureUnixFileExecutePermission(OutputBinDir);
        }
        else if (Target.Platform == UnrealTargetPlatform.LinuxArm64)
        {
            // add definitions
            PublicDefinitions.AddRange(
                new string[]{
                    "OS_LINUXS=1",
                    "OS_POSIX=1",
                });

            // add the import libraries and framework
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libcef_dll_wrapper.a"));
            PublicAdditionalLibraries.Add(Path.Combine(SourceLibDir, "libCefViewCore.a"));
            PublicAdditionalLibraries.Add(Path.Combine(OutputBinDir, "libcef.so"));

            // add run path
            PublicRuntimeLibraryPaths.Add(OutputBinDir);

            // ensure file permission
            EnsureUnixFileExecutePermission(OutputBinDir);
        }
        else
        {
            throw new NotSupportedException($"UCefView:UCefViewCore:Unsupported target platform {Target.Platform.ToString()}");
        }
    }

    private void EnsureUnixFileExecutePermission(string binDir)
    {
        Console.WriteLine($"UCefView:UCefViewCore:ensure permission on folde recursively: {binDir}");

        Process.Start(new ProcessStartInfo
        {
            FileName = "bash",
            Arguments = $"-c \"chmod -R +x {binDir}\"",
            RedirectStandardOutput = true,
            RedirectStandardError = true,
            UseShellExecute = false,
            CreateNoWindow = true
        });
    }

    private void SyncRuntimeDependencyDirectory(string sourceDir, string outputDir)
    {
        if (!Directory.Exists(sourceDir))
        {
            throw new DirectoryNotFoundException($"UCefView:UCefViewCore: runtime dependency source directory was missing: {sourceDir}");
        }

        Console.WriteLine($"UCefView:UCefViewCore: syncing runtime dependencies from {sourceDir} to {outputDir}");

        Directory.CreateDirectory(outputDir);

        foreach (var sourceSubDir in Directory.GetDirectories(sourceDir, "*", SearchOption.AllDirectories))
        {
            var relativeDir = Path.GetRelativePath(sourceDir, sourceSubDir);
            Directory.CreateDirectory(Path.Combine(outputDir, relativeDir));
        }

        foreach (var sourceFile in Directory.GetFiles(sourceDir, "*", SearchOption.AllDirectories))
        {
            var relativeFile = Path.GetRelativePath(sourceDir, sourceFile);
            var outputFile = Path.Combine(outputDir, relativeFile);
            var outputFileDir = Path.GetDirectoryName(outputFile);
            if (!string.IsNullOrEmpty(outputFileDir))
            {
                Directory.CreateDirectory(outputFileDir);
            }

            if (ShouldCopyRuntimeDependency(sourceFile, outputFile))
            {
                File.Copy(sourceFile, outputFile, true);
            }
        }
    }

    private bool ShouldCopyRuntimeDependency(string sourceFile, string outputFile)
    {
        if (!File.Exists(outputFile))
        {
            return true;
        }

        var sourceInfo = new FileInfo(sourceFile);
        var outputInfo = new FileInfo(outputFile);
        return sourceInfo.Length != outputInfo.Length || sourceInfo.LastWriteTimeUtc > outputInfo.LastWriteTimeUtc;
    }

    private void RestoreWindowsUCefViewHelperExe(string binDir)
    {
        const string UCEFVIEWHELPER_BIN_FILE_NAME = "UCefViewHelper.bin";
        const string UCEFVIEWHELPER_EXE_FILE_NAME = "UCefViewHelper.exe";

        // check existence of UCefViewHelper.exe
        var UCefViewHelperExeFilePath = Path.Combine(binDir, UCEFVIEWHELPER_EXE_FILE_NAME);
        if (File.Exists(UCefViewHelperExeFilePath))
        {
            Console.WriteLine($"UCefView:UCefViewCore: {UCEFVIEWHELPER_EXE_FILE_NAME} exists at:{UCefViewHelperExeFilePath}");
            return;
        }

        Console.WriteLine($"UCefView:UCefViewCore: {UCEFVIEWHELPER_EXE_FILE_NAME} was not found, restoring it...");
        // check existence of UCefViewHelper.bin
        var UCefViewHelperBinFilePath = Path.Combine(binDir, UCEFVIEWHELPER_BIN_FILE_NAME);
        if (File.Exists(UCefViewHelperBinFilePath))
        {
            // read UCefViewHelper.bin content
            var UCefViewHelperBinContent = File.ReadAllBytes(UCefViewHelperBinFilePath);
            // restore DOS header signature
            UCefViewHelperBinContent[0] = 0x4d;
            UCefViewHelperBinContent[1] = 0x5a;

            // UCefViewHelper.exe does not exist, need to create
            File.WriteAllBytes(UCefViewHelperExeFilePath, UCefViewHelperBinContent);
            Console.WriteLine($"UCefView:UCefViewCore: {UCEFVIEWHELPER_EXE_FILE_NAME} was created at: {UCefViewHelperExeFilePath}");
        }
        else
        {
            Console.WriteLine($"UCefView:UCefViewCore: UCefViewHelper.bin was not found");
            throw new FileNotFoundException($"UCefView:UCefViewCore: {UCefViewHelperBinFilePath} was missing, please reinstall UCefView plugin");
        }
    }
}
