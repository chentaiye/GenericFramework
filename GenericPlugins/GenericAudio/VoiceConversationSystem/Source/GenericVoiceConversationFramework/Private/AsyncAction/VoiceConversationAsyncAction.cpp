// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/VoiceConversationAsyncAction.h"

#include "Component/VoiceConversationComponent.h"

UVoiceConversationAsyncAction* UVoiceConversationAsyncAction::SendText(UVoiceConversationComponent* InConversationComponent, const FString& InText, const bool bInStartSessionIfNeeded)
{
	UVoiceConversationAsyncAction* Action = NewObject<UVoiceConversationAsyncAction>();
	Action->ConversationComponent = InConversationComponent;
	Action->Text = InText;
	Action->bStartSessionIfNeeded = bInStartSessionIfNeeded;
	return Action;
}

void UVoiceConversationAsyncAction::Activate()
{
	if (ConversationComponent == nullptr)
	{
		OnError.Broadcast(MakeErrorEvent(TEXT("Conversation component is null.")));
		SetReadyToDestroy();
		return;
	}

	ConversationComponent->OnConversationStarted.AddDynamic(this, &UVoiceConversationAsyncAction::HandleStarted);
	ConversationComponent->OnConversationReplyEvent.AddDynamic(this, &UVoiceConversationAsyncAction::HandleReply);
	ConversationComponent->OnConversationError.AddDynamic(this, &UVoiceConversationAsyncAction::HandleError);
	bBound = true;

	if (ConversationComponent->IsSessionActive())
	{
		TrySendText();
		return;
	}

	if (!bStartSessionIfNeeded)
	{
		HandleError(MakeErrorEvent(TEXT("Conversation session is not active.")));
		return;
	}

	if (!ConversationComponent->StartConversationSession() && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("StartConversation failed.")));
	}
}

void UVoiceConversationAsyncAction::HandleStarted(FVoiceConversationProviderEvent InEvent)
{
	OnStarted.Broadcast(InEvent);
	TrySendText();
}

void UVoiceConversationAsyncAction::HandleReply(FVoiceConversationReply InReply)
{
	OnReply.Broadcast(InReply);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceConversationAsyncAction::HandleError(FVoiceConversationProviderEvent InEvent)
{
	OnError.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceConversationAsyncAction::TrySendText()
{
	if (bMessageSent || ConversationComponent == nullptr)
	{
		return;
	}

	bMessageSent = true;
	if (!ConversationComponent->SendUserText(Text) && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("SendText failed.")));
	}
}

void UVoiceConversationAsyncAction::Unbind()
{
	if (!bBound || ConversationComponent == nullptr)
	{
		return;
	}

	ConversationComponent->OnConversationStarted.RemoveDynamic(this, &UVoiceConversationAsyncAction::HandleStarted);
	ConversationComponent->OnConversationReplyEvent.RemoveDynamic(this, &UVoiceConversationAsyncAction::HandleReply);
	ConversationComponent->OnConversationError.RemoveDynamic(this, &UVoiceConversationAsyncAction::HandleError);
	bBound = false;
}

FVoiceConversationProviderEvent UVoiceConversationAsyncAction::MakeErrorEvent(const FString& InMessage)
{
	FVoiceConversationProviderEvent Event;
	Event.Message = InMessage;
	return Event;
}
