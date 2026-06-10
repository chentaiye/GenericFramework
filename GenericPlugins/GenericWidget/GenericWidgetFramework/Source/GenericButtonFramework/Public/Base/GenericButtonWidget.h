// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionWidget.h"
#include "ButtonType.h"
#include "GameplayTagContainer.h"
#include "GenericButtonWidget.generated.h"

class UGenericButton;
class UGenericButtonStyle;
class SWidget;

#if WITH_EDITOR
struct FPropertyChangedEvent;
#endif

/** 定义通用 UI使用的通用ButtonDesiredStyle取值范围。 */
UENUM(BlueprintType)
enum class EGenericButtonDesiredStyle : uint8
{
	Disabled,
	Normal,
	Selected
};

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonEnabled);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonDisabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonDisabled);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonPressed);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonReleased);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonReleased);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonHovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonHovered);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonUnhovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonUnhovered);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonClicked);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonDoubleClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonDoubleClicked);

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate_OnButtonSelectionChanged, bool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnButtonSelectionChanged, bool, bSelected);

DECLARE_MULTICAST_DELEGATE(FDelegate_OnButtonStyleChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnButtonStyleChanged);

/** 表示运行时自动将自身根节点包裹为通用按钮的行为UI控件。 */
UCLASS(MinimalAPI)
class UGenericButtonWidget : public UGenericActionWidget
{
	GENERATED_BODY()

	friend class UGenericButtonStyle;

public:
	/** 初始化按钮控件默认状态。 */
	GENERICBUTTONFRAMEWORK_API UGenericButtonWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API FGameplayTag GetButtonTag() const;

	UFUNCTION(BlueprintCallable, Category="Button", meta=(Categories="GameplayUI.Button"))
	GENERICBUTTONFRAMEWORK_API void SetButtonTag(FGameplayTag InButtonTag);

	/** 设置按钮业务可用状态，不会调用引擎禁用状态。 */
	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonEnabled() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonEnabled(bool bInButtonEnabled);

	/** 设置按钮业务交互状态，不会禁用内部Slate按钮。 */
	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonInteractionEnabled() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonInteractionEnabled(bool bInInteractionEnabled);

	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonSelectable() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonSelectable(bool bInSelectable);

	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonToggleable() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonToggleable(bool bInToggleable);

	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonDefaultSelected() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonDefaultSelected(bool bInDefaultSelected);


	/** 判断按钮当前是否处于选中状态。 */
	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API bool GetButtonSelected() const;

	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SetButtonSelected(bool bInSelected);

	/** 获取运行时包裹出的通用按钮。 */
	UFUNCTION(BlueprintPure, Category="Button")
	GENERICBUTTONFRAMEWORK_API UGenericButton* GetWrappedButton() const;

public:
	/** 记录Button标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button", meta=(Categories="GameplayUI.Button"))
	FGameplayTag ButtonTag;

	/** 标记按钮业务是否可用，不改变Slate/UMG enabled状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button")
	bool bButtonEnabled = true;

	/** 标记按钮业务是否允许交互，不改变Slate/UMG enabled状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button")
	bool bInteractionEnabled = true;

	/** 标记按钮是否允许被选中。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button")
	bool bSelectable = true;

	/** 标记选中按钮再次点击时是否取消选中。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button", meta=(EditCondition="bSelectable"))
	bool bToggleable = false;

	/** 标记按钮首次构造时是否默认选中。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button", meta=(EditCondition="bSelectable"))
	bool bDefaultSelected = false;

	/** 指定按钮禁用状态使用的样式蓝图类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button|Style")
	TSubclassOf<UGenericButtonStyle> DisabledStyleClass = nullptr;

	/** 指定按钮普通状态使用的样式蓝图类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button|Style")
	TSubclassOf<UGenericButtonStyle> NormalStyleClass = nullptr;

	/** 指定按钮选中状态使用的样式蓝图类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button|Style")
	TSubclassOf<UGenericButtonStyle> SelectedStyleClass = nullptr;

#if WITH_EDITORONLY_DATA
	/** 记录DesiredButtonStyle。 */
	UPROPERTY(EditAnywhere, Category="Button|Preview")
	EGenericButtonDesiredStyle DesiredButtonStyle = EGenericButtonDesiredStyle::Normal;
#endif

protected:
	GENERICBUTTONFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICBUTTONFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICBUTTONFRAMEWORK_API virtual void NativePreConstruct() override;
	GENERICBUTTONFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICBUTTONFRAMEWORK_API virtual void NativeDestruct() override;

#if WITH_EDITOR
	GENERICBUTTONFRAMEWORK_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	/** 模拟按钮按下。 */
	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SimulateButtonPressed();

	/** 模拟按钮释放。 */
	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SimulateButtonReleased();

	/** 模拟一次按下、释放、点击。 */
	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SimulateButtonClick();

	/** 模拟一次按下、释放、点击、双击。 */
	UFUNCTION(BlueprintCallable, Category="Button")
	GENERICBUTTONFRAMEWORK_API void SimulateButtonDoubleClick();

private:
	UFUNCTION()
	void HandleOnButtonPressedInternal();

	UFUNCTION()
	void HandleOnButtonReleasedInternal();

	UFUNCTION()
	void HandleOnButtonHoveredInternal();

