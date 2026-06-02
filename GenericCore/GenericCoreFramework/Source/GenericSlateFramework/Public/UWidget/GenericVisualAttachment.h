#pragma once

#include "Components/SizeBox.h"
#include "GenericVisualAttachment.generated.h"

/** 作为可视附着 UMG 控件，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI)
class UGenericVisualAttachment : public USizeBox
{
	GENERATED_BODY()

public:
	/** 初始化可视附着控件默认锚点，供后续 Slate 重建时使用。 */
	GENERICSLATEFRAMEWORK_API UGenericVisualAttachment(const FObjectInitializer& ObjectInitializer);

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif

	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICSLATEFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

public:
	/** 保存附着内容锚点，决定子控件在目标区域中的对齐位置。 */
	UPROPERTY(EditAnywhere, Getter, Setter, BlueprintGetter="GetContentAnchor", BlueprintSetter="SetContentAnchor", Category="Visual Attachment")
	FVector2D ContentAnchor;

public:
	/** 读取内容锚点，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintPure, Category="Visual Attachment")
	GENERICSLATEFRAMEWORK_API FVector2D GetContentAnchor() const;

	/** 写入内容锚点，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Visual Attachment")
	GENERICSLATEFRAMEWORK_API void SetContentAnchor(FVector2D InAnchor);

private:
	/** 实现可视附着 Slate 容器，负责组织子控件、同步属性并转发 Slate 事件。 */
	TSharedPtr<class SGenericVisualAttachmentBox> MyAttachmentBox;
};
