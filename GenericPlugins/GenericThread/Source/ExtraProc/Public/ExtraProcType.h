// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtraProcType.generated.h"

EXTRAPROC_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogExtraProc, Log, All);

/** 描述一次外部进程启动所需的文件、参数和运行方式，配置与蓝图启动流程都使用它。 */
USTRUCT(BlueprintType)
struct EXTRAPROC_API FProcStartUpInfo
{
	GENERATED_BODY()

public:
	/** 初始化为空启动配置，默认不后台运行也不创建输出管道。 */
	FProcStartUpInfo()
		: bRunInBackground(false),
		  bCreatePipe(false)
	{
	}

	/** 用文件路径和参数映射快速构造启动信息，静态启动函数会把参数映射拼成命令行。 */
	FProcStartUpInfo(const FString& InFilePath, const TMap<FString, FString>& InParams, bool bIsRunInBackground, bool bIsCreatePipe)
		: StartParams(InParams),
		  bRunInBackground(bIsRunInBackground),
		  bCreatePipe(bIsCreatePipe)
	{
		ProcFile.FilePath = InFilePath;
	}

	/** 要启动的项目内 Extras 相对文件路径，LaunchExtraProc 会拼接 ProjectDir 并校验目录。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(RelativeToGameDir, FilePathFilter= "Proc Files (*.exe, *.bat)|*.exe;*.bat;"), Category="ExtraProc")
	FFilePath ProcFile;

	/** 启动参数键值表，静态函数会转换为 -Key 或 -Key=Value 命令行片段。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="ExtraProc")
	TMap<FString, FString> StartParams;

	/** 控制 CreateProc 的后台或隐藏运行参数，影响进程窗口和焦点行为。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="ExtraProc")
	bool bRunInBackground;

	/** 控制是否为进程创建输出管道，开启后线程会缓存标准输出。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="ExtraProc")
	bool bCreatePipe;
};

/** 配置一个可在子系统初始化或 PIE 开始时自动启动的外部进程条目。 */
USTRUCT(BlueprintType)
struct EXTRAPROC_API FProcAutoStartUpInfo
{
	GENERATED_BODY()

	/** 初始化为不自动启动，避免配置项创建后立即参与 LaunchAllProc。 */
	FProcAutoStartUpInfo()
		: bAutoLaunch(false)
	{
	}

public:
	/** 决定 LaunchAllProc 是否跳过此配置项。 */
	UPROPERTY(Config, EditAnywhere, Category="ExtraProc")
	bool bAutoLaunch;

	/** 自动启动时传入静态启动函数的进程文件、参数和管道配置。 */
	UPROPERTY(Config, EditAnywhere, Category="ExtraProc")
	FProcStartUpInfo ExtraStartProcInfo;
};
