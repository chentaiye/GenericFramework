// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineSessionDelegates.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SessionAsyncActionBase.generated.h"

/** 为所有会话蓝图异步节点保存 WorldContext 并提供 OnlineSession 访问入口，派生节点只负责具体请求和完成广播。 */
UCLASS(MinimalAPI, Abstract)
class USessionAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	/** 基于保存的 WorldContext 取得当前世界的 OnlineSession 接口，供派生节点绑定和清理异步回调。 */
	GENERICNETWORKFRAMEWORK_API IOnlineSessionPtr GetOnlineSessionPtr();

protected:
	/** 保存蓝图调用时传入的上下文对象，延迟到 Activate 和回调阶段解析世界与会话接口。 */
	UPROPERTY()
	UObject* WorldContextObject=nullptr;
};
