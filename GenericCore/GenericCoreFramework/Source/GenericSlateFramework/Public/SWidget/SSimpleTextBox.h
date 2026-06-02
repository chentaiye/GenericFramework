// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateType.h"
#include "Framework/Text/TextLayout.h"
#include "Styling/CoreStyle.h"
#include "Layout/Visibility.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/SCompoundWidget.h"

/** 定义简单文本框类型枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class ESimpleTextBoxType:uint8
{
	/** 表示水平位移切换。 */
	Horizontal,

	/** 表示垂直位移切换。 */
	Vertical,

	/** 表示水平Reversal。 */
	HorizontalReversal,

	/** 表示垂直Reversal。 */
	VerticalReversal
};

/** 实现简单文本框 Slate 控件，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SSimpleTextBox : public SCompoundWidget
{
	SLATE_DECLARE_WIDGET(SSimpleTextBox, SCompoundWidget)

public:
	SLATE_BEGIN_ARGS(SSimpleTextBox)
			: _Text(),
			  _TextColor(),
			  _TextFont(),
			  _TextStrikeBrush(),
			  _TextShadowOffset(),
			  _TextShadowColor(),
			  _HighlightText(),
			  _TextHighlightShape(),
			  _AutoWrapText(false),
			  _WrapTextAt(0.0f),
			  _WrappingPolicy(ETextWrappingPolicy::DefaultWrapping),
			  _TransformPolicy(),
			  _Justification(ETextJustify::Left),

			  _MinDesiredWidth(0.0f),
			  _LineHeightPercentage(1.0f),
			  _TextMargin(),
			  _OverflowPolicy(),
			  _Space(0.f),
			  _Image(FCoreStyle::Get().GetDefaultBrush()),
			  _ImageColor(FLinearColor::White),
			  _ImageMargin(),
			  _SimpleTextBoxType(ESimpleTextBoxType::Horizontal),
			  _TextHorizontalAlignment(HAlign_Center),
			  _TextVerticalAlignment(VAlign_Center),
			  _ImageHorizontalAlignment(HAlign_Center),
			  _ImageVerticalAlignment(VAlign_Center)
		{
		}

		SLATE_ATTRIBUTE(FText, Text)
		SLATE_ATTRIBUTE(FSlateColor, TextColor)
		SLATE_ATTRIBUTE(FSlateFontInfo, TextFont)
		SLATE_ATTRIBUTE(const FSlateBrush*, TextStrikeBrush)
		SLATE_ATTRIBUTE(FVector2D, TextShadowOffset)
		SLATE_ATTRIBUTE(FLinearColor, TextShadowColor)
		SLATE_ATTRIBUTE(FText, HighlightText)
		SLATE_ATTRIBUTE(const FSlateBrush*, TextHighlightShape)
		SLATE_ATTRIBUTE(bool, AutoWrapText)
		SLATE_ATTRIBUTE(float, WrapTextAt)
		SLATE_ATTRIBUTE(ETextWrappingPolicy, WrappingPolicy)
		SLATE_ATTRIBUTE(ETextTransformPolicy, TransformPolicy)
		SLATE_ATTRIBUTE(ETextJustify::Type, Justification)
		SLATE_ATTRIBUTE(float, MinDesiredWidth)
		SLATE_ATTRIBUTE(float, LineHeightPercentage)
		SLATE_ATTRIBUTE(FMargin, TextMargin)
		SLATE_ARGUMENT(TOptional<ETextOverflowPolicy>, OverflowPolicy)

		SLATE_ATTRIBUTE(float, Space)

		SLATE_ATTRIBUTE(const FSlateBrush*, Image)
		SLATE_ATTRIBUTE(FSlateColor, ImageColor)
		SLATE_ATTRIBUTE(FMargin, ImageMargin)

		SLATE_ATTRIBUTE(ESimpleTextBoxType, SimpleTextBoxType)
		SLATE_ATTRIBUTE(FMargin, Padding)
		SLATE_ATTRIBUTE(EHorizontalAlignment, TextHorizontalAlignment)
		SLATE_ATTRIBUTE(EVerticalAlignment, TextVerticalAlignment)
		SLATE_ATTRIBUTE(EHorizontalAlignment, ImageHorizontalAlignment)
		SLATE_ATTRIBUTE(EVerticalAlignment, ImageVerticalAlignment)

	SLATE_END_ARGS()

	SSimpleTextBox();

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

protected:
	/** 缓存文本Ptr的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TSharedPtr<STextBlock> TextPtr;

	/** 保存SpacerPtr，供当前对象后续同步逻辑读取。 */
	TSharedPtr<SSpacer> SpacerPtr;

	/** 保存图片Ptr，供当前对象后续同步逻辑读取。 */
	TSharedPtr<SImage> ImagePtr;

protected:
	/** 保存图片MarginAttribute，供当前对象后续同步逻辑读取。 */
	TSlateAttribute<FMargin> ImageMarginAttribute;

