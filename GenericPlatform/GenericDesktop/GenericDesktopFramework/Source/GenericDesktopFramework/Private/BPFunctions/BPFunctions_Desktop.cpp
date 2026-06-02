#include "BPFunctions/BPFunctions_Desktop.h"

#include "Async/Async.h"
#include "DynamicRHI.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/GameUserSettings.h"
#include "GenericPlatform/GenericApplication.h"
#include "GenericPlatform/GenericPlatformDriver.h"
#include "GenericPlatform/GenericPlatformMemory.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformApplicationMisc.h"
#include "HAL/PlatformFileManager.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/App.h"
#include "Misc/Base64.h"
#include "Misc/CommandLine.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "RHI.h"
#include "RHICommandList.h"
#include "RHIGlobals.h"
#include "RHIStats.h"
#include "Rendering/Texture2DResource.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <Psapi.h>
#include <TlHelp32.h>
#include <combaseapi.h>
#include <iphlpapi.h>
#include <iptypes.h>
#include <KnownFolders.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shobjidl.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#if PLATFORM_WINDOWS
#ifndef WDA_EXCLUDEFROMCAPTURE
#define WDA_EXCLUDEFROMCAPTURE 0x00000011
#endif
#endif

namespace
{
	int64 ClampByteSizeToInt64(const uint64 Value)
	{
		return Value > static_cast<uint64>(MAX_int64) ? MAX_int64 : static_cast<int64>(Value);
	}

	FString BoolToString(const bool bValue)
	{
		return bValue ? TEXT("True") : TEXT("False");
	}

	float GetCurrentProcessGPUUsageFraction(const FRHIGPUUsageFractions& Usage)
	{
#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)
		return Usage.CurrentProcessMHz;
#else
		return Usage.CurrentProcess;
#endif
	}

	float GetExternalProcessGPUUsageFraction(const FRHIGPUUsageFractions& Usage)
	{
#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)
		return Usage.ExternalProcessesMHz;
#else
		return Usage.ExternalProcesses;
#endif
	}

	FString NormalizeExternalPath(FString InPath)
	{
		InPath = FPaths::ConvertRelativePathToFull(InPath);
		FPaths::NormalizeFilename(InPath);
#if PLATFORM_WINDOWS
		InPath.ReplaceInline(TEXT("/"), TEXT("\\"));
#endif
		return InPath;
	}

	EDesktopDisplayMode ConvertToWindowDisplayMode(const EWindowMode::Type InMode)
	{
		switch (InMode)
		{
		case EWindowMode::Windowed:
			return EDesktopDisplayMode::Windowed;
		case EWindowMode::WindowedFullscreen:
			return EDesktopDisplayMode::WindowedFullscreen;
		case EWindowMode::Fullscreen:
			return EDesktopDisplayMode::Fullscreen;
		default:
			return EDesktopDisplayMode::Unknown;
		}
	}

	EWindowMode::Type ConvertFromWindowDisplayMode(const EDesktopDisplayMode InMode)
	{
		switch (InMode)
		{
		case EDesktopDisplayMode::Windowed:
			return EWindowMode::Windowed;
		case EDesktopDisplayMode::WindowedFullscreen:
			return EWindowMode::WindowedFullscreen;
		case EDesktopDisplayMode::Fullscreen:
			return EWindowMode::Fullscreen;
		default:
			return EWindowMode::Windowed;
		}
	}

	EDesktopNetworkType ConvertToWindowNetworkType(const ENetworkConnectionType InType)
	{
		switch (InType)
		{
		case ENetworkConnectionType::None:
			return EDesktopNetworkType::None;
		case ENetworkConnectionType::AirplaneMode:
			return EDesktopNetworkType::AirplaneMode;
		case ENetworkConnectionType::Cell:
			return EDesktopNetworkType::Cell;
		case ENetworkConnectionType::WiFi:
			return EDesktopNetworkType::WiFi;
		case ENetworkConnectionType::WiMAX:
			return EDesktopNetworkType::WiMAX;
		case ENetworkConnectionType::Bluetooth:
			return EDesktopNetworkType::Bluetooth;
		case ENetworkConnectionType::Ethernet:
			return EDesktopNetworkType::Ethernet;
		default:
			return EDesktopNetworkType::Unknown;
		}
	}

#if PLATFORM_WINDOWS
	EDesktopDisplayOrientation ConvertToWindowDisplayOrientation(const DWORD InOrientation)
	{
		switch (InOrientation)
		{
		case DMDO_DEFAULT:
			return EDesktopDisplayOrientation::Landscape;
		case DMDO_90:
			return EDesktopDisplayOrientation::Portrait;
		case DMDO_180:
			return EDesktopDisplayOrientation::LandscapeFlipped;
		case DMDO_270:
			return EDesktopDisplayOrientation::PortraitFlipped;
		default:
			return EDesktopDisplayOrientation::Unknown;
		}
	}
#endif

	FGPUDriverInfo GetCurrentGPUDriverInfo()
	{
		FString DeviceDescription = GRHIGlobals.GpuInfo.AdapterName;
		if (DeviceDescription.IsEmpty())
		{
			DeviceDescription = FPlatformMisc::GetPrimaryGPUBrand();
		}

		return FPlatformMisc::GetGPUDriverInfo(DeviceDescription);
	}

	FDesktopMemoryInfo BuildMemoryInfo()
	{
		const FPlatformMemoryStats Stats = FPlatformMemory::GetStats();
		const FPlatformMemoryConstants& Constants = FPlatformMemory::GetConstants();

		FDesktopMemoryInfo Info;
		Info.TotalPhysicalBytes = ClampByteSizeToInt64(Stats.TotalPhysical);
		Info.AvailablePhysicalBytes = ClampByteSizeToInt64(Stats.AvailablePhysical);
		Info.SystemUsedPhysicalBytes = ClampByteSizeToInt64(Stats.TotalPhysical > Stats.AvailablePhysical ? Stats.TotalPhysical - Stats.AvailablePhysical : 0);
		Info.ProcessUsedPhysicalBytes = ClampByteSizeToInt64(Stats.UsedPhysical);
		Info.PeakProcessUsedPhysicalBytes = ClampByteSizeToInt64(Stats.PeakUsedPhysical);
		Info.TotalVirtualBytes = ClampByteSizeToInt64(Stats.TotalVirtual);
		Info.AvailableVirtualBytes = ClampByteSizeToInt64(Stats.AvailableVirtual);
		Info.ProcessUsedVirtualBytes = ClampByteSizeToInt64(Stats.UsedVirtual);
		Info.PeakProcessUsedVirtualBytes = ClampByteSizeToInt64(Stats.PeakUsedVirtual);
		Info.PageSizeBytes = static_cast<int64>(Constants.PageSize);
		Info.OsAllocationGranularityBytes = static_cast<int64>(Constants.OsAllocationGranularity);
		Info.BinnedPageSizeBytes = static_cast<int64>(Constants.BinnedPageSize);
		Info.TotalPhysicalGB = static_cast<int32>(Constants.TotalPhysicalGB);

		if (Stats.TotalPhysical > 0)
		{
			Info.SystemPhysicalUsagePercent = static_cast<float>((static_cast<double>(Stats.TotalPhysical - Stats.AvailablePhysical) / static_cast<double>(Stats.TotalPhysical)) * 100.0);
			Info.ProcessPhysicalUsagePercent = static_cast<float>((static_cast<double>(Stats.UsedPhysical) / static_cast<double>(Stats.TotalPhysical)) * 100.0);
		}

		return Info;
	}

	FDesktopGPUMemoryInfo BuildGPUMemoryInfo()
	{
		FDesktopGPUMemoryInfo Info;

		if (!GRHIGlobals.IsRHIInitialized || GDynamicRHI == nullptr)
		{
			return Info;
		}

		FTextureMemoryStats TextureMemoryStats;
		RHIGetTextureMemoryStats(TextureMemoryStats);

		Info.bIsValid = TextureMemoryStats.AreHardwareStatsValid()
			|| TextureMemoryStats.TotalGraphicsMemory >= 0
			|| TextureMemoryStats.TexturePoolSize > 0
			|| TextureMemoryStats.StreamingMemorySize > 0
			|| TextureMemoryStats.NonStreamingMemorySize > 0;
		Info.DedicatedVideoMemoryBytes = TextureMemoryStats.DedicatedVideoMemory;
		Info.DedicatedSystemMemoryBytes = TextureMemoryStats.DedicatedSystemMemory;
		Info.SharedSystemMemoryBytes = TextureMemoryStats.SharedSystemMemory;
		Info.TotalGraphicsMemoryBytes = TextureMemoryStats.TotalGraphicsMemory;
		Info.StreamingMemorySizeBytes = ClampByteSizeToInt64(TextureMemoryStats.StreamingMemorySize);
		Info.NonStreamingMemorySizeBytes = ClampByteSizeToInt64(TextureMemoryStats.NonStreamingMemorySize);
		Info.LargestContiguousAllocationBytes = TextureMemoryStats.LargestContiguousAllocation;
		Info.TexturePoolSizeBytes = TextureMemoryStats.TexturePoolSize;
		Info.AvailableTexturePoolBytes = TextureMemoryStats.ComputeAvailableMemorySize();

		return Info;
	}

	FString GetDriveTypeName(const uint32 InDriveType)
	{
#if PLATFORM_WINDOWS
		switch (InDriveType)
		{
		case DRIVE_UNKNOWN:
			return TEXT("Unknown");
		case DRIVE_NO_ROOT_DIR:
			return TEXT("NoRootDir");
		case DRIVE_REMOVABLE:
			return TEXT("Removable");
		case DRIVE_FIXED:
			return TEXT("Fixed");
		case DRIVE_REMOTE:
			return TEXT("Remote");
		case DRIVE_CDROM:
			return TEXT("CDROM");
		case DRIVE_RAMDISK:
			return TEXT("RAMDisk");
		default:
			return TEXT("Unknown");
		}
#else
		return TEXT("Unknown");
#endif
	}

