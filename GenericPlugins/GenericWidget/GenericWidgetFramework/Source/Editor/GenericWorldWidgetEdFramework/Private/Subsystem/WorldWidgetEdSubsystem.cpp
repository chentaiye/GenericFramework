// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/WorldWidgetEdSubsystem.h"

#include "Base/GenericWidget.h"
#include "Base/WorldWidgetComponent.h"
#include "Base/WorldWidgetShared.h"
#include "Blueprint/UserWidget.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "Framework/Application/IInputProcessor.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "LevelEditorViewport.h"
#include "SLevelViewport.h"
#include "SceneView.h"
#include "UObject/UObjectIterator.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SViewport.h"
#include "Widgets/SWindow.h"

class FWorldWidgetEditorInputProcessor : public IInputProcessor
{
public:
	explicit FWorldWidgetEditorInputProcessor(UWorldWidgetEdSubsystem* InSubsystem)
		: Subsystem(InSubsystem)
	{
	}

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override
	{
		(void)DeltaTime;
		(void)SlateApp;
		(void)Cursor;
	}

	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override
	{
		(void)SlateApp;
		if (UWorldWidgetEdSubsystem* WorldWidgetEdSubsystem = Subsystem.Get())
		{
			return WorldWidgetEdSubsystem->HandleEditorMouseButtonDownEvent(MouseEvent);
		}

		return false;
	}

	virtual const TCHAR* GetDebugName() const override
	{
		return TEXT("WorldWidgetEditorInputProcessor");
	}

private:
	TWeakObjectPtr<UWorldWidgetEdSubsystem> Subsystem;
};

