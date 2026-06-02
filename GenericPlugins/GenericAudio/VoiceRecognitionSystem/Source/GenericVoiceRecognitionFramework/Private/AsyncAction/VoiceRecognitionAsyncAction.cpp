// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/VoiceRecognitionAsyncAction.h"

#include "Component/VoiceRecognitionComponent.h"

UVoiceRecognitionAsyncAction* UVoiceRecognitionAsyncAction::StartRecognition(UVoiceRecognitionComponent* InRecognitionComponent, const FString& InAudioFilePath)
{
	UVoiceRecognitionAsyncAction* Action = NewObject<UVoiceRecognitionAsyncAction>();
	Action->RecognitionComponent = InRecognitionComponent;
	Action->AudioFilePath = InAudioFilePath;
	return Action;
}

void UVoiceRecognitionAsyncAction::Activate()
{
	if (RecognitionComponent == nullptr)
	{
		OnError.Broadcast(MakeErrorEvent(TEXT("Recognition component is null.")));
		SetReadyToDestroy();
		return;
	}

	RecognitionComponent->OnRecognitionStarted.AddDynamic(this, &UVoiceRecognitionAsyncAction::HandleStarted);
	RecognitionComponent->OnRecognitionPartial.AddDynamic(this, &UVoiceRecognitionAsyncAction::HandlePartial);
	RecognitionComponent->OnRecognitionFinal.AddDynamic(this, &UVoiceRecognitionAsyncAction::HandleFinal);
	RecognitionComponent->OnRecognitionError.AddDynamic(this, &UVoiceRecognitionAsyncAction::HandleError);
	bBound = true;

	if (!RecognitionComponent->StartRecognition() && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("StartRecognition failed.")));
	}
}

void UVoiceRecognitionAsyncAction::HandleStarted(FVoiceRecognitionProviderEvent InEvent)
{
	OnStarted.Broadcast(InEvent);

	if (!bAudioSubmitted && !AudioFilePath.IsEmpty() && RecognitionComponent != nullptr)
	{
		bAudioSubmitted = true;
		RecognitionComponent->RecognizeAudioFile(AudioFilePath);
	}
}

void UVoiceRecognitionAsyncAction::HandlePartial(FVoiceRecognitionResult InResult)
{
	OnPartial.Broadcast(InResult);
}

void UVoiceRecognitionAsyncAction::HandleFinal(FVoiceRecognitionResult InResult)
{
	OnFinal.Broadcast(InResult);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceRecognitionAsyncAction::HandleError(FVoiceRecognitionProviderEvent InEvent)
{
	OnError.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceRecognitionAsyncAction::Unbind()
{
	if (!bBound || RecognitionComponent == nullptr)
	{
		return;
	}

	RecognitionComponent->OnRecognitionStarted.RemoveDynamic(this, &UVoiceRecognitionAsyncAction::HandleStarted);
	RecognitionComponent->OnRecognitionPartial.RemoveDynamic(this, &UVoiceRecognitionAsyncAction::HandlePartial);
	RecognitionComponent->OnRecognitionFinal.RemoveDynamic(this, &UVoiceRecognitionAsyncAction::HandleFinal);
	RecognitionComponent->OnRecognitionError.RemoveDynamic(this, &UVoiceRecognitionAsyncAction::HandleError);
	bBound = false;
}

FVoiceRecognitionProviderEvent UVoiceRecognitionAsyncAction::MakeErrorEvent(const FString& InMessage)
{
	FVoiceRecognitionProviderEvent Event;
	Event.Message = InMessage;
	return Event;
}
