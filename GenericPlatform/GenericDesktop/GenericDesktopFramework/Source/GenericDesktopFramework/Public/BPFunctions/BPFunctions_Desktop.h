#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Type/DesktopType.h"
#include "BPFunctions_Desktop.generated.h"

/** 提供桌面蓝图函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Desktop : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 应用信息。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API void GetApplicationInfo(FDesktopApplicationInfo& OutInfo);

	/** 获取系统路径信息。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API void GetSystemPathInfo(FDesktopSystemPathInfo& OutInfo);

	/** 获取设备 ID。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDeviceID();

	/** 获取桌面名称。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopName();

	/** 获取桌面用户名称。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopUserName();

	/** 获取桌面基础目录。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopBaseDir();

	/** 获取桌面用户目录。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopUserDir();

	/** 获取桌面用户临时目录。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopUserTempDir();

	/** 获取桌面用户主目录目录。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopUserHomeDir();

	/** 获取可执行文件路径。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetExecutablePath();

	/** 获取进程ID。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API int32 GetProcessId();

	/** 获取命令行字符串。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetCommandLineString();

	/** 获取操作系统ID。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetOperatingSystemId();

	/** 获取OS版本。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetOSVersion();

	/** 获取OS Versions。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API void GetOSVersions(FString& OutOSVersionLabel, FString& OutOSSubVersionLabel);

	/** 判断管理员运行状态是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API bool IsRunningAsAdministrator();

	/** 获取Environment Variable。 */
	UFUNCTION(BlueprintPure, Category="Window|System")
	static GENERICDESKTOPFRAMEWORK_API FString GetEnvironmentVariable(const FString& VariableName);

