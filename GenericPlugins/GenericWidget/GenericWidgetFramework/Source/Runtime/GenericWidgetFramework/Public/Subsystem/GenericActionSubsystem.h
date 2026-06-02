// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionWidget.h"
#include "Containers/Ticker.h"
#include "Engine/EngineBaseTypes.h"
#include "Input/GenericInputActionDataAsset.h"
#include "InputActionValue.h"
#include "InputCoreTypes.h"
#include "InputKeyEventArgs.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "GenericActionSubsystem.generated.h"

class APlayerController;
class UGenericLayer;
class UGenericRouteSubsystem;

/** 保存通用 UI流程中的通用动作RuntimeTrigger状态数据，供运行时传递和蓝图访问。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericActionRuntimeTriggerState
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UGenericLayer> Layer = nullptr;

	UPROPERTY()
	FGameplayTag ActionTag;

	UPROPERTY()
	FKey Key;

	UPROPERTY()
	TObjectPtr<UGenericInputTrigger> TemplateTrigger = nullptr;

	UPROPERTY()
	TObjectPtr<UGenericInputTrigger> RuntimeTrigger = nullptr;

	UPROPERTY()
	FInputActionValue LastInputValue;

	UPROPERTY()
	EGenericInputTriggerState LastTriggerState = EGenericInputTriggerState::None;

	UPROPERTY()
	bool bIsPressed = false;

	UPROPERTY()
	float HeldDuration = 0.0f;

	UPROPERTY()
	float ReleasedDuration = 0.0f;

	UPROPERTY()
	float TriggeredTime = 0.0f;

	UPROPERTY()
	bool bHasTriggered = false;

	UPROPERTY()
	bool bHasStarted = false;

	UPROPERTY()
	double LastUpdateTime = 0.0;
};

/** 保存通用 UI流程中的通用动作视口Input事件数据，供运行时传递和蓝图访问。 */
struct GENERICWIDGETFRAMEWORK_API FGenericActionViewportInputEvent
{
	FKey Key;
	FInputActionValue InputValue;
	bool bIsPressed = false;
	float DeltaTime = 0.0f;
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegate_PostRouteViewportInput, const FGenericActionViewportInputEvent&, bool&);

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnActionWidgetRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Action Widget Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Action Widget Registered Message")
	TObjectPtr<UGenericActionWidget> ActionWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnActionWidgetUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Action Widget Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Action Widget Unregistered Message")
	TObjectPtr<UGenericActionWidget> ActionWidget = nullptr;
};

/** 管理本地玩家当前可响应通用UI行为的控件栈。 */
UCLASS(MinimalAPI)
class UGenericActionSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericActionSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericActionSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	GENERICWIDGETFRAMEWORK_API bool RegisterActionWidget(UGenericActionWidget* InWidget);
	GENERICWIDGETFRAMEWORK_API bool UnregisterActionWidget(UGenericActionWidget* InWidget);
	GENERICWIDGETFRAMEWORK_API TArray<UGenericActionWidget*> GetAllActionWidgets() const;
	GENERICWIDGETFRAMEWORK_API bool HandleViewportInputKey(const FInputKeyEventArgs& EventArgs);
	GENERICWIDGETFRAMEWORK_API bool HandleViewportInputTouch(FViewport* Viewport, FInputDeviceId DeviceId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, uint32 TouchpadIndex, uint64 Timestamp);
	GENERICWIDGETFRAMEWORK_API FDelegate_PostRouteViewportInput& GetPostRouteViewportInputDelegate();

public:
	GENERICWIDGETFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	bool IsWidgetOwnedByThisSubsystem(const UGenericActionWidget* InWidget) const;
	bool DispatchViewportInput(const FGenericActionViewportInputEvent& InputEvent, bool bCanConsumeInput);
	bool TickActionInput(float DeltaTime);
	bool EvaluateLayerActionInput(UGenericLayer* InLayer, const FGenericInputActionKeyTriggerMapping& ActionMapping, const FGenericInputKeyTrigger& KeyTrigger, const FGenericActionViewportInputEvent& InputEvent, const UGenericRouteSubsystem* RouteSubsystem, bool bCanConsumeInput, bool& bOutShouldConsume);
	FGenericActionRuntimeTriggerState& FindOrCreateRuntimeTriggerState(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericInputKeyTrigger& InKeyTrigger);
	FGenericInputTriggerContext BuildTriggerContext(FGenericActionRuntimeTriggerState& RuntimeState, const FGenericActionViewportInputEvent& InputEvent) const;
	void UpdateRuntimeTriggerState(FGenericActionRuntimeTriggerState& RuntimeState, const FGenericInputTriggerContext& TriggerContext, EGenericInputTriggerState NewTriggerState);
	bool DispatchTriggerEventsToLayer(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericActionViewportInputEvent& InputEvent, const FGenericInputTriggerContext& TriggerContext, FGenericActionRuntimeTriggerState& RuntimeState, EGenericInputTriggerState NewTriggerState, const UGenericRouteSubsystem* RouteSubsystem);
	bool DispatchActionEventToLayer(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericActionInputEventData& EventData, const UGenericRouteSubsystem* RouteSubsystem);
	bool IsActionWidgetInLayerRoute(UGenericActionWidget* InWidget, UGenericLayer* InLayer, const UGenericRouteSubsystem* RouteSubsystem) const;
	void PruneRuntimeTriggerStates();

private:
	UPROPERTY()
	TArray<TObjectPtr<UGenericActionWidget>> ActionWidgetStack;

	UPROPERTY()
	TArray<FGenericActionRuntimeTriggerState> RuntimeTriggerStates;

	FDelegate_PostRouteViewportInput Delegate_PostRouteViewportInput;
	FTSTicker::FDelegateHandle ActionInputTickerHandle;
};
