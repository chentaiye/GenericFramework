// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraView/LevelSequenceCameraViewSyncPolicy.h"

#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "GenericLevelSequenceHandle.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

void ULevelSequenceCameraViewSyncPolicy::InitializeCameraViewSyncPolicy(USyncCameraViewComponent* InOwnerComponent)
{
	Super::InitializeCameraViewSyncPolicy(InOwnerComponent);

	RegisterLevelSequenceListeners(GetOwnerActor());
}

void ULevelSequenceCameraViewSyncPolicy::DeinitializeCameraViewSyncPolicy()
{
	UnregisterLevelSequenceListeners();
	ResetLevelSequenceSyncState();

	Super::DeinitializeCameraViewSyncPolicy();
}

void ULevelSequenceCameraViewSyncPolicy::TickCameraViewSyncPolicy(float DeltaSeconds)
{
	Super::TickCameraViewSyncPolicy(DeltaSeconds);

	APlayerController* PlayerController = GetOwnerPlayerController();
	if (!IsValid(PlayerController) || !PlayerController->IsLocalController())
	{
		return;
	}

	// 通过句柄播放的序列优先走消息路径；Tick 兜底处理场景中直接放置并播放的 LevelSequenceActor。
	if (!CacheActiveLevelSequenceCameraView())
	{
		CacheObservedLevelSequenceCameraView(PlayerController);
	}

	TrySyncObservedLevelSequenceCameraView(PlayerController);
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	TrackLevelSequence(LevelSequenceHandle, LevelSequencePlayer);
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayReverseMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	TrackLevelSequence(LevelSequenceHandle, LevelSequencePlayer);
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePauseMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	if (!IsTrackedLevelSequence(LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	CacheActiveLevelSequenceCameraView();
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceStopMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	if (!IsTrackedLevelSequence(LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	const FLevelSequenceCameraView FinalCameraView = GetFinalLevelSequenceCameraView(PlayerController, InMessage.CameraView, LevelSequencePlayer);
	if (ShouldSyncLevelSequenceCameraView(PlayerController, FinalCameraView))
	{
		SyncLevelSequenceCameraView(PlayerController, FinalCameraView);
	}

	ResetLevelSequenceSyncState();
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceSeekMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	if (!IsTrackedLevelSequence(LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	CacheActiveLevelSequenceCameraView();
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceFinishMessage(FGameplayTag, const FOnLevelSequenceMessage& InMessage)
{
	APlayerController* PlayerController = nullptr;
	UGenericLevelSequenceHandle* LevelSequenceHandle = nullptr;
	ULevelSequencePlayer* LevelSequencePlayer = nullptr;
	if (!TryGetLevelSequenceMessageContext(InMessage, PlayerController, LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	if (!IsTrackedLevelSequence(LevelSequenceHandle, LevelSequencePlayer))
	{
		return;
	}

	const FLevelSequenceCameraView FinalCameraView = GetFinalLevelSequenceCameraView(PlayerController, InMessage.CameraView, LevelSequencePlayer);
	if (ShouldSyncLevelSequenceCameraView(PlayerController, FinalCameraView))
	{
		SyncLevelSequenceCameraView(PlayerController, FinalCameraView);
	}

	ResetLevelSequenceSyncState();
}

void ULevelSequenceCameraViewSyncPolicy::SyncLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView)
{
	AlignCameraToCameraView(InPlayerController, InCameraView, true);
}

void ULevelSequenceCameraViewSyncPolicy::AlignCameraToCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView, const bool bInSetViewTarget) const
{
	AActor* TargetActor = GetOwnerActor();
	if (!IsValid(InPlayerController) || !IsValid(TargetActor) || !InCameraView.bHasCameraView)
	{
		return;
	}

	USpringArmComponent* TargetSpringArmComponent = GetTargetSpringArmComponent();
	UCameraComponent* TargetCameraComponent = GetTargetCameraComponent();
	if (!IsValid(TargetSpringArmComponent) || !IsValid(TargetCameraComponent))
	{
		return;
	}

	const FMinimalViewInfo& SourceCameraView = InCameraView.CameraView;
	const FVector SourceCameraLocation = SourceCameraView.Location;
	const FRotator SourceCameraRotation = SourceCameraView.Rotation;

	// 同步时把 SpringArm 的偏移和碰撞影响清零并重置 Lag，避免切回 Pawn 相机的最后一帧出现插值偏移。
	TargetSpringArmComponent->TargetOffset = FVector::ZeroVector;
	TargetSpringArmComponent->SocketOffset = FVector::ZeroVector;
	TargetSpringArmComponent->bDoCollisionTest = false;
	TargetSpringArmComponent->SetRelativeLocation(FVector::ZeroVector, false, nullptr, ETeleportType::TeleportPhysics);

	TargetActor->SetActorLocation(SourceCameraLocation, false, nullptr, ETeleportType::TeleportPhysics);
	TargetActor->SetActorRotation(FRotator(0.f, SourceCameraRotation.Yaw, 0.f), ETeleportType::TeleportPhysics);
	TargetSpringArmComponent->SetRelativeRotation(FRotator(SourceCameraRotation.Pitch, 0.f, 0.f), false, nullptr, ETeleportType::TeleportPhysics);
	SetSpringArmTargetArmLength(TargetSpringArmComponent, 0.f);
	TargetSpringArmComponent->UpdateComponentToWorld();
	ResetSpringArmLagState(TargetSpringArmComponent);

	ApplyCameraViewParameters(SourceCameraView, TargetCameraComponent);
	TargetCameraComponent->SetWorldLocationAndRotation(SourceCameraLocation, SourceCameraRotation, false, nullptr, ETeleportType::TeleportPhysics);
	TargetCameraComponent->UpdateComponentToWorld();

	InPlayerController->SetControlRotation(SourceCameraRotation);
	if (bInSetViewTarget)
	{
		InPlayerController->SetViewTarget(TargetActor);
	}
}

void ULevelSequenceCameraViewSyncPolicy::ApplyCameraViewParameters(const FMinimalViewInfo& InSourceCameraView, UCameraComponent* InTargetCameraComponent) const
{
	if (!IsValid(InTargetCameraComponent))
	{
		return;
	}

	// FMinimalViewInfo 中和 CameraComponent 对应的参数逐项写回，保证 FOV、投影、后处理一致。
	InTargetCameraComponent->SetProjectionMode(InSourceCameraView.ProjectionMode);
	InTargetCameraComponent->SetFieldOfView(InSourceCameraView.FOV);
	InTargetCameraComponent->SetAspectRatio(InSourceCameraView.AspectRatio);
	InTargetCameraComponent->SetConstraintAspectRatio(InSourceCameraView.bConstrainAspectRatio);
	InTargetCameraComponent->SetUseFieldOfViewForLOD(InSourceCameraView.bUseFieldOfViewForLOD);
	InTargetCameraComponent->SetOrthoWidth(InSourceCameraView.OrthoWidth);
	InTargetCameraComponent->SetAutoCalculateOrthoPlanes(InSourceCameraView.bAutoCalculateOrthoPlanes);
	InTargetCameraComponent->SetAutoPlaneShift(InSourceCameraView.AutoPlaneShift);
	InTargetCameraComponent->SetOrthoNearClipPlane(InSourceCameraView.OrthoNearClipPlane);
	InTargetCameraComponent->SetOrthoFarClipPlane(InSourceCameraView.OrthoFarClipPlane);
	InTargetCameraComponent->SetUpdateOrthoPlanes(InSourceCameraView.bUpdateOrthoPlanes);
	InTargetCameraComponent->SetUseCameraHeightAsViewTarget(InSourceCameraView.bUseCameraHeightAsViewTarget);
	InTargetCameraComponent->SetEnableFirstPersonFieldOfView(InSourceCameraView.bUseFirstPersonParameters);
	InTargetCameraComponent->SetEnableFirstPersonScale(InSourceCameraView.bUseFirstPersonParameters);
	InTargetCameraComponent->SetFirstPersonFieldOfView(InSourceCameraView.FirstPersonFOV);
	InTargetCameraComponent->SetFirstPersonScale(InSourceCameraView.FirstPersonScale);
	InTargetCameraComponent->SetPostProcessBlendWeight(InSourceCameraView.PostProcessBlendWeight);
	InTargetCameraComponent->PostProcessSettings = InSourceCameraView.PostProcessSettings;
	if (InSourceCameraView.AspectRatioAxisConstraint.IsSet())
	{
		InTargetCameraComponent->SetAspectRatioAxisConstraint(InSourceCameraView.AspectRatioAxisConstraint.GetValue());
		InTargetCameraComponent->bOverrideAspectRatioAxisConstraint = true;
	}
	else
	{
		InTargetCameraComponent->bOverrideAspectRatioAxisConstraint = false;
	}
}

bool ULevelSequenceCameraViewSyncPolicy::CacheActiveLevelSequenceCameraView()
{
	ULevelSequencePlayer* LevelSequencePlayer = ActiveLevelSequencePlayer.Get();
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	RegisterLevelSequencePlayerUpdate(LevelSequencePlayer);
	if (!LevelSequencePlayer->IsPlaying() && !LevelSequencePlayer->IsPaused())
	{
		// Stop/Finish 后当前 CameraCut 可能已空，继续返回历史缓存供结束消息使用。
		return CachedLevelSequenceCameraView.bHasCameraView;
	}

	FLevelSequenceCameraView CameraView;
	if (!TryCacheLevelSequencePlayerCameraView(GetOwnerPlayerController(), LevelSequencePlayer, CameraView))
	{
		return false;
	}

	CachedLevelSequenceCameraView = CameraView;
	return true;
}

bool ULevelSequenceCameraViewSyncPolicy::CacheObservedLevelSequenceCameraView(APlayerController* InPlayerController)
{
	AActor* OwnerActor = GetOwnerActor();
	if (ActiveLevelSequenceHandle.IsValid() || !IsValid(InPlayerController) || !IsValid(OwnerActor))
	{
		return false;
	}

	UWorld* World = OwnerActor->GetWorld();
	if (!IsValid(World))
	{
		return false;
	}

	// 兼容未通过 UGenericLevelSequenceHandle 创建的场景序列，运行时按世界 Actor 扫描正在播放的序列。
	for (TActorIterator<ALevelSequenceActor> It(World); It; ++It)
	{
		ALevelSequenceActor* LevelSequenceActor = *It;
		ULevelSequencePlayer* LevelSequencePlayer = IsValid(LevelSequenceActor) ? LevelSequenceActor->GetSequencePlayer() : nullptr;
		if (!IsValid(LevelSequencePlayer) || (!LevelSequencePlayer->IsPlaying() && !LevelSequencePlayer->IsPaused()))
		{
			continue;
		}

		RegisterObservedLevelSequencePlayer(LevelSequencePlayer);

		FLevelSequenceCameraView CameraView;
		if (!TryCacheLevelSequencePlayerCameraView(InPlayerController, LevelSequencePlayer, CameraView))
		{
			return false;
		}

		CachedLevelSequenceCameraView = CameraView;
		return true;
	}

	return false;
}

bool ULevelSequenceCameraViewSyncPolicy::CacheCameraView(UCameraComponent* InCameraComponent, FLevelSequenceCameraView& OutCameraView) const
{
	if (!IsValid(InCameraComponent) || IsOwnerCameraComponent(InCameraComponent))
	{
		return false;
	}

	FMinimalViewInfo CameraView;
	InCameraComponent->GetCameraView(0.f, CameraView);

	OutCameraView.CameraComponent = InCameraComponent;
	OutCameraView.CameraView = CameraView;
	OutCameraView.bHasCameraView = true;
	return true;
}

UCameraComponent* ULevelSequenceCameraViewSyncPolicy::GetActiveLevelSequenceCameraComponent(ULevelSequencePlayer* InLevelSequencePlayer) const
{
	UCameraComponent* CurrentCameraComponent = GetCurrentLevelSequenceCameraComponent(InLevelSequencePlayer);
	if (IsValid(CurrentCameraComponent))
	{
		return CurrentCameraComponent;
	}

	// 当前 CameraCut 被清空时只允许使用最后缓存的非拥有者相机组件。
	UCameraComponent* CachedCameraComponent = CachedLevelSequenceCameraView.CameraComponent;
	return IsValid(CachedCameraComponent) && !IsOwnerCameraComponent(CachedCameraComponent) ? CachedCameraComponent : nullptr;
}

UCameraComponent* ULevelSequenceCameraViewSyncPolicy::GetCurrentLevelSequenceCameraComponent(ULevelSequencePlayer* InLevelSequencePlayer) const
{
	if (!IsValid(InLevelSequencePlayer))
	{
		return nullptr;
	}

	UCameraComponent* ActiveCameraComponent = InLevelSequencePlayer->GetActiveCameraComponent();
	if (IsValid(ActiveCameraComponent) && !IsOwnerCameraComponent(ActiveCameraComponent))
	{
		return ActiveCameraComponent;
	}

	// 只读当前帧快照，不使用历史缓存，避免把旧相机误判为当前 CameraCut。
	FLevelSequencePlayerSnapshot Snapshot;
	InLevelSequencePlayer->TakeFrameSnapshot(Snapshot);
	UCameraComponent* SnapshotCameraComponent = Snapshot.CameraComponent.Get();
	if (IsValid(SnapshotCameraComponent) && !IsOwnerCameraComponent(SnapshotCameraComponent))
	{
		return SnapshotCameraComponent;
	}

	return nullptr;
}

FLevelSequenceCameraView ULevelSequenceCameraViewSyncPolicy::GetFinalLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InMessageCameraView, ULevelSequencePlayer* InLevelSequencePlayer) const
{
	FLevelSequenceCameraView FinalCameraView;

	// 最终视图优先使用 PlayerCameraManager 的实际渲染结果，其次使用消息缓存，再回退到策略逐帧缓存。
	UCameraComponent* SourceCameraComponent = GetCurrentLevelSequenceCameraComponent(InLevelSequencePlayer);
	if (IsValid(SourceCameraComponent) && TryGetPlayerCameraManagerView(InPlayerController, SourceCameraComponent, FinalCameraView))
	{
		return FinalCameraView;
	}

	if (InMessageCameraView.bHasCameraView && !IsOwnerCameraComponent(InMessageCameraView.CameraComponent))
	{
		return InMessageCameraView;
	}

	if (CachedLevelSequenceCameraView.bHasCameraView && !IsOwnerCameraComponent(CachedLevelSequenceCameraView.CameraComponent))
	{
		return CachedLevelSequenceCameraView;
	}

	if (TryGetPlayerCameraManagerView(InPlayerController, SourceCameraComponent, FinalCameraView))
	{
		return FinalCameraView;
	}

	SourceCameraComponent = GetActiveLevelSequenceCameraComponent(InLevelSequencePlayer);
	CacheCameraView(SourceCameraComponent, FinalCameraView);
	return FinalCameraView;
}

APlayerController* ULevelSequenceCameraViewSyncPolicy::GetOwnerPlayerController() const
{
	const APawn* OwnerPawn = Cast<APawn>(GetOwnerActor());
	return IsValid(OwnerPawn) ? Cast<APlayerController>(OwnerPawn->GetController()) : nullptr;
}

UCameraComponent* ULevelSequenceCameraViewSyncPolicy::GetTargetCameraComponent() const
{
	const AActor* OwnerActor = GetOwnerActor();
	return IsValid(OwnerActor) ? OwnerActor->FindComponentByClass<UCameraComponent>() : nullptr;
}

USpringArmComponent* ULevelSequenceCameraViewSyncPolicy::GetTargetSpringArmComponent() const
{
	const AActor* OwnerActor = GetOwnerActor();
	return IsValid(OwnerActor) ? OwnerActor->FindComponentByClass<USpringArmComponent>() : nullptr;
}

bool ULevelSequenceCameraViewSyncPolicy::IsOwnerCameraComponent(const UCameraComponent* InCameraComponent) const
{
	const AActor* OwnerActor = GetOwnerActor();
	return IsValid(InCameraComponent) && IsValid(OwnerActor) && InCameraComponent->GetOwner() == OwnerActor;
}

bool ULevelSequenceCameraViewSyncPolicy::IsTrackedLevelSequence(UGenericLevelSequenceHandle* InLevelSequenceHandle, ULevelSequencePlayer* InLevelSequencePlayer) const
{
	if (ActiveLevelSequenceHandle.IsValid() && ActiveLevelSequenceHandle.Get() != InLevelSequenceHandle)
	{
		return false;
	}

	if (ActiveLevelSequencePlayer.IsValid() && ActiveLevelSequencePlayer.Get() != InLevelSequencePlayer)
	{
		return false;
	}

	return true;
}

void ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayerUpdated(const UMovieSceneSequencePlayer& InSequencePlayer, FFrameTime, FFrameTime)
{
	ULevelSequencePlayer* LevelSequencePlayer = LevelSequenceUpdatedPlayer.Get();
	if (!IsValid(LevelSequencePlayer) || static_cast<const UMovieSceneSequencePlayer*>(LevelSequencePlayer) != &InSequencePlayer)
	{
		return;
	}

	// 与句柄侧保持一致：只有播放/暂停期间的相机才允许刷新缓存。
	if (!LevelSequencePlayer->IsPlaying() && !LevelSequencePlayer->IsPaused())
	{
		return;
	}

	FLevelSequenceCameraView CameraView;
	if (TryCacheLevelSequencePlayerCameraView(GetOwnerPlayerController(), LevelSequencePlayer, CameraView))
	{
		CachedLevelSequenceCameraView = CameraView;
	}
}

void ULevelSequenceCameraViewSyncPolicy::HandleObservedLevelSequencePlayerStop()
{
	TrySyncObservedLevelSequenceCameraView(GetOwnerPlayerController());
}

void ULevelSequenceCameraViewSyncPolicy::HandleObservedLevelSequencePlayerFinish()
{
	TrySyncObservedLevelSequenceCameraView(GetOwnerPlayerController());
}

void ULevelSequenceCameraViewSyncPolicy::RegisterLevelSequencePlayerUpdate(ULevelSequencePlayer* InLevelSequencePlayer)
{
	if (LevelSequenceUpdatedPlayer.Get() == InLevelSequencePlayer && LevelSequenceUpdatedDelegateHandle.IsValid())
	{
		return;
	}

	UnregisterLevelSequencePlayerUpdate();

	if (!IsValid(InLevelSequencePlayer))
	{
		return;
	}

	LevelSequenceUpdatedPlayer = InLevelSequencePlayer;
	LevelSequenceUpdatedDelegateHandle = InLevelSequencePlayer->OnSequenceUpdated().AddUObject(this, &ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayerUpdated);
}

void ULevelSequenceCameraViewSyncPolicy::RegisterLevelSequenceListeners(AActor* InOwnerActor)
{
	UnregisterLevelSequenceListeners();

	if (!UGameplayMessageSubsystem::HasInstance(InOwnerActor))
	{
		return;
	}

	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(InOwnerActor);
	// 每个通道单独绑定到独立函数，保持消息语义清晰，便于后续按事件扩展。
	LevelSequencePlayListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnPlay,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayMessage
	);
	LevelSequencePlayReverseListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnPlayReverse,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePlayReverseMessage
	);
	LevelSequencePauseListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnPause,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequencePauseMessage
	);
	LevelSequenceStopListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnStop,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceStopMessage
	);
	LevelSequenceSeekListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnSeek,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceSeekMessage
	);
	LevelSequenceFinishListenerHandle = MessageSubsystem.RegisterListener<FOnLevelSequenceMessage>(
		TAG_GameplayMessage_Channel_LevelSequence_OnFinish,
		this,
		&ULevelSequenceCameraViewSyncPolicy::HandleLevelSequenceFinishMessage
	);
}

void ULevelSequenceCameraViewSyncPolicy::RegisterObservedLevelSequencePlayer(ULevelSequencePlayer* InLevelSequencePlayer)
{
	if (ObservedLevelSequencePlayer.Get() == InLevelSequencePlayer)
	{
		return;
	}

	UnregisterObservedLevelSequencePlayer();

	if (!IsValid(InLevelSequencePlayer))
	{
		return;
	}

	ObservedLevelSequencePlayer = InLevelSequencePlayer;
	InLevelSequencePlayer->OnStop.AddUniqueDynamic(this, &ULevelSequenceCameraViewSyncPolicy::HandleObservedLevelSequencePlayerStop);
	InLevelSequencePlayer->OnFinished.AddUniqueDynamic(this, &ULevelSequenceCameraViewSyncPolicy::HandleObservedLevelSequencePlayerFinish);
	RegisterLevelSequencePlayerUpdate(InLevelSequencePlayer);
}

void ULevelSequenceCameraViewSyncPolicy::ResetLevelSequenceSyncState()
{
	UnregisterObservedLevelSequencePlayer();
	UnregisterLevelSequencePlayerUpdate();
	ActiveLevelSequenceHandle.Reset();
	ActiveLevelSequencePlayer.Reset();
	CachedLevelSequenceCameraView = FLevelSequenceCameraView();
}

bool ULevelSequenceCameraViewSyncPolicy::ShouldSyncLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView) const
{
	AActor* OwnerActor = GetOwnerActor();
	if (!IsValid(InPlayerController) || !IsValid(OwnerActor) || !InCameraView.bHasCameraView)
	{
		return false;
	}

	const UCameraComponent* SourceCameraComponent = InCameraView.CameraComponent;
	if (IsValid(SourceCameraComponent) && SourceCameraComponent->GetOwner() == OwnerActor)
	{
		return false;
	}

	return true;
}

