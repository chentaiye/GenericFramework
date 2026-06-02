#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 注册 GenericJson 运行时模块，为 JSON 对象、反射转换和蓝图函数提供模块入口。 */
class FGenericJsonModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
