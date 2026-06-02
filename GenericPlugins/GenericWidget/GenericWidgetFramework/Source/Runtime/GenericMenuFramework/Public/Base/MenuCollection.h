// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ButtonType.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "MenuCollection.generated.h"

class APlayerController;
class UGenericButtonGroup;
class UMenuAsset;
class UMenuContainer;
class UMenuNode;
class UMenuWidget;

/** 保存通用 UI流程中的Menu集合RuntimeButtonEntry数据，供运行时传递和蓝图访问。 */
USTRUCT()
struct FMenuCollectionRuntimeButtonEntry
{
	GENERATED_BODY()

	/** 持有节点实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UMenuNode> Node = nullptr;

	/** 持有Button控件实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UMenuWidget> ButtonWidget = nullptr;

	/** 保存Pressed句柄，用于解绑对应委托。 */
	FDelegateHandle PressedHandle;

	/** 保存Released句柄，用于解绑对应委托。 */
	FDelegateHandle ReleasedHandle;

	/** 保存Hovered句柄，用于解绑对应委托。 */
	FDelegateHandle HoveredHandle;

	/** 保存Unhovered句柄，用于解绑对应委托。 */
	FDelegateHandle UnhoveredHandle;

	/** 保存Clicked句柄，用于解绑对应委托。 */
	FDelegateHandle ClickedHandle;

	/** 保存双精度Clicked句柄，用于解绑对应委托。 */
	FDelegateHandle DoubleClickedHandle;

	/** 保存Selection变化句柄，用于解绑对应委托。 */
	FDelegateHandle SelectionChangedHandle;
};

/** 保存通用 UI流程中的Menu集合Runtime关卡Entry数据，供运行时传递和蓝图访问。 */
USTRUCT()
struct FMenuCollectionRuntimeLevelEntry
{
	GENERATED_BODY()

	/** 持有Owner节点实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UMenuNode> OwnerNode = nullptr;

	/** 持有Container实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UMenuContainer> Container = nullptr;

	/** 持有ButtonGroup实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonGroup> ButtonGroup = nullptr;

	/** 保存Buttons列表。 */
	UPROPERTY(Transient)
	TArray<FMenuCollectionRuntimeButtonEntry> Buttons;

	/** 记录RegisteredSlot标签。 */
	UPROPERTY(Transient)
	FGameplayTag RegisteredSlotTag;
};

