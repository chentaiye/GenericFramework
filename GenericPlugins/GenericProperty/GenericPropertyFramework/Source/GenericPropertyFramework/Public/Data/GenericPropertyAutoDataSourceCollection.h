#pragma once

#include "Data/GenericPropertyDataSourceCollection.h"
#include "GenericPropertyAutoDataSourceCollection.generated.h"

/** 基于 UObject 反射的默认数据源，负责自动生成属性树并刷新反射节点状态。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced, Transient)
class UGenericPropertyAutoDataSourceCollection : public UGenericPropertyDataSourceCollection
{
	GENERATED_BODY()

public:
	GENERICPROPERTYFRAMEWORK_API virtual void BuildRootNodes(TArray<UGenericProperty*>& OutNodes) override;
	GENERICPROPERTYFRAMEWORK_API virtual void RefreshNode(UGenericProperty& InNode) const override;
	GENERICPROPERTYFRAMEWORK_API virtual void RebuildNodeChildren(UGenericProperty& InNode) const override;
};
