// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericActionWidget.h"

#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "Subsystem/GenericActionSubsystem.h"
#include "UObject/StructOnScope.h"
#include "UObject/UnrealType.h"
#include "WidgetType.h"

namespace
{
	bool ShouldAttemptActionAutoRegistration(const UGenericActionWidget* InWidget)
	{
		if (!IsValid(InWidget) || InWidget->IsDesignTime())
		{
			return false;
		}

		const UWorld* World = InWidget->GetWorld();
		return World && World->IsGameWorld();
	}

	FString SanitizeActionTagForFunctionName(FGameplayTag InActionTag)
	{
		FString SanitizedTag = InActionTag.ToString();
		for (TCHAR& Character : SanitizedTag)
		{
			if (!FChar::IsAlnum(Character) && Character != TEXT('_'))
			{
				Character = TEXT('_');
			}
		}

		return SanitizedTag;
	}

	FProperty* FindEventParameter(const UFunction* InFunction, FName InParameterName)
	{
		if (!InFunction)
		{
			return nullptr;
		}

		for (TFieldIterator<FProperty> PropertyIt(InFunction); PropertyIt && PropertyIt->HasAnyPropertyFlags(CPF_Parm); ++PropertyIt)
		{
			FProperty* Property = *PropertyIt;
			if (Property && Property->GetFName() == InParameterName)
			{
				return Property;
			}
		}

		return nullptr;
	}

	FProperty* FindFirstEnumEventParameter(const UFunction* InFunction)
	{
		if (!InFunction)
		{
			return nullptr;
		}

		for (TFieldIterator<FProperty> PropertyIt(InFunction); PropertyIt && PropertyIt->HasAnyPropertyFlags(CPF_Parm); ++PropertyIt)
		{
			FProperty* Property = *PropertyIt;
			if (CastField<FEnumProperty>(Property) || CastField<FByteProperty>(Property))
			{
				return Property;
			}
		}

		return nullptr;
	}

	FStructProperty* FindStructEventParameter(const UFunction* InFunction, FName InParameterName, const UScriptStruct* InStruct)
	{
		if (FStructProperty* NamedProperty = CastField<FStructProperty>(FindEventParameter(InFunction, InParameterName)))
		{
			if (NamedProperty->Struct == InStruct)
			{
				return NamedProperty;
			}
		}

		if (!InFunction)
		{
			return nullptr;
		}

		for (TFieldIterator<FProperty> PropertyIt(InFunction); PropertyIt && PropertyIt->HasAnyPropertyFlags(CPF_Parm); ++PropertyIt)
		{
			FStructProperty* StructProperty = CastField<FStructProperty>(*PropertyIt);
			if (StructProperty && StructProperty->Struct == InStruct)
			{
				return StructProperty;
			}
		}

		return nullptr;
	}

	FFloatProperty* FindFloatEventParameter(const UFunction* InFunction, FName InParameterName, int32 InFallbackFloatIndex)
	{
		if (FFloatProperty* NamedProperty = CastField<FFloatProperty>(FindEventParameter(InFunction, InParameterName)))
		{
			return NamedProperty;
		}

		if (!InFunction)
		{
			return nullptr;
		}

		int32 FloatIndex = 0;
		for (TFieldIterator<FProperty> PropertyIt(InFunction); PropertyIt && PropertyIt->HasAnyPropertyFlags(CPF_Parm); ++PropertyIt)
		{
			FFloatProperty* FloatProperty = CastField<FFloatProperty>(*PropertyIt);
			if (FloatProperty && FloatIndex++ == InFallbackFloatIndex)
			{
				return FloatProperty;
			}
		}

		return nullptr;
	}
}

UGenericActionWidget::UGenericActionWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ActionTag = TAG_GameplayUI_Action;
}

FName UGenericActionWidget::MakeActionTagEventFunctionName(FGameplayTag InActionTag)
{
	if (!InActionTag.IsValid())
	{
		return NAME_None;
	}

	return FName(*FString::Printf(TEXT("GameplayUIAction__%s"), *SanitizeActionTagForFunctionName(InActionTag)));
}

