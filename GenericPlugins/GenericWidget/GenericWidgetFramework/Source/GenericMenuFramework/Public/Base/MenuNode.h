// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MenuNode.generated.h"

/** 承载UIMenu节点职责，衔接上层调用与模块内部实现。 */
UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced)
class GENERICMENUFRAMEWORK_API UMenuNode : public UObject
{
	GENERATED_BODY()

public:
	/** 初始化节点并确保拥有稳定 Guid。 */
	UMenuNode();

	/** 检查当前节点是否没有父级，运行时会将其视为菜单树根节点。 */
	UFUNCTION(BlueprintPure, Category="Menu")
	bool IsRootNode() const;

	/** 在节点缺少 Guid 时生成稳定标识，供资产校验和编辑器图使用。 */
	void EnsureNodeGuid();

	/** 设置当前节点在菜单树中的父级引用。 */
	void SetParent(UMenuNode* InParent);

	/** 添加子节点并避免重复记录。 */
	void AddChild(UMenuNode* InChild);

	/** 将子节点移动到指定顺序位置，索引会被限制在有效范围内。 */
	void InsertChild(UMenuNode* InChild, int32 InChildIndex);

	/** 从当前节点的子节点列表中移除指定节点。 */
	void RemoveChild(UMenuNode* InChild);

	virtual void PostLoad() override;

public:
	/** 记录节点GUID。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Menu")
	FGuid NodeGuid;

	/** 记录Menu数据。 */
	/** 持有Parent实例，供通用 UI运行时复用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Menu")
	TObjectPtr<UMenuNode> Parent = nullptr;

	/** 持有Children实例，供通用 UI运行时复用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Menu")
	TArray<TObjectPtr<UMenuNode>> Children;

	/** 记录GraphPosition。 */
	UPROPERTY()
	FVector2D GraphPosition = FVector2D::ZeroVector;
};
