// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Provider/AuthorizationServiceFeature.h"

/** 本地文件授权提供器的 ModularFeature 实现，注册后由授权子系统按 LocalFile 名称发现，用文件或内联文本完成离线激活与缓存刷新回放。 */
class GENERICAUTHLOCAL_API FLocalFileAuthorizationServiceFeature : public IAuthorizationServiceFeatureInterface
{
public:
	virtual FName GetProviderName() const override;
	virtual bool IsOnlineService() const override;
	virtual bool SupportsActivation() const override;
	virtual bool SupportsRefresh() const override;
	virtual bool Activate(const FAuthorizationActivationRequest& InRequest, FAuthorizationServiceResponse& OutResponse) override;
	virtual bool Refresh(const FAuthorizationRefreshRequest& InRequest, FAuthorizationServiceResponse& OutResponse) override;

private:
	/** 将激活请求中的授权码解析为 license token 文本；当授权码命中文件路径时返回实际路径，供 Activate 继续读取同目录 Manifest。 */
	static bool ResolveLicenseTokenText(const FString& AuthorizationCode, FString& OutLicenseTokenText, FString& OutResolvedFilePath, FString& OutError);

	/** 在已解析的 license 文件旁查找配置的 Manifest 文件名或默认清单名；缺失时静默失败，让本地 token 激活仍可继续。 */
	static bool TryLoadSiblingManifestText(const FString& ResolvedLicenseFilePath, FString& OutManifestText);
};
