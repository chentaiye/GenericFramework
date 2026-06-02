// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenericTextBlockStyle.generated.h"

/** 作为通用文本块样式，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(Abstract, MinimalAPI, Blueprintable)
class UGenericTextBlockStyle : public UObject
{
	GENERATED_BODY()

public:
	/** 读取文本块样式，供调用方复用当前对象缓存或引擎状态。 */
	GENERICSLATEFRAMEWORK_API void GetTextBlockStyle(FTextBlockStyle& OutTextBlockStyle) const;

public:
	/** 保存字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateFontInfo Font;

	/** 保存颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateColor ColorAndOpacity;

	/** 保存阴影偏移状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FDeprecateSlateVector2D ShadowOffset;

	/** 保存阴影颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FLinearColor ShadowColorAndOpacity;

	/** 保存已选择Background颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateColor SelectedBackgroundColor;

	/** 保存Highlight颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateColor HighlightColor;

	/** 保存HighlightShape显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateBrush HighlightShape;

	/** 保存删除线画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateBrush StrikeBrush;

	/** 保存Underline画刷显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	FSlateBrush UnderlineBrush;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	ETextTransformPolicy TransformPolicy;

	/** 保存溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Text Block Style")
	ETextOverflowPolicy OverflowPolicy;
};
