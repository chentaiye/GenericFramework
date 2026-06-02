#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AcquireAndroidPermissionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPermissionsGrantedSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPermissionsGrantedFail, const TArray<FString>&, FailPermissions);

/** 提供获取Android权限异步动作能力。 */
UCLASS(MinimalAPI)
class UAcquireAndroidPermissionAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICANDROIDFRAMEWORK_API virtual void Activate() override;

	/** 处理异步获取Android权限。 */
	UFUNCTION(BlueprintCallable, Category="Android|Permission|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICANDROIDFRAMEWORK_API UAcquireAndroidPermissionAsyncAction* AsyncAcquireAndroidPermission(const FString& InPermission);

	/** 处理异步获取Android Permissions。 */
	UFUNCTION(BlueprintCallable, Category="Android|Permission|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICANDROIDFRAMEWORK_API UAcquireAndroidPermissionAsyncAction* AsyncAcquireAndroidPermissions(const TArray<FString>& InPermissions);

	/** 保存On成功。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnPermissionsGrantedSuccess OnSuccess;

	/** 保存On失败。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnPermissionsGrantedFail OnFail;

private:
	/** 保存Permissions。 */
	TArray<FString> Permissions;
	/** 保存Permissions未Acquired。 */
	TArray<FString> PermissionsNotAcquired;
	/** 保存失败Permissions。 */
	TArray<FString> FailPermissions;

	/** 响应Permissions Granted。 */
	void OnPermissionsGranted(const TArray<FString>& InPermissions, const TArray<bool>& InGrantResults);
};