bool ULevelSequenceCameraViewSyncPolicy::ShouldSyncObservedLevelSequenceCameraView(APlayerController* InPlayerController) const
{
	AActor* OwnerActor = GetOwnerActor();
	if (ActiveLevelSequenceHandle.IsValid() || !ObservedLevelSequencePlayer.IsValid() || !ShouldSyncLevelSequenceCameraView(InPlayerController, CachedLevelSequenceCameraView))
	{
		return false;
	}

	return IsValid(InPlayerController) && InPlayerController->GetViewTarget() == OwnerActor;
}

void ULevelSequenceCameraViewSyncPolicy::TrackLevelSequence(UGenericLevelSequenceHandle* InLevelSequenceHandle, ULevelSequencePlayer* InLevelSequencePlayer)
{
	ResetLevelSequenceSyncState();
	ActiveLevelSequenceHandle = InLevelSequenceHandle;
	ActiveLevelSequencePlayer = InLevelSequencePlayer;
	RegisterLevelSequencePlayerUpdate(InLevelSequencePlayer);
	CacheActiveLevelSequenceCameraView();
}

bool ULevelSequenceCameraViewSyncPolicy::TryCacheLevelSequencePlayerCameraView(APlayerController* InPlayerController, ULevelSequencePlayer* InLevelSequencePlayer, FLevelSequenceCameraView& OutCameraView) const
{
	if (!IsValid(InLevelSequencePlayer))
	{
		return false;
	}

	UCameraComponent* SourceCameraComponent = GetCurrentLevelSequenceCameraComponent(InLevelSequencePlayer);
	if (CacheCameraView(SourceCameraComponent, OutCameraView))
	{
		return true;
	}

	// 当前 CameraCut 取不到时，只在 PlayerCameraManager 仍指向序列相机的情况下使用渲染缓存。
	return TryGetPlayerCameraManagerView(InPlayerController, SourceCameraComponent, OutCameraView);
}

