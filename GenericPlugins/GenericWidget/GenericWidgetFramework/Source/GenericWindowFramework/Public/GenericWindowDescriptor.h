// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowType.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "GenericWindowDescriptor.generated.h"

class UGenericWindowContent;
class UGenericWindowTitleBar;

/** 通用窗口描述类。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class UGenericWindowDescriptor : public UObject
{
	GENERATED_BODY()

public:
	/** 通用窗口描述构造函数。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowDescriptor();

	/** 记录Drag策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	EGenericWindowDragPolicy DragPolicy=EGenericWindowDragPolicy::InViewportOnly;

	/** 标记是否可以Drag窗口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bCanDragWindow=true;

	/** 标记DragAnywhere状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bDragAnywhere=false;

	/** 标记是否可以Resize窗口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bCanResizeWindow=true;

	/** 标记是否可以关闭窗口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bCanCloseWindow=true;

	/** 标记是否可以Minimize窗口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bCanMinimizeWindow=true;

	/** 标记是否可以Maximize窗口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bCanMaximizeWindow=true;

	/** 标记显示关闭按钮。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bShowCloseButton=true;

	/** 标记显示Minimize按钮。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bShowMinimizeButton=true;

	/** 标记显示Maximize按钮。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bShowMaximizeButton=true;

	/** 标记双精度Click标题栏目标切换Maximize状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bDoubleClickTitleBarToToggleMaximize=true;

	/** 标记焦点On打开。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bFocusOnOpen=true;

	/** 标记自动Bring To Front On Activate。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Behavior")
	bool bAutoBringToFrontOnActivate=true;

	/** 记录InitialZOrder。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	int32 InitialZOrder=100;

	/** 记录InitialRect。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	FGenericWindowRect InitialRect;

	/** 记录标题栏Padding。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	FMargin TitleBarPadding=FMargin(0.f);

	/** 记录ClientAreaPadding。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	FMargin ClientAreaPadding=FMargin(0.f);

	/** 记录ResizeBorderThickness。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	float ResizeBorderThickness=6.0f;

	/** 记录Min窗口Width。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	float MinWindowWidth=240.0f;

	/** 记录Min窗口Height。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	float MinWindowHeight=120.0f;

	/** 记录Max窗口Width。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	float MaxWindowWidth=4096.0f;

	/** 记录Max窗口Height。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	float MaxWindowHeight=4096.0f;

	/** 记录InitialDisplay状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Layout")
	EGenericInGameWindowDisplayState InitialDisplayState=EGenericInGameWindowDisplayState::Expanded;

	/** 记录窗口标题栏类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Class")
	TSubclassOf<UGenericWindowTitleBar> WindowTitleBarClass;

	/** 记录窗口内容类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window|Class")
	TSubclassOf<UGenericWindowContent> WindowContentClass;

#if WITH_EDITOR
	GENERICWINDOWFRAMEWORK_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	GENERICWINDOWFRAMEWORK_API virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif
};
