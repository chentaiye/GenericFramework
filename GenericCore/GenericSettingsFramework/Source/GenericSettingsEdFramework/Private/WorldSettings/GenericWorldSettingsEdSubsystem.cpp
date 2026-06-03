// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/GenericWorldSettingsEdSubsystem.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Base/GenericSlateStyle.h"
#include "Blueprint/BlueprintSupport.h"
#include "Containers/Ticker.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "FileHelpers.h"
#include "Framework/Docking/TabManager.h"
#include "GameFramework/WorldSettings.h"
#include "Misc/EngineVersionComparison.h"
#include "Misc/PackageName.h"
#include "ScopedTransaction.h"
#include "UObject/ObjectSaveContext.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/UObjectIterator.h"
#include "Widgets/Docking/SDockTab.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "WorldSettings/GenericWorldSettingsCollection.h"
#include "WorldSettings/SGenericWorldSettingsEditor.h"

#define LOCTEXT_NAMESPACE "GenericWorldSettingsEdSubsystem"

namespace GenericWorldSettingsEditor
{
const FName WorldSettingsTabName("GenericWorldSettings");
}

namespace
{
constexpr int32 MaxWorldSettingsClassLoadsPerTick = 4;

TArray<TWeakObjectPtr<UClass>>& GetManualWorldSettingsClasses()
{
	static TArray<TWeakObjectPtr<UClass>> ManualClasses;
	return ManualClasses;
}
}

void UGenericWorldSettingsEdSubsystem::RegisterWorldSettingsClass(TSubclassOf<UGenericWorldSettings> SettingsClass)
{
	UClass* ResolvedClass = SettingsClass.Get();
	if (!IsValidWorldSettingsClass(ResolvedClass))
	{
		return;
	}

	TArray<TWeakObjectPtr<UClass>>& ManualClasses = GetManualWorldSettingsClasses();
	for (const TWeakObjectPtr<UClass>& ExistingClass : ManualClasses)
	{
		if (ExistingClass.Get() == ResolvedClass)
		{
			return;
		}
	}

	ManualClasses.Add(ResolvedClass);
}

void UGenericWorldSettingsEdSubsystem::UnregisterWorldSettingsClass(TSubclassOf<UGenericWorldSettings> SettingsClass)
{
	UClass* ResolvedClass = SettingsClass.Get();
	TArray<TWeakObjectPtr<UClass>>& ManualClasses = GetManualWorldSettingsClasses();

	ManualClasses.RemoveAll
	(
		[ResolvedClass](const TWeakObjectPtr<UClass>& ExistingClass)
		{
			return !ExistingClass.IsValid() || ExistingClass.Get() == ResolvedClass;
		}
	);
}

TArray<TSubclassOf<UGenericWorldSettings>> UGenericWorldSettingsEdSubsystem::GetRegisteredWorldSettingsClasses()
{
	TArray<TSubclassOf<UGenericWorldSettings>> Result;
	TSet<const UClass*> SeenClasses;

	for (const TWeakObjectPtr<UClass>& RegisteredClass : GetManualWorldSettingsClasses())
	{
		AddUniqueSettingsClass(RegisteredClass.Get(), Result, SeenClasses);
	}

	return Result;
}

void UGenericWorldSettingsEdSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(GenericWorldSettingsEditor::WorldSettingsTabName, FOnSpawnTab::CreateUObject(this, &UGenericWorldSettingsEdSubsystem::HandleSpawnWorldSettingsTab))
		.SetDisplayName(LOCTEXT("GenericWorldSettingsTabTitle", "Generic World Settings"))
		.SetMenuType(ETabSpawnerMenuType::Hidden)
		.SetIcon(FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "WorldSettings", "WorldSettings.Small"));

	FEditorDelegates::MapChange.AddUObject(this, &UGenericWorldSettingsEdSubsystem::HandleEditorMapChanged);
	FEditorDelegates::PostSaveWorldWithContext.AddUObject(this, &UGenericWorldSettingsEdSubsystem::HandleEditorPostSaveWorld);
}

