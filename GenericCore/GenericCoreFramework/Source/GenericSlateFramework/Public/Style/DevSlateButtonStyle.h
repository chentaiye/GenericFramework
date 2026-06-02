// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DevSlateButtonStyle.generated.h"

/** 封装DevSlate按钮样式资源，供 Slate 样式集和 UMG 控件共享显示参数。 */
UCLASS(Abstract, MinimalAPI, Blueprintable)
class UDevSlateButtonStyle : public UObject
{
	GENERATED_BODY()

public:
	/** 读取按钮样式，供调用方复用当前对象缓存或引擎状态。 */
	GENERICSLATEFRAMEWORK_API void GetButtonStyle(FButtonStyle& OutStyle) const;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateBrush Normal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateBrush Hovered;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateBrush Pressed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateColor NormalForeground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateColor HoveredForeground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateColor PressedForeground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateColor DisabledForeground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FMargin NormalPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FMargin PressedPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateSound HoveredSlateSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Button Style")
	FSlateSound PressedSlateSound;
};
