// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NativeAPIInterface.generated.h"

class FJsonObject;
struct FNativeAPIPayload;

/** 让接收 NativeAPI Payload 的 UObject 拥有接口外壳，使子系统和组件可以统一判定处理能力。 */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UNativeAPIInterface : public UInterface
{
	GENERATED_BODY()
};

/** 约束 NativeAPI 消息处理的 C++ 入口，负责把 JSON 模拟入口与已解析 Payload 的分发入口串起来。 */
class NATIVEAPI_API INativeAPIInterface
{
	GENERATED_BODY()

public:
	/** 接收已验证的 Payload；子系统实现会继续路由，代理组件实现会转换为 Owner 上的函数调用。 */
	virtual void ProcessingNativeAPI(const FNativeAPIPayload& Payload) const
	{
	}

	/** 解析调试传入的 JSON 字符串，并在通过 NativeAPI 格式校验后复用真实会话的 Payload 链路。 */
	void SendSimulationNativeAPIMessage(const FString& InMessage) const;

	/** 将已反序列化的 JSON 转换为 Payload 并调用 ProcessingNativeAPI，供引擎子系统和测试复用。 */
	virtual void SendSimulationNativeAPIMessage_Internal(const TSharedPtr<FJsonObject>& InJsonObject) const;
};

/** 让可被 NativeAPI 定位和调用的 UObject 拥有接口外壳，供直达投递和代理注册流程做类型判断。 */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UNativeAPIEntityInterface : public UNativeAPIInterface
{
	GENERATED_BODY()
};

/** 在基础处理接口上补充实体名、实体类和对象路径，让 Payload 能在多实例场景中匹配目标。 */
class NATIVEAPI_API INativeAPIEntityInterface : public INativeAPIInterface
{
	GENERATED_BODY()

public:
	/** 返回逻辑实体名；具体实现用它与 Payload 的 Entity 字段匹配目标实例。 */
	virtual FString GetEntity() const;

	/** 返回实体类型，Payload 路由和世界子系统分桶都会用它匹配 EntityClass。 */
	virtual UClass* GetEntityClass() const;

	/** 返回可精确投递的对象路径，编辑器示例 JSON 和 EntityPath 解析都依赖该路径定位实例。 */
	FString GetEntityPath() const;
};
