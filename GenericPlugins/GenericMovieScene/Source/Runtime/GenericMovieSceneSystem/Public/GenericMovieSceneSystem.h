#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 运行时电影场景模块入口，启动时向 LevelSequence 注册 UMG 生成器。 */
class FGenericMovieSceneSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	FDelegateHandle OnCreateMovieSceneUMGSpawnerDelegateHandle;
};
