// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "OpenWorldSettings.generated.h"

struct FToolMenuSection;

/** 注册世界设置工具栏入口，并把点击行为转发到世界设置编辑器 Tab。 */
UCLASS(MinimalAPI)
class UOpenWorldSettings : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	/** 把世界设置入口放入 GenericFramework 编辑器工具栏。 */
	void RegisterToolBarOpenWorldSettings(FToolMenuSection& ToolMenuSection);

	/** 刷新世界设置类型列表后打开或激活世界设置 Tab。 */
	void OpenWorldSettings();
};
