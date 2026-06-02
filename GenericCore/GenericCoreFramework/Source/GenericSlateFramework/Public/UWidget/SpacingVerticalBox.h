// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/VerticalBox.h"
#include "SpacingVerticalBox.generated.h"

class SSpacingVerticalBox;
class UVerticalBoxSlot;

/** 作为带间距垂直框，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI)
class USpacingVerticalBox : public UVerticalBox
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif

public:
	/** 添加ChildTo间距垂直盒，并同步内部缓存、显示状态或事件绑定。 */
	UFUNCTION(BlueprintCallable, Category="Spacing Vertical Box")
	GENERICSLATEFRAMEWORK_API UVerticalBoxSlot* AddChildToSpacingVerticalBox(UWidget* Content);

	/** 写入InnerSlot内边距，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Spacing Vertical Box")
	GENERICSLATEFRAMEWORK_API void SetInnerSlotPadding(float InInnerSlotPadding);

	/** 读取InnerSlot内边距，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="Spacing Vertical Box")
	GENERICSLATEFRAMEWORK_API float GetInnerSlotPadding() const;

	GENERICSLATEFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;

public:
	/** 保存InnerSlot内边距数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spacing")
	float InnerSlotPadding=0.0f;

private:
	/** 保存MySpacing垂直Box，供当前对象后续同步逻辑读取。 */
	TSharedPtr<SSpacingVerticalBox> MySpacingVerticalBox;
};
