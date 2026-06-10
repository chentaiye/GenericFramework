// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/WorldWidgetComponent.h"

#include "Base/GenericWidget.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/SWidget.h"
#include "Widgets/SWindow.h"

namespace
{
	bool IsValidWorldWidgetSize(const FVector2D& InSize)
	{
		return InSize.X > 0.0 && InSize.Y > 0.0;
	}

	FVector2D MakeWorldWidgetDrawSize(const FVector2D& InDesiredSize)
	{
		return FVector2D(
			FMath::Max(1.0, FMath::RoundToDouble(InDesiredSize.X)),
			FMath::Max(1.0, FMath::RoundToDouble(InDesiredSize.Y)));
	}

	FVector2D GetSlateWindowDesiredSize(const TSharedPtr<SWindow>& InSlateWindow)
	{
		if (!InSlateWindow.IsValid())
		{
			return FVector2D::ZeroVector;
		}

		InSlateWindow->SlatePrepass();
		const TSharedRef<SWidget> WindowContent = InSlateWindow->GetContent();
		WindowContent->SlatePrepass();
		return WindowContent->GetDesiredSize();
	}

	FVector2D GetUserWidgetDesiredSize(UGenericWidget* InWidget)
	{
		if (!IsValid(InWidget))
		{
			return FVector2D::ZeroVector;
		}

		InWidget->InvalidateLayoutAndVolatility();
		InWidget->ForceLayoutPrepass();

		FVector2D DesiredSize = InWidget->GetDesiredSize();
		if (IsValidWorldWidgetSize(DesiredSize))
		{
			return DesiredSize;
		}

		const TSharedPtr<SWidget> CachedWidget = InWidget->GetCachedWidget();
		if (CachedWidget.IsValid())
		{
			CachedWidget->SlatePrepass();
			DesiredSize = CachedWidget->GetDesiredSize();
		}

		return DesiredSize;
	}

}

UWorldWidgetComponent::UWorldWidgetComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	SetEditTimeUsable(true);
	SetDrawAtDesiredSize(false);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> GenericWorldWidgetMaterialFinder(
		TEXT("/GenericWidgetFramework/Material/Widget3DPassThrough_Translucent_OneSided.Widget3DPassThrough_Translucent_OneSided"));
	if (GenericWorldWidgetMaterialFinder.Succeeded())
	{
		SetMaterial(0, GenericWorldWidgetMaterialFinder.Object);
	}

	SynchronizePaintMethod();
	SynchronizeAnchor();
	SynchronizeFollowCameraTick();
}

EWorldWidgetPaintMethod UWorldWidgetComponent::GetPaintMethod() const
{
	return PaintMethod;
}

void UWorldWidgetComponent::SetPaintMethod(EWorldWidgetPaintMethod InPaintMethod)
{
	if (PaintMethod == InPaintMethod)
	{
		return;
	}

	PaintMethod = InPaintMethod;
	SynchronizePaintMethod();
	SynchronizeWorldWidget();
	SynchronizeFollowCameraTick();
	UpdateFollowCameraTransform();

	BroadcastComponentChanged();
}

FVector2D UWorldWidgetComponent::GetAnchor() const
{
	return Anchor;
}

void UWorldWidgetComponent::SetAnchor(FVector2D InAnchor)
{
	if (Anchor.Equals(InAnchor))
	{
		return;
	}

	Anchor = InAnchor;
	SynchronizeAnchor();

	BroadcastComponentChanged();
}

UGenericWidget* UWorldWidgetComponent::GetWorldWidget() const
{
	return WorldWidget;
}

void UWorldWidgetComponent::SetWorldWidget(UGenericWidget* InWidget)
{
	if (WorldWidget == InWidget)
	{
		return;
	}

	WorldWidget = InWidget;
	SynchronizeWorldWidget();

	BroadcastComponentChanged();
}

int32 UWorldWidgetComponent::GetInputPriority() const
{
	return InputPriority;
}

void UWorldWidgetComponent::SetInputPriority(int32 InInputPriority)
{
	if (InputPriority == InInputPriority)
	{
		return;
	}

	InputPriority = InInputPriority;
	BroadcastComponentChanged();
}

void UWorldWidgetComponent::OnRegister()
{
	SynchronizePaintMethod();
	SynchronizeAnchor();
	SynchronizeWorldWidget();
	Super::OnRegister();
	SynchronizeWorldWidgetSize();
	SynchronizeFollowCameraTick();
	UpdateFollowCameraTransform();

	BroadcastComponentRegistered();
}

