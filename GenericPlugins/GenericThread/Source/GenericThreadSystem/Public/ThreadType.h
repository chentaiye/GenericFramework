// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThreadType.generated.h"

class FGenericThread;

GENERICTHREADSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogThread, Log, All);

/** 描述线程任务在调度子系统中的生命周期状态，用于区分实时运行、正常完成和被终止后的结果缓存。 */
UENUM(BlueprintType)
enum class EThreadExecutionState : uint8
{
	/** 默认无效状态，表示句柄未解析到活动线程或缓存结果。 */
	Invalid,

	/** 线程仍在子系统活动映射中，查询时会从当前线程对象实时构建结果。 */
	Running,

	/** 线程自然结束，子系统已缓存最终输出、耗时和可选退出码。 */
	Completed,

	/** 线程被取消或清理流程终止，子系统按终止状态缓存最后一次快照。 */
	Terminated
};

/** 在线程系统和蓝图之间传递线程身份的轻量句柄，封装注册到子系统的 GUID。 */
USTRUCT(BlueprintType)
struct GENERICTHREADSYSTEM_API FThreadHandle
{
	GENERATED_BODY()

public:
	/** 创建空句柄，供蓝图输出参数初始化或失败路径复位。 */
	FThreadHandle();

	/** 用已注册线程的 GUID 构造句柄，供调用方后续查询结果或终止实例。 */
	FThreadHandle(FGuid InThreadGuid);

	bool operator==(const FThreadHandle& Other) const { return Other.ThreadGuid == ThreadGuid; }
	bool operator==(const FGuid Other) const { return Other == ThreadGuid; }
	bool operator!=(const FThreadHandle& Other) const { return !(*this == Other); }
	bool operator!=(const FGuid Other) const { return !(*this == Other); }

	/** 返回内部 GUID，供子系统和静态函数按键查找线程实例或结果缓存。 */
	FGuid GetThreadGuid() const { return ThreadGuid; }

	/** 检查 GUID 是否可用于向线程子系统发起查询。 */
	bool IsValid() const { return ThreadGuid.IsValid(); }

private:
	/** 线程注册表使用的唯一键，完成或终止后仍用于读取缓存结果。 */
	FGuid ThreadGuid;
};

/** 线程查询接口返回的快照，统一承载运行状态、耗时、输出和退出码。 */
USTRUCT(BlueprintType)
struct GENERICTHREADSYSTEM_API FThreadExecutionResult
{
	GENERATED_BODY()

public:
	/** 初始化为无效结果，确保查询失败时蓝图拿到可判定的默认值。 */
	FThreadExecutionResult();

	/** 结果对应的线程句柄，用于调用方继续关联后续查询。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	FThreadHandle ThreadHandle;

	/** 子系统填充的生命周期状态，区分实时运行结果和已缓存终态。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	EThreadExecutionState State;

	/** 线程创建时使用的名称，帮助日志或蓝图区分结果来源。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	FString ThreadName;

	/** 从启动到当前或结束的耗时，由运行状态决定实时计算或读取结束时间。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	FTimespan Duration;

	/** 管道或线程逻辑累积的输出缓存，完成或终止后随结果保留。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	FString Output;

	/** 标记 ExitCode 是否来自具体线程实现，普通线程默认没有退出码。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	bool bHasExitCode;

	/** 外部进程等实现返回的退出码，仅在 bHasExitCode 为 true 时有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Thread")
	int32 ExitCode;
};
