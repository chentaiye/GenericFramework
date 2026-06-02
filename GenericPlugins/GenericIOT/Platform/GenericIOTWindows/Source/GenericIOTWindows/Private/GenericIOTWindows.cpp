// Copyright ChenTaiye 2026. All Rights Reserved.

#include "GenericIOTWindows.h"

#include "Features/IModularFeatures.h"
#include "Interface/IOTPlatformDiscoveryProvider.h"

namespace
{
	/** Windows平台发现提供器，向IOT子系统提供本机可直接探测的Home Assistant默认地址，并通过平台判断避免被其他平台采纳。 */
	class FWindowsHomeAssistantDiscoveryProvider final : public IIOTPlatformDiscoveryProviderInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			return TEXT("GenericIOTWindows");
		}

		virtual bool CanHandleCurrentPlatform() const override
		{
#if PLATFORM_WINDOWS
			return true;
#else
			return false;
#endif
		}

		virtual void GatherDiscoveryBaseUrls(TArray<FString>& OutBaseUrls) const override
		{
			OutBaseUrls.AddUnique(TEXT("http://homeassistant.local:8123"));
			OutBaseUrls.AddUnique(TEXT("http://homeassistant:8123"));
			OutBaseUrls.AddUnique(TEXT("http://127.0.0.1:8123"));
		}
	};
}

/** 保存模块生命周期内注册到ModularFeatures的发现提供器实例，确保ShutdownModule使用同一指针撤销注册并释放资源。 */
static TUniquePtr<FWindowsHomeAssistantDiscoveryProvider> GIOTWindowsDiscoveryProvider;

void FGenericIOTWindowsModule::StartupModule()
{
	GIOTWindowsDiscoveryProvider = MakeUnique<FWindowsHomeAssistantDiscoveryProvider>();
	IModularFeatures::Get().RegisterModularFeature(IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName(), GIOTWindowsDiscoveryProvider.Get());
}

void FGenericIOTWindowsModule::ShutdownModule()
{
	if (GIOTWindowsDiscoveryProvider)
	{
		IModularFeatures::Get().UnregisterModularFeature(IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName(), GIOTWindowsDiscoveryProvider.Get());
		GIOTWindowsDiscoveryProvider.Reset();
	}
}

IMPLEMENT_MODULE(FGenericIOTWindowsModule, GenericIOTWindows)