void UGenericWorldSettingsEdSubsystem::Deinitialize()
{
	NotifyEditorSettingsUnloaded();

	Super::Deinitialize();

	++WorldSettingsClassRefreshRequestId;
	StopWorldSettingsClassDiscoveryTicker();
	StopWorldSettingsClassRefreshTicker();
	bIsRefreshingWorldSettingsClasses = false;

	FEditorDelegates::MapChange.RemoveAll(this);
	FEditorDelegates::PostSaveWorldWithContext.RemoveAll(this);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(GenericWorldSettingsEditor::WorldSettingsTabName);
}

void UGenericWorldSettingsEdSubsystem::HandleEditorMapChanged(uint32 MapChangeFlags)
{
	if ((MapChangeFlags & MapChangeEventFlags::MapRebuild) != 0 && (MapChangeFlags & (MapChangeEventFlags::NewMap | MapChangeEventFlags::WorldTornDown)) == 0)
	{
		return;
	}

	NotifyEditorSettingsUnloaded();
	if ((MapChangeFlags & MapChangeEventFlags::WorldTornDown) == 0)
	{
		NotifyEditorSettingsLoaded();
	}

	WorldSettingsClassesChangedDelegate.Broadcast();
}

void UGenericWorldSettingsEdSubsystem::HandleEditorPostSaveWorld(UWorld* World, FObjectPostSaveContext ObjectSaveContext)
{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	const bool bIsFromAutoSave = false;
#else
	const bool bIsFromAutoSave = ObjectSaveContext.IsFromAutoSave();
#endif
	if (!World || World != GetEditorWorld() || !ObjectSaveContext.SaveSucceeded() || bIsFromAutoSave)
	{
		return;
	}

	NotifyEditorSettingsSaved();
}

void UGenericWorldSettingsEdSubsystem::RefreshWorldSettingsClasses()
{
	++WorldSettingsClassRefreshRequestId;
	StopWorldSettingsClassDiscoveryTicker();
	StopWorldSettingsClassDiscoveryTicker();
	StopWorldSettingsClassRefreshTicker();
	bIsRefreshingWorldSettingsClasses = false;

	TArray<TSubclassOf<UGenericWorldSettings>> RefreshedClasses;
	TSet<const UClass*> SeenClasses;
	AddLoadedWorldSettingsClasses(RefreshedClasses, SeenClasses);
	SortWorldSettingsClasses(RefreshedClasses);

	WorldSettingsClasses = MoveTemp(RefreshedClasses);
	bHasLoadedWorldSettingsClasses = true;
	NotifyEditorSettingsLoaded();
	WorldSettingsClassesChangedDelegate.Broadcast();
}

void UGenericWorldSettingsEdSubsystem::RequestAsyncRefreshWorldSettingsClasses(bool bForce)
{
	if (bIsRefreshingWorldSettingsClasses)
	{
		return;
	}

	if (bHasLoadedWorldSettingsClasses && !bForce)
	{
		WorldSettingsClassesChangedDelegate.Broadcast();
		return;
	}

	StopWorldSettingsClassDiscoveryTicker();
	StopWorldSettingsClassRefreshTicker();

	const int32 RequestId = ++WorldSettingsClassRefreshRequestId;
	bIsRefreshingWorldSettingsClasses = true;
	bHasLoadedWorldSettingsClasses = false;
	PendingWorldSettingsClassPaths.Reset();
	PendingWorldSettingsClasses.Reset();
	WorldSettingsClassesChangedDelegate.Broadcast();

	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	if (!AssetRegistry.IsSearchAllAssets())
	{
		AssetRegistry.SearchAllAssets(false);
	}

	WorldSettingsClassDiscoveryTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericWorldSettingsEdSubsystem::TickCollectDiscoveredWorldSettingsClassPaths, RequestId), 0.0f);
}

bool UGenericWorldSettingsEdSubsystem::IsRefreshingWorldSettingsClasses() const
{
	return bIsRefreshingWorldSettingsClasses;
}

bool UGenericWorldSettingsEdSubsystem::HasLoadedWorldSettingsClasses() const
{
	return bHasLoadedWorldSettingsClasses;
}

