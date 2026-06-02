// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunction_Network.generated.h"

/** 为蓝图集中提供网络身份转换和会话句柄查询入口，避免脚本层直接依赖 PlayerState 或子系统实现细节。 */
UCLASS(MinimalAPI)
class UBPFunction_Network : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 从玩家控制器构造框架网络身份，让蓝图可直接把本地玩家传给会话创建或搜索节点。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(DisplayName="To Unique Network ID (PlayerController)", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICNETWORKFRAMEWORK_API FUniqueNetworkID Conv_PlayerControllerToUniqueNetworkID(APlayerController* InPlayerController);

	/** 从玩家状态构造框架网络身份，适用于已经拿到 PlayerState 的注册或查询流程。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(DisplayName="To Unique Network ID (PlayerState)", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICNETWORKFRAMEWORK_API FUniqueNetworkID Conv_PlayerStateToUniqueNetworkID(APlayerState* InPlayerState);

	/** 把复制的 Online UniqueId 包装成框架网络身份，便于蓝图复用统一的会话参数类型。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(DisplayName="To Unique Network ID (UniqueNetIdRepl)", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICNETWORKFRAMEWORK_API FUniqueNetworkID Conv_UniqueNetIdReplToUniqueNetworkID(const FUniqueNetIdRepl& InUniqueNetIDRepl);

public:
	/** 按框架网络身份查询子系统缓存的会话句柄，用于从玩家反查当前会话名和设置。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(WorldContext="WorldContextObject"))
	static GENERICNETWORKFRAMEWORK_API bool GetSessionHandleByUniqueNetID(const UObject* WorldContextObject, const FUniqueNetworkID& UniqueNetworkID, FGenericSessionHandle& OutHandle);

	/** 按复制的 Online UniqueId 查询会话句柄，供只有 PlayerState UniqueId 的蓝图路径使用。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(WorldContext="WorldContextObject"))
	static GENERICNETWORKFRAMEWORK_API bool GetSessionHandleByNetID(const UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueNetIDRepl, FGenericSessionHandle& OutHandle);

	/** 按会话名查询缓存句柄，供 UI 或生命周期逻辑从名称回查完整上下文。 */
	UFUNCTION(BlueprintPure, Category="Network", meta=(WorldContext="WorldContextObject"))
	static GENERICNETWORKFRAMEWORK_API bool GetSessionHandleByName(const UObject* WorldContextObject, FName InSessionName, FGenericSessionHandle& OutHandle);
};
