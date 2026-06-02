// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Camera.generated.h"

class ACameraActor;
class ACameraPointBase;
class APlayerController;
class UCameraComponent;
class UGenericCameraSwitchMethod;

/** 暴露以玩家控制器为入口的相机蓝图工具函数，内部统一转发到该玩家的 LocalPlayer 相机子系统。 */
UCLASS(MinimalAPI)
class UBPFunctions_Camera : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 从指定玩家的相机索引中按标签读取 CameraPoint，找不到子系统或标签无效时返回空。 */
	UFUNCTION(BlueprintPure, Category="Camera", meta=(GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API ACameraPointBase* GetCameraPoint(APlayerController* Player, FGameplayTag InCameraTag);

	/** 检查指定玩家是否已经注册可切换的目标标签。 */
	UFUNCTION(BlueprintPure, Category="Camera", meta=(GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API bool CanSwitchToCamera(APlayerController* Player, FGameplayTag InCameraTag);

	/** 刷新指定玩家所在世界里已索引 CameraPoint 的焦点距离。 */
	UFUNCTION(BlueprintCallable, Category="Camera")
	static GENERICCAMERASYSTEM_API void RefreshAllCameraPoints(APlayerController* Player);

	/** 读取指定玩家回到根视角时使用的相机标签。 */
	UFUNCTION(BlueprintPure, Category="Camera")
	static GENERICCAMERASYSTEM_API FGameplayTag GetRootCameraTag(APlayerController* Player);

	/** 写入指定玩家回到根视角时使用的相机标签，不会主动触发镜头切换。 */
	UFUNCTION(BlueprintCallable, Category="Camera")
	static GENERICCAMERASYSTEM_API void SetRootCameraTag(APlayerController* Player, FGameplayTag InCameraTag);

	/** 使用方法类围绕目标 Actor 生成临时相机点，适合蓝图快速聚焦一个场景对象。 */
	UFUNCTION(BlueprintCallable, DisplayName="FocusToActor(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void FocusToActor_HandleClass(APlayerController* Player, AActor* InActor, float FocusLens, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例围绕目标 Actor 生成临时相机点，保留实例上的过渡参数。 */
	UFUNCTION(BlueprintCallable, DisplayName="FocusToActor", Category="Camera")
	static GENERICCAMERASYSTEM_API void FocusToActor_Handle(APlayerController* Player, AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类按世界位置和旋转切换到一次性相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByTransform(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Transform_HandleClass(APlayerController* Player, FVector Location, FRotator Rotation, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例按世界位置和旋转切换到一次性相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByTransform", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Transform_Handle(APlayerController* Player, FVector Location, FRotator Rotation, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类复制 CameraActor 的组件参数并切换到临时相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByActor(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Actor_HandleClass(APlayerController* Player, ACameraActor* InCameraActor, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例复制 CameraActor 的组件参数并切换到临时相机点。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByActor", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Actor_Handle(APlayerController* Player, ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类从 CameraComponent 创建普通或 Cine 临时相机点并切换。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByComponent(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Component_HandleClass(APlayerController* Player, UCameraComponent* InCameraComponent, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例从 CameraComponent 创建普通或 Cine 临时相机点并切换。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByComponent", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Component_Handle(APlayerController* Player, UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类按已注册标签切换，标签查找限定在指定玩家的相机子系统内。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByTag(Class)", Category="Camera", meta=(GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Tag_HandleClass(APlayerController* Player, FGameplayTag InCameraTag, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例按已注册标签切换，适合业务蓝图传入带参数的过渡对象。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByTag", Category="Camera", meta=(GameplayTagFilter="GameplayCamera"))
	static GENERICCAMERASYSTEM_API void SwitchToCamera_Tag_Handle(APlayerController* Player, FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类直接切换到传入 CameraPoint，绕过标签索引查找。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByCameraPoint(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_CameraPoint_HandleClass(APlayerController* Player, ACameraPointBase* InCameraPoint, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例直接切换到传入 CameraPoint，绕过标签索引查找。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCameraByCameraPoint", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCamera_CameraPoint_Handle(APlayerController* Player, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类重新切回当前记录的相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCurrentCamera(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCurrent_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例重新切回当前记录的相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToCurrentCamera", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToCurrent_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类切回上一次记录的相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToPreviousCamera(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToPrevious_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例切回上一次记录的相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToPreviousCamera", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToPrevious_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);

	/** 使用方法类切回指定玩家的根相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToRootCamera(Class)", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToRoot_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass);

	/** 使用方法实例切回指定玩家的根相机标签。 */
	UFUNCTION(BlueprintCallable, DisplayName="SwitchToRootCamera", Category="Camera")
	static GENERICCAMERASYSTEM_API void SwitchToRoot_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod);
};
