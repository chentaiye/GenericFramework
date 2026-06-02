// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoiceConversationComponent.h"

#include "Interface/VoiceConversationInterface.h"
#include "Provider/VoiceConversationServiceFeature.h"
#include "Route/VoiceRouteResolver.h"

UVoiceConversationComponent::UVoiceConversationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetConversationState(EVoiceConversationState::Idle);
}

bool UVoiceConversationComponent::StartConversationSession()
{
	if (bSessionActive)
	{
		return true;
	}

	const FVoiceConversationStartRequest Request = BuildStartRequest();
	SetConversationState(EVoiceConversationState::Starting);
	SetVoiceComponentState(EVoiceComponentState::Starting);

	FString LastMessage = TEXT("No conversation provider candidates available.");
	const TArray<FVoiceProviderRouteCandidate> Candidates = FVoiceRouteResolver::BuildCandidates(Request.RoutePolicy, Request.OnlineProvider, Request.OfflineProvider);
	for (const FVoiceProviderRouteCandidate& Candidate : Candidates)
	{
		if (IVoiceConversationServiceFeatureInterface* Feature = IVoiceConversationServiceFeatureInterface::FindFeatureByName(Candidate.ProviderName))
		{
			if (TryStartWithFeature(*Feature, Candidate.RouteSource, Request, LastMessage))
			{
				return true;
			}
		}
	}

	NotifyProviderError(NAME_None, EVoiceRouteSource::None, LastMessage);
	return false;
}

void UVoiceConversationComponent::StopConversationSession()
{
	if (!bSessionActive)
	{
		return;
	}

	if (IVoiceConversationServiceFeatureInterface* Feature = IVoiceConversationServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName()))
	{
		Feature->StopSession(*this);
	}
	else
	{
		NotifyProviderSessionStopped(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Conversation provider already unavailable when stopping."));
	}
}

bool UVoiceConversationComponent::SendUserText(const FString& InText)
{
	if (!bSessionActive)
	{
		NotifyProviderError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Conversation session is not active."));
		return false;
	}

	FVoiceConversationMessage Message;
	Message.Role = EVoiceConversationRole::User;
	Message.Content = InText;
	ConversationHistory.Add(Message);

	IVoiceConversationServiceFeatureInterface* Feature = IVoiceConversationServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName());
	if (Feature == nullptr)
	{
		NotifyProviderError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Conversation provider feature is unavailable."));
		return false;
	}

	FString OutMessage;
	const bool bSuccess = Feature->SendUserMessage(*this, InText, OutMessage);
	if (!bSuccess)
	{
		NotifyProviderError(GetSelectedProviderName(), GetSelectedRouteSource(), OutMessage);
		return false;
	}

	SetConversationState(EVoiceConversationState::WaitingReply);
	return true;
}

void UVoiceConversationComponent::SimulateAssistantReply(const FString& InReplyText, const FString& InMessage)
{
	NotifyProviderReply(GetSelectedProviderName(), GetSelectedRouteSource(), InReplyText, InMessage);
}

void UVoiceConversationComponent::NotifyProviderSessionStarted(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bSessionActive = true;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Running);
	SetConversationState(EVoiceConversationState::Ready);
	OnConversationStarted.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceConversationComponent::NotifyProviderSessionStopped(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bSessionActive = false;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetConversationState(EVoiceConversationState::Stopped);
	OnConversationStopped.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceConversationComponent::NotifyProviderReply(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InContent, const FString& InMessage)
{
	FVoiceConversationMessage HistoryMessage;
	HistoryMessage.Role = EVoiceConversationRole::Assistant;
	HistoryMessage.Content = InContent;
	ConversationHistory.Add(HistoryMessage);

	FVoiceConversationReply Reply;
	Reply.bSuccessful = true;
	Reply.ProviderName = InProviderName;
	Reply.RouteSource = InRouteSource;
	Reply.Content = InContent;
	Reply.Message = InMessage;

	SetConversationState(EVoiceConversationState::Ready);
	OnConversationReplyEvent.Broadcast(Reply);
	ForwardReplyToOwner(Reply);
}

void UVoiceConversationComponent::NotifyProviderError(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InErrorMessage)
{
	UE_LOG(LogVoiceConversation, Error, TEXT("Conversation provider '%s' failed. Route=%d Message=%s"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource),
		*InErrorMessage);

	SetVoiceRouteInfo(InProviderName, InRouteSource, InErrorMessage);
	SetVoiceError(InErrorMessage);
	SetConversationState(EVoiceConversationState::Error);
	OnConversationError.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InErrorMessage));
	ForwardErrorToOwner(InErrorMessage);
}

void UVoiceConversationComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopConversationSession();
	Super::EndPlay(EndPlayReason);
}

FVoiceConversationStartRequest UVoiceConversationComponent::BuildStartRequest() const
{
	FVoiceConversationStartRequest Request;
	Request.RoutePolicy = RoutePolicy;
	Request.OnlineProvider = OnlineProvider;
	Request.OfflineProvider = OfflineProvider;
	Request.ModelId = ModelId;
	Request.SystemPrompt = SystemPrompt;

	return Request;
}

bool UVoiceConversationComponent::TryStartWithFeature(IVoiceConversationServiceFeatureInterface& InFeature, const EVoiceRouteSource InRouteSource, const FVoiceConversationStartRequest& InRequest, FString& OutMessage)
{
	if (InRouteSource == EVoiceRouteSource::Online && !bEnableOnlineRoute)
	{
		OutMessage = TEXT("Online conversation is disabled.");
		return false;
	}

	if (InRouteSource == EVoiceRouteSource::Offline && !bEnableOfflineRoute)
	{
		OutMessage = TEXT("Offline conversation is disabled.");
		return false;
	}

	return InFeature.StartSession(*this, InRequest, OutMessage);
}

void UVoiceConversationComponent::SetConversationState(const EVoiceConversationState InState)
{
	if (ConversationState == InState)
	{
		return;
	}

	ConversationState = InState;
	OnConversationStateChanged.Broadcast(ConversationState);
	ForwardStateToOwner(ConversationState);
}

void UVoiceConversationComponent::ForwardStateToOwner(const EVoiceConversationState InState) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceConversationInterface::StaticClass()))
		{
			IVoiceConversationInterface::Execute_OnConversationStateChanged(OwnerActor, InState);
		}
	}
}

void UVoiceConversationComponent::ForwardReplyToOwner(const FVoiceConversationReply& InReply) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceConversationInterface::StaticClass()))
		{
			IVoiceConversationInterface::Execute_OnConversationReply(OwnerActor, InReply);
		}
	}
}

void UVoiceConversationComponent::ForwardErrorToOwner(const FString& InMessage) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceConversationInterface::StaticClass()))
		{
			IVoiceConversationInterface::Execute_OnConversationError(OwnerActor, InMessage);
		}
	}
}

FVoiceConversationProviderEvent UVoiceConversationComponent::MakeProviderEvent(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage) const
{
	FVoiceConversationProviderEvent Event;
	Event.ProviderName = InProviderName;
	Event.RouteSource = InRouteSource;
	Event.Message = InMessage;
	return Event;
}
