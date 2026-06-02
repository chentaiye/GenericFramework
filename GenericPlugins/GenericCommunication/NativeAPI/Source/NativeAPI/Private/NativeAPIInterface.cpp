// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPIInterface.h"
#include "NativeAPILog.h"
#include "NativeAPITypes.h"
#include "NativeAPIUtilities.h"
#include "Type/DebugType.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

void INativeAPIInterface::SendSimulationNativeAPIMessage(const FString& InMessage) const
{
	if (InMessage.IsEmpty())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Send simulation native api fail! json string can not be empty!"))
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(InMessage);

	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Send simulation native api fail! invalid json string."))
		return;
	}

	if (!FNativeAPIUtilities::IsNativeAPIJson(JsonObject))
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Send simulation native api fail! message is not a native api json."))
		return;
	}

	this->SendSimulationNativeAPIMessage_Internal(JsonObject);
}

void INativeAPIInterface::SendSimulationNativeAPIMessage_Internal(const TSharedPtr<FJsonObject>& InJsonObject) const
{
	if (!InJsonObject.IsValid())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("Send simulation native api fail, invalid json object."))
		return;
	}

	FNativeAPIPayload Payload;

	if (!FNativeAPIUtilities::ConvertNativeAPIJsonToPayload(InJsonObject, Payload) || !Payload.IsValid())
	{
		GenericLOG(LogNativeAPI, Warning, TEXT("解析 Native API Json 失败!"))
		return;
	}

	this->ProcessingNativeAPI(Payload);
}

FString INativeAPIEntityInterface::GetEntity() const
{
	return TEXT("");
}

UClass* INativeAPIEntityInterface::GetEntityClass() const
{
	const auto ThisObject = Cast<UObject>(this);
	if (ThisObject != nullptr)
	{
		return ThisObject->GetClass();
	}

	return nullptr;
}

FString INativeAPIEntityInterface::GetEntityPath() const
{
	const auto ThisObject = Cast<UObject>(this);

	if (ThisObject != nullptr)
	{
		return ThisObject->GetPathName();
	}

	return TEXT("");
}
