//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Modules/ModuleManager.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Generated Header"
#pragma endregion

/** 负责在模块启动时定位并加载 CEF View Core 运行时资源。 */
class FCefViewModule : public IModuleInterface
{
public:
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;

  /** 返回第三方 CEF View Core 二进制和资源所在目录。 */
  FString GetCefViewCoreDir();

private:
  /** 缓存模块启动时解析出的 CEF View Core 目录。 */
  FString CefViewCoreDir;
};
