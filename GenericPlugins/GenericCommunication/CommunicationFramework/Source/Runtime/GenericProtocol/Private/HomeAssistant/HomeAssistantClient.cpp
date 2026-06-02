// Copyright ChenTaiye 2026. All Rights Reserved.

#include "HomeAssistant/HomeAssistantClient.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "IWebSocket.h"
#include "Json.h"
#include "TimerManager.h"
#include "WebSocketsModule.h"

UHomeAssistantClient::UHomeAssistantClient(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UHomeAssistantClient* UHomeAssistantClient::CreateHomeAssistantClient(UObject* Outer)
{
	return NewObject<UHomeAssistantClient>(Outer ? Outer : GetTransientPackage());
}

void UHomeAssistantClient::Configure(const FString& InBaseUrl, const FString& InAccessToken, const float InTimeoutSeconds, const bool bInAutoReconnect)
{
	BaseUrl = InBaseUrl;
	while (BaseUrl.EndsWith(TEXT("/")))
	{
		BaseUrl.LeftChopInline(1);
	}

	AccessToken = InAccessToken;
	TimeoutSeconds = FMath::Max(1.0f, InTimeoutSeconds);
	bAutoReconnect = bInAutoReconnect;
}

bool UHomeAssistantClient::HasValidConfiguration() const
{
	return !BaseUrl.IsEmpty() && !AccessToken.IsEmpty();
}

void UHomeAssistantClient::ValidateConnection()
{
	SendAuthorizedRequest(TEXT("ValidateConnection"), TEXT(""), TEXT("/api/"), TEXT("GET"), TEXT(""), &OnConnectionValidated);
}

void UHomeAssistantClient::FetchStates()
{
	SendAuthorizedRequest(TEXT("FetchStates"), TEXT(""), TEXT("/api/states"), TEXT("GET"), TEXT(""), &OnStatesReceived);
}

void UHomeAssistantClient::StartRealtime()
{
	if (!HasValidConfiguration())
	{
		OnTransportError.Broadcast(TEXT("Home Assistant 配置无效"));
		return;
	}

	bShuttingDown = false;
	bPendingRealtimeSubscription = true;
	bRealtimeActive = false;

	if (WebSocket.IsValid())
	{
		WebSocket->Close();
		WebSocket.Reset();
	}

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ReconnectTimerHandle);
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket(BuildWebSocketUrl(), TEXT(""));
	WebSocket->OnConnected().AddUObject(this, &UHomeAssistantClient::HandleRealtimeConnected);
	WebSocket->OnConnectionError().AddUObject(this, &UHomeAssistantClient::HandleRealtimeConnectionError);
	WebSocket->OnClosed().AddUObject(this, &UHomeAssistantClient::HandleRealtimeClosed);
	WebSocket->OnMessage().AddUObject(this, &UHomeAssistantClient::HandleRealtimeMessage);
	WebSocket->Connect();
}

void UHomeAssistantClient::StopRealtime()
{
	bPendingRealtimeSubscription = false;
	bShuttingDown = true;
	bRealtimeActive = false;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ReconnectTimerHandle);
	}

	if (WebSocket.IsValid())
	{
		WebSocket->Close();
		WebSocket.Reset();
	}

	OnRealtimeStateChanged.Broadcast(false);
}

void UHomeAssistantClient::CallService(const FString& InRequestId, const FName& InDomain, const FName& InService, const FString& InJsonPayload)
{
	const FString RelativePath = FString::Printf(TEXT("/api/services/%s/%s"), *InDomain.ToString(), *InService.ToString());
	SendAuthorizedRequest(TEXT("CallService"), InRequestId, RelativePath, TEXT("POST"), InJsonPayload, &OnServiceCalled);
}

