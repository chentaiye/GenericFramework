// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/VoiceSynthesisAsyncAction.h"

#include "Component/VoiceSynthesisComponent.h"

UVoiceSynthesisAsyncAction* UVoiceSynthesisAsyncAction::SynthesizeText(UVoiceSynthesisComponent* InSynthesisComponent, const FString& InText, const FString& InOutputFilePath)
{
	UVoiceSynthesisAsyncAction* Action = NewObject<UVoiceSynthesisAsyncAction>();
	Action->SynthesisComponent = InSynthesisComponent;
	Action->Text = InText;
	Action->OutputFilePath = InOutputFilePath;
	return Action;
}

void UVoiceSynthesisAsyncAction::Activate()
{
	if (SynthesisComponent == nullptr)
	{
		OnError.Broadcast(MakeErrorEvent(TEXT("Synthesis component is null.")));
		SetReadyToDestroy();
		return;
	}

	SynthesisComponent->OnSynthesisStarted.AddDynamic(this, &UVoiceSynthesisAsyncAction::HandleStarted);
	SynthesisComponent->OnSynthesisCompletedEvent.AddDynamic(this, &UVoiceSynthesisAsyncAction::HandleCompleted);
	SynthesisComponent->OnSynthesisError.AddDynamic(this, &UVoiceSynthesisAsyncAction::HandleError);
	bBound = true;

	if (!SynthesisComponent->SynthesizeText(Text, OutputFilePath) && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("SynthesizeText failed.")));
	}
}

void UVoiceSynthesisAsyncAction::HandleStarted(FVoiceSynthesisProviderEvent InEvent)
{
	OnStarted.Broadcast(InEvent);
}

void UVoiceSynthesisAsyncAction::HandleCompleted(FVoiceSynthesisResult InResult)
{
	OnCompleted.Broadcast(InResult);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceSynthesisAsyncAction::HandleError(FVoiceSynthesisProviderEvent InEvent)
{
	OnError.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceSynthesisAsyncAction::Unbind()
{
	if (!bBound || SynthesisComponent == nullptr)
	{
		return;
	}

	SynthesisComponent->OnSynthesisStarted.RemoveDynamic(this, &UVoiceSynthesisAsyncAction::HandleStarted);
	SynthesisComponent->OnSynthesisCompletedEvent.RemoveDynamic(this, &UVoiceSynthesisAsyncAction::HandleCompleted);
	SynthesisComponent->OnSynthesisError.RemoveDynamic(this, &UVoiceSynthesisAsyncAction::HandleError);
	bBound = false;
}

FVoiceSynthesisProviderEvent UVoiceSynthesisAsyncAction::MakeErrorEvent(const FString& InMessage)
{
	FVoiceSynthesisProviderEvent Event;
	Event.Message = InMessage;
	return Event;
}
