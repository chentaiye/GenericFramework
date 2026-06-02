#include "Subsystem/RandomSeedGenerationSubsystem.h"

#include "Engine/World.h"
#include "Misc/Crc.h"
#include "Misc/Guid.h"
#include "Settings/RandomSeedWorldSettings.h"
#include "WorldSettings/GenericWorldSettingsSubsystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(RandomSeedGenerationSubsystem)

namespace RandomSeedGenerationPrivate
{
	static const FName DefaultSeedKey(TEXT("Default"));

	static int32 CombineSeed(const int64 BaseSeed, const int32 SaltA, const int32 SaltB)
	{
		const uint64 SeedBits = static_cast<uint64>(BaseSeed);
		uint32 Combined = HashCombine(static_cast<uint32>(SeedBits), static_cast<uint32>(SeedBits >> 32));
		Combined = HashCombine(Combined, ::GetTypeHash(SaltA));
		Combined = HashCombine(Combined, ::GetTypeHash(SaltB));
		return Combined != 0 ? static_cast<int32>(Combined) : 1;
	}
}

URandomSeedGenerationSubsystem* URandomSeedGenerationSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UWorld* World = WorldContextObject->GetWorld();
	return World ? World->GetSubsystem<URandomSeedGenerationSubsystem>() : nullptr;
}

void URandomSeedGenerationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	ManagedSeeds.Reset();
	RuntimeGenerationCounter=0;

	ApplyWorldSeedSettingsFromCurrentWorld();
}

void URandomSeedGenerationSubsystem::Deinitialize()
{
	ManagedSeeds.Reset();
	RuntimeGenerationCounter=0;

	Super::Deinitialize();
}

void URandomSeedGenerationSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	ApplyWorldSeedSettingsFromCurrentWorld();
}

bool URandomSeedGenerationSubsystem::HasManagedSeed(const FName SeedKey) const
{
	return ManagedSeeds.Contains(NormalizeSeedKey(SeedKey));
}

bool URandomSeedGenerationSubsystem::GetManagedSeed(const FName SeedKey, int64& OutSeed) const
{
	if (const int64* ExistingSeed = ManagedSeeds.Find(NormalizeSeedKey(SeedKey)))
	{
		OutSeed = *ExistingSeed;
		return true;
	}

	return false;
}

int64 URandomSeedGenerationSubsystem::GetOrCreateManagedSeed(const FName SeedKey)
{
	const FName NormalizedSeedKey = NormalizeSeedKey(SeedKey);
	if (const int64* ExistingSeed = ManagedSeeds.Find(NormalizedSeedKey))
	{
		return *ExistingSeed;
	}

	const int64 GeneratedSeed = BuildDeterministicSeed(NormalizedSeedKey);
	ManagedSeeds.Add(NormalizedSeedKey, GeneratedSeed);
	return GeneratedSeed;
}

int64 URandomSeedGenerationSubsystem::SetManagedSeed(const FName SeedKey, const int64 Seed)
{
	const FName NormalizedSeedKey = NormalizeSeedKey(SeedKey);
	ManagedSeeds.Add(NormalizedSeedKey, Seed);
	return Seed;
}

int64 URandomSeedGenerationSubsystem::GenerateManagedSeed(const FName SeedKey)
{
	const FName NormalizedSeedKey = NormalizeSeedKey(SeedKey);
	const int64 GeneratedSeed = BuildGeneratedSeed(NormalizedSeedKey);
	ManagedSeeds.Add(NormalizedSeedKey, GeneratedSeed);
	return GeneratedSeed;
}

bool URandomSeedGenerationSubsystem::RemoveManagedSeed(const FName SeedKey)
{
	return ManagedSeeds.Remove(NormalizeSeedKey(SeedKey)) > 0;
}

FRandomStream URandomSeedGenerationSubsystem::MakeRandomStream(const FName SeedKey, const int32 SaltA, const int32 SaltB)
{
	return FRandomStream(RandomSeedGenerationPrivate::CombineSeed(GetOrCreateManagedSeed(SeedKey), SaltA, SaltB));
}

int64 URandomSeedGenerationSubsystem::ApplyWorldSeedSettings(const bool bUseCustomSeed, const int64 CustomSeed)
{
	const FName DefaultSeedKey = NormalizeSeedKey(NAME_None);
	if (bUseCustomSeed)
	{
		return SetManagedSeed(DefaultSeedKey, CustomSeed);
	}

	if (const int64* ExistingSeed = ManagedSeeds.Find(DefaultSeedKey))
	{
		return *ExistingSeed;
	}

	return GenerateManagedSeed(DefaultSeedKey);
}

void URandomSeedGenerationSubsystem::ApplyWorldSeedSettingsFromCurrentWorld()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	const UGenericWorldSettingsSubsystem* WorldSettingsSubsystem = World->GetSubsystem<UGenericWorldSettingsSubsystem>();
	const URandomSeedWorldSettings* RandomSeedWorldSettings = WorldSettingsSubsystem ? WorldSettingsSubsystem->GetWorldSetting<URandomSeedWorldSettings>() : nullptr;
	if (!RandomSeedWorldSettings)
	{
		return;
	}

	ApplyWorldSeedSettings(RandomSeedWorldSettings->bUseCustomSeed, RandomSeedWorldSettings->CustomSeed);
}

FName URandomSeedGenerationSubsystem::NormalizeSeedKey(const FName SeedKey)
{
	return SeedKey.IsNone() ? RandomSeedGenerationPrivate::DefaultSeedKey : SeedKey;
}

int64 URandomSeedGenerationSubsystem::BuildDeterministicSeed(const FName SeedKey)
{
	const FName NormalizedSeedKey = NormalizeSeedKey(SeedKey);
	const int64 Seed = static_cast<int64>(FCrc::StrCrc32(*NormalizedSeedKey.ToString()));
	return Seed != 0 ? Seed : 1;
}

int64 URandomSeedGenerationSubsystem::BuildGeneratedSeed(const FName SeedKey)
{
	++RuntimeGenerationCounter;

	const FGuid Guid = FGuid::NewGuid();
	uint64 Combined = (static_cast<uint64>(FCrc::StrCrc32(*NormalizeSeedKey(SeedKey).ToString())) << 32) | (RuntimeGenerationCounter & 0xffffffffull);
	Combined ^= (static_cast<uint64>(Guid.A) << 32) | Guid.B;
	Combined = (Combined * 11400714819323198485ull) ^ ((static_cast<uint64>(Guid.C) << 32) | Guid.D);
	const int64 Seed = static_cast<int64>(Combined & 0x7fffffffffffffffull);
	return Seed != 0 ? Seed : 1;
}
