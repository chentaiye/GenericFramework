// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "GenericButton.generated.h"

class SBackgroundBlur;
class SBox;
class UPanelSlot;

#if WITH_EDITOR
struct FPropertyChangedEvent;
#endif

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPDelegate_OnGenericButtonDoubleClicked);

/** 提供背景模糊、最小尺寸和双击事件的通用按钮。 */
UCLASS(MinimalAPI)
class UGenericButton : public UButton
{
	GENERATED_BODY()

public:
	/** 初始化通用按钮默认值。 */
	GENERICBUTTONFRAMEWORK_API UGenericButton(const FObjectInitializer& ObjectInitializer);

	/** 设置背景模糊强度，0表示无模糊。 */
	UFUNCTION(BlueprintCallable, Category="Button|Appearance")
	GENERICBUTTONFRAMEWORK_API void SetBlurStrength(float InBlurStrength);

	/** 设置背景模糊半径，0表示使用引擎自动半径。 */
	UFUNCTION(BlueprintCallable, Category="Button|Appearance")
	GENERICBUTTONFRAMEWORK_API void SetBlurRadius(int32 InBlurRadius);

	/** 设置按钮最小宽度，0表示不限制。 */
	UFUNCTION(BlueprintCallable, Category="Button|Layout")
	GENERICBUTTONFRAMEWORK_API void SetMinWidth(float InMinWidth);

	/** 设置按钮最小高度，0表示不限制。 */
	UFUNCTION(BlueprintCallable, Category="Button|Layout")
	GENERICBUTTONFRAMEWORK_API void SetMinHeight(float InMinHeight);

	/** 设置按钮是否广播点击和双击事件，不改变Slate启用状态。 */
	UFUNCTION(BlueprintCallable, Category="Button|Interaction")
	GENERICBUTTONFRAMEWORK_API void SetInteractionEnabled(bool bInInteractionEnabled);

public:
	/** 记录BlurStrength。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance", meta=(ClampMin="0.0"))
	float BlurStrength = 0.0f;

	/** 记录BlurRadius。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance", meta=(ClampMin="0"))
	int32 BlurRadius = 0;

	/** 记录MinWidth。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Layout", meta=(ClampMin="0.0"))
	float MinWidth = 0.0f;

	/** 记录MinHeight。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Layout", meta=(ClampMin="0.0"))
	float MinHeight = 0.0f;

	/** 标记按钮是否允许广播点击和双击事件。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	bool bInteractionEnabled = true;

	UPROPERTY(BlueprintAssignable, Category="Button|Event")
	FBPDelegate_OnGenericButtonDoubleClicked OnDoubleClickedEvent;

public:
	GENERICBUTTONFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICBUTTONFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
	GENERICBUTTONFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICBUTTONFRAMEWORK_API virtual void OnSlotAdded(UPanelSlot* InSlot) override;

#if WITH_EDITOR
	GENERICBUTTONFRAMEWORK_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	/** 响应Slate句柄Clicked，把Slate点击事件转换为通用按钮委托。 */
	FReply SlateHandleGenericClicked();

	/** 响应Slate句柄双精度Clicked，把Slate点击事件转换为通用按钮委托。 */
	FReply SlateHandleGenericDoubleClicked();

	/** 同步最小尺寸和背景模糊到Slate控件。 */
	void ApplyGenericButtonProperties();

	/** 缓存最小尺寸约束容器。 */
	TSharedPtr<SBox> MySizeBox;

	/** 缓存背景模糊控件。 */
	TSharedPtr<SBackgroundBlur> MyBackgroundBlur;
};