public:
	/** 获取Plugin基础目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginBaseDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin Binaries目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginBinariesDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin内容目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginContentDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin Intermediate目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginIntermediateDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin Resources目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginResourcesDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin来源目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginSourceDir(const FString& InPluginName, FString& Directory);

	/** 获取Plugin Extra目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API bool GetPluginExtraDir(const FString& InPluginName, FString& Directory);

	/** 获取保存游戏目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetSaveGameDir();

	/** 获取Extras目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetExtrasDir();

	/** 获取桌面目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetDesktopDir();

	/** 获取Documents目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetDocumentsDir();

	/** 获取Downloads目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetDownloadsDir();

	/** 获取应用数据目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetAppDataDir();

	/** 获取本地应用数据目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetLocalAppDataDir();

	/** 获取Program数据目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetProgramDataDir();

	/** 获取保存Games目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetSavedGamesDir();

	/** 获取临时目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Path")
	static GENERICDESKTOPFRAMEWORK_API FString GetTempDir();

	/** 处理Exist目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API bool ExistDirectory(FString Directory);

	/** 创建目录。 */
	UFUNCTION(BlueprintCallable, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API bool CreateDirectory(FString Directory);

	/** 处理Delete目录。 */
	UFUNCTION(BlueprintCallable, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API bool DeleteDirectory(FString Directory);

	/** 处理Delete目录Recursively。 */
	UFUNCTION(BlueprintCallable, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API bool DeleteDirectoryRecursively(FString Directory);

	/** 查找目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API TArray<FString> FindDirectory(FString Directory);

	/** 查找目录Recursive。 */
	UFUNCTION(BlueprintPure, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API TArray<FString> FindDirectoryRecursive(FString Directory);

	/** 处理Normalize目录。 */
	UFUNCTION(BlueprintPure, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API FString NormalizeDirectory(FString Directory);

	/** 打开目录对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|Directory")
	static GENERICDESKTOPFRAMEWORK_API bool OpenDirectoryDialog(FString& Directory);

public:
	/** 查找文件。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API TArray<FString> FindFile(FString Directory, FString Extension = TEXT("*.*"));

	/** 查找文件Recursive。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API TArray<FString> FindFileRecursive(FString Directory, FString Extension = TEXT("*.*"));

	/** 处理Exist文件。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool ExistFile(FString FileName);

	/** 处理Copy文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool CopyFile(FString FileSource, FString FileDest, bool Replace = true, bool EvenIfReadOnly = false);

	/** 处理Move文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool MoveFile(FString FileSource, FString FileDest, bool Replace = true, bool EvenIfReadOnly = false);

	/** 处理Delete文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool DeleteFile(FString FileName, bool RequireExists = false, bool EvenReadOnly = false);

	/** 执行文件尺寸。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API int64 FileSize(FString Filename);

	/** 处理Normalize文件名称。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString NormalizeFileName(FString Filename);

	/** 判断Drive是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool IsDrive(const FString& FileName);

	/** 判断文件读取Only是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool IsFileReadOnly(FString FileName);

	/** 获取文件Extension。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString GetFileExtension(FString FileName, bool bIncludeDot = false);

	/** 设置文件Extension。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString SetFileExtension(FString FileName, FString NewExtension);

	/** 获取Clean Filename。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString GetCleanFilename(FString FileName);

	/** 获取基础Filename。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString GetBaseFilename(FString FileName, bool bRemovePath = true);

	/** 获取文件路径。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString GetFilePath(FString FileName);

	/** 获取文件路径Leaf。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString GetFilePathLeaf(FString FileName);

	/** 获取时间Stamp。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FDateTime GetTimeStamp(FString FileName);

	/** 判断Relative是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool IsRelative(FString FileName);

	/** 转换为Relative路径。 */
	UFUNCTION(BlueprintPure, Category="Window|File", meta=(DisplayName="To Relative", CompactNodeTitle="->"))
	static GENERICDESKTOPFRAMEWORK_API FString ConvertToRelativePath(const FString& Filename);

	/** 转换为满路径。 */
	UFUNCTION(BlueprintPure, Category="Window|File", meta=(DisplayName="To Full", CompactNodeTitle="->"))
	static GENERICDESKTOPFRAMEWORK_API FString ConvertToFullPath(const FString& Filename);

	/** 判断Under目录是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool IsUnderDirectory(const FString& Filename, const FString& Directory);

	/** 创建有效文件名称。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API FString MakeValidFileName(const FString& Filename);

	/** 打开文件对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool OpenFileDialog(FString FileType, TArray<FString>& FilePaths);

	/** 处理保存文件对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool SaveFileDialog(FString FileName, FString FileType, TArray<FString>& FilePaths);

	/** 处理读取字节数From文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool ReadBytesFromFile(const FString& FileName, TArray<uint8>& OutBytes);

	/** 处理保存字节数To文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool SaveBytesToFile(const FString& FileName, const TArray<uint8>& Bytes);

	/** 处理添加字节数To文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool AddBytesToFile(const FString& FileName, TArray<uint8> Bytes);

	/** 处理读取字符串From文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool ReadStringFromFile(FString FileName, FString& Data);

	/** 处理写入字符串To文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool WriteStringToFile(FString Data, FString FileName, EDesktopTextEncodingOptions EncodingOptions = EDesktopTextEncodingOptions::AutoDetect);

	/** 处理字符串To基础64字符串。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API void StringToBase64String(FString String, FString& Base64String);

	/** 处理基础64字符串To字符串。 */
	UFUNCTION(BlueprintPure, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool Base64StringToString(FString Base64String, FString& String);

	/** 处理字节数To基础64字符串。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API void BytesToBase64String(TArray<uint8> Bytes, FString& Base64String);

	/** 处理基础64字符串To字节数。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API bool Base64StringToBytes(FString Base64String, TArray<uint8>& Bytes);

	/** 加载图像From对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API UTexture2D* LoadImageFromDialog();

	/** 加载图像From文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File")
	static GENERICDESKTOPFRAMEWORK_API UTexture2D* LoadImageFromFile(FString ImagePath);

	/** 转换字节数To纹理2 D。 */
	UFUNCTION(BlueprintPure, Category="Window|File", meta=(DisplayName="To Texture2D (Bytes)", BlueprintAutocast))
	static GENERICDESKTOPFRAMEWORK_API UTexture2D* ConvBytesToTexture2D(const TArray<uint8>& InBytes);

	/** 转换纹理2 D To字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|File", meta=(DisplayName="To Bytes (Texture2D)", BlueprintAutocast))
	static GENERICDESKTOPFRAMEWORK_API bool ConvTexture2DToBytes(UTexture2D* Texture, TArray<uint8>& OutBuffer, EDesktopImageFormat Format = EDesktopImageFormat::PNG);

public:
	/** 设置Clipboard文本。 */
	UFUNCTION(BlueprintCallable, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API void SetClipboardText(const FString& InText);

	/** 获取Clipboard文本。 */
	UFUNCTION(BlueprintPure, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API FString GetClipboardText();

	/** 判断是否可以启动URL。 */
	UFUNCTION(BlueprintPure, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API bool CanLaunchUrl(const FString& InUrl);

	/** 处理启动URL。 */
	UFUNCTION(BlueprintCallable, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API bool LaunchUrl(const FString& InUrl);

	/** 打开文件In Shell。 */
	UFUNCTION(BlueprintCallable, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API bool OpenFileInShell(const FString& InFilePath);

	/** 打开目录In Shell。 */
	UFUNCTION(BlueprintCallable, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API bool OpenDirectoryInShell(const FString& InDirectoryPath);

	/** 处理Reveal文件In Explorer。 */
	UFUNCTION(BlueprintCallable, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API bool RevealFileInExplorer(const FString& InFilePath);

	/** 获取系统Font字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Shell")
	static GENERICDESKTOPFRAMEWORK_API void GetSystemFontBytes(TArray<uint8>& OutBytes);

public:
	/** 获取显示信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Display")
	static GENERICDESKTOPFRAMEWORK_API void GetDisplayInfo(FDesktopDisplayInfo& OutInfo);

	/** 获取主Monitor信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Display")
	static GENERICDESKTOPFRAMEWORK_API void GetPrimaryMonitorInfo(FDesktopMonitorInfo& OutInfo);

	/** 获取当前Monitor信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Display")
	static GENERICDESKTOPFRAMEWORK_API void GetCurrentMonitorInfo(FDesktopMonitorInfo& OutInfo);

	/** 获取全部Monitor Infos。 */
	UFUNCTION(BlueprintPure, Category="Window|Display")
	static GENERICDESKTOPFRAMEWORK_API void GetAllMonitorInfos(TArray<FDesktopMonitorInfo>& OutInfos);

	/** 获取Monitor数量。 */
	UFUNCTION(BlueprintPure, Category="Window|Display")
	static GENERICDESKTOPFRAMEWORK_API int32 GetMonitorCount();

public:
	/** 获取Main窗口信息。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API void GetMainWindowInfo(FDesktopMainWindowInfo& OutInfo);

	/** 获取Main窗口标题。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API FString GetMainWindowTitle();

	/** 设置Main窗口标题。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool SetMainWindowTitle(const FString& InTitle);

	/** 获取Main窗口处理值。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API int64 GetMainWindowHandleValue();

	/** 判断Main窗口有效是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool IsMainWindowValid();

	/** 判断Main窗口激活是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool IsMainWindowActive();

	/** 判断Main窗口Minimized是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool IsMainWindowMinimized();

	/** 判断Main窗口Maximized是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool IsMainWindowMaximized();

	/** 处理Bring Main窗口To Front。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool BringMainWindowToFront();

	/** 处理Minimize Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool MinimizeMainWindow();

	/** 处理Maximize Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool MaximizeMainWindow();

	/** 处理Restore Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool RestoreMainWindow();

	/** 处理Move Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool MoveMainWindow(int32 NewPositionX, int32 NewPositionY);

	/** 处理Resize Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool ResizeMainWindow(int32 NewSizeX, int32 NewSizeY);

	/** 设置Main窗口Top Most。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool SetMainWindowTopMost(bool bEnable);

	/** 处理Flash Main窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool FlashMainWindow(bool bStop = false);

	/** 获取窗口模式。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API EDesktopDisplayMode GetWindowMode();

	/** 设置窗口模式。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool SetWindowMode(EDesktopDisplayMode InWindowMode);

	/** 请求Minimize应用。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API void RequestMinimizeApplication();

	/** 处理Restart应用。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool RestartApplication();

	/** 判断Screen Capture已禁用是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool IsScreenCaptureDisabled();

	/** 设置Screen Capture已禁用。 */
	UFUNCTION(BlueprintCallable, Category="Window|MainWindow")
	static GENERICDESKTOPFRAMEWORK_API bool SetScreenCaptureDisabled(bool bDisable);

public:
	/** 获取CPU硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API void GetCPUHardwareInfo(FDesktopCPUInfo& OutInfo);

	/** 处理Test CPU信息。 */
	UFUNCTION(BlueprintCallable, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API void Test_CPUInfo();

	/** 获取CPU厂商。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetCPUVendor();

	/** 获取CPU品牌。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetCPUBrand();

	/** 获取CPU芯片组。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetCPUChipset();

	/** 获取CPU物理核心数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API int32 GetCPUPhysicalCores();

	/** 获取CPU核心数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API int32 GetCPUCores();

	/** 获取CPU逻辑核心数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API int32 GetCPULogicalCores();

	/** 获取CPU使用率。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API float GetCPUUsage();

	/** 获取CPU Frequency。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API float GetCPUFrequency();

	/** 获取CPU进程数量。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API int32 GetCPUProcessCount();

	/** 获取CPU线程数量。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API int32 GetCPUThreadCount();

	/** 获取系统Uptime Second。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|CPU")
	static GENERICDESKTOPFRAMEWORK_API double GetSystemUptimeSecond();

	/** 获取GPU硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API void GetGPUHardwareInfo(FDesktopGPUInfo& OutInfo);

	/** 获取GPU内存信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API void GetGPUMemoryInfo(FDesktopGPUMemoryInfo& OutInfo);

	/** 处理Test GPU信息。 */
	UFUNCTION(BlueprintCallable, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API void Test_GPUInfo();

	/** 获取GPU品牌。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUBrand();

	/** 获取GPU Adapter名称。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUAdapterName();

	/** 获取GPU Adapter内部驱动版本。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUAdapterInternalDriverVersion();

	/** 获取GPU Adapter用户驱动版本。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUAdapterUserDriverVersion();

	/** 获取GPU Adapter驱动日期。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUAdapterDriverDate();

	/** 获取GPU提供器名称。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUProviderName();

	/** 获取GPU驱动统一版本。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUDriverUnifiedVersion();

	/** 获取GPURHI名称。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPURHIName();

	/** 获取GPU设备ID。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUDeviceId();

	/** 获取GPU设备Revision。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUDeviceRevision();

	/** 获取GPU厂商ID。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API FString GetGPUVendorId();

	/** 获取GPU使用率。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|GPU")
	static GENERICDESKTOPFRAMEWORK_API float GetGPUUsage();

	/** 获取内存硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Memory")
	static GENERICDESKTOPFRAMEWORK_API void GetMemoryHardwareInfo(FDesktopMemoryInfo& OutInfo);

	/** 获取内存总物理字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Memory")
	static GENERICDESKTOPFRAMEWORK_API int64 GetMemoryTotalPhysicalBytes();

	/** 获取内存可用物理字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Memory")
	static GENERICDESKTOPFRAMEWORK_API int64 GetMemoryAvailablePhysicalBytes();

	/** 获取内存系统已用物理字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Memory")
	static GENERICDESKTOPFRAMEWORK_API int64 GetMemorySystemUsedPhysicalBytes();

	/** 获取内存进程已用物理字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Memory")
	static GENERICDESKTOPFRAMEWORK_API int64 GetMemoryProcessUsedPhysicalBytes();

	/** 获取磁盘信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API bool GetDiskInfo(const FString& InPath, FDesktopDiskInfo& OutInfo);

	/** 获取项目磁盘信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API bool GetProjectDiskInfo(FDesktopDiskInfo& OutInfo);

	/** 获取全部磁盘Infos。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API void GetAllDiskInfos(TArray<FDesktopDiskInfo>& OutInfos);

	/** 获取磁盘总字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API int64 GetDiskTotalBytes(const FString& InPath);

	/** 获取磁盘可用字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API int64 GetDiskFreeBytes(const FString& InPath);

	/** 获取磁盘已用字节数。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Disk")
	static GENERICDESKTOPFRAMEWORK_API int64 GetDiskUsedBytes(const FString& InPath);

	/** 获取电源信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Power")
	static GENERICDESKTOPFRAMEWORK_API void GetPowerInfo(FDesktopPowerInfo& OutInfo);

	/** 判断Laptop设备是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Power")
	static GENERICDESKTOPFRAMEWORK_API bool IsLaptopDevice();

	/** 判断运行On电池是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Power")
	static GENERICDESKTOPFRAMEWORK_API bool IsRunningOnBattery();

	/** 获取电池电量百分比。 */
	UFUNCTION(BlueprintPure, Category="Window|Hardware|Power")
	static GENERICDESKTOPFRAMEWORK_API int32 GetBatteryPercent();

public:
	/** 获取网络Adapter信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Network")
	static GENERICDESKTOPFRAMEWORK_API void GetNetworkAdapterInfo(TArray<FDesktopNetworkAdapterInfo>& OutInfos);

	/** 获取网络信息。 */
	UFUNCTION(BlueprintPure, Category="Window|Network")
	static GENERICDESKTOPFRAMEWORK_API void GetNetworkInfo(FDesktopNetworkInfo& OutInfo);

public:
	/** 获取硬件快照。 */
	UFUNCTION(BlueprintPure, Category="Window|Diagnostics")
	static GENERICDESKTOPFRAMEWORK_API void GetHardwareSnapshot(FDesktopHardwareSnapshot& OutSnapshot);

	/** 获取窗口调试Report。 */
	UFUNCTION(BlueprintPure, Category="Window|Diagnostics")
	static GENERICDESKTOPFRAMEWORK_API FString GetWindowDebugReport();
};