	bool PopulateDiskInfoInternal(const FString& InPath, FDesktopDiskInfo& OutInfo)
	{
		OutInfo = FDesktopDiskInfo();

		const FString ResolvedPath = InPath.IsEmpty() ? FPaths::ProjectDir() : InPath;
		FString FullPath = FPaths::ConvertRelativePathToFull(ResolvedPath);
		FPaths::MakePlatformFilename(FullPath);

		OutInfo.Path = FullPath;
		OutInfo.RootPath = FullPath;

		uint64 TotalBytes = 0;
		uint64 FreeBytes = 0;
		OutInfo.bIsValid = FPlatformMisc::GetDiskTotalAndFreeSpace(FullPath, TotalBytes, FreeBytes);
		if (!OutInfo.bIsValid)
		{
			return false;
		}

		OutInfo.TotalBytes = ClampByteSizeToInt64(TotalBytes);
		OutInfo.FreeBytes = ClampByteSizeToInt64(FreeBytes);
		OutInfo.UsedBytes = ClampByteSizeToInt64(TotalBytes >= FreeBytes ? TotalBytes - FreeBytes : 0);

#if PLATFORM_WINDOWS
		TCHAR VolumePathBuffer[MAX_PATH] = { 0 };
		if (GetVolumePathName(*FullPath, VolumePathBuffer, UE_ARRAY_COUNT(VolumePathBuffer)))
		{
			OutInfo.RootPath = VolumePathBuffer;
		}

		OutInfo.DriveType = static_cast<int32>(GetDriveType(*OutInfo.RootPath));
		OutInfo.DriveTypeName = GetDriveTypeName(static_cast<uint32>(OutInfo.DriveType));

		TCHAR VolumeNameBuffer[MAX_PATH] = { 0 };
		TCHAR FileSystemNameBuffer[MAX_PATH] = { 0 };
		DWORD SerialNumber = 0;
		DWORD MaxComponentLength = 0;
		DWORD FileSystemFlags = 0;
		if (GetVolumeInformation(
			*OutInfo.RootPath,
			VolumeNameBuffer,
			UE_ARRAY_COUNT(VolumeNameBuffer),
			&SerialNumber,
			&MaxComponentLength,
			&FileSystemFlags,
			FileSystemNameBuffer,
			UE_ARRAY_COUNT(FileSystemNameBuffer)))
		{
			OutInfo.VolumeName = VolumeNameBuffer;
			OutInfo.FileSystemName = FileSystemNameBuffer;
		}
#else
		OutInfo.DriveTypeName = TEXT("MountedPath");
#endif

		return true;
	}

#if PLATFORM_WINDOWS
	bool ResolveKnownFolderPathInternal(REFKNOWNFOLDERID InFolderId, FString& OutPath)
	{
		PWSTR RawPath = nullptr;
		const HRESULT Result = SHGetKnownFolderPath(InFolderId, KF_FLAG_DEFAULT, nullptr, &RawPath);
		if (FAILED(Result) || RawPath == nullptr)
		{
			return false;
		}

		OutPath = RawPath;
		CoTaskMemFree(RawPath);
		return true;
	}

	bool IsRunningAsAdministratorInternal()
	{
		BOOL bIsAdmin = 0;
		PSID AdministratorsGroup = nullptr;
		SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
		if (AllocateAndInitializeSid(
			&NtAuthority,
			2,
			SECURITY_BUILTIN_DOMAIN_RID,
			DOMAIN_ALIAS_RID_ADMINS,
			0,
			0,
			0,
			0,
			0,
			0,
			&AdministratorsGroup))
		{
			CheckTokenMembership(nullptr, AdministratorsGroup, &bIsAdmin);
			FreeSid(AdministratorsGroup);
		}

		return bIsAdmin != 0;
	}

	HWND GetMainWindowHandleInternal()
	{
		HWND Handle = nullptr;
		if (FSlateApplication::IsInitialized())
		{
			Handle = reinterpret_cast<HWND>(const_cast<void*>(FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr)));
		}

		if (Handle == nullptr)
		{
			Handle = GetActiveWindow();
		}

		if (Handle == nullptr)
		{
			Handle = GetForegroundWindow();
		}

