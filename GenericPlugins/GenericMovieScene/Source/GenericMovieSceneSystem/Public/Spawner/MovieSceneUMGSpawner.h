// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IMovieSceneObjectSpawner.h"
#include "Misc/EngineVersionComparison.h"

class UUserWidgetBlueprint;
class IMovieScenePlayer;

/** LevelSequence 的 UMG 对象生成器，把 Spawnable 模板实例化为运行时 UserWidget 并挂到对应世界视口。 */
class GENERICMOVIESCENESYSTEM_API FMovieSceneUMGSpawner : public IMovieSceneObjectSpawner
{
public:
	/** 创建运行时 UMG 生成器实例，供 LevelSequence 模块注册为 ObjectSpawner。 */
	static TSharedRef<IMovieSceneObjectSpawner> CreateObjectSpawner();

	virtual UClass* GetSupportedTemplateType() const override;
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual UObject* SpawnObject(FMovieSceneSpawnable& Spawnable, FMovieSceneSequenceIDRef TemplateID, TSharedRef<const UE::MovieScene::FSharedPlaybackState> SharedPlaybackState) override;
#else
	virtual UObject* SpawnObject(FMovieSceneSpawnable& Spawnable, FMovieSceneSequenceIDRef TemplateID, IMovieScenePlayer& Player) override;
#endif
	virtual void DestroySpawnedObject(UObject& Object) override;

private:
	/** 按 Spawnable 指定的关卡名解析流关卡，PIE 下会转换为对应实例包名以避免生成到错误世界。 */
	ULevelStreaming* GetLevelStreaming(const FName& DesiredLevelName, const UWorld* World);
};
