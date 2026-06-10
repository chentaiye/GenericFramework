// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericBinkMediaSubsystem.h"

#include "GenericBinkMediaHandle.h"
#include "MovieSceneType.h"
#include "Type/DebugType.h"

UGenericBinkMediaSubsystem* UGenericBinkMediaSubsystem::Get(const UObject* WorldContextObject)
{
	if (const UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		return World->GetSubsystem<ThisClass>();
	}
	return nullptr;
}

UGenericBinkMediaHandle* UGenericBinkMediaSubsystem::ConstructBinkMediaHandle(const UObject* WorldContextObject, UBinkMediaPlayer* InBinkMediaPlayer, UBinkMediaTexture* InBinkMediaTexture)
{
	if (!IsValid(InBinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("ConstructBinkMediaHandle Failed: Invalid BinkMediaPlayer"))
		return nullptr;
	}

	if (UGenericBinkMediaSubsystem* GenericBinkMediaSubsystem = UGenericBinkMediaSubsystem::Get(WorldContextObject))
	{
		UGenericBinkMediaHandle* NewHandle = NewObject<UGenericBinkMediaHandle>(GenericBinkMediaSubsystem);
		NewHandle->Register(InBinkMediaPlayer, InBinkMediaTexture);
		GenericBinkMediaSubsystem->RegisterBinkMediaHandle(NewHandle);

		return NewHandle;
	}

	return nullptr;
}

void UGenericBinkMediaSubsystem::DeconstructBinkMediaHandle(const UObject* WorldContextObject, UGenericBinkMediaHandle* InHandle)
{
	if (UGenericBinkMediaSubsystem* GenericBinkMediaSubsystem = UGenericBinkMediaSubsystem::Get(WorldContextObject))
	{
		GenericBinkMediaSubsystem->UnRegisterBinkMediaHandle(InHandle);
	}
}

void UGenericBinkMediaSubsystem::RegisterBinkMediaHandle(UGenericBinkMediaHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (BinkMediaHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already Register"))
		return;
	}

	BinkMediaHandles.Add(InHandle);
}

void UGenericBinkMediaSubsystem::UnRegisterBinkMediaHandle(UGenericBinkMediaHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (!BinkMediaHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already UnRegister"))
		return;
	}

	InHandle->CloseMovieScene();
	BinkMediaHandles.Remove(InHandle);
}