namespace
{
	bool ProjectWorldWidgetToPreviewCanvas(const TWeakPtr<SLevelViewport>& InViewport, const TWeakPtr<SConstraintCanvas>& InCanvas, UWorldWidgetComponent* InComponent, FVector2D& OutPreviewPosition)
	{
		const TSharedPtr<SLevelViewport> LevelViewport = InViewport.Pin();
		if (!LevelViewport.IsValid() || !IsValid(InComponent))
		{
			return false;
		}

		FLevelEditorViewportClient& ViewportClient = LevelViewport->GetLevelViewportClient();
		if (!ViewportClient.Viewport)
		{
			return false;
		}

		const TSharedPtr<SViewport> ViewportWidget = LevelViewport->GetViewportWidget().Pin();
		if (!ViewportWidget.IsValid())
		{
			return false;
		}

		const FGeometry& ViewportGeometry = ViewportWidget->GetCachedGeometry();
		const FVector2D ViewportLocalSize = ViewportGeometry.GetLocalSize();
		if (ViewportLocalSize.X <= 0.0 || ViewportLocalSize.Y <= 0.0)
		{
			return false;
		}

		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			ViewportClient.Viewport,
			ViewportClient.GetScene(),
			ViewportClient.EngineShowFlags));

		FSceneView* View = ViewportClient.CalcSceneView(&ViewFamily);
		if (!View)
		{
			return false;
		}

		const FIntRect ViewRect = View->UnscaledViewRect;
		const FIntPoint ViewRectSize = ViewRect.Size();
		if (ViewRectSize.X <= 0 || ViewRectSize.Y <= 0)
		{
			return false;
		}

		FVector2D ScreenPosition;
		if (!FSceneView::ProjectWorldToScreen(
			InComponent->GetComponentLocation(),
			ViewRect,
			View->ViewMatrices.GetViewProjectionMatrix(),
			ScreenPosition))
		{
			return false;
		}

		const FVector2D ViewRelativePosition(
			ScreenPosition.X - static_cast<double>(ViewRect.Min.X),
			ScreenPosition.Y - static_cast<double>(ViewRect.Min.Y));
		const FVector2D LocalPosition(
			ViewRelativePosition.X / static_cast<double>(ViewRectSize.X) * ViewportLocalSize.X,
			ViewRelativePosition.Y / static_cast<double>(ViewRectSize.Y) * ViewportLocalSize.Y);

		FVector2D PreviewLocalPosition = LocalPosition;
		const TSharedPtr<SConstraintCanvas> PreviewCanvas = InCanvas.Pin();
		if (PreviewCanvas.IsValid())
		{
			const FGeometry& PreviewGeometry = PreviewCanvas->GetCachedGeometry();
			if (PreviewGeometry.GetLocalSize().X > 0.0 && PreviewGeometry.GetLocalSize().Y > 0.0)
			{
				PreviewLocalPosition = PreviewGeometry.AbsoluteToLocal(ViewportGeometry.LocalToAbsolute(LocalPosition));
			}
		}

		OutPreviewPosition = InComponent->ModifyProjectedLocalPosition(ViewportGeometry, PreviewLocalPosition);
		return true;
	}

	bool GetPreviewCanvasLocalPosition(const TWeakPtr<SLevelViewport>& InViewport, const TWeakPtr<SConstraintCanvas>& InCanvas, const FVector2D& InScreenSpacePosition, FVector2D& OutLocalPosition)
	{
		const TSharedPtr<SLevelViewport> LevelViewport = InViewport.Pin();
		if (!LevelViewport.IsValid())
		{
			return false;
		}

		const TSharedPtr<SViewport> ViewportWidget = LevelViewport->GetViewportWidget().Pin();
		if (!ViewportWidget.IsValid())
		{
			return false;
		}

		const FGeometry& ViewportGeometry = ViewportWidget->GetCachedGeometry();
		const FVector2D ViewportLocalSize = ViewportGeometry.GetLocalSize();
		if (ViewportLocalSize.X <= 0.0 || ViewportLocalSize.Y <= 0.0)
		{
			return false;
		}

		const FVector2D ViewportLocalPosition = ViewportGeometry.AbsoluteToLocal(InScreenSpacePosition);
		if (ViewportLocalPosition.X < 0.0
			|| ViewportLocalPosition.Y < 0.0
			|| ViewportLocalPosition.X > ViewportLocalSize.X
			|| ViewportLocalPosition.Y > ViewportLocalSize.Y)
		{
			return false;
		}

		OutLocalPosition = ViewportLocalPosition;
		const TSharedPtr<SConstraintCanvas> PreviewCanvas = InCanvas.Pin();
		if (PreviewCanvas.IsValid())
		{
			const FGeometry& PreviewGeometry = PreviewCanvas->GetCachedGeometry();
			if (PreviewGeometry.GetLocalSize().X > 0.0 && PreviewGeometry.GetLocalSize().Y > 0.0)
			{
				OutLocalPosition = PreviewGeometry.AbsoluteToLocal(InScreenSpacePosition);
			}
		}

		return true;
	}

	FVector2D GetWorldWidgetDesiredSize(const UGenericWidget* InWidget)
	{
		if (!IsValid(InWidget))
		{
			return FVector2D::ZeroVector;
		}

		const_cast<UGenericWidget*>(InWidget)->InvalidateLayoutAndVolatility();
		const_cast<UGenericWidget*>(InWidget)->ForceLayoutPrepass();
		FVector2D DesiredSize = InWidget->GetDesiredSize();

		if (DesiredSize.X <= 0.0 || DesiredSize.Y <= 0.0)
		{
			TSharedPtr<SWidget> SlateWidget = InWidget->GetCachedWidget();
			if (SlateWidget.IsValid())
			{
				SlateWidget->SlatePrepass();
				DesiredSize = SlateWidget->GetDesiredSize();
			}
		}

		return DesiredSize;
	}

	FVector2D GetSlateWidgetDesiredSize(const TSharedPtr<SWidget>& InWidget)
	{
		if (!InWidget.IsValid())
		{
			return FVector2D::ZeroVector;
		}

		InWidget->SlatePrepass();
		return InWidget->GetDesiredSize();
	}

	FVector2D MakePreviewDrawSize(const FVector2D& InSize)
	{
		return FVector2D(
			FMath::Max(1.0, FMath::RoundToDouble(InSize.X)),
			FMath::Max(1.0, FMath::RoundToDouble(InSize.Y)));
	}

	FVector2D GetComponentDrawSize(const UWorldWidgetComponent* InComponent)
	{
		if (!IsValid(InComponent))
		{
			return FVector2D(1.0, 1.0);
		}

		FVector2D DrawSize = FVector2D::ZeroVector;
		if (TSharedPtr<SWindow> WorldWidgetWindow = InComponent->GetSlateWindow())
		{
			WorldWidgetWindow->SlatePrepass();
			const TSharedRef<SWidget> WorldWidgetContent = WorldWidgetWindow->GetContent();
			WorldWidgetContent->SlatePrepass();
			DrawSize = WorldWidgetContent->GetDesiredSize();
		}

		if (DrawSize.X <= 0.0 || DrawSize.Y <= 0.0)
		{
			DrawSize = GetWorldWidgetDesiredSize(InComponent->GetWorldWidget());
		}

		if (DrawSize.X <= 0.0 || DrawSize.Y <= 0.0)
		{
			DrawSize = InComponent->GetCurrentDrawSize();
		}

		if (DrawSize.X <= 0.0 || DrawSize.Y <= 0.0)
		{
			DrawSize = InComponent->GetDrawSize();
		}

		return FVector2D(FMath::Max(1.0, DrawSize.X), FMath::Max(1.0, DrawSize.Y));
	}

	FVector2D GetPreviewDrawSize(const TWeakObjectPtr<UWorldWidgetComponent> InComponent, const TWeakObjectPtr<UGenericWidget> InPreviewWidget, const TWeakPtr<SWidget> InPreviewSlateWidget)
	{
		FVector2D DrawSize = GetSlateWidgetDesiredSize(InPreviewSlateWidget.Pin());
		if (DrawSize.X <= 0.0 || DrawSize.Y <= 0.0)
		{
			DrawSize = GetWorldWidgetDesiredSize(InPreviewWidget.Get());
		}

		if (DrawSize.X <= 0.0 || DrawSize.Y <= 0.0)
		{
			DrawSize = GetComponentDrawSize(InComponent.Get());
		}

		return MakePreviewDrawSize(DrawSize);
	}

	FOptionalSize GetPreviewWidthOverride(const TWeakObjectPtr<UWorldWidgetComponent> InComponent, const TWeakObjectPtr<UGenericWidget> InPreviewWidget, const TWeakPtr<SWidget> InPreviewSlateWidget)
	{
		return FOptionalSize(GetPreviewDrawSize(InComponent, InPreviewWidget, InPreviewSlateWidget).X);
	}

	FOptionalSize GetPreviewHeightOverride(const TWeakObjectPtr<UWorldWidgetComponent> InComponent, const TWeakObjectPtr<UGenericWidget> InPreviewWidget, const TWeakPtr<SWidget> InPreviewSlateWidget)
	{
		return FOptionalSize(GetPreviewDrawSize(InComponent, InPreviewWidget, InPreviewSlateWidget).Y);
	}

	void RefreshWorldWidgetComponentForPreview(UWorldWidgetComponent* InComponent)
	{
		if (!IsValid(InComponent))
		{
			return;
		}

		UGenericWidget* SourceWidget = InComponent->GetWorldWidget();
		if (!IsValid(SourceWidget))
		{
			InComponent->SetWidget(nullptr);
			return;
		}

		InComponent->SetDrawAtDesiredSize(false);
		InComponent->SetWidget(InComponent->GetWidgetSpace() == EWidgetSpace::Screen ? nullptr : SourceWidget);

		const FVector2D DrawSize = GetWorldWidgetDesiredSize(SourceWidget);
		if (DrawSize.X > 0.0 && DrawSize.Y > 0.0)
		{
			InComponent->SetDrawSize(FVector2D(FMath::RoundToDouble(DrawSize.X), FMath::RoundToDouble(DrawSize.Y)));
		}

		InComponent->RequestRenderUpdate();
		InComponent->MarkRenderStateDirty();
	}

	EVisibility GetPreviewVisibility(const TWeakPtr<SLevelViewport>& InViewport, const TWeakPtr<SConstraintCanvas>& InCanvas, TWeakObjectPtr<UWorldWidgetComponent> InComponent)
	{
		UWorldWidgetComponent* Component = InComponent.Get();
		FVector2D ScreenPosition;
		return IsValid(Component)
			&& Component->GetWidgetSpace() == EWidgetSpace::Screen
			&& Component->IsVisible()
			&& ProjectWorldWidgetToPreviewCanvas(InViewport, InCanvas, Component, ScreenPosition)
				? EVisibility::HitTestInvisible
				: EVisibility::Collapsed;
	}

	FMargin GetPreviewOffset(const TWeakPtr<SLevelViewport>& InViewport, const TWeakPtr<SConstraintCanvas>& InCanvas, TWeakObjectPtr<UWorldWidgetComponent> InComponent, const TWeakObjectPtr<UGenericWidget> InPreviewWidget, const TWeakPtr<SWidget> InPreviewSlateWidget)
	{
		UWorldWidgetComponent* Component = InComponent.Get();
		if (!IsValid(Component))
		{
			return FMargin();
		}

		FVector2D ScreenPosition;
		if (!ProjectWorldWidgetToPreviewCanvas(InViewport, InCanvas, Component, ScreenPosition))
		{
			return FMargin();
		}

		const FVector2D DrawSize = GetPreviewDrawSize(InComponent, InPreviewWidget, InPreviewSlateWidget);
		return FMargin(ScreenPosition.X, ScreenPosition.Y, DrawSize.X, DrawSize.Y);
	}

	bool IsUsableEditorFollowCameraViewport(const FLevelEditorViewportClient* InViewportClient, const UWorld* InWorld)
	{
		return InViewportClient
			&& InViewportClient->Viewport
			&& InViewportClient->GetWorld() == InWorld
			&& InViewportClient->IsPerspective();
	}

	FLevelEditorViewportClient* FindEditorFollowCameraViewport(UWorld* InWorld)
	{
		if (!GEditor || !InWorld)
		{
			return nullptr;
		}

		if (IsUsableEditorFollowCameraViewport(GCurrentLevelEditingViewportClient, InWorld))
		{
			return GCurrentLevelEditingViewportClient;
		}

		if (IsUsableEditorFollowCameraViewport(GLastKeyLevelEditingViewportClient, InWorld))
		{
			return GLastKeyLevelEditingViewportClient;
		}

		for (FLevelEditorViewportClient* ViewportClient : GEditor->GetLevelViewportClients())
		{
			if (IsUsableEditorFollowCameraViewport(ViewportClient, InWorld))
			{
				return ViewportClient;
			}
		}

		return nullptr;
	}

	TOptional<float> CalculateEditorFollowCameraTargetScale(FLevelEditorViewportClient* InViewportClient, UWorldWidgetComponent* InComponent)
	{
		if (!InViewportClient || !InViewportClient->Viewport || !IsValid(InComponent) || !InComponent->bEnableFollowCameraScale)
		{
			return TOptional<float>();
		}

		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			InViewportClient->Viewport,
			InViewportClient->GetScene(),
			InViewportClient->EngineShowFlags));

		FSceneView* View = InViewportClient->CalcSceneView(&ViewFamily);
		if (!View)
		{
			return TOptional<float>();
		}

		const FIntRect ViewRect = View->UnscaledViewRect;
		const FIntPoint ViewRectSize = ViewRect.Size();
		if (ViewRectSize.X <= 0 || ViewRectSize.Y <= 0)
		{
			return TOptional<float>();
		}

		const FVector ComponentLocation = InComponent->GetComponentLocation();
		const FVector CameraUpVector = InViewportClient->GetViewRotation().Quaternion().GetUpVector();
		FVector2D ComponentScreenLocation = FVector2D::ZeroVector;
		FVector2D UnitOffsetScreenLocation = FVector2D::ZeroVector;
		if (!FSceneView::ProjectWorldToScreen(ComponentLocation, ViewRect, View->ViewMatrices.GetViewProjectionMatrix(), ComponentScreenLocation)
			|| !FSceneView::ProjectWorldToScreen(ComponentLocation + CameraUpVector, ViewRect, View->ViewMatrices.GetViewProjectionMatrix(), UnitOffsetScreenLocation))
		{
			return TOptional<float>();
		}

		const double PixelsPerWorldUnit = FVector2D::Distance(ComponentScreenLocation, UnitOffsetScreenLocation);
		if (PixelsPerWorldUnit <= UE_SMALL_NUMBER)
		{
			return TOptional<float>();
		}

		return FMath::Max(0.0f, InComponent->FollowCameraScale) / static_cast<float>(PixelsPerWorldUnit);
	}

}

