// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPISubsystem.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Features/IModularFeatures.h"
#include "INativeAPISessionFeature.h"
#include "NativeAPILog.h"
#include "NativeAPIProxyComponent.h"
#include "NativeAPITypes.h"
#include "NativeAPIWorldSubsystem.h"
#include "Settings/NativeAPIWorldSettings.h"
#include "Type/DebugType.h"

void UNativeAPISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	IModularFeatures::Get().OnModularFeatureRegistered().AddUObject(this, &UNativeAPISubsystem::HandleOnNativeAPISessionFeatureRegistered);
	IModularFeatures::Get().OnModularFeatureUnregistered().AddUObject(this, &UNativeAPISubsystem::HandleOnNativeAPISessionFeatureUnRegistered);
}

void UNativeAPISubsystem::Deinitialize()
{
	EndAllFeatureSession();
	ActiveWorldSettingsStack.Reset();

	IModularFeatures::Get().OnModularFeatureRegistered().RemoveAll(this);
	IModularFeatures::Get().OnModularFeatureUnregistered().RemoveAll(this);

	Super::Deinitialize();
}

void UNativeAPISubsystem::SendSimulationNativeAPI(const FString& NativeAPIJson)
{
	SendSimulationNativeAPIMessage(NativeAPIJson);
}

void UNativeAPISubsystem::ProcessingNativeAPI(const FNativeAPIPayload& Payload) const
{
	check(Payload.IsValid());
	const UClass* EntityClass = Payload.GetClassPath().ResolveClass();

	if (!EntityClass)
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Type [%s] could not be found in memory."), *Payload.GetClassPath().ToString());
		return;
	}

	const FSoftObjectPath WorldPath = Payload.GetWorldPath();

	UWorld* TargetWorld = nullptr;
	if (WorldPath.IsValid())
	{
		TargetWorld = Cast<UWorld>(WorldPath.ResolveObject());
	}

	bool bResolved = false;

	if (Payload.IsValidEntityPath())
	{
		if (TargetWorld == nullptr)
		{
			GenericLOG(LogNativeAPI, Error, TEXT("Native API cannot be directed to the world %s"), *Payload.GetWorldPath().ToString());
			return;
		}

		const FSoftObjectPath EntityPath = Payload.GetEntityPath();
		check(EntityPath.IsSubobject());

		UObject* FoundObject = nullptr;
		if (TargetWorld->ResolveSubobject(*EntityPath.GetSubPathString(), FoundObject, false))
		{
			if (!FoundObject->Implements<UNativeAPIEntityInterface>())
			{
				GenericLOG(LogNativeAPI, Error, TEXT("Native API object must implement INativeAPIEntityInterface. %s"), *EntityPath.ToString());
				return;
			}

			const TScriptInterface<INativeAPIEntityInterface> Script(FoundObject);
			check(Script != nullptr);
			check(Script->GetEntityClass() == EntityClass);
			Script->ProcessingNativeAPI(Payload);

			bResolved = true;
		}
		else
		{
			GenericLOG(LogNativeAPI, Warning, TEXT("Native API could not resolve entity object: %s"), *EntityPath.ToString());
		}
	}

	if (!bResolved)
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Native API could not resolve EntityPath: %s"), *Payload.GetEntityPath().ToString());
		GenericLOG(LogNativeAPI, Warning, TEXT("Native API could not resolve WorldPath: %s"), *Payload.GetWorldPath().ToString());
		GenericLOG(LogNativeAPI, Warning, TEXT("Native API could not resolve ClassPath: %s"), *Payload.GetClassPath().ToString());
		GenericLOG(LogNativeAPI, Warning, TEXT("Native API could not resolve Entity: %s"), *Payload.GetEntity().ToString());

		auto NativeAPIToWorld = [&Payload](const UWorld* World)
		{
			const UNativeAPIWorldSubsystem* NativeAPIWorldSubsystem = UNativeAPIWorldSubsystem::Get(World);

			if (NativeAPIWorldSubsystem != nullptr)
			{
				NativeAPIWorldSubsystem->ProcessingNativeAPI(Payload);
			}
			else
			{
				GenericLOG(LogNativeAPI, Error, TEXT("Native API cannot broadcast to world %s because subsystem is invalid."), *World->GetName());
			}
		};

		const UEngine* Engine = CastChecked<UEngine>(GetOuter());

		for (const FWorldContext& WorldContext : Engine->GetWorldContexts())
		{
			if (WorldContext.WorldType == EWorldType::Game || WorldContext.WorldType == EWorldType::PIE)
			{
				NativeAPIToWorld(WorldContext.World());
			}
		}
	}
}

void UNativeAPISubsystem::HandleOnNativeAPISessionFeatureRegistered(const FName& FeatureName, IModularFeature* Feature)
{
	if (FeatureName != INativeAPISessionFeatureInterface::GetFeatureName() || GetActiveWorldSettings() == nullptr)
	{
		return;
	}

	INativeAPISessionFeatureInterface* Session = static_cast<INativeAPISessionFeatureInterface*>(Feature);
	if (Session != nullptr && Session->StartSession())
	{
		Session->SetReceiveSessionPayloadBinding(FOnReceiveNativePayload::CreateUObject(this, &UNativeAPISubsystem::HandleOnReceiveNativePayload));
	}
}