/** 承载UIMenu集合职责，衔接上层调用与模块内部实现。 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class GENERICMENUFRAMEWORK_API UMenuCollection : public UObject
{
	GENERATED_BODY()

public:
	/** 获取菜单按钮事件类型对应的稳定文本名，用于生成蓝图函数名。 */
	static FString GetMenuButtonEventTypeName(EGenericButtonEvent InEventType);

	/** 构造菜单按钮事件在蓝图中对应的图名。 */
	static FName MakeMenuButtonEventGraphName(EGenericButtonEvent InEventType);

	/** 根据事件类型和菜单 ID 构造可被 ProcessEvent 调用的蓝图事件函数名。 */
	static FName MakeMenuButtonEventFunctionName(EGenericButtonEvent InEventType, const FString& InMenuID);

	/** 记录运行时菜单操作所属的玩家控制器，并在归属变化时清理旧菜单。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	bool Initialize(APlayerController* PlayerController);

	/** 从菜单资产根节点开始创建根容器和第一层菜单按钮。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	void BuildMenu();

	/** 移除全部已生成菜单层级并清理按钮事件绑定和槽位注册。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	void ClearMenu();

protected:
	/** 在菜单集合完成玩家控制器绑定后触发，供蓝图准备运行时状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuInitialized(APlayerController* PlayerController);

	/** 在菜单开始重建前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuBuildStarted();

	/** 在菜单构建结束后触发，并告知本次构建是否成功生成根层级。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuBuildFinished(bool bSucceeded);

	/** 在菜单开始清理前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuClearStarted();

	/** 在菜单全部运行时层级清理完成后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuClearFinished();

	/** 在指定节点对应的菜单层级开始构建前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuLevelBuildStarted(UMenuNode* OwnerNode);

	/** 在指定节点对应的菜单层级完成容器、按钮组和按钮构建后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuLevelBuilt(UMenuNode* OwnerNode, UMenuContainer* Container, UGenericButtonGroup* ButtonGroup);

	/** 在指定运行时菜单层级开始清理前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuLevelClearStarted(UMenuNode* OwnerNode, UMenuContainer* Container);

	/** 在指定运行时菜单层级完成清理后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuLevelCleared(UMenuNode* OwnerNode);

	/** 根据拥有节点的容器配置创建菜单层级容器。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	UMenuContainer* CreateButtonContainer(UMenuNode* OwnerNode);

	/** 根据拥有节点的按钮组配置创建该层级的选择管理对象。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	UGenericButtonGroup* CreateButtonGroup(UMenuNode* OwnerNode);

	/** 根据菜单子节点配置创建对应按钮控件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	UMenuWidget* CreateButtonWidget(UMenuNode* ButtonNode);

	/** 将菜单层级容器注册到 GenericWidget 槽位系统，子菜单层级可要求必须存在槽位标签。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	bool RegisterButtonContainer(UMenuContainer* Container, UMenuNode* OwnerNode, bool bRequireSlotTag);

	/** 将按钮注册到父容器对应的路由下，使其进入 GenericWidget 路由树。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	bool RegisterButton(UMenuContainer* ParentContainer, UMenuWidget* ButtonWidget, UMenuNode* ButtonNode);

	/** 将菜单节点中的可见性、标签、可用性和选中配置应用到按钮控件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void ApplyButtonState(UMenuWidget* ButtonWidget, UMenuNode* ButtonNode);

	/** 执行ApplyDefaultSelections流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void ApplyDefaultSelections(UMenuNode* OwnerNode);

	/** 在单个菜单按钮创建、注册并绑定事件后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuButtonBuilt(UMenuNode* ButtonNode, UMenuWidget* ButtonWidget);

	/** 在单个菜单按钮解绑并移除前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuButtonDestroyed(UMenuNode* ButtonNode, UMenuWidget* ButtonWidget);

	/** 在菜单按钮事件被统一接收后触发，先于动态生成函数执行结果回调。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuButtonEventReceived(EGenericButtonEvent EventType, UMenuNode* ButtonNode, UMenuWidget* ButtonWidget);

	/** 在菜单按钮事件尝试执行对应动态蓝图函数后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Menu")
	void OnMenuButtonGeneratedEventExecuted(EGenericButtonEvent EventType, UMenuNode* ButtonNode, bool bExecuted);

public:
	/** 记录集合名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FName CollectionName = NAME_None;

	/** 持有MenuAsset实例，供通用 UI运行时复用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	TObjectPtr<UMenuAsset> MenuAsset = nullptr;

private:
	/** 构建指定节点对应的运行时菜单层级，并返回 RuntimeLevels 中的索引。 */
	int32 BuildMenuLevel(UMenuNode* OwnerNode, bool bRequireSlotTag);

	/** 清理指定索引的运行时菜单层级并移除其容器、按钮和事件绑定。 */
	void ClearLevelAtIndex(int32 InLevelIndex);

	/** 清理指定节点及其子树对应的全部运行时菜单层级。 */
	void ClearDescendantLevels(UMenuNode* OwnerNode);

	/** 清理指定父节点所有子节点展开出的运行时菜单层级。 */
	void ClearChildLevelsOfParent(UMenuNode* ParentNode);

	/** 检查候选节点是否位于指定根节点的父链或子树范围内。 */
	bool IsNodeInSubtree(UMenuNode* CandidateNode, UMenuNode* RootNode) const;

	/** 查找指定拥有节点对应的运行时菜单层级。 */
	FMenuCollectionRuntimeLevelEntry* FindRuntimeLevel(UMenuNode* OwnerNode);

	/** 只读查找指定拥有节点对应的运行时菜单层级。 */
	const FMenuCollectionRuntimeLevelEntry* FindRuntimeLevel(UMenuNode* OwnerNode) const;

	/** 查找指定菜单节点当前生成出的按钮控件。 */
	UMenuWidget* FindRuntimeButtonWidget(UMenuNode* ButtonNode) const;

	/** 尝试执行事件类型和菜单 ID 共同生成出的蓝图事件函数。 */
	bool ExecuteMenuButtonEvent(EGenericButtonEvent InEventType, UMenuNode* ButtonNode);

	/** 执行句柄Button事件流程，并把结果同步给通用 UI相关状态。 */
	void HandleButtonEvent(EGenericButtonEvent InEventType, UMenuNode* ButtonNode);

	/** 处理ButtonSelection变化并同步相关状态。 */
	void HandleButtonSelectionChanged(bool bSelected, UMenuNode* ButtonNode);

private:
	/** 持有所属玩家Controller实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<APlayerController> OwningPlayerController = nullptr;

	/** 保存RuntimeLevels列表。 */
	UPROPERTY(Transient)
	TArray<FMenuCollectionRuntimeLevelEntry> RuntimeLevels;
};
