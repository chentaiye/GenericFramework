// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPITypes.h"

class FJsonValue;

/** 集中处理 NativeAPI JSON 格式识别与 Payload 转换，避免接口、会话和测试重复解析同一协议。 */
class FNativeAPIUtilities
{
public:
	/** 校验 JSON 是否至少包含 NativeAPI 协议入口字段，模拟入口和会话入口都用它过滤无关消息。 */
	static bool IsNativeAPIJson(const TSharedPtr<FJsonObject>& Json);

	/** 判断字段名是否属于可调用任务，解析器只把 `API_` 前缀字段转换成 FNativeAPITask。 */
	static bool IsNativeAPIFunctionName(const FName& InName);

	/** 把外部 JSON 转换为可分发 Payload，负责解析实体目标、任务参数、可选世界路径和实体路径。 */
	static bool ConvertNativeAPIJsonToPayload(const TSharedPtr<FJsonObject>& InJson, FNativeAPIPayload& OutPayload);
};
