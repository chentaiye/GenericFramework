// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "SWidget/SGenericAnimatedSwitcher.h"
#include "GenericAnimatedSwitcher.generated.h"

class SOverlay;
class SSpacer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveIndexChangedFinish, UWidget*, ActiveWidget, int32, ActiveIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGenericAnimatedSwitcherActiveIndexChangedDelegate, UWidget*, ActiveWidget, int32, ActiveIndex);

/** 作为带动画切换器 UMG 控件，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI)
class UGenericAnimatedSwitcher : public UWidgetSwitcher
{
	GENERATED_BODY()

public:
	/** 初始化带动画切换器默认过渡参数，并准备底层 Slate 同步状态。 */
	GENERICSLATEFRAMEWORK_API UGenericAnimatedSwitcher(const FObjectInitializer& ObjectInitializer);

	GENERICSLATEFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	GENERICSLATEFRAMEWORK_API virtual void SetActiveWidgetIndex(int32 Index) override;
	GENERICSLATEFRAMEWORK_API virtual void SetActiveWidget(UWidget* Widget) override;

	/** 切换到下一个可用子控件，并按配置决定是否循环。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API void ActivateNextWidget(bool bCanWrap);

	/** 切换到上一个可用子控件，并按配置决定是否循环。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API void ActivatePreviousWidget(bool bCanWrap);

	/** 判断Widgets，供调用方选择后续流程或过滤无效输入。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API bool HasWidgets() const;

	/** 设置是否禁用过渡动画，影响后续切换是否即时完成。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API void SetDisableTransitionAnimation(bool bDisableAnimation);

	/** 判断 UMG 封装是否正在等待底层切换完成。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API bool IsCurrentlySwitching() const;

	/** 判断切换动画是否正在播放，供外部逻辑避免重复启动过渡。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API bool IsTransitionPlaying() const;

	/** 读取待激活子控件，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API UWidget* GetPendingActiveWidget() const;

	/** 读取待激活子控件索引，供调用方复用当前对象缓存或引擎状态。 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	GENERICSLATEFRAMEWORK_API int32 GetPendingActiveWidgetIndex() const;

	DECLARE_EVENT_TwoParams(UGenericAnimatedSwitcher, FOnActiveIndexChanged, UWidget*, int32)

	FOnActiveIndexChanged OnActiveWidgetIndexChanged;

	DECLARE_EVENT_OneParam(UGenericAnimatedSwitcher, FOnTransitioningChanged, bool)

	FOnTransitioningChanged OnTransitioningChanged;

	UPROPERTY(BlueprintAssignable, Category="Common Widget Switcher")
	FOnGenericAnimatedSwitcherActiveIndexChangedDelegate OnActiveWidgetIndexChangedBP;

	UPROPERTY(BlueprintAssignable, Category="Common Widget Switcher")
	FOnActiveIndexChangedFinish OnActiveIndexChangedFinish;

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
#endif

	GENERICSLATEFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;

	/** 响应底层 Slate 激活索引变化，并把结果同步到 UMG 事件。 */
	GENERICSLATEFRAMEWORK_API virtual void HandleSlateActiveIndexChanged(int32 ActiveIndex);

	/** 响应底层 Slate 切换状态变化，并把结果同步到 UMG 事件。 */
	GENERICSLATEFRAMEWORK_API virtual void HandleSlateIsTransitioningChanged(bool bIsTransitioning);

	/** 响应Outgoing控件回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	virtual void HandleOutgoingWidget() {}

protected:
	/** 保存切换动画类型状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Transition")
	EGenericSwitcherTransition TransitionType;

	/** 保存切换曲线类型状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Transition")
	EGenericTransitionCurve TransitionCurveType;

	/** 保存切换时长数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Transition")
	float TransitionDuration;

	/** 保存切换回退策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Transition")
	EGenericSwitcherTransitionFallbackStrategy TransitionFallbackStrategy=EGenericSwitcherTransitionFallbackStrategy::None;

	/** 缓存输入覆盖层的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SOverlay> MyOverlay;

	/** 缓存输入拦截层的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SSpacer> MyInputGuard;

	/** 缓存底层动画切换器的 Slate 引用，用于属性同步和资源释放。 */
	TSharedPtr<SGenericAnimatedSwitcher> MyAnimatedSwitcher;

	/** 记录即时切换标记，用于控制后续同步或切换流程。 */
	bool bInstantTransition=false;

	/** 记录首次同步标记，用于控制后续同步或切换流程。 */
	bool bSetOnce=false;

	/** 记录 UMG 层是否正在等待底层切换完成，避免重复广播状态。 */
	bool bCurrentlySwitching=false;

private:
	/** 写入内部激活索引，集中处理 Slate 同步和事件广播。 */
	void SetActiveWidgetIndex_Internal(int32 Index);
};