void UWorldWidgetComponent::OnUnregister()
{
	RestoreFollowCameraBaseScale();
	BroadcastComponentUnregistered();
	Super::OnUnregister();
}

void UWorldWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateFollowCameraTransform();
}

#if WITH_EDITOR
void UWorldWidgetComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SynchronizePaintMethod();
	SynchronizeAnchor();
	SynchronizeWorldWidget();
	SynchronizeWorldWidgetSize();
	SynchronizeFollowCameraTick();
	UpdateFollowCameraTransform();
	BroadcastComponentChanged();
}
#endif

void UWorldWidgetComponent::SynchronizePaintMethod()
{
	SetWidgetSpace(PaintMethod == EWorldWidgetPaintMethod::World ? EWidgetSpace::World : EWidgetSpace::Screen);
}

void UWorldWidgetComponent::SynchronizeAnchor()
{
	SetPivot(Anchor);
}

void UWorldWidgetComponent::SynchronizeWorldWidget()
{
	SetDrawAtDesiredSize(false);
	SetWidget(WorldWidget);
	SynchronizeWorldWidgetSize();
	RequestRenderUpdate();
	MarkRenderStateDirty();
}

void UWorldWidgetComponent::SynchronizeWorldWidgetSize()
{
	if (!IsValid(WorldWidget))
	{
		return;
	}

	UpdateWidget();

	FVector2D DesiredSize = GetSlateWindowDesiredSize(GetSlateWindow());
	if (!IsValidWorldWidgetSize(DesiredSize))
	{
		DesiredSize = GetUserWidgetDesiredSize(WorldWidget);
	}

	if (IsValidWorldWidgetSize(DesiredSize))
	{
		SetDrawSize(MakeWorldWidgetDrawSize(DesiredSize));
		RequestRenderUpdate();
		MarkRenderStateDirty();
	}
}

void UWorldWidgetComponent::SynchronizeFollowCameraTick()
{
	const bool bShouldFollowCamera = PaintMethod == EWorldWidgetPaintMethod::World
		&& (bEnableFollowCameraPitch || bEnableFollowCameraYaw || bEnableFollowCameraRoll || bEnableFollowCameraScale);

	if (PaintMethod != EWorldWidgetPaintMethod::World || !bEnableFollowCameraScale)
	{
		RestoreFollowCameraBaseScale();
	}

	if (IsRegistered())
	{
		SetComponentTickEnabled(bShouldFollowCamera);
	}
	else
	{
		PrimaryComponentTick.SetTickFunctionEnable(bShouldFollowCamera);
	}
}

void UWorldWidgetComponent::UpdateFollowCameraTransform()
{
	if (PaintMethod != EWorldWidgetPaintMethod::World)
	{
		RestoreFollowCameraBaseScale();
		return;
	}

	const bool bShouldUpdateRotation = bEnableFollowCameraPitch || bEnableFollowCameraYaw || bEnableFollowCameraRoll;
	const bool bShouldUpdateScale = bEnableFollowCameraScale;
	if (!bShouldUpdateRotation && !bShouldUpdateScale)
	{
		RestoreFollowCameraBaseScale();
		return;
	}

	FVector CameraLocation = FVector::ZeroVector;
	FRotator CameraRotation = FRotator::ZeroRotator;
	APlayerController* PlayerController = nullptr;
	if (!TryGetFollowCameraView(CameraLocation, CameraRotation, PlayerController))
	{
		return;
	}

	TOptional<float> TargetScale;
	if (bEnableFollowCameraScale)
	{
		float CalculatedScale = 1.0f;
		if (CalculateFollowCameraScale(PlayerController, CameraRotation, CalculatedScale))
		{
			TargetScale = CalculatedScale;
		}
	}

	UpdateFollowCameraTransformForView(CameraLocation, CameraRotation, TargetScale);
}

