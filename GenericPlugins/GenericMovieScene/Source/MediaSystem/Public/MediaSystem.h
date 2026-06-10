#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** MediaSystem 运行时模块入口，加载后提供 UMediaPlayer 句柄封装能力。 */
class FMediaSystemModule : public IModuleInterface
{
public:
	/** 模块启动入口，当前模块主要依靠 UObject 和 GameplayTag 静态注册提供运行时能力。 */
	virtual void StartupModule() override;

	/** 模块关闭入口，保留给后续释放模块级资源或注销扩展点。 */
	virtual void ShutdownModule() override;
};
