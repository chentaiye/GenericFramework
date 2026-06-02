// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericBinkMediaHandle.h"

#include "MovieSceneType.h"
#include "Type/DebugType.h"

namespace
{
	constexpr int32 DefaultBinkFrameRate = 30;
}

UGenericBinkMediaHandle::UGenericBinkMediaHandle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	  bIsMediaInitialize(false)
{
}

void UGenericBinkMediaHandle::Register(UBinkMediaPlayer* InBinkMediaPlayer, UBinkMediaTexture* InBinkMediaTexture)
{
	if (!IsValid(InBinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Bink Media Handle Register Failed: Invalid BinkMediaPlayer"))
		return;
	}

	BinkMediaPlayer = InBinkMediaPlayer;
	BinkMediaTexture = InBinkMediaTexture;
	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;

	if (IsValid(BinkMediaTexture))
	{
		BinkMediaTexture->SetMediaPlayer(BinkMediaPlayer);
	}

	BinkMediaPlayer->OnMediaOpened.AddUniqueDynamic(this, &UGenericBinkMediaHandle::OnMediaOpened);
	BinkMediaPlayer->OnMediaClosed.AddUniqueDynamic(this, &UGenericBinkMediaHandle::OnMediaClosed);
	BinkMediaPlayer->OnMediaReachedEnd.AddUniqueDynamic(this, &UGenericBinkMediaHandle::OnMediaReachedEnd);
	BinkMediaPlayer->OnPlaybackSuspended.AddUniqueDynamic(this, &UGenericBinkMediaHandle::OnPlaybackSuspended);

	OpenMovieScene();
}

void UGenericBinkMediaHandle::OpenMovieScene()
{
	if (!IsValid(BinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OpenMovieScene Failed: Invalid BinkMediaPlayer"))
		return;
	}

	if (IsValid(BinkMediaTexture))
	{
		BinkMediaTexture->SetMediaPlayer(BinkMediaPlayer);
	}

	const FString OpenUrl = ResolveOpenUrl();
	if (OpenUrl.IsEmpty())
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OpenMovieScene Failed: Empty Bink Media Url"))
		return;
	}

	bIsMediaInitialize = false;

	const bool bPreviousStartImmediately = BinkMediaPlayer->StartImmediately != 0;
	BinkMediaPlayer->StartImmediately = false;
	const bool bOpened = BinkMediaPlayer->OpenUrl(OpenUrl);
	BinkMediaPlayer->StartImmediately = bPreviousStartImmediately;

	if (!bOpened)
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OpenMovieScene Failed: Unable to open bink media source"))
	}
}

void UGenericBinkMediaHandle::CloseMovieScene()
{
	if (!IsValid(BinkMediaPlayer))
	{
		bIsMediaInitialize = false;
		BinkMediaTexture = nullptr;
		return;
	}

	Super::CloseMovieScene();
}

void UGenericBinkMediaHandle::OnMovieSceneOpened()
{
	Super::OnMovieSceneOpened();
}

void UGenericBinkMediaHandle::OnMovieSceneClosed()
{
	Super::OnMovieSceneClosed();

	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;

	if (IsValid(BinkMediaPlayer))
	{
		BinkMediaPlayer->OnMediaOpened.RemoveAll(this);
		BinkMediaPlayer->OnMediaClosed.RemoveAll(this);
		BinkMediaPlayer->OnMediaReachedEnd.RemoveAll(this);
		BinkMediaPlayer->OnPlaybackSuspended.RemoveAll(this);
		BinkMediaPlayer->Stop();
		BinkMediaPlayer = nullptr;
	}

	if (IsValid(BinkMediaTexture))
	{
		BinkMediaTexture->SetMediaPlayer(nullptr);
		BinkMediaTexture = nullptr;
	}
}

