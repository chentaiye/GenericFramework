// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowType.h"
#include "Widgets/SCompoundWidget.h"

class SBox;
class UGenericWindowWidget;

/** 作为窗口Frame能力控件，负责把运行时状态呈现到Slate或UMG层。 */
class SGenericWindowFrame : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGenericWindowFrame)
		: _OwnerWindowWidget(nullptr)
	{
	}
		SLATE_ARGUMENT(UGenericWindowWidget*, OwnerWindowWidget)
	SLATE_END_ARGS()

	/** 构建通用窗口Frame布局。 */
	void Construct(const FArguments& InArgs);

	/** 刷新或清理来源Owner相关的运行时缓存。 */
	void RefreshFromOwner();

	/** 获取Measured标题Bar高度。 */
	float GetMeasuredTitleBarHeight() const;

	virtual FReply OnPreviewMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void OnMouseCaptureLost(const FCaptureLostEvent& CaptureLostEvent) override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	/** 根据按钮、边缘和标题栏优先级尝试进入窗口交互。 */
	FReply TryBeginWindowInteraction(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	/** 检测检测Resize句柄，把屏幕位置转换为窗口缩放句柄。 */
	EGenericWindowResizeHandle DetectResizeHandle(const FGeometry& MyGeometry, const FVector2D& ScreenSpacePosition) const;

	/** 判断Within标题Bar是否成立。 */
	bool IsWithinTitleBar(const FGeometry& MyGeometry, const FVector2D& ScreenSpacePosition) const;

	/** 判断Over标题Bar按钮是否成立。 */
	bool IsOverTitleBarButton(const FVector2D& ScreenSpacePosition) const;

	/** 获取Client区域可见性。 */
	EVisibility GetClientAreaVisibility() const;

	/** 缓存拥有者窗口控件。 */
	TWeakObjectPtr<UGenericWindowWidget> OwnerWindowWidget;

	/** 缓存标题Bar Region盒。 */
	TSharedPtr<SBox> TitleBarRegionBox;

	/** 缓存标题Bar盒。 */
	TSharedPtr<SBox> TitleBarBox;

	/** 缓存窗口内容盒。 */
	TSharedPtr<SBox> WindowContentBox;

	/** 记录Interaction启动ScreenPosition。 */
	FVector2D InteractionStartHostPosition = FVector2D::ZeroVector;

	/** 记录上一帧交互使用的宿主坐标，拖拽时按增量推进窗口位置，避免边界夹取造成手感迟滞。 */
	FVector2D InteractionPreviousHostPosition = FVector2D::ZeroVector;

	/** 记录交互开始时的 Slate 屏幕坐标，作为宿主几何短暂失效时的连续移动兜底。 */
	FVector2D InteractionStartFallbackScreenPosition = FVector2D::ZeroVector;

	/** 记录上一帧 Slate 屏幕坐标，宿主几何临时不可用时继续按鼠标增量拖动。 */
	FVector2D InteractionPreviousFallbackScreenPosition = FVector2D::ZeroVector;

	/** 记录Interaction启动窗口Position。 */
	FVector2D InteractionStartWindowPosition = FVector2D::ZeroVector;

	/** 记录Interaction启动窗口大小。 */
	FVector2D InteractionStartWindowSize = FVector2D::ZeroVector;

	/** 记录HoveredResize句柄。 */
	EGenericWindowResizeHandle HoveredResizeHandle = EGenericWindowResizeHandle::None;

	/** 记录激活Resize句柄。 */
	EGenericWindowResizeHandle ActiveResizeHandle = EGenericWindowResizeHandle::None;

	/** 标记IsDragging状态。 */
	bool bIsDragging = false;

	/** 标记IsResizing状态。 */
	bool bIsResizing = false;

	/** 标记本次交互是否已经锁定到宿主逻辑坐标系。 */
	bool bInteractionUsesHostCoordinates = false;
};
