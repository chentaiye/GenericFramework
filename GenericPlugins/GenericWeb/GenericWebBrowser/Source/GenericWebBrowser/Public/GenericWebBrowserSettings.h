#pragma once

#include "CoreMinimal.h"
#include "GenericWebBrowserSettings.generated.h"

/** 暴露浏览器后端的视图级输入与显示配置，由 UMG 控件同步到 Slate CEF 视图。 */
USTRUCT(BlueprintType)
struct GENERICWEBBROWSER_API FGenericWebBrowserViewSettings
{
	GENERATED_BODY()

	/** 允许透明区域把命中测试透传给下层 Slate/UMG 控件。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(InlineEditConditionToggle))
	bool bEnableAlphaHitTestPassthrough=false;

	/** 低于该透明度阈值的像素会被视为可透传区域。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(ClampMin="0", ClampMax="255", UIMin="0", UIMax="255", EditCondition="bEnableAlphaHitTestPassthrough"))
	int32 AlphaHitTestThreshold=0;

	/** CEF 视图清屏背景色，透明色用于配合合成和命中透传。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FColor BackgroundColor=FColor::Transparent;
};
