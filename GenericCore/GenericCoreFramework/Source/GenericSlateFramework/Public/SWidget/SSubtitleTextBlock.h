// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Framework/Text/TextLayout.h"
#include "Layout/Margin.h"
#include "Styling/SlateColor.h"
#include "Widgets/SLeafWidget.h"

class FSlateTextLayout;

/** 实现字幕 Slate 控件，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SSubtitleTextBlock : public SLeafWidget
{
	SLATE_DECLARE_WIDGET(SSubtitleTextBlock, SLeafWidget)

public:
	SLATE_BEGIN_ARGS(SSubtitleTextBlock)

		: _ColorAndOpacity(FLinearColor::White)
		, _ShadowOffset(FVector2D::ZeroVector)
		, _ShadowColorAndOpacity(FLinearColor::Transparent)
		, _MinDesiredWidth(0.0f)
		, _TextTransformPolicy(ETextTransformPolicy::None)
		, _TextOverflowPolicy(ETextOverflowPolicy::Clip)
		, _AutoWrapText(false)
		, _WrapTextAt(0.0f)
		, _WrappingPolicy(ETextWrappingPolicy::DefaultWrapping)
		, _LineHeightPercentage(1.0f)
		, _ApplyLineHeightToBottomLine(true)
		, _Justification(ETextJustify::Left)
		, _TailVisibleLineCount(0)
		, _MaxDisplayHeight(0.0f)
		, _GradientLineCount(0)
		, _LineOpacityStep(0.0f)
	{
	}
		SLATE_ARGUMENT(TArray<FText>, TextLines)
		SLATE_ARGUMENT(FSlateFontInfo, Font)
		SLATE_ARGUMENT(FSlateColor, ColorAndOpacity)
		SLATE_ARGUMENT(FVector2D, ShadowOffset)
		SLATE_ARGUMENT(FLinearColor, ShadowColorAndOpacity)
		SLATE_ARGUMENT(float, MinDesiredWidth)
		SLATE_ARGUMENT(ETextTransformPolicy, TextTransformPolicy)
		SLATE_ARGUMENT(ETextOverflowPolicy, TextOverflowPolicy)
		SLATE_ARGUMENT(bool, AutoWrapText)
		SLATE_ARGUMENT(float, WrapTextAt)
		SLATE_ARGUMENT(ETextWrappingPolicy, WrappingPolicy)
		SLATE_ARGUMENT(FMargin, Margin)
		SLATE_ARGUMENT(float, LineHeightPercentage)
		SLATE_ARGUMENT(bool, ApplyLineHeightToBottomLine)
		SLATE_ARGUMENT(ETextJustify::Type, Justification)
		SLATE_ARGUMENT(TOptional<ETextShapingMethod>, TextShapingMethod)
		SLATE_ARGUMENT(TOptional<ETextFlowDirection>, TextFlowDirection)
		SLATE_ARGUMENT(int32, TailVisibleLineCount)
		SLATE_ARGUMENT(float, MaxDisplayHeight)
		SLATE_ARGUMENT(int32, GradientLineCount)
		SLATE_ARGUMENT(float, LineOpacityStep)
	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	/** 写入文本行集合，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextLines(const TArray<FText>& InTextLines);

	/** 写入字体，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetFont(const FSlateFontInfo& InFont);

	/** 写入颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetColorAndOpacity(const FSlateColor& InColorAndOpacity);

	/** 写入阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetShadowOffset(FVector2D InShadowOffset);

	/** 写入阴影颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity);

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMinDesiredWidth(float InMinDesiredWidth);

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransformPolicy(ETextTransformPolicy InTransformPolicy);

	/** 写入溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetOverflowPolicy(ETextOverflowPolicy InOverflowPolicy);

	/** 写入文本塑形方式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextShapingMethod(const TOptional<ETextShapingMethod>& InTextShapingMethod);

	/** 写入文本流向，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextFlowDirection(const TOptional<ETextFlowDirection>& InTextFlowDirection);

	/** 写入自动换行开关，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetAutoWrapText(bool bInAutoWrapText);

	/** 写入固定换行宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetWrapTextAt(float InWrapTextAt);

	/** 写入可绑定的换行宽度属性，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetWrapTextAt(const TAttribute<float>& InWrapTextAt);

	/** 写入文本换行策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetWrappingPolicy(ETextWrappingPolicy InWrappingPolicy);

	/** 写入边距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMargin(const FMargin& InMargin);

	/** 写入行高比例，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetLineHeightPercentage(float InLineHeightPercentage);

	/** 写入是否把行高应用到最后一行，并同步到底层 Slate 控件。 */
	void SetApplyLineHeightToBottomLine(bool bInApplyLineHeightToBottomLine);

	/** 写入文本对齐方式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetJustification(ETextJustify::Type InJustification);

	/** 写入尾部可见行数，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTailVisibleLineCount(int32 InTailVisibleLineCount);

	/** 写入最大显示高度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMaxDisplayHeight(float InMaxDisplayHeight);

	/** 写入渐隐行数，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetGradientLineCount(int32 InGradientLineCount);

	/** 写入行透明度步长，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetLineOpacityStep(float InLineOpacityStep);

	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

private:
	/** 标记字幕显示内容失效，触发后续布局和绘制刷新。 */
	void InvalidateSubtitle(EInvalidateWidgetReason InvalidationReason);

	/** 重置字幕文本布局缓存，确保尺寸或内容变化后重新排版。 */
	void ResetLayouts() const;

	/** 按当前缩放更新文本布局缓存，供期望尺寸和绘制流程复用。 */
	void UpdateLayouts(float LayoutScaleMultiplier) const;

	/** 根据控件几何和设置计算换行宽度，避免字幕文本超出显示区域。 */
	float CalculateWrappingWidth() const;

	/** 构建单行字幕样式，合并基础字体、颜色和渐隐参数。 */
	FTextBlockStyle BuildLineStyle(float InLineAlpha) const;

	/** 按文本变换策略处理字幕字符串，统一大小写和显示格式。 */
	FString TransformString(const FString& InSource) const;

	/** 把公共文本布局设置应用到 Slate 文本布局对象。 */
	void ApplyCommonLayoutSettings(FSlateTextLayout& InLayout, float LayoutScaleMultiplier, float WrappingWidth, ETextOverflowPolicy InOverflowPolicy) const;