FGenericWorldSettingsClassesChangedDelegate& UGenericWorldSettingsEdSubsystem::OnWorldSettingsClassesChanged()
{
	return WorldSettingsClassesChangedDelegate;
}

const TArray<TSubclassOf<UGenericWorldSettings>>& UGenericWorldSettingsEdSubsystem::GetWorldSettingsClasses() const
{
	return WorldSettingsClasses;
}

UWorld* UGenericWorldSettingsEdSubsystem::GetEditorWorld() const
{
	return GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
}

AWorldSettings* UGenericWorldSettingsEdSubsystem::GetEditorWorldSettings() const
{
	UWorld* World = GetEditorWorld();
	return World ? World->GetWorldSettings(false, false) : nullptr;
}

UGenericWorldSettingsCollection* UGenericWorldSettingsEdSubsystem::GetSettingsCollection() const
{
	AWorldSettings* WorldSettings = GetEditorWorldSettings();
	return WorldSettings ? Cast<UGenericWorldSettingsCollection>(WorldSettings->GetAssetUserDataOfClass(UGenericWorldSettingsCollection::StaticClass())) : nullptr;
}

UGenericWorldSettingsCollection* UGenericWorldSettingsEdSubsystem::CreateSettingsCollection()
{
	if (UGenericWorldSettingsCollection* ExistingCollection = GetSettingsCollection())
	{
		return ExistingCollection;
	}

	AWorldSettings* WorldSettings = GetEditorWorldSettings();
	if (!WorldSettings)
	{
		return nullptr;
	}

	const FScopedTransaction Transaction(LOCTEXT("CreateWorldSettingsCollectionTransaction", "Create Generic World Settings Collection"));
	WorldSettings->Modify();

	UGenericWorldSettingsCollection* NewCollection = NewObject<UGenericWorldSettingsCollection>(WorldSettings, NAME_None, RF_Transactional);
	WorldSettings->AddAssetUserData(NewCollection);

	MarkCurrentWorldDirty();
	NotifyEditorSettingsLoaded();
	return NewCollection;
}

bool UGenericWorldSettingsEdSubsystem::DeleteSettingsCollection()
{
	AWorldSettings* WorldSettings = GetEditorWorldSettings();
	UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	if (!WorldSettings || !Collection)
	{
		return false;
	}

	const FScopedTransaction Transaction(LOCTEXT("DeleteWorldSettingsCollectionTransaction", "Delete Generic World Settings Collection"));
	NotifyEditorSettingsUnloaded();
	WorldSettings->Modify();
	Collection->Modify();
	WorldSettings->RemoveUserDataOfClass(UGenericWorldSettingsCollection::StaticClass());

	MarkCurrentWorldDirty();
	WorldSettingsClassesChangedDelegate.Broadcast();
	return true;
}

int32 UGenericWorldSettingsEdSubsystem::SyncMissingSettings()
{
	UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	if (!Collection)
	{
		return 0;
	}

	if (!bHasLoadedWorldSettingsClasses && !bIsRefreshingWorldSettingsClasses)
	{
		RequestAsyncRefreshWorldSettingsClasses();
		return 0;
	}

	if (bIsRefreshingWorldSettingsClasses)
	{
		return 0;
	}

	const FScopedTransaction Transaction(LOCTEXT("SyncWorldSettingsTransaction", "Sync Generic World Settings"));
	Collection->Modify();

	int32 CreatedCount = 0;
	for (const TSubclassOf<UGenericWorldSettings>& SettingsClass : WorldSettingsClasses)
	{
		if (!SettingsClass || Collection->FindSettingsByExactClass(SettingsClass.Get()))
		{
			continue;
		}

		if (UGenericWorldSettings* CreatedSettings = Collection->FindOrCreateSettings(SettingsClass))
		{
			CreatedSettings->Modify();
			++CreatedCount;
		}
	}

	if (CreatedCount > 0)
	{
		MarkCurrentWorldDirty();
		NotifyEditorSettingsLoaded();
	}

	return CreatedCount;
}

