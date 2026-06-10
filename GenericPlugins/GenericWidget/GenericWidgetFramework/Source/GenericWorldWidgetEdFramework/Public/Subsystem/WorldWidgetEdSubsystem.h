// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "UObject/UObjectGlobals.h"
#include "WorldWidgetEdSubsystem.generated.h"

class SConstraintCanvas;
class IInputProcessor;
struct FPointerEvent;
class SLevelViewport;
class SWidget;
class UGenericWidget;
class UWorldWidgetComponent;

struct FWorldWidgetEditorPreviewSlot
{
	TWeakObjectPtr<UWorldWidgetComponent> Component;
	TWeakObjectPtr<UGenericWidget> PreviewWidget;
	TWeakPtr<SWidget> PreviewSlateWidget;
};

struct FWorldWidgetEditorViewportPreview
{
	TWeakPtr<SLevelViewport> Viewport;
	TSharedPtr<SConstraintCanvas> Canvas;
	TArray<FWorldWidgetEditorPreviewSlot> Slots;
};

/** Editor-world manager for WorldWidget components and screen-space viewport previews. */
UCLASS(MinimalAPI)
class UWorldWidgetEdSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	GENERICWORLDWIDGETEDFRAMEWORK_API bool RegisterWorldWidget(UWorldWidgetComponent* InComponent);
	GENERICWORLDWIDGETEDFRAMEWORK_API bool UnregisterWorldWidget(UWorldWidgetComponent* InComponent);
	GENERICWORLDWIDGETEDFRAMEWORK_API TArray<UWorldWidgetComponent*> GetAllWorldWidgets() const;

public:
	GENERICWORLDWIDGETEDFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWORLDWIDGETEDFRAMEWORK_API virtual void Deinitialize() override;
	GENERICWORLDWIDGETEDFRAMEWORK_API virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	void RegisterExistingWorldWidgets();
	void HandleComponentRegistered(UWorldWidgetComponent* InComponent);
	void HandleComponentUnregistered(UWorldWidgetComponent* InComponent);
	void HandleComponentChanged(UWorldWidgetComponent* InComponent);
	void HandleBeginPIE(bool bIsSimulating);
	void HandleEndPIE(bool bWasSimulating);
	void HandleObjectPropertyChanged(UObject* InObject, FPropertyChangedEvent& InPropertyChangedEvent);
	void HandleObjectsReinstanced(const FCoreUObjectDelegates::FReplacementObjectMap& InReplacementMap);
	bool HandleEditorMouseButtonDownEvent(const FPointerEvent& InMouseEvent);
	bool TickEditorPreview(float InDeltaTime);
	void MarkEditorPreviewDirty();
	void RefreshEditorViewportPreviews();
	void RefreshEditorWorldFollowCameraTransforms();
	void RebuildViewportPreview(FWorldWidgetEditorViewportPreview& InViewportPreview);
	void RemoveAllViewportPreviews();
	void RefreshRegisteredComponentsForPreview(UObject* InRelevantObject);
	UWorldWidgetComponent* FindHitScreenWorldWidget(const FVector2D& InScreenSpacePosition) const;
	bool IsComponentOwnedByWorld(UWorldWidgetComponent* InComponent) const;
	bool IsObjectRelevantToPreview(UObject* InObject) const;

	friend class FWorldWidgetEditorInputProcessor;

private:
	UPROPERTY()
	TArray<TObjectPtr<UWorldWidgetComponent>> RegisteredComponents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericWidget>> PreviewWidgetReferences;

	TArray<FWorldWidgetEditorViewportPreview> ViewportPreviews;
	TSharedPtr<IInputProcessor> EditorInputProcessor;
	FTSTicker::FDelegateHandle EditorPreviewTickerHandle;
	bool bEditorPreviewDirty = true;
	bool bEditorPreviewPausedForPIE = false;
};
