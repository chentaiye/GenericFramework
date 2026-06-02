// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/IOTSubsystem.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Interface/IOTPlatformAdapter.h"
#include "Interface/IOTPlatformDiscoveryProvider.h"
#include "Settings/IOTSettings.h"
#include "GenericIOTFramework.h"
#include "Engine/GameInstance.h"
#include "Modules/ModuleManager.h"
#include "Features/IModularFeatures.h"

UIOTSubsystem* UIOTSubsystem::Get(const UObject* WorldContextObject)
{
	if (!IsValid(WorldContextObject))
	{
		return nullptr;
	}

	if (const UWorld* World = WorldContextObject->GetWorld())
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UIOTSubsystem>();
		}
	}

	if (const UGameInstance* GameInstance = Cast<UGameInstance>(WorldContextObject))
	{
		return GameInstance->GetSubsystem<UIOTSubsystem>();
	}

	return nullptr;
}

void UIOTSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LoadSettingsConfig();

	if (UIOTSettings* Settings = UIOTSettings::Get(); Settings && Settings->bAutoConnectOnInitialize)
	{
		ConnectHomeAssistant();
	}
}

void UIOTSubsystem::Deinitialize()
{
	bDiscoveryInProgress = false;
	DiscoveryCandidates.Reset();
	DiscoveryRequest.Reset();

	DisconnectPlatform();

	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->ShutdownAdapter();
	}
	PlatformAdapterObject = nullptr;

	DevicesById.Reset();
	DeviceStatesById.Reset();
	DeviceIdByEntityId.Reset();

	Super::Deinitialize();
}

void UIOTSubsystem::SetEndpointConfig(const FIOTPlatformEndpointConfig& InConfig)
{
	EndpointConfig = InConfig;
	EndpointConfig.BaseUrl = NormalizeBaseUrl(InConfig.BaseUrl);
	PersistEndpointConfig();

	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->ApplyEndpointConfig(EndpointConfig);
	}
}

FIOTPlatformEndpointConfig UIOTSubsystem::GetEndpointConfig() const
{
	return EndpointConfig;
}

bool UIOTSubsystem::ConnectHomeAssistant()
{
	if (!EnsureHomeAssistantAdapter())
	{
		NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("未找到 Home Assistant 平台适配器"));
		return false;
	}

	if (!EndpointConfig.HasBaseUrl() && EndpointConfig.bAutoDiscover)
	{
		BeginAutoDiscovery();
		return true;
	}

	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->ApplyEndpointConfig(EndpointConfig);
		Adapter->Connect();
		return true;
	}

	return false;
}

bool UIOTSubsystem::DisconnectPlatform()
{
	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->Disconnect();
	}

	NotifyRealtimeStateChanged(false);
	NotifyConnectionStateChanged(EIOTConnectionState::Disconnected);
	return true;
}

bool UIOTSubsystem::RefreshDevices()
{
	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->RefreshDevices();
		return true;
	}

	NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("无法刷新设备，平台适配器未准备好"));
	return false;
}

bool UIOTSubsystem::SubscribeRealtime()
{
	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		NotifyConnectionStateChanged(EIOTConnectionState::Subscribing);
		Adapter->SubscribeRealtime();
		return true;
	}

	NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("无法启动实时订阅，平台适配器未准备好"));
	return false;
}

TArray<FIOTDeviceDescriptor> UIOTSubsystem::GetAllDevices() const
{
	TArray<FIOTDeviceDescriptor> Result;
	DevicesById.GenerateValueArray(Result);
	return Result;
}

bool UIOTSubsystem::TryGetDeviceById(const FString& DeviceId, FIOTDeviceDescriptor& OutDevice) const
{
	if (const FIOTDeviceDescriptor* Found = DevicesById.Find(DeviceId))
	{
		OutDevice = *Found;
		return true;
	}

	return false;
}

bool UIOTSubsystem::TryGetDeviceByEntityId(const FString& EntityId, FIOTDeviceDescriptor& OutDevice) const
{
	if (const FString* DeviceId = DeviceIdByEntityId.Find(EntityId))
	{
		return TryGetDeviceById(*DeviceId, OutDevice);
	}

	return false;
}

