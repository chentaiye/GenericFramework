// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Camera.h"

#include "Subsystem/GenericCameraLocalPlayerSubsystem.h"
#include "Subsystem/GenericCameraSubsystem.h"

ACameraPointBase* UBPFunctions_Camera::GetCameraPoint(APlayerController* Player, const FGameplayTag InCameraTag)
{
	if (const UGenericCameraSubsystem* GenericCameraSubsystem = UGenericCameraSubsystem::Get(Player))
	{
		return GenericCameraSubsystem->GetCameraPoint(InCameraTag);
	}

	return nullptr;
}

bool UBPFunctions_Camera::CanSwitchToCamera(APlayerController* Player, const FGameplayTag InCameraTag)
{
	if (const UGenericCameraSubsystem* GenericCameraSubsystem = UGenericCameraSubsystem::Get(Player))
	{
		return GenericCameraSubsystem->CanSwitchToCamera(InCameraTag);
	}

	return false;
}

void UBPFunctions_Camera::RefreshAllCameraPoints(APlayerController* Player)
{
	if (UGenericCameraSubsystem* GenericCameraSubsystem = UGenericCameraSubsystem::Get(Player))
	{
		GenericCameraSubsystem->RefreshAllCameraPoints();
	}
}

FGameplayTag UBPFunctions_Camera::GetRootCameraTag(APlayerController* Player)
{
	if (const UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		return GenericCameraSubsystem->GetRootCameraTag();
	}

	return FGameplayTag::EmptyTag;
}

void UBPFunctions_Camera::SetRootCameraTag(APlayerController* Player, FGameplayTag InCameraTag)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SetRootCameraTag(InCameraTag);
	}
}

void UBPFunctions_Camera::FocusToActor_HandleClass(APlayerController* Player, AActor* InActor, float FocusLens, TSubclassOf<UGenericCameraSwitchMethod> InCameraSwitchMethodClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->FocusToActor(InActor, FocusLens, InCameraSwitchMethodClass);
	}
}

void UBPFunctions_Camera::FocusToActor_Handle(APlayerController* Player, AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InSwitchCameraMethod)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->FocusToActor(InActor, FocusLens, InSwitchCameraMethod);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Transform_HandleClass(APlayerController* Player, FVector Location, FRotator Rotation, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(Location, Rotation, InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Transform_Handle(APlayerController* Player, FVector Location, FRotator Rotation, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(Location, Rotation, InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Actor_HandleClass(APlayerController* Player, ACameraActor* InCameraActor, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraActor, InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Actor_Handle(APlayerController* Player, ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraActor, InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Component_HandleClass(APlayerController* Player, UCameraComponent* InCameraComponent, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraComponent, InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Component_Handle(APlayerController* Player, UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraComponent, InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Tag_HandleClass(APlayerController* Player, const FGameplayTag InCameraTag, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraTag, InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCamera_Tag_Handle(APlayerController* Player, const FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraTag, InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToCamera_CameraPoint_HandleClass(APlayerController* Player, ACameraPointBase* InCameraPoint, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraPoint, InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCamera_CameraPoint_Handle(APlayerController* Player, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCamera(InCameraPoint, InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToCurrent_HandleClass(APlayerController* Player, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCurrent(InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToCurrent_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToCurrent(InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToPrevious_HandleClass(APlayerController* Player, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToPrevious(InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToPrevious_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToPrevious(InCameraHandle);
	}
}

void UBPFunctions_Camera::SwitchToRoot_HandleClass(APlayerController* Player, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToRoot(InCameraHandleClass);
	}
}

void UBPFunctions_Camera::SwitchToRoot_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraHandle)
{
	if (UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(Player))
	{
		GenericCameraSubsystem->SwitchToRoot(InCameraHandle);
	}
}
