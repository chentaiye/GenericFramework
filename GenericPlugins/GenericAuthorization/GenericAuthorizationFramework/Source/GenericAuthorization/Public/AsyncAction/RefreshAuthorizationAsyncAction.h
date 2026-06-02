// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "RefreshAuthorizationAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRefreshAuthorizationAsyncActionEvent, EAuthorizationState, State, FString, Message);

/** 封装刷新授权蓝图异步节点，把 Provider 刷新流程转成成功/失败事件，便于蓝图在授权续期后继续业务逻辑。 */
UCLASS(MinimalAPI)
class URefreshAuthorizationAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建刷新授权异步动作，保存世界上下文和 Provider 名称，激活时交给授权子系统执行刷新。 */
	UFUNCTION(BlueprintCallable, Category="Authorization", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API URefreshAuthorizationAsyncAction* RefreshAuthorization(UObject* WorldContextObject, FName ProviderName);

	GENERICAUTHORIZATION_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FRefreshAuthorizationAsyncActionEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FRefreshAuthorizationAsyncActionEvent OnError;

private:
	/** 保存创建节点时传入的世界上下文，激活时用它定位当前 GameInstance 授权子系统。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;

	/** 指定刷新用的授权 Provider；为空时由子系统按配置和可用 Feature 自动解析。 */
	FName ProviderName = NAME_None;
};