bool UWorldWidgetEdSubsystem::RegisterWorldWidget(UWorldWidgetComponent* InComponent)
{
	if (!IsValid(InComponent) || !IsComponentOwnedByWorld(InComponent))
	{
		return false;
	}

	if (FWorldWidgetRegistry::AddComponent(RegisteredComponents, InComponent))
	{
		RefreshWorldWidgetComponentForPreview(InComponent);
		MarkEditorPreviewDirty();
		return true;
	}

	return false;
}

bool UWorldWidgetEdSubsystem::UnregisterWorldWidget(UWorldWidgetComponent* InComponent)
{
	const bool bRemoved = FWorldWidgetRegistry::RemoveComponent(RegisteredComponents, InComponent);
	if (bRemoved)
	{
		MarkEditorPreviewDirty();
	}

	return bRemoved;
}

TArray<UWorldWidgetComponent*> UWorldWidgetEdSubsystem::GetAllWorldWidgets() const
{
	return FWorldWidgetRegistry::GetAllComponents(RegisteredComponents);
}

void UWorldWidgetEdSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UWorldWidgetComponent::OnComponentRegistered.AddUObject(this, &ThisClass::HandleComponentRegistered);
	UWorldWidgetComponent::OnComponentUnregistered.AddUObject(this, &ThisClass::HandleComponentUnregistered);
	UWorldWidgetComponent::OnComponentChanged.AddUObject(this, &ThisClass::HandleComponentChanged);
	FEditorDelegates::BeginPIE.AddUObject(this, &ThisClass::HandleBeginPIE);
	FEditorDelegates::EndPIE.AddUObject(this, &ThisClass::HandleEndPIE);
	FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(this, &ThisClass::HandleObjectPropertyChanged);
	FCoreUObjectDelegates::OnObjectsReinstanced.AddUObject(this, &ThisClass::HandleObjectsReinstanced);

	if (FSlateApplication::IsInitialized() && !EditorInputProcessor.IsValid())
	{
		const TSharedRef<FWorldWidgetEditorInputProcessor> NewInputProcessor = MakeShared<FWorldWidgetEditorInputProcessor>(this);
		EditorInputProcessor = StaticCastSharedRef<IInputProcessor>(NewInputProcessor).ToSharedPtr();
		FSlateApplication::Get().RegisterInputPreProcessor(EditorInputProcessor);
	}

	RegisterExistingWorldWidgets();

	if (!EditorPreviewTickerHandle.IsValid())
	{
		EditorPreviewTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &ThisClass::TickEditorPreview));
	}
}

