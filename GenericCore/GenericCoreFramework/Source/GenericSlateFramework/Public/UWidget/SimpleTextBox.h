// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Framework/Text/TextLayout.h"
#include "SWidget/SSimpleTextBox.h"
#include "SimpleTextBox.generated.h"

class SSimpleTextBox;

/** 作为简单文本框 UMG 控件，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI)
class USimpleTextBox : public UWidget
{
	GENERATED_UCLASS_BODY()

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif
	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICSLATEFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

public:
	/** 保存文本内容，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetText", BlueprintSetter="SetText", Category="SimpleTextBox|Text", meta=(MultiLine="true"))
	FText Text;

	/** 保存文本颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextColor", BlueprintSetter="SetTextColor", Category="SimpleTextBox|Text")
	FSlateColor TextColor;

	/** 保存文本字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextFont", BlueprintSetter="SetTextFont", Category="SimpleTextBox|Text")
	FSlateFontInfo TextFont;

	/** 保存文本删除线画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextStrikeBrush", BlueprintSetter="SetTextStrikeBrush", Category="SimpleTextBox|Text")
	FSlateBrush TextStrikeBrush;

	/** 保存文本阴影偏移显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextShadowOffset", BlueprintSetter="SetTextShadowOffset", Category="SimpleTextBox|Text")
	FVector2D TextShadowOffset;

	/** 保存文本阴影颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextShadowColor", BlueprintSetter="SetTextShadowColor", Category="SimpleTextBox|Text")
	FLinearColor TextShadowColor;

	/** 保存高亮文本，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetHighlightText", BlueprintSetter="SetHighlightText", Category="SimpleTextBox|Text", meta=(MultiLine="true"))
	FText HighlightText;

	/** 保存文本HighlightShape显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextHighlightShape", BlueprintSetter="SetTextHighlightShape", Category="SimpleTextBox|Text")
	FSlateBrush TextHighlightShape;

	/** 记录是否自动换行，影响 Slate 文本布局宽度计算。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetAutoWrapText", BlueprintSetter="SetAutoWrapText", Category="SimpleTextBox|Text")
	bool AutoWrapText;

	/** 保存手动换行宽度，覆盖默认布局宽度计算。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetWrapTextAt", BlueprintSetter="SetWrapTextAt", Category="SimpleTextBox|Text")
	float WrapTextAt;

	/** 保存文本换行策略，控制单词边界和裁剪行为。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetWrappingPolicy", BlueprintSetter="SetWrappingPolicy", Category="SimpleTextBox|Text")
	ETextWrappingPolicy WrappingPolicy;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTransformPolicy", BlueprintSetter="SetTransformPolicy", Category="SimpleTextBox|Text")
	ETextTransformPolicy TransformPolicy;

	/** 保存文本对齐方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetJustification", BlueprintSetter="SetJustification", Category="SimpleTextBox|Text")
	TEnumAsByte<ETextJustify::Type> Justification;

	/** 保存最小期望宽度数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetMinDesiredWidth", BlueprintSetter="SetMinDesiredWidth", Category="SimpleTextBox|Text")
	float MinDesiredWidth;

	/** 保存行高比例，供文本布局计算垂直间距。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetLineHeightPercentage", BlueprintSetter="SetLineHeightPercentage", Category="SimpleTextBox|Text")
	float LineHeightPercentage;

	/** 保存文本边距显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextMargin", BlueprintSetter="SetTextMargin", Category="SimpleTextBox|Text")
	FMargin TextMargin;

	/** 保存溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetOverflowPolicy", BlueprintSetter="SetOverflowPolicy", Category="SimpleTextBox|Text")
	ETextOverflowPolicy OverflowPolicy;

public:
	/** 保存文字与图片之间的间距。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetSpace", BlueprintSetter="SetSpace", Category="SimpleTextBox|Space")
	float Space;

public:
	/** 保存图片，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImage", BlueprintSetter="SetImage", Category="SimpleTextBox|Image")
	FSlateBrush Image;

	/** 保存图片Color，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImageColor", BlueprintSetter="SetImageColor", Category="SimpleTextBox|Image")
	FSlateColor ImageColor;

	/** 保存图片Margin，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImageMargin", BlueprintSetter="SetImageMargin", Category="SimpleTextBox|Image")
	FMargin ImageMargin;

	/** 保存图片Visibility，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImageVisibility", BlueprintSetter="SetImageVisibility", Category="SimpleTextBox|Image")
	ESlateVisibility ImageVisibility;

public:
	/** 保存简单文本盒类型状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetSimpleTextBoxType", BlueprintSetter="SetSimpleTextBoxType", Category="SimpleTextBox|Layout")
	ESimpleTextBoxType SimpleTextBoxType;

	/** 保存内边距显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetPadding", BlueprintSetter="SetPadding", Category="SimpleTextBox|Layout")
	FMargin Padding;

	/** 保存文本水平对齐，用于组合文本和图片的布局位置。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextHorizontalAlignment", BlueprintSetter="SetTextHorizontalAlignment", Category="SimpleTextBox|Layout")
	TEnumAsByte<EHorizontalAlignment> TextHorizontalAlignment;

	/** 保存文本垂直对齐，用于组合文本和图片的布局位置。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetTextVerticalAlignment", BlueprintSetter="SetTextVerticalAlignment", Category="SimpleTextBox|Layout")
	TEnumAsByte<EVerticalAlignment> TextVerticalAlignment;

	/** 保存图片水平对齐，用于组合文本和图片的布局位置。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImageHorizontalAlignment", BlueprintSetter="SetImageHorizontalAlignment", Category="SimpleTextBox|Layout")
	TEnumAsByte<EHorizontalAlignment> ImageHorizontalAlignment;

	/** 保存图片垂直对齐，用于组合文本和图片的布局位置。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetImageVerticalAlignment", BlueprintSetter="SetImageVerticalAlignment", Category="SimpleTextBox|Layout")
	TEnumAsByte<EVerticalAlignment> ImageVerticalAlignment;

	/* Text */
