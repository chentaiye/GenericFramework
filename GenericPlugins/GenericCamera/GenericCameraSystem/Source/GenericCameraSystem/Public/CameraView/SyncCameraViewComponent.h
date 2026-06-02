// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraType.h"
#include "CameraView/CameraViewSyncPolicy.h"
#include "Components/ActorComponent.h"
#include "GameplayMessageSubsystem.h"
#include "SyncCameraViewComponent.generated.h"

/** 挂载到需要同步视角的 Actor 上，并把相机切换消息转发给指定策略。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class USyncCameraViewComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 创建视角同步组件并启用 Tick，用于驱动策略缓存运行期相机状态。 */
	GENERICCAMERASYSTEM_API USyncCameraViewComponent();
	GENERICCAMERASYSTEM_API virtual void BeginPlay() override;
	GENERICCAMERASYSTEM_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	GENERICCAMERASYSTEM_API virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/** 返回当前创建的视角同步策略实例。 */
	UFUNCTION(BlueprintPure, Category="Sync Camera View Component")
	GENERICCAMERASYSTEM_API UCameraViewSyncPolicy* GetCameraViewSyncPolicy() const;

	UFUNCTION(BlueprintPure, Category="Sync Camera View Component")
	GENERICCAMERASYSTEM_API TArray<UCameraViewSyncPolicy*> GetCameraViewSyncPolicies() const;

protected:
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchBeginMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchResetMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchFinishMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);

private:
	bool HasCameraViewSyncPolicy() const;
	void InitializeCameraViewSyncPolicies();
	void DeinitializeCameraViewSyncPolicies();
	void RegisterCameraSwitchListeners();
	void UnregisterCameraSwitchListeners();

public:
	/** 指定当前组件使用的视角同步策略类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sync Camera View Component")
	TArray<TSubclassOf<UCameraViewSyncPolicy>> CameraViewSyncPolicyClasses;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UCameraViewSyncPolicy>> CameraViewSyncPolicies;

	FGameplayMessageListenerHandle CameraSwitchBeginListenerHandle;
	FGameplayMessageListenerHandle CameraSwitchResetListenerHandle;
	FGameplayMessageListenerHandle CameraSwitchFinishListenerHandle;
};