void UWorldWidgetEdSubsystem::Deinitialize()
{
	if (EditorPreviewTickerHandle.IsValid())
	{
		FTSTicker::RemoveTicker(EditorPreviewTickerHandle);
		EditorPreviewTickerHandle.Reset();
	}

	if (EditorInputProcessor.IsValid() && FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(EditorInputProcessor);
	}
	EditorInputProcessor.Reset();

	UWorldWidgetComponent::OnComponentRegistered.RemoveAll(this);
	UWorldWidgetComponent::OnComponentUnregistered.RemoveAll(this);
	UWorldWidgetComponent::OnComponentChanged.RemoveAll(this);
	FEditorDelegates::BeginPIE.RemoveAll(this);
	FEditorDelegates::EndPIE.RemoveAll(this);
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
	FCoreUObjectDelegates::OnObjectsReinstanced.RemoveAll(this);

	RemoveAllViewportPreviews();
	PreviewWidgetReferences.Reset();
	RegisteredComponents.Reset();

	Super::Deinitialize();
}

bool UWorldWidgetEdSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Editor;
}

void UWorldWidgetEdSubsystem::RegisterExistingWorldWidgets()
{
	for (TObjectIterator<UWorldWidgetComponent> ComponentIt; ComponentIt; ++ComponentIt)
	{
		UWorldWidgetComponent* Component = *ComponentIt;
		if (IsValid(Component) && Component->IsRegistered() && IsComponentOwnedByWorld(Component))
		{
			RegisterWorldWidget(Component);
		}
	}
}