		return Handle;
	}

	FString GetWindowTitleInternal(HWND InHandle)
	{
		if (InHandle == nullptr)
		{
			return FString();
		}

		const int32 TitleLength = GetWindowTextLength(InHandle);
		TArray<TCHAR> Buffer;
		Buffer.SetNumZeroed(TitleLength + 1);
		GetWindowText(InHandle, Buffer.GetData(), Buffer.Num());
		return FString(Buffer.GetData());
	}

	EDesktopBatteryState ConvertBatteryState(const SYSTEM_POWER_STATUS& InStatus)
	{
		if (InStatus.BatteryFlag == 128)
		{
			return EDesktopBatteryState::NoBattery;
		}
		if (InStatus.ACLineStatus == 1 && InStatus.BatteryLifePercent >= 100)
		{
			return EDesktopBatteryState::Full;
		}
		if (InStatus.ACLineStatus == 1)
		{
			return EDesktopBatteryState::Charging;
		}
		if (InStatus.ACLineStatus == 0)
		{
			return EDesktopBatteryState::Discharging;
		}
		return EDesktopBatteryState::Unknown;
	}

	EDesktopPowerLineStatus ConvertPowerLineStatus(const SYSTEM_POWER_STATUS& InStatus)
	{
		switch (InStatus.ACLineStatus)
		{
		case 0:
			return EDesktopPowerLineStatus::Offline;
		case 1:
			return EDesktopPowerLineStatus::Online;
		default:
			return EDesktopPowerLineStatus::Unknown;
		}
	}

	bool ExtractShellItemPath(IShellItem* InItem, FString& OutPath)
	{
		if (InItem == nullptr)
		{
			return false;
		}

		PWSTR RawPath = nullptr;
		const HRESULT Result = InItem->GetDisplayName(SIGDN_FILESYSPATH, &RawPath);
		if (FAILED(Result) || RawPath == nullptr)
		{
			return false;
		}

		OutPath = RawPath;
		CoTaskMemFree(RawPath);
		return true;
	}

	void BuildDialogFilterParts(const FString& InFileType, FString& OutDisplayName, FString& OutPattern, FString& OutDefaultExtension)
	{
		FString FileType = InFileType.TrimStartAndEnd();
		if (FileType.IsEmpty() || FileType == TEXT("*.*"))
		{
			OutDisplayName = TEXT("All Files");
			OutPattern = TEXT("*.*");
			OutDefaultExtension.Reset();
			return;
		}

		if (FileType.Contains(TEXT("|")))
		{
			FString Left;
			FString Right;
			if (FileType.Split(TEXT("|"), &Left, &Right))
			{
				OutDisplayName = Left;
				OutPattern = Right;
				FString Temp = Right;
				Temp.RemoveFromStart(TEXT("*."));
				Temp.RemoveFromStart(TEXT("."));
				OutDefaultExtension = Temp;
				return;
			}
		}

		FileType.RemoveFromStart(TEXT("*."));
		FileType.RemoveFromStart(TEXT("."));
		OutDisplayName = FString::Printf(TEXT("%s Files"), *FileType.ToUpper());
		OutPattern = FString::Printf(TEXT("*.%s"), *FileType);
		OutDefaultExtension = FileType;
	}

	bool OpenDirectoryDialogInternal(FString& OutDirectory)
	{
		const HRESULT InitResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
		const bool bNeedUninitialize = SUCCEEDED(InitResult);

		IFileOpenDialog* Dialog = nullptr;
		const HRESULT CreateResult = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&Dialog));
		if (FAILED(CreateResult) || Dialog == nullptr)
		{
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		DWORD Options = 0;
		Dialog->GetOptions(&Options);
		Dialog->SetOptions(Options | FOS_FORCEFILESYSTEM | FOS_PICKFOLDERS | FOS_PATHMUSTEXIST);
		Dialog->SetTitle(TEXT("閫夋嫨鐩綍"));

		const HRESULT ShowResult = Dialog->Show(GetMainWindowHandleInternal());
		if (FAILED(ShowResult))
		{
			Dialog->Release();
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		IShellItem* ResultItem = nullptr;
		const bool bSuccess = SUCCEEDED(Dialog->GetResult(&ResultItem)) && ExtractShellItemPath(ResultItem, OutDirectory);
		if (ResultItem != nullptr)
		{
			ResultItem->Release();
		}

		Dialog->Release();
		if (bNeedUninitialize)
		{
			CoUninitialize();
		}
		return bSuccess;
	}

	bool OpenFileDialogInternal(const FString& InFileType, TArray<FString>& OutFiles)
	{
		OutFiles.Reset();

		const HRESULT InitResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
		const bool bNeedUninitialize = SUCCEEDED(InitResult);

		IFileOpenDialog* Dialog = nullptr;
		const HRESULT CreateResult = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&Dialog));
		if (FAILED(CreateResult) || Dialog == nullptr)
		{
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		DWORD Options = 0;
		Dialog->GetOptions(&Options);
		Dialog->SetOptions(Options | FOS_FORCEFILESYSTEM | FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST | FOS_ALLOWMULTISELECT);
		Dialog->SetTitle(TEXT("鎵撳紑鏂囦欢"));

		FString FilterName;
		FString FilterPattern;
		FString DefaultExtension;
		BuildDialogFilterParts(InFileType, FilterName, FilterPattern, DefaultExtension);
		const COMDLG_FILTERSPEC FilterSpec[] = { { *FilterName, *FilterPattern } };
		Dialog->SetFileTypes(UE_ARRAY_COUNT(FilterSpec), FilterSpec);

		const HRESULT ShowResult = Dialog->Show(GetMainWindowHandleInternal());
		if (FAILED(ShowResult))
		{
			Dialog->Release();
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		IShellItemArray* ResultArray = nullptr;
		bool bSuccess = false;
		if (SUCCEEDED(Dialog->GetResults(&ResultArray)) && ResultArray != nullptr)
		{
			DWORD Count = 0;
			ResultArray->GetCount(&Count);
			for (DWORD Index = 0; Index < Count; ++Index)
			{
				IShellItem* Item = nullptr;
				if (SUCCEEDED(ResultArray->GetItemAt(Index, &Item)))
				{
					FString FilePath;
					if (ExtractShellItemPath(Item, FilePath))
					{
						OutFiles.Add(FilePath);
						bSuccess = true;
					}
					Item->Release();
				}
			}
			ResultArray->Release();
		}

		Dialog->Release();
		if (bNeedUninitialize)
		{
			CoUninitialize();
		}
		return bSuccess;
	}

	bool SaveFileDialogInternal(const FString& InFileName, const FString& InFileType, TArray<FString>& OutFiles)
	{
		OutFiles.Reset();

		const HRESULT InitResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
		const bool bNeedUninitialize = SUCCEEDED(InitResult);

		IFileSaveDialog* Dialog = nullptr;
		const HRESULT CreateResult = CoCreateInstance(CLSID_FileSaveDialog, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&Dialog));
		if (FAILED(CreateResult) || Dialog == nullptr)
		{
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		DWORD Options = 0;
		Dialog->GetOptions(&Options);
		Dialog->SetOptions(Options | FOS_FORCEFILESYSTEM | FOS_PATHMUSTEXIST | FOS_OVERWRITEPROMPT);
		Dialog->SetTitle(TEXT("淇濆瓨鏂囦欢"));

		FString FilterName;
		FString FilterPattern;
		FString DefaultExtension;
		BuildDialogFilterParts(InFileType, FilterName, FilterPattern, DefaultExtension);
		const COMDLG_FILTERSPEC FilterSpec[] = { { *FilterName, *FilterPattern } };
		Dialog->SetFileTypes(UE_ARRAY_COUNT(FilterSpec), FilterSpec);
		if (!DefaultExtension.IsEmpty())
		{
			Dialog->SetDefaultExtension(*DefaultExtension);
		}

		FString SuggestedName = InFileName;
		if (!DefaultExtension.IsEmpty() && FPaths::GetExtension(SuggestedName).IsEmpty())
		{
			SuggestedName = FString::Printf(TEXT("%s.%s"), *SuggestedName, *DefaultExtension);
		}
		Dialog->SetFileName(*SuggestedName);

		const HRESULT ShowResult = Dialog->Show(GetMainWindowHandleInternal());
		if (FAILED(ShowResult))
		{
			Dialog->Release();
			if (bNeedUninitialize)
			{
				CoUninitialize();
			}
			return false;
		}

		IShellItem* ResultItem = nullptr;
		bool bSuccess = false;
		if (SUCCEEDED(Dialog->GetResult(&ResultItem)) && ResultItem != nullptr)
		{
			FString FilePath;
			if (ExtractShellItemPath(ResultItem, FilePath))
			{
				OutFiles.Add(MoveTemp(FilePath));
				bSuccess = true;
			}
		}

		if (ResultItem != nullptr)
		{
			ResultItem->Release();
		}

		Dialog->Release();
		if (bNeedUninitialize)
		{
			CoUninitialize();
		}
		return bSuccess;
	}
#endif

	FDesktopSystemPathInfo BuildSystemPathInfoInternal()
	{
		FDesktopSystemPathInfo Info;
		Info.TempDir = FPlatformProcess::UserTempDir();
		Info.ProjectExtrasDir = FPaths::Combine(FPaths::ProjectDir(), TEXT("Extras"));
		Info.ProjectSaveGameDir = FString::Printf(TEXT("%sSaveGames/"), *FPaths::ProjectSavedDir());

#if PLATFORM_WINDOWS
		ResolveKnownFolderPathInternal(FOLDERID_Desktop, Info.DesktopDir);
		ResolveKnownFolderPathInternal(FOLDERID_Documents, Info.DocumentsDir);
		ResolveKnownFolderPathInternal(FOLDERID_Downloads, Info.DownloadsDir);
		ResolveKnownFolderPathInternal(FOLDERID_Music, Info.MusicDir);
		ResolveKnownFolderPathInternal(FOLDERID_Pictures, Info.PicturesDir);
		ResolveKnownFolderPathInternal(FOLDERID_Videos, Info.VideosDir);
		ResolveKnownFolderPathInternal(FOLDERID_RoamingAppData, Info.AppDataDir);
		ResolveKnownFolderPathInternal(FOLDERID_LocalAppData, Info.LocalAppDataDir);
		ResolveKnownFolderPathInternal(FOLDERID_ProgramData, Info.ProgramDataDir);
		ResolveKnownFolderPathInternal(FOLDERID_SavedGames, Info.SavedGamesDir);
#endif

		return Info;
	}

	FDesktopApplicationInfo BuildApplicationInfoInternal()
	{
		FDesktopApplicationInfo Info;
		Info.DeviceId = UBPFunctions_Desktop::GetDeviceID();
		Info.ComputerName = FPlatformProcess::ComputerName();
		Info.UserName = FPlatformProcess::UserName();
		Info.BaseDir = FPlatformProcess::BaseDir();
		Info.UserDir = FPlatformProcess::UserDir();
		Info.UserTempDir = FPlatformProcess::UserTempDir();
		Info.UserHomeDir = FPlatformProcess::UserHomeDir();
		Info.ExecutablePath = FPlatformProcess::ExecutablePath();
		Info.LaunchDir = FPaths::LaunchDir();
		Info.ProjectDir = FPaths::ProjectDir();
		Info.ProjectSavedDir = FPaths::ProjectSavedDir();
		Info.ProjectContentDir = FPaths::ProjectContentDir();
		Info.CommandLine = FCommandLine::Get();
		Info.OperatingSystemId = FPlatformMisc::GetOperatingSystemId();
		Info.OSVersion = FPlatformMisc::GetOSVersion();
		FPlatformMisc::GetOSVersions(Info.OSVersionLabel, Info.OSSubVersionLabel);
		Info.EngineVersion = FEngineVersion::Current().ToString();
		Info.ProcessId = FPlatformProcess::GetCurrentProcessId();
#if PLATFORM_WINDOWS
		Info.bIsRunningAsAdministrator = IsRunningAsAdministratorInternal();
#endif
		return Info;
	}

	FDesktopMonitorInfo BuildMonitorInfoFromPlatformInfo(const FMonitorInfo& InMonitor)
	{
		FDesktopMonitorInfo OutInfo;
		OutInfo.Name = InMonitor.Name;
		OutInfo.Id = InMonitor.ID;
		OutInfo.NativeWidth = InMonitor.NativeWidth;
		OutInfo.NativeHeight = InMonitor.NativeHeight;
		OutInfo.MaxResolutionX = InMonitor.MaxResolution.X;
		OutInfo.MaxResolutionY = InMonitor.MaxResolution.Y;
		OutInfo.DisplayLeft = InMonitor.DisplayRect.Left;
		OutInfo.DisplayTop = InMonitor.DisplayRect.Top;
		OutInfo.DisplayRight = InMonitor.DisplayRect.Right;
		OutInfo.DisplayBottom = InMonitor.DisplayRect.Bottom;
		OutInfo.WorkAreaLeft = InMonitor.WorkArea.Left;
		OutInfo.WorkAreaTop = InMonitor.WorkArea.Top;
		OutInfo.WorkAreaRight = InMonitor.WorkArea.Right;
		OutInfo.WorkAreaBottom = InMonitor.WorkArea.Bottom;
		OutInfo.DPI = InMonitor.DPI;
		OutInfo.DPIScale = InMonitor.DPI > 0 ? static_cast<float>(InMonitor.DPI) / 96.f : 1.f;
		OutInfo.bIsPrimary = InMonitor.bIsPrimary;

#if PLATFORM_WINDOWS
		DEVMODE DevMode;
		FMemory::Memzero(DevMode);
		DevMode.dmSize = sizeof(DEVMODE);
		if (EnumDisplaySettingsEx(*InMonitor.Name, ENUM_CURRENT_SETTINGS, &DevMode, 0))
		{
			OutInfo.RefreshRate = static_cast<int32>(DevMode.dmDisplayFrequency);
			OutInfo.Orientation = ConvertToWindowDisplayOrientation(DevMode.dmDisplayOrientation);
		}
#endif

		return OutInfo;
	}

	FDesktopDisplayInfo BuildDisplayInfoInternal()
	{
		FDesktopDisplayInfo Info;

		FDisplayMetrics DisplayMetrics;
		FDisplayMetrics::RebuildDisplayMetrics(DisplayMetrics);
		Info.PrimaryDisplayWidth = DisplayMetrics.PrimaryDisplayWidth;
		Info.PrimaryDisplayHeight = DisplayMetrics.PrimaryDisplayHeight;
		Info.PrimaryWorkAreaLeft = DisplayMetrics.PrimaryDisplayWorkAreaRect.Left;
		Info.PrimaryWorkAreaTop = DisplayMetrics.PrimaryDisplayWorkAreaRect.Top;
		Info.PrimaryWorkAreaRight = DisplayMetrics.PrimaryDisplayWorkAreaRect.Right;
		Info.PrimaryWorkAreaBottom = DisplayMetrics.PrimaryDisplayWorkAreaRect.Bottom;
		Info.VirtualDisplayLeft = DisplayMetrics.VirtualDisplayRect.Left;
		Info.VirtualDisplayTop = DisplayMetrics.VirtualDisplayRect.Top;
		Info.VirtualDisplayRight = DisplayMetrics.VirtualDisplayRect.Right;
		Info.VirtualDisplayBottom = DisplayMetrics.VirtualDisplayRect.Bottom;
		Info.MonitorCount = DisplayMetrics.MonitorInfo.Num();
		Info.ApplicationScale = FSlateApplication::IsInitialized() ? FSlateApplication::Get().GetApplicationScale() : 1.f;

		for (const FMonitorInfo& MonitorInfo : DisplayMetrics.MonitorInfo)
		{
			Info.Monitors.Add(BuildMonitorInfoFromPlatformInfo(MonitorInfo));
		}

		return Info;
	}

	FDesktopMainWindowInfo BuildMainWindowInfoInternal()
	{
		FDesktopMainWindowInfo Info;
		Info.WindowMode = UBPFunctions_Desktop::GetWindowMode();

#if PLATFORM_WINDOWS
		const HWND Handle = GetMainWindowHandleInternal();
		Info.WindowHandleValue = reinterpret_cast<int64>(Handle);
		Info.bIsValid = Handle != nullptr;
		if (Handle != nullptr)
		{
			RECT WindowRect = { 0 };
			if (GetWindowRect(Handle, &WindowRect))
			{
				Info.PositionX = WindowRect.left;
				Info.PositionY = WindowRect.top;
				Info.SizeX = WindowRect.right - WindowRect.left;
				Info.SizeY = WindowRect.bottom - WindowRect.top;
			}

			RECT ClientRect = { 0 };
			if (GetClientRect(Handle, &ClientRect))
			{
				Info.ClientSizeX = ClientRect.right - ClientRect.left;
				Info.ClientSizeY = ClientRect.bottom - ClientRect.top;
			}

			Info.Title = GetWindowTitleInternal(Handle);
			Info.bIsVisible = IsWindowVisible(Handle) != 0;
			Info.bIsForeground = GetForegroundWindow() == Handle;
			Info.bIsMinimized = IsIconic(Handle) != 0;
			Info.bIsMaximized = IsZoomed(Handle) != 0;
			Info.bIsTopMost = (GetWindowLongPtr(Handle, GWL_EXSTYLE) & WS_EX_TOPMOST) != 0;

			DWORD Affinity = 0;
			if (GetWindowDisplayAffinity(Handle, &Affinity))
			{
				Info.bIsScreenCaptureDisabled = Affinity == WDA_EXCLUDEFROMCAPTURE;
			}
		}
#endif

		if (GEngine != nullptr && GEngine->GameViewport != nullptr)
		{
			FVector2D ViewportSize(0.f, 0.f);
			GEngine->GameViewport->GetViewportSize(ViewportSize);
			Info.ViewportSizeX = FMath::RoundToInt(ViewportSize.X);
			Info.ViewportSizeY = FMath::RoundToInt(ViewportSize.Y);
		}

		return Info;
	}

	void CollectNetworkAdapterInfosInternal(TArray<FDesktopNetworkAdapterInfo>& OutInfos)
	{
		OutInfos.Reset();

#if PLATFORM_WINDOWS
		ULONG BufferLength = 0;
		if (GetAdaptersInfo(nullptr, &BufferLength) != ERROR_BUFFER_OVERFLOW || BufferLength == 0)
		{
			return;
		}

		TArray<uint8> Buffer;
		Buffer.SetNumZeroed(BufferLength);
		PIP_ADAPTER_INFO AdapterInfo = reinterpret_cast<PIP_ADAPTER_INFO>(Buffer.GetData());
		if (GetAdaptersInfo(AdapterInfo, &BufferLength) != ERROR_SUCCESS)
		{
			return;
		}

		for (PIP_ADAPTER_INFO Adapter = AdapterInfo; Adapter != nullptr; Adapter = Adapter->Next)
		{
			FDesktopNetworkAdapterInfo Info;
			Info.Name = ANSI_TO_TCHAR(Adapter->AdapterName);
			Info.Description = ANSI_TO_TCHAR(Adapter->Description);
			Info.Index = static_cast<int32>(Adapter->Index);
			Info.Type = static_cast<int32>(Adapter->Type);
			Info.bEnableDHCP = Adapter->DhcpEnabled != 0;
			if (Adapter->AddressLength >= 6)
			{
				Info.MacAddress = FString::Printf(TEXT("%02X-%02X-%02X-%02X-%02X-%02X"), Adapter->Address[0], Adapter->Address[1], Adapter->Address[2], Adapter->Address[3], Adapter->Address[4], Adapter->Address[5]);
			}

			for (PIP_ADDR_STRING IpAddress = &Adapter->IpAddressList; IpAddress != nullptr; IpAddress = IpAddress->Next)
			{
				FDesktopNetworkAdapterIp IpInfo;
				IpInfo.Ip = ANSI_TO_TCHAR(IpAddress->IpAddress.String);
				IpInfo.Mask = ANSI_TO_TCHAR(IpAddress->IpMask.String);
				IpInfo.Gateway = ANSI_TO_TCHAR(Adapter->GatewayList.IpAddress.String);
				Info.IPList.Add(MoveTemp(IpInfo));
			}

			OutInfos.Add(MoveTemp(Info));
		}
#endif
	}

	FDesktopNetworkInfo BuildNetworkInfoInternal()
	{
		FDesktopNetworkInfo Info;
		Info.NetworkType = ConvertToWindowNetworkType(FPlatformMisc::GetNetworkConnectionType());
		Info.bHasWiFiConnection = FPlatformMisc::HasActiveWiFiConnection();
		Info.HostName = FPlatformProcess::ComputerName();

		TArray<FDesktopNetworkAdapterInfo> Adapters;
		CollectNetworkAdapterInfosInternal(Adapters);
		Info.AdapterCount = Adapters.Num();

		for (const FDesktopNetworkAdapterInfo& Adapter : Adapters)
		{
			if (Adapter.Type == 6)
			{
				Info.bHasEthernetConnection = true;
			}

			for (const FDesktopNetworkAdapterIp& IpInfo : Adapter.IPList)
			{
				if (Info.PrimaryIpv4.IsEmpty() && !IpInfo.Ip.IsEmpty() && IpInfo.Ip != TEXT("0.0.0.0"))
				{
					Info.PrimaryIpv4 = IpInfo.Ip;
				}
			}
		}

		Info.bHasNetwork = Info.NetworkType != EDesktopNetworkType::None
			&& Info.NetworkType != EDesktopNetworkType::Unknown
			&& (Info.AdapterCount > 0 || !Info.PrimaryIpv4.IsEmpty() || Info.bHasWiFiConnection || Info.bHasEthernetConnection);

		return Info;
	}

	FDesktopPowerInfo BuildPowerInfoInternal()
	{
		FDesktopPowerInfo Info;
		Info.bIsRunningOnBattery = FPlatformMisc::IsRunningOnBattery();

#if PLATFORM_WINDOWS
		SYSTEM_POWER_STATUS PowerStatus;
		if (GetSystemPowerStatus(&PowerStatus))
		{
			Info.PowerLineStatus = ConvertPowerLineStatus(PowerStatus);
			Info.BatteryState = ConvertBatteryState(PowerStatus);
			Info.BatteryPercent = PowerStatus.BatteryLifePercent == 255 ? -1 : static_cast<int32>(PowerStatus.BatteryLifePercent);
			Info.BatteryLifeTimeSeconds = PowerStatus.BatteryLifeTime == static_cast<DWORD>(-1) ? -1 : static_cast<int32>(PowerStatus.BatteryLifeTime);
			Info.BatteryFullLifeTimeSeconds = PowerStatus.BatteryFullLifeTime == static_cast<DWORD>(-1) ? -1 : static_cast<int32>(PowerStatus.BatteryFullLifeTime);
			Info.bHasBattery = PowerStatus.BatteryFlag != 128;
			Info.bIsBatterySaverEnabled = (PowerStatus.SystemStatusFlag & 0x01) != 0;
		}
#endif

		return Info;
	}
}

