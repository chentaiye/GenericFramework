// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "GenericWindowType.h"
#include "GenericWindowWidget.generated.h"

class APlayerController;
class UGenericButtonWidget;
class UGenericWindowAnchor;
class UGenericWindowContent;
class UGenericWindowDescriptor;
class UGenericWindowRuntimeState;
class UGenericWindowTitleBar;
class SGenericWindowFrame;
class IGenericWindowHostInterface;

/** 作为窗口控件能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, BlueprintType)
class UGenericWindowWidget : public UWidget
{
	GENERATED_BODY()

public:
	/** 初始化通用窗口控件默认状态。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowWidget(const FObjectInitializer& ObjectInitializer);

	/** 初始化窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void InitializeWindow(APlayerController* InOwningPlayer, UGenericWindowDescriptor* InDescriptor);

	/** 打开窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void OpenWindow();

	/** 关闭窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void CloseWindow();

	/** 最小化窗口，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void MinimizeWindow();

	/** 最大化窗口，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void MaximizeWindow();

	/** 恢复窗口，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void RestoreWindow();

	/** 切换窗口Maximize，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void ToggleWindowMaximize();

	/** 切换窗口Minimize，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void ToggleWindowMinimize();

	/** 折叠窗口目标标题栏，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void CollapseWindowToTitleBar();

	/** 展开窗口来源标题栏，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void ExpandWindowFromTitleBar();

	/** 切换窗口Collapse目标标题栏，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void ToggleWindowCollapseToTitleBar();

	/** 置顶目标Front，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void BringToFront();

	/** 设置窗口描述。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void SetWindowDescriptor(UGenericWindowDescriptor* InDescriptor);

	/** 获取窗口描述。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowDescriptor* GetWindowDescriptor() const;

	/** 获取窗口运行时状态。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowRuntimeState* GetWindowRuntimeState() const;

	/** 获取拥有者玩家。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API APlayerController* GetOwnerPlayer() const;

	/** 判断窗口打开是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool IsWindowOpen() const;

	/** 判断窗口Maximized是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool IsWindowMaximized() const;

	/** 判断窗口Collapsed To标题Bar是否成立。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool IsWindowCollapsedToTitleBar() const;

	/** 获取窗口显示状态。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API EGenericInGameWindowDisplayState GetWindowDisplayState() const;

	/** 获取窗口标题栏控件。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowTitleBar* GetWindowTitleBarWidget() const;

	/** 获取窗口内容控件。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowContent* GetWindowContentWidget() const;

	/** 刷新窗口Parts。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void RefreshWindowParts();

	/** 刷新窗口Layout。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void RefreshWindowLayout();

	/** 请求窗口Move。 */
	GENERICWINDOWFRAMEWORK_API void RequestWindowMove(const FVector2D& InNewPosition);

	/** 请求窗口Resize。 */
	GENERICWINDOWFRAMEWORK_API void RequestWindowResize(EGenericWindowResizeHandle InHandle, const FVector2D& InStartPosition, const FVector2D& InStartSize, const FVector2D& InDelta);

	/** 通知交互开始。 */
	GENERICWINDOWFRAMEWORK_API void NotifyInteractionStarted(bool bIsResizeOperation);

	/** 通知交互Ended。 */
	GENERICWINDOWFRAMEWORK_API void NotifyInteractionEnded();

	/** 获取Viewport大小。 */
	GENERICWINDOWFRAMEWORK_API FVector2D GetViewportSize() const;
	GENERICWINDOWFRAMEWORK_API virtual APlayerController* GetOwningPlayer() const override;

/** 构建窗口标题栏控件，供窗口布局同步和部件绑定复用。 */
	GENERICWINDOWFRAMEWORK_API TSharedRef<SWidget> BuildWindowTitleBarWidget();

/** 构建窗口内容控件，供窗口布局同步和部件绑定复用。 */
	GENERICWINDOWFRAMEWORK_API TSharedRef<SWidget> BuildWindowContentWidget();

	/** 获取Minimum窗口高度。 */
	GENERICWINDOWFRAMEWORK_API float GetMinimumWindowHeight() const;

	/** 设置窗口Anchor主机地址。 */
	GENERICWINDOWFRAMEWORK_API void SetWindowAnchorHost(UGenericWindowAnchor* InAnchorHost);

	/** 获取窗口Anchor主机地址。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowAnchor* GetWindowAnchorHost() const;

	/** 判断Hosted按窗口Anchor是否成立。 */
	GENERICWINDOWFRAMEWORK_API bool IsHostedByWindowAnchor() const;

	/** 处理窗口Descriptor变化并同步相关状态。 */
	GENERICWINDOWFRAMEWORK_API void HandleWindowDescriptorChanged();

	/** 执行句柄ExternalHost窗口Closed流程，并把结果同步给通用 UI相关状态。 */
	GENERICWINDOWFRAMEWORK_API void HandleExternalHostWindowClosed();

protected:
	GENERICWINDOWFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	GENERICWINDOWFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICWINDOWFRAMEWORK_API virtual void SynchronizeProperties() override;

#if WITH_EDITOR
	GENERICWINDOWFRAMEWORK_API virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
	GENERICWINDOWFRAMEWORK_API virtual const FText GetPaletteCategory() override;
