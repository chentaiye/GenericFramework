// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Manifest/AuthorizationManifest.h"
#include "License/AuthorizationLicenseToken.h"

class UAuthorizationSettings;

/** 提供授权数据的规范化、签名和校验入口，子系统通过它判断许可证、Manifest、设备和包体绑定是否可信。 */
class GENERICAUTHORIZATIONCORE_API FAuthorizationVerifier
{
public:
	/** 返回当前 UTC Unix 秒，Grant 过期判断、请求码生成和运行时刷新时间都使用同一时间来源。 */
	static int64 GetCurrentUnixTimestamp();

	/** 解析当前产品标识，优先使用设置值，缺省时回退到项目名以保持签名、缓存和校验口径一致。 */
	static FString ResolveProductId(const UAuthorizationSettings* InSettings = nullptr);

	/** 基于平台设备、登录和机器名生成稳定设备指纹，许可证机器绑定和请求码都会使用该值。 */
	static FString BuildCurrentDeviceId();

	/** 根据可执行文件、构建版本和内容容器文件生成包体指纹，用于构建绑定和缓存隔离。 */
	static FString BuildCurrentPackageFingerprint();

	/** 将内容路径统一为小写正斜杠形式，Manifest 文件匹配和 Pak 挂载校验以此消除路径格式差异。 */
	static FString NormalizeContentPath(const FString& InPath);

	/** 比较两个内容路径是否指向同一声明文件，完整路径不同时也会回退到文件名匹配以兼容打包路径差异。 */
	static bool MatchesContentPath(const FString& LeftPath, const FString& RightPath);

	/** 将许可证 JSON 解析为运行时结构，缓存加载、Provider 响应和用户导入都会通过它进入校验链路。 */
	static bool ParseLicenseToken(const FString& InJsonText, FAuthorizationLicenseToken& OutToken, FString& OutError);

	/** 将许可证结构序列化为 JSON，存储层和本地刷新 Provider 用它写回可持久化文本。 */
	static bool SerializeLicenseToken(const FAuthorizationLicenseToken& InToken, FString& OutJsonText, bool bIncludeSignature, FString& OutError);

	/** 构建稳定排序后的许可证签名载荷，确保 Grant 顺序变化不会影响同一令牌的验签结果。 */
	static FString BuildCanonicalLicenseTokenPayload(const FAuthorizationLicenseToken& InToken);

	/** 使用验证密钥计算许可证签名，生成和校验流程都依赖它保证令牌载荷未被篡改。 */
	static FString SignLicenseToken(const FAuthorizationLicenseToken& InToken, const FString& VerificationKey);

	/** 校验许可证的产品、签名、设备和包体绑定，失败时输出可供 UI 和日志解释的授权状态。 */
	static bool VerifyLicenseToken(const FAuthorizationLicenseToken& InToken, const FString& ExpectedProductId, const FString& CurrentDeviceId, const FString& CurrentPackageFingerprint, const FString& VerificationKey, bool bRequireDeviceBinding, bool bRequirePackageBinding, EAuthorizationState& OutState, FString& OutError);

	/** 将 Manifest JSON 解析为内容清单结构，项目清单、离线清单和 Provider 响应都会经由这里进入运行时。 */
	static bool ParseManifest(const FString& InJsonText, FAuthorizationManifest& OutManifest, FString& OutError);

	/** 将 Manifest 结构序列化为 JSON，存储层用它保存已验证的内容范围和 Pak 映射。 */
	static bool SerializeManifest(const FAuthorizationManifest& InManifest, FString& OutJsonText, bool bIncludeSignature, FString& OutError);

	/** 构建稳定排序后的 Manifest 签名载荷，保护 Scope 与 PakFiles 映射不受顺序变化影响。 */
	static FString BuildCanonicalManifestPayload(const FAuthorizationManifest& InManifest);

	/** 使用验证密钥计算 Manifest 签名，使项目或离线清单中的 Scope/Pak 映射可被校验。 */
	static FString SignManifest(const FAuthorizationManifest& InManifest, const FString& VerificationKey);

	/** 校验 Manifest 的产品标识和可选签名，决定内容清单能否参与 Pak 挂载授权判断。 */
	static bool VerifyManifest(const FAuthorizationManifest& InManifest, const FString& ExpectedProductId, const FString& VerificationKey, bool bRequireSignature, EAuthorizationState& OutState, FString& OutError);
};
