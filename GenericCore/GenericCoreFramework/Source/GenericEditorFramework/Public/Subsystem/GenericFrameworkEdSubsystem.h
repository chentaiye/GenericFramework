// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "GenericFrameworkEdSubsystem.generated.h"

class IManagerEdInterface;
class ILevelEditor;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnCommandListInitialize, TSharedPtr<FUICommandList>&)
DECLARE_MULTICAST_DELEGATE_OneParam(FToolMenuDelegate, UToolMenu*&)
DECLARE_MULTICAST_DELEGATE_OneParam(FFToolMenuSectionDelegate, FToolMenuSection&)

/** 作为通用框架编辑器子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericFrameworkEdSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	static UGenericFrameworkEdSubsystem* Get();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	/** 关卡编辑器创建后接入菜单和工具栏扩展，确保命令列表可用。 */
	void OnLevelEditorCreated(TSharedPtr<ILevelEditor> LevelEditor);

	/** 注册菜单栏，把模块扩展点接入或移出编辑器菜单、工具栏和标签页。 */
	void RegisterMenuBar();

	/** 注册菜单，把模块扩展点接入或移出编辑器菜单、工具栏和标签页。 */
	void RegisterMenu(UToolMenu* InToolMenu);

	/** 注册编辑器工具栏扩展点，并绑定通用命令列表。 */
	void RegisterToolBar();

	/** 注册工具栏选项区域扩展点，供工具入口追加分组按钮。 */
	void RegisterToolBarOption();

	/** 注册工具栏选项下拉菜单，并广播给外部模块填充内容。 */
	void RegisterToolBarOptionMenu(UToolMenu* InToolMenu);

public:
	static GENERICEDITORFRAMEWORK_API FOnCommandListInitialize OnCommandListInitialize;

	static GENERICEDITORFRAMEWORK_API FToolMenuDelegate OnMenuBarExtend;

	static GENERICEDITORFRAMEWORK_API FToolMenuDelegate OnMenuExtend;

	static GENERICEDITORFRAMEWORK_API FToolMenuDelegate OnToolBarExtend;

	static GENERICEDITORFRAMEWORK_API FFToolMenuSectionDelegate OnToolBarSectionExtend;

	static GENERICEDITORFRAMEWORK_API FToolMenuDelegate OnToolBarOptionExtend;

protected:
	/** 保存菜单栏扩展分组名，供编辑器注册、查找和重复打开时使用。 */
	static FName MenuBarSectionName;

	/** 保存工具栏扩展分组名，供编辑器注册、查找和重复打开时使用。 */
	static FName ToolBarSectionName;

	/** 缓存命令列表的 Slate 引用，便于后续属性同步、布局计算或事件绑定。 */
	TSharedPtr<FUICommandList> CommandList=nullptr;
};
