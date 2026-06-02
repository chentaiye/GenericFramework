// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Slate.generated.h"

class USpline2DSlot;
class UBackgroundBlurSlot;
class UWidget;
class UButtonSlot;
class UStackBoxSlot;
class UBorder;
class UImage;

/** 集中暴露Slate蓝图函数库接口，让蓝图通过稳定入口访问Slate/UMG功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Slate : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/* Layout */
public:
	/** 把 UWidget 的插槽转换为StackBox槽位，便于蓝图访问具体布局参数。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Slot")
	static GENERICSLATEFRAMEWORK_API UStackBoxSlot* SlotAsStackBoxSlot(const UWidget* Widget);

	/** 把 UWidget 的插槽转换为Button槽位，便于蓝图访问具体布局参数。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Slot")
	static GENERICSLATEFRAMEWORK_API UButtonSlot* SlotAsButtonSlot(const UWidget* Widget);

	/** 把 UWidget 的插槽转换为BackgroundBlur槽位，便于蓝图访问具体布局参数。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Slot")
	static GENERICSLATEFRAMEWORK_API UBackgroundBlurSlot* SlotAsBackgroundBlurSlot(const UWidget* Widget);

	/* Image */
public:
	/** 判断图片画刷包装是否包含可解析资源，避免 Slate 构建时使用空画刷。 */
	UFUNCTION(BlueprintPure, DisplayName="IsValid(ImageBrush)", Category="BPFunctions_Slate|Image", meta=(CompactNodeTitle="IsValid"))
	static GENERICSLATEFRAMEWORK_API bool IsValid_ImageBrush(const FImageBrush& InImageBrush);

	/** 写入图片Brush，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slate|Image")
	static GENERICSLATEFRAMEWORK_API void SetImageBrush(UImage* InImage, FImageBrush InImageBrush);

	/** 转换To图片画刷，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Image", meta=(DisplayName="To Image Brush", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICSLATEFRAMEWORK_API FImageBrush ConvToImageBrush(const FSlateBrush& InSlateBrush);

	/** 转换图片ConvToSlate画刷，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Image", meta=(DisplayName="To Slate Brush(Image)", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICSLATEFRAMEWORK_API FSlateBrush Image_ConvToSlateBrush(const FImageBrush& InImageBrush);

	/* Border */
public:
	/** 判断ValidBorder画刷，供调用方选择后续流程或过滤无效输入。 */
	UFUNCTION(BlueprintPure, DisplayName="IsValid(BorderBrush)", Category="BPFunctions_Slate|Border", meta=(CompactNodeTitle="IsValid"))
	static GENERICSLATEFRAMEWORK_API bool IsValid_BorderBrush(const FBorderBrush& InBorderBrush);

	/** 写入边框画刷，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slate|Border")
	static GENERICSLATEFRAMEWORK_API void SetBorderBrush(UBorder* InBorder, FBorderBrush InBorderBrush);

	/** 转换To边框画刷，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Border", meta=(DisplayName="To Border Brush", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICSLATEFRAMEWORK_API FBorderBrush ConvToBorderBrush(const FSlateBrush& InSlateBrush);

	/** 转换边框ConvToSlate画刷，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slate|Border", meta=(DisplayName="To Slate Brush(Border)", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICSLATEFRAMEWORK_API FSlateBrush Border_ConvToSlateBrush(const FBorderBrush& InBorderBrush);
};
