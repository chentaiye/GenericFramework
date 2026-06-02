// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SwitchToCameraAsyncAction.generated.h"

class AActor;
class ACameraActor;
class ACameraPointBase;
class APlayerController;
class UCameraComponent;
class UGenericCameraSwitchMethod;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCameraHandleFinish);

/** 标记异步节点激活后要转发到相机子系统的具体切换入口。 */
enum class ESwitchToCameraAsyncActionType : uint8
{
	/** 未配置有效操作，激活后会直接完成节点。 */
	None,

	/** 围绕目标 Actor 生成临时相机点并切换。 */
	FocusToActor,

	/** 按世界位置和旋转生成临时相机点并切换。 */
	SwitchToTransform,

	/** 使用 CameraActor 的相机组件生成临时相机点并切换。 */
	SwitchToActor,

	/** 使用外部 CameraComponent 生成匹配类型的临时相机点并切换。 */
	SwitchToComponent,

	/** 按相机标签查找已注册 CameraPoint 并切换。 */
	SwitchToTag,

	/** 直接切换到传入的 CameraPoint。 */
	SwitchToCameraPoint,

	/** 重新切回当前记录的 CameraPoint。 */
	SwitchToCurrent,

	/** 切回上一次记录的 CameraPoint。 */
	SwitchToPrevious,

	/** 切回当前玩家配置的根 CameraPoint。 */
	SwitchToRoot,
};

/** 把相机子系统的一次切换包装成蓝图异步节点，切换重置或完成后统一广播 OnFinish。 */
UCLASS(MinimalAPI)
class USwitchToCameraAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICCAMERASYSTEM_API virtual void Activate() override;

public:
	/** 创建按类配置的聚焦 Actor 节点，激活后会在 Actor 前方生成临时相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncFocusToActor(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* FocusToActor_HandleClass(APlayerController* Player, AActor* InActor, float FocusLens, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的聚焦 Actor 节点，适合传入已设置参数的切换方法对象。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncFocusToActor", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* FocusToActor_Handle(APlayerController* Player, AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的变换切换节点，运行时会用位置和旋转生成一次性相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByTransform(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Transform_HandleClass(APlayerController* Player, FVector Location, FRotator Rotation, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的变换切换节点，切换方法会随节点生命周期被相机子系统调用。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByTransform", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Transform_Handle(APlayerController* Player, FVector Location, FRotator Rotation, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的 CameraActor 切换节点，实际切换会复制 Actor 上的 CameraComponent 参数。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByActor(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Actor_HandleClass(APlayerController* Player, ACameraActor* InCameraActor, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的 CameraActor 切换节点，保留外部切换方法对象上的编辑参数。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByActor", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Actor_Handle(APlayerController* Player, ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的 CameraComponent 切换节点，会按普通相机或 Cine 相机生成匹配的临时点。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByComponent(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Component_HandleClass(APlayerController* Player, UCameraComponent* InCameraComponent, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的 CameraComponent 切换节点，适合蓝图临时传入自定义过渡参数。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByComponent", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Component_Handle(APlayerController* Player, UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的标签切换节点，标签必须已被当前玩家的相机子系统索引。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByTag(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true", GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Tag_HandleClass(APlayerController* Player, FGameplayTag InCameraTag, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的标签切换节点，常用于把世界设置或蓝图中的方法对象直接用于指定标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByTag", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true", GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_Tag_Handle(APlayerController* Player, FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的 CameraPoint 切换节点，直接使用传入相机点而不再做标签查找。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByCameraPoint(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_CameraPoint_HandleClass(APlayerController* Player, ACameraPointBase* InCameraPoint, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的 CameraPoint 切换节点，用于运行时已拿到目标相机点的蓝图流程。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCameraByCameraPoint", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCamera_CameraPoint_Handle(APlayerController* Player, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的切回当前镜头节点，当前标签无效时会直接结束异步节点。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCurrentCamera(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCurrent_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的切回当前镜头节点，复用相机子系统记录的 CurrentCameraTag。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToCurrentCamera", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToCurrent_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的切回上一镜头节点，上一标签无效时会直接结束异步节点。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToPreviousCamera(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToPrevious_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的切回上一镜头节点，适合返回上一个业务镜头时传入自定义过渡。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToPreviousCamera", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToPrevious_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 创建按类配置的切回根镜头节点，根标签由当前玩家相机子系统维护。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToRootCamera(Class)", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToRoot_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass);

	/** 创建按实例配置的切回根镜头节点，常用于从临时镜头恢复到默认视角。 */
	UFUNCTION(BlueprintCallable, DisplayName="AsyncSwitchToRootCamera", Category="Switch To Camera|Async Action", meta=(BlueprintInternalUseOnly="true"))
	static GENERICCAMERASYSTEM_API USwitchToCameraAsyncAction* SwitchToRoot_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCameraHandleFinish OnFinish;

protected:
	/** 作为相机子系统完成回调的桥接点，广播蓝图完成事件并释放异步节点。 */
	GENERICCAMERASYSTEM_API virtual void OnHandleFinish();

private:
	/** 创建节点并把它注册到玩家 GameInstance，保证潜在异步过渡期间对象不会被回收。 */
	static USwitchToCameraAsyncAction* CreateAction(APlayerController* Player);

	/** 缓存拥有本次切换的玩家，Activate 时据此取得 LocalPlayer 相机子系统。 */
	UPROPERTY()
	TObjectPtr<APlayerController> CachedPlayer = nullptr;

	/** 缓存 FocusToActor 的目标 Actor。 */
	UPROPERTY()
	TObjectPtr<AActor> CachedActor = nullptr;

	/** 缓存按 CameraActor 切换时的源对象。 */
	UPROPERTY()
	TObjectPtr<ACameraActor> CachedCameraActor = nullptr;

	/** 缓存按 CameraComponent 切换时的源组件。 */
	UPROPERTY()
	TObjectPtr<UCameraComponent> CachedCameraComponent = nullptr;

	/** 缓存直接切换时的目标 CameraPoint。 */
	UPROPERTY()
	TObjectPtr<ACameraPointBase> CachedCameraPoint = nullptr;

	/** 缓存按对象实例配置的切换方法。 */
	UPROPERTY()
	TObjectPtr<UGenericCameraSwitchMethod> CachedCameraSwitchMethod = nullptr;

	/** 缓存按类配置的切换方法类型，Activate 时由相机子系统创建运行时实例。 */
	UPROPERTY()
	TSubclassOf<UGenericCameraSwitchMethod> CachedCameraSwitchMethodClass = nullptr;

	/** 记录节点激活时要执行的相机子系统入口。 */
	ESwitchToCameraAsyncActionType ActionType = ESwitchToCameraAsyncActionType::None;

	/** 缓存按 Transform 切换时的目标世界位置。 */
	FVector CachedLocation = FVector::ZeroVector;

	/** 缓存按 Transform 切换时的目标世界旋转。 */
	FRotator CachedRotation = FRotator::ZeroRotator;

	/** 缓存按标签切换、切回当前或切回历史镜头时需要的目标标签。 */
	FGameplayTag CachedCameraTag;

	/** 缓存 FocusToActor 时相机与目标 Actor 的距离。 */
	float CachedFocusLens = 0.f;

	/** 标记 Activate 时应从类创建方法，还是直接使用缓存的方法实例。 */
	bool bUseMethodClass = false;
};
