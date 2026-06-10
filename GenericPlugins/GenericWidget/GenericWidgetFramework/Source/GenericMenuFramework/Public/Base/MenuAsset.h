// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif
#include "MenuAsset.generated.h"

class UMenuNode;
class FObjectPreSaveContext;

/** 作为UIMenuAsset能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(BlueprintType)
class GENERICMENUFRAMEWORK_API UMenuAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化菜单资产默认状态。 */
	UMenuAsset();

	/** 确保菜单资产存在有效根节点，并修复根节点父级和全量节点列表。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	void EnsureRootNode();

	/** 在指定父节点末尾创建子节点。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	UMenuNode* CreateChildNode(UMenuNode* InParentNode, FVector2D InGraphPosition = FVector2D::ZeroVector);
	UMenuNode* CreateChildNode(UMenuNode* InParentNode, TSubclassOf<UMenuNode> InNodeClass, FVector2D InGraphPosition = FVector2D::ZeroVector);

	/** 在指定父节点的目标顺序位置创建子节点。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	UMenuNode* CreateChildNodeAtIndex(UMenuNode* InParentNode, int32 InChildIndex, FVector2D InGraphPosition = FVector2D::ZeroVector);
	UMenuNode* CreateChildNodeAtIndex(UMenuNode* InParentNode, TSubclassOf<UMenuNode> InNodeClass, int32 InChildIndex, FVector2D InGraphPosition = FVector2D::ZeroVector);

	/** 使用来源节点的父级创建相邻兄弟节点，根节点不允许创建兄弟节点。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	UMenuNode* CreateSiblingNode(UMenuNode* InSourceNode, FVector2D InGraphPosition = FVector2D::ZeroVector);

	/** 删除指定节点及其完整子树，根节点不允许删除。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	bool DeleteNode(UMenuNode* InNode);

	/** 将节点移动到新的父节点末尾，同时保持菜单树有效。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	bool ReparentNode(UMenuNode* InNode, UMenuNode* InNewParent);

	/** 将节点移动到新父节点的指定顺序位置。 */
	UFUNCTION(BlueprintCallable, Category="Menu")
	bool ReparentNodeAtIndex(UMenuNode* InNode, UMenuNode* InNewParent, int32 InChildIndex);

	/** 检查节点是否可以移动到目标父节点下，防止根节点移动、自引用和循环。 */
	UFUNCTION(BlueprintPure, Category="Menu")
	bool CanReparentNode(UMenuNode* InNode, UMenuNode* InNewParent) const;

	/** 检查指定节点是否属于当前菜单资产。 */
	UFUNCTION(BlueprintPure, Category="Menu")
	bool ContainsNode(UMenuNode* InNode) const;

	/** 检查指定节点是否是当前菜单树根节点。 */
	UFUNCTION(BlueprintPure, Category="Menu")
	bool IsRootNode(UMenuNode* InNode) const;

	/** 检查候选节点是否位于指定父节点的子树内。 */
	UFUNCTION(BlueprintPure, Category="Menu")
	bool IsDescendantOf(UMenuNode* InCandidateNode, UMenuNode* InPotentialParent) const;

	virtual void PostLoad() override;
	virtual void PreSave(FObjectPreSaveContext SaveContext) override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif

private:
	/** 执行节点创建、父子关系挂接、唯一 ID 分配和资产脏标记。 */
	UMenuNode* CreateNodeInternal(UMenuNode* InParentNode, TSubclassOf<UMenuNode> InNodeClass, FVector2D InGraphPosition, int32 InChildIndex);

	/** 从指定节点开始收集整棵子树，供删除和清理流程使用。 */
	void CollectSubtree(UMenuNode* InNode, TArray<UMenuNode*>& OutNodes) const;

	/** 深度遍历菜单树并检测是否存在循环引用。 */
	bool HasCycle(UMenuNode* InNode, TSet<const UMenuNode*>& Visiting, TSet<const UMenuNode*>& Visited) const;

	/** 根据当前资产内已有菜单标识生成不重复的默认 MenuID。 */
	FString MakeUniqueMenuID(const FString& InBaseMenuID) const;

public:
	/** 持有根节点实例，供通用 UI运行时复用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category="Menu")
	TObjectPtr<UMenuNode> RootNode = nullptr;

	/** 持有All节点实例，供通用 UI运行时复用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category="Menu")
	TArray<TObjectPtr<UMenuNode>> AllNodes;
};
