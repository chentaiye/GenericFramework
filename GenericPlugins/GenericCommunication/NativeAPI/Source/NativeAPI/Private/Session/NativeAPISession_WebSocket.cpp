// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPISession_WebSocket.h"

#include "Engine/Engine.h"
#include "NativeAPILog.h"
#include "NativeAPISubsystem.h"
#include "NativeAPITypes.h"
#include "NativeAPIUtilities.h"
#include "Settings/NativeAPIWorldSettings.h"
#include "WebSocketsModule.h"
#include "Type/DebugType.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "WebSocket/BPFunctions_WebSocket.h"

#if WITH_WEBSOCKETS
#include "IWebSocket.h"
#endif

namespace
{
	const UNativeAPIWorldSettings* GetActiveNativeAPIWorldSettings()
	{
		const UNativeAPISubsystem* NativeAPISubsystem = GEngine ? GEngine->GetEngineSubsystem<UNativeAPISubsystem>() : nullptr;
		return NativeAPISubsystem ? NativeAPISubsystem->GetActiveWorldSettings() : nullptr;
	}
}

FNativeAPISession_WebSocket::FNativeAPISession_WebSocket()
	: WebSocket(nullptr)
{
}

FName FNativeAPISession_WebSocket::GetSessionName()
{
	static FName SessionName(TEXT("WebSocket"));
	return SessionName;
}

bool FNativeAPISession_WebSocket::StartSession()
{
	const UNativeAPIWorldSettings* Settings = GetActiveNativeAPIWorldSettings();
	if (Settings == nullptr)
	{
		return false;
	}

	if (!Settings->bSupportWebSocket)
	{
		return false;
	}

	if (WebSocket.IsValid())
	{
		return true;
	}

	Connection = Settings->Connect;

	if (Connection.IsValid())
	{
#if WITH_WEBSOCKETS
		WebSocket = FWebSocketsModule::Get().CreateWebSocket(Connection.GetUrl(), ConvertToWebSocketProtocolString(Connection.Protocol), Connection.Headers);

		if (WebSocket.IsValid())
		{
			WebSocket->OnConnected().AddRaw(this, &FNativeAPISession_WebSocket::HandleOnWebSocketConnection);
			WebSocket->OnConnectionError().AddRaw(this, &FNativeAPISession_WebSocket::HandleOnWebSocketConnectionError);
			WebSocket->OnMessage().AddRaw(this, &FNativeAPISession_WebSocket::HandleOnWebSocketMessage);
			WebSocket->Connect();
			return true;
		}
#endif
		return false;
	}

	return false;
}

void FNativeAPISession_WebSocket::EndSession()
{
#if WITH_WEBSOCKETS
	if (WebSocket.IsValid())
	{
		WebSocket->OnConnected().RemoveAll(this);
		WebSocket->OnConnectionError().RemoveAll(this);
		WebSocket->OnMessage().RemoveAll(this);

		if (WebSocket->IsConnected())
		{
			WebSocket->Close();
		}

		WebSocket.Reset();
	}
#endif
}

void FNativeAPISession_WebSocket::HandleOnWebSocketConnection()
{
	GenericLOG(LogNativeAPI, Warning, TEXT("Native API WebSocket Session Connect, [URL] %s"), *Connection.GetUrl())
}

void FNativeAPISession_WebSocket::HandleOnWebSocketConnectionError(const FString& Error)
{
	GenericLOG(LogNativeAPI, Warning, TEXT("Native API WebSocket Session Connect Error, [URL] %s, [Error] %s"), *Connection.GetUrl(), *Error);

	const UNativeAPIWorldSettings* Settings = GetActiveNativeAPIWorldSettings();
	if (Settings != nullptr && Settings->bConnectWebSocketUntilSuccess && WebSocket.IsValid())
	{
		WebSocket->Connect();
	}
	else
	{
		if (WebSocket.IsValid())
		{
			WebSocket->OnConnected().RemoveAll(this);
			WebSocket->OnConnectionError().RemoveAll(this);
			WebSocket->OnMessage().RemoveAll(this);
		}

		WebSocket.Reset();
	}
}

void FNativeAPISession_WebSocket::HandleOnWebSocketMessage(const FString& InMessage)
{
	TSharedPtr<FJsonObject> JsonObject;
	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(InMessage);
	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("无效的NativeAPI WebSocket 消息!"))
		return;
	}

	FNativeAPIPayload Payload;
	if (!FNativeAPIUtilities::ConvertNativeAPIJsonToPayload(JsonObject, Payload) || !Payload.IsValid())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("无法转换 WebSocket 信息 为 Native API Payload!"))
		return;
	}

	NotifyReceiveNativePayload(Payload);
}