bool UGenericWorldSettingsEdSubsystem::SaveCurrentWorld() const
{
	UWorld* World = GetEditorWorld();
	UPackage* WorldPackage = World ? World->GetOutermost() : nullptr;
	if (!WorldPackage)
	{
		return false;
	}

	TArray<UPackage*> PackagesToSave;
	PackagesToSave.Add(WorldPackage);

	const FEditorFileUtils::EPromptReturnCode SaveResult = FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, true, false);
	return SaveResult == FEditorFileUtils::PR_Success || SaveResult == FEditorFileUtils::PR_Declined;
}

bool UGenericWorldSettingsEdSubsystem::HasMissingSettings() const
{
	if (bIsRefreshingWorldSettingsClasses)
	{
		return false;
	}

	const UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	if (!Collection)
	{
		return false;
	}

	for (const TSubclassOf<UGenericWorldSettings>& SettingsClass : WorldSettingsClasses)
	{
		if (SettingsClass && !Collection->FindSettingsByExactClass(SettingsClass.Get()))
		{
			return true;
		}
	}

	return false;
}

UGenericWorldSettings* UGenericWorldSettingsEdSubsystem::FindSettingsInstance(TSubclassOf<UGenericWorldSettings> SettingsClass) const
{
	const UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	return Collection ? Collection->FindSettingsByExactClass(SettingsClass.Get()) : nullptr;
}

TSharedRef<SDockTab> UGenericWorldSettingsEdSubsystem::HandleSpawnWorldSettingsTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SGenericWorldSettingsEditor)
			.SettingsSubsystem(this)
		];
}

void UGenericWorldSettingsEdSubsystem::AddLoadedWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses, TSet<const UClass*>& SeenClasses) const
{
	for (const TWeakObjectPtr<UClass>& RegisteredClass : GetManualWorldSettingsClasses())
	{
		AddUniqueSettingsClass(RegisteredClass.Get(), OutClasses, SeenClasses);
	}

	TArray<UClass*> DerivedClasses;
	GetDerivedClasses(UGenericWorldSettings::StaticClass(), DerivedClasses, true);
	for (UClass* DerivedClass : DerivedClasses)
	{
		AddUniqueSettingsClass(DerivedClass, OutClasses, SeenClasses);
	}
}

void UGenericWorldSettingsEdSubsystem::SortWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& InOutClasses) const
{
	InOutClasses.Sort
	(
		[](const TSubclassOf<UGenericWorldSettings>& Left, const TSubclassOf<UGenericWorldSettings>& Right)
		{
			const UClass* LeftClass = Left.Get();
			const UClass* RightClass = Right.Get();
			const FString LeftName = LeftClass ? LeftClass->GetDisplayNameText().ToString() : FString();
			const FString RightName = RightClass ? RightClass->GetDisplayNameText().ToString() : FString();
			return LeftName < RightName;
		}
	);
}

void UGenericWorldSettingsEdSubsystem::StartResolvingDiscoveredWorldSettingsClasses(TArray<FString>&& ClassObjectPaths, int32 RequestId)
{
	if (RequestId != WorldSettingsClassRefreshRequestId || !bIsRefreshingWorldSettingsClasses)
	{
		return;
	}

	PendingWorldSettingsClassPaths = MoveTemp(ClassObjectPaths);
	PendingWorldSettingsClasses.Reset();

	TSet<const UClass*> SeenClasses;
	AddLoadedWorldSettingsClasses(PendingWorldSettingsClasses, SeenClasses);

	if (PendingWorldSettingsClassPaths.IsEmpty())
	{
		CompleteWorldSettingsClassRefresh();
		return;
	}

	StopWorldSettingsClassRefreshTicker();
	WorldSettingsClassRefreshTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericWorldSettingsEdSubsystem::TickResolveDiscoveredWorldSettingsClasses), 0.0f);
}

