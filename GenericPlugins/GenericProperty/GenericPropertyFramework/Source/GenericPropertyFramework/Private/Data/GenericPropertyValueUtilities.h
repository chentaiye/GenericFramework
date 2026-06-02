#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"

class UGenericPropertyProxy;
class UGenericProperty;

namespace GenericPropertyFramework::Private
{
	/** 通过代理目标和节点访问路径读取序列化值。 */
	FGenericPropertyReadResult ReadNodeValue(const UGenericPropertyProxy& InProxy, const UGenericProperty& InNode);

	/** 校验并把节点当前序列化值写回所有目标对象。 */
	FGenericPropertyWriteResult WriteNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, const FString& InValue);

	/** 使用反射属性和节点元数据校验序列化输入。 */
	FGenericPropertyValidationResult ValidateNodeValue(const UGenericPropertyProxy& InProxy, const UGenericProperty& InNode, const FString& InValue);

	/** 按源值或类默认值重置节点，并根据应用模式决定是否写回。 */
	bool ResetNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, EGenericPropertyResetMode InMode);

	/** 对数组、Set 或 Map 容器添加默认元素。 */
	FGenericPropertyWriteResult AddContainerNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode);

	/** 从父容器中移除节点对应的元素或条目。 */
	FGenericPropertyWriteResult RemoveNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode);

	/** 复制数组元素节点的当前值到相邻新元素。 */
	FGenericPropertyWriteResult DuplicateNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode);

	/** 在父数组中移动节点对应元素到目标索引。 */
	FGenericPropertyWriteResult MoveNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, int32 InNewIndex);

	/** 清空容器节点对应的底层数组、Set 或 Map。 */
	FGenericPropertyWriteResult ClearNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode);
}
