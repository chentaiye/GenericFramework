#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 注册 GenericProtocol 运行时模块，为 HTTP、WebSocket、UDP 和 Home Assistant 通信封装提供入口。 */
class FGenericProtocolModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
