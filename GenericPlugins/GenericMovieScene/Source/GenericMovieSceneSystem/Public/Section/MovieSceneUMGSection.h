// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sections/MovieSceneHookSection.h"
#include "MovieSceneUMGSection.generated.h"

class UUserWidgetBlueprint;

/** UMG 轨道使用的 Section 类型，作为 Sequencer 中 Widget 生成段的运行时占位。 */
UCLASS(MinimalAPI)
class UMovieSceneUMGSection : public UMovieSceneSection
{
	GENERATED_BODY()

public:
	/** 构造 UMG Section，保持父类默认区间和事务行为供编辑器轨道直接创建。 */
	GENERICMOVIESCENESYSTEM_API UMovieSceneUMGSection(const FObjectInitializer& ObjInit);
};