#endif

	GENERICWINDOWFRAMEWORK_API virtual void BeginDestroy() override;

protected:
	/** 窗口描述。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Window")
	TObjectPtr<UGenericWindowDescriptor> WindowDescriptor=nullptr;

	/** 缓存窗口运行时状态。 */
	UPROPERTY(BlueprintReadOnly, Instanced, Category="Window")
	TObjectPtr<UGenericWindowRuntimeState> WindowRuntimeState=nullptr;

	/** 缓存窗口标题Bar控件实例。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericWindowTitleBar> WindowTitleBarWidgetInstance=nullptr;

	/** 缓存窗口内容控件实例。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericWindowContent> WindowContentWidgetInstance=nullptr;

	/** 持有MinimizeButton控件Instance实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> MinimizeButtonWidgetInstance=nullptr;

	/** 持有MaximizeButton控件Instance实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> MaximizeButtonWidgetInstance=nullptr;

	/** 缓存关闭按钮控件实例。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> CloseButtonWidgetInstance=nullptr;

	/** 持有ExpandButton控件Instance实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> ExpandButtonWidgetInstance=nullptr;

private:
	friend class SGenericWindowFrame;

	/** 确保描述。 */
	void EnsureDescriptor();

	/** 确保运行时状态。 */
	void EnsureRuntimeState();

	/** 确保运行时状态初始化状态。 */
	void EnsureRuntimeStateInitialized();

	/** 确保Drag策略已锁定。 */
	void EnsureDragPolicyLocked();

	/** 确保主机地址。 */
	void EnsureHost();

	/** 应用运行时状态Constraints。 */
	void ApplyRuntimeStateConstraints();

	/** 更新可见矩形。 */
	void UpdateVisibleRect();

	/** 只同步窗口状态和布局，避免在按钮回调中重挂 Slate 子树。 */
	void RefreshWindowState();

	/** 获取Collapsed窗口高度。 */
	float GetCollapsedWindowHeight() const;

	/** 判断运行时窗口实例是否成立。 */
	bool IsRuntimeWindowInstance() const;

	/** 判断是否需要Apply已锁定Drag策略。 */
	bool ShouldApplyLockedDragPolicy() const;

	/** 判断使用s原生窗口Host，让调用方按结果选择后续路径。 */
	bool UsesNativeWindowHost() const;

	/** 获取Effective Drag策略。 */
	EGenericWindowDragPolicy GetEffectiveDragPolicy() const;

	/** 把 Slate 鼠标屏幕位置转换到当前窗口宿主的逻辑坐标。 */
	bool TryConvertScreenToWindowHostPosition(const FVector2D& InScreenSpacePosition, FVector2D& OutHostPosition) const;

	/** 约束限制Rect目标Descriptor，确保窗口矩形落在描述符允许范围内。 */
	void ClampRectToDescriptor(FVector2D& InOutPosition, FVector2D& InOutSize) const;

	/** 更新Collapse Restore矩形After Layout Change。 */
	void UpdateCollapseRestoreRectAfterLayoutChange(const FVector2D& InPosition, const FVector2D& InSize);

	/** 应用窗口Part上下文。 */
	void ApplyWindowPartContext(UWidget* InWidget) const;

	/** 同步窗口Part控件s，使运行时状态与输入配置保持一致。 */
	void SyncWindowPartWidgets();

	/** 把输入解析为窗口标题栏控件，供后续流程使用。 */
	UGenericWindowTitleBar* ResolveWindowTitleBarWidget();

	/** 把输入解析为窗口内容控件，供后续流程使用。 */
	UGenericWindowContent* ResolveWindowContentWidget();

	/** 把输入解析为窗口标题栏Slate，供后续流程使用。 */
	TSharedRef<SWidget> ResolveWindowTitleBarSlate();

	/** 把输入解析为窗口内容Slate，供后续流程使用。 */
	TSharedRef<SWidget> ResolveWindowContentSlate();

	/** 绑定Button委托集合，保持对象生命周期内的委托连接一致。 */
	void BindButtonDelegates();

	/** 解绑Button委托集合，保持对象生命周期内的委托连接一致。 */
	void UnbindButtonDelegates();

	/** 执行句柄MinimizeButtonClicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleMinimizeButtonClicked();

	/** 执行句柄MaximizeButtonClicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleMaximizeButtonClicked();

	/** 执行句柄CloseButtonClicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleCloseButtonClicked();

	/** 执行句柄ExpandButtonClicked流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleExpandButtonClicked();

	/** 缓存窗口Frame。 */
	TSharedPtr<SGenericWindowFrame> WindowFrame;

	/** 缓存窗口主机地址。 */
	TSharedPtr<IGenericWindowHostInterface> WindowHost;

	/** 缓存窗口Anchor主机地址。 */
	TWeakObjectPtr<UGenericWindowAnchor> WindowAnchorHost;

	/** 标记运行时状态初始化状态。 */
	bool bRuntimeStateInitialized = false;

	/** 标记Drag策略Locked状态。 */
	bool bDragPolicyLocked = false;

	/** 标记窗口主机地址打开In Progress。 */
	bool bWindowHostOpenInProgress = false;

	/** 记录LockedDrag策略。 */
	EGenericWindowDragPolicy LockedDragPolicy = EGenericWindowDragPolicy::InViewportOnly;
};
