// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericCameraLocalPlayerSubsystem.h"
#include "Subsystem/GenericCameraSubsystem.h"

#include "CameraType.h"
#include "Camera/CameraComponent.h"
#include "CineCameraComponent.h"
#include "Camera/CameraActor.h"
#include "CameraPoint/GenericCameraPoint.h"
#include "CameraPoint/CameraPointBase.h"
#include "CameraPoint/GenericCineCameraPoint.h"
#include "CameraSwitch/GenericCameraSwitchMethod.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Kismet/KismetMathLibrary.h"
#include "Type/DebugType.h"
#include "Type/GenericType.h"

#define LOCTEXT_NAMESPACE "FGenericCameraSystemModule"

UGenericCameraLocalPlayerSubsystem* UGenericCameraLocalPlayerSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject || GEngine == nullptr)
	{
		return nullptr;
	}

	if (const APlayerController* PlayerController = Cast<APlayerController>(WorldContextObject))
	{
		return Get(PlayerController);
	}

	if (const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(WorldContextObject))
	{
		return Get(LocalPlayer);
	}

	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	if (!World)
	{
		return nullptr;
	}

	if (UGameInstance* GameInstance = World->GetGameInstance())
	{
		return Get(GameInstance->GetFirstGamePlayer());
	}

	return nullptr;
}

UGenericCameraLocalPlayerSubsystem* UGenericCameraLocalPlayerSubsystem::Get(const APlayerController* PlayerController)
{
	return Get(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericCameraLocalPlayerSubsystem* UGenericCameraLocalPlayerSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericCameraLocalPlayerSubsystem>(LocalPlayer);
}

void UGenericCameraLocalPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UGameplayMessageSubsystem::HasInstance(this))
	{
		UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
		HandleCameraSwitchResetListenerHandle = MessageSubsystem.RegisterListener<FOnHandleCameraSwitchMessage>(
			TAG_GameplayMessage_Channel_Camera_OnCameraSwitchReset,
			this,
			&UGenericCameraLocalPlayerSubsystem::HandleSwitchToCameraFinish);
		HandleCameraSwitchFinishListenerHandle = MessageSubsystem.RegisterListener<FOnHandleCameraSwitchMessage>(
			TAG_GameplayMessage_Channel_Camera_OnCameraSwitchFinish,
			this,
			&UGenericCameraLocalPlayerSubsystem::HandleSwitchToCameraFinish);
	}

}

void UGenericCameraLocalPlayerSubsystem::Deinitialize()
{
	Super::Deinitialize();

	HandleCameraSwitchResetListenerHandle.Unregister();
	HandleCameraSwitchFinishListenerHandle.Unregister();
}

void UGenericCameraLocalPlayerSubsystem::HandleSwitchToCameraFinish(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage)
{
	(void)InChannel;
	UGenericCameraSwitchMethod* InCameraHandle = InMessage.SwitchMethod;
	if (!IsValid(InCameraHandle))
	{
		return;
	}

	APlayerController* PlayerController = GetPlayerController();
	if (InMessage.PlayerController != PlayerController || InCameraHandle->OwnerPlayerController != PlayerController)
	{
		return;
	}

	const FString CameraTagString = IsValid(InMessage.CameraPoint) ? InMessage.CameraPoint->CameraTag.ToString() : TEXT("None");
	GenericLOG(GenericLogCamera, Log, TEXT("Camera Switch Finish : [%s]"), *CameraTagString)

	if (CurrentCameraMethods.Contains(InCameraHandle))
	{
		CurrentCameraMethods.Remove(InCameraHandle);
	}
}

FGameplayTag UGenericCameraLocalPlayerSubsystem::GetRootCameraTag() const
{
	return IsValid(GetPlayerController()) ? RootCameraTag : FGameplayTag::EmptyTag;
}