bool UIOTSubsystem::TryGetDeviceState(const FString& DeviceId, FIOTDeviceState& OutState) const
{
	if (const FIOTDeviceState* Found = DeviceStatesById.Find(DeviceId))
	{
		OutState = *Found;
		return true;
	}

	return false;
}

FString UIOTSubsystem::ExecuteCommand(FIOTCommandRequest InRequest)
{
	if (!EnsureHomeAssistantAdapter())
	{
		NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("无法执行命令，平台适配器未准备好"));
		return FString();
	}

	InRequest.DeviceId = InRequest.DeviceId.TrimStartAndEnd();
	if (InRequest.DeviceId.IsEmpty())
	{
		return FString();
	}

	if (InRequest.RequestId.IsEmpty())
	{
		InRequest.RequestId = FString::Printf(TEXT("iot-%llu"), ++RequestCounter);
	}

	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->ExecuteCommand(InRequest);
		return InRequest.RequestId;
	}

	return FString();
}

FString UIOTSubsystem::ExecuteRawService(const FString& DeviceId, const FName Domain, const FName Service, const TMap<FString, FString>& Params)
{
	if (!EnsureHomeAssistantAdapter())
	{
		NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("无法执行原生服务，平台适配器未准备好"));
		return FString();
	}

	const FString RequestId = FString::Printf(TEXT("iot-%llu"), ++RequestCounter);
	if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
	{
		Adapter->ExecuteRawService(RequestId, DeviceId, Domain, Service, Params);
		return RequestId;
	}

	return FString();
}

bool UIOTSubsystem::TryResolveEntityIdForDevice(const FString& DeviceId, FString& OutEntityId) const
{
	if (const FIOTDeviceDescriptor* Found = DevicesById.Find(DeviceId))
	{
		OutEntityId = Found->EntityId;
		return true;
	}

	return false;
}

FString UIOTSubsystem::MakeDeviceIdFromEntityId(const FString& EntityId) const
{
	return FString::Printf(TEXT("ha:%s"), *EntityId);
}

void UIOTSubsystem::NotifyConnectionStateChanged(const EIOTConnectionState InState, const FString& InErrorMessage)
{
	const EIOTConnectionState PreviousState = ConnectionState;
	ConnectionState = InState;

	if (!InErrorMessage.IsEmpty())
	{
		LastErrorMessage = InErrorMessage;
		UE_LOG(GenericLogIOT, Warning, TEXT("%s"), *InErrorMessage);
	}
	else if (InState != EIOTConnectionState::Error)
	{
		LastErrorMessage.Reset();
	}

	OnConnectionStateChanged.Broadcast(ConnectionState);

	if (PreviousState != EIOTConnectionState::Connected && InState == EIOTConnectionState::Connected)
	{
		if (UIOTSettings* Settings = UIOTSettings::Get())
		{
			if (Settings->bAutoRefreshDevicesOnConnect)
			{
				RefreshDevices();
			}

			if (Settings->bAutoSubscribeRealtimeOnConnect)
			{
				SubscribeRealtime();
			}
		}
	}
}

void UIOTSubsystem::ReplaceDeviceSnapshot(const TArray<FIOTDeviceDescriptor>& InDevices, const TArray<FIOTDeviceState>& InStates)
{
	DevicesById.Reset();
	DeviceStatesById.Reset();
	DeviceIdByEntityId.Reset();

	for (const FIOTDeviceDescriptor& Device : InDevices)
	{
		DevicesById.Add(Device.DeviceId, Device);
		DeviceIdByEntityId.Add(Device.EntityId, Device.DeviceId);
	}

	for (const FIOTDeviceState& State : InStates)
	{
		if (const FString* DeviceId = State.CapabilityValues.Find(TEXT("__device_id")))
		{
			FIOTDeviceState SanitizedState = State;
			SanitizedState.CapabilityValues.Remove(TEXT("__device_id"));
			DeviceStatesById.Add(*DeviceId, SanitizedState);
		}
	}

	for (const FIOTDeviceDescriptor& Device : InDevices)
	{
		const FIOTDeviceState State = DeviceStatesById.FindRef(Device.DeviceId);
		OnDeviceStateChanged.Broadcast(Device, State);
	}

	OnDevicesRefreshed.Broadcast(DevicesById.Num());
}

