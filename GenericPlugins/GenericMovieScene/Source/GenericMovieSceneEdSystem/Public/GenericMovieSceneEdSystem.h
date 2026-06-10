#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 编辑器电影场景模块入口，负责向 Sequencer/LevelSequence 注册 UMG 轨道编辑器和编辑器生成器。 */
class FGenericMovieSceneEdSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	FDelegateHandle EditorUMGSpawnerDelegateHandle;

	FDelegateHandle UMGTrackCreateEditorHandle;
};