void UGenericCameraLocalPlayerSubsystem::SetRootCameraTag(FGameplayTag InCameraTag)
{
	if (!IsValid(GetPlayerController()))
	{
		GenericLOG(GenericLogCamera, Warning, TEXT("SetRootCameraTag failed because player does not belong to this camera subsystem."))
		return;
	}

	RootCameraTag = InCameraTag;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::FocusToActor(AActor* InActor, float FocusLens, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return FocusToActor(InActor, FocusLens, NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::FocusToActor(AActor* InActor, float FocusLens, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (!IsValid(InActor))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Actor Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (!IsValid(PlayerController->PlayerCameraManager))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("PlayerCameraManager Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		GenericLOG(GenericLogCamera, Error, TEXT("World Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	FVector Location = InActor->GetActorLocation() + PlayerController->PlayerCameraManager->GetActorForwardVector() * -1 * FocusLens;
	FRotator Rotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	AGenericCameraPoint* SpawnCameraPoint = World->SpawnActor<AGenericCameraPoint>(Location, Rotation);
	return SwitchToCamera(SpawnCameraPoint, InCameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FVector& Location, const FRotator& Rotation, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToCamera(Location, Rotation, NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FVector& Location, const FRotator& Rotation, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		GenericLOG(GenericLogCamera, Error, TEXT("World Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	AGenericCameraPoint* SpawnCameraPoint = World->SpawnActor<AGenericCameraPoint>(Location, Rotation);
	return SwitchToCamera(SpawnCameraPoint, InCameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FSwitchToCameraByTransform& InSwitchToCameraByTransform, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	UGenericCameraSwitchMethod* CameraSwitchMethod = nullptr;
	if (InSwitchToCameraByTransform.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodClass && InSwitchToCameraByTransform.CameraSwitchMethodClass)
	{
		CameraSwitchMethod = NewObject<UGenericCameraSwitchMethod>(this, InSwitchToCameraByTransform.CameraSwitchMethodClass);
	}
	else if (InSwitchToCameraByTransform.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodRef && InSwitchToCameraByTransform.CameraSwitchMethodRef)
	{
		CameraSwitchMethod = DuplicateObject<UGenericCameraSwitchMethod>(InSwitchToCameraByTransform.CameraSwitchMethodRef, this);
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		GenericLOG(GenericLogCamera, Error, TEXT("World Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	AGenericCameraPoint* SpawnCameraPoint = World->SpawnActor<AGenericCameraPoint>(InSwitchToCameraByTransform.Location, InSwitchToCameraByTransform.Rotation);
	return SwitchToCamera(SpawnCameraPoint, CameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const ACameraActor* InCameraActor, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	if (!IsValid(InCameraActor))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("CameraActor Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	return SwitchToCamera(InCameraActor->GetCameraComponent(), InCameraSwitchMethodClass, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const ACameraActor* InCameraActor, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	if (!IsValid(InCameraActor))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("CameraActor Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	return SwitchToCamera(InCameraActor->GetCameraComponent(), InCameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(UCameraComponent* InCameraComponent, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToCamera(InCameraComponent, NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(UCameraComponent* InCameraComponent, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (!IsValid(InCameraComponent))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("CameraComponent Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		GenericLOG(GenericLogCamera, Error, TEXT("World Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	ACameraPointBase* SpawnCameraPoint;
	/** Cine 组件需要保留电影机专属参数，因此按组件类型创建对应的临时 CameraPoint。 */
	if (InCameraComponent->IsA(UCineCameraComponent::StaticClass()))
	{
		SpawnCameraPoint = World->SpawnActor<AGenericCineCameraPoint>(InCameraComponent->GetComponentLocation(), InCameraComponent->GetComponentRotation());
	}
	else
	{
		SpawnCameraPoint = World->SpawnActor<AGenericCameraPoint>(InCameraComponent->GetComponentLocation(), InCameraComponent->GetComponentRotation());
	}

	if (!IsValid(SpawnCameraPoint))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("SpawnCameraPoint Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	SpawnCameraPoint->SetCameraComponent(InCameraComponent);
	return SwitchToCamera(SpawnCameraPoint, InCameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FGameplayTag InCameraTag, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToCamera(InCameraTag, NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FGameplayTag InCameraTag, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	const UGenericCameraSubsystem* CameraSubsystem = UGenericCameraSubsystem::Get(this);
	return SwitchToCamera(CameraSubsystem ? CameraSubsystem->GetCameraPoint(InCameraTag) : nullptr, InCameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(const FSwitchToCameraByTag& InSwitchToCameraByTag, const FSimpleDelegate& OnFinish)
{
	UGenericCameraSwitchMethod* CameraSwitchMethod = nullptr;
	if (InSwitchToCameraByTag.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodClass && InSwitchToCameraByTag.CameraSwitchMethodClass)
	{
		CameraSwitchMethod = NewObject<UGenericCameraSwitchMethod>(this, InSwitchToCameraByTag.CameraSwitchMethodClass);
	}
	else if (InSwitchToCameraByTag.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodRef && InSwitchToCameraByTag.CameraSwitchMethodRef)
	{
		CameraSwitchMethod = DuplicateObject<UGenericCameraSwitchMethod>(InSwitchToCameraByTag.CameraSwitchMethodRef, this);
	}

	return SwitchToCamera(InSwitchToCameraByTag.CameraTag, CameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(ACameraPointBase* InCameraPoint, const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToCamera(InCameraPoint, NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCamera(ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (!IsValid(InCameraPoint))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("CameraPoint Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (!IsValid(InCameraSwitchMethod))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("SwitchCameraMethod Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 新切换会打断当前玩家尚未收尾的过渡，旧方法走 Reset 路径以清理计时器和临时相机点。 */
	if (IsSwitching())
	{
		UGenericCameraSwitchMethod* CameraHandle = GetCameraSwitchMethod();
		if (IsValid(CameraHandle))
		{
			const FString CameraTagString = IsValid(CameraHandle->TargetCameraPoint) ? CameraHandle->TargetCameraPoint->CameraTag.ToString() : TEXT("None");
			GenericLOG(GenericLogCamera, Log, TEXT("Camera Switch Reset : [%s]"), *CameraTagString)
			CameraHandle->NativeOnSwitchToCameraPointReset();
		}
	}

	CurrentCameraMethods.AddUnique(InCameraSwitchMethod);

	/** 只有带标签的相机点才进入历史记录，临时相机点完成后会被销毁，不参与 Current/Previous。 */
	if (InCameraPoint->CameraTag.IsValid())
	{
		UpdateCameraTag(InCameraPoint->CameraTag);
	}

	GenericLOG(GenericLogCamera, Log, TEXT("Camera Switch Begin : [%s]"), *InCameraPoint->CameraTag.ToString())
	InCameraSwitchMethod->NativeHandleSwitchToCameraPoint(PlayerController, InCameraPoint, OnFinish);

	return InCameraSwitchMethod;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCurrent(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToCurrent(NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCurrent(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (CurrentCameraTag.IsValid())
	{
		return SwitchToCamera(CurrentCameraTag, InCameraSwitchMethod, OnFinish);
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToCurrent(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish)
{
	UGenericCameraSwitchMethod* CameraSwitchMethod = nullptr;
	if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodClass && InSwitchToCameraParameter.CameraSwitchMethodClass)
	{
		CameraSwitchMethod = NewObject<UGenericCameraSwitchMethod>(this, InSwitchToCameraParameter.CameraSwitchMethodClass);
	}
	else if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodRef && InSwitchToCameraParameter.CameraSwitchMethodRef)
	{
		CameraSwitchMethod = DuplicateObject<UGenericCameraSwitchMethod>(InSwitchToCameraParameter.CameraSwitchMethodRef, this);
	}

	return SwitchToCurrent(CameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToPrevious(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToPrevious(NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToPrevious(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (PreviousCameraTag.IsValid())
	{
		return SwitchToCamera(PreviousCameraTag, InCameraSwitchMethod, OnFinish);
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToPrevious(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish)
{
	UGenericCameraSwitchMethod* CameraSwitchMethod = nullptr;
	if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodClass && InSwitchToCameraParameter.CameraSwitchMethodClass)
	{
		CameraSwitchMethod = NewObject<UGenericCameraSwitchMethod>(this, InSwitchToCameraParameter.CameraSwitchMethodClass);
	}
	else if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodRef && InSwitchToCameraParameter.CameraSwitchMethodRef)
	{
		CameraSwitchMethod = DuplicateObject<UGenericCameraSwitchMethod>(InSwitchToCameraParameter.CameraSwitchMethodRef, this);
	}

	return SwitchToPrevious(CameraSwitchMethod, OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToRoot(const TSubclassOf<UGenericCameraSwitchMethod>& InCameraSwitchMethodClass, const FSimpleDelegate& OnFinish)
{
	return SwitchToRoot(NewObject<UGenericCameraSwitchMethod>(this, InCameraSwitchMethodClass), OnFinish);
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToRoot(UGenericCameraSwitchMethod* InCameraSwitchMethod, const FSimpleDelegate& OnFinish)
{
	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		GenericLOG(GenericLogCamera, Error, TEXT("Player Is InValid"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	if (RootCameraTag.IsValid())
	{
		return SwitchToCamera(RootCameraTag, InCameraSwitchMethod, OnFinish);
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::SwitchToRoot(const FSwitchToCameraParameter& InSwitchToCameraParameter, const FSimpleDelegate& OnFinish)
{
	UGenericCameraSwitchMethod* CameraSwitchMethod = nullptr;
	if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodClass && InSwitchToCameraParameter.CameraSwitchMethodClass)
	{
		CameraSwitchMethod = NewObject<UGenericCameraSwitchMethod>(this, InSwitchToCameraParameter.CameraSwitchMethodClass);
	}
	else if (InSwitchToCameraParameter.CameraSwitchMethodType == ECameraSwitchMethodType::UseMethodRef && InSwitchToCameraParameter.CameraSwitchMethodRef)
	{
		CameraSwitchMethod = DuplicateObject<UGenericCameraSwitchMethod>(InSwitchToCameraParameter.CameraSwitchMethodRef, this);
	}

	return SwitchToRoot(CameraSwitchMethod, OnFinish);
}

bool UGenericCameraLocalPlayerSubsystem::IsSwitching() const
{
	const APlayerController* PlayerController = GetPlayerController();

	if (IsValid(PlayerController))
	{
		for (const auto& CurrentCameraHandle : CurrentCameraMethods)
		{
			if (IsValid(CurrentCameraHandle) && CurrentCameraHandle->OwnerPlayerController == PlayerController)
			{
				return true;
			}
		}
	}

	return false;
}

UGenericCameraSwitchMethod* UGenericCameraLocalPlayerSubsystem::GetCameraSwitchMethod() const
{
	const APlayerController* PlayerController = GetPlayerController();
	for (const auto& Method : CurrentCameraMethods)
	{
		if (IsValid(Method) && Method->OwnerPlayerController == PlayerController)
		{
			return Method;
		}
	}
	return nullptr;
}

void UGenericCameraLocalPlayerSubsystem::UpdateCameraTag(const FGameplayTag InCameraTag)
{
	PreviousCameraTag = CurrentCameraTag;
	CurrentCameraTag = InCameraTag;
}

#undef LOCTEXT_NAMESPACE