void UIOTSubsystem::UpdateDeviceState(const FIOTDeviceDescriptor& InDevice, const FIOTDeviceState& InState)
{
	DevicesById.Add(InDevice.DeviceId, InDevice);
	DeviceIdByEntityId.Add(InDevice.EntityId, InDevice.DeviceId);
	DeviceStatesById.Add(InDevice.DeviceId, InState);
	OnDeviceStateChanged.Broadcast(InDevice, InState);
}

void UIOTSubsystem::CompleteCommand(const FIOTCommandRequest& InRequest, const FIOTCommandResult& InResult)
{
	OnCommandCompleted.Broadcast(InRequest, InResult);
}

void UIOTSubsystem::NotifyRealtimeStateChanged(const bool bInRealtimeActive, const FString& InErrorMessage)
{
	bRealtimeActive = bInRealtimeActive;

	if (!InErrorMessage.IsEmpty())
	{
		LastErrorMessage = InErrorMessage;
	}

	OnRealtimeStateChanged.Broadcast(bRealtimeActive);
}

void UIOTSubsystem::LoadSettingsConfig()
{
	if (UIOTSettings* Settings = UIOTSettings::Get())
	{
		EndpointConfig = Settings->HomeAssistantEndpoint;
		EndpointConfig.BaseUrl = NormalizeBaseUrl(EndpointConfig.BaseUrl);
		EndpointConfig.bAutoDiscover = Settings->bEnableAutoDiscovery;
	}
}

void UIOTSubsystem::PersistEndpointConfig() const
{
	if (UIOTSettings* Settings = UIOTSettings::Get())
	{
		Settings->HomeAssistantEndpoint = EndpointConfig;
		Settings->SaveConfig();
	}
}

bool UIOTSubsystem::EnsureHomeAssistantAdapter()
{
	if (PlatformAdapterObject)
	{
		return GetPlatformAdapter() != nullptr;
	}

	if (!FModuleManager::Get().IsModuleLoaded(TEXT("IOTPlatformHomeAssistant")))
	{
		FModuleManager::Get().LoadModule(TEXT("IOTPlatformHomeAssistant"));
	}

	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	const TArray<IIOTPlatformAdapterFactoryInterface*> Factories = ModularFeatures.GetModularFeatureImplementations<IIOTPlatformAdapterFactoryInterface>(IIOTPlatformAdapterFactoryInterface::GetModularFeatureName());
	for (IIOTPlatformAdapterFactoryInterface* Factory : Factories)
	{
		if (Factory && Factory->GetPlatformKind() == EIOTPlatformKind::HomeAssistant)
		{
			if (UObject* AdapterObject = Factory->CreateAdapter(this))
			{
				PlatformAdapterObject = AdapterObject;
				if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
				{
					Adapter->InitializeAdapter(this);
					Adapter->ApplyEndpointConfig(EndpointConfig);
					return true;
				}
			}
		}
	}

	return false;
}

IIOTPlatformAdapterInterface* UIOTSubsystem::GetPlatformAdapter() const
{
	return PlatformAdapterObject ? Cast<IIOTPlatformAdapterInterface>(PlatformAdapterObject) : nullptr;
}

void UIOTSubsystem::BeginAutoDiscovery()
{
	if (bDiscoveryInProgress)
	{
		return;
	}

	GatherDiscoveryBaseUrls(DiscoveryCandidates);
	if (DiscoveryCandidates.Num() == 0)
	{
		NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("未找到可用于自动发现的 Home Assistant 地址"));
		return;
	}

	bDiscoveryInProgress = true;
	DiscoveryCandidateIndex = INDEX_NONE;
	NotifyConnectionStateChanged(EIOTConnectionState::Discovering);
	ProbeNextDiscoveryCandidate();
}

