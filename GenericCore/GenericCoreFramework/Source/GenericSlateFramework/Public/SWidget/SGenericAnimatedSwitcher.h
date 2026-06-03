// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CurveSequence.h"
#include "Misc/EngineVersionComparison.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "SGenericAnimatedSwitcher.generated.h"

/** 定义切换动画类型枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EGenericSwitcherTransition : uint8
{
	/** 表示仅淡入淡出切换。 */
	FadeOnly,

	/** 表示水平位移切换。 */
	Horizontal,

	/** 表示垂直位移切换。 */
	Vertical,

	/** 表示缩放切换。 */
	Zoom
};

/** 定义切换曲线类型枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EGenericTransitionCurve : uint8
{
	/** 表示线性曲线。 */
	Linear,

	/** 表示二次缓入曲线。 */
	QuadIn,

	/** 表示二次缓出曲线。 */
	QuadOut,

	/** 表示二次缓入缓出曲线。 */
	QuadInOut,

	/** 表示三次缓入曲线。 */
	CubicIn,

	/** 表示三次缓出曲线。 */
	CubicOut,

	/** 表示三次缓入缓出曲线。 */
	CubicInOut,
};

/** 定义切换回退策略枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EGenericSwitcherTransitionFallbackStrategy : uint8
{
	/** 表示不启用额外策略或没有有效类型。 */
	None,

	/** 表示上一个有效子控件。 */
	Previous,

	/** 表示下一个有效子控件。 */
	Next,

	/** 表示第一个子控件。 */
	First,

	/** 表示最后一个子控件。 */
	Last
};

/** 转换通用切换曲线To曲线EaseFunction，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
static inline ECurveEaseFunction GenericTransitionCurveToCurveEaseFunction(const EGenericTransitionCurve CurveType)
{
	switch (CurveType)
	{
	default:
	case EGenericTransitionCurve::Linear: return ECurveEaseFunction::Linear;
	case EGenericTransitionCurve::QuadIn: return ECurveEaseFunction::QuadIn;
	case EGenericTransitionCurve::QuadOut: return ECurveEaseFunction::QuadOut;
	case EGenericTransitionCurve::QuadInOut: return ECurveEaseFunction::QuadInOut;
	case EGenericTransitionCurve::CubicIn: return ECurveEaseFunction::CubicIn;
	case EGenericTransitionCurve::CubicOut: return ECurveEaseFunction::CubicOut;
	case EGenericTransitionCurve::CubicInOut: return ECurveEaseFunction::CubicInOut;
	}
}

/** 实现带动画切换器 Slate 控件，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SGenericAnimatedSwitcher : public SWidgetSwitcher
{
	SLATE_DECLARE_WIDGET(SGenericAnimatedSwitcher, SWidgetSwitcher)

public:
	DECLARE_DELEGATE_OneParam(FOnActiveIndexChanged, int32)
	DECLARE_DELEGATE_OneParam(FOnIsTransitioningChanged, bool)

	SLATE_BEGIN_ARGS(SGenericAnimatedSwitcher)

		: _InitialIndex(0)
		, _TransitionType(EGenericSwitcherTransition::FadeOnly)
		, _TransitionCurveType(EGenericTransitionCurve::CubicInOut)
		, _TransitionDuration(0.4f)
		, _TransitionFallbackStrategy(EGenericSwitcherTransitionFallbackStrategy::Previous)
	{
		_Visibility = EVisibility::SelfHitTestInvisible;
	}
		SLATE_ARGUMENT(int32, InitialIndex)
		SLATE_ARGUMENT(EGenericSwitcherTransition, TransitionType)
		SLATE_ARGUMENT(EGenericTransitionCurve, TransitionCurveType)
		SLATE_ARGUMENT(float, TransitionDuration)
		SLATE_ARGUMENT(EGenericSwitcherTransitionFallbackStrategy, TransitionFallbackStrategy)
		SLATE_EVENT(FOnActiveIndexChanged, OnActiveIndexChanged)
		SLATE_EVENT(FOnIsTransitioningChanged, OnIsTransitioningChanged)
	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	/** 启动到指定子控件的切换流程，必要时跳过动画立即完成。 */
	void TransitionToIndex(int32 NewWidgetIndex, bool bInstantTransition=false);

	/** 读取指定索引的子控件槽位，供调用方调整切换器子项布局。 */
	FSlot* GetChildSlot(int32 SlotIndex);

	/** 写入切换，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransition(float Duration, EGenericTransitionCurve Curve);

	/** 写入切换，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransition(float Duration, EGenericTransitionCurve Curve, EGenericSwitcherTransition NewTransitionType);

	/** 写入切换动画类型，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransitionType(EGenericSwitcherTransition NewTransitionType);

	/** 判断切换动画是否正在播放，供外部逻辑避免重复启动过渡。 */
	bool IsTransitionPlaying() const;

	/** 读取待激活子控件，供调用方复用当前对象缓存或引擎状态。 */
	TWeakPtr<SWidget> GetPendingActiveWidget() const { return PendingActiveWidget; }

	/** 读取待激活子控件索引，供调用方复用当前对象缓存或引擎状态。 */
	int32 GetPendingActiveWidgetIndex() const { return PendingActiveWidgetIndex; }

	/** 写入切换回退策略，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetTransitionFallbackStrategy(const EGenericSwitcherTransitionFallbackStrategy InStrategy) { TransitionFallbackStrategy=InStrategy; }

	/** 读取切换回退策略，供调用方复用当前对象缓存或引擎状态。 */
	EGenericSwitcherTransitionFallbackStrategy GetTransitionFallbackStrategy() const { return TransitionFallbackStrategy; }
	bool IsTransitionFallbackEnabled() const { return TransitionFallbackStrategy != EGenericSwitcherTransitionFallbackStrategy::None; }

