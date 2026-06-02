// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraSwitch/GenericCameraSwitchMethod.h"

#include "CameraType.h"
#include "CameraPoint/CameraPointBase.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"

namespace
{
	void BroadcastHandleCameraSwitchMessage(const UObject* WorldContextObject, const FGameplayTag Channel, APlayerController* PlayerController, ACameraPointBase* CameraPoint, UGenericCameraSwitchMethod* SwitchMethod)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnHandleCameraSwitchMessage Message;
		Message.PlayerController = PlayerController;
		Message.CameraPoint = CameraPoint;
		Message.SwitchMethod = SwitchMethod;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(Channel, Message);
	}
}

bool UGenericCameraSwitchMethod::HandleSwitchToCameraPoint_Implementation(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint)
{
	return true;
}

bool UGenericCameraSwitchMethod::NativeHandleSwitchToCameraPoint(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint, FSimpleDelegate OnFinish)
{
	if (IsValid(InPlayerController) && IsValid(InCameraPoint))
	{
		/** 切换方法只缓存本次调用上下文，重置和正常完成都会在同一收尾路径中清空。 */
		OwnerPlayerController = InPlayerController;
		TargetCameraPoint = InCameraPoint;
		OnHandleFinish = OnFinish;

		BroadcastHandleCameraSwitchMessage(InPlayerController, TAG_GameplayMessage_Channel_Camera_OnCameraSwitchBegin, InPlayerController, InCameraPoint, this);
		return HandleSwitchToCameraPoint(InPlayerController, InCameraPoint);
	}

	OnFinish.ExecuteIfBound();
	return false;
}

void UGenericCameraSwitchMethod::OnSwitchToCameraPointReset_Implementation()
{
}

void UGenericCameraSwitchMethod::NativeOnSwitchToCameraPointReset()
{
	OnSwitchToCameraPointReset();

	BroadcastHandleCameraSwitchMessage(OwnerPlayerController, TAG_GameplayMessage_Channel_Camera_OnCameraSwitchReset, OwnerPlayerController, TargetCameraPoint, this);
	OnHandleFinish.ExecuteIfBound();

	if (IsValid(TargetCameraPoint) && !TargetCameraPoint->CameraTag.IsValid())
	{
		/** 无标签相机点由一次性切换流程生成，收尾时由方法对象统一销毁。 */
		TargetCameraPoint->Destroy();
	}

	OwnerPlayerController = nullptr;
	TargetCameraPoint = nullptr;
	OnHandleFinish.Unbind();
}

void UGenericCameraSwitchMethod::OnSwitchToCameraPointFinish_Implementation()
{
}

void UGenericCameraSwitchMethod::NativeOnSwitchToCameraPointFinish()
{
	OnSwitchToCameraPointFinish();

	BroadcastHandleCameraSwitchMessage(OwnerPlayerController, TAG_GameplayMessage_Channel_Camera_OnCameraSwitchFinish, OwnerPlayerController, TargetCameraPoint, this);
	OnHandleFinish.ExecuteIfBound();

	if (IsValid(TargetCameraPoint) && !TargetCameraPoint->CameraTag.IsValid())
	{
		/** 标签索引中的相机点归关卡拥有，只有临时无标签相机点在切换结束后释放。 */
		TargetCameraPoint->Destroy();
	}

	OwnerPlayerController = nullptr;
	TargetCameraPoint = nullptr;
	OnHandleFinish.Unbind();
}

float UGenericCameraSwitchMethod::GetSwitchDuration_Implementation()
{
	return 0.f;
}
