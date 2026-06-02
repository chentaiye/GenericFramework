#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "UObject/Object.h"
#include "GenericPropertyDataSourceCollection.generated.h"

class UGenericPropertyProxy;
class UGenericProperty;

/** 属性数据源基类，定义节点建树、读写、校验和容器结构修改的统一入口。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable, Abstract, EditInlineNew, DefaultToInstanced, Transient)
class UGenericPropertyDataSourceCollection : public UObject
{
	GENERATED_BODY()

public:
	/** 绑定拥有者代理和面板选项，供后续读写目标对象使用。 */
	GENERICPROPERTYFRAMEWORK_API virtual void Initialize(UGenericPropertyProxy* InOwnerProxy, const FGenericPropertyPanelOptions& InOptions);

	/** 构建根属性节点列表，集合会按这些节点生成分类展示。 */
	GENERICPROPERTYFRAMEWORK_API virtual void BuildRootNodes(TArray<UGenericProperty*>& OutNodes);

	/** 按访问路径从目标对象读取序列化值。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyReadResult ReadValue(const FGenericPropertyAccessPath& InPath) const;

	/** 按访问路径把序列化值写回目标对象。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult WriteValue(const FGenericPropertyAccessPath& InPath, const FString& InValue);

	/** 按访问路径校验序列化输入是否能安全写入目标属性。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyValidationResult ValidateValue(const FGenericPropertyAccessPath& InPath, const FString& InValue) const;

	/** 从目标对象刷新指定节点的文本值、编辑能力和问题状态。 */
	GENERICPROPERTYFRAMEWORK_API virtual void RefreshNode(UGenericProperty& InNode) const;

	/** 为可展开节点重新生成子节点。 */
	GENERICPROPERTYFRAMEWORK_API virtual void RebuildNodeChildren(UGenericProperty& InNode) const;

	/** 按重置模式恢复节点当前值。 */
	GENERICPROPERTYFRAMEWORK_API virtual bool ResetNode(UGenericProperty& InNode, const EGenericPropertyResetMode InMode);

	/** 向容器节点添加默认元素并返回结构修改结果。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult AddContainerElement(UGenericProperty& InNode);

	/** 从父容器移除指定元素节点。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult RemoveNode(UGenericProperty& InNode);

	/** 复制指定数组元素节点。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult DuplicateNode(UGenericProperty& InNode);

	/** 将数组元素节点移动到目标索引。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult MoveNode(UGenericProperty& InNode, int32 InNewIndex);

	/** 清空容器节点中的元素。 */
	GENERICPROPERTYFRAMEWORK_API virtual FGenericPropertyWriteResult ClearNode(UGenericProperty& InNode);

	/** 返回拥有者代理，便于蓝图扩展数据源访问会话目标。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	UGenericPropertyProxy* GetOwnerProxy() const { return OwnerProxy; }

protected:
	/** 拥有者代理，数据源通过它访问目标对象和同步选项。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericPropertyProxy> OwnerProxy;

	/** 当前面板选项，数据源建树和写入时读取只读、展开和过滤策略。 */
	FGenericPropertyPanelOptions Options;
};
