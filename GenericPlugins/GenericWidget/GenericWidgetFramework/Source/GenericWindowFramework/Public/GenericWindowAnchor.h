// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "GenericWindowAnchor.generated.h"

class SBox;
class SGenericWindowAnchorRoot;
class UGenericWindowSlot;
class UGenericWindowWidget;

/** 作为窗口Anchor能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, BlueprintType)
class UGenericWindowAnchor : public UContentWidget
{
	GENERATED_BODY()

public:
	/** 初始化通用窗口Anchor的默认运行状态。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowAnchor(const FObjectInitializer& ObjectInitializer);

	/** 获取Hosted窗口。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowWidget* GetHostedWindow() const;

	/** 设置Hosted窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowSlot* SetHostedWindow(UGenericWindowWidget* InWindowWidget);

	/** 刷新Hosted窗口Layout。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void RefreshHostedWindowLayout();

protected:
	GENERICWINDOWFRAMEWORK_API virtual UClass* GetSlotClass() const override;
	GENERICWINDOWFRAMEWORK_API virtual void OnSlotAdded(UPanelSlot* InSlot) override;
	GENERICWINDOWFRAMEWORK_API virtual void OnSlotRemoved(UPanelSlot* InSlot) override;
	GENERICWINDOWFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICWINDOWFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	GENERICWINDOWFRAMEWORK_API virtual void SynchronizeProperties() override;

#if WITH_EDITOR
	GENERICWINDOWFRAMEWORK_API virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
	GENERICWINDOWFRAMEWORK_API virtual const FText GetPaletteCategory() override;
#endif

private:
	friend class SGenericWindowAnchorRoot;

	/** 执行句柄锚点GeometryTick流程，并把结果同步给通用 UI相关状态。 */
	void HandleAnchorGeometryTick(const FGeometry& InGeometry);

	/** 尝试尝试OpenHosted窗口来源锚点，失败时通过返回值或输出参数交还调用方处理。 */
	void TryOpenHostedWindowFromAnchor(const FGeometry& InGeometry);

	/** 刷新重建托管窗口Slot相关缓存或运行时状态。 */
	void RebuildHostedWindowSlot();

	/** 获取Hosted窗口大小。 */
	FVector2D GetHostedWindowSize() const;

	/** 获取Hosted窗口Offset。 */
	FMargin GetHostedWindowOffset() const;

	/** 获取Hosted窗口Top Left Offset。 */
	FVector2D GetHostedWindowTopLeftOffset() const;

	/** 获取Hosted窗口对齐。 */
	FVector2D GetHostedWindowAlignment() const;

	/** 获取通用窗口槽位。 */
	UGenericWindowSlot* GetGenericWindowSlot() const;

	/** 判断是否需要预览Hosted窗口In Anchor。 */
	bool ShouldPreviewHostedWindowInAnchor() const;

	/** 弱引用托管窗口控件，避免运行时回调延长对象生命周期。 */
	TWeakObjectPtr<UGenericWindowWidget> HostedWindowWidget;

	/** 记录锚点根Box。 */
	TSharedPtr<SBox> AnchorRootBox;

	/** 记录锚点Canvas。 */
	TSharedPtr<SConstraintCanvas> AnchorCanvas;

	/** 记录Hosted窗口Slot。 */
	SConstraintCanvas::FSlot* HostedWindowSlot = nullptr;

	/** 标记是否包含Activated运行时窗口。 */
	bool bHasActivatedRuntimeWindow = false;

	/** 标记是否包含Observed Activation放置。 */
	bool bHasObservedActivationPlacement = false;

	/** 记录LastObserved视口TopLeft。 */
	FVector2D LastObservedViewportTopLeft = FVector2D::ZeroVector;

	/** 记录LastObservedDesktopTopLeft。 */
	FVector2D LastObservedDesktopTopLeft = FVector2D::ZeroVector;

	/** 记录LastObserved窗口大小。 */
	FVector2D LastObservedWindowSize = FVector2D::ZeroVector;
};