void UBPFunctions_Desktop::GetApplicationInfo(FDesktopApplicationInfo& OutInfo)
{
	OutInfo = BuildApplicationInfoInternal();
}

void UBPFunctions_Desktop::GetSystemPathInfo(FDesktopSystemPathInfo& OutInfo)
{
	OutInfo = BuildSystemPathInfoInternal();
}

FString UBPFunctions_Desktop::GetDeviceID()
{
	FString DeviceID;

#if PLATFORM_WINDOWS
	HKEY KeyHandle = nullptr;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Cryptography"), 0, KEY_READ, &KeyHandle) == ERROR_SUCCESS)
	{
		DWORD Type = REG_SZ;
		TCHAR Value[256] = { 0 };
		DWORD ValueSize = sizeof(Value);
		if (RegQueryValueEx(KeyHandle, TEXT("MachineGuid"), nullptr, &Type, reinterpret_cast<LPBYTE>(Value), &ValueSize) == ERROR_SUCCESS)
		{
			DeviceID = Value;
		}

		RegCloseKey(KeyHandle);
	}
#endif

	if (DeviceID.IsEmpty())
	{
		DeviceID = FPlatformMisc::GetOperatingSystemId();
	}

	return DeviceID;
}

FString UBPFunctions_Desktop::GetDesktopName()
{
	return FPlatformProcess::ComputerName();
}

FString UBPFunctions_Desktop::GetDesktopUserName()
{
	return FPlatformProcess::UserName();
}

FString UBPFunctions_Desktop::GetDesktopBaseDir()
{
	return FPlatformProcess::BaseDir();
}

FString UBPFunctions_Desktop::GetDesktopUserDir()
{
	return FPlatformProcess::UserDir();
}

FString UBPFunctions_Desktop::GetDesktopUserTempDir()
{
	return FPlatformProcess::UserTempDir();
}

FString UBPFunctions_Desktop::GetDesktopUserHomeDir()
{
	return FPlatformProcess::UserHomeDir();
}

FString UBPFunctions_Desktop::GetExecutablePath()
{
	return FPlatformProcess::ExecutablePath();
}

int32 UBPFunctions_Desktop::GetProcessId()
{
	return FPlatformProcess::GetCurrentProcessId();
}

FString UBPFunctions_Desktop::GetCommandLineString()
{
	return FCommandLine::Get();
}

FString UBPFunctions_Desktop::GetOperatingSystemId()
{
	return FPlatformMisc::GetOperatingSystemId();
}

FString UBPFunctions_Desktop::GetOSVersion()
{
	return FPlatformMisc::GetOSVersion();
}

void UBPFunctions_Desktop::GetOSVersions(FString& OutOSVersionLabel, FString& OutOSSubVersionLabel)
{
	FPlatformMisc::GetOSVersions(OutOSVersionLabel, OutOSSubVersionLabel);
}

bool UBPFunctions_Desktop::IsRunningAsAdministrator()
{
#if PLATFORM_WINDOWS
	return IsRunningAsAdministratorInternal();
#else
	return false;
#endif
}

FString UBPFunctions_Desktop::GetEnvironmentVariable(const FString& VariableName)
{
	return FPlatformMisc::GetEnvironmentVariable(*VariableName);
}

bool UBPFunctions_Desktop::GetPluginBaseDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir();
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginBinariesDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir() / TEXT("Binaries");
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginContentDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetContentDir();
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginIntermediateDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir() / TEXT("Intermediate");
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginResourcesDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir() / TEXT("Resources");
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginSourceDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir() / TEXT("Source");
		return true;
	}

	return false;
}

bool UBPFunctions_Desktop::GetPluginExtraDir(const FString& InPluginName, FString& Directory)
{
	if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName))
	{
		Directory = Plugin->GetBaseDir() / TEXT("Extra");
		return true;
	}

	return false;
}

FString UBPFunctions_Desktop::GetSaveGameDir()
{
	return FString::Printf(TEXT("%sSaveGames/"), *FPaths::ProjectSavedDir());
}

FString UBPFunctions_Desktop::GetExtrasDir()
{
	return FPaths::Combine(FPaths::ProjectDir(), TEXT("Extras"));
}

FString UBPFunctions_Desktop::GetDesktopDir()
{
	return BuildSystemPathInfoInternal().DesktopDir;
}

FString UBPFunctions_Desktop::GetDocumentsDir()
{
	return BuildSystemPathInfoInternal().DocumentsDir;
}

FString UBPFunctions_Desktop::GetDownloadsDir()
{
	return BuildSystemPathInfoInternal().DownloadsDir;
}

FString UBPFunctions_Desktop::GetAppDataDir()
{
	return BuildSystemPathInfoInternal().AppDataDir;
}

FString UBPFunctions_Desktop::GetLocalAppDataDir()
{
	return BuildSystemPathInfoInternal().LocalAppDataDir;
}

FString UBPFunctions_Desktop::GetProgramDataDir()
{
	return BuildSystemPathInfoInternal().ProgramDataDir;
}

FString UBPFunctions_Desktop::GetSavedGamesDir()
{
	return BuildSystemPathInfoInternal().SavedGamesDir;
}

FString UBPFunctions_Desktop::GetTempDir()
{
	return BuildSystemPathInfoInternal().TempDir;
}

bool UBPFunctions_Desktop::ExistDirectory(FString Directory)
{
	return FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*Directory);
}

bool UBPFunctions_Desktop::CreateDirectory(FString Directory)
{
	return FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*Directory);
}

bool UBPFunctions_Desktop::DeleteDirectory(FString Directory)
{
	return FPlatformFileManager::Get().GetPlatformFile().DeleteDirectory(*Directory);
}

bool UBPFunctions_Desktop::DeleteDirectoryRecursively(FString Directory)
{
	return FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*Directory);
}

TArray<FString> UBPFunctions_Desktop::FindDirectory(FString Directory)
{
	TArray<FString> Subdirectories;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(
		*Directory,
		[&Subdirectories](const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			if (bIsDirectory)
			{
				const FString DirName = FPaths::GetCleanFilename(FilenameOrDirectory);
				if (DirName != TEXT(".") && DirName != TEXT(".."))
				{
					Subdirectories.Add(FilenameOrDirectory);
				}
			}
			return true;
		});
	return Subdirectories;
}

TArray<FString> UBPFunctions_Desktop::FindDirectoryRecursive(FString Directory)
{
	TArray<FString> Subdirectories;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectoryRecursively(
		*Directory,
		[&Subdirectories](const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			if (bIsDirectory)
			{
				const FString DirName = FPaths::GetCleanFilename(FilenameOrDirectory);
				if (DirName != TEXT(".") && DirName != TEXT(".."))
				{
					Subdirectories.Add(FilenameOrDirectory);
				}
			}
			return true;
		});
	return Subdirectories;
}

FString UBPFunctions_Desktop::NormalizeDirectory(FString Directory)
{
	FPaths::NormalizeDirectoryName(Directory);
	return Directory;
}