bool UGenericWorldSettingsEdSubsystem::TickCollectDiscoveredWorldSettingsClassPaths(float DeltaTime, int32 RequestId)
{
	if (RequestId != WorldSettingsClassRefreshRequestId || !bIsRefreshingWorldSettingsClasses)
	{
		WorldSettingsClassDiscoveryTickerHandle.Reset();
		return false;
	}

	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	if (AssetRegistry.IsLoadingAssets())
#else
	if (AssetRegistry.IsLoadingAssets() || AssetRegistry.IsGathering())
#endif
	{
		return true;
	}

	TArray<FTopLevelAssetPath> BaseClassNames;
	BaseClassNames.Add(UGenericWorldSettings::StaticClass()->GetClassPathName());

	TSet<FTopLevelAssetPath> ExcludedClassNames;
	TSet<FTopLevelAssetPath> DerivedClassNames;
	AssetRegistry.GetDerivedClassNames(BaseClassNames, ExcludedClassNames, DerivedClassNames);

	FARFilter BlueprintFilter;
	BlueprintFilter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
	BlueprintFilter.bRecursiveClasses = true;
	BlueprintFilter.bRecursivePaths = true;

	TSet<FString> UniqueClassObjectPaths;
	AssetRegistry.EnumerateAssets
	(
		BlueprintFilter,
		[&UniqueClassObjectPaths, &DerivedClassNames](const FAssetData& BlueprintAsset)
		{
			FString GeneratedClassPath;
			if (!BlueprintAsset.GetTagValue(FBlueprintTags::GeneratedClassPath, GeneratedClassPath) || GeneratedClassPath.IsEmpty())
			{
				return true;
			}

			FString ClassObjectPath = FPackageName::ExportTextPathToObjectPath(GeneratedClassPath);
			if (ClassObjectPath.IsEmpty())
			{
				ClassObjectPath = GeneratedClassPath;
			}

			const FSoftObjectPath SoftClassPath(ClassObjectPath);
			const FTopLevelAssetPath GeneratedAssetPath = SoftClassPath.GetAssetPath();
			if (!GeneratedAssetPath.IsNull() && DerivedClassNames.Contains(GeneratedAssetPath))
			{
				UniqueClassObjectPaths.Add(ClassObjectPath);
			}

			return true;
		}
	);

	TArray<FString> ClassObjectPaths = UniqueClassObjectPaths.Array();
	ClassObjectPaths.Sort();

	WorldSettingsClassDiscoveryTickerHandle.Reset();
	StartResolvingDiscoveredWorldSettingsClasses(MoveTemp(ClassObjectPaths), RequestId);
	return false;
}

bool UGenericWorldSettingsEdSubsystem::TickResolveDiscoveredWorldSettingsClasses(float DeltaTime)
{
	TSet<const UClass*> SeenClasses;
	for (const TSubclassOf<UGenericWorldSettings>& ExistingClass : PendingWorldSettingsClasses)
	{
		if (ExistingClass)
		{
			SeenClasses.Add(ExistingClass.Get());
		}
	}

	for (int32 Index = 0; Index < MaxWorldSettingsClassLoadsPerTick && !PendingWorldSettingsClassPaths.IsEmpty(); ++Index)
	{
#if UE_VERSION_OLDER_THAN(5, 5, 0)
		const FString ClassObjectPath = PendingWorldSettingsClassPaths.Pop(false);
#else
		const FString ClassObjectPath = PendingWorldSettingsClassPaths.Pop(EAllowShrinking::No);
#endif
		UClass* GeneratedClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), nullptr, *ClassObjectPath, nullptr, LOAD_NoWarn));
		AddUniqueSettingsClass(GeneratedClass, PendingWorldSettingsClasses, SeenClasses);
	}

	if (PendingWorldSettingsClassPaths.IsEmpty())
	{
		CompleteWorldSettingsClassRefresh();
		return false;
	}

	return true;
}

void UGenericWorldSettingsEdSubsystem::CompleteWorldSettingsClassRefresh()
{
	StopWorldSettingsClassRefreshTicker();

	SortWorldSettingsClasses(PendingWorldSettingsClasses);
	WorldSettingsClasses = MoveTemp(PendingWorldSettingsClasses);
	PendingWorldSettingsClassPaths.Reset();
	bIsRefreshingWorldSettingsClasses = false;
	bHasLoadedWorldSettingsClasses = true;

	NotifyEditorSettingsLoaded();
	WorldSettingsClassesChangedDelegate.Broadcast();
}

