// Copyright ChenTaiye 2025. All Rights Reserved.

#include "AsyncAction/BroadcastGameplayMessageAsyncAction.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameplayMessageSubsystem.h"
#include "UObject/Stack.h"
#include "UObject/UnrealType.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(BroadcastGameplayMessageAsyncAction)

UBroadcastGameplayMessageAsyncAction* UBroadcastGameplayMessageAsyncAction::BroadcastGameplayMessage(UObject* WorldContextObject, FGameplayTag Channel, const int32& Message)
{
	checkNoEntry();
	return nullptr;
}

UBroadcastGameplayMessageAsyncAction* UBroadcastGameplayMessageAsyncAction::CreateAction(UObject* WorldContextObject, FGameplayTag Channel, const UScriptStruct* MessageStruct, const void* MessageBytes)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if ((World == nullptr) || (MessageStruct == nullptr) || (MessageBytes == nullptr))
	{
		return nullptr;
	}

	UBroadcastGameplayMessageAsyncAction* Action = NewObject<UBroadcastGameplayMessageAsyncAction>();
	Action->WorldPtr = World;
	Action->ChannelToBroadcast = Channel;
	Action->MessageStructType = const_cast<UScriptStruct*>(MessageStruct);

	const int32 MessageSize = FMath::Max(MessageStruct->GetStructureSize(), 1);
	Action->MessagePayload.SetNumUninitialized(MessageSize);
	MessageStruct->InitializeStruct(Action->MessagePayload.GetData());
	MessageStruct->CopyScriptStruct(Action->MessagePayload.GetData(), MessageBytes);

	Action->RegisterWithGameInstance(World);
	return Action;
}

DEFINE_FUNCTION(UBroadcastGameplayMessageAsyncAction::execBroadcastGameplayMessage)
{
	P_GET_OBJECT(UObject, WorldContextObject);
	P_GET_STRUCT(FGameplayTag, Channel);

	Stack.MostRecentPropertyAddress = nullptr;
	Stack.StepCompiledIn<FStructProperty>(nullptr);
	void* MessagePtr = Stack.MostRecentPropertyAddress;
	FStructProperty* MessageProperty = CastField<FStructProperty>(Stack.MostRecentProperty);

	P_FINISH;

	P_NATIVE_BEGIN;
	*(UBroadcastGameplayMessageAsyncAction**)RESULT_PARAM =
		((MessageProperty != nullptr) && (MessageProperty->Struct != nullptr) && (MessagePtr != nullptr))
			? UBroadcastGameplayMessageAsyncAction::CreateAction(WorldContextObject, Channel, MessageProperty->Struct, MessagePtr)
			: nullptr;
	P_NATIVE_END;
}

void UBroadcastGameplayMessageAsyncAction::Activate()
{
	if (UWorld* World = WorldPtr.Get())
	{
		if (UGameplayMessageSubsystem::HasInstance(World))
		{
			if (UScriptStruct* MessageStruct = MessageStructType.Get())
			{
				if (MessagePayload.Num() > 0)
				{
					UGameplayMessageSubsystem::Get(World).BroadcastMessageStruct(ChannelToBroadcast, MessageStruct, MessagePayload.GetData());
					Completed.Broadcast();
					SetReadyToDestroy();
					return;
				}
			}
		}
	}

	SetReadyToDestroy();
}

void UBroadcastGameplayMessageAsyncAction::SetReadyToDestroy()
{
	ResetMessagePayload();

	Super::SetReadyToDestroy();
}

void UBroadcastGameplayMessageAsyncAction::ResetMessagePayload()
{
	if (UScriptStruct* MessageStruct = MessageStructType.Get())
	{
		if (MessagePayload.Num() > 0)
		{
			MessageStruct->DestroyStruct(MessagePayload.GetData());
			MessagePayload.Reset();
		}
	}
	else
	{
		MessagePayload.Reset();
	}

	MessageStructType = nullptr;
}