private:
	/** 缓存文本行集合集合，供批量同步、查找或编辑器刷新使用。 */
	TArray<FText> TextLines;

	/** 保存字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FSlateFontInfo Font;

	/** 保存颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FSlateColor ColorAndOpacity;

	/** 保存阴影偏移显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FVector2D ShadowOffset = FVector2D::ZeroVector;

	/** 保存阴影颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FLinearColor ShadowColorAndOpacity = FLinearColor::Transparent;

	/** 保存最小期望宽度数值，供布局、渲染或运行时逻辑读取。 */
	float MinDesiredWidth = 0.0f;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextTransformPolicy TransformPolicy = ETextTransformPolicy::None;

	/** 保存溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextOverflowPolicy OverflowPolicy = ETextOverflowPolicy::Clip;

	/** 保存文本塑形方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	TOptional<ETextShapingMethod> TextShapingMethod;

	/** 保存文本流向状态，供当前对象后续生命周期和同步逻辑读取。 */
	TOptional<ETextFlowDirection> TextFlowDirection;

	/** 记录是否自动换行，影响 Slate 文本布局宽度计算。 */
	bool bAutoWrapText = false;

	/** 保存手动换行宽度，覆盖默认布局宽度计算。 */
	float WrapTextAt = 0.0f;

	/** 保存文本换行策略，控制单词边界和裁剪行为。 */
	ETextWrappingPolicy WrappingPolicy = ETextWrappingPolicy::DefaultWrapping;

	/** 保存边距显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FMargin Margin;

	/** 保存行高比例，供文本布局计算垂直间距。 */
	float LineHeightPercentage = 1.0f;

	/** 记录是否把行高应用到最后一行，影响字幕垂直排布。 */
	bool bApplyLineHeightToBottomLine = true;

	/** 保存文本对齐方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextJustify::Type Justification = ETextJustify::Left;

	/** 保存尾部可见行数数值，供布局、渲染或运行时逻辑读取。 */
	int32 TailVisibleLineCount = 0;

	/** 保存最大显示高度数值，供布局、渲染或运行时逻辑读取。 */
	float MaxDisplayHeight = 0.0f;

	/** 保存渐隐行数数值，供布局、渲染或运行时逻辑读取。 */
	int32 GradientLineCount = 0;

	/** 保存行透明度步长数值，供布局、渲染或运行时逻辑读取。 */
	float LineOpacityStep = 0.0f;

	/** 缓存原始文本布局对象，用于源文本测量和换行计算。 */
	mutable TSharedPtr<FSlateTextLayout> SourceTextLayout;

	/** 缓存最终显示布局对象，用于 OnPaint 绘制和尺寸复用。 */
	mutable TSharedPtr<FSlateTextLayout> DisplayTextLayout;

	/** 保存上次参与布局计算的尺寸，避免重复构建文本布局。 */
	mutable FVector2f CachedSize = FVector2f::ZeroVector;

	/** 保存上次计算出的期望尺寸，供 Slate 布局查询复用。 */
	mutable FVector2D CachedDesiredSize = FVector2D::ZeroVector;
};
