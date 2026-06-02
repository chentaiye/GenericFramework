// Copyright ChenTaiye 2026. All Rights Reserved.

#include "BPFunctions/BPFunctions_IOT.h"

#include "Subsystem/IOTSubsystem.h"

UIOTSubsystem* UBPFunctions_IOT::GetIOTSubsystem(const UObject* WorldContextObject)
{
	return UIOTSubsystem::Get(WorldContextObject);
}

FIOTCommandRequest UBPFunctions_IOT::MakeCommandRequest(const FString& DeviceId, const EIOTCapabilityKind CapabilityKind, const FString& CommandName, const TMap<FString, FString>& Parameters)
{
	FIOTCommandRequest Request;
	Request.DeviceId = DeviceId;
	Request.CapabilityKind = CapabilityKind;
	Request.CommandName = CommandName;
	Request.Parameters = Parameters;
	return Request;
}

FString UBPFunctions_IOT::MakeIOTDeviceId(const FString& EntityId)
{
	return FString::Printf(TEXT("ha:%s"), *EntityId);
}
