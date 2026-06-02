// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "AuthorizationSettings.generated.h"

/** 保存授权系统的全局策略，子系统、校验器、存储层和 Provider 选择都会从这里读取同一份项目配置。 */
UCLASS(MinimalAPI, config=GenericSettings, DefaultConfig)
class UAuthorizationSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	/** 返回默认配置对象，供无 World 上下文的授权工具函数读取项目级策略。 */
	static const ThisClass* Get() { return GetDefault<ThisClass>(); }

	/** 当前产品标识，写入许可证、Manifest 和缓存根目录，并在校验时防止跨产品授权复用。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="产品 ID"))
	FString ProductId=TEXT("DevProject");

	/** 基础应用 Scope，子系统用它查询 BaseApp Grant 来决定启动拦截和全局可运行状态。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="基础包 Scope"))
	FName BaseScopeId=TEXT("base_app");

	/** 总开关，关闭后全局授权状态直接视为 Authorized，并跳过缓存加载、弹窗和生命周期阻断。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="启用授权"))
	bool bEnableAuthorization=true;

	/** 控制未授权时是否在启动地图 BeginPlay 前拦截，避免游戏逻辑在授权完成前进入主流程。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="启动前拦截授权"))
	bool bInterceptBeforeStartupMap=true;

	/** 决定自动加载缓存时先尝试在线来源还是离线来源，也影响默认 Provider 解析的倾向。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="优先使用在线授权"))
	bool bPreferOnlineAuthorization=true;

	/** 未获得基础包授权时自动弹出授权窗口，关闭后调用方需要自行驱动导入或激活流程。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="未授权时自动弹窗"))
	bool bAutoPromptForAuthorization=true;

	/** 授权弹窗被取消后请求退出进程，用于必须授权才能运行的发行包。 */
	UPROPERTY(Config, EditAnywhere, Category="Basic Settings", meta=(DisplayName="取消授权后退出"))
	bool bExitIfAuthorizationPromptCancelled=true;

	/** 基础包 Grant 接近过期时启用提示和重新授权窗口，生命周期监控会按该开关决定是否提醒。 */
	UPROPERTY(Config, EditAnywhere, Category="Expiration Warning", meta=(DisplayName="启用到期预警"))
	bool bEnableExpirationWarning=true;

	/** 到期前的提醒提前量；Grant 剩余时间进入该窗口后，授权监控会显示续期提示。 */
	UPROPERTY(Config, EditAnywhere, Category="Expiration Warning", meta=(DisplayName="预警提前秒数", ClampMin="60", EditCondition="bEnableExpirationWarning"))
	int32 ExpirationWarningLeadSeconds=86400;

	/** 允许在线来源参与加载、激活和刷新；关闭后在线 Provider 即使已注册也不会被子系统选用。 */
	UPROPERTY(Config, EditAnywhere, Category="Online Authorization", meta=(DisplayName="启用在线授权"))
	bool bEnableOnlineAuthorization=false;

	/** 启动加载授权状态时自动尝试在线缓存，配合优先级设置决定是否先于离线来源使用。 */
	UPROPERTY(Config, EditAnywhere, Category="Online Authorization", meta=(DisplayName="自动读取在线缓存"))
	bool bAutoLoadOnlineAuthorizationCache=true;

	/** 在线激活或刷新成功后将许可证、Manifest 和运行时状态写入在线缓存目录。 */
	UPROPERTY(Config, EditAnywhere, Category="Online Authorization", meta=(DisplayName="持久化在线缓存"))
	bool bPersistOnlineAuthorization=true;

	/** 没有显式指定 Provider 时优先尝试的在线 Provider 名称。 */
	UPROPERTY(Config, EditAnywhere, Category="Online Authorization", meta=(DisplayName="首选在线 Provider"))
	FName PreferredOnlineProvider=NAME_None;

	/** 允许本地文件、包体旁授权和离线缓存参与授权链路。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="启用离线授权"))
	bool bEnableOfflineAuthorization=false;

	/** 启动加载授权状态时自动读取离线缓存目录中的许可证和 Manifest。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="自动读取离线缓存"))
	bool bAutoLoadOfflineAuthorizationCache=true;

	/** 离线缓存无效时继续尝试包体旁授权目录，便于发行包随附授权文件。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="自动读取包体旁授权文件"))
	bool bAutoLoadOfflineLocalFiles=true;

	/** 离线导入或本地 Provider 激活成功后写入离线缓存，后续启动可直接恢复。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="持久化离线缓存"))
	bool bPersistOfflineAuthorization=true;

	/** 包体旁授权目录，存储层会解析为项目目录下路径并查找离线 license 与 Manifest 文件。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="包体旁授权目录", RelativeToGameDir))
	FDirectoryPath OfflineAuthorizationDirectory;

	/** 没有显式指定 Provider 时优先尝试的离线 Provider 名称，默认对应本地文件 Provider。 */
	UPROPERTY(Config, EditAnywhere, Category="Offline Authorization", meta=(DisplayName="首选离线 Provider"))
	FName PreferredOfflineProvider=TEXT("LocalFile");

	/** 签名和传输编码共用密钥，校验器用它验证许可证/Manifest，Codec 用它加解密请求码和令牌码。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="签名密钥", PasswordField=true))
	FString VerificationKey=TEXT("GenericAuthorizationDevKey");

	/** 要求许可证 DeviceId 匹配当前设备指纹，防止许可证在其他机器上复用。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="绑定机器"))
	bool bRequireDeviceBinding=true;

	/** 要求许可证 PackageFingerprint 匹配当前构建指纹，并按构建隔离缓存目录。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="绑定包体版本"))
	bool bRequirePackageBinding=true;

	/** 使用持久化可信时间检测本地时间回拨，避免通过修改系统时间绕过 Grant 过期。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="防本地回拨时间"))
	bool bEnableClockRollbackProtection=true;

	/** 时间回拨容忍窗口，小幅时钟漂移不会触发 ClockRollback 状态。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="允许回拨秒数", ClampMin="0", EditCondition="bEnableClockRollbackProtection"))
	int32 AllowedClockRollbackSeconds=300;

	/** Grant 到期后的宽限秒数，GetScopeState 在判断 Expired 时会加入该缓冲。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="授权宽限秒数", ClampMin="0"))
	int32 GracePeriodSeconds=0;

	/** 要求 Manifest 也带有有效签名，确保 Pak 与 Scope 的映射未被本地篡改。 */
	UPROPERTY(Config, EditAnywhere, Category="Security and Validation", meta=(DisplayName="强制校验 Manifest 签名"))
	bool bRequireManifestSignature=false;

	/** 重置或启动时自动读取项目 Manifest，使没有授权缓存时仍可建立内容范围和 Pak 映射。 */
	UPROPERTY(Config, EditAnywhere, Category="Content Manifest", meta=(DisplayName="自动读取项目 Manifest"))
	bool bAutoLoadProjectManifest=true;

	/** 项目 Manifest 文件路径，存储层会解析相对项目目录的路径并交给校验器解析。 */
	UPROPERTY(Config, EditAnywhere, Category="Content Manifest", meta=(DisplayName="项目 Manifest 文件", RelativeToGameDir))
	FFilePath ProjectManifestFile;

	/** 应用设置目录下的授权缓存根目录名，在线/离线缓存都会放在该根目录内。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="公共缓存根目录名"))
	FString CacheRelativeDirectory=TEXT("GenericAuthorization");

	/** 缓存和包体旁目录中许可证令牌文件名，所有读取和写入路径都复用该名称。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="License 文件名"))
	FString LicenseFileName=TEXT("license.token.json");

	/** 缓存和包体旁目录中 Manifest 文件名，本地 Provider 也会用它查找同目录清单。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="Manifest 文件名"))
	FString ManifestFileName=TEXT("content.manifest.json");

	/** 持久化运行时状态文件名，用于保存可信时间和当前设备/包体上下文。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="运行时状态文件名"))
	FString RuntimeStateFileName=TEXT("runtime.state.json");

	/** 在线来源缓存的子目录名，使在线和离线授权数据互不覆盖。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="在线缓存目录名"))
	FString OnlineCacheDirectoryName=TEXT("Online");

	/** 离线来源缓存的子目录名，使本地导入授权可独立于在线缓存恢复。 */
	UPROPERTY(Config, EditAnywhere, AdvancedDisplay, Category="Advanced", meta=(DisplayName="离线缓存目录名"))
	FString OfflineCacheDirectoryName=TEXT("Offline");
};
