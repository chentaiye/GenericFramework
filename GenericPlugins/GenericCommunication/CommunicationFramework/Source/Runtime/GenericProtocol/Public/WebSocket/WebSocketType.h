// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/DebugType.h"
#include "StaticFunctions/StaticFunctions_Enum.h"
#include "WebSocketType.generated.h"

/** WebSocket 连接协议，构造 URL 时会作为 ws 或 wss 前缀。 */
UENUM(BlueprintType)
enum class EGenericWebSocketProtocol : uint8
{
	/** 明文 WebSocket 连接，生成 ws:// 地址。 */
	ws,

	/** TLS WebSocket 连接，生成 wss:// 地址。 */
	wss
};

/** 将协议字符串转换为蓝图枚举，供配置文本驱动连接参数。 */
inline EGenericWebSocketProtocol ConvertToWebSocketProtocolEnum(const FString& InProtocol)
{
	EGenericWebSocketProtocol HttpVerb = EGenericWebSocketProtocol::ws;
	if (FStaticFunctions_Enum::GetEnumByNameString(InProtocol, HttpVerb)) { return HttpVerb; }

	return HttpVerb;
}

/** 将协议枚举转换为 URL 和底层 WebSocket 模块使用的字符串。 */
inline FString ConvertToWebSocketProtocolString(EGenericWebSocketProtocol InProtocol) { return FStaticFunctions_Enum::GetEnumNameString(InProtocol); }

/** 保存 WebSocket 建连配置和重连状态，UGenericWebSocket 会用它创建底层连接。 */
USTRUCT(BlueprintType)
struct GENERICPROTOCOL_API FGenericWebSocketConnection
{
	GENERATED_BODY()

public:
	/** 目标主机名或 IP，GetUrl 会把它拼入连接地址。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type")
	FString Host;

	/** 目标端口，IsValid 会要求它不是 INDEX_NONE。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type", meta=(ClampMin=0, ClampMax=65535, UIMin=0, UIMax=65535))
	int32 Port=INDEX_NONE;

	/** 连接协议，决定最终 URL 使用 ws 还是 wss。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type")
	EGenericWebSocketProtocol Protocol=EGenericWebSocketProtocol::ws;

	/** 建连时传给底层 WebSocket 的请求头，用于认证或自定义握手信息。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type")
	TMap<FString, FString> Headers;

	/** 允许自动重连的最大尝试次数，负数表示不限制。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type", meta=(ClampMin=-1, UIMin=-1))
	int32 MaxReconnectionAttempts=-1;

	/** 每次重连前等待的秒数，0 表示立即重连。 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Web Socket Type", meta=(ClampMin=0, UIMin=0))
	float ReconnectIntervalTime=5.f;

public:
	/** 检查 Host 和 Port 是否足以创建连接，ConnectWithConnection 会据此阻断无效配置。 */
	bool IsValid() const;

	/** 组合协议、主机和端口生成底层 WebSocket 模块需要的 URL。 */
	FString GetUrl() const;

private:
	friend class UGenericWebSocket;

	/** 当前连接生命周期内已尝试重连的次数，Reconnect 用它判断是否超过上限。 */
	int32 ReconnectionAttempts = 0;
};

/** 常见 WebSocket 关闭代码，关闭异步节点会把整数状态映射到这些枚举。 */
UENUM(BlueprintType)
enum class EGenericWebSocketCode : uint8
{
	/** 1000，正常关闭。 */
	Code1000 UMETA(DisplayName="Code1000 : Close Normal"),

	/** 1001，端点离开或服务关闭。 */
	Code1001 UMETA(DisplayName="Code1001 : Close Going Away"),

	/** 1002，协议错误导致关闭。 */
	Code1002 UMETA(DisplayName="Code1002 : Close Protocol Error"),

	/** 1003，收到不支持的数据类型。 */
	Code1003 UMETA(DisplayName="Code1003 : Close Unsupported"),

	/** 1004，保留未定义关闭代码。 */
	Code1004 UMETA(DisplayName="Code1004 : Undefined"),

	/** 1005，没有收到状态码的本地占位。 */
	Code1005 UMETA(DisplayName="Code1005 : Close No Status"),

	/** 1006，异常关闭的本地占位。 */
	Code1006 UMETA(DisplayName="Code1006 : Close Abnormal"),

	/** 1007，载荷格式与消息类型不匹配。 */
	Code1007 UMETA(DisplayName="Code1007 : Unsupported Data"),

	/** 1008，消息违反策略。 */
	Code1008 UMETA(DisplayName="Code1008 : Policy Violation"),

	/** 1009，消息过大。 */
	Code1009 UMETA(DisplayName="Code1009 : Close Too Large"),

	/** 1010，客户端期望的扩展未被协商。 */
	Code1010 UMETA(DisplayName="Code1010 : Missing Extension"),

	/** 1011，服务端内部错误。 */
	Code1011 UMETA(DisplayName="Code1011 : Internal Error"),

	/** 1012，服务正在重启。 */
	Code1012 UMETA(DisplayName="Code1012 : Service Restart"),

	/** 1013，服务端建议稍后重试。 */
	Code1013 UMETA(DisplayName="Code1013 : Try Again Later"),

	/** 1014，上游网关类错误的保留代码。 */
	Code1014 UMETA(DisplayName="Code1014 : Undefined"),

	/** 1015，TLS 握手失败的本地占位。 */
	Code1015 UMETA(DisplayName="Code1015 : TLS Handshake"),

	/** 无法映射已知关闭代码时使用。 */
	CodeUnKnown UMETA(DisplayName="UnKnown Error")
};

/** 将整数关闭代码转换为蓝图枚举，供关闭回调稳定分支。 */
inline EGenericWebSocketCode ConvertToWebSocketCodeEnum(const int32 InCode)
{
	const FString CodeString = TEXT("Code") + FString::FromInt(InCode);

	EGenericWebSocketCode Code=EGenericWebSocketCode::CodeUnKnown;
	if (FStaticFunctions_Enum::GetEnumByNameString(CodeString, Code)) { return Code; }

	return Code;
}

/** 将关闭代码枚举还原为整数，CodeUnKnown 返回 -1。 */
inline int32 ConvertToWebSocketCodeInt(const EGenericWebSocketCode InCode)
{
	if (InCode == EGenericWebSocketCode::CodeUnKnown)
	{
		return -1;
	}

	FString CodeString = FStaticFunctions_Enum::GetEnumNameString(InCode);

	CodeString.Split(TEXT("Code"), nullptr, &CodeString, ESearchCase::CaseSensitive);

	return FCString::Atoi(*CodeString);
}
