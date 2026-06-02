#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 保留 GenericCameraSystem 的运行时模块入口，供 Unreal 模块系统加载相机相关类型。 */
class FGenericCameraSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
