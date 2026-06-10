// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "UObject/Object.h"
#include "GenericButtonStyle.generated.h"

#if WITH_EDITOR
struct FPropertyChangedEvent;
#endif

/** 作为UIButtonStyle能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(BlueprintType, Blueprintable)
class GENERICBUTTONFRAMEWORK_API UGenericButtonStyle : public UObject
{
	GENERATED_BODY()

public:
	/** 根据当前对象数据生成Slate按钮样式。 */
	FButtonStyle ToButtonStyle() const;

	/** 生成缺失样式时使用的全透明按钮样式。 */
	static FButtonStyle MakeTransparentButtonStyle();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	/** 记录Normal。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateBrush Normal;

	/** 记录Hovered。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateBrush Hovered;

	/** 记录Pressed。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateBrush Pressed;

	/** 记录NormalForeground。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateColor NormalForeground;

	/** 记录HoveredForeground。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateColor HoveredForeground;

	/** 记录PressedForeground。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateColor PressedForeground;

	/** 记录NormalPadding。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FMargin NormalPadding;

	/** 记录HoveredPadding。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FMargin HoveredPadding;

	/** 记录PressedPadding。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FMargin PressedPadding;

	/** 记录HoveredSlateSound。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	FSlateSound HoveredSlateSound;

	/** 记录PressedSlateSound。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	FSlateSound PressedSlateSound;
};