bool UBPFunctions_Desktop::OpenDirectoryDialog(FString& Directory)
{
#if PLATFORM_WINDOWS
	return OpenDirectoryDialogInternal(Directory);
#else
	Directory.Reset();
	return false;
#endif
}

TArray<FString> UBPFunctions_Desktop::FindFile(FString Directory, FString Extension)
{
	TArray<FString> Result;
	IFileManager::Get().FindFiles(Result, *Directory, *Extension);
	return Result;
}

TArray<FString> UBPFunctions_Desktop::FindFileRecursive(FString Directory, FString Extension)
{
	TArray<FString> Result;
	IFileManager& FileManager = IFileManager::Get();
	if (FileManager.DirectoryExists(*Directory))
	{
		FileManager.FindFilesRecursive(Result, *Directory, *Extension, true, false);
	}
	return Result;
}

bool UBPFunctions_Desktop::ExistFile(FString FileName)
{
	return IFileManager::Get().FileExists(*FileName);
}

bool UBPFunctions_Desktop::CopyFile(FString FileSource, FString FileDest, bool Replace, bool EvenIfReadOnly)
{
	return IFileManager::Get().Copy(*FileDest, *FileSource, Replace, EvenIfReadOnly) == COPY_OK;
}

bool UBPFunctions_Desktop::MoveFile(FString FileSource, FString FileDest, bool Replace, bool EvenIfReadOnly)
{
	return IFileManager::Get().Move(*FileDest, *FileSource, Replace, EvenIfReadOnly);
}

bool UBPFunctions_Desktop::DeleteFile(FString FileName, bool RequireExists, bool EvenReadOnly)
{
	return IFileManager::Get().Delete(*FileName, RequireExists, EvenReadOnly);
}

int64 UBPFunctions_Desktop::FileSize(FString Filename)
{
	return IFileManager::Get().FileSize(*Filename);
}

FString UBPFunctions_Desktop::NormalizeFileName(FString Filename)
{
	FPaths::NormalizeFilename(Filename);
	return Filename;
}

bool UBPFunctions_Desktop::IsDrive(const FString& FileName)
{
	return FPaths::IsDrive(FileName);
}

bool UBPFunctions_Desktop::IsFileReadOnly(FString FileName)
{
	return IFileManager::Get().IsReadOnly(*FileName);
}

FString UBPFunctions_Desktop::GetFileExtension(FString FileName, bool bIncludeDot)
{
	return FPaths::GetExtension(FileName, bIncludeDot);
}

FString UBPFunctions_Desktop::SetFileExtension(FString FileName, FString NewExtension)
{
	return FPaths::SetExtension(FileName, NewExtension);
}

FString UBPFunctions_Desktop::GetCleanFilename(FString FileName)
{
	return FPaths::GetCleanFilename(FileName);
}

FString UBPFunctions_Desktop::GetBaseFilename(FString FileName, bool bRemovePath)
{
	return FPaths::GetBaseFilename(FileName, bRemovePath);
}

FString UBPFunctions_Desktop::GetFilePath(FString FileName)
{
	return FPaths::GetPath(FileName);
}

FString UBPFunctions_Desktop::GetFilePathLeaf(FString FileName)
{
	return FPaths::GetPathLeaf(FileName);
}

FDateTime UBPFunctions_Desktop::GetTimeStamp(FString FileName)
{
	return FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*FileName);
}

bool UBPFunctions_Desktop::IsRelative(FString FileName)
{
	return FPaths::IsRelative(FileName);
}

FString UBPFunctions_Desktop::ConvertToRelativePath(const FString& Filename)
{
	return IFileManager::Get().ConvertToRelativePath(*Filename);
}

FString UBPFunctions_Desktop::ConvertToFullPath(const FString& Filename)
{
	return FPaths::ConvertRelativePathToFull(Filename);
}

bool UBPFunctions_Desktop::IsUnderDirectory(const FString& Filename, const FString& Directory)
{
	return FPaths::IsUnderDirectory(Filename, Directory);
}

FString UBPFunctions_Desktop::MakeValidFileName(const FString& Filename)
{
	return FPaths::MakeValidFileName(Filename);
}

bool UBPFunctions_Desktop::OpenFileDialog(FString FileType, TArray<FString>& FilePaths)
{
#if PLATFORM_WINDOWS
	return OpenFileDialogInternal(FileType, FilePaths);
#else
	FilePaths.Reset();
	return false;
#endif
}

bool UBPFunctions_Desktop::SaveFileDialog(FString FileName, FString FileType, TArray<FString>& FilePaths)
{
#if PLATFORM_WINDOWS
	if (FileType.IsEmpty())
	{
		FilePaths.Reset();
		return false;
	}

	return SaveFileDialogInternal(FileName, FileType, FilePaths);
#else
	FilePaths.Reset();
	return false;
#endif
}

bool UBPFunctions_Desktop::ReadBytesFromFile(const FString& FileName, TArray<uint8>& OutBytes)
{
	return FFileHelper::LoadFileToArray(OutBytes, *FileName);
}

bool UBPFunctions_Desktop::SaveBytesToFile(const FString& FileName, const TArray<uint8>& Bytes)
{
	return FFileHelper::SaveArrayToFile(Bytes, *FileName);
}

bool UBPFunctions_Desktop::AddBytesToFile(const FString& FileName, TArray<uint8> Bytes)
{
	FArchive* Writer = IFileManager::Get().CreateFileWriter(*FileName, EFileWrite::FILEWRITE_Append);
	if (Writer == nullptr)
	{
		return false;
	}

	Writer->Seek(Writer->TotalSize());
	Writer->Serialize(Bytes.GetData(), Bytes.Num());
	Writer->Close();
	delete Writer;
	return true;
}

bool UBPFunctions_Desktop::ReadStringFromFile(FString FileName, FString& Data)
{
	return FFileHelper::LoadFileToString(Data, *FileName);
}

bool UBPFunctions_Desktop::WriteStringToFile(FString Data, FString FileName, EDesktopTextEncodingOptions EncodingOptions)
{
	return FFileHelper::SaveStringToFile(Data, *FileName, ConvertToDesktopEncodingOptions(EncodingOptions));
}

void UBPFunctions_Desktop::StringToBase64String(FString String, FString& Base64String)
{
	FTCHARToUTF8 Convert(*String);
	TArray<uint8> Bytes;
	Bytes.Append(reinterpret_cast<const uint8*>(Convert.Get()), Convert.Length());
	Base64String = FBase64::Encode(Bytes);
}

bool UBPFunctions_Desktop::Base64StringToString(FString Base64String, FString& String)
{
	TArray<uint8> Bytes;
	if (!FBase64::Decode(*Base64String, Bytes))
	{
		String.Reset();
		return false;
	}

	Bytes.Add(0x00);
	String = FString(UTF8_TO_TCHAR(reinterpret_cast<const char*>(Bytes.GetData())));
	return true;
}

void UBPFunctions_Desktop::BytesToBase64String(TArray<uint8> Bytes, FString& Base64String)
{
	Base64String = FBase64::Encode(Bytes);
}

bool UBPFunctions_Desktop::Base64StringToBytes(FString Base64String, TArray<uint8>& Bytes)
{
	Bytes.Reset();
	return FBase64::Decode(*Base64String, Bytes);
}

UTexture2D* UBPFunctions_Desktop::LoadImageFromDialog()
{
	TArray<FString> FilePaths;
	if (!OpenFileDialog(TEXT(""), FilePaths) || FilePaths.Num() == 0)
	{
		return nullptr;
	}

	return LoadImageFromFile(FilePaths[0]);
}

UTexture2D* UBPFunctions_Desktop::LoadImageFromFile(FString ImagePath)
{
	TArray<uint8> FileData;
	if (!FFileHelper::LoadFileToArray(FileData, *ImagePath))
	{
		return nullptr;
	}

	return ConvBytesToTexture2D(FileData);
}

UTexture2D* UBPFunctions_Desktop::ConvBytesToTexture2D(const TArray<uint8>& InBytes)
{
	if (InBytes.Num() == 0)
	{
		return nullptr;
	}

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
	const EImageFormat DetectedFormat = ImageWrapperModule.DetectImageFormat(InBytes.GetData(), InBytes.Num());
	if (DetectedFormat == EImageFormat::Invalid)
	{
		return nullptr;
	}

	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(DetectedFormat);
	if (!ImageWrapper.IsValid() || !ImageWrapper->SetCompressed(InBytes.GetData(), InBytes.Num()))
	{
		return nullptr;
	}

	UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);
	if (Texture == nullptr)
	{
		return nullptr;
	}

	Texture->UpdateResource();

	Async(EAsyncExecution::ThreadPool, [ImageWrapper, Texture]()
	{
		TArray64<uint8> BufferArray;
		if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, BufferArray))
		{
			FUpdateTextureRegion2D Region(0, 0, 0, 0, ImageWrapper->GetWidth(), ImageWrapper->GetHeight());
			const uint32 Pitch = ImageWrapper->GetWidth() * 4;

			ENQUEUE_RENDER_COMMAND(BytesToTextureCommand)(
				[Texture, Region, Pitch, BufferArray = MoveTemp(BufferArray)](FRHICommandListImmediate& RHICmdList)
				{
					if (Texture != nullptr && Texture->GetResource() != nullptr)
					{
						RHIUpdateTexture2D(
							static_cast<FTextureResource*>(Texture->GetResource())->TextureRHI->GetTexture2D(),
							0,
							Region,
							Pitch,
							BufferArray.GetData());
					}
				});
		}
	});

	return Texture;
}

bool UBPFunctions_Desktop::ConvTexture2DToBytes(UTexture2D* Texture, TArray<uint8>& OutBuffer, EDesktopImageFormat Format)
{
	OutBuffer.Reset();
	if (Texture == nullptr || Texture->GetPlatformData() == nullptr || Texture->GetPlatformData()->Mips.Num() == 0)
	{
		return false;
	}

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ConvertToDesktopImageFormat(Format));
	if (!ImageWrapper.IsValid())
	{
		return false;
	}

	const int32 Width = Texture->GetPlatformData()->Mips[0].SizeX;
	const int32 Height = Texture->GetPlatformData()->Mips[0].SizeY;
	const int32 DataLength = Width * Height * 4;
	void* TextureDataPointer = Texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_ONLY);
	const bool bSetRaw = ImageWrapper->SetRaw(TextureDataPointer, DataLength, Width, Height, ERGBFormat::BGRA, 8);
	Texture->GetPlatformData()->Mips[0].BulkData.Unlock();

	if (!bSetRaw)
	{
		return false;
	}

	OutBuffer = ImageWrapper->GetCompressed();
	return OutBuffer.Num() > 0;
}

void UBPFunctions_Desktop::SetClipboardText(const FString& InText)
{
	FPlatformApplicationMisc::ClipboardCopy(*InText);
}

FString UBPFunctions_Desktop::GetClipboardText()
{
	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);
	return ClipboardText;
}

bool UBPFunctions_Desktop::CanLaunchUrl(const FString& InUrl)
{
	return FPlatformProcess::CanLaunchURL(*InUrl);
}

