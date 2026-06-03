// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextWidgetTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "Misc/EngineVersionComparison.h"
#include "Styling/SlateColor.h"
#include "Containers/Ticker.h"
#include "SubtitleTextBlock.generated.h"

class SSubtitleTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubtitleLineAdded, const FText&, AddedLine);

/** 作为字幕 UMG 控件，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI, meta=(DisplayName="Subtitle Text"))
class USubtitleTextBlock : public UTextLayoutWidget
{
	GENERATED_BODY()

public:
	/** 初始化字幕文本控件默认样式、缓存上限和过期清理参数。 */
	GENERICSLATEFRAMEWORK_API USubtitleTextBlock(const FObjectInitializer& ObjectInitializer);
	GENERICSLATEFRAMEWORK_API virtual void BeginDestroy() override;
	GENERICSLATEFRAMEWORK_API virtual void SynchronizeProperties() override;
	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	/** 读取文本，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API FText GetText() const;

	/** 写入文本，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void SetText(FText InText);

	/** 读取字幕行集合，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API TArray<FText> GetLines();

	/** 写入字幕行集合，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void SetLines(const TArray<FText>& InLines);

	/** 批量追加字幕行，并把缓存同步到底层 Slate 显示。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void AppendLines(const TArray<FText>& InLines);

	/** 清空字幕行缓存，并立即同步到底层 Slate 显示。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void ClearLines();

	/** 添加文本，并同步内部缓存、显示状态或事件绑定。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void AddText(FText InText);

	/** 添加文本WithLifetime，并同步内部缓存、显示状态或事件绑定。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text")
	GENERICSLATEFRAMEWORK_API void AddTextWithLifetime(FText InText, float InLifetimeSeconds);

	/** 读取字体，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API const FSlateFontInfo& GetFont() const;

	/** 写入字体，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetFont(FSlateFontInfo InFont);

	/** 读取颜色和透明度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API FSlateColor GetColorAndOpacity() const;

	/** 写入颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetColorAndOpacity(FSlateColor InColorAndOpacity);

	/** 读取阴影偏移，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API FVector2D GetShadowOffset() const;

	/** 写入阴影偏移，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetShadowOffset(FVector2D InShadowOffset);

	/** 读取阴影颜色和透明度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API FLinearColor GetShadowColorAndOpacity() const;

	/** 写入阴影颜色和透明度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity);

	/** 读取最小期望宽度，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API float GetMinDesiredWidth() const;

	/** 写入最小期望宽度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetMinDesiredWidth(float InMinDesiredWidth);

	/** 读取文本变换策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API ETextTransformPolicy GetTextTransformPolicy() const;

	/** 写入文本变换策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetTextTransformPolicy(ETextTransformPolicy InTransformPolicy);

	/** 读取文本溢出策略，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API ETextOverflowPolicy GetTextOverflowPolicy() const;

	/** 写入文本溢出策略，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Appearance")
	GENERICSLATEFRAMEWORK_API void SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy);

	/** 写入尾部可见行数，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetTailVisibleLineCount(int32 InTailVisibleLineCount);

	/** 写入最大显示高度，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetMaxDisplayHeight(float InMaxDisplayHeight);

	/** 写入渐隐行数，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetGradientLineCount(int32 InGradientLineCount);

	/** 写入行透明度步长，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetLineOpacityStep(float InLineOpacityStep);

	/** 写入最大缓存行数，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetMaxStoredLines(int32 InMaxStoredLines);

	/** 写入默认行存活时间秒，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetDefaultLineLifetimeSeconds(float InDefaultLineLifetimeSeconds);

	/** 写入暂停过期清理开关，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Subtitle Text|Subtitle")
	GENERICSLATEFRAMEWORK_API void SetPauseExpiration(bool bInPauseExpiration);

public:
	UPROPERTY(BlueprintAssignable, Category="Subtitle Text")
	FOnSubtitleLineAdded OnLineAdded;

	/** 保存文本内容，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Content", meta=(MultiLine="true"))
	FText Text;

	/** 保存最小期望宽度数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float MinDesiredWidth=0.0f;

	/** 保存颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateColor ColorAndOpacity;

	/** 保存字体显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateFontInfo Font;

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D ShadowOffset=FVector2D(1.0f, 1.0f);

	/** 保存阴影颜色和透明度显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FLinearColor ShadowColorAndOpacity=FLinearColor::Transparent;

	/** 保存文本变换策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	ETextTransformPolicy TextTransformPolicy=ETextTransformPolicy::None;

	/** 保存文本溢出策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clipping")
	ETextOverflowPolicy TextOverflowPolicy=ETextOverflowPolicy::Clip;

	/** 保存尾部可见行数数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	int32 TailVisibleLineCount=3;

	/** 保存最大显示高度数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	float MaxDisplayHeight=0.0f;

	/** 保存渐隐行数数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	int32 GradientLineCount=3;

	/** 保存行透明度步长数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	float LineOpacityStep=0.2f;

	/** 保存最大缓存行数数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	int32 MaxStoredLines=64;

	/** 保存默认字幕行存活时间，供当前对象后续同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	float DefaultLineLifetimeSeconds=0.0f;

	/** 记录暂停过期，用于在生命周期、同步或输入流程中选择后续路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Subtitle")
	bool bPauseExpiration=false;

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif

	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	GENERICSLATEFRAMEWORK_API virtual void OnShapedTextOptionsChanged(FShapedTextOptions InShapedTextOptions) override;
	GENERICSLATEFRAMEWORK_API virtual void OnJustificationChanged(ETextJustify::Type InJustification) override;
	GENERICSLATEFRAMEWORK_API virtual void OnWrappingPolicyChanged(ETextWrappingPolicy InWrappingPolicy) override;
	GENERICSLATEFRAMEWORK_API virtual void OnAutoWrapTextChanged(bool InAutoWrapText) override;
	GENERICSLATEFRAMEWORK_API virtual void OnWrapTextAtChanged(float InWrapTextAt) override;
	GENERICSLATEFRAMEWORK_API virtual void OnLineHeightPercentageChanged(float InLineHeightPercentage) override;
	GENERICSLATEFRAMEWORK_API virtual void OnApplyLineHeightToBottomLineChanged(bool InApplyLineHeightToBottomLine) override;
	GENERICSLATEFRAMEWORK_API virtual void OnMarginChanged(const FMargin& InMargin) override;
#endif

private:
	/** 汇总缓存字幕行数据，便于 Slate、UMG 或蓝图在同一结构中传递配置。 */
	struct FStoredSubtitleLine
	{
		/** 保存文本内容，供当前对象后续同步逻辑读取。 */
		FText Text;

		/** 保存edAtSeconds数值，供布局、渲染或运行时逻辑读取。 */
		double AddedAtSeconds = 0.0;

		/** 保存字幕行存活时间，供当前对象后续同步逻辑读取。 */
		float LifetimeSeconds = 0.0f;
	};

	/** 把输入文本拆分为字幕行缓存，并记录追加时间用于过期清理。 */
	void ParseTextIntoStoredLines(const FText& InText, float InLifetimeSeconds);

	/** 写入单条字幕缓存，并按需要广播新增事件。 */
	void AppendLineInternal(const FText& InText, float InLifetimeSeconds, bool bBroadcastEvent);

	/** 裁剪超出上限的字幕行缓存，控制运行时内存和显示长度。 */
	void EnforceMaxStoredLines();

	/** 根据字幕行缓存重建聚合文本，供属性面板和底层 Slate 同步使用。 */
	void RebuildTextProperty();

	/** 把字幕行缓存推送到底层 Slate 控件，保持 UMG 属性与显示文本一致。 */
	void PushLinesToSlate();

	/** 刷新过期计时器，同步编辑器缓存、蓝图状态或控件显示。 */
	void RefreshExpirationTicker();

	/** 停止字幕过期计时器，避免无待清理内容时继续 Tick。 */
	void StopExpirationTicker();

	/** 响应过期计时器回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	bool HandleExpirationTicker(float DeltaTime);

	/** 清理已过期字幕行，并在缓存变化后触发文本重建。 */
	bool PruneExpiredLines();

	/** 读取当前时间秒数，供字幕过期判断复用。 */
	double GetNowSeconds() const;

private:
	/** 缓存字幕行缓存集合，供批量同步、查找或编辑器刷新使用。 */
	TArray<FStoredSubtitleLine> StoredLines;

	/** 缓存底层字幕文本控件的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SSubtitleTextBlock> MySubtitleTextBlock;

	FTSTicker::FDelegateHandle ExpirationTickerHandle;
};
