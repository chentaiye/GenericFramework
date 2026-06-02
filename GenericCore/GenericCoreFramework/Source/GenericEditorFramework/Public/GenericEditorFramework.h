#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 定义 GenericEditorFramework 编辑器模块入口，负责注册编辑器工具和扩展。 */
class FGenericEditorFrameworkModule : public IModuleInterface
{
	/* IModuleInterface */
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
