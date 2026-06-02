// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.h"

/** 封装语音路由Resolver。 */
struct GENERICVOICEFRAMEWORK_API FVoiceRouteResolver
{
/** 构建候选项列表，供语音服务请求发送复用。 */
	static TArray<FVoiceProviderRouteCandidate> BuildCandidates(EVoiceRoutePolicy InPolicy, FName InOnlineProvider, FName InOfflineProvider);

	/** 判断AllowsFallback，让调用方按布尔结果选择后续路径。 */
	static bool AllowsFallback(EVoiceRoutePolicy InPolicy);
};