bool UBPFunctions_Desktop::LaunchUrl(const FString& InUrl)
{
	if (!CanLaunchUrl(InUrl))
	{
		return false;
	}

	FPlatformProcess::LaunchURL(*InUrl, nullptr, nullptr);
	return true;
}

bool UBPFunctions_Desktop::OpenFileInShell(const FString& InFilePath)
{
	return FPlatformProcess::LaunchFileInDefaultExternalApplication(*NormalizeExternalPath(InFilePath));
}

bool UBPFunctions_Desktop::OpenDirectoryInShell(const FString& InDirectoryPath)
{
	const FString DirectoryPath = NormalizeExternalPath(InDirectoryPath);
	if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*DirectoryPath))
	{
		return false;
	}

	FPlatformProcess::ExploreFolder(*DirectoryPath);
	return true;
}

bool UBPFunctions_Desktop::RevealFileInExplorer(const FString& InFilePath)
{
	const FString FilePath = NormalizeExternalPath(InFilePath);
	if (!IFileManager::Get().FileExists(*FilePath))
	{
		return false;
	}

#if PLATFORM_WINDOWS
	const FString Params = FString::Printf(TEXT("/select,\"%s\""), *FilePath);
	FProcHandle ProcHandle = FPlatformProcess::CreateProc(TEXT("explorer.exe"), *Params, true, false, false, nullptr, 0, nullptr, nullptr);
	return ProcHandle.IsValid();
#else
	FPlatformProcess::ExploreFolder(*FPaths::GetPath(FilePath));
	return true;
#endif
}

void UBPFunctions_Desktop::GetSystemFontBytes(TArray<uint8>& OutBytes)
{
	OutBytes = FPlatformMisc::GetSystemFontBytes();
}

void UBPFunctions_Desktop::GetDisplayInfo(FDesktopDisplayInfo& OutInfo)
{
	OutInfo = BuildDisplayInfoInternal();
}

void UBPFunctions_Desktop::GetPrimaryMonitorInfo(FDesktopMonitorInfo& OutInfo)
{
	OutInfo = FDesktopMonitorInfo();
	const FDesktopDisplayInfo DisplayInfo = BuildDisplayInfoInternal();
	for (const FDesktopMonitorInfo& Monitor : DisplayInfo.Monitors)
	{
		if (Monitor.bIsPrimary)
		{
			OutInfo = Monitor;
			return;
		}
	}
}

void UBPFunctions_Desktop::GetCurrentMonitorInfo(FDesktopMonitorInfo& OutInfo)
{
	OutInfo = FDesktopMonitorInfo();
	const FDesktopDisplayInfo DisplayInfo = BuildDisplayInfoInternal();

#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	if (Handle != nullptr)
	{
		MONITORINFOEX MonitorInfo;
		FMemory::Memzero(MonitorInfo);
		MonitorInfo.cbSize = sizeof(MONITORINFOEX);
		if (GetMonitorInfo(MonitorFromWindow(Handle, MONITOR_DEFAULTTOPRIMARY), &MonitorInfo))
		{
			for (const FDesktopMonitorInfo& Monitor : DisplayInfo.Monitors)
			{
				if (Monitor.DisplayLeft == MonitorInfo.rcMonitor.left
					&& Monitor.DisplayTop == MonitorInfo.rcMonitor.top
					&& Monitor.DisplayRight == MonitorInfo.rcMonitor.right
					&& Monitor.DisplayBottom == MonitorInfo.rcMonitor.bottom)
				{
					OutInfo = Monitor;
					return;
				}
			}
		}
	}
#endif

	GetPrimaryMonitorInfo(OutInfo);
}

void UBPFunctions_Desktop::GetAllMonitorInfos(TArray<FDesktopMonitorInfo>& OutInfos)
{
	OutInfos = BuildDisplayInfoInternal().Monitors;
}

int32 UBPFunctions_Desktop::GetMonitorCount()
{
	return BuildDisplayInfoInternal().MonitorCount;
}

void UBPFunctions_Desktop::GetMainWindowInfo(FDesktopMainWindowInfo& OutInfo)
{
	OutInfo = BuildMainWindowInfoInternal();
}

FString UBPFunctions_Desktop::GetMainWindowTitle()
{
	return BuildMainWindowInfoInternal().Title;
}

bool UBPFunctions_Desktop::SetMainWindowTitle(const FString& InTitle)
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	return Handle != nullptr && SetWindowText(Handle, *InTitle) != 0;
#else
	return false;
#endif
}

int64 UBPFunctions_Desktop::GetMainWindowHandleValue()
{
	return BuildMainWindowInfoInternal().WindowHandleValue;
}

bool UBPFunctions_Desktop::IsMainWindowValid()
{
	return BuildMainWindowInfoInternal().bIsValid;
}

bool UBPFunctions_Desktop::IsMainWindowActive()
{
	return BuildMainWindowInfoInternal().bIsForeground;
}

bool UBPFunctions_Desktop::IsMainWindowMinimized()
{
	return BuildMainWindowInfoInternal().bIsMinimized;
}

bool UBPFunctions_Desktop::IsMainWindowMaximized()
{
	return BuildMainWindowInfoInternal().bIsMaximized;
}

bool UBPFunctions_Desktop::BringMainWindowToFront()
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	return Handle != nullptr && SetForegroundWindow(Handle) != 0;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::MinimizeMainWindow()
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	if (Handle == nullptr)
	{
		return false;
	}

	ShowWindow(Handle, SW_MINIMIZE);
	return true;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::MaximizeMainWindow()
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	if (Handle == nullptr)
	{
		return false;
	}

	ShowWindow(Handle, SW_MAXIMIZE);
	return true;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::RestoreMainWindow()
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	if (Handle == nullptr)
	{
		return false;
	}

	ShowWindow(Handle, SW_RESTORE);
	return true;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::MoveMainWindow(int32 NewPositionX, int32 NewPositionY)
{
#if PLATFORM_WINDOWS
	const FDesktopMainWindowInfo WindowInfo = BuildMainWindowInfoInternal();
	const HWND Handle = reinterpret_cast<HWND>(WindowInfo.WindowHandleValue);
	return Handle != nullptr && SetWindowPos(Handle, nullptr, NewPositionX, NewPositionY, 0, 0, SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER) != 0;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::ResizeMainWindow(int32 NewSizeX, int32 NewSizeY)
{
#if PLATFORM_WINDOWS
	const FDesktopMainWindowInfo WindowInfo = BuildMainWindowInfoInternal();
	const HWND Handle = reinterpret_cast<HWND>(WindowInfo.WindowHandleValue);
	return Handle != nullptr && SetWindowPos(Handle, nullptr, 0, 0, NewSizeX, NewSizeY, SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOMOVE | SWP_NOZORDER) != 0;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::SetMainWindowTopMost(bool bEnable)
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	return Handle != nullptr && SetWindowPos(Handle, bEnable ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE) != 0;
#else
	return false;
#endif
}

bool UBPFunctions_Desktop::FlashMainWindow(bool bStop)
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	if (Handle == nullptr)
	{
		return false;
	}

	FLASHWINFO FlashInfo;
	FlashInfo.cbSize = sizeof(FLASHWINFO);
	FlashInfo.hwnd = Handle;
	FlashInfo.dwFlags = bStop ? FLASHW_STOP : (FLASHW_ALL | FLASHW_TIMERNOFG);
	FlashInfo.uCount = bStop ? 0 : 3;
	FlashInfo.dwTimeout = 0;
	return FlashWindowEx(&FlashInfo) != 0;
#else
	return false;
#endif
}

EDesktopDisplayMode UBPFunctions_Desktop::GetWindowMode()
{
	if (GEngine == nullptr)
	{
		return EDesktopDisplayMode::Unknown;
	}

	const UGameUserSettings* Settings = GEngine->GetGameUserSettings();
	return Settings == nullptr ? EDesktopDisplayMode::Unknown : ConvertToWindowDisplayMode(Settings->GetFullscreenMode());
}

bool UBPFunctions_Desktop::SetWindowMode(EDesktopDisplayMode InWindowMode)
{
	if (GEngine == nullptr)
	{
		return false;
	}

	UGameUserSettings* Settings = GEngine->GetGameUserSettings();
	if (Settings == nullptr)
	{
		return false;
	}

	Settings->SetFullscreenMode(ConvertFromWindowDisplayMode(InWindowMode));
	Settings->ApplySettings(false);
	return true;
}

void UBPFunctions_Desktop::RequestMinimizeApplication()
{
	MinimizeMainWindow();
}

bool UBPFunctions_Desktop::RestartApplication()
{
	return FPlatformMisc::RestartApplication();
}

bool UBPFunctions_Desktop::IsScreenCaptureDisabled()
{
	return BuildMainWindowInfoInternal().bIsScreenCaptureDisabled;
}

bool UBPFunctions_Desktop::SetScreenCaptureDisabled(bool bDisable)
{
#if PLATFORM_WINDOWS
	const HWND Handle = GetMainWindowHandleInternal();
	return Handle != nullptr && SetWindowDisplayAffinity(Handle, bDisable ? WDA_EXCLUDEFROMCAPTURE : WDA_NONE) != 0;
#else
	return false;
#endif
}

void UBPFunctions_Desktop::GetCPUHardwareInfo(FDesktopCPUInfo& OutInfo)
{
	OutInfo = FDesktopCPUInfo();
	OutInfo.Vendor = GetCPUVendor();
	OutInfo.Brand = GetCPUBrand();
	OutInfo.Chipset = GetCPUChipset();
	OutInfo.PhysicalCores = GetCPUPhysicalCores();
	OutInfo.LogicalCores = GetCPULogicalCores();
	OutInfo.UsagePercent = GetCPUUsage();
	OutInfo.FrequencyMHz = GetCPUFrequency();
	OutInfo.ProcessCount = GetCPUProcessCount();
	OutInfo.ThreadCount = GetCPUThreadCount();
	OutInfo.SystemUptimeSeconds = GetSystemUptimeSecond();
}

void UBPFunctions_Desktop::Test_CPUInfo()
{
	FDesktopCPUInfo Info;
	GetCPUHardwareInfo(Info);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU Vendor: %s"), *Info.Vendor);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU Brand: %s"), *Info.Brand);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU Chipset: %s"), *Info.Chipset);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU PhysicalCores: %d"), Info.PhysicalCores);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU LogicalCores: %d"), Info.LogicalCores);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU UsagePercent: %.2f"), Info.UsagePercent);
	UE_LOG(GenericLogWindows, Display, TEXT("CPU FrequencyMHz: %.2f"), Info.FrequencyMHz);
}

FString UBPFunctions_Desktop::GetCPUVendor()
{
	return FPlatformMisc::GetCPUVendor();
}

FString UBPFunctions_Desktop::GetCPUBrand()
{
	return FPlatformMisc::GetCPUBrand();
}

FString UBPFunctions_Desktop::GetCPUChipset()
{
	return FPlatformMisc::GetCPUChipset();
}

int32 UBPFunctions_Desktop::GetCPUPhysicalCores()
{
	return FPlatformMisc::NumberOfCores();
}

