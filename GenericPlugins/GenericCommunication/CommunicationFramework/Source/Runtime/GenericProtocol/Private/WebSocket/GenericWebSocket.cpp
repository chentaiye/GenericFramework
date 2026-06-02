// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WebSocket/GenericWebSocket.h"

#include "GenericJsonObject.h"
#include "IWebSocket.h"
#include "ProtocolType.h"
#include "WebSocketsModule.h"
#include "WebSocket/BPFunctions_WebSocket.h"

UGenericWebSocket::UGenericWebSocket(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UGenericWebSocket* UGenericWebSocket::CreateWebSocket()
{
	return NewObject<UGenericWebSocket>();
}

bool UGenericWebSocket::IsConnected() const
{
	return WebSocket.IsValid() ? WebSocket->IsConnected() : false;
}

void UGenericWebSocket::ConnectWithConnection(const FGenericWebSocketConnection& InWebSocketConnect)
{
	if (!InWebSocketConnect.IsValid())
	{
		GenericLOG(GenericLogWebSocket, Error, TEXT("Invalid WebSocketConnect"));
		return;
	}

	WebSocketConnect = InWebSocketConnect;
	ConnectWithURL(WebSocketConnect.Host, WebSocketConnect.Port, WebSocketConnect.Protocol, WebSocketConnect.Headers);
}

void UGenericWebSocket::ConnectWithURL(const FString Host, const int32 Port, const EGenericWebSocketProtocol Protocol, const TMap<FString, FString>& Headers)
{
	WebSocketConnect.Host = Host;
	WebSocketConnect.Port = Port;
	WebSocketConnect.Protocol = Protocol;
	WebSocketConnect.Headers = Headers;

	if (IsConnected())
	{
		WebSocketCache = FWebSocketsModule::Get().CreateWebSocket(WebSocketConnect.GetUrl(), ConvertToWebSocketProtocolString(WebSocketConnect.Protocol), WebSocketConnect.Headers);
		Close();
	}
	else
	{
		if (WebSocket.IsValid())
		{
			UnBindWebSocketDelegate();
			WebSocket.Reset();
		}

		WebSocket = FWebSocketsModule::Get().CreateWebSocket(WebSocketConnect.GetUrl(), ConvertToWebSocketProtocolString(WebSocketConnect.Protocol), WebSocketConnect.Headers);
		Connect();
	}
}

void UGenericWebSocket::Connect()
{
	if (WebSocket.IsValid())
	{
		WebSocketConnect.ReconnectionAttempts = 0;

		BindWebSocketDelegate();
		WebSocket->Connect();
	}
}

void UGenericWebSocket::Close(const int32 Code, FString Reason)
{
	if (IsConnected())
	{
		WebSocket->Close(Code, Reason);
	}
	else
	{
		GenericLOG(GenericLogWebSocket, Warning, TEXT("WebSocket is not connected"));
	}
}

void UGenericWebSocket::SendMessage(const FString& Message)
{
	if (IsConnected())
	{
		WebSocket->Send(Message);
	}
	else
	{
		GenericLOG(GenericLogWebSocket, Warning, TEXT("WebSocket is not connected"));
	}
}

void UGenericWebSocket::SendJsonMessage(UGenericJsonObject* JsonObject)
{
	if (!IsValid(JsonObject))
	{
		GenericLOG(GenericLogWebSocket, Warning, TEXT("JsonObject Is InValid"));
		return;
	}

	FString Message;
	if (JsonObject->EncodeJson(Message))
	{
		SendMessage(Message);
	}
}

void UGenericWebSocket::SendBinaryMessage(const TArray<uint8>& Message, const bool bIsBinary)
{
	if (IsConnected())
	{
		WebSocket->Send(Message.GetData(), sizeof(uint8) * Message.Num(), bIsBinary);
	}
	else
	{
		GenericLOG(GenericLogWebSocket, Warning, TEXT("WebSocket is not connected"));
	}
}

void UGenericWebSocket::BindWebSocketDelegate()
{
	if (WebSocket.IsValid())
	{
		WebSocket->OnConnected().AddUObject(this, &UGenericWebSocket::OnConnected);
		WebSocket->OnConnectionError().AddUObject(this, &UGenericWebSocket::OnConnectionError);
		WebSocket->OnRawMessage().AddUObject(this, &UGenericWebSocket::OnRawMessage);
		WebSocket->OnBinaryMessage().AddUObject(this, &UGenericWebSocket::OnBinaryMessage);
		WebSocket->OnMessage().AddUObject(this, &UGenericWebSocket::OnMessage);
		WebSocket->OnMessageSent().AddUObject(this, &UGenericWebSocket::OnMessageSent);
		WebSocket->OnClosed().AddUObject(this, &UGenericWebSocket::OnClosed);
	}
}

void UGenericWebSocket::UnBindWebSocketDelegate() const
{
	if (WebSocket.IsValid())
	{
		WebSocket->OnConnected().RemoveAll(this);
		WebSocket->OnConnectionError().RemoveAll(this);
		WebSocket->OnRawMessage().RemoveAll(this);
		WebSocket->OnBinaryMessage().RemoveAll(this);
		WebSocket->OnMessage().RemoveAll(this);
		WebSocket->OnMessageSent().RemoveAll(this);
		WebSocket->OnClosed().RemoveAll(this);
	}
}

FString UGenericWebSocket::GetHost() const
{
	return WebSocketConnect.Host;
}

void UGenericWebSocket::SetHost(FString InHost)
{
	WebSocketConnect.Host = InHost;
}

int32 UGenericWebSocket::GetPort() const
{
	return WebSocketConnect.Port;
}

void UGenericWebSocket::SetPort(int32 InPort)
{
	WebSocketConnect.Port = InPort;
}

EGenericWebSocketProtocol UGenericWebSocket::GetProtocol() const
{
	return WebSocketConnect.Protocol;
}

void UGenericWebSocket::SetProtocol(EGenericWebSocketProtocol InProtocol)
{
	WebSocketConnect.Protocol = InProtocol;
}

void UGenericWebSocket::AddHeader(const FString& Header, const FString& Value)
{
	WebSocketConnect.Headers.Add(Header, Value);
}

void UGenericWebSocket::AddHeaders(TMap<FString, FString> Headers)
{
	WebSocketConnect.Headers.Append(Headers);
}

void UGenericWebSocket::RemoveHeader(const FString& Header)
{
	WebSocketConnect.Headers.Remove(Header);
}

void UGenericWebSocket::RemoveHeaders(TArray<FString> Headers)
{
	for (auto& Header : Headers)
	{
		RemoveHeader(Header);
	}
}

TMap<FString, FString> UGenericWebSocket::GetHeaders()
{
	return WebSocketConnect.Headers;
}

void UGenericWebSocket::SetHeaders(TMap<FString, FString> Headers)
{
	WebSocketConnect.Headers = Headers;
}

int32 UGenericWebSocket::GetMaxReconnectCount() const
{
	return WebSocketConnect.MaxReconnectionAttempts;
}

void UGenericWebSocket::SetMaxReconnectCount(int32 MaxReconnectCount)
{
	WebSocketConnect.MaxReconnectionAttempts = MaxReconnectCount;
}

void UGenericWebSocket::OnConnected()
{
	GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Connected [URL = %s]"), *WebSocketConnect.GetUrl());
	OnConnectedEvent.Broadcast(this);
}

void UGenericWebSocket::OnConnectionError(const FString& Error)
{
	GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Connection Error [URL = %s] [Error = %s]"), *WebSocketConnect.GetUrl(), *Error);
	OnConnectionErrorEvent.Broadcast(Error);
	Reconnect();
}

void UGenericWebSocket::OnRawMessage(const void* Data, SIZE_T Size, SIZE_T BytesRemaining)
{
	const TArray<uint8> ArrayData(static_cast<const uint8*>(Data), Size / sizeof(uint8));
	OnRawMessageEvent.Broadcast(ArrayData, BytesRemaining);
}

void UGenericWebSocket::OnBinaryMessage(const void* Data, SIZE_T Size, bool bIsLastFragment)
{
	const TArray<uint8> ArrayData(static_cast<const uint8*>(Data), Size / sizeof(uint8));
	OnBinaryMessageEvent.Broadcast(ArrayData, bIsLastFragment);
}

void UGenericWebSocket::OnMessage(const FString& Message)
{
	GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Received [URL = %s] [Message = %s]"), *WebSocketConnect.GetUrl(), *Message);
	OnMessageEvent.Broadcast(Message);
}

void UGenericWebSocket::OnMessageSent(const FString& Message)
{
	GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Sent [URL = %s] [Message = %s]"), *WebSocketConnect.GetUrl(), *Message);
	OnMessageSentEvent.Broadcast(Message);
}

void UGenericWebSocket::OnClosed(int32 Status, const FString& Reason, bool bWasClean)
{
	GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Closed [URL = %s]"), *WebSocketConnect.GetUrl());

	OnCloseEvent.Broadcast(Status, Reason, bWasClean);
	UnBindWebSocketDelegate();

	if (WebSocketCache.IsValid())
	{
		WebSocket = WebSocketCache;
		WebSocketCache = nullptr;
		Connect();
	}
}

void UGenericWebSocket::Reconnect()
{
	WebSocketConnect.ReconnectionAttempts++;
	if (WebSocketConnect.MaxReconnectionAttempts < 0 || WebSocketConnect.ReconnectionAttempts < WebSocketConnect.MaxReconnectionAttempts)
	{
		if (WebSocketConnect.ReconnectIntervalTime == 0.f)
		{
			ReconnectInternal();
		}
		else
		{
			if (UWorld* World = GetWorld())
			{
				FTimerHandle TimerHandle;
				World->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateUObject(this, &UGenericWebSocket::ReconnectInternal), WebSocketConnect.ReconnectIntervalTime, false);

				GenericLOG(GenericLogWebSocket, Log, TEXT("Reconnect To %s After %fs "), *WebSocketConnect.GetUrl(), WebSocketConnect.ReconnectIntervalTime);
			}
			else
			{
				GenericLOG(GenericLogWebSocket, Warning, TEXT("Invalid World To Reconnect, Reconnect Will Start Immediately"));
				ReconnectInternal();
			}
		}
	}
}

void UGenericWebSocket::ReconnectInternal()
{
	if (WebSocket.IsValid())
	{
		GenericLOG(GenericLogWebSocket, Log, TEXT("WebSocket Reconnect [URL = %s]"), *WebSocketConnect.GetUrl());
		WebSocket->Connect();
	}
}
