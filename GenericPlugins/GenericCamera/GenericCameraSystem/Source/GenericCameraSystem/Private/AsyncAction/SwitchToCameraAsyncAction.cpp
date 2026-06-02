// Copyright ChenTaiye 2025. All Rights Reserved.

#include "AsyncAction/SwitchToCameraAsyncAction.h"

#include "GameFramework/PlayerController.h"
#include "Subsystem/GenericCameraLocalPlayerSubsystem.h"

void USwitchToCameraAsyncAction::Activate()
{
	Super::Activate();

	UGenericCameraLocalPlayerSubsystem* GenericCameraSubsystem = UGenericCameraLocalPlayerSubsystem::Get(CachedPlayer);
	if (!GenericCameraSubsystem)
	{
		OnHandleFinish();
		return;
	}

	const FSimpleDelegate FinishDelegate = FSimpleDelegate::CreateUObject(this, &USwitchToCameraAsyncAction::OnHandleFinish);
	/** 蓝图静态工厂只缓存参数，真正的子系统调用延迟到 Activate，保证异步节点生命周期已注册。 */
	switch (ActionType)
	{
	case ESwitchToCameraAsyncActionType::FocusToActor:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->FocusToActor(CachedActor, CachedFocusLens, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->FocusToActor(CachedActor, CachedFocusLens, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToTransform:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCamera(CachedLocation, CachedRotation, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCamera(CachedLocation, CachedRotation, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToActor:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraActor, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraActor, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToComponent:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraComponent, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraComponent, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToTag:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraTag, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraTag, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToCameraPoint:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraPoint, CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCamera(CachedCameraPoint, CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToCurrent:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToCurrent(CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToCurrent(CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToPrevious:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToPrevious(CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToPrevious(CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	case ESwitchToCameraAsyncActionType::SwitchToRoot:
		if (bUseMethodClass)
		{
			GenericCameraSubsystem->SwitchToRoot(CachedCameraSwitchMethodClass, FinishDelegate);
		}
		else
		{
			GenericCameraSubsystem->SwitchToRoot(CachedCameraSwitchMethod, FinishDelegate);
		}
		break;

	default:
		OnHandleFinish();
		break;
	}
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::CreateAction(APlayerController* Player)
{
	USwitchToCameraAsyncAction* NewAction = NewObject<USwitchToCameraAsyncAction>();
	NewAction->CachedPlayer = Player;

	if (Player)
	{
		NewAction->RegisterWithGameInstance(Player);
	}

	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::FocusToActor_HandleClass(APlayerController* Player, AActor* InActor, float FocusLens, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::FocusToActor;
	NewAction->bUseMethodClass = true;
	NewAction->CachedActor = InActor;
	NewAction->CachedFocusLens = FocusLens;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::FocusToActor_Handle(APlayerController* Player, AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::FocusToActor;
	NewAction->CachedActor = InActor;
	NewAction->CachedFocusLens = FocusLens;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Transform_HandleClass(APlayerController* Player, const FVector Location, const FRotator Rotation, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToTransform;
	NewAction->bUseMethodClass = true;
	NewAction->CachedLocation = Location;
	NewAction->CachedRotation = Rotation;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Transform_Handle(APlayerController* Player, const FVector Location, const FRotator Rotation, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToTransform;
	NewAction->CachedLocation = Location;
	NewAction->CachedRotation = Rotation;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Actor_HandleClass(APlayerController* Player, ACameraActor* InCameraActor, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToActor;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraActor = InCameraActor;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Actor_Handle(APlayerController* Player, ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToActor;
	NewAction->CachedCameraActor = InCameraActor;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Component_HandleClass(APlayerController* Player, UCameraComponent* InCameraComponent, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToComponent;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraComponent = InCameraComponent;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Component_Handle(APlayerController* Player, UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToComponent;
	NewAction->CachedCameraComponent = InCameraComponent;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Tag_HandleClass(APlayerController* Player, const FGameplayTag InCameraTag, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToTag;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraTag = InCameraTag;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_Tag_Handle(APlayerController* Player, const FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToTag;
	NewAction->CachedCameraTag = InCameraTag;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_CameraPoint_HandleClass(APlayerController* Player, ACameraPointBase* InCameraPoint, const TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToCameraPoint;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraPoint = InCameraPoint;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCamera_CameraPoint_Handle(APlayerController* Player, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToCameraPoint;
	NewAction->CachedCameraPoint = InCameraPoint;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCurrent_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToCurrent;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToCurrent_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToCurrent;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToPrevious_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToPrevious;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToPrevious_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToPrevious;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToRoot_HandleClass(APlayerController* Player, TSubclassOf<UGenericCameraSwitchMethod> InCameraHandleClass)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToRoot;
	NewAction->bUseMethodClass = true;
	NewAction->CachedCameraSwitchMethodClass = InCameraHandleClass;
	return NewAction;
}

USwitchToCameraAsyncAction* USwitchToCameraAsyncAction::SwitchToRoot_Handle(APlayerController* Player, UGenericCameraSwitchMethod* InCameraSwitchMethod)
{
	USwitchToCameraAsyncAction* NewAction = CreateAction(Player);
	NewAction->ActionType = ESwitchToCameraAsyncActionType::SwitchToRoot;
	NewAction->CachedCameraSwitchMethod = InCameraSwitchMethod;
	return NewAction;
}

void USwitchToCameraAsyncAction::OnHandleFinish()
{
	OnFinish.Broadcast();
	SetReadyToDestroy();
}