void UGenericWorldSettingsEdSubsystem::NotifyEditorSettingsLoaded()
{
	UWorld* World = GetEditorWorld();
	if (EditorLoadedWorld.Get() != World)
	{
		NotifyEditorSettingsUnloaded();
		EditorLoadedWorld = World;
	}

	UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	if (!Collection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	Collection->GetAllSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		const TObjectKey<UGenericWorldSettings> SettingKey(Setting);
		if (Setting && !EditorLoadedSettings.Contains(SettingKey))
		{
			EditorLoadedSettings.Add(SettingKey);
			Setting->OnWorldSettingsEditorLoaded(World);
		}
	}
}

void UGenericWorldSettingsEdSubsystem::NotifyEditorSettingsUnloaded()
{
	UWorld* World = EditorLoadedWorld.IsValid() ? EditorLoadedWorld.Get() : GetEditorWorld();

	for (const TObjectKey<UGenericWorldSettings>& SettingKey : EditorLoadedSettings)
	{
		if (UGenericWorldSettings* Setting = SettingKey.ResolveObjectPtr())
		{
			Setting->OnWorldSettingsEditorUnloaded(World);
		}
	}

	EditorLoadedSettings.Reset();
	EditorLoadedWorld = nullptr;
}

void UGenericWorldSettingsEdSubsystem::NotifyEditorSettingsSaved() const
{
	const UGenericWorldSettingsCollection* Collection = GetSettingsCollection();
	if (!Collection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	Collection->GetAllSettings(LoadedSettings);
	UWorld* World = GetEditorWorld();

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		if (Setting)
		{
			Setting->OnWorldSettingsEditorSaved(World);
		}
	}
}

void UGenericWorldSettingsEdSubsystem::StopWorldSettingsClassRefreshTicker()
{
	if (WorldSettingsClassRefreshTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(WorldSettingsClassRefreshTickerHandle);
		WorldSettingsClassRefreshTickerHandle.Reset();
	}
}

void UGenericWorldSettingsEdSubsystem::StopWorldSettingsClassDiscoveryTicker()
{
	if (WorldSettingsClassDiscoveryTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(WorldSettingsClassDiscoveryTickerHandle);
		WorldSettingsClassDiscoveryTickerHandle.Reset();
	}
}

bool UGenericWorldSettingsEdSubsystem::IsValidWorldSettingsClass(const UClass* SettingsClass)
{
	return SettingsClass
		&& SettingsClass != UGenericWorldSettings::StaticClass()
		&& SettingsClass->IsChildOf(UGenericWorldSettings::StaticClass())
		&& !SettingsClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists);
}

void UGenericWorldSettingsEdSubsystem::AddUniqueSettingsClass(UClass* SettingsClass, TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses, TSet<const UClass*>& SeenClasses)
{
	if (!IsValidWorldSettingsClass(SettingsClass) || SeenClasses.Contains(SettingsClass))
	{
		return;
	}

	SeenClasses.Add(SettingsClass);
	OutClasses.Add(SettingsClass);
}

void UGenericWorldSettingsEdSubsystem::DiscoverWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses) const
{
	TSet<const UClass*> SeenClasses;
	for (const TSubclassOf<UGenericWorldSettings>& ExistingClass : OutClasses)
	{
		if (ExistingClass)
		{
			SeenClasses.Add(ExistingClass.Get());
		}
	}

	AddLoadedWorldSettingsClasses(OutClasses, SeenClasses);
}

void UGenericWorldSettingsEdSubsystem::MarkCurrentWorldDirty() const
{
	if (AWorldSettings* WorldSettings = GetEditorWorldSettings())
	{
		WorldSettings->Modify();
		WorldSettings->MarkPackageDirty();
	}

	if (UWorld* World = GetEditorWorld())
	{
		World->MarkPackageDirty();
		if (UPackage* WorldPackage = World->GetOutermost())
		{
			WorldPackage->SetDirtyFlag(true);
		}
	}
}

#undef LOCTEXT_NAMESPACE
