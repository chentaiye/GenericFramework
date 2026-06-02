// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraPoint/CameraPointBase.h"

#include "BPFunctions/BPFunctions_Gameplay.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"
#include "StaticFunctions/StaticFunctions_Object.h"

#if WITH_EDITOR
#include "LevelEditorSubsystem.h"
#include "LevelEditorViewport.h"
#include "Selection.h"
#endif

ACameraPointBase::ACameraPointBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	RootComponent = SceneComponent;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetSphereRadius(30.f);
	SphereComponent->SetEnableGravity(false);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SphereComponent->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringComponent");
	SpringArmComponent->TargetArmLength = 0.f;
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->SetupAttachment(SphereComponent);

#if WITH_EDITORONLY_DATA
	bIsSpatiallyLoaded = true;
#endif
}

#if WITH_EDITOR

void ACameraPointBase::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	const UWorld* World = GetWorld();
	if (!IsTemplate() && (!World || !World->IsGameWorld()))
	{
		/** 组件注册完成是关卡加载和编辑器重建后的稳定点，在这里恢复链接相机，避免常驻 Tick 监听。 */
		RefreshFromCameraActorLink(true);
	}
}

#endif

void ACameraPointBase::BeginPlay()
{
	Super::BeginPlay();
	OnCameraPointRegister.Broadcast(this);
}

void ACameraPointBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnCameraPointUnRegister.Broadcast(this);
	Super::EndPlay(EndPlayReason);
}

void ACameraPointBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

#if WITH_EDITOR

void ACameraPointBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		const FName PropertyName = PropertyChangedEvent.Property->GetFName();

		if (PropertyName == GET_MEMBER_NAME_CHECKED(ACameraPointBase, CameraActorLink))
		{
			LastRefreshedCameraActorLink = nullptr;
			RefreshFromCameraActorLink(true);
		}
	}
}

#endif

UCameraComponent* ACameraPointBase::GetCameraComponent_Implementation()
{
	return nullptr;
}

void ACameraPointBase::SetCameraComponent_Implementation(UCameraComponent* InCameraComponent)
{
}

void ACameraPointBase::RefreshFocus()
{
	if (!IsValid(SpringArmComponent))
	{
		return;
	}

	FHitResult HitResult;
	UBPFunctions_Gameplay::GetActorForwardHitResult(this, HitResult);
	if (HitResult.bBlockingHit)
	{
		/** 焦点命中点成为相机点 Actor 位置，弹簧臂长度保存相机到焦点的距离。 */
		SetActorLocation(HitResult.Location);
		SpringArmComponent->TargetArmLength = HitResult.Distance;
	}
}

#if WITH_EDITOR

void ACameraPointBase::RefreshCameraActorLink()
{
	LastRefreshedCameraActorLink = nullptr;
	RefreshFromCameraActorLink(true);
}

void ACameraPointBase::CopyFromViewportCamera()
{
	if (!GCurrentLevelEditingViewportClient || !IsValid(SpringArmComponent))
	{
		return;
	}

	Modify();
	SpringArmComponent->Modify();

	SpringArmComponent->TargetArmLength = 0.f;

	const FVector Location = GCurrentLevelEditingViewportClient->GetViewLocation();
	const FRotator Rotation = GCurrentLevelEditingViewportClient->GetViewRotation();

	/** 视口相机直接写入根节点后再刷新焦点，避免复制时保留旧 SpringArm 偏移。 */
	SetActorLocation(NormalizeCameraLocation(Location));
	SetActorRotation(NormalizeCameraRotation(Rotation));
	RefreshFocus();
}

void ACameraPointBase::ToggleLock()
{
	GEditor->ToggleSelectedActorMovementLock();
}

void ACameraPointBase::PilotCamera()
{
	NormalizeForEditorPilot();

	if (ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>())
	{
		LevelEditorSubsystem->PilotLevelActor(this);
	}
}

void ACameraPointBase::EjectPilotCamera()
{
	if (ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>())
	{
		LevelEditorSubsystem->EjectPilotLevelActor();
	}

	Modify();
	RefreshFocus();
}

void ACameraPointBase::DuplicateFromCamera(const TSoftObjectPtr<ACameraActor>& InCameraActor)
{
	if (!InCameraActor.IsNull())
	{
		ACameraActor* CameraActor = FStaticFunctions_Object::LoadObject<ACameraActor>(InCameraActor);
		DuplicateFromCamera(CameraActor);
	}
}

void ACameraPointBase::DuplicateFromCamera(const ACameraActor* InCameraActor)
{
	ApplyCameraActor(InCameraActor, true);
}

void ACameraPointBase::DuplicateFromCamera(const UCameraComponent* InCameraComponent)
{
	if (IsValid(InCameraComponent))
	{
		UCameraComponent* DuplicateCameraComponent = DuplicateObject<UCameraComponent>(InCameraComponent, this);
		SetCameraComponent(DuplicateCameraComponent);

		TArray<AActor*> SelectedActors;
		TArray<UActorComponent*> SelectedComponents;
		GEditor->GetSelectedActors()->GetSelectedObjects(SelectedActors);
		GEditor->GetSelectedComponents()->GetSelectedObjects(SelectedComponents);

		GEditor->SelectNone(false, true);
		for (AActor* SelectedActor : SelectedActors)
		{
			GEditor->SelectActor(SelectedActor, true, true);
		}
		for (UActorComponent* SelectedComponent : SelectedComponents)
		{
			GEditor->SelectComponent(SelectedComponent, true, true);
		}
	}
}

