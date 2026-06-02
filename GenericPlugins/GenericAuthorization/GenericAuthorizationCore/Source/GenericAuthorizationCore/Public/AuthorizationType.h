// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.generated.h"

GENERICAUTHORIZATIONCORE_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogAuthorization, Log, All);

/** 区分授权项绑定的内容层级，许可证 Grant 和内容 Manifest 都用它解释同一个 ScopeId 所代表的授权粒度。 */
UENUM(BlueprintType)
enum class EAuthorizationScopeType : uint8
{
	/** 基础包权限，子系统通过配置的 BaseScopeId 查询该范围来决定应用整体是否可运行。 */
	BaseApp,

	/** DLC 内容权限，Manifest 中的 PakFiles 可归入该范围并由 Pak 挂载守卫按授权状态放行。 */
	DLC,

	/** 普通功能权限，用于非基础包和非 DLC 的可选功能开关。 */
	Feature
};

/** 描述 Grant 的有效期模型，范围状态检查会据此决定是否需要比较过期时间。 */
UENUM(BlueprintType)
enum class EAuthorizationGrantType : uint8
{
	/** 有期限授权，GetScopeState 会结合 ExpireAtUnixSeconds 和宽限期返回 Authorized 或 Expired。 */
	Timed,

	/** 永久授权，FAuthorizationGrant::IsPermanent 使到期检查直接放行。 */
	Permanent
};

/** 标记当前授权数据来自哪条加载链路，缓存路径、Provider 选择和持久化策略都会按来源分流。 */
UENUM(BlueprintType)
enum class EAuthorizationSourceType : uint8
{
	/** 尚未应用任何来源，重置状态或避免写入来源缓存时使用。 */
	None,

	/** 在线 Provider 或在线缓存来源，加载优先级和持久化目录使用在线配置。 */
	Online,

	/** 本地文件、包体旁授权或离线缓存来源，支持无网络激活和独立缓存目录。 */
	Offline
};

/** 统一授权校验结果，子系统、蓝图接口和挂载守卫用它解释失败原因并决定是否阻断流程。 */
UENUM(BlueprintType)
enum class EAuthorizationState : uint8
{
	/** 未加载许可证或目标 Scope 没有对应 Grant，调用方应提示导入或激活授权。 */
	Unauthorized,

	/** 许可证、绑定信息和可选 Manifest 校验通过，目标流程可以继续。 */
	Authorized,

	/** Grant 已超过过期时间和宽限期，生命周期监控会触发续期或重新授权路径。 */
	Expired,

	/** Grant 被显式撤销，即使时间未过期也按不可用处理。 */
	Revoked,

	/** 许可证签名缺失或与规范化载荷不匹配，说明令牌不可被当前密钥信任。 */
	InvalidSignature,

	/** 许可证的设备绑定与当前设备指纹不一致，启用机器绑定时阻断授权。 */
	DeviceMismatch,

	/** 许可证的包体指纹与当前构建不一致，启用包体绑定时阻断授权。 */
	PackageMismatch,

	/** 许可证或 Manifest 的 ProductId 与当前项目解析出的产品标识不一致。 */
	ProductMismatch,

	/** 本地时间早于已信任时间并超过容忍窗口，防止通过回拨系统时间绕过过期检查。 */
	ClockRollback,

	/** 需要内容清单但当前没有可用 Manifest，Pak 挂载判断无法建立 Scope 映射。 */
	MissingManifest,

	/** Manifest 签名或结构校验失败，内容范围和 Pak 绑定信息不可被信任。 */
	InvalidManifest
};

/** 暴露可授权内容范围的轻量描述，适合 UI 或蓝图在不持有完整 Manifest 时展示 Scope 与 Pak 绑定关系。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationScopeDescriptor
{
	GENERATED_BODY()

public:
	/** 范围的稳定键，许可证 Grant、Manifest Scope 和子系统查询都通过它对齐同一个授权对象。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FName ScopeId = NAME_None;

	/** 范围所属层级，帮助界面和校验逻辑区分基础包、DLC 与普通功能。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	EAuthorizationScopeType ScopeType=EAuthorizationScopeType::Feature;

	/** 面向用户的显示名称，用于授权提示或内容列表而不影响签名匹配键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DisplayName;

	/** 范围版本，参与签名规范化时可区分同一 Scope 的不同发布批次。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Version;

	/** 该范围声明的 Pak/容器文件路径，挂载守卫会用归一化路径把实际文件映射回 Scope。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TArray<FString> PakFiles;

	/** 控制匹配到该范围时是否必须检查 Grant；公共内容可关闭该标记直接放行。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	bool bRequiresAuthorization=true;
};

/** 持久化本地授权运行状态，子系统用它恢复设备/包体上下文和可信时间，避免每次启动都丢失防回拨基线。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationRuntimeState
{
	GENERATED_BODY()

public:
	/** 最近保存状态时的设备指纹，用于恢复后与当前设备上下文保持一致。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString CurrentDeviceId;

	/** 最近保存状态时的包体指纹，用于按构建隔离缓存并辅助绑定校验。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString CurrentPackageFingerprint;

	/** 已接受过的最大可信 Unix 时间，ClockGuard 用它识别本地时间回拨。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 LastTrustedUnixSeconds=0;

	/** 最近一次刷新成功的 Unix 时间，授权监控和后续续期策略可据此判断缓存新鲜度。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 LastSuccessfulRefreshUnixSeconds=0;
};
