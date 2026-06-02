// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Authorization.generated.h"

class UGenericAuthorizationSubsystem;

/** 提供授权蓝图便捷入口，把世界上下文解析为授权子系统并暴露常用查询与 Pak 挂载检查。 */
UCLASS(MinimalAPI)
class UBPFunctions_Authorization : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 从世界上下文解析当前 GameInstance 的授权子系统，蓝图可用它调用完整授权 API。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API UGenericAuthorizationSubsystem* GetAuthorizationSubsystem(const UObject* WorldContextObject);

	/** 查询基础 Scope 是否已授权，供蓝图在进入主流程或显示功能入口前做快速门禁。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API bool IsBaseAppAuthorized(const UObject* WorldContextObject);

	/** 查询指定 Scope 是否已授权，蓝图可按功能模块或 DLC Scope 控制访问。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API bool IsScopeAuthorized(const UObject* WorldContextObject, FName ScopeId);

	/** 返回指定 Scope 的详细状态，让蓝图区分缺失、过期、撤销和全局校验失败。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API EAuthorizationState GetScopeState(const UObject* WorldContextObject, FName ScopeId);

	/** 读取当前设备 ID，便于蓝图展示或提交给外部签发工具生成离线许可证。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API FString GetCurrentAuthorizationDeviceId(const UObject* WorldContextObject);

	/** 读取当前申请码，蓝图可把它显示给用户复制到授权签发流程。 */
	UFUNCTION(BlueprintPure, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API FString GetCurrentAuthorizationRequestCode(const UObject* WorldContextObject);

	/** 根据当前清单匹配 Pak 路径并返回 Scope 与授权状态，供蓝图在挂载前阻止未授权内容包。 */
	UFUNCTION(BlueprintCallable, Category="Authorization", meta=(WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API bool CanMountPakFile(const UObject* WorldContextObject, const FString& PakFilePath, FName& OutScopeId, EAuthorizationState& OutState);
};
