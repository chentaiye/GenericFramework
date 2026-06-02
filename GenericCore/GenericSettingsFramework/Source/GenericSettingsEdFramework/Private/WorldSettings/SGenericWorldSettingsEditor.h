// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class IDetailsView;
class ITableRow;
class STableViewBase;
class UGenericWorldSettingsEdSubsystem;
class UGenericWorldSettings;
struct FPropertyChangedEvent;
template <typename ItemType> class STableRow;
template <typename ItemType> class STreeView;
class SWidgetSwitcher;

/** 编辑器列表的混合条目，既能表示分类标题，也能表示分类下的设置类型。 */
struct FGenericWorldSettingsEditorEntry
{
	/** 设置类型本身，左侧列表选中后会用它定位地图中的实例。 */
	TSubclassOf<UGenericWorldSettings> SettingsClass;

	/** 条目所属分类；分类标题本身也使用该值进行树形分组。 */
	FName CategoryName;

	/** 列表主文本，优先来自设置对象的显示名接口。 */
	FText DisplayName;

	/** 列表辅助文本，显示设置用途或当前类型名。 */
	FText Description;

	/** 标记当前世界的总集中是否已经存在该类型的实例。 */
	bool bHasInstance = false;

	/** 标记该设置是否适用于当前编辑世界；失效项仍可选中，用于在右侧展示失效原因。 */
	bool bIsEnabled = true;

	/** 设置失效时展示给用户的原因文本。 */
	FText DisabledReason;

	/** 区分分类标题与真实设置项，标题只作为分组，不打开 Details。 */
	bool bIsCategoryHeader = false;

	/** 分类标题下的设置项列表，树视图只允许类别和设置项两级。 */
	TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>> Children;
};

/** Generic World Settings 的 Slate 编辑器，先展示异步加载态，再进入创建或左右分栏编辑界面。 */
class SGenericWorldSettingsEditor : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGenericWorldSettingsEditor)
	{
	}
		SLATE_ARGUMENT(TWeakObjectPtr<UGenericWorldSettingsEdSubsystem>, SettingsSubsystem)
	SLATE_END_ARGS()

	~SGenericWorldSettingsEditor();

	void Construct(const FArguments& InArgs);

	/** 重新读取当前编辑器世界、设置类型缓存和实例状态，并刷新列表与 Details 面板。 */
	void Refresh();

