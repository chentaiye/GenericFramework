// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ImportLicenseFileAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FImportLicenseFileAsyncActionEvent, EAuthorizationState, State, FString, Message);

/** 封装离线许可证文件导入蓝图异步节点，先可选导入清单，再导入许可证并把基础授权状态返回给蓝图。 */
UCLASS(MinimalAPI)
class UImportLicenseFileAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建许可证文件导入动作，保存许可证与清单路径，激活时由授权子系统读取并持久化离线授权。 */
	UFUNCTION(BlueprintCallable, Category="Authorization", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICAUTHORIZATION_API UImportLicenseFileAsyncAction* ImportLicenseFile(UObject* WorldContextObject, const FString& LicenseTokenFilePath, const FString& ManifestFilePath);

	GENERICAUTHORIZATION_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FImportLicenseFileAsyncActionEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FImportLicenseFileAsyncActionEvent OnError;

private:
	/** 保存创建节点时传入的世界上下文，激活时用它查找当前授权子系统。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;

	/** 保存许可证令牌文件路径，激活时读取文本并走离线许可证导入流程。 */
	FString LicenseTokenFilePath;

	/** 保存可选清单文件路径，非空时先导入清单以更新 Pak 与 Scope 映射。 */
	FString ManifestFilePath;
};
