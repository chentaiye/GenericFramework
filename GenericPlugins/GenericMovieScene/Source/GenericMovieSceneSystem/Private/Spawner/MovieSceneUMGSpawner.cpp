// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Spawner/MovieSceneUMGSpawner.h"

#include "IMovieScenePlayer.h"
#include "MovieSceneSpawnable.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "Engine/LevelStreaming.h"
#include "Engine/World.h"
#include "Misc/PackageName.h"

TSharedRef<IMovieSceneObjectSpawner> FMovieSceneUMGSpawner::CreateObjectSpawner()
{
	return MakeShareable(new FMovieSceneUMGSpawner);
}

UClass* FMovieSceneUMGSpawner::GetSupportedTemplateType() const
{
	return UUserWidget::StaticClass();
}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
UObject* FMovieSceneUMGSpawner::SpawnObject(FMovieSceneSpawnable& Spawnable, FMovieSceneSequenceIDRef TemplateID, TSharedRef<const UE::MovieScene::FSharedPlaybackState> SharedPlaybackState)
#else
UObject* FMovieSceneUMGSpawner::SpawnObject(FMovieSceneSpawnable& Spawnable, FMovieSceneSequenceIDRef TemplateID, IMovieScenePlayer& Player)
#endif
{
	UUserWidget* ObjectTemplate = Cast<UUserWidget>(Spawnable.GetObjectTemplate());
	if (!ObjectTemplate)
	{
		return nullptr;
	}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	UObject* PlaybackContext = SharedPlaybackState->GetPlaybackContext();
	UWorld* WorldContext = PlaybackContext ? PlaybackContext->GetWorld() : nullptr;
#else
	UWorld* WorldContext = Cast<UWorld>(Player.GetPlaybackContext());
#endif

	FName DesiredLevelName = Spawnable.GetLevelName();
	if (DesiredLevelName != NAME_None)
	{
		if (!WorldContext)
		{
			UE_LOG(LogMovieScene, Warning, TEXT("Can't resolve world for '%s' while trying to spawn '%s'"), *DesiredLevelName.ToString(), *Spawnable.GetName());
		}
		else if (WorldContext->GetFName() == DesiredLevelName)
		{
			// done, spawn into this world
		}
		else
		{
			ULevelStreaming* LevelStreaming = GetLevelStreaming(DesiredLevelName, WorldContext);
			if (LevelStreaming && LevelStreaming->GetWorldAsset().IsValid())
			{
				WorldContext = LevelStreaming->GetWorldAsset().Get();
			}
			else
			{
				UE_LOG(LogMovieScene, Warning, TEXT("Can't find sublevel '%s' to spawn '%s' into, defaulting to Persistent level"), *DesiredLevelName.ToString(), *Spawnable.GetName());
			}
		}
	}

	if (WorldContext == nullptr)
	{
		UE_LOG(LogMovieScene, Warning, TEXT("Can't find world to spawn '%s' into, defaulting to Persistent level"), *Spawnable.GetName());
		WorldContext = GWorld;
	}

	if (WorldContext == nullptr)
	{
		return nullptr;
	}

	UUserWidget* NewUserWidget = CreateWidget<UUserWidget>(WorldContext, ObjectTemplate->GetClass());
	if (!NewUserWidget)
	{
		return nullptr;
	}

	NewUserWidget->AddToViewport();

	return NewUserWidget;
}

void FMovieSceneUMGSpawner::DestroySpawnedObject(UObject& Object)
{
	if (UUserWidget* UserWidget = Cast<UUserWidget>(&Object))
	{
		UserWidget->RemoveFromParent();
	}
}

ULevelStreaming* FMovieSceneUMGSpawner::GetLevelStreaming(const FName& DesiredLevelName, const UWorld* World)
{
	if (DesiredLevelName == NAME_None || World == nullptr || GEngine == nullptr)
	{
		return nullptr;
	}

	const TArray<ULevelStreaming*>& StreamingLevels = World->GetStreamingLevels();
	FString SafeLevelNameString = DesiredLevelName.ToString();
	if (FPackageName::IsShortPackageName(SafeLevelNameString))
	{
		// Make sure MyMap1 and Map1 names do not resolve to a same streaming level
		SafeLevelNameString.InsertAt(0, '/');
	}

#if WITH_EDITOR
	FWorldContext* WorldContext = GEngine->GetWorldContextFromWorld(World);
	if (WorldContext && WorldContext->PIEInstance != INDEX_NONE)
	{
		SafeLevelNameString = UWorld::ConvertToPIEPackageName(SafeLevelNameString, WorldContext->PIEInstance);
	}
#endif

	for (ULevelStreaming* LevelStreaming : StreamingLevels)
	{
		if (LevelStreaming && LevelStreaming->GetWorldAssetPackageName().EndsWith(SafeLevelNameString, ESearchCase::IgnoreCase))
		{
			return LevelStreaming;
		}
	}

	return nullptr;
}
