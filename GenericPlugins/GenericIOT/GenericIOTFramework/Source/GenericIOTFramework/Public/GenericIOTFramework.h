// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

GENERICIOTFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogIOT, Log, All);

/** 声明 GenericIOT 运行时模块，负责提供日志分类并承载模块加载生命周期。 */
class FGenericIOTFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
