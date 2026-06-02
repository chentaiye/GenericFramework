// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "License/AuthorizationLicenseToken.h"
#include "AuthorizationCodec.generated.h"

/** 授权请求码的明文载荷，Codec 会将它序列化并加密成可复制给授权服务或本地 Provider 的短文本。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationRequestCodePayload
{
	GENERATED_BODY()

public:
	/** 请求载荷结构版本，解析授权请求码时用于区分协议格式。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString SchemaVersion=TEXT("1.0");

	/** 请求授权的产品标识，Provider 生成许可证时应写回同一 ProductId。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ProductId;

	/** 当前设备指纹，启用机器绑定时 Provider 会把它写入许可证令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DeviceId;

	/** 当前构建指纹，启用包体绑定时 Provider 会把它写入许可证令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString PackageFingerprint;

	/** 请求码生成时间，便于服务端或工具判断请求的新旧程度。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	int64 IssuedAtUnixSeconds=0;
};

/** 负责授权文本的传输编码，将请求和许可证 JSON 包装成带前缀的加密文本，并兼容直接输入原始 JSON。 */
class GENERICAUTHORIZATIONCORE_API FAuthorizationCodec
{
public:
	/** 根据当前产品、设备和包体指纹生成授权请求码，授权弹窗会把它交给用户或 Provider 换取许可证。 */
	static FString BuildAuthorizationRequestCode(const FString& ProductId, const FString& DeviceId, const FString& PackageFingerprint, const FString& VerificationKey);

	/** 解密并解析授权请求码，Provider 侧用它还原产品、设备和包体绑定信息。 */
	static bool ParseAuthorizationRequestCode(const FString& RequestCode, const FString& VerificationKey, FAuthorizationRequestCodePayload& OutPayload, FString& OutError);

	/** 将许可证令牌序列化后加密成 GAL1 前缀文本，便于复制传递且不直接暴露 JSON 内容。 */
	static FString BuildLicenseTokenCode(const FAuthorizationLicenseToken& LicenseToken, const FString& VerificationKey);

	/** 接受许可证输入并自动区分加密令牌码或原始 JSON，导入流程用它统一处理用户提交内容。 */
	static bool TryDecodeLicenseTokenInput(const FString& LicenseTokenInput, const FString& VerificationKey, FString& OutLicenseTokenText, FString& OutError);

	/** 通过 GARQ1 前缀识别授权请求码，避免把普通文本误交给解密流程。 */
	static bool IsAuthorizationRequestCode(const FString& InText);

	/** 通过 GAL1 前缀识别加密许可证令牌，导入流程据此决定是否需要先解密。 */
	static bool IsLicenseTokenCode(const FString& InText);
};
