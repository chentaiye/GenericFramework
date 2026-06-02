#include "Model/GenericPropertySubsystem.h"

#include "Core/GenericPropertyCollection.h"
#include "Data/GenericPropertyAutoDataSourceCollection.h"
#include "Model/GenericPropertyProxy.h"
#include "Model/GenericPropertyVisualData.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UnrealType.h"

void UGenericPropertySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VisualData = NewObject<UGenericPropertyVisualData>(this);
	AutoRefreshTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericPropertySubsystem::TickAutoRefresh));
#if WITH_EDITOR
	PropertyChangedDelegateHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(this, &UGenericPropertySubsystem::HandleObjectPropertyChanged);
#endif
}

void UGenericPropertySubsystem::Deinitialize()
{
	if (AutoRefreshTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(AutoRefreshTickerHandle);
		AutoRefreshTickerHandle.Reset();
	}

	if (PropertyChangedDelegateHandle.IsValid())
	{
#if WITH_EDITOR
		FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(PropertyChangedDelegateHandle);
#endif
		PropertyChangedDelegateHandle.Reset();
	}

	ActiveCollections.Reset();
	VisualData = nullptr;
	Super::Deinitialize();
}

UGenericPropertyCollection* UGenericPropertySubsystem::CreatePropertyCollectionForObject(UObject* InTarget, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass)
{
	TArray<UObject*> Targets;
	if (InTarget != nullptr)
	{
		Targets.Add(InTarget);
	}

	return CreatePropertyCollectionForObjects(Targets, InOptions, InDataSourceClass);
}

UGenericPropertyCollection* UGenericPropertySubsystem::CreatePropertyCollectionForObjects(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass)
{
	if (InTargets.IsEmpty())
	{
		return nullptr;
	}

	if (InDataSourceClass == nullptr)
	{
		InDataSourceClass = UGenericPropertyAutoDataSourceCollection::StaticClass();
	}

	UGenericPropertyProxy* Proxy = NewObject<UGenericPropertyProxy>(this);
	Proxy->Initialize(InTargets, InOptions, InDataSourceClass);

	UGenericPropertyCollection* Collection = Proxy->CreateCollection();
	ActiveCollections.Add(Collection);
	return Collection;
}

void UGenericPropertySubsystem::DestroyPropertyCollection(UGenericPropertyCollection* InCollection)
{
	ActiveCollections.Remove(InCollection);
}

void UGenericPropertySubsystem::RefreshCollectionsForObject(UObject* InTarget)
{
	for (UGenericPropertyCollection* Collection : ActiveCollections)
	{
		if (Collection == nullptr || Collection->Proxy == nullptr)
		{
			continue;
		}

		if (Collection->Proxy->TracksTargetObject(InTarget))
		{
			Collection->Refresh();
		}
	}
}

void UGenericPropertySubsystem::NotifyObjectPropertyChanged(UObject* InTarget, const FName InMemberPropertyName)
{
	for (int32 Index = ActiveCollections.Num() - 1; Index >= 0; --Index)
	{
		UGenericPropertyCollection* Collection = ActiveCollections[Index];
		if (Collection == nullptr || Collection->Proxy == nullptr)
		{
			ActiveCollections.RemoveAtSwap(Index);
			continue;
		}

		Collection->Proxy->NotifyObjectPropertyChanged(InTarget, InMemberPropertyName, InMemberPropertyName, false);
	}
}

void UGenericPropertySubsystem::NotifyObjectPropertyPathChanged(UObject* InTarget, const FString& InPropertyPath, const bool bStructuralChange)
{
	for (int32 Index = ActiveCollections.Num() - 1; Index >= 0; --Index)
	{
		UGenericPropertyCollection* Collection = ActiveCollections[Index];
		if (Collection == nullptr || Collection->Proxy == nullptr)
		{
			ActiveCollections.RemoveAtSwap(Index);
			continue;
		}

		Collection->Proxy->NotifyPropertyPathChanged(InTarget, InPropertyPath, bStructuralChange);
	}
}

bool UGenericPropertySubsystem::TickAutoRefresh(const float InDeltaTime)
{
	const double CurrentTimeSeconds = FPlatformTime::Seconds();

	for (int32 Index = ActiveCollections.Num() - 1; Index >= 0; --Index)
	{
		UGenericPropertyCollection* Collection = ActiveCollections[Index];
		if (Collection == nullptr || Collection->Proxy == nullptr)
		{
			ActiveCollections.RemoveAtSwap(Index);
			continue;
		}

		if (Collection->Proxy->HasPendingPropertyChanges())
		{
			const EGenericPropertySyncMode SyncMode = Collection->Proxy->GetOptions().SyncMode;
			if (SyncMode == EGenericPropertySyncMode::Immediate)
			{
				Collection->Proxy->FlushPendingPropertyChanges();
				continue;
			}

			if (SyncMode == EGenericPropertySyncMode::Deferred && Collection->Proxy->ShouldAutoRefresh(CurrentTimeSeconds))
			{
				Collection->Proxy->FlushPendingPropertyChanges();
				continue;
			}
		}

		if (Collection->Proxy->ShouldAutoRefresh(CurrentTimeSeconds))
		{
			Collection->Refresh();
		}
	}

	return true;
}

void UGenericPropertySubsystem::HandleObjectPropertyChanged(UObject* InObject, FPropertyChangedEvent& InPropertyChangedEvent)
{
	const EPropertyChangeType::Type ChangeType = InPropertyChangedEvent.ChangeType;
	const bool bStructuralChange = (ChangeType & (EPropertyChangeType::ArrayAdd | EPropertyChangeType::ArrayRemove | EPropertyChangeType::ArrayClear | EPropertyChangeType::Duplicate)) != 0;
	const FName MemberPropertyName = InPropertyChangedEvent.GetMemberPropertyName();
	const FName LeafPropertyName = InPropertyChangedEvent.GetPropertyName();

	for (int32 Index = ActiveCollections.Num() - 1; Index >= 0; --Index)
	{
		UGenericPropertyCollection* Collection = ActiveCollections[Index];
		if (Collection == nullptr || Collection->Proxy == nullptr)
		{
			ActiveCollections.RemoveAtSwap(Index);
			continue;
		}

		Collection->Proxy->QueueObjectPropertyChanged(InObject, MemberPropertyName, LeafPropertyName, bStructuralChange);
	}
}