public:
	/** 读取文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FText& GetText() const;

	/** 写入文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetText(const FText& InText);

	/** 读取文本颜色，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FSlateColor& GetTextColor() const;

	/** 写入文本颜色，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextColor(const FSlateColor& InTextColor);

	/** 读取文本字体，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FSlateFontInfo& GetTextFont() const;

	/** 写入文本字体，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextFont(const FSlateFontInfo& InTextFont);

	/** 读取文本删除线画刷，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FSlateBrush& GetTextStrikeBrush() const;

	/** 写入文本删除线画刷，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextStrikeBrush(const FSlateBrush& InTextStrikeBrush);

	/** 读取文本阴影偏移，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API FVector2D GetTextShadowOffset() const;

	/** 写入文本阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextShadowOffset(FVector2D InTextShadowOffset);

	/** 读取文本阴影颜色，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API FLinearColor GetTextShadowColor() const;

	/** 写入文本阴影颜色，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextShadowColor(FLinearColor InTextShadowColor);

	/** 读取Highlight文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FText& GetHighlightText() const;

	/** 写入Highlight文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetHighlightText(const FText& InHighlightText);

	/** 读取文本HighlightShape，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API const FSlateBrush& GetTextHighlightShape() const;

	/** 写入文本HighlightShape，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextHighlightShape(const FSlateBrush& InTextHighlightShape);

	/** 读取自动换行文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API bool GetAutoWrapText() const;

	/** 写入自动换行文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetAutoWrapText(bool InAutoWrapText);

	/** 读取换行文本位置，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API float GetWrapTextAt() const;

	/** 写入换行文本位置，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetWrapTextAt(float InWrapTextAt);

	/** 读取换行Policy，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API ETextWrappingPolicy GetWrappingPolicy() const;

	/** 写入换行Policy，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetWrappingPolicy(ETextWrappingPolicy InWrappingPolicy);

	/** 读取文本变换策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API ETextTransformPolicy GetTransformPolicy() const;

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTransformPolicy(ETextTransformPolicy InTransformPolicy);

	/** 读取文本对齐方式，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API ETextJustify::Type GetJustification() const;

	/** 写入文本对齐方式，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetJustification(ETextJustify::Type InJustification);

	/** 读取最小期望宽度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API float GetMinDesiredWidth() const;

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetMinDesiredWidth(float InMinDesiredWidth);

	/** 读取行Height百分比，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API float GetLineHeightPercentage() const;

	/** 写入行Height百分比，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetLineHeightPercentage(float InLineHeightPercentage);

	/** 读取文本边距，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API FMargin GetTextMargin() const;

	/** 写入文本边距，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetTextMargin(const FMargin& InTextMargin);

	/** 读取溢出策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API ETextOverflowPolicy GetOverflowPolicy() const;

	/** 写入溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Text")
	GENERICSLATEFRAMEWORK_API void SetOverflowPolicy(ETextOverflowPolicy InOverflowPolicy);

	/* Spacer */
public:
	/** 读取间距，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Space")
	GENERICSLATEFRAMEWORK_API float GetSpace() const;

	/** 写入间距，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Space")
	GENERICSLATEFRAMEWORK_API void SetSpace(float InSpace);

	/* Image */
public:
	/** 读取图片，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API const FSlateBrush& GetImage() const;

	/** 写入图片，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API void SetImage(const FSlateBrush& InImage);

	/** 读取图片Color，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API const FSlateColor& GetImageColor() const;

	/** 写入图片Color，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API void SetImageColor(const FSlateColor& InImageColor);

	/** 读取图片Margin，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API FMargin GetImageMargin() const;

	/** 写入图片Margin，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API void SetImageMargin(const FMargin& InImageMargin);

	/** 读取图片Visibility，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API ESlateVisibility GetImageVisibility() const;

	/** 写入图片Visibility，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Image")
	GENERICSLATEFRAMEWORK_API void SetImageVisibility(ESlateVisibility InImageVisibility);

	/* Layout */
public:
	/** 读取简单文本盒类型，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API ESimpleTextBoxType GetSimpleTextBoxType() const;

	/** 写入简单文本盒类型，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetSimpleTextBoxType(ESimpleTextBoxType InSimpleTextBoxType);

	/** 读取内边距，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API FMargin GetPadding() const;

	/** 写入内边距，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetPadding(const FMargin& InPadding);

	/** 读取文本水平对齐，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API EHorizontalAlignment GetTextHorizontalAlignment() const;

	/** 写入文本水平对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetTextHorizontalAlignment(EHorizontalAlignment InTextHorizontalAlignment);

	/** 读取文本垂直对齐，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API EVerticalAlignment GetTextVerticalAlignment() const;

	/** 写入文本垂直对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetTextVerticalAlignment(EVerticalAlignment InTextVerticalAlignment);

	/** 读取图片水平对齐，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API EHorizontalAlignment GetImageHorizontalAlignment() const;

	/** 写入图片水平对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetImageHorizontalAlignment(EHorizontalAlignment InImageHorizontalAlignment);

	/** 读取图片垂直对齐，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API EVerticalAlignment GetImageVerticalAlignment() const;

	/** 写入图片垂直对齐，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="SimpleTextBox|Layout")
	GENERICSLATEFRAMEWORK_API void SetImageVerticalAlignment(EVerticalAlignment InImageVerticalAlignment);

protected:
	/** 缓存底层简单文本框的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SSimpleTextBox> MySimpleTextBox;
};