void UWorldWidgetEdSubsystem::HandleComponentRegistered(UWorldWidgetComponent* InComponent)
{
	RegisterWorldWidget(InComponent);
}

void UWorldWidgetEdSubsystem::HandleComponentUnregistered(UWorldWidgetComponent* InComponent)
{
	UnregisterWorldWidget(InComponent);
}

void UWorldWidgetEdSubsystem::HandleComponentChanged(UWorldWidgetComponent* InComponent)
{
	if (IsComponentOwnedByWorld(InComponent))
	{
		RefreshWorldWidgetComponentForPreview(InComponent);
		MarkEditorPreviewDirty();
	}
	else
	{
		UnregisterWorldWidget(InComponent);
	}
}

void UWorldWidgetEdSubsystem::HandleBeginPIE(bool bIsSimulating)
{
	(void)bIsSimulating;
	bEditorPreviewPausedForPIE = true;
	RemoveAllViewportPreviews();
	PreviewWidgetReferences.Reset();
	bEditorPreviewDirty = true;
}

void UWorldWidgetEdSubsystem::HandleEndPIE(bool bWasSimulating)
{
	(void)bWasSimulating;
	bEditorPreviewPausedForPIE = false;
	MarkEditorPreviewDirty();
}

void UWorldWidgetEdSubsystem::HandleObjectPropertyChanged(UObject* InObject, FPropertyChangedEvent& InPropertyChangedEvent)
{
	(void)InPropertyChangedEvent;
	if (IsObjectRelevantToPreview(InObject))
	{
		RefreshRegisteredComponentsForPreview(InObject);
		MarkEditorPreviewDirty();
	}
}

void UWorldWidgetEdSubsystem::HandleObjectsReinstanced(const FCoreUObjectDelegates::FReplacementObjectMap& InReplacementMap)
{
	bool bAnyRegisteredComponentUpdated = false;
	for (UWorldWidgetComponent* Component : RegisteredComponents)
	{
		if (!IsValid(Component))
		{
			continue;
		}

		if (UGenericWidget* SourceWidget = Component->GetWorldWidget())
		{
			if (UObject* const* Replacement = InReplacementMap.Find(SourceWidget))
			{
				if (UGenericWidget* ReplacementWidget = Cast<UGenericWidget>(*Replacement))
				{
					Component->SetWorldWidget(ReplacementWidget);
					RefreshWorldWidgetComponentForPreview(Component);
					bAnyRegisteredComponentUpdated = true;
				}
			}
		}
	}

	if (bAnyRegisteredComponentUpdated)
	{
		MarkEditorPreviewDirty();
		return;
	}

	for (const TPair<UObject*, UObject*>& ReplacementPair : InReplacementMap)
	{
		if (IsObjectRelevantToPreview(ReplacementPair.Key) || IsObjectRelevantToPreview(ReplacementPair.Value))
		{
			MarkEditorPreviewDirty();
			return;
		}
	}

	if (RegisteredComponents.Num() > 0)
	{
		RefreshRegisteredComponentsForPreview(nullptr);
		MarkEditorPreviewDirty();
	}
}