bool ACameraPointBase::RefreshFromCameraActorLink(bool bAllowSynchronousLoad)
{
	if (CameraActorLink.IsNull())
	{
		LastRefreshedCameraActorLink = nullptr;
		return true;
	}

	ACameraActor* CameraActor = CameraActorLink.Get();
	if (!IsValid(CameraActor) && bAllowSynchronousLoad && CameraActorLink.IsPending())
	{
		CameraActor = CameraActorLink.LoadSynchronous();
	}

	if (!IsValid(CameraActor))
	{
		/** 软引用尚未解析时不清空旧数据，后续属性变更或手动刷新可再次尝试。 */
		return false;
	}

	if (LastRefreshedCameraActorLink.Get() != CameraActor)
	{
		ApplyCameraActor(CameraActor, bAllowSynchronousLoad);
		LastRefreshedCameraActorLink = CameraActor;
	}

	return true;
}

void ACameraPointBase::NormalizeForEditorPilot()
{
	if (!IsValid(SpringArmComponent))
	{
		return;
	}

	const UCameraComponent* CameraComponent = GetCameraComponent();
	const FVector CameraWorldLocation = IsValid(CameraComponent) ? CameraComponent->GetComponentLocation() : GetActorLocation();
	const FRotator CameraWorldRotation = IsValid(CameraComponent) ? CameraComponent->GetComponentRotation() : GetActorRotation();

	/** Pilot 时编辑器锁定 Actor 根节点，所以把相机组件的世界姿态折叠回根节点再清空臂长。 */
	Modify();
	SpringArmComponent->Modify();

	SpringArmComponent->TargetArmLength = 0.f;
	SetActorLocation(NormalizeCameraLocation(CameraWorldLocation));
	SetActorRotation(NormalizeCameraRotation(CameraWorldRotation));

	SpringArmComponent->UpdateComponentToWorld();
	if (UCameraComponent* MutableCameraComponent = GetCameraComponent())
	{
		MutableCameraComponent->UpdateComponentToWorld();
	}
}

void ACameraPointBase::ApplyCameraActor(const ACameraActor* InCameraActor, bool bRecordTransaction)
{
	if (!IsValid(InCameraActor))
	{
		return;
	}

	if (bRecordTransaction)
	{
		Modify();
		if (IsValid(SpringArmComponent))
		{
			SpringArmComponent->Modify();
		}
	}

	SetActorLocation(NormalizeCameraLocation(InCameraActor->GetActorLocation()));
	SetActorRotation(NormalizeCameraRotation(InCameraActor->GetActorRotation()));

	DuplicateFromCamera(InCameraActor->GetCameraComponent());
	RefreshFocus();

	LastRefreshedCameraActorLink = const_cast<ACameraActor*>(InCameraActor);
}

#endif

void ACameraPointBase::CopyCameraComponentProperties(const UCameraComponent* InCameraComponent, UCameraComponent* OutCameraComponent) const
{
	if (!IsValid(InCameraComponent) || !IsValid(OutCameraComponent))
	{
		return;
	}

	OutCameraComponent->SetProjectionMode(InCameraComponent->ProjectionMode);
	OutCameraComponent->SetFieldOfView(InCameraComponent->FieldOfView);
	OutCameraComponent->SetAspectRatio(InCameraComponent->AspectRatio);

	OutCameraComponent->SetConstraintAspectRatio(InCameraComponent->bConstrainAspectRatio);
	OutCameraComponent->bUsePawnControlRotation = InCameraComponent->bUsePawnControlRotation;
	OutCameraComponent->SetPostProcessBlendWeight(InCameraComponent->PostProcessBlendWeight);
	OutCameraComponent->SetAspectRatioAxisConstraint(InCameraComponent->AspectRatioAxisConstraint);
	OutCameraComponent->bOverrideAspectRatioAxisConstraint = InCameraComponent->bOverrideAspectRatioAxisConstraint;
	OutCameraComponent->bLockToHmd = InCameraComponent->bLockToHmd;
	OutCameraComponent->SetUseFieldOfViewForLOD(InCameraComponent->bUseFieldOfViewForLOD);

	OutCameraComponent->SetOrthoWidth(InCameraComponent->OrthoWidth);
	OutCameraComponent->PostProcessSettings = InCameraComponent->PostProcessSettings;
}

FVector ACameraPointBase::NormalizeCameraLocation(const FVector& InLocation)
{
	return InLocation;
}

FRotator ACameraPointBase::NormalizeCameraRotation(const FRotator& InRotation)
{
	FRotator Rotation;
	Rotation.Pitch = FMath::Clamp(InRotation.Pitch, -89.9f, 89.9f);
	Rotation.Yaw = InRotation.Yaw + InRotation.Roll;
	Rotation.Roll = 0;
	Rotation.Normalize();

	return Rotation;
}
