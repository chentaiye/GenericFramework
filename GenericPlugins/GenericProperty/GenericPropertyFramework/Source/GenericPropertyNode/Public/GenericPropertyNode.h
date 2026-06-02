#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 通用属性编辑器节点模块，注册旧版属性提交 K2 节点相关类型。 */
class FGenericPropertyNodeModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
