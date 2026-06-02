// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "AuthorizationManifest.generated.h"

/** 描述 Manifest 中一个可挂载内容范围，Pak 挂载守卫会用它把文件路径映射到授权 Scope。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationManifestScope
{
	GENERATED_BODY()

public:
	/** 内容范围的稳定键，必须与许可证 Grant 的 ScopeId 匹配才能按授权状态放行。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FName ScopeId=NAME_None;

	/** 内容范围层级，参与 Manifest 签名载荷并帮助外部界面区分基础包、DLC 和功能内容。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	EAuthorizationScopeType ScopeType=EAuthorizationScopeType::Feature;

	/** 面向用户的范围名称，随 Manifest 签名保护以防展示内容被本地篡改。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DisplayName;

	/** 内容范围版本，规范化签名载荷用它区分同一 Scope 的不同发布批次。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Version;

	/** 该范围包含的 Pak/容器文件路径，CanMountPakFile 会逐项归一化后与实际挂载路径匹配。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TArray<FString> PakFiles;

	/** 匹配该范围后是否继续检查许可证 Grant，公共内容可关闭以允许无需授权挂载。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	bool bRequiresAuthorization=true;
};

/** 承载内容清单和可选签名，子系统用它校验 Pak 与 Scope 的映射并阻止未授权内容挂载。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationManifest
{
	GENERATED_BODY()

public:
	/** Manifest 结构版本，进入签名载荷以支持未来格式升级。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString SchemaVersion=TEXT("1.0");

	/** Manifest 绑定的产品标识，VerifyManifest 会与当前产品标识比较以防跨项目复用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ProductId;

	/** Manifest 签发时间，参与签名载荷并说明内容清单生成时刻。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 IssuedAtUnixSeconds=0;

	/** 内容范围集合，CanMountPakFile 和 FindScope 都以它建立文件到授权状态的映射。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TArray<FAuthorizationManifestScope> Scopes;

	/** Manifest 规范化载荷签名；启用强制校验时签名无效会阻断清单使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Signature;

	/** 判断清单是否缺少产品和范围信息，加载失败或未配置项目 Manifest 时用于快速返回 MissingManifest。 */
	bool IsEmpty() const { return ProductId.IsEmpty() && Scopes.IsEmpty(); }

	/** 恢复为空清单，子系统重置授权状态时用它清除旧的 Pak 与 Scope 映射。 */
	void Reset()
	{
		SchemaVersion = TEXT("1.0");
		ProductId.Empty();
		IssuedAtUnixSeconds = 0;
		Scopes.Reset();
		Signature.Empty();
	}

	/** 按 ScopeId 查找清单范围，外部流程可用它定位某个内容条目的 Pak 声明。 */
	const FAuthorizationManifestScope* FindScope(const FName ScopeId) const
	{
		return Scopes.FindByPredicate([ScopeId](const FAuthorizationManifestScope& Scope)
		{
			return Scope.ScopeId == ScopeId;
		});
	}
};