protected:
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	virtual void OnSlotAdded(int32 AddedIndex) override;
	virtual void OnSlotRemoved(int32 RemovedIndex, TSharedRef<SWidget> RemovedWidget, bool bWasActiveSlot) override;
#endif

private:
	/** 推进切换动画计时，根据曲线进度更新当前绘制状态。 */
	EActiveTimerReturnType UpdateTransition(double InCurrentTime, float InDeltaTime);

	/** 读取切换进度，供调用方复用当前对象缓存或引擎状态。 */
	float GetTransitionProgress() const;

	/** 计算被移除索引对应的回退目标，保证切换器仍指向有效子控件。 */
	int32 GetTransitionFallbackForIndex(int32 RemovedWidgetIndex) const;

	/** 尝试在子控件移除后选择回退目标，避免切换状态悬空。 */
	bool TryTransitionFallbackOfPendingWidget();

	/** 尝试在子控件移除后选择回退目标，避免切换状态悬空。 */
	bool TryTransitionFallbackOfActiveWidget(int32 RemovedWidgetIndex);

private:
	/** 保存切换动画序列状态，供当前对象后续生命周期和同步逻辑读取。 */
	FCurveSequence TransitionSequence;

	/** 缓存待激活子控件的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TWeakPtr<SWidget> PendingActiveWidget;

	/** 保存待激活子控件索引数值，供布局、渲染或运行时逻辑读取。 */
	int32 PendingActiveWidgetIndex=INDEX_NONE;

	/** 保存切换回退策略状态，供当前对象后续生命周期和同步逻辑读取。 */
	EGenericSwitcherTransitionFallbackStrategy TransitionFallbackStrategy=EGenericSwitcherTransitionFallbackStrategy::None;

	/** 记录退出动画状态，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bTransitioningOut=false;

	/** 记录切换计时器注册状态，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bIsTransitionTimerRegistered=false;

	/** 保存切换动画类型状态，供当前对象后续生命周期和同步逻辑读取。 */
	EGenericSwitcherTransition TransitionType=EGenericSwitcherTransition::FadeOnly;

	FOnActiveIndexChanged OnActiveIndexChanged;

	FOnIsTransitioningChanged OnIsTransitioningChanged;
};
