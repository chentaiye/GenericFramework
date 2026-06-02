// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Platform.h"
#include "Misc/Timespan.h"
#include "Subsystem/GenericEngineSubsystem.h"
#include "ExtraProcSubsystem.generated.h"

class FExtraProcThread;

/** 管理配置驱动的外部进程启动和销毁，并维护自动启动进程的线程 GUID 列表。 */
UCLASS(MinimalAPI)
class UExtraProcSubsystem : public UGenericEngineSubsystem
{
	GENERATED_BODY()

public:
	static EXTRAPROC_API UExtraProcSubsystem* Get();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
#if WITH_EDITOR
	/** PIE 开始时启动启用了自动启动的外部进程配置项。 */
	void BeginPIE(bool bIsSimulating);

	/** PIE 结束时终止本子系统自动启动过的外部进程。 */
	void EndPIE(bool bIsSimulating);
#endif

public:
	/** 遍历开发者设置中的自动启动列表，启动成功后记录返回的线程 GUID。 */
	void LaunchAllProc();

	/** 根据记录的 GUID 终止自动启动进程，并清空本地跟踪列表。 */
	void DestroyAllProc();

	/** 返回项目 Extras/Proc 目录，初始化时会确保目录存在。 */
	static FString GetExtraProcPath();

private:
	/** 保存由 LaunchAllProc 启动的进程 GUID，DestroyAllProc 用它批量终止。 */
	TArray<FGuid> ProcGuids;
};
