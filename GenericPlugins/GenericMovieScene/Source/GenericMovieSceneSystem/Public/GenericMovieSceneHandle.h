// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneType.h"
#include "Interface/StateInterface.h"
#include "GenericMovieSceneInterface.h"
#include "Obect/GenericObject.h"
#include "GenericMovieSceneHandle.generated.h"

/** 所有电影场景句柄的公共基类，接入对象生命周期并把接口钩子转换为蓝图可订阅事件。 */
UCLASS(Abstract, MinimalAPI)
class UGenericMovieSceneHandle : public UGenericObject, public IStateInterface, public IGenericMovieSceneInterface
{
	GENERATED_BODY()

	/* IStateInterface */
protected:
	GENERICMOVIESCENESYSTEM_API virtual void NativeOnCreate() override;
	GENERICMOVIESCENESYSTEM_API virtual void NativeOnDestroy() override;

	/* IMovieSceneInterface */
protected:
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieScenePlay() override;
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieScenePlayReverse() override;
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieScenePause() override;
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieSceneStop() override;
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieSceneSeek() override;
	GENERICMOVIESCENESYSTEM_API virtual void OnMovieScenePlayFinish() override;
};