private:
	/** 响应异步类型发现状态变化，Loading 完成后重建真实内容。 */
	void HandleWorldSettingsClassesChanged();

	/** Tab 打开后的类型发现完成时，如果当前世界总集缺少已发现的设置实例，则立即补齐一次。 */
	void SyncMissingSettingsOnOpen();

	/** 根据子系统加载状态切换根视图，确保加载期间只显示居中 Loading。 */
	void RefreshRootSwitcher();

	TSharedRef<SWidget> BuildToolbar();

	/** 生成左侧树视图的一行，类别行只展示分组，设置项行展示实例状态和说明。 */
	TSharedRef<ITableRow> HandleGenerateSettingsRow(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, const TSharedRef<STableViewBase>& OwnerTable);

	/** 为树视图返回分类节点下的设置项，设置项自身不会再拥有子项。 */
	void HandleGetSettingsChildren(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>>& OutChildren) const;

	/** 记录用户手动展开的分类，刷新列表时保持用户已经打开的分类状态。 */
	void HandleSettingsExpansionChanged(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, bool bExpanded);

	/** 双击分类行任意位置时切换展开状态，单击只保留普通选中行为。 */
	void HandleSettingsRowDoubleClicked(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry);

	/** 列表选择变化后切换右侧 Details 面板展示的实例。 */
	void HandleSettingsSelectionChanged(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, ESelectInfo::Type SelectInfo);

	/** Details 面板修改完成后标记当前地图 dirty，保证嵌入实例可以随地图保存。 */
	void HandleFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent);

	/** 响应编辑器地图切换，重新异步发现设置类型并避免继续引用旧世界实例。 */
	void HandleMapChanged(uint32 MapChangeFlags);

	/** 创建当前世界的总集并补齐已发现设置实例。 */
	FReply HandleCreateCollectionClicked();

	/** 保存当前世界所在地图包。 */
	FReply HandleSaveWorldClicked();

	void ExecuteSaveWorld();

	void ExecuteDeleteCollection();

	bool CanSaveWorld() const;

	bool CanDeleteCollection() const;

	/** 返回当前选中条目在地图中的设置实例；缺失或未创建总集时返回空。 */
	UGenericWorldSettings* GetSelectedSettingsInstance() const;

	/** 根据当前世界和总集状态生成顶部状态文本。 */
	FText GetStatusText() const;

	/** 生成右侧 Details 面板上方的提示文本。 */
	FText GetDetailsStatusText() const;

	/** 只有选中地图中真实存在的设置实例时才展示 Details 面板。 */
	EVisibility GetDetailsViewVisibility() const;

	/** 未选中真实设置实例时在右侧面板居中显示提示文本。 */
	EVisibility GetDetailsEmptyPromptVisibility() const;

	/** 当前世界尚无总集时允许点击创建按钮。 */
	bool IsCreateCollectionEnabled() const;

	/** 根据当前世界是否已有设置总集，切换居中创建入口或左右分栏编辑界面。 */
	int32 GetContentSwitcherIndex() const;

	/** 从条目缓存中返回左侧列表主文本。 */
	FText GetEntryDisplayName(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const;

	/** 优先使用设置对象提供的显示名，未设置时回退到类显示名或类名。 */
	static FText ResolveEntryDisplayName(const UGenericWorldSettings* DisplaySource, const UClass* SettingsClass);

	/** 从实例或 CDO 中读取编辑器分组，未设置时统一归入 Default。 */
	static FName ResolveEntryCategory(const UGenericWorldSettings* DisplaySource);

	/** 从条目缓存中返回左侧列表辅助文本。 */
	FText GetEntryDescription(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const;

	/** 根据实例存在状态返回左侧列表状态文本。 */
	FText GetEntryStateText(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const;

	/** 根据实例存在状态返回左侧列表状态颜色。 */
	FSlateColor GetEntryStateColor(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const;

	/** 设置项失效时让左侧主文本和说明文本整体置灰，但保留树行的可选中行为。 */
	FSlateColor GetEntryTextColor(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const;

	/** 把当前选中条目同步到 Details 面板。 */
	void RefreshDetailsView();

private:
	/** 编辑器子系统弱引用，所有创建、同步、保存和异步发现操作都通过它执行。 */
	TWeakObjectPtr<UGenericWorldSettingsEdSubsystem> SettingsSubsystem;

	/** 监听世界设置类型发现状态变化的句柄。 */
	FDelegateHandle ClassesChangedHandle;

	/** 左侧树视图根节点，每个元素都是一个分类，设置项保存在分类节点的 Children 中。 */
	TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>> Entries;

	/** 用户当前展开的分类名，新打开 Tab 时为空，因此默认只显示分类。 */
	TSet<FName> ExpandedCategoryNames;

	/** 标记下一次有效列表构建需要默认展开全部分类，用于首次打开和地图切换后的新世界。 */
	bool bShouldExpandAllCategoriesOnNextRefresh = true;

	/** 当前左侧选中的设置类型条目。 */
	TSharedPtr<FGenericWorldSettingsEditorEntry> SelectedEntry;

	/** 根内容切换器：加载中只显示 Loading，加载完成后显示实际工具栏和内容。 */
	TSharedPtr<SWidgetSwitcher> RootSwitcher;

	/** 左侧设置类型树控件，固定为分类和设置项两层。 */
	TSharedPtr<STreeView<TSharedPtr<FGenericWorldSettingsEditorEntry>>> SettingsTreeView;

	/** 主内容区切换器：无总集时显示创建按钮，有总集时显示设置列表和 Details 面板。 */
	TSharedPtr<SWidgetSwitcher> ContentSwitcher;

	/** 右侧属性编辑器，直接展示地图中嵌入的设置实例。 */
	TSharedPtr<IDetailsView> DetailsView;
};
