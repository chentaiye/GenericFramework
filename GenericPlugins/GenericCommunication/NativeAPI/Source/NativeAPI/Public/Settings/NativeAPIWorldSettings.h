// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPITypes.h"
#include "WebSocket/WebSocketType.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "NativeAPIWorldSettings.generated.h"

class UWorld;

/** 保存当前世界激活 NativeAPI 外部入口所需配置，加载和卸载时会通知引擎子系统切换会话。 */
UCLASS(MinimalAPI)
class UNativeAPIWorldSettings : public UGenericWorldSettings
{
	GENERATED_BODY()

public:
	/** 标记当前世界是否通过 WebSocket 接收 NativeAPI 消息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WebSocket")
	bool bSupportWebSocket = false;

	/** WebSocket 连接失败时是否继续重连，适合外部服务晚于 PIE 或游戏进程启动的场景。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WebSocket", meta=(EditCondition="bSupportWebSocket"))
	bool bConnectWebSocketUntilSuccess = true;

	/** WebSocket 会话使用的连接地址、协议和请求头。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WebSocket", meta=(EditCondition="bSupportWebSocket"))
	FGenericWebSocketConnection Connect;

	/** 标记当前世界是否开启 HTTP 路由入口接收 NativeAPI 消息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HTTP")
	bool bSupportHTTPRoute = false;

	/** HTTP 路由监听端口，StartSession 用它取得 IHttpRouter 并绑定 `/NativeAPI` POST 入口；INDEX_NONE 时不创建有效监听。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HTTP", meta=(EditCondition="bSupportHTTPRoute", ClampMin=-1, ClampMax=65545, UIMin=-1, UIMax=65535))
	int32 HTTPRoutePort = INDEX_NONE;

protected:
#if WITH_EDITOR
	virtual FName GetSettingsCategory_Implementation() const override;
#endif

	virtual void OnWorldSettingsLoaded_Implementation(UWorld* World) override;
	virtual void OnWorldSettingsBeginTearDown_Implementation(UWorld* World) override;
	virtual void OnWorldSettingsUnloaded_Implementation(UWorld* World) override;
	virtual void OnWorldSettingsBeginDestroy_Implementation() override;
};
