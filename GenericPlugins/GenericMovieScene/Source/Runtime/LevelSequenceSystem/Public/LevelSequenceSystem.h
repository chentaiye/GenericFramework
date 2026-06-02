#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** LevelSequenceSystem 运行时模块入口，加载后提供关卡序列句柄封装能力。 */
class FLevelSequenceSystemModule : public IModuleInterface
{
public:
	/** 模块启动入口，当前模块依赖 UObject 静态注册完成后即可被其他模块调用。 */
	virtual void StartupModule() override;

	/** 模块关闭入口，保留给后续释放模块级资源或注销扩展点。 */
	virtual void ShutdownModule() override;
};
