// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraSwitch/GenericCameraSwitchMethod_Transition.h"

#include "CameraPoint/CameraPointBase.h"

UGenericCameraSwitchMethod_Transition::UGenericCameraSwitchMethod_Transition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ViewTargetTransitionParams.BlendTime = 1.f;
	ViewTargetTransitionParams.BlendFunction = VTBlend_Cubic;
	ViewTargetTransitionParams.BlendExp = 0.f;
	ViewTargetTransitionParams.bLockOutgoing = false;
}

bool UGenericCameraSwitchMethod_Transition::HandleSwitchToCameraPoint_Implementation(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint)
{
	if (Super::HandleSwitchToCameraPoint_Implementation(InPlayerController, InCameraPoint))
	{
		if (!IsValid(OwnerPlayerController) || !IsValid(OwnerPlayerController->PlayerCameraManager))
		{
			NativeOnSwitchToCameraPointReset();
			return false;
		}

		OwnerPlayerController->PlayerCameraManager->SetViewTarget(TargetCameraPoint, ViewTargetTransitionParams);

		if (ViewTargetTransitionParams.BlendTime <= 0.f)
		{
			NativeOnSwitchToCameraPointFinish();
			return true;
		}

		if (UWorld* World = InPlayerController->GetWorld())
		{
			/** PlayerCameraManager 不提供过渡完成回调，这里按 BlendTime 计时后走统一完成收尾。 */
			World->GetTimerManager().SetTimer(TimerHandle, this, &UGenericCameraSwitchMethod_Transition::NativeOnSwitchToCameraPointFinish, ViewTargetTransitionParams.BlendTime);
		}
		else
		{
			NativeOnSwitchToCameraPointFinish();
		}

		return true;
	}

	return false;
}

void UGenericCameraSwitchMethod_Transition::OnSwitchToCameraPointReset_Implementation()
{
	/** 过渡被新切换打断时必须取消旧计时器，避免旧回调在新镜头开始后再次触发完成。 */
	if (IsValid(OwnerPlayerController))
	{
		if (UWorld* World = OwnerPlayerController->GetWorld())
		{
			World->GetTimerManager().ClearTimer(TimerHandle);
		}
	}

	TimerHandle.Invalidate();
	Super::OnSwitchToCameraPointReset_Implementation();
}

void UGenericCameraSwitchMethod_Transition::OnSwitchToCameraPointFinish_Implementation()
{
	/** 正常完成也清理计时器句柄，保持 Reset 与 Finish 两条路径的资源状态一致。 */
	if (IsValid(OwnerPlayerController))
	{
		if (UWorld* World = OwnerPlayerController->GetWorld())
		{
			World->GetTimerManager().ClearTimer(TimerHandle);
		}
	}

	TimerHandle.Invalidate();
	Super::OnSwitchToCameraPointFinish_Implementation();
}

float UGenericCameraSwitchMethod_Transition::GetSwitchDuration_Implementation()
{
	return ViewTargetTransitionParams.BlendTime;
}
