// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "ISettingsViewer.h"
#include "OpenDeveloperSettings.generated.h"

class ISettingsEditorModel;
class ISettingsModule;
class FSpawnTabArgs;
class SDockTab;
struct FToolMenuSection;

/** 统一设置页签名称，供 Settings Viewer 注册和工具栏入口定位同一个 DockTab。 */
static const FName DeveloperSettingsTabName("DeveloperSettings");

/** 在编辑器中注册 GenericFramework 设置入口，并把工具栏按钮跳转到统一的设置页签。 */
UCLASS(MinimalAPI)
class UOpenDeveloperSettings : public UEditorSubsystem, public ISettingsViewer
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/* ISettingsViewer */
public:
	virtual void ShowSettings(const FName& CategoryName, const FName& SectionName) override;

protected:
	/** 缓存当前设置编辑器模型，ShowSettings 被调用时用它切换到目标分类和分区。 */
	TWeakPtr<ISettingsEditorModel> SettingsEditorModelPtr;

	/** 生成设置页签内容，将 GenericFramework 设置容器嵌入编辑器 DockTab。 */
	TSharedRef<SDockTab> HandleSpawnSettingsTab(const FSpawnTabArgs& SpawnTabArgs);

private:
	/** 把 GenericFramework 设置入口挂到编辑器工具栏扩展点。 */
	virtual void RegisterToolBarOpenDeveloperSettings(FToolMenuSection& ToolMenuSection);

	/** 打开 GenericFramework 设置页签，并定位到全局设置分区。 */
	virtual void OpenDeveloperSettings();
};
