// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "UniqueNetworkIDInterface.generated.h"

/** 标记对象可以向网络身份组件提供玩家状态和框架身份，使组件无需了解具体拥有者类型。 */
UINTERFACE()
class UUniqueNetworkIDInterface : public UInterface
{
	GENERATED_BODY()
};

/** 由自定义拥有者实现的网络身份访问契约，供 UUniqueNetworkIDComponent 在非标准 Actor 类型上刷新身份。 */
class GENERICNETWORKFRAMEWORK_API IUniqueNetworkIDInterface
{
	GENERATED_BODY()

public:
	/** 返回可提供 Online UniqueId 的 PlayerState，组件刷新身份时会优先用它构造 FUniqueNetworkID。 */
	virtual APlayerState* GetPlayerState() = 0;

	/** 返回实现对象当前维护的框架网络身份，供外部系统读取统一身份数据。 */
	virtual const FUniqueNetworkID& GetUniqueNetworkID() = 0;

	/** 写入新的框架网络身份，使实现对象能与组件复制结果保持一致。 */
	virtual void SetUniqueNetworkID(const FUniqueNetworkID& InUniqueNetworkID) = 0;
};
