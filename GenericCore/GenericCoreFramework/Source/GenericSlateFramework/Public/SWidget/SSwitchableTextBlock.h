// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Framework/Text/TextLayout.h"
#include "Widgets/SCompoundWidget.h"
#include "SSwitchableTextBlock.generated.h"

class SEditableText;
class STextBlock;
class SWidgetSwitcher;

/** 定义可切换文本模式枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class ESwitchableTextBlockMode : uint8
{
	/** 表示只读显示模式。 */
	Display,

	/** 表示可编辑输入模式。 */
	Editable
};

/** 实现可切换文本 Slate 控件，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SSwitchableTextBlock : public SCompoundWidget
{
	SLATE_DECLARE_WIDGET(SSwitchableTextBlock, SCompoundWidget)

public:
	SLATE_BEGIN_ARGS(SSwitchableTextBlock)

		: _Mode(ESwitchableTextBlockMode::Display)
		, _ColorAndOpacity(FLinearColor::White)
		, _ShadowOffset(FVector2D::ZeroVector)
		, _ShadowColorAndOpacity(FLinearColor::Transparent)
		, _MinDesiredWidth(0.0f)
		, _OverflowPolicy(ETextOverflowPolicy::Clip)
		, _TransformPolicy(ETextTransformPolicy::None)
		, _Justification(ETextJustify::Left)
		, _IsReadOnly(false)
	{
	}
		SLATE_ARGUMENT(ESwitchableTextBlockMode, Mode)
		SLATE_ARGUMENT(FText, Text)
		SLATE_ARGUMENT(FText, HintText)
		SLATE_ARGUMENT(FSlateFontInfo, Font)
		SLATE_ARGUMENT(FSlateColor, ColorAndOpacity)
		SLATE_ARGUMENT(FVector2D, ShadowOffset)
		SLATE_ARGUMENT(FLinearColor, ShadowColorAndOpacity)
		SLATE_ARGUMENT(FSlateBrush, StrikeBrush)
		SLATE_ARGUMENT(float, MinDesiredWidth)
		SLATE_ARGUMENT(ETextOverflowPolicy, OverflowPolicy)
		SLATE_ARGUMENT(ETextTransformPolicy, TransformPolicy)
		SLATE_ARGUMENT(ETextJustify::Type, Justification)
		SLATE_ARGUMENT(TOptional<ETextShapingMethod>, TextShapingMethod)
		SLATE_ARGUMENT(TOptional<ETextFlowDirection>, TextFlowDirection)
		SLATE_ARGUMENT(bool, IsReadOnly)
		SLATE_EVENT(FOnTextChanged, OnTextChanged)
		SLATE_EVENT(FOnTextCommitted, OnTextCommitted)
	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	/** 写入显示模式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMode(ESwitchableTextBlockMode InMode);

	/** 写入文本，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetText(const FText& InText);

	/** 写入提示文本，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetHintText(const FText& InHintText);

	/** 写入字体，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetFont(const FSlateFontInfo& InFont);

	/** 写入颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetColorAndOpacity(const FSlateColor& InColorAndOpacity);

	/** 写入阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetShadowOffset(FVector2D InShadowOffset);

	/** 写入阴影颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity);

	/** 写入删除线画刷，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetStrikeBrush(const FSlateBrush& InStrikeBrush);

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetMinDesiredWidth(float InMinDesiredWidth);

	/** 写入溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetOverflowPolicy(ETextOverflowPolicy InOverflowPolicy);

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransformPolicy(ETextTransformPolicy InTransformPolicy);

	/** 写入文本对齐方式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetJustification(ETextJustify::Type InJustification);

	/** 写入文本塑形方式，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextShapingMethod(const TOptional<ETextShapingMethod>& InTextShapingMethod);

	/** 写入文本流向，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTextFlowDirection(const TOptional<ETextFlowDirection>& InTextFlowDirection);

	/** 写入只读状态，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetIsReadOnly(bool bInIsReadOnly);

private:
	/** 响应 Slate 文本变更回调，更新缓存文本并转发给外部委托。 */
	void HandleEditableTextChanged(const FText& InText);

	/** 响应 Slate 文本提交回调，更新缓存文本并转发提交方式。 */
	void HandleEditableTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod);

	/** 同步显示文本，把缓存属性推送到当前 Slate 显示对象。 */
	void SynchronizeDisplayText();

private:
	/** 缓存内部切换器的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TSharedPtr<SWidgetSwitcher> WidgetSwitcher;

	/** 缓存只读文本块的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TSharedPtr<STextBlock> DisplayTextBlock;

	/** 缓存可编辑文本框的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TSharedPtr<SEditableText> EditableText;

	FOnTextChanged ExternalOnTextChanged;

	FOnTextCommitted ExternalOnTextCommitted;

	/** 保存显示模式状态，供当前对象后续生命周期和同步逻辑读取。 */
	ESwitchableTextBlockMode Mode=ESwitchableTextBlockMode::Display;

	/** 保存文本内容，供当前对象后续同步逻辑读取。 */
	FText Text;

	/** 保存提示文本，供当前对象后续同步逻辑读取。 */
	FText HintText;

	/** 保存字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FSlateFontInfo Font;

	/** 保存颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FSlateColor ColorAndOpacity;

	/** 保存阴影偏移显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FVector2D ShadowOffset=FVector2D::ZeroVector;

	/** 保存阴影颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FLinearColor ShadowColorAndOpacity=FLinearColor::Transparent;

	/** 保存删除线画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FSlateBrush StrikeBrush;

	/** 保存最小期望宽度数值，供布局、渲染或运行时逻辑读取。 */
	float MinDesiredWidth=0.0f;

	/** 保存溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextOverflowPolicy OverflowPolicy=ETextOverflowPolicy::Clip;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextTransformPolicy TransformPolicy=ETextTransformPolicy::None;

	/** 保存文本对齐方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	ETextJustify::Type Justification=ETextJustify::Left;

	/** 保存文本塑形方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	TOptional<ETextShapingMethod> TextShapingMethod;

	/** 保存文本流向状态，供当前对象后续生命周期和同步逻辑读取。 */
	TOptional<ETextFlowDirection> TextFlowDirection;

	/** 记录只读状态，用于控制后续同步或切换流程。 */
	bool bIsReadOnly=false;
};
