// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "GenericWindowSlot.generated.h"

class UGenericWindowAnchor;

/** 作为窗口槽位能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class UGenericWindowSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	/** 设置窗口Anchor。 */
	UFUNCTION(BlueprintCallable, Category="Layout")
	GENERICWINDOWFRAMEWORK_API void SetWindowAnchor(const FVector2D& InWindowAnchor);

	/** 获取窗口Anchor。 */
	UFUNCTION(BlueprintPure, Category="Layout")
	GENERICWINDOWFRAMEWORK_API FVector2D GetWindowAnchor() const;

private:
	/** 获取Clamped窗口Anchor。 */
	FVector2D GetClampedWindowAnchor() const;

public:
	/** 记录窗口锚点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Layout", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	FVector2D WindowAnchor=FVector2D::ZeroVector;
};
