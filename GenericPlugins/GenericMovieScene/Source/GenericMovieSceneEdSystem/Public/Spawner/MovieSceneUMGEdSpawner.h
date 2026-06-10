// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Spawner/MovieSceneUMGSpawner.h"

/** 编辑器侧 UMG 生成器，扩展运行时生成器以支持从 Widget Blueprint 创建 Sequencer Spawnable。 */
class FMovieSceneUMGEdSpawner : public FMovieSceneUMGSpawner
{
public:
	/** 创建编辑器 UMG 生成器实例，供 LevelSequence 模块在编辑器环境注册。 */
	static TSharedRef<IMovieSceneObjectSpawner> CreateObjectSpawner();

	virtual bool IsEditor() const override { return true; }
	virtual TValueOrError<FNewSpawnable, FText> CreateNewSpawnableType(UObject& SourceObject, UMovieScene& OwnerMovieScene, UActorFactory* ActorFactory = nullptr) override;
	virtual bool CanSetupDefaultsForSpawnable(UObject* SpawnedObject) const override;
	virtual void SetupDefaultsForSpawnable(UObject* SpawnedObject, const FGuid& Guid, const TOptional<FTransformData>& TransformData, TSharedRef<ISequencer> Sequencer, USequencerSettings* Settings) override;
};
