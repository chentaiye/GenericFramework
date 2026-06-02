// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ActivateAuthorizationAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActivateAuthorizationAsyncActionEvent, EAuthorizationState, State, FString, Message);

/** 封装授权激活蓝图异步节点，支持 Provider 激活码和本地令牌文本两条路径，并把基础授权状态广播回蓝图。 */
UCLASS(MinimalAPI)
class UActivateAuthorizationAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建 Provider 激活动作，保存授权码、用户和请求 Scope，激活时向授权服务换取许可证/清单。 */
	UFUNCTION(BlueprintCallable, Category="Authorization", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API UActivateAuthorizationAsyncAction* ActivateAuthorization(UObject* WorldContextObject, FName ProviderName, const FString& AuthorizationCode, const FString& UserId, FName RequestedScopeId);

	/** 创建本地令牌导入动作，激活时先可选导入清单再导入许可证文本，用于离线授权码粘贴场景。 */
	UFUNCTION(BlueprintCallable, Category="Authorization", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API UActivateAuthorizationAsyncAction* ActivateAuthorizationByTokenText(UObject* WorldContextObject, const FString& LicenseTokenText, const FString& ManifestText);

	GENERICAUTHORIZATION_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FActivateAuthorizationAsyncActionEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FActivateAuthorizationAsyncActionEvent OnError;

private:
	/** 保存创建节点时传入的世界上下文，激活时用它定位当前授权子系统。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;

	/** 指定激活用 Provider；为空时子系统按首选在线/离线 Provider 自动解析。 */
	FName ProviderName = NAME_None;

	/** 保存请求激活的 Scope，Provider 激活请求会把它传给授权服务生成对应 Grant。 */
	FName RequestedScopeId = NAME_None;

	/** 保存用户输入或业务传入的激活码，Provider 激活路径会用它换取许可证令牌。 */
	FString AuthorizationCode;

	/** 保存可选用户标识，Provider 激活请求会携带它用于服务端绑定或审计。 */
	FString UserId;

	/** 保存离线许可证文本，本地令牌路径激活时直接交给子系统解析和持久化。 */
	FString LicenseTokenText;

	/** 保存可选清单文本，本地令牌路径会先导入它以更新内容授权范围。 */
	FString ManifestText;

	/** 区分 Provider 激活和令牌文本导入两条执行路径，Activate 根据该标记选择子系统 API。 */
	bool bImportByTokenText = false;
};
