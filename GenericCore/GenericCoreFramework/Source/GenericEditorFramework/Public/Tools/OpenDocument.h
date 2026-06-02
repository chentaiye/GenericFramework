// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "OpenDocument.generated.h"

class ISettingsEditorModel;

/** 保存文档工具标签页名称，供 TabManager 注册和重复打开时定位同一页面。 */
static const FName DocumentTabName("DeveloperDocument");

/** 定义打开文档类型，作为 编辑器扩展 模块内复用的稳定入口。 */
UCLASS(MinimalAPI)
class UOpenDocument : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	/** 在工具栏扩展点中追加工具入口，连接编辑器菜单注册和实际打开动作。 */
	void OnToolBarSectionExtend(FToolMenuSection& InToolMenuSection);

	/** 打开文档标签页，优先复用已有页面，必要时通过 TabManager 生成新页面。 */
	void OpenDocument();

	/** 生成文档标签页内容，把文档视图挂接到编辑器 DockTab。 */
	TSharedRef<SDockTab> HandleSpawnDocumentTab(const FSpawnTabArgs& SpawnTabArgs);
};
