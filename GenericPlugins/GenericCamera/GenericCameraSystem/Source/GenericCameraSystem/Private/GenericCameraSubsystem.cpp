// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericCameraSubsystem.h"

#include "CameraType.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameplayMessageSubsystem.h"
#include "Type/DebugType.h"
#include "Type/GenericType.h"

namespace
{
	void BroadcastCameraPointRegisteredMessage(const UObject* WorldContextObject, ACameraPointBase* CameraPoint)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnCameraPointRegisteredMessage Message;
		Message.CameraPoint = CameraPoint;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_Camera_OnCameraPointRegister, Message);
	}

	void BroadcastCameraPointUnregisteredMessage(const UObject* WorldContextObject, ACameraPointBase* CameraPoint)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnCameraPointUnregisteredMessage Message;
		Message.CameraPoint = CameraPoint;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_Camera_OnCameraPointUnRegister, Message);
	}
}

UGenericCameraSubsystem* UGenericCameraSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject || GEngine == nullptr)
	{
		return nullptr;
	}

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	return Get(World);
}

UGenericCameraSubsystem* UGenericCameraSubsystem::Get(const UWorld* World)
{
	return World ? const_cast<UWorld*>(World)->GetSubsystem<UGenericCameraSubsystem>() : nullptr;
}

void UGenericCameraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	ACameraPointBase::OnCameraPointRegister.AddUObject(this, &UGenericCameraSubsystem::AddCameraPoint);
	ACameraPointBase::OnCameraPointUnRegister.AddUObject(this, &UGenericCameraSubsystem::RemoveCameraPoint);

	RegisterExistingCameraPoints();
}

void UGenericCameraSubsystem::Deinitialize()
{
	ACameraPointBase::OnCameraPointRegister.RemoveAll(this);
	ACameraPointBase::OnCameraPointUnRegister.RemoveAll(this);

	CameraPoints.Reset();

	Super::Deinitialize();
}

void UGenericCameraSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	RegisterExistingCameraPoints();
}

void UGenericCameraSubsystem::AddCameraPoint(ACameraPointBase* InCameraPoint)
{
	if (IsValid(InCameraPoint) && IsCameraPointInWorld(InCameraPoint) && InCameraPoint->CameraTag.IsValid() && !CameraPoints.Contains(InCameraPoint->CameraTag))
	{
		GenericLOG(GenericLogCamera, Log, TEXT("On Register : ACameraPointBase [Camera Tag = %s]"), *InCameraPoint->CameraTag.ToString())
		CameraPoints.FindOrAdd(InCameraPoint->CameraTag, InCameraPoint);

		GenericLOG(GenericLogCamera, Log, TEXT("Broadcast OnCameraPointRegister"))
		BroadcastCameraPointRegisteredMessage(this, InCameraPoint);
	}
}

void UGenericCameraSubsystem::RemoveCameraPoint(ACameraPointBase* InCameraPoint)
{
	if (IsValid(InCameraPoint) && IsCameraPointInWorld(InCameraPoint) && InCameraPoint->CameraTag.IsValid() && CameraPoints.Contains(InCameraPoint->CameraTag))
	{
		GenericLOG(GenericLogCamera, Log, TEXT("On UnRegister : ACameraPointBase [Camera Tag = %s]"), *InCameraPoint->CameraTag.ToString())
		CameraPoints.Remove(InCameraPoint->CameraTag);

		GenericLOG(GenericLogCamera, Log, TEXT("Broadcast OnCameraPointUnRegister"))
		BroadcastCameraPointUnregisteredMessage(this, InCameraPoint);
	}
}

bool UGenericCameraSubsystem::CanSwitchToCamera(const FGameplayTag InCameraTag) const
{
	return InCameraTag.IsValid() && IsValid(GetCameraPoint(InCameraTag));
}

ACameraPointBase* UGenericCameraSubsystem::GetCameraPoint(const FGameplayTag InCameraTag) const
{
	if (CameraPoints.Contains(InCameraTag))
	{
		return CameraPoints.FindRef(InCameraTag);
	}

	return nullptr;
}

void UGenericCameraSubsystem::RefreshAllCameraPoints()
{
	for (const TPair<FGameplayTag, ACameraPointBase*>& CameraPointPair : CameraPoints)
	{
		if (IsValid(CameraPointPair.Value))
		{
			CameraPointPair.Value->RefreshFocus();
		}
	}
}

bool UGenericCameraSubsystem::IsCameraPointInWorld(const ACameraPointBase* InCameraPoint) const
{
	return IsValid(InCameraPoint) && InCameraPoint->GetWorld() == GetWorld();
}

void UGenericCameraSubsystem::RegisterExistingCameraPoints()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	CameraPoints.Reset();
	for (TActorIterator<ACameraPointBase> It(World); It; ++It)
	{
		AddCameraPoint(*It);
	}
}