int32 UBPFunctions_Desktop::GetCPUCores()
{
	return FPlatformMisc::NumberOfCoresIncludingHyperthreads();
}

int32 UBPFunctions_Desktop::GetCPULogicalCores()
{
	return FPlatformMisc::NumberOfCoresIncludingHyperthreads();
}

float UBPFunctions_Desktop::GetCPUUsage()
{
#if PLATFORM_WINDOWS
	auto FileTimeToUInt64 = [](const FILETIME& Time) -> uint64
	{
		ULARGE_INTEGER Value;
		Value.LowPart = Time.dwLowDateTime;
		Value.HighPart = Time.dwHighDateTime;
		return Value.QuadPart;
	};

	FILETIME IdleTime;
	FILETIME KernelTime;
	FILETIME UserTime;
	if (!GetSystemTimes(&IdleTime, &KernelTime, &UserTime))
	{
		return -1.f;
	}

	static uint64 PreviousIdleTime = 0;
	static uint64 PreviousKernelTime = 0;
	static uint64 PreviousUserTime = 0;
	static bool bHasPreviousSample = false;

	const uint64 CurrentIdleTime = FileTimeToUInt64(IdleTime);
	const uint64 CurrentKernelTime = FileTimeToUInt64(KernelTime);
	const uint64 CurrentUserTime = FileTimeToUInt64(UserTime);

	if (!bHasPreviousSample)
	{
		PreviousIdleTime = CurrentIdleTime;
		PreviousKernelTime = CurrentKernelTime;
		PreviousUserTime = CurrentUserTime;
		bHasPreviousSample = true;
		return 0.f;
	}

	const uint64 IdleDelta = CurrentIdleTime - PreviousIdleTime;
	const uint64 KernelDelta = CurrentKernelTime - PreviousKernelTime;
	const uint64 UserDelta = CurrentUserTime - PreviousUserTime;
	const uint64 TotalDelta = KernelDelta + UserDelta;

	PreviousIdleTime = CurrentIdleTime;
	PreviousKernelTime = CurrentKernelTime;
	PreviousUserTime = CurrentUserTime;

	if (TotalDelta == 0)
	{
		return 0.f;
	}

	return FMath::Clamp(static_cast<float>((static_cast<double>(TotalDelta - IdleDelta) / static_cast<double>(TotalDelta)) * 100.0), 0.f, 100.f);
#else
	return -1.f;
#endif
}

float UBPFunctions_Desktop::GetCPUFrequency()
{
#if PLATFORM_WINDOWS
	HKEY KeyHandle = nullptr;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"), 0, KEY_READ, &KeyHandle) != ERROR_SUCCESS)
	{
		return 0.f;
	}

	DWORD FrequencyMHz = 0;
	DWORD Size = sizeof(DWORD);
	if (RegQueryValueEx(KeyHandle, TEXT("~MHz"), nullptr, nullptr, reinterpret_cast<LPBYTE>(&FrequencyMHz), &Size) != ERROR_SUCCESS)
	{
		RegCloseKey(KeyHandle);
		return 0.f;
	}

	RegCloseKey(KeyHandle);
	return static_cast<float>(FrequencyMHz);
#else
	return -1.f;
#endif
}

int32 UBPFunctions_Desktop::GetCPUProcessCount()
{
#if PLATFORM_WINDOWS
	ULONG Processes[2048];
	DWORD BytesNeeded = 0;
	if (!EnumProcesses(Processes, sizeof(Processes), &BytesNeeded))
	{
		return 0;
	}

	return static_cast<int32>(BytesNeeded / sizeof(DWORD));
#else
	return -1;
#endif
}

