// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "MovieSceneUMGTrack.generated.h"

class UUserWidgetBlueprint;

/** Sequencer 中承载 UMG 预览 Section 的主轨道，负责创建并维护可生成 Widget 的 Section 列表。 */
UCLASS(MinimalAPI)
class UMovieSceneUMGTrack : public UMovieSceneNameableTrack
{
	GENERATED_BODY()

public:
	GENERICMOVIESCENESYSTEM_API virtual bool SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const override;
	GENERICMOVIESCENESYSTEM_API virtual UMovieSceneSection* CreateNewSection() override;
	GENERICMOVIESCENESYSTEM_API virtual bool HasSection(const UMovieSceneSection& Section) const override;
	GENERICMOVIESCENESYSTEM_API virtual void AddSection(UMovieSceneSection& Section) override;
	GENERICMOVIESCENESYSTEM_API virtual void RemoveSection(UMovieSceneSection& Section) override;
	GENERICMOVIESCENESYSTEM_API virtual void RemoveSectionAt(int32 SectionIndex) override;
	GENERICMOVIESCENESYSTEM_API virtual bool IsEmpty() const override;
	GENERICMOVIESCENESYSTEM_API virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;
	GENERICMOVIESCENESYSTEM_API virtual bool SupportsMultipleRows() const override;

public:
	/** 当前轨道持有的 UMG Section 集合，AddSection 使用 AddUnique 避免同一 Section 重复进入 Sequencer 轨道。 */
	UPROPERTY()
	TArray<UMovieSceneSection*> Sections;
};