bool UGenericBinkMediaHandle::PlayMovieScene()
{
	if (!bIsMediaInitialize || !IsValid(BinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayMovieScene Failed: Bink Media Is Not Ready"))
		return false;
	}

	bLoopIndefinitely = false;
	RemainingLoopCount = 1;
	BinkMediaPlayer->SetLooping(false);

	if (!BinkMediaPlayer->Play())
	{
		return false;
	}

	Super::PlayMovieScene();
	return true;
}

bool UGenericBinkMediaHandle::PlayMovieSceneFromStart()
{
	if (!bIsMediaInitialize || !IsValid(BinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayMovieSceneFromStart Failed: Bink Media Is Not Ready"))
		return false;
	}

	bLoopIndefinitely = false;
	RemainingLoopCount = 1;
	BinkMediaPlayer->SetLooping(false);
	BinkMediaPlayer->Rewind();

	if (!BinkMediaPlayer->Play())
	{
		return false;
	}

	Super::PlayMovieSceneFromStart();
	return true;
}

bool UGenericBinkMediaHandle::PlayLoopingMovieScene(int32 NumLoops)
{
	if (!bIsMediaInitialize || !IsValid(BinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayLoopingMovieScene Failed: Bink Media Is Not Ready"))
		return false;
	}

	bLoopIndefinitely = NumLoops < 0;
	RemainingLoopCount = bLoopIndefinitely ? INDEX_NONE : FMath::Max(NumLoops, 1);
	BinkMediaPlayer->SetLooping(bLoopIndefinitely);
	BinkMediaPlayer->Rewind();

	if (!BinkMediaPlayer->Play())
	{
		return false;
	}

	Super::PlayLoopingMovieScene(NumLoops);
	return true;
}

bool UGenericBinkMediaHandle::PlayReverseMovieScene()
{
	if (!bIsMediaInitialize || !IsValid(BinkMediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayReverseMovieScene Failed: Bink Media Is Not Ready"))
		return false;
	}

	GenericLOG(GenericLogMovieScene, Error, TEXT("PlayReverseMovieScene Failed: Reverse Playback Is Not Supported By Bink"))
	return false;
}

bool UGenericBinkMediaHandle::PauseMovieScene()
{
	if (!IsValid(BinkMediaPlayer))
	{
		return false;
	}

	if (!BinkMediaPlayer->Pause())
	{
		return false;
	}

	Super::PauseMovieScene();
	return true;
}

bool UGenericBinkMediaHandle::StopMovieScene()
{
	if (!IsValid(BinkMediaPlayer))
	{
		return false;
	}

	bLoopIndefinitely = false;
	RemainingLoopCount = 0;
	BinkMediaPlayer->SetLooping(false);
	BinkMediaPlayer->Pause();
	BinkMediaPlayer->Rewind();

	Super::StopMovieScene();
	return true;
}

bool UGenericBinkMediaHandle::SeekMovieScene(FTimecode SeekTime)
{
	if (!bIsMediaInitialize || !IsValid(BinkMediaPlayer))
	{
		return false;
	}

	if (!BinkMediaPlayer->SupportsSeeking())
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("SeekMovieScene Failed: Bink Media Does Not Support Seeking"))
		return false;
	}

	const bool bSeeked = BinkMediaPlayer->Seek(SeekTime.ToTimespan(GetFrameRate()));
	if (bSeeked)
	{
		OnMovieSceneSeek();
	}

	return bSeeked;
}

void UGenericBinkMediaHandle::ChangeMovieSceneDirection()
{
	GenericLOG(GenericLogMovieScene, Warning, TEXT("ChangeMovieSceneDirection Ignored: Reverse Playback Is Not Supported By Bink"))
}

bool UGenericBinkMediaHandle::IsPlaying()
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->IsPlaying();
}

bool UGenericBinkMediaHandle::IsLooping()
{
	return bLoopIndefinitely || RemainingLoopCount > 1 || (IsValid(BinkMediaPlayer) && BinkMediaPlayer->IsLooping());
}

bool UGenericBinkMediaHandle::IsPaused()
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->IsPaused();
}

bool UGenericBinkMediaHandle::IsReversed()
{
	return false;
}

FTimecode UGenericBinkMediaHandle::GetCurrentTime()
{
	if (!IsValid(BinkMediaPlayer))
	{
		return FTimecode();
	}

	return FTimecode::FromTimespan(BinkMediaPlayer->GetTime(), GetFrameRate(), true);
}

FTimecode UGenericBinkMediaHandle::GetDuration()
{
	if (!IsValid(BinkMediaPlayer))
	{
		return FTimecode();
	}

	return FTimecode::FromTimespan(BinkMediaPlayer->GetDuration(), GetFrameRate(), true);
}

FFrameRate UGenericBinkMediaHandle::GetFrameRate()
{
	if (!IsValid(BinkMediaPlayer))
	{
		return FFrameRate(DefaultBinkFrameRate, 1);
	}

	const float FrameRate = BinkMediaPlayer->GetFrameRate();
	if (FrameRate > 0.f)
	{
		return FFrameRate(FMath::Max(FMath::RoundToInt(FrameRate), 1), 1);
	}

	return FFrameRate(DefaultBinkFrameRate, 1);
}

