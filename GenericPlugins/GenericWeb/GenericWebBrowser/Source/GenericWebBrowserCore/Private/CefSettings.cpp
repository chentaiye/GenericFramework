//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CefSettings.h"
#pragma endregion

#pragma region <Engine Headers>
#if WITH_EDITOR
// SettingsEditor/Public/
#include <ISettingsEditorModule.h>
#endif
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

#if WITH_EDITOR
void
UCefSettings::PostEditChangeProperty(struct FPropertyChangedEvent& InPropertyChangedEvent)
{
  Super::PostEditChangeProperty(InPropertyChangedEvent);

  /** CEF 全局配置只在进程初始化时读取，编辑器中修改后需要提示用户重启。 */
  ISettingsEditorModule& SettingsEditorModule =
    FModuleManager::GetModuleChecked<ISettingsEditorModule>("SettingsEditor");
  SettingsEditorModule.OnApplicationRestartRequired();
}
#endif
