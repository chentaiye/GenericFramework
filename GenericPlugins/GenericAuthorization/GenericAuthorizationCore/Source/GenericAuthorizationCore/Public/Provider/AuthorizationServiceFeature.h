// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeatures.h"
#include "Manifest/AuthorizationManifest.h"
#include "License/AuthorizationLicenseToken.h"
#include "AuthorizationServiceFeature.generated.h"

/** Provider 激活调用的输入数据，子系统把当前产品、设备和用户提交的授权信息统一打包给实现方。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationActivationRequest
{
	GENERATED_BODY()

public:
	/** 当前产品标识，Provider 生成许可证时需要写入令牌并保持与项目配置一致。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ProductId;

	/** 当前设备指纹，启用机器绑定时 Provider 应将它绑定到返回的许可证。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DeviceId;

	/** 调用方希望激活的目标 Scope，Provider 可据此生成单范围或增量授权。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FName RequestedScopeId=NAME_None;

	/** 用户或授权窗口提交的激活材料，可能是请求码、许可证文件路径或本地 JSON。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString AuthorizationCode;

	/** 外部账号或业务用户标识，在线 Provider 可用它关联授权记录。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString UserId;

	/** 扩展参数表，允许具体 Provider 接收额外业务字段而不改变核心接口。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TMap<FString, FString> Parameters;
};

/** Provider 刷新调用的输入数据，子系统把当前缓存令牌和 Manifest 交给实现方决定是否续期或回放。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationRefreshRequest
{
	GENERATED_BODY()

public:
	/** 当前产品标识，刷新响应必须仍然属于同一产品才能被应用。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ProductId;

	/** 当前设备指纹，刷新后的许可证需要继续匹配机器绑定策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString DeviceId;

	/** 当前已应用的许可证令牌，Provider 可基于它续期、替换或本地回放授权内容。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FAuthorizationLicenseToken CurrentLicenseToken;

	/** 当前已应用的 Manifest，Provider 可在刷新响应中返回新清单或复用旧清单。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FAuthorizationManifest CurrentManifest;

	/** 扩展参数表，保留 Provider 自定义刷新参数而不扩大核心结构。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	TMap<FString, FString> Parameters;
};

/** Provider 返回给子系统的标准响应，激活和刷新流程会解析其中的许可证与 Manifest 文本并应用状态。 */
USTRUCT(BlueprintType)
struct GENERICAUTHORIZATIONCORE_API FAuthorizationServiceResponse
{
	GENERATED_BODY()

public:
	/** Provider 业务是否成功；即使函数返回 true，子系统仍会检查该字段决定是否继续解析响应。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	bool bSuccessful=false;

	/** 面向日志或 UI 的结果说明，失败时会作为 OutMessage 传回调用方。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString Message;

	/** 产生响应的 Provider 名称，便于日志定位并保持激活/刷新结果来源可追踪。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FName ProviderName=NAME_None;

	/** Provider 返回的许可证 JSON 文本，子系统会解析、验签并按来源选择是否持久化。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString LicenseTokenText;

	/** Provider 可选返回的 Manifest JSON 文本，非空时会先校验再替换当前内容清单。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Authorization")
	FString ManifestText;
};

/** 授权 Provider 的 Modular Feature 契约，在线和离线实现通过该接口向子系统提供激活与刷新能力。 */
class GENERICAUTHORIZATIONCORE_API IAuthorizationServiceFeatureInterface : public IModularFeature
{
public:
	/** 返回所有授权 Provider 注册到 ModularFeatures 时使用的统一特性名。 */
	static FName GetFeatureName()
	{
		static const FName FeatureName(TEXT("AuthorizationService"));
		return FeatureName;
	}

	/** 保证通过接口指针释放 Provider 实现时走虚析构，配合模块注销流程安全清理。 */
	virtual ~IAuthorizationServiceFeatureInterface()
	{
	}

	/** 返回 Provider 的稳定名称，配置项和 ResolveProvider 会用它选择具体实现。 */
	virtual FName GetProviderName() const = 0;

	/** 标识 Provider 属于在线还是离线来源，子系统据此检查开关并选择缓存目录。 */
	virtual bool IsOnlineService() const = 0;

	/** 声明 Provider 是否支持激活，默认关闭以避免未实现接口被错误调用。 */
	virtual bool SupportsActivation() const
	{
		return false;
	}

	/** 声明 Provider 是否支持刷新，默认关闭以便子系统只在实现方明确支持时发起刷新。 */
	virtual bool SupportsRefresh() const
	{
		return false;
	}

	/** 执行激活流程并填充许可证或 Manifest 文本；默认实现返回不支持，具体 Provider 需要覆盖。 */
	virtual bool Activate(const FAuthorizationActivationRequest& InRequest, FAuthorizationServiceResponse& OutResponse)
	{
		OutResponse.bSuccessful = false;
		OutResponse.ProviderName = GetProviderName();
		OutResponse.Message = TEXT("Activation is not supported by this provider.");
		return false;
	}

	/** 执行授权刷新流程，允许 Provider 返回新的令牌或复用当前缓存；默认实现返回不支持。 */
	virtual bool Refresh(const FAuthorizationRefreshRequest& InRequest, FAuthorizationServiceResponse& OutResponse)
	{
		OutResponse.bSuccessful = false;
		OutResponse.ProviderName = GetProviderName();
		OutResponse.Message = TEXT("Refresh is not supported by this provider.");
		return false;
	}

	/** 枚举已注册的授权 Provider，子系统自动解析 Provider 时会遍历该列表。 */
	static TArray<IAuthorizationServiceFeatureInterface*> GetAvailableFeatures()
	{
		return IModularFeatures::Get().GetModularFeatureImplementations<IAuthorizationServiceFeatureInterface>(GetFeatureName());
	}

	/** 按 Provider 名称查找已注册实现，显式激活或刷新请求会先走该路径。 */
	static IAuthorizationServiceFeatureInterface* FindFeatureByName(const FName ProviderName)
	{
		if (ProviderName.IsNone()) { return nullptr; }

		for (IAuthorizationServiceFeatureInterface* Feature : GetAvailableFeatures())
		{
			if (Feature != nullptr && Feature->GetProviderName() == ProviderName) { return Feature; }
		}

		return nullptr;
	}
};
