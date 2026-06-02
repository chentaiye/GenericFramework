#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 定义 GenericSlateFramework 模块入口，负责注册共享 Slate 样式和控件类型。 */
class FGenericSlateFrameworkModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