bool ULevelSequenceCameraViewSyncPolicy::TryGetLevelSequenceMessageContext(const FOnLevelSequenceMessage& InMessage, APlayerController*& OutPlayerController, UGenericLevelSequenceHandle*& OutLevelSequenceHandle, ULevelSequencePlayer*& OutLevelSequencePlayer) const
{
	OutPlayerController = GetOwnerPlayerController();
	if (!IsValid(OutPlayerController) || !OutPlayerController->IsLocalController())
	{
		return false;
	}

	OutLevelSequenceHandle = InMessage.LevelSequenceHandle;
	OutLevelSequencePlayer = IsValid(OutLevelSequenceHandle) ? OutLevelSequenceHandle->GetULevelSequencePlayer() : nullptr;
	return IsValid(OutLevelSequenceHandle) && IsValid(OutLevelSequencePlayer);
}

bool ULevelSequenceCameraViewSyncPolicy::TryGetPlayerCameraManagerView(APlayerController* InPlayerController, UCameraComponent* InSourceCameraComponent, FLevelSequenceCameraView& OutCameraView) const
{
	AActor* OwnerActor = GetOwnerActor();
	if (!IsValid(InPlayerController) || !IsValid(InPlayerController->PlayerCameraManager) || !IsValid(OwnerActor))
	{
		return false;
	}

	AActor* ViewTarget = InPlayerController->GetViewTarget();
	const AActor* SourceCameraOwner = IsValid(InSourceCameraComponent) ? InSourceCameraComponent->GetOwner() : nullptr;
	// PlayerCameraManager 只在当前 ViewTarget 仍是序列相机拥有者时可信，切回 Pawn 后不再作为序列最后帧。
	if (!IsValid(ViewTarget) || (IsValid(SourceCameraOwner) && ViewTarget != SourceCameraOwner))
	{
		return false;
	}

	if (!IsValid(SourceCameraOwner) && ViewTarget == OwnerActor)
	{
		return false;
	}

	const FMinimalViewInfo& CameraView = InPlayerController->PlayerCameraManager->GetCameraCacheView();
	OutCameraView.CameraComponent = InSourceCameraComponent;
	OutCameraView.CameraView = CameraView;
	OutCameraView.bHasCameraView = true;
	return true;
}

