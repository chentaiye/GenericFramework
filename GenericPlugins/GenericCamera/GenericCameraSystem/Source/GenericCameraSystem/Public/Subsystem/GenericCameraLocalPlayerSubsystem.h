// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraType.h"
#include "GameplayMessageSubsystem.h"
#include "GameplayTagContainer.h"
#include "CameraPoint/CameraPointBase.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "GenericCameraLocalPlayerSubsystem.generated.h"

class UCameraComponent;
class UGenericCameraSwitchMethod;
class ACameraPointBase;
class APlayerController;
class ULocalPlayer;

UCLASS(MinimalAPI)
class UGenericCameraLocalPlayerSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	static GENERICCAMERASYSTEM_API UGenericCameraLocalPlayerSubsystem* Get(const UObject* WorldContextObject);
	static GENERICCAMERASYSTEM_API UGenericCameraLocalPlayerSubsystem* Get(const APlayerController* PlayerController);
	static GENERICCAMERASYSTEM_API UGenericCameraLocalPlayerSubsystem* Get(const ULocalPlayer* LocalPlayer);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	virtual void HandleSwitchToCameraFinish(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage);

public:
	/** 读取当前本地玩家回到默认视角时使用的根相机标签。 */
	GENERICCAMERASYSTEM_API FGameplayTag GetRootCameraTag() const;

	/** 写入当前本地玩家回退到根视角时使用的相机标签，不会立刻触发切换。 */
	GENERICCAMERASYSTEM_API void SetRootCameraTag(FGameplayTag InCameraTag);

	/** 围绕目标 Actor 生成临时相机点，并使用指定方法类切到该聚焦视角。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* FocusToActor(AActor* InActor, float FocusLens, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 围绕目标 Actor 生成临时相机点，并使用传入方法实例切到该聚焦视角。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* FocusToActor(AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按世界变换生成一次性相机点，并使用指定方法类开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const FVector& Location, const FRotator& Rotation, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按世界变换生成一次性相机点，并使用传入方法实例开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const FVector& Location, const FRotator& Rotation, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按结构体参数生成一次性相机点，并根据方法选择模式创建或复制切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const FSwitchToCameraByTransform& InSwitchToCameraByTransform, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 从 CameraActor 的组件创建临时相机点，并使用指定方法类开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const ACameraActor* InCameraActor, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 从 CameraActor 的组件创建临时相机点，并使用传入方法实例开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 从普通或 Cine CameraComponent 创建匹配的临时相机点，并使用指定方法类开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(UCameraComponent* InCameraComponent, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 从普通或 Cine CameraComponent 创建匹配的临时相机点，并使用传入方法实例开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按标签查找当前玩家已注册的相机点，并使用指定方法类开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(FGameplayTag InCameraTag, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按标签查找当前玩家已注册的相机点，并使用传入方法实例开始切换。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 按结构体标签参数查找相机点，并根据方法选择模式创建或复制切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(const FSwitchToCameraByTag& InSwitchToCameraByTag, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 直接切换到传入相机点，并使用指定方法类创建运行时切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(ACameraPointBase* InCameraPoint, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 直接切换到传入相机点，负责打断旧切换、更新历史标签并广播开始消息。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCamera(ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用指定方法类切回当前标签指向的相机点，当前标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCurrent(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用传入方法实例切回当前标签指向的相机点，当前标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCurrent(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用参数结构体切回当前标签，并根据方法选择模式创建或复制切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToCurrent(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用指定方法类切回上一标签指向的相机点，上一标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToPrevious(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用传入方法实例切回上一标签指向的相机点，上一标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToPrevious(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用参数结构体切回上一标签，并根据方法选择模式创建或复制切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToPrevious(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用指定方法类切回根标签指向的相机点，根标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToRoot(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用传入方法实例切回根标签指向的相机点，根标签无效时只执行完成回调。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToRoot(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish = FSimpleDelegate());

	/** 使用参数结构体切回根标签，并根据方法选择模式创建或复制切换方法。 */
	GENERICCAMERASYSTEM_API UGenericCameraSwitchMethod* SwitchToRoot(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish = FSimpleDelegate());

private:
	/** 判断当前玩家是否已有未收尾的切换方法，便于新切换开始前重置旧过渡。 */
	bool IsSwitching() const;

	/** 读取当前玩家正在执行的切换方法；同一子系统只允许一个玩家上下文生效。 */
	UGenericCameraSwitchMethod* GetCameraSwitchMethod() const;

	/** 推进当前标签和上一标签记录，为 SwitchToCurrent 与 SwitchToPrevious 提供历史。 */
	void UpdateCameraTag(FGameplayTag InCameraTag);

protected:
	/** 当前仍在运行的切换方法实例，完成或重置后由 HandleSwitchToCameraFinish 移除。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Generic Camera Subsystem")
	TArray<UGenericCameraSwitchMethod*> CurrentCameraMethods;

	/** 当前玩家默认返回视角的标签，通常由世界设置或业务初始化流程写入。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Generic Camera Subsystem", meta=(Categories="GameplayCamera"))
	FGameplayTag RootCameraTag;

	/** 最近一次成功发起标签切换的目标标签，用于重新切回当前镜头。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Generic Camera Subsystem", meta=(Categories="GameplayCamera"))
	FGameplayTag CurrentCameraTag;

	/** 当前标签被更新前的历史标签，用于返回上一镜头。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Generic Camera Subsystem", meta=(Categories="GameplayCamera"))
	FGameplayTag PreviousCameraTag;

	FGameplayMessageListenerHandle HandleCameraSwitchResetListenerHandle;
	FGameplayMessageListenerHandle HandleCameraSwitchFinishListenerHandle;
};