bool UWorldWidgetEdSubsystem::HandleEditorMouseButtonDownEvent(const FPointerEvent& InMouseEvent)
{
	if (!GEditor
		|| bEditorPreviewPausedForPIE
		|| GEditor->IsPlaySessionInProgress()
		|| InMouseEvent.GetEffectingButton() != EKeys::MiddleMouseButton)
	{
		return false;
	}

	UWorldWidgetComponent* HitComponent = FindHitScreenWorldWidget(InMouseEvent.GetScreenSpacePosition());
	AActor* HitActor = IsValid(HitComponent) ? HitComponent->GetOwner() : nullptr;
	if (!IsValid(HitActor))
	{
		return false;
	}

	GEditor->SelectNone(false, true);
	GEditor->SelectActor(HitActor, true, true, true);
	return true;
}

bool UWorldWidgetEdSubsystem::TickEditorPreview(float InDeltaTime)
{
	(void)InDeltaTime;
	if (!bEditorPreviewPausedForPIE && GEditor && !GEditor->IsPlaySessionInProgress())
	{
		RefreshEditorWorldFollowCameraTransforms();
	}

	RefreshEditorViewportPreviews();
	return true;
}

void UWorldWidgetEdSubsystem::RefreshEditorWorldFollowCameraTransforms()
{
	FLevelEditorViewportClient* ViewportClient = FindEditorFollowCameraViewport(GetWorld());
	if (!ViewportClient)
	{
		return;
	}

	const FVector CameraLocation = ViewportClient->GetViewLocation();
	const FRotator CameraRotation = ViewportClient->GetViewRotation();
	for (UWorldWidgetComponent* Component : FWorldWidgetRegistry::GetComponentsBySpace(RegisteredComponents, EWidgetSpace::World))
	{
		if (!IsValid(Component) || !Component->IsRegistered() || !Component->IsVisible())
		{
			continue;
		}

		Component->UpdateFollowCameraTransformForView(
			CameraLocation,
			CameraRotation,
			CalculateEditorFollowCameraTargetScale(ViewportClient, Component));
	}
}

void UWorldWidgetEdSubsystem::MarkEditorPreviewDirty()
{
	bEditorPreviewDirty = true;
}

void UWorldWidgetEdSubsystem::RefreshEditorViewportPreviews()
{
	if (!GEditor)
	{
		return;
	}

	if (bEditorPreviewPausedForPIE || GEditor->IsPlaySessionInProgress())
	{
		RemoveAllViewportPreviews();
		PreviewWidgetReferences.Reset();
		bEditorPreviewDirty = true;
		return;
	}

	bool bViewportListChanged = false;
	for (int32 Index = ViewportPreviews.Num() - 1; Index >= 0; --Index)
	{
		FWorldWidgetEditorViewportPreview& Preview = ViewportPreviews[Index];
		if (!Preview.Viewport.IsValid())
		{
			ViewportPreviews.RemoveAt(Index);
			bViewportListChanged = true;
		}
	}

	for (FLevelEditorViewportClient* ViewportClient : GEditor->GetLevelViewportClients())
	{
		if (!ViewportClient || ViewportClient->GetWorld() != GetWorld())
		{
			continue;
		}

		TSharedPtr<SLevelViewport> LevelViewport = StaticCastSharedPtr<SLevelViewport>(ViewportClient->GetEditorViewportWidget());
		if (!LevelViewport.IsValid())
		{
			continue;
		}

		const bool bAlreadyTracked = ViewportPreviews.ContainsByPredicate([&LevelViewport](const FWorldWidgetEditorViewportPreview& ExistingPreview)
		{
			return ExistingPreview.Viewport.Pin() == LevelViewport;
		});

		if (!bAlreadyTracked)
		{
			FWorldWidgetEditorViewportPreview& NewPreview = ViewportPreviews.AddDefaulted_GetRef();
			NewPreview.Viewport = LevelViewport;
			NewPreview.Canvas = SNew(SConstraintCanvas);
			LevelViewport->AddOverlayWidget(NewPreview.Canvas.ToSharedRef());
			bViewportListChanged = true;
		}
	}

	if (!bEditorPreviewDirty && !bViewportListChanged)
	{
		return;
	}

	PreviewWidgetReferences.Reset();
	for (FWorldWidgetEditorViewportPreview& Preview : ViewportPreviews)
	{
		RebuildViewportPreview(Preview);
	}

	bEditorPreviewDirty = false;
}

