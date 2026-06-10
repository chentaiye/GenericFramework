// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ISequencerSection.h"
#include "Misc/EngineVersionComparison.h"

class UMovieSceneUMGSection;

/** Sequencer 中 UMG Section 的编辑器外观适配器，目前复用基础 Section 绘制与标题行为。 */
class FMovieSceneUMGEdSection : public FSequencerSection
{
public:
	/** 绑定运行时 UMG Section 对象，让 Sequencer 面板可以为该段创建编辑器显示接口。 */
	FMovieSceneUMGEdSection(UMovieSceneSection& InSectionObject);
	virtual FText GetSectionTitle() const override;
	virtual FText GetSectionToolTip() const override;
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual float GetSectionHeight(const UE::Sequencer::FViewDensityInfo& ViewDensity) const override;
#else
	virtual float GetSectionHeight() const override;
#endif
	virtual int32 OnPaintSection(FSequencerSectionPainter& InPainter) const override;
};
