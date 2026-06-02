// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "Type/IOTTypes.h"
#include "IOTSettings.generated.h"

/** 保存 GenericIOT 的默认连接和自动化策略，子系统初始化时从这里加载运行时配置。 */
UCLASS(MinimalAPI, config=GenericSettings, DefaultConfig)
class UIOTSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	/** 初始化默认自动发现地址，保证未配置项目也能尝试常见 Home Assistant 入口。 */
	GENERICIOTFRAMEWORK_API UIOTSettings();
	static UIOTSettings* Get() { return GetMutableDefault<UIOTSettings>(); }

#if WITH_EDITOR
	virtual FText GetSectionText() const override { return FText::FromString(TEXT("IOT Settings")); }
#endif

	/** Home Assistant 默认 Endpoint，子系统启动时复制到运行时连接配置。 */
	UPROPERTY(Config, EditAnywhere, Category="HomeAssistant")
	FIOTPlatformEndpointConfig HomeAssistantEndpoint;

	/** 控制子系统 Initialize 后是否立即尝试连接平台。 */
	UPROPERTY(Config, EditAnywhere, Category="Runtime")
	bool bAutoConnectOnInitialize=true;

	/** 控制首次进入 Connected 状态后是否自动拉取设备快照。 */
	UPROPERTY(Config, EditAnywhere, Category="Runtime")
	bool bAutoRefreshDevicesOnConnect=true;

	/** 控制首次连接成功后是否自动建立实时状态订阅。 */
	UPROPERTY(Config, EditAnywhere, Category="Runtime")
	bool bAutoSubscribeRealtimeOnConnect=true;

	/** 控制 BaseUrl 为空时是否启用自动发现候选地址探测。 */
	UPROPERTY(Config, EditAnywhere, Category="Discovery")
	bool bEnableAutoDiscovery=true;

	/** 用户配置的自动发现候选基础地址，会与发现提供器返回的地址合并去重。 */
	UPROPERTY(Config, EditAnywhere, Category="Discovery")
	TArray<FString> DiscoveryBaseUrls;
};
