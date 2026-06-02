// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPIWorldSubsystem.h"
#include "NativeAPIProxyComponent.h"
#include "NativeAPITypes.h"
#include "NativeAPILog.h"
#include "Type/DebugType.h"

UNativeAPIWorldSubsystem* UNativeAPIWorldSubsystem::Get(const UObject* WorldContextObject)
{
	if (const UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		return World->GetSubsystem<ThisClass>();
	}
	return nullptr;
}

void UNativeAPIWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UNativeAPIWorldSubsystem::Deinitialize()
{
	Super::Deinitialize();

	NativeAPIProxyCollection.Empty();
}

void UNativeAPIWorldSubsystem::RegisterNativeAPI(UNativeAPIProxyComponent* InProxy)
{
	if (!IsValid(InProxy))
	{
		return;
	}

	const TScriptInterface<INativeAPIEntityInterface> Script(InProxy);
	UClass* Class = Script->GetEntityClass();

	check(Class);

	auto& Values = NativeAPIProxyCollection.FindOrAdd(Class);
	if (!Values.Contains(InProxy))
	{
		Values.Add(InProxy);
	}
}

void UNativeAPIWorldSubsystem::UnRegisterNativeAPI(UNativeAPIProxyComponent* InProxy)
{
	if (!IsValid(InProxy))
	{
		return;
	}

	const TScriptInterface<INativeAPIEntityInterface> Script(InProxy);

	const UClass* Class = Script->GetEntityClass();

	check(Class);

	if (TArray<TObjectPtr<UNativeAPIProxyComponent>>* Values = NativeAPIProxyCollection.Find(Class))
	{
		Values->RemoveSwap(InProxy);
		if (Values->IsEmpty())
		{
			NativeAPIProxyCollection.Remove(Class);
		}
	}
}

void UNativeAPIWorldSubsystem::ProcessingNativeAPI(const FNativeAPIPayload& Payload) const
{
	check(Payload.IsValid())

	if (NativeAPIProxyCollection.IsEmpty())
	{
		return;
	}

	const UWorld* World = GetWorld();
	if (!World->IsInitialized() || !World->HasBegunPlay())
	{
		return;
	}

	TArray<UClass*> Classes;
	NativeAPIProxyCollection.GenerateKeyArray(Classes);

	UClass** Class = Classes.FindByPredicate([Payload](const UClass* Other)
		{
			return Other->GetClassPathName() == Payload.GetClassPath().GetAssetPath();
		}
	);

	if (Class != nullptr)
	{
		if (const TArray<TObjectPtr<UNativeAPIProxyComponent>>* Values = NativeAPIProxyCollection.Find(*Class))
		{
			for (const TObjectPtr<UNativeAPIProxyComponent>& Proxy : *Values)
			{
				if (!IsValid(Proxy))
				{
					continue;
				}

				const TScriptInterface<INativeAPIEntityInterface> Script(Proxy);
				if (Script != nullptr)
				{
					Script->ProcessingNativeAPI(Payload);
				}
			}
		}
	}
	else
	{
		GenericLOG(LogNativeAPI, Log, TEXT("World NativeAPI 没有被处理, 当前没有这个类型的注册对象. %s"), *Payload.GetClassPath().ToString())
	}
}
