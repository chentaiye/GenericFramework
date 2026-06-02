// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "AuthorizationLicenseToken.generated.h"

/** 描述许可证授予的单个 Scope 权限，子系统通过它判断基础包、DLC 或功能是否可用。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationGrant
{
	GENERATED_BODY()

public:
	/** 被授予权限的 Scope 键，必须与 Manifest Scope 和查询接口使用的 ScopeId 对齐。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FName ScopeId=NAME_None;

	/** Scope 所属层级，用于签名规范化和外部展示时区分基础包、DLC 与功能授权。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	EAuthorizationScopeType ScopeType=EAuthorizationScopeType::Feature;

	/** 授权有效期模型，决定 IsPermanent 和 IsExpired 如何解释过期时间。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	EAuthorizationGrantType GrantType=EAuthorizationGrantType::Timed;

	/** 面向用户的授权名称，进入签名载荷以保证展示内容与令牌一起受保护。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DisplayName;

	/** 授权范围版本，签名排序和载荷会保留它以区分不同发布批次。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Version;

	/** Grant 签发时间，生命周期提示会用它与过期时间计算授权总时长。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 IssuedAtUnixSeconds=0;

	/** Grant 到期时间；Timed 授权超过该时间和宽限期后会返回 Expired。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 ExpireAtUnixSeconds=0;

	/** 撤销标记，置位后 IsExpired 和 Scope 状态判断都会把该授权视为不可用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	bool bRevoked=false;

	/** 判断该 Grant 是否绕过过期时间检查，永久类型或非正过期时间都会被视为长期有效。 */
	bool IsPermanent() const { return GrantType == EAuthorizationGrantType::Permanent || ExpireAtUnixSeconds <= 0; }

	/** 按当前时间和配置的宽限期判断授权是否不可继续使用，供 GetScopeState 返回 Expired 或 Revoked。 */
	bool IsExpired(const int64 CurrentUnixSeconds, const int32 GracePeriodSeconds = 0) const
	{
		if (bRevoked)
		{
			return true;
		}

		if (IsPermanent()) { return false; }

		return CurrentUnixSeconds > (ExpireAtUnixSeconds + FMath::Max(0, GracePeriodSeconds));
	}
};

/** 承载可持久化和可签名的许可证令牌，子系统加载后用它校验产品、设备、包体和各 Scope Grant。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationLicenseToken
{
	GENERATED_BODY()

public:
	/** 令牌结构版本，参与签名载荷以便后续协议升级时区分格式。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString SchemaVersion = TEXT("1.0");

	/** 许可证唯一标识，状态跟踪和过期提示会用它区分不同授权实例。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString LicenseId;

	/** 令牌绑定的产品标识，VerifyLicenseToken 会与当前设置解析出的产品标识比较。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ProductId;

	/** 令牌绑定的设备指纹，启用机器绑定时必须匹配当前设备。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DeviceId;

	/** 令牌绑定的构建指纹，启用包体绑定时必须匹配当前可执行和内容容器状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString PackageFingerprint;

	/** 令牌签发时间，进入签名载荷以固定许可证生成时刻。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 IssuedAtUnixSeconds=0;

	/** 令牌授予的 Scope 列表，FindGrant 和 GetScopeState 通过它决定具体内容是否授权。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TArray<FAuthorizationGrant> Grants;

	/** 对规范化令牌载荷生成的签名，校验失败时令牌不会被应用到运行时状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Signature;

	/** 判断令牌是否没有可用身份和 Grant，加载或校验时用作快速失败条件。 */
	bool IsEmpty() const { return LicenseId.IsEmpty() && Grants.IsEmpty(); }

	/** 恢复为默认空令牌，子系统清理授权状态时用它清空当前许可证。 */
	void Reset()
	{
		SchemaVersion = TEXT("1.0");
		LicenseId.Empty();
		ProductId.Empty();
		DeviceId.Empty();
		PackageFingerprint.Empty();
		IssuedAtUnixSeconds = 0;
		Grants.Reset();
		Signature.Empty();
	}

	/** 按 ScopeId 查找授权 Grant，Scope 状态查询和基础包授权判断都依赖该匹配。 */
	const FAuthorizationGrant* FindGrant(const FName ScopeId) const
	{
		return Grants.FindByPredicate([ScopeId](const FAuthorizationGrant& Grant)
		{
			return Grant.ScopeId == ScopeId;
		});
	}
};
