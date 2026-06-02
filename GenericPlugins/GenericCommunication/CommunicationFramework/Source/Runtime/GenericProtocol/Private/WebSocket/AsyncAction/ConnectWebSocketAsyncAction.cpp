// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WebSocket/AsyncAction/ConnectWebSocketAsyncAction.h"

#include "WebSocket/GenericWebSocket.h"

UConnectWebSocketAsyncAction* UConnectWebSocketAsyncAction::ConnectWebSocketWithConnection(UGenericWebSocket* InWebSocket, FGenericWebSocketConnection InWebSocketConnect)
{
	UConnectWebSocketAsyncAction* Action = NewObject<UConnectWebSocketAsyncAction>();
	Action->InitWebSocket(InWebSocket);
	if (UGenericWebSocket* WebSocket = Action->GetWebSocket())
	{
		WebSocket->ConnectWithConnection(InWebSocketConnect);
	}
	return Action;
}

UConnectWebSocketAsyncAction* UConnectWebSocketAsyncAction::ConnectWebSocketWithURL(UGenericWebSocket* InWebSocket, FString Host, int32 Port, EGenericWebSocketProtocol Protocol, TMap<FString, FString> Headers)
{
	UConnectWebSocketAsyncAction* Action = NewObject<UConnectWebSocketAsyncAction>();
	Action->InitWebSocket(InWebSocket);
	if (UGenericWebSocket* WebSocket = Action->GetWebSocket())
	{
		WebSocket->ConnectWithURL(Host, Port, Protocol, Headers);
	}
	return Action;
}

UConnectWebSocketAsyncAction* UConnectWebSocketAsyncAction::ConnectWebSocket(UGenericWebSocket* InWebSocket)
{
	UConnectWebSocketAsyncAction* Action = NewObject<UConnectWebSocketAsyncAction>();
	Action->InitWebSocket(InWebSocket);
	if (UGenericWebSocket* WebSocket = Action->GetWebSocket())
	{
		WebSocket->Connect();
	}
	return Action;
}

void UConnectWebSocketAsyncAction::OnConnectedInternal(UGenericWebSocket* WebSocket)
{
	Super::OnConnectedInternal(WebSocket);
	OnConnected.Broadcast(WebSocket,TEXT("Success"));
}

void UConnectWebSocketAsyncAction::OnConnectionErrorInternal(const FString& Error)
{
	Super::OnConnectionErrorInternal(Error);

	if (UGenericWebSocket* WebSocket = GetWebSocket())
	{
		OnConnectionError.Broadcast(WebSocket, Error);
	}
}