	UFUNCTION()
	void HandleOnButtonUnhoveredInternal();

	UFUNCTION()
	void HandleOnButtonClickedInternal();

	UFUNCTION()
	void HandleOnButtonDoubleClickedInternal();

protected:
	/** Executes the enabled event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonEnabledInternal();

	/** Executes the disabled event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonDisabledInternal();

	/** Executes the pressed event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonPressedInternal();

	/** Executes the released event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonReleasedInternal();

	/** Executes the hovered event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonHoveredInternal();

	/** Executes the unhovered event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonUnhoveredInternal();

	/** Executes the clicked event path and applies this button's own selection rules. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonClickedInternal();

	/** Executes the double clicked event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonDoubleClickedInternal();

	/** Executes the selection changed event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonSelectionChangedInternal(bool bInSelected);

	/** Executes the style changed event path. */
	UFUNCTION(BlueprintCallable, Category="Button|Event")
	GENERICBUTTONFRAMEWORK_API void SetOnButtonStyleChangedInternal();

protected:
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonEnabled();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonDisabled();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonPressed();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonReleased();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonHovered();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonUnhovered();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonClicked();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonDoubleClicked();
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonSelectionChanged(bool bInSelected);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnButtonStyleChanged();

	/** 执行句柄OnButtonEnabled流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonEnabled();

	/** 执行句柄OnButtonDisabled流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonDisabled();

	/** 执行句柄OnButtonPressed流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonPressed();

	/** 执行句柄OnButtonReleased流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonReleased();

	/** 执行句柄OnButtonHovered流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonHovered();

	/** 执行句柄OnButtonUnhovered流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonUnhovered();

	/** 执行句柄OnButtonClicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonClicked();

	/** 执行句柄OnButton双精度Clicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonDoubleClicked();

	/** 处理OnButtonSelection变化并同步相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonSelectionChanged(bool bInSelected);

	/** 处理OnButtonStyle变化并同步相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Button|Event")
	void HandleOnButtonStyleChanged();

public:
	FDelegate_OnButtonEnabled Delegate_OnButtonEnabledEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonEnabled BPDelegate_OnButtonEnabledEvent;

	FDelegate_OnButtonDisabled Delegate_OnButtonDisabledEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonDisabled BPDelegate_OnButtonDisabledEvent;

	FDelegate_OnButtonPressed Delegate_OnButtonPressedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonPressed BPDelegate_OnButtonPressedEvent;

	FDelegate_OnButtonReleased Delegate_OnButtonReleasedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonReleased BPDelegate_OnButtonReleasedEvent;

	FDelegate_OnButtonHovered Delegate_OnButtonHoveredEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonHovered BPDelegate_OnButtonHoveredEvent;

	FDelegate_OnButtonUnhovered Delegate_OnButtonUnhoveredEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonUnhovered BPDelegate_OnButtonUnhoveredEvent;

	FDelegate_OnButtonClicked Delegate_OnButtonClickedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonClicked BPDelegate_OnButtonClickedEvent;

	FDelegate_OnButtonDoubleClicked Delegate_OnButtonDoubleClickedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonDoubleClicked BPDelegate_OnButtonDoubleClickedEvent;

	FDelegate_OnButtonSelectionChanged Delegate_OnButtonSelectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonSelectionChanged BPDelegate_OnButtonSelectionChangedEvent;

	FDelegate_OnButtonStyleChanged Delegate_OnButtonStyleChangedEvent;
	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnButtonStyleChanged BPDelegate_OnButtonStyleChangedEvent;

private:
	void EnsureGenericButtonWrapper();
	void BindWrappedButtonEvents();
	void UnbindWrappedButtonEvents();
	void InitializeSelectionState();
	void RefreshButtonState(bool bForceStyleChangedEvent = false);
	bool CanExecuteButtonInteraction() const;
	bool CanExecuteButtonHover() const;
	const UGenericButtonStyle* GetCurrentStyle() const;
	/** 解析样式类引用，并兼容旧资产里保存的内联样式实例。 */
	const UGenericButtonStyle* ResolveStyle(TSubclassOf<UGenericButtonStyle> InStyleClass, const UGenericButtonStyle* InLegacyStyle) const;

private:
	/** 缓存运行时包裹出的通用按钮。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButton> WrappedButton = nullptr;

	/** 缓存当前选中状态。 */
	UPROPERTY(Transient)
	bool bSelected = false;

	/** 标记默认选中状态是否已经初始化。 */
	UPROPERTY(Transient)
	bool bSelectionInitialized = false;

	/** 缓存上次应用的按钮样式对象。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonStyle> AppliedButtonStyle = nullptr;

	/** 标记是否已经完成过一次样式应用。 */
	UPROPERTY(Transient)
	bool bHasAppliedButtonStyle = false;

	/** 兼容旧资产里内联保存的禁用样式实例。 */
	UPROPERTY()
	TObjectPtr<UGenericButtonStyle> DisabledStyle = nullptr;

	/** 兼容旧资产里内联保存的普通样式实例。 */
	UPROPERTY()
	TObjectPtr<UGenericButtonStyle> NormalStyle = nullptr;

	/** 兼容旧资产里内联保存的选中样式实例。 */
	UPROPERTY()
	TObjectPtr<UGenericButtonStyle> SelectedStyle = nullptr;
};
