// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "GenericCameraSwitchMethod.generated.h"

class APlayerController;
class ACameraPointBase;

/** 定义相机切换方法的运行时基类，负责保存目标玩家、目标相机点和完成回调。 */
UCLASS(Abstract, EditInlineNew, MinimalAPI)
class UGenericCameraSwitchMethod : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 蓝图扩展入口，由具体切换方法把玩家视角切换到目标相机点。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Camera Switch Method")
	GENERICCAMERASYSTEM_API bool HandleSwitchToCameraPoint(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint);

	/** 进入切换生命周期，缓存上下文、广播开始事件，并调用蓝图或派生类实现。 */
	GENERICCAMERASYSTEM_API virtual bool NativeHandleSwitchToCameraPoint(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint, FSimpleDelegate OnFinish = FSimpleDelegate());

	/** 蓝图重置回调，在新的切换打断当前切换时清理派生方法持有的临时状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Camera Switch Method")
	GENERICCAMERASYSTEM_API void OnSwitchToCameraPointReset();

	/** 执行重置收尾，广播重置事件、触发完成回调，并释放临时相机点。 */
	GENERICCAMERASYSTEM_API virtual void NativeOnSwitchToCameraPointReset();

	/** 蓝图完成回调，在切换自然结束时收尾派生方法持有的临时状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Camera Switch Method")
	GENERICCAMERASYSTEM_API void OnSwitchToCameraPointFinish();

	/** 执行完成收尾，广播完成事件、触发调用方回调，并释放临时相机点。 */
	GENERICCAMERASYSTEM_API virtual void NativeOnSwitchToCameraPointFinish();

	/** 返回切换方法预计持续的时间，用于蓝图或外部系统同步过渡节奏。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Generic Camera Switch Method")
	GENERICCAMERASYSTEM_API float GetSwitchDuration();

public:
	/** 缓存本次切换所属的玩家控制器，重置或完成后会被清空。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Camera Switch Method")
	TObjectPtr<APlayerController> OwnerPlayerController = nullptr;

	/** 缓存本次切换目标相机点，临时相机点会在收尾阶段自动销毁。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Camera Switch Method")
	TObjectPtr<ACameraPointBase> TargetCameraPoint = nullptr;

protected:
	/** 保存调用方传入的完成回调，确保重置和正常完成走同一套收尾路径。 */
	FSimpleDelegate OnHandleFinish;
};