void UWorldWidgetEdSubsystem::RebuildViewportPreview(FWorldWidgetEditorViewportPreview& InViewportPreview)
{
	if (!InViewportPreview.Canvas.IsValid())
	{
		return;
	}

	InViewportPreview.Canvas->ClearChildren();
	InViewportPreview.Slots.Reset();

	for (UWorldWidgetComponent* Component : FWorldWidgetRegistry::GetComponentsBySpace(RegisteredComponents, EWidgetSpace::Screen))
	{
		UGenericWidget* SourceWidget = IsValid(Component) ? Component->GetWorldWidget() : nullptr;
		if (!IsValid(Component) || !Component->IsVisible() || !IsValid(SourceWidget))
		{
			continue;
		}

		UGenericWidget* PreviewWidget = DuplicateObject<UGenericWidget>(SourceWidget, this);
		if (!IsValid(PreviewWidget))
		{
			continue;
		}

		PreviewWidget->SetDesignerFlags(EWidgetDesignFlags::Designing);
		PreviewWidget->Initialize();
		PreviewWidgetReferences.Add(PreviewWidget);
		const TSharedRef<SWidget> PreviewSlateWidget = PreviewWidget->TakeWidget();

		FWorldWidgetEditorPreviewSlot& PreviewSlot = InViewportPreview.Slots.AddDefaulted_GetRef();
		PreviewSlot.Component = Component;
		PreviewSlot.PreviewWidget = PreviewWidget;
		PreviewSlot.PreviewSlateWidget = PreviewSlateWidget;

		const TWeakPtr<SLevelViewport> WeakViewport = InViewportPreview.Viewport;
		const TWeakPtr<SConstraintCanvas> WeakCanvas = InViewportPreview.Canvas;
		const TWeakObjectPtr<UWorldWidgetComponent> WeakComponent = Component;
		const TWeakObjectPtr<UGenericWidget> WeakPreviewWidget = PreviewWidget;
		const TWeakPtr<SWidget> WeakPreviewSlateWidget = PreviewSlateWidget;

		InViewportPreview.Canvas->AddSlot()
			.Anchors(FAnchors(0.0f, 0.0f))
			.Alignment(Component->GetAnchor())
			.AutoSize(false)
			.Offset_Lambda([WeakViewport, WeakCanvas, WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget]()
			{
				return GetPreviewOffset(WeakViewport, WeakCanvas, WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget);
			})
			[
				SNew(SBox)
				.WidthOverride(TAttribute<FOptionalSize>::Create(TAttribute<FOptionalSize>::FGetter::CreateLambda([WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget]()
				{
					return GetPreviewWidthOverride(WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget);
				})))
				.HeightOverride(TAttribute<FOptionalSize>::Create(TAttribute<FOptionalSize>::FGetter::CreateLambda([WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget]()
				{
					return GetPreviewHeightOverride(WeakComponent, WeakPreviewWidget, WeakPreviewSlateWidget);
				})))
				.Visibility(TAttribute<EVisibility>::Create(TAttribute<EVisibility>::FGetter::CreateLambda([WeakViewport, WeakCanvas, WeakComponent]()
				{
					return GetPreviewVisibility(WeakViewport, WeakCanvas, WeakComponent);
				})))
				[
					PreviewSlateWidget
				]
			];
	}
}

void UWorldWidgetEdSubsystem::RemoveAllViewportPreviews()
{
	for (FWorldWidgetEditorViewportPreview& Preview : ViewportPreviews)
	{
		const TSharedPtr<SLevelViewport> LevelViewport = Preview.Viewport.Pin();
		if (LevelViewport.IsValid() && Preview.Canvas.IsValid())
		{
			LevelViewport->RemoveOverlayWidget(Preview.Canvas.ToSharedRef());
		}
	}

	ViewportPreviews.Reset();
}

void UWorldWidgetEdSubsystem::RefreshRegisteredComponentsForPreview(UObject* InRelevantObject)
{
	for (UWorldWidgetComponent* Component : RegisteredComponents)
	{
		if (!IsValid(Component))
		{
			continue;
		}

		UGenericWidget* SourceWidget = Component->GetWorldWidget();
		const bool bRefreshAll = InRelevantObject == nullptr;
		const bool bRelevantWidget = IsValid(SourceWidget) && InRelevantObject && (InRelevantObject == SourceWidget || InRelevantObject->IsIn(SourceWidget));
		const bool bRelevantComponent = InRelevantObject == Component;
		const bool bRelevantClassPackage = IsValid(SourceWidget) && InRelevantObject && InRelevantObject->GetOutermost() == SourceWidget->GetClass()->GetOutermost();
		if (bRefreshAll || bRelevantWidget || bRelevantComponent || bRelevantClassPackage)
		{
			RefreshWorldWidgetComponentForPreview(Component);
		}
	}
}

