// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WebSocket/WebSocketType.h"

bool FGenericWebSocketConnection::IsValid() const
{
	return !Host.IsEmpty() && Port != INDEX_NONE;
}

FString FGenericWebSocketConnection::GetUrl() const
{
	FStringFormatNamedArguments Arguments;
	Arguments.Add(TEXT("PROTOCOL"), ConvertToWebSocketProtocolString(Protocol));
	Arguments.Add(TEXT("HOST"), Host);
	Arguments.Add(TEXT("PORT"), FString::FromInt(Port));

	return FString::Format(TEXT("{PROTOCOL}://{HOST}:{PORT}"), Arguments);
}