void UHomeAssistantClient::SendAuthorizedRequest(const FString& InOperationName, const FString& InRequestId, const FString& InRelativePath, const FString& InVerb, const FString& InPayload, FHomeAssistantClientResponseNative* InDelegate)
{
	if (!HasValidConfiguration())
	{
		FHomeAssistantClientResponse Response;
		Response.OperationName = InOperationName;
		Response.RequestId = InRequestId;
		Response.ErrorMessage = TEXT("Home Assistant 配置无效");
		if (InDelegate)
		{
			InDelegate->Broadcast(Response);
		}
		return;
	}

	TWeakObjectPtr<UHomeAssistantClient> WeakThis(this);
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(BuildHttpUrl(InRelativePath));
	Request->SetVerb(InVerb);
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *AccessToken));
	Request->SetHeader(TEXT("Accept"), TEXT("application/json"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(TimeoutSeconds);

	if (!InPayload.IsEmpty())
	{
		Request->SetContentAsString(InPayload);
	}

	Request->OnProcessRequestComplete().BindLambda([WeakThis, InOperationName, InRequestId, InDelegate](FHttpRequestPtr InHttpRequest, FHttpResponsePtr InResponse, bool bConnectedSuccessfully)
	{
		FHomeAssistantClientResponse Response;
		Response.OperationName = InOperationName;
		Response.RequestId = InRequestId;
		Response.bSucceeded = bConnectedSuccessfully && InResponse.IsValid() && EHttpResponseCodes::IsOk(InResponse->GetResponseCode());
		Response.ResponseCode = InResponse.IsValid() ? InResponse->GetResponseCode() : 0;
		Response.Payload = InResponse.IsValid() ? InResponse->GetContentAsString() : FString();
		Response.ErrorMessage = Response.bSucceeded ? FString() : (InResponse.IsValid() ? InResponse->GetContentAsString() : TEXT("HTTP 请求失败"));

		if (WeakThis.IsValid() && (!bConnectedSuccessfully || !InResponse.IsValid()))
		{
			WeakThis->OnTransportError.Broadcast(Response.ErrorMessage);
		}

		if (InDelegate)
		{
			InDelegate->Broadcast(Response);
		}
	});

	Request->ProcessRequest();
}

FString UHomeAssistantClient::BuildHttpUrl(const FString& InRelativePath) const
{
	return FString::Printf(TEXT("%s%s"), *BaseUrl, *InRelativePath);
}

FString UHomeAssistantClient::BuildWebSocketUrl() const
{
	FString Url = BaseUrl;
	if (Url.StartsWith(TEXT("https://")))
	{
		Url = Url.Replace(TEXT("https://"), TEXT("wss://"));
	}
	else if (Url.StartsWith(TEXT("http://")))
	{
		Url = Url.Replace(TEXT("http://"), TEXT("ws://"));
	}
	return FString::Printf(TEXT("%s/api/websocket"), *Url);
}

void UHomeAssistantClient::HandleRealtimeConnected()
{
	// Home Assistant sends auth_required after the socket connects.
}

void UHomeAssistantClient::HandleRealtimeConnectionError(const FString& InErrorMessage)
{
	bRealtimeActive = false;
	OnTransportError.Broadcast(InErrorMessage);
	OnRealtimeStateChanged.Broadcast(false);
	ScheduleRealtimeReconnect();
}

void UHomeAssistantClient::HandleRealtimeClosed(const int32 InStatusCode, const FString& InReason, const bool bWasClean)
{
	bRealtimeActive = false;
	OnRealtimeStateChanged.Broadcast(false);

	if (!bWasClean && !InReason.IsEmpty())
	{
		OnTransportError.Broadcast(InReason);
	}

	ScheduleRealtimeReconnect();
}

void UHomeAssistantClient::HandleRealtimeMessage(const FString& InMessage)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InMessage);
	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		OnRealtimeMessage.Broadcast(InMessage);
		return;
	}

	const FString Type = JsonObject->GetStringField(TEXT("type"));
	if (Type == TEXT("auth_required"))
	{
		SendRealtimeAuthMessage();
		return;
	}

	if (Type == TEXT("auth_ok"))
	{
		if (bPendingRealtimeSubscription)
		{
			SendRealtimeSubscribeMessage();
		}
		return;
	}

	if (Type == TEXT("auth_invalid"))
	{
		bRealtimeActive = false;
		OnRealtimeStateChanged.Broadcast(false);
		OnTransportError.Broadcast(JsonObject->GetStringField(TEXT("message")));
		return;
	}

	if (Type == TEXT("result"))
	{
		const int32 Id = JsonObject->GetIntegerField(TEXT("id"));
		if (Id == RealtimeSubscriptionRequestId)
		{
			bRealtimeActive = JsonObject->GetBoolField(TEXT("success"));
			OnRealtimeStateChanged.Broadcast(bRealtimeActive);
		}
		return;
	}

	OnRealtimeMessage.Broadcast(InMessage);
}

void UHomeAssistantClient::SendRealtimeAuthMessage()
{
	if (WebSocket.IsValid())
	{
		const FString Message = FString::Printf(TEXT("{\"type\":\"auth\",\"access_token\":\"%s\"}"), *AccessToken);
		WebSocket->Send(Message);
	}
}

void UHomeAssistantClient::SendRealtimeSubscribeMessage()
{
	if (!WebSocket.IsValid())
	{
		return;
	}

	RealtimeSubscriptionRequestId = NextWebSocketMessageId++;
	const FString Message = FString::Printf(TEXT("{\"id\":%d,\"type\":\"subscribe_events\",\"event_type\":\"state_changed\"}"), RealtimeSubscriptionRequestId);
	WebSocket->Send(Message);
}

void UHomeAssistantClient::ScheduleRealtimeReconnect()
{
	if (bShuttingDown || !bAutoReconnect)
	{
		return;
	}

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(ReconnectTimerHandle, [WeakThis = TWeakObjectPtr<UHomeAssistantClient>(this)]()
		{
			if (WeakThis.IsValid())
			{
				WeakThis->StartRealtime();
			}
		}, 2.0f, false);
	}
}