protected:
	/** 保存简单文本盒类型Attribute状态，供当前对象后续生命周期和同步逻辑读取。 */
	TSlateAttribute<ESimpleTextBoxType> SimpleTextBoxTypeAttribute;

	/** 保存内边距Attribute显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	TSlateAttribute<FMargin> PaddingAttribute;

	/** 保存文本水平对齐Attribute，供当前对象后续同步逻辑读取。 */
	TSlateAttribute<EHorizontalAlignment> TextHorizontalAlignmentAttribute;

	/** 保存文本垂直对齐Attribute，供当前对象后续同步逻辑读取。 */
	TSlateAttribute<EVerticalAlignment> TextVerticalAlignmentAttribute;

	/** 保存图片水平对齐Attribute，供当前对象后续同步逻辑读取。 */
	TSlateAttribute<EHorizontalAlignment> ImageHorizontalAlignmentAttribute;

	/** 保存图片垂直对齐Attribute，供当前对象后续同步逻辑读取。 */
	TSlateAttribute<EVerticalAlignment> ImageVerticalAlignmentAttribute;

public:
	/** 写入文本，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetText(const TAttribute<FText>& InText) const;

	/** 写入文本颜色，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextColor(const TAttribute<FSlateColor>& InTextColor) const;

	/** 写入文本字体，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextFont(const TAttribute<FSlateFontInfo>& InTextFont) const;

	/** 写入文本删除线画刷，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextStrikeBrush(const TAttribute<const FSlateBrush*>& InTextStrikeBrush) const;

	/** 写入文本阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextShadowOffset(const TAttribute<FVector2D>& InTextShadowOffset) const;

	/** 写入文本阴影颜色，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextShadowColor(const TAttribute<FLinearColor>& InTextShadowColor) const;

	/** 写入文本Highlight文本，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextHighlightText(const TAttribute<FText>& InHighlightText) const;

	/** 写入文本HighlightShape，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextHighlightShape(const TAttribute<const FSlateBrush*>& InTextHighlightShape) const;

	/** 写入自动换行文本，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetAutoWrapText(const TAttribute<bool>& InAutoWrapText) const;

	/** 写入换行文本位置，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetWrapTextAt(const TAttribute<float>& InWrapTextAt) const;

	/** 写入换行Policy，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetWrappingPolicy(const TAttribute<ETextWrappingPolicy>& InWrappingPolicy) const;

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransformPolicy(const TAttribute<ETextTransformPolicy>& InTransformPolicy) const;

	/** 写入文本对齐方式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetJustification(const TAttribute<ETextJustify::Type>& InJustification) const;

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMinDesiredWidth(const TAttribute<float>& InMinDesiredWidth) const;

	/** 写入行Height百分比，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetLineHeightPercentage(const TAttribute<float>& InLineHeightPercentage) const;

	/** 写入文本边距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextMargin(const TAttribute<FMargin>& InTextMargin) const;

	/** 写入溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetOverflowPolicy(const TOptional<ETextOverflowPolicy>& InOverflowPolicy) const;

public:
	/** 写入间距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetSpace(const TAttribute<float>& InSpace) const;

public:
	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	FMargin GetImageMargin() const { return ImageMarginAttribute.Get(); }

	/** 读取可见性，供调用方复用当前对象缓存或引擎状态。 */
	EVisibility GetImageVisibility() const { return ImagePtr->GetVisibility(); }

	/** 写入图片，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImage(const TAttribute<const FSlateBrush*>& InImage) const;

	/** 写入图片Color，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImageColor(const TAttribute<FSlateColor>& InImageColor) const;

	/** 写入图片Margin，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImageMargin(TAttribute<FMargin> InImageMargin);

	/** 写入图片Visibility，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImageVisibility(EVisibility InImageVisibility) const;

public:
	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	ESimpleTextBoxType GetSimpleTextBoxType() const { return SimpleTextBoxTypeAttribute.Get(); }

	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	FMargin GetPadding() const { return PaddingAttribute.Get(); }

	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	EHorizontalAlignment GetTextHorizontalAlignment() const { return TextHorizontalAlignmentAttribute.Get(); }

	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	EVerticalAlignment GetTextVerticalAlignment() const { return TextVerticalAlignmentAttribute.Get(); }

	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	EHorizontalAlignment GetImageHorizontalAlignment() const { return ImageHorizontalAlignmentAttribute.Get(); }

	/** 读取当前缓存值，供 Slate 布局和属性同步复用。 */
	EVerticalAlignment GetImageVerticalAlignment() const { return ImageVerticalAlignmentAttribute.Get(); }

	/** 写入简单文本盒类型，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetSimpleTextBoxType(TAttribute<ESimpleTextBoxType> InSimpleTextBoxType);

	/** 写入内边距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetPadding(TAttribute<FMargin> InPadding);

	/** 写入文本水平对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextHorizontalAlignment(TAttribute<EHorizontalAlignment> InTextHorizontalAlignment);

	/** 写入文本垂直对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextVerticalAlignment(TAttribute<EVerticalAlignment> InTextVerticalAlignment);

	/** 写入图片水平对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImageHorizontalAlignment(TAttribute<EHorizontalAlignment> InImageHorizontalAlignment);

	/** 写入图片垂直对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetImageVerticalAlignment(TAttribute<EVerticalAlignment> InImageVerticalAlignment);

public:
	/** 初始化Simple文本布局实例，保证默认状态能参与反射、资源注册或控件构建。 */
	void UpdateSimpleTextLayout();
};