int32 UBPFunctions_Desktop::GetCPUThreadCount()
{
#if PLATFORM_WINDOWS
	HANDLE SnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (SnapshotHandle == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	THREADENTRY32 ThreadEntry;
	ThreadEntry.dwSize = sizeof(THREADENTRY32);
	int32 ThreadCount = 0;
	if (Thread32First(SnapshotHandle, &ThreadEntry))
	{
		do
		{
			++ThreadCount;
		}
		while (Thread32Next(SnapshotHandle, &ThreadEntry));
	}

	CloseHandle(SnapshotHandle);
	return ThreadCount;
#else
	return -1;
#endif
}

double UBPFunctions_Desktop::GetSystemUptimeSecond()
{
#if PLATFORM_WINDOWS
	return static_cast<double>(GetTickCount64()) / 1000.0;
#else
	return -1.0;
#endif
}

void UBPFunctions_Desktop::GetGPUHardwareInfo(FDesktopGPUInfo& OutInfo)
{
	OutInfo = FDesktopGPUInfo();
	const FGPUDriverInfo DriverInfo = GetCurrentGPUDriverInfo();

	float TotalUsagePercent = -1.f;
	float CurrentProcessUsagePercent = -1.f;
	if (GRHIGlobals.IsRHIInitialized && GRHISupportsGPUUsage && RHIGetGPUUsage != nullptr)
	{
		const FRHIGPUUsageFractions Usage = RHIGetGPUUsage(0);
		const float CurrentProcessUsageFraction = GetCurrentProcessGPUUsageFraction(Usage);
		TotalUsagePercent = FMath::Clamp((CurrentProcessUsageFraction + GetExternalProcessGPUUsageFraction(Usage)) * 100.f, 0.f, 100.f);
		CurrentProcessUsagePercent = FMath::Clamp(CurrentProcessUsageFraction * 100.f, 0.f, 100.f);
	}

	OutInfo.Brand = GetGPUBrand();
	OutInfo.AdapterName = GetGPUAdapterName();
	OutInfo.ProviderName = DriverInfo.ProviderName;
	OutInfo.DriverInternalVersion = GetGPUAdapterInternalDriverVersion();
	OutInfo.DriverUserVersion = GetGPUAdapterUserDriverVersion();
	OutInfo.DriverUnifiedVersion = DriverInfo.GetUnifiedDriverVersion();
	OutInfo.DriverDate = GetGPUAdapterDriverDate();
	OutInfo.DriverRHIName = GetGPURHIName();
	OutInfo.VendorId = GetGPUVendorId();
	OutInfo.DeviceId = GetGPUDeviceId();
	OutInfo.DeviceRevision = GetGPUDeviceRevision();
	OutInfo.UsagePercent = TotalUsagePercent;
	OutInfo.ProcessUsagePercent = CurrentProcessUsagePercent;
}

void UBPFunctions_Desktop::GetGPUMemoryInfo(FDesktopGPUMemoryInfo& OutInfo)
{
	OutInfo = BuildGPUMemoryInfo();
}

void UBPFunctions_Desktop::Test_GPUInfo()
{
	FDesktopGPUInfo Info;
	GetGPUHardwareInfo(Info);
	UE_LOG(GenericLogWindows, Display, TEXT("GPU Brand: %s"), *Info.Brand);
	UE_LOG(GenericLogWindows, Display, TEXT("GPU AdapterName: %s"), *Info.AdapterName);
	UE_LOG(GenericLogWindows, Display, TEXT("GPU ProviderName: %s"), *Info.ProviderName);
	UE_LOG(GenericLogWindows, Display, TEXT("GPU DriverUnifiedVersion: %s"), *Info.DriverUnifiedVersion);
	UE_LOG(GenericLogWindows, Display, TEXT("GPU UsagePercent: %.2f"), Info.UsagePercent);
}

FString UBPFunctions_Desktop::GetGPUBrand()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

FString UBPFunctions_Desktop::GetGPUAdapterName()
{
	return GRHIGlobals.GpuInfo.AdapterName.IsEmpty() ? GetGPUBrand() : GRHIGlobals.GpuInfo.AdapterName;
}

FString UBPFunctions_Desktop::GetGPUAdapterInternalDriverVersion()
{
	return GRHIGlobals.GpuInfo.AdapterInternalDriverVersion;
}

FString UBPFunctions_Desktop::GetGPUAdapterUserDriverVersion()
{
	return GRHIGlobals.GpuInfo.AdapterUserDriverVersion;
}

FString UBPFunctions_Desktop::GetGPUAdapterDriverDate()
{
	return GRHIGlobals.GpuInfo.AdapterDriverDate;
}

FString UBPFunctions_Desktop::GetGPUProviderName()
{
	const FGPUDriverInfo DriverInfo = GetCurrentGPUDriverInfo();
	if (!DriverInfo.ProviderName.IsEmpty())
	{
		return DriverInfo.ProviderName;
	}

	switch (GRHIGlobals.GpuInfo.VendorId)
	{
	case 0x10DE:
		return TEXT("NVIDIA");
	case 0x1002:
		return TEXT("AMD");
	case 0x8086:
		return TEXT("Intel");
	default:
		return FString();
	}
}

FString UBPFunctions_Desktop::GetGPUDriverUnifiedVersion()
{
	return GetCurrentGPUDriverInfo().GetUnifiedDriverVersion();
}

FString UBPFunctions_Desktop::GetGPURHIName()
{
	return GetCurrentGPUDriverInfo().RHIName;
}

FString UBPFunctions_Desktop::GetGPUDeviceId()
{
	return FString::FromInt(GRHIGlobals.GpuInfo.DeviceId);
}

FString UBPFunctions_Desktop::GetGPUDeviceRevision()
{
	return FString::FromInt(GRHIGlobals.GpuInfo.DeviceRevision);
}

FString UBPFunctions_Desktop::GetGPUVendorId()
{
	return FString::FromInt(GRHIGlobals.GpuInfo.VendorId);
}

float UBPFunctions_Desktop::GetGPUUsage()
{
	if (!GRHIGlobals.IsRHIInitialized || !GRHISupportsGPUUsage || RHIGetGPUUsage == nullptr)
	{
		return -1.f;
	}

	const FRHIGPUUsageFractions Usage = RHIGetGPUUsage(0);
	return FMath::Clamp((GetCurrentProcessGPUUsageFraction(Usage) + GetExternalProcessGPUUsageFraction(Usage)) * 100.f, 0.f, 100.f);
}

void UBPFunctions_Desktop::GetMemoryHardwareInfo(FDesktopMemoryInfo& OutInfo)
{
	OutInfo = BuildMemoryInfo();
}

int64 UBPFunctions_Desktop::GetMemoryTotalPhysicalBytes()
{
	return BuildMemoryInfo().TotalPhysicalBytes;
}

int64 UBPFunctions_Desktop::GetMemoryAvailablePhysicalBytes()
{
	return BuildMemoryInfo().AvailablePhysicalBytes;
}

int64 UBPFunctions_Desktop::GetMemorySystemUsedPhysicalBytes()
{
	return BuildMemoryInfo().SystemUsedPhysicalBytes;
}

int64 UBPFunctions_Desktop::GetMemoryProcessUsedPhysicalBytes()
{
	return BuildMemoryInfo().ProcessUsedPhysicalBytes;
}

bool UBPFunctions_Desktop::GetDiskInfo(const FString& InPath, FDesktopDiskInfo& OutInfo)
{
	return PopulateDiskInfoInternal(InPath, OutInfo);
}

bool UBPFunctions_Desktop::GetProjectDiskInfo(FDesktopDiskInfo& OutInfo)
{
	return PopulateDiskInfoInternal(FPaths::ProjectDir(), OutInfo);
}

void UBPFunctions_Desktop::GetAllDiskInfos(TArray<FDesktopDiskInfo>& OutInfos)
{
	OutInfos.Reset();

#if PLATFORM_WINDOWS
	const DWORD BufferLength = GetLogicalDriveStrings(0, nullptr);
	if (BufferLength == 0)
	{
		return;
	}

	TArray<TCHAR> Buffer;
	Buffer.SetNumZeroed(BufferLength + 1);
	if (GetLogicalDriveStrings(BufferLength, Buffer.GetData()) == 0)
	{
		return;
	}

	for (const TCHAR* Drive = Buffer.GetData(); *Drive != TEXT('\0'); Drive += FCString::Strlen(Drive) + 1)
	{
		FDesktopDiskInfo DiskInfo;
		if (PopulateDiskInfoInternal(FString(Drive), DiskInfo))
		{
			OutInfos.Add(MoveTemp(DiskInfo));
		}
	}
#else
	FWindowDiskInfo DiskInfo;
	if (GetProjectDiskInfo(DiskInfo))
	{
		OutInfos.Add(MoveTemp(DiskInfo));
	}
#endif
}

int64 UBPFunctions_Desktop::GetDiskTotalBytes(const FString& InPath)
{
	FDesktopDiskInfo DiskInfo;
	return PopulateDiskInfoInternal(InPath, DiskInfo) ? DiskInfo.TotalBytes : -1;
}

int64 UBPFunctions_Desktop::GetDiskFreeBytes(const FString& InPath)
{
	FDesktopDiskInfo DiskInfo;
	return PopulateDiskInfoInternal(InPath, DiskInfo) ? DiskInfo.FreeBytes : -1;
}

int64 UBPFunctions_Desktop::GetDiskUsedBytes(const FString& InPath)
{
	FDesktopDiskInfo DiskInfo;
	return PopulateDiskInfoInternal(InPath, DiskInfo) ? DiskInfo.UsedBytes : -1;
}

void UBPFunctions_Desktop::GetPowerInfo(FDesktopPowerInfo& OutInfo)
{
	OutInfo = BuildPowerInfoInternal();
}

bool UBPFunctions_Desktop::IsLaptopDevice()
{
	return BuildPowerInfoInternal().bHasBattery;
}

bool UBPFunctions_Desktop::IsRunningOnBattery()
{
	return BuildPowerInfoInternal().bIsRunningOnBattery;
}

int32 UBPFunctions_Desktop::GetBatteryPercent()
{
	return BuildPowerInfoInternal().BatteryPercent;
}

void UBPFunctions_Desktop::GetNetworkAdapterInfo(TArray<FDesktopNetworkAdapterInfo>& OutInfos)
{
	CollectNetworkAdapterInfosInternal(OutInfos);
}

void UBPFunctions_Desktop::GetNetworkInfo(FDesktopNetworkInfo& OutInfo)
{
	OutInfo = BuildNetworkInfoInternal();
}

void UBPFunctions_Desktop::GetHardwareSnapshot(FDesktopHardwareSnapshot& OutSnapshot)
{
	OutSnapshot = FDesktopHardwareSnapshot();
	OutSnapshot.CaptureTimeSeconds = FPlatformTime::Seconds();
	OutSnapshot.ApplicationInfo = BuildApplicationInfoInternal();
	OutSnapshot.SystemPathInfo = BuildSystemPathInfoInternal();
	OutSnapshot.DisplayInfo = BuildDisplayInfoInternal();
	OutSnapshot.MainWindowInfo = BuildMainWindowInfoInternal();
	GetCPUHardwareInfo(OutSnapshot.CPUInfo);
	GetGPUHardwareInfo(OutSnapshot.GPUInfo);
	GetGPUMemoryInfo(OutSnapshot.GPUMemoryInfo);
	GetMemoryHardwareInfo(OutSnapshot.MemoryInfo);
	GetProjectDiskInfo(OutSnapshot.ProjectDiskInfo);
	GetAllDiskInfos(OutSnapshot.DiskInfos);
	GetPowerInfo(OutSnapshot.PowerInfo);
	GetNetworkInfo(OutSnapshot.NetworkInfo);
	GetNetworkAdapterInfo(OutSnapshot.NetworkAdapters);
}

FString UBPFunctions_Desktop::GetWindowDebugReport()
{
	FDesktopHardwareSnapshot Snapshot;
	GetHardwareSnapshot(Snapshot);

	FString Report;
	auto AppendLine = [&Report](const FString& Line)
	{
		Report += Line;
		Report += LINE_TERMINATOR;
	};

	AppendLine(TEXT("[Application]"));
	AppendLine(FString::Printf(TEXT("DeviceId=%s"), *Snapshot.ApplicationInfo.DeviceId));
	AppendLine(FString::Printf(TEXT("ComputerName=%s"), *Snapshot.ApplicationInfo.ComputerName));
	AppendLine(FString::Printf(TEXT("UserName=%s"), *Snapshot.ApplicationInfo.UserName));
	AppendLine(FString::Printf(TEXT("ExecutablePath=%s"), *Snapshot.ApplicationInfo.ExecutablePath));
	AppendLine(FString::Printf(TEXT("ProcessId=%d"), Snapshot.ApplicationInfo.ProcessId));
	AppendLine(FString::Printf(TEXT("OSVersion=%s"), *Snapshot.ApplicationInfo.OSVersion));
	AppendLine(FString::Printf(TEXT("OSVersionLabel=%s %s"), *Snapshot.ApplicationInfo.OSVersionLabel, *Snapshot.ApplicationInfo.OSSubVersionLabel));
	AppendLine(FString::Printf(TEXT("IsAdministrator=%s"), *BoolToString(Snapshot.ApplicationInfo.bIsRunningAsAdministrator)));
	AppendLine(TEXT(""));

	AppendLine(TEXT("[Paths]"));
	AppendLine(FString::Printf(TEXT("Desktop=%s"), *Snapshot.SystemPathInfo.DesktopDir));
	AppendLine(FString::Printf(TEXT("Documents=%s"), *Snapshot.SystemPathInfo.DocumentsDir));
	AppendLine(FString::Printf(TEXT("Downloads=%s"), *Snapshot.SystemPathInfo.DownloadsDir));
	AppendLine(FString::Printf(TEXT("ProjectExtras=%s"), *Snapshot.SystemPathInfo.ProjectExtrasDir));
	AppendLine(FString::Printf(TEXT("ProjectSaveGames=%s"), *Snapshot.SystemPathInfo.ProjectSaveGameDir));
	AppendLine(TEXT(""));

	AppendLine(TEXT("[Display]"));
	AppendLine(FString::Printf(TEXT("Primary=%dx%d"), Snapshot.DisplayInfo.PrimaryDisplayWidth, Snapshot.DisplayInfo.PrimaryDisplayHeight));
	AppendLine(FString::Printf(TEXT("MonitorCount=%d"), Snapshot.DisplayInfo.MonitorCount));
	AppendLine(FString::Printf(TEXT("ApplicationScale=%.2f"), Snapshot.DisplayInfo.ApplicationScale));
	AppendLine(TEXT(""));

	AppendLine(TEXT("[Window]"));
	AppendLine(FString::Printf(TEXT("Title=%s"), *Snapshot.MainWindowInfo.Title));
	AppendLine(FString::Printf(TEXT("Handle=%lld"), Snapshot.MainWindowInfo.WindowHandleValue));
	AppendLine(FString::Printf(TEXT("Position=%d,%d"), Snapshot.MainWindowInfo.PositionX, Snapshot.MainWindowInfo.PositionY));
	AppendLine(FString::Printf(TEXT("Size=%d,%d"), Snapshot.MainWindowInfo.SizeX, Snapshot.MainWindowInfo.SizeY));
	AppendLine(FString::Printf(TEXT("Viewport=%d,%d"), Snapshot.MainWindowInfo.ViewportSizeX, Snapshot.MainWindowInfo.ViewportSizeY));
	AppendLine(FString::Printf(TEXT("Visible=%s Foreground=%s Minimized=%s Maximized=%s TopMost=%s CaptureDisabled=%s"),
		*BoolToString(Snapshot.MainWindowInfo.bIsVisible),
		*BoolToString(Snapshot.MainWindowInfo.bIsForeground),
		*BoolToString(Snapshot.MainWindowInfo.bIsMinimized),
		*BoolToString(Snapshot.MainWindowInfo.bIsMaximized),
		*BoolToString(Snapshot.MainWindowInfo.bIsTopMost),
		*BoolToString(Snapshot.MainWindowInfo.bIsScreenCaptureDisabled)));
	AppendLine(TEXT(""));

	AppendLine(TEXT("[Hardware]"));
	AppendLine(FString::Printf(TEXT("CPU=%s | %s | Usage=%.2f%% | Frequency=%.2fMHz"), *Snapshot.CPUInfo.Vendor, *Snapshot.CPUInfo.Brand, Snapshot.CPUInfo.UsagePercent, Snapshot.CPUInfo.FrequencyMHz));
	AppendLine(FString::Printf(TEXT("GPU=%s | %s | Usage=%.2f%%"), *Snapshot.GPUInfo.Brand, *Snapshot.GPUInfo.AdapterName, Snapshot.GPUInfo.UsagePercent));
	AppendLine(FString::Printf(TEXT("Memory Total=%lld Available=%lld ProcessUsed=%lld"), Snapshot.MemoryInfo.TotalPhysicalBytes, Snapshot.MemoryInfo.AvailablePhysicalBytes, Snapshot.MemoryInfo.ProcessUsedPhysicalBytes));
	AppendLine(FString::Printf(TEXT("ProjectDisk Total=%lld Free=%lld"), Snapshot.ProjectDiskInfo.TotalBytes, Snapshot.ProjectDiskInfo.FreeBytes));
	AppendLine(FString::Printf(TEXT("BatteryPercent=%d OnBattery=%s"), Snapshot.PowerInfo.BatteryPercent, *BoolToString(Snapshot.PowerInfo.bIsRunningOnBattery)));
	AppendLine(TEXT(""));

	AppendLine(TEXT("[Network]"));
	AppendLine(FString::Printf(TEXT("Host=%s"), *Snapshot.NetworkInfo.HostName));
	AppendLine(FString::Printf(TEXT("PrimaryIpv4=%s"), *Snapshot.NetworkInfo.PrimaryIpv4));
	AppendLine(FString::Printf(TEXT("AdapterCount=%d"), Snapshot.NetworkInfo.AdapterCount));
	AppendLine(FString::Printf(TEXT("WiFi=%s Ethernet=%s HasNetwork=%s"),
		*BoolToString(Snapshot.NetworkInfo.bHasWiFiConnection),
		*BoolToString(Snapshot.NetworkInfo.bHasEthernetConnection),
		*BoolToString(Snapshot.NetworkInfo.bHasNetwork)));

	return Report;
}