UWorldWidgetComponent* UWorldWidgetEdSubsystem::FindHitScreenWorldWidget(const FVector2D& InScreenSpacePosition) const
{
	UWorldWidgetComponent* BestComponent = nullptr;
	int32 BestPriority = MIN_int32;
	int32 BestIndex = INDEX_NONE;

	for (const FWorldWidgetEditorViewportPreview& ViewportPreview : ViewportPreviews)
	{
		FVector2D LocalMousePosition;
		if (!GetPreviewCanvasLocalPosition(ViewportPreview.Viewport, ViewportPreview.Canvas, InScreenSpacePosition, LocalMousePosition))
		{
			continue;
		}

		for (int32 ComponentIndex = 0; ComponentIndex < RegisteredComponents.Num(); ++ComponentIndex)
		{
			UWorldWidgetComponent* Component = RegisteredComponents[ComponentIndex];
			AActor* Owner = IsValid(Component) ? Component->GetOwner() : nullptr;
			if (!IsValid(Component)
				|| !IsValid(Owner)
				|| Owner->IsHiddenEd()
				|| Component->GetWidgetSpace() != EWidgetSpace::Screen
				|| !Component->IsVisible())
			{
				continue;
			}

			FVector2D ProjectedPosition;
			if (!ProjectWorldWidgetToPreviewCanvas(ViewportPreview.Viewport, ViewportPreview.Canvas, Component, ProjectedPosition))
			{
				continue;
			}

			const FWorldWidgetEditorPreviewSlot* PreviewSlot = ViewportPreview.Slots.FindByPredicate([Component](const FWorldWidgetEditorPreviewSlot& ExistingSlot)
			{
				return ExistingSlot.Component.Get() == Component;
			});
			const TWeakObjectPtr<UWorldWidgetComponent> WeakComponent = Component;
			const FVector2D DrawSize = PreviewSlot
				? GetPreviewDrawSize(WeakComponent, PreviewSlot->PreviewWidget, PreviewSlot->PreviewSlateWidget)
				: GetComponentDrawSize(Component);
			const FVector2D Anchor = Component->GetAnchor();
			const FVector2D TopLeft(
				ProjectedPosition.X - DrawSize.X * Anchor.X,
				ProjectedPosition.Y - DrawSize.Y * Anchor.Y);
			const FVector2D BottomRight = TopLeft + DrawSize;
			const bool bHit = LocalMousePosition.X >= TopLeft.X
				&& LocalMousePosition.Y >= TopLeft.Y
				&& LocalMousePosition.X <= BottomRight.X
				&& LocalMousePosition.Y <= BottomRight.Y;
			if (!bHit)
			{
				continue;
			}

			const int32 ComponentPriority = Component->GetInputPriority();
			if (!BestComponent || ComponentPriority > BestPriority || (ComponentPriority == BestPriority && ComponentIndex > BestIndex))
			{
				BestComponent = Component;
				BestPriority = ComponentPriority;
				BestIndex = ComponentIndex;
			}
		}
	}

	return BestComponent;
}

bool UWorldWidgetEdSubsystem::IsComponentOwnedByWorld(UWorldWidgetComponent* InComponent) const
{
	return IsValid(InComponent) && InComponent->GetWorld() == GetWorld();
}

bool UWorldWidgetEdSubsystem::IsObjectRelevantToPreview(UObject* InObject) const
{
	if (!IsValid(InObject))
	{
		return false;
	}

	if (InObject->IsA<UWorldWidgetComponent>())
	{
		return true;
	}

	const UBlueprint* Blueprint = Cast<UBlueprint>(InObject);
	const UClass* BlueprintClass = Blueprint ? Blueprint->GeneratedClass : nullptr;
	const UPackage* ObjectPackage = InObject->GetOutermost();

	for (UWorldWidgetComponent* Component : RegisteredComponents)
	{
		if (!IsValid(Component))
		{
			continue;
		}

		UGenericWidget* SourceWidget = Component->GetWorldWidget();
		if (!IsValid(SourceWidget))
		{
			continue;
		}

		if (InObject == SourceWidget || InObject->IsIn(SourceWidget))
		{
			return true;
		}

		const UClass* SourceWidgetClass = SourceWidget->GetClass();
		if (BlueprintClass && SourceWidgetClass && SourceWidgetClass->IsChildOf(BlueprintClass))
		{
			return true;
		}

		if (ObjectPackage && SourceWidgetClass && ObjectPackage == SourceWidgetClass->GetOutermost())
		{
			return true;
		}
	}

	return false;
}
