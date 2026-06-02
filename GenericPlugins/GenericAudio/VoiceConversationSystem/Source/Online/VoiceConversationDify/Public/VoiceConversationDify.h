// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** 声明语音Conversation Dify模块。 */
class FVoiceConversationDifyModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
