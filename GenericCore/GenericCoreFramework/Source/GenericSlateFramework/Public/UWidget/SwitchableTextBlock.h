// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "Components/Widget.h"
#include "Components/TextWidgetTypes.h"
#include "SWidget/SSwitchableTextBlock.h"
#include "SwitchableTextBlock.generated.h"

class SSwitchableTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSwitchableTextChangedEvent, const FText&, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwitchableTextCommittedEvent, const FText&, Text, ETextCommit::Type, CommitMethod);

/** 作为可切换文本 UMG 控件，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI, meta=(DisplayName="Switchable Text"))
class USwitchableTextBlock : public UWidget
{
	GENERATED_BODY()

public:
	/** 初始化可切换文本控件默认显示模式和文本样式。 */
	GENERICSLATEFRAMEWORK_API USwitchableTextBlock(const FObjectInitializer& ObjectInitializer);
	GENERICSLATEFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	/** 读取文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API FText GetText() const;

	/** 写入文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API void SetText(FText InText);

	/** 读取提示文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API FText GetHintText() const;

	/** 写入提示文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API void SetHintText(FText InHintText);

	/** 读取显示模式，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API ESwitchableTextBlockMode GetMode() const;

	/** 写入显示模式，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API void SetMode(ESwitchableTextBlockMode InMode);

	/** 读取字体，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API const FSlateFontInfo& GetFont() const;

	/** 写入字体，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetFont(FSlateFontInfo InFontInfo);

	/** 读取颜色和透明度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API FSlateColor GetColorAndOpacity() const;

	/** 写入颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetColorAndOpacity(FSlateColor InColorAndOpacity);

	/** 读取阴影偏移，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API FVector2D GetShadowOffset() const;

	/** 写入阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetShadowOffset(FVector2D InShadowOffset);

	/** 读取阴影颜色和透明度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API FLinearColor GetShadowColorAndOpacity() const;

	/** 写入阴影颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity);

	/** 读取删除线画刷，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API const FSlateBrush& GetStrikeBrush() const;

	/** 写入删除线画刷，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetStrikeBrush(FSlateBrush InStrikeBrush);

	/** 读取最小期望宽度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API float GetMinDesiredWidth() const;

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetMinDesiredWidth(float InMinDesiredWidth);

	/** 读取文本溢出策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API ETextOverflowPolicy GetTextOverflowPolicy() const;

	/** 写入文本溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy);

	/** 读取文本变换策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API ETextTransformPolicy GetTextTransformPolicy() const;

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetTextTransformPolicy(ETextTransformPolicy InTransformPolicy);

	/** 读取文本对齐方式，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API ETextJustify::Type GetJustification() const;

	/** 写入文本对齐方式，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetJustification(ETextJustify::Type InJustification);

	/** 读取只读状态，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API bool GetIsReadOnly() const;

	/** 写入只读状态，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Switchable Text")
	GENERICSLATEFRAMEWORK_API void SetIsReadOnly(bool bInIsReadOnly);

public:
	UPROPERTY(BlueprintAssignable, Category="Switchable Text")
	FOnSwitchableTextChangedEvent OnTextChanged;

	UPROPERTY(BlueprintAssignable, Category="Switchable Text")
	FOnSwitchableTextCommittedEvent OnTextCommitted;

	/** 保存文本内容，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Content")
	FText Text;

	/** 保存提示文本，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Content")
	FText HintText;

	/** 保存显示模式状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Content")
	ESwitchableTextBlockMode Mode=ESwitchableTextBlockMode::Display;

	/** 保存字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateFontInfo Font;

	/** 保存颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateColor ColorAndOpacity;

	/** 保存阴影偏移显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D ShadowOffset;

	/** 保存阴影颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=(DisplayName="Shadow Color"))
	FLinearColor ShadowColorAndOpacity;

	/** 保存删除线画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush StrikeBrush;

	/** 保存最小期望宽度数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float MinDesiredWidth=0.0f;

	/** 保存溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=(DisplayName="Overflow Policy"))
	ETextOverflowPolicy OverflowPolicy=ETextOverflowPolicy::Clip;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=(DisplayName="Transform Policy"))
	ETextTransformPolicy TransformPolicy=ETextTransformPolicy::None;

	/** 保存文本对齐方式状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	TEnumAsByte<ETextJustify::Type> Justification;

	/** 保存Shaped文本选项状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Localization", meta=(ShowOnlyInnerProperties))
	FShapedTextOptions ShapedTextOptions;

	/** 记录只读状态，用于控制后续同步或切换流程。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior")
	bool bIsReadOnly=false;

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif

	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	/** 响应 Slate 文本变更回调，更新缓存文本并转发给外部委托。 */
	void HandleSlateTextChanged(const FText& InText);

	/** 响应 Slate 文本提交回调，更新缓存文本并转发提交方式。 */
	void HandleSlateTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod);

private:
	/** 缓存底层可切换文本控件的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SSwitchableTextBlock> MySwitchableTextBlock;
};