void UGenericBinkMediaHandle::SetFrameRate(FFrameRate FrameRate)
{
	Super::SetFrameRate(FrameRate);
}

float UGenericBinkMediaHandle::GetPlayRate()
{
	return IsValid(BinkMediaPlayer) ? BinkMediaPlayer->GetRate() : 1.f;
}

void UGenericBinkMediaHandle::SetPlayRate(float InPlayRate)
{
	if (!IsValid(BinkMediaPlayer))
	{
		return;
	}

	if (InPlayRate <= 0.f)
	{
		BinkMediaPlayer->Pause();
		return;
	}

	if (!BinkMediaPlayer->SupportsRate(InPlayRate, true))
	{
		GenericLOG(GenericLogMovieScene, Warning, TEXT("SetPlayRate Clamped: Bink only supports play rate 1.0, requested %.3f"), InPlayRate)
	}

	BinkMediaPlayer->Play();
}

bool UGenericBinkMediaHandle::IsReady() const
{
	return bIsMediaInitialize && IsValid(BinkMediaPlayer) && BinkMediaPlayer->IsInitialized();
}

bool UGenericBinkMediaHandle::IsClosed() const
{
	return !IsValid(BinkMediaPlayer) || BinkMediaPlayer->IsStopped();
}

bool UGenericBinkMediaHandle::CanPause() const
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->CanPause();
}

FText UGenericBinkMediaHandle::GetMediaName() const
{
	return FText::FromString(FPaths::GetBaseFilename(GetUrl()));
}

const FString& UGenericBinkMediaHandle::GetUrl() const
{
	static const FString EmptyUrl;
	return IsValid(BinkMediaPlayer) ? BinkMediaPlayer->GetUrl() : EmptyUrl;
}

bool UGenericBinkMediaHandle::SetLooping(bool Looping) const
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->SetLooping(Looping);
}

void UGenericBinkMediaHandle::SetVolume(float Volume)
{
	if (IsValid(BinkMediaPlayer))
	{
		BinkMediaPlayer->SetVolume(Volume);
	}
}

bool UGenericBinkMediaHandle::SupportsRate(float Rate, bool Unthinned) const
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->SupportsRate(Rate, Unthinned);
}

bool UGenericBinkMediaHandle::SupportsScrubbing() const
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->SupportsScrubbing();
}

bool UGenericBinkMediaHandle::SupportsSeeking() const
{
	return IsValid(BinkMediaPlayer) && BinkMediaPlayer->SupportsSeeking();
}

FIntPoint UGenericBinkMediaHandle::GetDimensions() const
{
	return IsValid(BinkMediaPlayer) ? BinkMediaPlayer->GetDimensions() : FIntPoint::ZeroValue;
}

UBinkMediaPlayer* UGenericBinkMediaHandle::GetBinkMediaPlayer() const
{
	return BinkMediaPlayer;
}

UBinkMediaTexture* UGenericBinkMediaHandle::GetBinkMediaTexture() const
{
	return BinkMediaTexture;
}

void UGenericBinkMediaHandle::OnMediaOpened(FString OpenedUrl)
{
	bIsMediaInitialize = true;

	if (IsValid(BinkMediaTexture))
	{
		BinkMediaTexture->SetMediaPlayer(BinkMediaPlayer);
	}

	Super::OpenMovieScene();
}

void UGenericBinkMediaHandle::OnMediaClosed()
{
	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;
	OnMovieSceneStop();
}

void UGenericBinkMediaHandle::OnMediaReachedEnd()
{
	if (bLoopIndefinitely)
	{
		return;
	}

	if (RemainingLoopCount > 1 && IsValid(BinkMediaPlayer))
	{
		--RemainingLoopCount;
		BinkMediaPlayer->Rewind();
		BinkMediaPlayer->Play();
		return;
	}

	RemainingLoopCount = 0;
	OnMovieScenePlayFinish();
}

void UGenericBinkMediaHandle::OnPlaybackSuspended()
{
	OnMovieScenePause();
}

FString UGenericBinkMediaHandle::ResolveOpenUrl() const
{
	if (!IsValid(BinkMediaPlayer))
	{
		return FString();
	}

	if (!BinkMediaPlayer->URL.IsEmpty())
	{
		return BinkMediaPlayer->URL;
	}

	return BinkMediaPlayer->GetUrl();
}
