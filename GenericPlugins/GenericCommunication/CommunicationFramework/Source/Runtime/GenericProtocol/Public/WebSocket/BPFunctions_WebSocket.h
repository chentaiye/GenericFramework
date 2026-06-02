// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocketType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_WebSocket.generated.h"

/** 提供 WebSocket 协议、关闭码转换和 URL 构造的蓝图辅助入口。 */
UCLASS(MinimalAPI)
class UBPFunctions_WebSocket : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 将协议字符串转为蓝图枚举，便于配置文本驱动 ws 或 wss 选择。 */
	UFUNCTION(BlueprintPure, Category="WebSocket", meta=(DisplayName="To WebSocket Protocol Enum", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API EGenericWebSocketProtocol BP_ConvertToWebSocketProtocolEnum(FString InProtocol);

	/** 将协议枚举转为底层连接和 URL 拼接需要的字符串。 */
	UFUNCTION(BlueprintPure, Category="WebSocket", meta=(DisplayName="To WebSocket Protocol String", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API FString BP_ConvertToWebSocketProtocolString(EGenericWebSocketProtocol InProtocol);

	/** 将整数关闭码转为蓝图枚举，供关闭回调做稳定分支判断。 */
	UFUNCTION(BlueprintPure, Category="WebSocket", meta=(DisplayName="To WebSocket Code Enum", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API EGenericWebSocketCode BP_ConvertToWebSocketCodeEnum(int32 InCode);

	/** 将关闭码枚举还原为整数，便于日志、UI 或外部协议继续使用原始状态码。 */
	UFUNCTION(BlueprintPure, Category="WebSocket", meta=(DisplayName="To WebSocket Code Int", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API int32 BP_ConvertToWebSocketCodeInt(EGenericWebSocketCode InCode);

public:
	/** 组合协议、主机和端口生成 WebSocket URL，和 FGenericWebSocketConnection::GetUrl 保持一致。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	static GENERICPROTOCOL_API FString GetWebSocketUrl(FString Host, int32 Port, EGenericWebSocketProtocol Protocol);
};
