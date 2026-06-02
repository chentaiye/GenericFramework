// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Manifest/AuthorizationManifest.h"
#include "License/AuthorizationLicenseToken.h"

class UAuthorizationSettings;

/** 负责授权文件路径解析和持久化读写，把在线、离线、项目清单和包体旁授权统一接入运行时加载流程。 */
class GENERICAUTHORIZATIONCORE_API FAuthorizationLicenseStore
{
public:
	/** 解析产品级公共缓存根目录，按产品和构建指纹隔离不同项目或包体的授权数据。 */
	static FString GetCommonCacheRootDirectory(const UAuthorizationSettings* InSettings = nullptr);

	/** 生成当前构建缓存键；启用包体绑定时使用包体指纹，否则让缓存落入 Shared 目录。 */
	static FString GetCurrentBuildCacheKey(const UAuthorizationSettings* InSettings = nullptr);

	/** 根据授权来源返回在线或离线缓存目录，自动加载和持久化流程都以此分流文件。 */
	static FString GetCacheDirectory(EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings = nullptr);

	/** 拼出指定来源的许可证令牌缓存路径，Load/SaveLicenseToken 会读写该文件。 */
	static FString GetLicenseTokenFilePath(EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings = nullptr);

	/** 拼出指定来源的 Manifest 缓存路径，内容清单随授权来源独立保存。 */
	static FString GetManifestFilePath(EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings = nullptr);

	/** 拼出指定来源的运行时状态路径，用于保存可信时间和当前绑定上下文。 */
	static FString GetRuntimeStateFilePath(EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings = nullptr);

	/** 将包体旁离线授权目录解析为绝对路径，空配置会回退到项目下 Authorization 目录。 */
	static FString GetResolvedOfflineAuthorizationDirectoryPath(const UAuthorizationSettings* InSettings = nullptr);

	/** 返回包体旁离线许可证路径，自动离线加载会在缓存失败后尝试该文件。 */
	static FString GetBundledOfflineLicenseTokenFilePath(const UAuthorizationSettings* InSettings = nullptr);

	/** 返回包体旁离线 Manifest 路径，使随包授权可以同时提供内容 Scope 映射。 */
	static FString GetBundledOfflineManifestFilePath(const UAuthorizationSettings* InSettings = nullptr);

	/** 解析项目 Manifest 配置路径，重置授权状态时可预加载内容清单用于 Pak 判断。 */
	static FString GetResolvedProjectManifestFilePath(const UAuthorizationSettings* InSettings = nullptr);

	/** 从指定来源缓存读取许可证文本并解析为令牌，启动自动加载和缓存恢复会调用它。 */
	static bool LoadLicenseToken(FAuthorizationLicenseToken& OutToken, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 将已验证或待持久化的许可证令牌序列化到指定来源缓存。 */
	static bool SaveLicenseToken(const FAuthorizationLicenseToken& InToken, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 从指定来源缓存读取 Manifest，并交给校验器解析为内容 Scope 映射。 */
	static bool LoadManifest(FAuthorizationManifest& OutManifest, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 读取项目 Manifest 配置文件，授权状态重置时用它建立默认内容清单。 */
	static bool LoadProjectManifest(FAuthorizationManifest& OutManifest, FString& OutError, const UAuthorizationSettings* InSettings = nullptr);

	/** 读取包体旁 Manifest，随包离线授权加载时用它补充 Pak 与 Scope 映射。 */
	static bool LoadBundledOfflineManifest(FAuthorizationManifest& OutManifest, FString& OutError, const UAuthorizationSettings* InSettings = nullptr);

	/** 将 Manifest 序列化到指定来源缓存，授权应用成功后用于后续启动恢复。 */
	static bool SaveManifest(const FAuthorizationManifest& InManifest, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 从指定来源缓存读取运行时状态，恢复可信时间并继续防回拨判断。 */
	static bool LoadRuntimeState(FAuthorizationRuntimeState& OutRuntimeState, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 将运行时状态写入指定来源缓存，保存刷新时间和当前绑定上下文。 */
	static bool SaveRuntimeState(const FAuthorizationRuntimeState& InRuntimeState, FString& OutError, EAuthorizationSourceType InSource = EAuthorizationSourceType::Online, const UAuthorizationSettings* InSettings = nullptr);

	/** 读取包体旁许可证令牌，离线自动加载会用它导入随发行包提供的授权。 */
	static bool LoadBundledOfflineLicenseToken(FAuthorizationLicenseToken& OutToken, FString& OutError, const UAuthorizationSettings* InSettings = nullptr);

	/** 删除指定来源的许可证、Manifest 和运行时状态文件，用于清理单一路径的授权缓存。 */
	static bool DeletePersistedAuthorization(EAuthorizationSourceType InSource, FString& OutError, const UAuthorizationSettings* InSettings = nullptr);

	/** 清空所有持久化授权数据，用于重置本地授权状态。 */
	static bool DeleteAllPersistedAuthorization(FString& OutError, const UAuthorizationSettings* InSettings = nullptr);

	/** 读取授权相关文本文件并统一错误格式，解析层可直接把错误返回给调用方。 */
	static bool ReadTextFile(const FString& FilePath, FString& OutText, FString& OutError);

	/** 写入授权相关文本文件并自动创建目录，缓存持久化失败时通过 OutError 说明文件路径。 */
	static bool WriteTextFile(const FString& FilePath, const FString& InText, FString& OutError);
};