bool UGenericActionWidget::ExecuteActionTagEvent(FGameplayTag InActionTag, EGenericActionTriggerEvent InTriggerEvent, const FGenericActionInputEventData& InEventData)
{
	const FName FunctionName = MakeActionTagEventFunctionName(InActionTag);
	if (FunctionName.IsNone())
	{
		return false;
	}

	UFunction* EventFunction = FindFunction(FunctionName);
	if (!EventFunction)
	{
		return false;
	}

	FStructOnScope Parameters(EventFunction);
	uint8* ParameterMemory = Parameters.GetStructMemory();
	if (!ParameterMemory)
	{
		return false;
	}

	if (FProperty* TriggerEventProperty = FindEventParameter(EventFunction, TEXT("TriggerEvent")))
	{
		void* TriggerEventValue = TriggerEventProperty->ContainerPtrToValuePtr<void>(ParameterMemory);
		if (FEnumProperty* EnumProperty = CastField<FEnumProperty>(TriggerEventProperty))
		{
			EnumProperty->GetUnderlyingProperty()->SetIntPropertyValue(TriggerEventValue, static_cast<int64>(InTriggerEvent));
		}
		else if (FByteProperty* ByteProperty = CastField<FByteProperty>(TriggerEventProperty))
		{
			ByteProperty->SetPropertyValue(TriggerEventValue, static_cast<uint8>(InTriggerEvent));
		}
	}
	else if (FProperty* FallbackTriggerEventProperty = FindFirstEnumEventParameter(EventFunction))
	{
		void* TriggerEventValue = FallbackTriggerEventProperty->ContainerPtrToValuePtr<void>(ParameterMemory);
		if (FEnumProperty* EnumProperty = CastField<FEnumProperty>(FallbackTriggerEventProperty))
		{
			EnumProperty->GetUnderlyingProperty()->SetIntPropertyValue(TriggerEventValue, static_cast<int64>(InTriggerEvent));
		}
		else if (FByteProperty* ByteProperty = CastField<FByteProperty>(FallbackTriggerEventProperty))
		{
			ByteProperty->SetPropertyValue(TriggerEventValue, static_cast<uint8>(InTriggerEvent));
		}
	}

	if (FStructProperty* ActionTagProperty = FindStructEventParameter(EventFunction, TEXT("ActionTag"), FGameplayTag::StaticStruct()))
	{
		*ActionTagProperty->ContainerPtrToValuePtr<FGameplayTag>(ParameterMemory) = InEventData.ActionTag;
	}

	if (FStructProperty* KeyProperty = FindStructEventParameter(EventFunction, TEXT("Key"), FKey::StaticStruct()))
	{
		*KeyProperty->ContainerPtrToValuePtr<FKey>(ParameterMemory) = InEventData.Key;
	}

	if (FFloatProperty* ActionValueProperty = FindFloatEventParameter(EventFunction, TEXT("ActionValue"), 0))
	{
		ActionValueProperty->SetPropertyValue_InContainer(ParameterMemory, InEventData.ActionValue);
	}

	if (FFloatProperty* ElapsedTimeProperty = FindFloatEventParameter(EventFunction, TEXT("ElapsedTime"), 1))
	{
		ElapsedTimeProperty->SetPropertyValue_InContainer(ParameterMemory, InEventData.ElapsedTime);
	}

	if (FFloatProperty* TriggeredTimeProperty = FindFloatEventParameter(EventFunction, TEXT("TriggeredTime"), 2))
	{
		TriggeredTimeProperty->SetPropertyValue_InContainer(ParameterMemory, InEventData.TriggeredTime);
	}

	ProcessEvent(EventFunction, ParameterMemory);
	return true;
}

void UGenericActionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!ShouldAttemptActionAutoRegistration(this))
	{
		return;
	}

	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(GetOwningLocalPlayer()))
	{
		ActionSubsystem->RegisterActionWidget(this);
	}
	else
	{
		UE_LOG(GenericLogUI, Warning, TEXT("GenericActionWidget '%s' failed to auto register because GenericActionSubsystem is missing."), *GetName());
	}
}

void UGenericActionWidget::NativeDestruct()
{
	if (ShouldAttemptActionAutoRegistration(this))
	{
		if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(GetOwningLocalPlayer()))
		{
			ActionSubsystem->UnregisterActionWidget(this);
		}
	}

	Super::NativeDestruct();
}
