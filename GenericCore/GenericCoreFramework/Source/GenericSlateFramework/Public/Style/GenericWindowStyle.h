// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenericWindowStyle.generated.h"

class UGenericTextBlockStyle;
class UDevSlateButtonStyle;

/** 封装通用窗口样式资源，供 Slate 样式集和 UMG 控件共享显示参数。 */
UCLASS(Abstract, MinimalAPI, Blueprintable)
class UGenericWindowStyle : public UObject
{
	GENERATED_BODY()

public:
	/** 读取窗口样式，供调用方复用当前对象缓存或引擎状态。 */
	GENERICSLATEFRAMEWORK_API void GetWindowStyle(FWindowStyle& OutWindowStyle) const;

public:
	/** 保存Minimize按钮样式类型引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	TSubclassOf<UDevSlateButtonStyle> MinimizeButtonStyleClass;

	/** 保存Maximize按钮样式引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	TSubclassOf<UDevSlateButtonStyle> MaximizeButtonStyle;

	/** 保存Restore按钮样式引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	TSubclassOf<UDevSlateButtonStyle> RestoreButtonStyle;

	/** 保存关闭按钮样式引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	TSubclassOf<UDevSlateButtonStyle> CloseButtonStyle;

	/** 保存标题文本样式引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	TSubclassOf<UGenericTextBlockStyle> TitleTextStyle;

	/** 保存激活标题画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush ActiveTitleBrush;

	/** 保存非激活标题画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush InactiveTitleBrush;

	/** 保存闪烁标题画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush FlashTitleBrush;

	/** 保存背景颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateColor BackgroundColor=FLinearColor::White;

	/** 保存描边画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush OutlineBrush;

	/** 保存描边颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateColor OutlineColor=FLinearColor::White;

	/** 保存边框画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush BorderBrush;

	/** 保存边框颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateColor BorderColor=FLinearColor::White;

	/** 保存背景画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush BackgroundBrush;

	/** 保存子区域背景画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FSlateBrush ChildBackgroundBrush;

	/** 保存圆角半径数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	int32 CornerRadius=5;

	/** 保存Border内边距显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Window Style")
	FMargin BorderPadding;
};
