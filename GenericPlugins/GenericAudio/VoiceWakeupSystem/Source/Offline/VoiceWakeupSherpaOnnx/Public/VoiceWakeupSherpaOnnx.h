// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** 声明语音唤醒Sherpa Onnx模块。 */
class FVoiceWakeupSherpaOnnxModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
