// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraView/SyncCameraViewComponent.h"

#include "CameraView/CameraViewSyncPolicy.h"

USyncCameraViewComponent::USyncCameraViewComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USyncCameraViewComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeCameraViewSyncPolicies();
	RegisterCameraSwitchListeners();
}

void USyncCameraViewComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UnregisterCameraSwitchListeners();
	DeinitializeCameraViewSyncPolicies();

	Super::EndPlay(EndPlayReason);
}

void USyncCameraViewComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->TickCameraViewSyncPolicy(DeltaTime);
		}
	}
}

UCameraViewSyncPolicy* USyncCameraViewComponent::GetCameraViewSyncPolicy() const
{
	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			return CameraViewSyncPolicy;
		}
	}

	return nullptr;
}

TArray<UCameraViewSyncPolicy*> USyncCameraViewComponent::GetCameraViewSyncPolicies() const
{
	TArray<UCameraViewSyncPolicy*> Result;
	Result.Reserve(CameraViewSyncPolicies.Num());
	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			Result.Add(CameraViewSyncPolicy);
		}
	}

	return Result;
}

void USyncCameraViewComponent::HandleCameraSwitchBeginMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage)
{
	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->HandleCameraSwitchBeginMessage(InChannel, InMessage);
		}
	}
}

void USyncCameraViewComponent::HandleCameraSwitchResetMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage)
{
	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->HandleCameraSwitchResetMessage(InChannel, InMessage);
		}
	}
}

void USyncCameraViewComponent::HandleCameraSwitchFinishMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage)
{
	for (UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->HandleCameraSwitchFinishMessage(InChannel, InMessage);
		}
	}
}

bool USyncCameraViewComponent::HasCameraViewSyncPolicy() const
{
	for (const UCameraViewSyncPolicy* CameraViewSyncPolicy : CameraViewSyncPolicies)
	{
		if (IsValid(CameraViewSyncPolicy))
		{
			return true;
		}
	}

	return false;
}

void USyncCameraViewComponent::InitializeCameraViewSyncPolicies()
{
	DeinitializeCameraViewSyncPolicies();

	TSet<UClass*> CreatedPolicyClasses;
	for (const TSubclassOf<UCameraViewSyncPolicy>& PolicyClass : CameraViewSyncPolicyClasses)
	{
		UClass* ResolvedPolicyClass = PolicyClass.Get();
		if (!IsValid(ResolvedPolicyClass) || ResolvedPolicyClass->HasAnyClassFlags(CLASS_Abstract) || CreatedPolicyClasses.Contains(ResolvedPolicyClass))
		{
			continue;
		}

		UCameraViewSyncPolicy* CameraViewSyncPolicy = NewObject<UCameraViewSyncPolicy>(this, ResolvedPolicyClass);
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->InitializeCameraViewSyncPolicy(this);
			CameraViewSyncPolicies.Add(CameraViewSyncPolicy);
			CreatedPolicyClasses.Add(ResolvedPolicyClass);
		}
	}
}

void USyncCameraViewComponent::DeinitializeCameraViewSyncPolicies()
{
	for (int32 Index = CameraViewSyncPolicies.Num() - 1; Index >= 0; --Index)
	{
		UCameraViewSyncPolicy* CameraViewSyncPolicy = CameraViewSyncPolicies[Index];
		if (IsValid(CameraViewSyncPolicy))
		{
			CameraViewSyncPolicy->DeinitializeCameraViewSyncPolicy();
		}
	}

	CameraViewSyncPolicies.Reset();
}

void USyncCameraViewComponent::RegisterCameraSwitchListeners()
{
	UnregisterCameraSwitchListeners();

	if (!HasCameraViewSyncPolicy() || !UGameplayMessageSubsystem::HasInstance(this))
	{
		return;
	}

	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	CameraSwitchBeginListenerHandle = MessageSubsystem.RegisterListener<FOnHandleCameraSwitchMessage>(
		TAG_GameplayMessage_Channel_Camera_OnCameraSwitchBegin,
		this,
		&USyncCameraViewComponent::HandleCameraSwitchBeginMessage
	);
	CameraSwitchResetListenerHandle = MessageSubsystem.RegisterListener<FOnHandleCameraSwitchMessage>(
		TAG_GameplayMessage_Channel_Camera_OnCameraSwitchReset,
		this,
		&USyncCameraViewComponent::HandleCameraSwitchResetMessage
	);
	CameraSwitchFinishListenerHandle = MessageSubsystem.RegisterListener<FOnHandleCameraSwitchMessage>(
		TAG_GameplayMessage_Channel_Camera_OnCameraSwitchFinish,
		this,
		&USyncCameraViewComponent::HandleCameraSwitchFinishMessage
	);
}

void USyncCameraViewComponent::UnregisterCameraSwitchListeners()
{
	CameraSwitchBeginListenerHandle.Unregister();
	CameraSwitchResetListenerHandle.Unregister();
	CameraSwitchFinishListenerHandle.Unregister();
}