void UIOTSubsystem::ProbeNextDiscoveryCandidate()
{
	DiscoveryRequest.Reset();
	++DiscoveryCandidateIndex;

	if (!DiscoveryCandidates.IsValidIndex(DiscoveryCandidateIndex))
	{
		bDiscoveryInProgress = false;
		NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("自动发现 Home Assistant 失败，请手动填写 Base URL"));
		return;
	}

	const FString CandidateBaseUrl = NormalizeBaseUrl(DiscoveryCandidates[DiscoveryCandidateIndex]);
	const FString ProbeUrl = FString::Printf(TEXT("%s/api/"), *CandidateBaseUrl);

	TWeakObjectPtr<UIOTSubsystem> WeakThis(this);
	DiscoveryRequest = FHttpModule::Get().CreateRequest();
	DiscoveryRequest->SetURL(ProbeUrl);
	DiscoveryRequest->SetVerb(TEXT("GET"));
	DiscoveryRequest->SetHeader(TEXT("Accept"), TEXT("application/json"));
	DiscoveryRequest->SetTimeout(EndpointConfig.RequestTimeoutSeconds);
	DiscoveryRequest->OnProcessRequestComplete().BindLambda([WeakThis](FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectedSuccessfully)
	{
		if (WeakThis.IsValid())
		{
			WeakThis->HandleDiscoveryProbeComplete(InRequest, InResponse, bConnectedSuccessfully);
		}
	});
	DiscoveryRequest->ProcessRequest();
}

void UIOTSubsystem::HandleDiscoveryProbeComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, const bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully && IsCandidateResponseLikelyHomeAssistant(InResponse))
	{
		bDiscoveryInProgress = false;
		EndpointConfig.BaseUrl = NormalizeBaseUrl(DiscoveryCandidates[DiscoveryCandidateIndex]);
		PersistEndpointConfig();

		if (IIOTPlatformAdapterInterface* Adapter = GetPlatformAdapter())
		{
			Adapter->ApplyEndpointConfig(EndpointConfig);
			Adapter->Connect();
			return;
		}
	}

	ProbeNextDiscoveryCandidate();
}

void UIOTSubsystem::GatherDiscoveryBaseUrls(TArray<FString>& OutBaseUrls) const
{
	OutBaseUrls.Reset();

	if (const UIOTSettings* Settings = UIOTSettings::Get())
	{
		for (const FString& Url : Settings->DiscoveryBaseUrls)
		{
			const FString Normalized = NormalizeBaseUrl(Url);
			if (!Normalized.IsEmpty())
			{
				OutBaseUrls.AddUnique(Normalized);
			}
		}
	}

	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	const TArray<IIOTPlatformDiscoveryProviderInterface*> Providers = ModularFeatures.GetModularFeatureImplementations<IIOTPlatformDiscoveryProviderInterface>(IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName());
	for (IIOTPlatformDiscoveryProviderInterface* Provider : Providers)
	{
		if (Provider && Provider->CanHandleCurrentPlatform())
		{
			TArray<FString> ProviderUrls;
			Provider->GatherDiscoveryBaseUrls(ProviderUrls);
			for (const FString& Url : ProviderUrls)
			{
				const FString Normalized = NormalizeBaseUrl(Url);
				if (!Normalized.IsEmpty())
				{
					OutBaseUrls.AddUnique(Normalized);
				}
			}
		}
	}
}

FString UIOTSubsystem::NormalizeBaseUrl(const FString& InBaseUrl) const
{
	FString Result = InBaseUrl.TrimStartAndEnd();
	while (Result.EndsWith(TEXT("/")))
	{
		Result.LeftChopInline(1);
	}
	return Result;
}

bool UIOTSubsystem::IsCandidateResponseLikelyHomeAssistant(const FHttpResponsePtr& InResponse) const
{
	if (!InResponse.IsValid())
	{
		return false;
	}

	const FString Content = InResponse->GetContentAsString();
	return Content.Contains(TEXT("API running")) || Content.Contains(TEXT("Home Assistant")) || InResponse->GetResponseCode() == 401;
}
