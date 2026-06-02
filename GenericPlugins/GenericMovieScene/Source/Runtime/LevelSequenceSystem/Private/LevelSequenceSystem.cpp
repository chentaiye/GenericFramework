#include "LevelSequenceSystem.h"

#define LOCTEXT_NAMESPACE "FLevelSequenceSystemModule"

void FLevelSequenceSystemModule::StartupModule()
{
	// 当前模块没有运行期单例或编辑器扩展需要显式注册，启动入口保留给后续模块级资源初始化。
}

void FLevelSequenceSystemModule::ShutdownModule()
{
	// 当前模块没有模块级资源需要释放，关闭入口保留给后续反注册流程。
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLevelSequenceSystemModule, LevelSequenceSystem)