void UWorldWidgetComponent::UpdateFollowCameraTransformForView(const FVector& InCameraLocation, const FRotator& InCameraRotation, TOptional<float> InTargetScale)
{
	if (PaintMethod != EWorldWidgetPaintMethod::World)
	{
		RestoreFollowCameraBaseScale();
		return;
	}

	const bool bShouldUpdateRotation = bEnableFollowCameraPitch || bEnableFollowCameraYaw || bEnableFollowCameraRoll;
	const bool bShouldUpdateScale = bEnableFollowCameraScale;
	if (!bShouldUpdateRotation && !bShouldUpdateScale)
	{
		RestoreFollowCameraBaseScale();
		return;
	}

	if (bShouldUpdateRotation)
	{
		const FVector ToCamera = (InCameraLocation - GetComponentLocation()).GetSafeNormal();
		if (ToCamera.IsNearlyZero())
		{
			return;
		}

		const FVector CameraUpVector = InCameraRotation.Quaternion().GetUpVector();
		const FRotator TargetRotation = FRotationMatrix::MakeFromXZ(ToCamera, CameraUpVector).Rotator();
		FRotator NewRotation = GetComponentRotation();
		NewRotation.Pitch = bEnableFollowCameraPitch ? TargetRotation.Pitch : NewRotation.Pitch;
		NewRotation.Yaw = bEnableFollowCameraYaw ? TargetRotation.Yaw : NewRotation.Yaw;
		NewRotation.Roll = bEnableFollowCameraRoll ? TargetRotation.Roll : NewRotation.Roll;
		NewRotation.Normalize();

		SetWorldRotation(NewRotation);
	}

	if (!bShouldUpdateScale)
	{
		RestoreFollowCameraBaseScale();
		return;
	}

	CacheFollowCameraBaseScale();

	if (InTargetScale.IsSet())
	{
		SetRelativeScale3D(FollowCameraBaseRelativeScale * InTargetScale.GetValue());
		bAppliedFollowCameraScale = true;
	}
}

bool UWorldWidgetComponent::TryGetFollowCameraView(FVector& OutCameraLocation, FRotator& OutCameraRotation, APlayerController*& OutPlayerController) const
{
	UWorld* World = GetWorld();
	if (!World || World->IsNetMode(NM_DedicatedServer))
	{
		return false;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!IsValid(PlayerController) || !IsValid(PlayerController->PlayerCameraManager))
	{
		return false;
	}

	OutPlayerController = PlayerController;
	OutCameraLocation = PlayerController->PlayerCameraManager->GetCameraLocation();
	OutCameraRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	return true;
}

bool UWorldWidgetComponent::CalculateFollowCameraScale(APlayerController* InPlayerController, const FRotator& InCameraRotation, float& OutScale) const
{
	if (!IsValid(InPlayerController))
	{
		return false;
	}

	const FVector ComponentLocation = GetComponentLocation();
	const FVector CameraUpVector = InCameraRotation.Quaternion().GetUpVector();
	FVector2D ComponentScreenLocation = FVector2D::ZeroVector;
	FVector2D UnitOffsetScreenLocation = FVector2D::ZeroVector;
	if (!InPlayerController->ProjectWorldLocationToScreen(ComponentLocation, ComponentScreenLocation, true)
		|| !InPlayerController->ProjectWorldLocationToScreen(ComponentLocation + CameraUpVector, UnitOffsetScreenLocation, true))
	{
		return false;
	}

	const double PixelsPerWorldUnit = FVector2D::Distance(ComponentScreenLocation, UnitOffsetScreenLocation);
	if (PixelsPerWorldUnit <= UE_SMALL_NUMBER)
	{
		return false;
	}

	OutScale = FMath::Max(0.0f, FollowCameraScale) / static_cast<float>(PixelsPerWorldUnit);
	return true;
}

void UWorldWidgetComponent::CacheFollowCameraBaseScale()
{
	if (bAppliedFollowCameraScale)
	{
		return;
	}

	FollowCameraBaseRelativeScale = GetRelativeScale3D();
	bHasFollowCameraBaseRelativeScale = true;
}

void UWorldWidgetComponent::RestoreFollowCameraBaseScale()
{
	if (bAppliedFollowCameraScale && bHasFollowCameraBaseRelativeScale)
	{
		SetRelativeScale3D(FollowCameraBaseRelativeScale);
	}

	bAppliedFollowCameraScale = false;
	bHasFollowCameraBaseRelativeScale = false;
}

void UWorldWidgetComponent::BroadcastComponentRegistered()
{
	OnComponentRegistered.Broadcast(this);
}

void UWorldWidgetComponent::BroadcastComponentUnregistered()
{
	OnComponentUnregistered.Broadcast(this);
}

void UWorldWidgetComponent::BroadcastComponentChanged()
{
	OnComponentChanged.Broadcast(this);
}
