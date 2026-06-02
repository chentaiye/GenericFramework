// Copyright ChenTaiye 2026. All Rights Reserved.

#include "GenericIOTAndroid.h"

#include "Features/IModularFeatures.h"
#include "Interface/IOTPlatformDiscoveryProvider.h"

namespace
{
	/** Android 专用的 Home Assistant 发现提供器，通过 ModularFeatures 接入 UIOTSubsystem::GatherDiscoveryBaseUrls，并只在 Android 目标上提供局域网候选地址。 */
	class FAndroidHomeAssistantDiscoveryProvider final : public IIOTPlatformDiscoveryProviderInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			return TEXT("GenericIOTAndroid");
		}

		virtual bool CanHandleCurrentPlatform() const override
		{
#if PLATFORM_ANDROID
			return true;
#else
			return false;
#endif
		}

		virtual void GatherDiscoveryBaseUrls(TArray<FString>& OutBaseUrls) const override
		{
			OutBaseUrls.AddUnique(TEXT("http://homeassistant.local:8123"));
			OutBaseUrls.AddUnique(TEXT("http://homeassistant:8123"));
		}
	};
}

/** 保存已注册到 ModularFeatures 的 Android 发现提供器实例，确保 StartupModule 注册后的对象生命周期延续到 ShutdownModule 注销。 */
static TUniquePtr<FAndroidHomeAssistantDiscoveryProvider> GIOTAndroidDiscoveryProvider;

void FGenericIOTAndroidModule::StartupModule()
{
	GIOTAndroidDiscoveryProvider = MakeUnique<FAndroidHomeAssistantDiscoveryProvider>();
	IModularFeatures::Get().RegisterModularFeature(IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName(), GIOTAndroidDiscoveryProvider.Get());
}

void FGenericIOTAndroidModule::ShutdownModule()
{
	if (GIOTAndroidDiscoveryProvider)
	{
		IModularFeatures::Get().UnregisterModularFeature(IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName(), GIOTAndroidDiscoveryProvider.Get());
		GIOTAndroidDiscoveryProvider.Reset();
	}
}

IMPLEMENT_MODULE(FGenericIOTAndroidModule, GenericIOTAndroid)
