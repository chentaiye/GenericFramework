// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "FastSwitchLanguage.generated.h"

/** 定义快捷切换语言类型，作为 编辑器扩展 模块内复用的稳定入口。 */
UCLASS(MinimalAPI)
class UFastSwitchLanguage : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	/** 在工具栏扩展点中追加工具入口，连接编辑器菜单注册和实际打开动作。 */
	void OnToolBarSectionExtend(FToolMenuSection& InToolMenuSection);

	/** 切换编辑器语言配置，并刷新已打开蓝图以应用本地化文本。 */
	void ToggleSwitchLanguage();

	/** 刷新Blueprints，同步编辑器缓存、蓝图状态或控件显示。 */
	void RefreshBlueprints();
};
