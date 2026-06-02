// Copyright ChenTaiye 2026. All Rights Reserved.

#include "IOTPlatformHomeAssistant.h"

#include "Features/IModularFeatures.h"
#include "HomeAssistantPlatformAdapter.h"
#include "Interface/IOTPlatformAdapter.h"

DEFINE_LOG_CATEGORY(GenericLogIOTHomeAssistant);

namespace
{
	class FHomeAssistantPlatformAdapterFactory final : public IIOTPlatformAdapterFactoryInterface
	{
	public:
		virtual EIOTPlatformKind GetPlatformKind() const override
		{
			return EIOTPlatformKind::HomeAssistant;
		}

		virtual UObject* CreateAdapter(UObject* Outer) override
		{
			return NewObject<UHomeAssistantPlatformAdapter>(Outer);
		}
	};
}

static TUniquePtr<FHomeAssistantPlatformAdapterFactory> GIOTHomeAssistantFactory;

void FIOTPlatformHomeAssistantModule::StartupModule()
{
	GIOTHomeAssistantFactory = MakeUnique<FHomeAssistantPlatformAdapterFactory>();
	IModularFeatures::Get().RegisterModularFeature(IIOTPlatformAdapterFactoryInterface::GetModularFeatureName(), GIOTHomeAssistantFactory.Get());
}

void FIOTPlatformHomeAssistantModule::ShutdownModule()
{
	if (GIOTHomeAssistantFactory)
	{
		IModularFeatures::Get().UnregisterModularFeature(IIOTPlatformAdapterFactoryInterface::GetModularFeatureName(), GIOTHomeAssistantFactory.Get());
		GIOTHomeAssistantFactory.Reset();
	}
}

IMPLEMENT_MODULE(FIOTPlatformHomeAssistantModule, IOTPlatformHomeAssistant)