void ULevelSequenceCameraViewSyncPolicy::TrySyncObservedLevelSequenceCameraView(APlayerController* InPlayerController)
{
	if (!ShouldSyncObservedLevelSequenceCameraView(InPlayerController))
	{
		return;
	}

	// 直接观察模式只有检测到视角已经切回拥有者后才同步，避免打断序列自身的相机控制。
	SyncLevelSequenceCameraView(InPlayerController, CachedLevelSequenceCameraView);
	ResetLevelSequenceSyncState();
}

void ULevelSequenceCameraViewSyncPolicy::UnregisterLevelSequencePlayerUpdate()
{
	ULevelSequencePlayer* LevelSequencePlayer = LevelSequenceUpdatedPlayer.Get();
	if (IsValid(LevelSequencePlayer) && LevelSequenceUpdatedDelegateHandle.IsValid())
	{
		LevelSequencePlayer->OnSequenceUpdated().Remove(LevelSequenceUpdatedDelegateHandle);
	}

	LevelSequenceUpdatedPlayer.Reset();
	LevelSequenceUpdatedDelegateHandle.Reset();
}

void ULevelSequenceCameraViewSyncPolicy::UnregisterLevelSequenceListeners()
{
	LevelSequencePlayListenerHandle.Unregister();
	LevelSequencePlayReverseListenerHandle.Unregister();
	LevelSequencePauseListenerHandle.Unregister();
	LevelSequenceStopListenerHandle.Unregister();
	LevelSequenceSeekListenerHandle.Unregister();
	LevelSequenceFinishListenerHandle.Unregister();
}

void ULevelSequenceCameraViewSyncPolicy::UnregisterObservedLevelSequencePlayer()
{
	ULevelSequencePlayer* LevelSequencePlayer = ObservedLevelSequencePlayer.Get();
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->OnStop.RemoveAll(this);
		LevelSequencePlayer->OnFinished.RemoveAll(this);
	}

	ObservedLevelSequencePlayer.Reset();
}
