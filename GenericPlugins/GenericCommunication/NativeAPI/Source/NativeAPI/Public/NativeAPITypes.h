// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "NativeAPITypes.generated.h"

/** 承载一个 `API_` JSON 字段解析出的待执行调用，代理组件会按该任务在 Owner 上查找同名函数并填充参数。 */
struct NATIVEAPI_API FNativeAPITask
{
	/** 确认该任务具备可分发的函数名和参数对象，Payload 解析阶段用它过滤无效调用。 */
	bool IsValid() const { return !FuncName.IsNone() && ParamJson.IsValid(); }

	/** 保存原始 `API_` 字段名，代理组件据此在 Actor Owner 上查找要执行的 UFunction。 */
	FName FuncName;

	/** 保存该任务的 JSON 参数表，ProcessEvent 前会按 UFunction 参数逐项反序列化。 */
	TSharedPtr<FJsonObject> ParamJson;

	bool operator==(const FNativeAPITask& Other) const { return Other.FuncName == FuncName; }
	bool operator!=(const FNativeAPITask& Other) const { return !operator==(Other); }
};

/** 承载一次外部 NativeAPI 消息的路由上下文和任务列表，是会话、引擎子系统、世界子系统与代理组件之间传递的调度单元。 */
USTRUCT()
struct NATIVEAPI_API FNativeAPIPayload
{
	GENERATED_BODY()

public:
	/** 保持默认空载荷状态，解析成功前不会通过 IsValid 检查，也不会被后续路由分发。 */
	FNativeAPIPayload()
	{
	}

	/** 确认载荷至少包含目标实体类型和一个任务，外部会话入口用它判断消息是否具备调度意义。 */
	bool IsValid() const { return EntityClassPath.IsValid() && !TaskList.IsEmpty(); }

	/** 返回请求目标实体类型，子系统用它解析 UClass 并按类型筛选代理组件。 */
	FSoftClassPath GetClassPath() const { return EntityClassPath; }

	/** 返回可选目标世界路径，外部消息指定世界时用于直接定位或校验 EntityPath 归属。 */
	FSoftObjectPath GetWorldPath() const { return WorldPath; }

	/** 返回可选实体子对象路径，存在时引擎子系统会优先尝试精确投递到该对象。 */
	FSoftObjectPath GetEntityPath() const { return EntityObjectPath; }

	/** 返回逻辑实体名，代理组件用它和自身签名比对，避免同类多个实例误接收请求。 */
	FName GetEntity() const { return Entity; }

	/** 拷贝待执行任务列表给代理组件，代理组件会按顺序查找并调用 Owner 上的 API 函数。 */
	void GetTaskList(TArray<FNativeAPITask>& OutList) const { OutList = TaskList; }

	/** 判断 EntityPath 是否为子对象路径，只有子对象路径才能通过 World->ResolveSubobject 精确定位。 */
	bool IsValidEntityPath() const { return EntityObjectPath.IsSubobject(); }

	/** 判断指定实体接口是否匹配载荷中的类和实体名，代理组件执行前用它过滤非目标对象。 */
	bool IsConsumer(TScriptInterface<class INativeAPIEntityInterface> InScript) const;

#if WITH_EDITOR
	/** 修正PIE实例来源路径，避免编辑器多实例下的NativeAPI标识冲突。 */
	void FixupFromPIE(int32 PIEInstance);
#endif

private:
	/** 保存 JSON 中 EntityClass 解析后的软类路径，是解析目标类型和世界广播分桶的依据。 */
	FSoftClassPath EntityClassPath;

	/** 保存 JSON 或 EntityPath 推导出的目标世界路径，用于多世界或 PIE 场景限定分发范围。 */
	FSoftObjectPath WorldPath;

	/** 保存逻辑实体标识；缺省时使用类资产名，保证未显式传入 Entity 的请求仍能匹配默认代理签名。 */
	FName Entity;

	/** 保存 EntityPath 指定的目标子对象路径，存在时引擎子系统会绕过广播并尝试直达目标对象。 */
	FSoftObjectPath EntityObjectPath;

	/** 保存所有通过 `API_` 前缀识别出的函数调用，代理组件会按该列表逐项执行。 */
	TArray<FNativeAPITask> TaskList;

	friend class FNativeAPIUtilities;
};
