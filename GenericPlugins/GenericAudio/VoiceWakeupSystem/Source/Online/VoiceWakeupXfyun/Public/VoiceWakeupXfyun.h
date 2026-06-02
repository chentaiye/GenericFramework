// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明语音唤醒Xfyun模块。 */
class FVoiceWakeupXfyunModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** 加载运行时Libraries。 */
	void LoadRuntimeLibraries();

	/** 卸载运行时Libraries。 */
	void UnloadRuntimeLibraries();

private:
	/** 保存RuntimeLibraries列表。 */
	TArray<void*> RuntimeLibraries;
};