void UNativeAPISubsystem::HandleOnNativeAPISessionFeatureUnRegistered(const FName& FeatureName, IModularFeature* Feature)
{
	if (FeatureName != INativeAPISessionFeatureInterface::GetFeatureName())
	{
		return;
	}

	INativeAPISessionFeatureInterface* Session = static_cast<INativeAPISessionFeatureInterface*>(Feature);
	if (Session != nullptr)
	{
		Session->SetReceiveSessionPayloadBinding(FOnReceiveNativePayload());
		Session->EndSession();
	}
}

void UNativeAPISubsystem::StartAllFeatureSession()
{
	if (GetActiveWorldSettings() == nullptr)
	{
		return;
	}

	TArray<INativeAPISessionFeatureInterface*> NativeAPISessionFeatures = IModularFeatures::Get().GetModularFeatureImplementations<INativeAPISessionFeatureInterface>(INativeAPISessionFeatureInterface::GetFeatureName());
	for (INativeAPISessionFeatureInterface* NativeAPISessionFeature : NativeAPISessionFeatures)
	{
		if (NativeAPISessionFeature == nullptr)
		{
			continue;
		}

		if (NativeAPISessionFeature->StartSession())
		{
			NativeAPISessionFeature->SetReceiveSessionPayloadBinding(FOnReceiveNativePayload::CreateUObject(this, &UNativeAPISubsystem::HandleOnReceiveNativePayload));
		}
	}
}

void UNativeAPISubsystem::EndAllFeatureSession()
{
	TArray<INativeAPISessionFeatureInterface*> NativeAPISessionFeatures = IModularFeatures::Get().GetModularFeatureImplementations<INativeAPISessionFeatureInterface>(INativeAPISessionFeatureInterface::GetFeatureName());

	for (INativeAPISessionFeatureInterface* NativeAPISessionFeature : NativeAPISessionFeatures)
	{
		if (NativeAPISessionFeature == nullptr)
		{
			continue;
		}

		NativeAPISessionFeature->SetReceiveSessionPayloadBinding(FOnReceiveNativePayload());
		NativeAPISessionFeature->EndSession();
	}
}

void UNativeAPISubsystem::ActivateWorldSettings(UNativeAPIWorldSettings* InWorldSettings)
{
	if (InWorldSettings == nullptr)
	{
		return;
	}

	const UNativeAPIWorldSettings* PreviousActiveWorldSettings = GetActiveWorldSettings();
	ActiveWorldSettingsStack.RemoveAll([InWorldSettings](const TWeakObjectPtr<UNativeAPIWorldSettings>& WorldSettings)
	{
		return !WorldSettings.IsValid() || WorldSettings.Get() == InWorldSettings;
	});
	ActiveWorldSettingsStack.Add(InWorldSettings);

	if (PreviousActiveWorldSettings != InWorldSettings)
	{
		EndAllFeatureSession();
		StartAllFeatureSession();
	}
}

void UNativeAPISubsystem::DeactivateWorldSettings(UNativeAPIWorldSettings* InWorldSettings)
{
	if (InWorldSettings == nullptr)
	{
		return;
	}

	const UNativeAPIWorldSettings* PreviousActiveWorldSettings = GetActiveWorldSettings();
	const int32 RemovedCount = ActiveWorldSettingsStack.RemoveAll([InWorldSettings](const TWeakObjectPtr<UNativeAPIWorldSettings>& WorldSettings)
	{
		return !WorldSettings.IsValid() || WorldSettings.Get() == InWorldSettings;
	});

	if (RemovedCount <= 0)
	{
		return;
	}

	const UNativeAPIWorldSettings* CurrentActiveWorldSettings = GetActiveWorldSettings();
	if (PreviousActiveWorldSettings != CurrentActiveWorldSettings)
	{
		EndAllFeatureSession();
		StartAllFeatureSession();
	}
}

const UNativeAPIWorldSettings* UNativeAPISubsystem::GetActiveWorldSettings() const
{
	for (int32 Index = ActiveWorldSettingsStack.Num() - 1; Index >= 0; --Index)
	{
		if (ActiveWorldSettingsStack[Index].IsValid())
		{
			return ActiveWorldSettingsStack[Index].Get();
		}
	}

	return nullptr;
}

void UNativeAPISubsystem::HandleOnReceiveNativePayload(const FNativeAPIPayload& InPayload)
{
	if (!InPayload.IsValid())
	{
		return;
	}

	FNativeAPIPayload TempPayload = InPayload;
	TArray<FNativeAPIPayload> ExecutePayloads;
#if WITH_EDITOR
	for (const FWorldContext& WorldContext : GEngine->GetWorldContexts())
	{
		if (WorldContext.WorldType == EWorldType::PIE)
		{
			TempPayload.FixupFromPIE(WorldContext.PIEInstance);
			ExecutePayloads.Add(TempPayload);
		}
	}
#else
	ExecutePayloads.Add(InPayload);
#endif

	for (const FNativeAPIPayload& Payload : ExecutePayloads)
	{
		ProcessingNativeAPI(Payload);
	}
}
