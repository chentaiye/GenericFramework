// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraType.h"
#include "UObject/Object.h"
#include "CameraViewSyncPolicy.generated.h"

class USpringArmComponent;
class USyncCameraViewComponent;

/** 定义相机视角同步策略基类，负责响应 SyncCameraViewComponent 转发的相机切换事件。 */
UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class UCameraViewSyncPolicy : public UObject
{
	GENERATED_BODY()

public:
	/** 绑定视角同步组件，策略的运行期状态应在这里初始化。 */
	GENERICCAMERASYSTEM_API virtual void InitializeCameraViewSyncPolicy(USyncCameraViewComponent* InOwnerComponent);

	/** 解绑视角同步组件，策略的监听和缓存应在这里清理。 */
	GENERICCAMERASYSTEM_API virtual void DeinitializeCameraViewSyncPolicy();

	/** 由视角同步组件驱动的逐帧更新入口，默认不执行逻辑。 */
	GENERICCAMERASYSTEM_API virtual void TickCameraViewSyncPolicy(float DeltaSeconds);

	/* Camera Switch Message */
public:
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchBeginMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchResetMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchFinishMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);

protected:
	/** 返回持有当前策略的同步组件。 */
	GENERICCAMERASYSTEM_API USyncCameraViewComponent* GetOwnerSyncCameraViewComponent() const;

	/** 返回同步组件所属 Actor，供派生策略查询具体 Pawn/Controller。 */
	GENERICCAMERASYSTEM_API AActor* GetOwnerActor() const;

	GENERICCAMERASYSTEM_API void SetSpringArmTargetArmLength(USpringArmComponent* InSpringArmComponent, float InTargetArmLength) const;
	GENERICCAMERASYSTEM_API void ResetSpringArmLagState(USpringArmComponent* InSpringArmComponent) const;

private:
	TWeakObjectPtr<USyncCameraViewComponent> OwnerComponent;
};
