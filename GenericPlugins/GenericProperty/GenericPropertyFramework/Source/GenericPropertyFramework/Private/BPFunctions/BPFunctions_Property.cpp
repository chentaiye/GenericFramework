#include "GenericPropertyFramework/Public/BPFunctions/BPFunctions_Property.h"

#include "Misc/EngineVersionComparison.h"
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
#include "Blueprint/BlueprintExceptionInfo.h"
#else
#include "UObject/Script.h"
#endif
#include "Core/GenericProperty.h"
#include "Data/GenericPropertyDataSourceCollection.h"
#include "Model/GenericPropertyProxy.h"
#include "Templates/GenericPropertyValueTemplate.h"
#include "UI/GenericPropertyRowValueSpawner.h"
#include "UI/GenericPropertyValue.h"

#define LOCTEXT_NAMESPACE "GenericPropertyBlueprintLibrary"

namespace
{
	bool ExportReflectedValueToString(FProperty* InValueProperty, void* InValuePtr, FString& OutSerializedValue)
	{
		if (InValueProperty == nullptr || InValuePtr == nullptr)
		{
			return false;
		}

		InValueProperty->ExportTextItem_Direct(OutSerializedValue, InValuePtr, nullptr, nullptr, PPF_None);
		return true;
	}

	template<typename TObjectType>
	bool CommitReflectedValue(TObjectType* InTarget, FProperty* InValueProperty, void* InValuePtr)
	{
		if (InTarget == nullptr)
		{
			return false;
		}

		FString SerializedValue;
		if (!ExportReflectedValueToString(InValueProperty, InValuePtr, SerializedValue))
		{
			return false;
		}

		return GenericPropertyFramework::Templates::CommitSerializedValue(*InTarget, SerializedValue);
	}
}

UGenericPropertyProxy* UBPFunctions_Property::CreatePropertyProxy(UObject* Outer, const TArray<UObject*>& Targets, const FGenericPropertyPanelOptions& Options, TSubclassOf<UGenericPropertyDataSourceCollection> DataSourceClass)
{
	UObject* ProxyOuter = Outer != nullptr ? Outer : GetTransientPackage();
	UGenericPropertyProxy* Proxy = NewObject<UGenericPropertyProxy>(ProxyOuter);
	if (Proxy != nullptr)
	{
		Proxy->Initialize(Targets, Options, DataSourceClass);
	}

	return Proxy;
}

bool UBPFunctions_Property::CommitPropertyValue(UGenericProperty* Property, const int32& Value)
{
	return false;
}

DEFINE_FUNCTION(UBPFunctions_Property::execCommitPropertyValue)
{
	P_GET_OBJECT(UGenericProperty, Property);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProperty = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (ValueProperty == nullptr || ValuePtr == nullptr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(EBlueprintExceptionType::AccessViolation, LOCTEXT("CommitPropertyValueMissingInput", "Failed to resolve the input parameter for CommitPropertyValue."));
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
		*static_cast<bool*>(RESULT_PARAM) = false;
		return;
	}

	bool bResult = false;
	P_NATIVE_BEGIN;
	bResult = CommitReflectedValue(Property, ValueProperty, ValuePtr);
	P_NATIVE_END;
	*static_cast<bool*>(RESULT_PARAM) = bResult;
}

bool UBPFunctions_Property::CommitPropertyValueWidget(UGenericPropertyValue* ValueWidget, const int32& Value)
{
	return false;
}

DEFINE_FUNCTION(UBPFunctions_Property::execCommitPropertyValueWidget)
{
	P_GET_OBJECT(UGenericPropertyValue, ValueWidget);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProperty = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (ValueProperty == nullptr || ValuePtr == nullptr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(EBlueprintExceptionType::AccessViolation, LOCTEXT("CommitPropertyValueWidgetMissingInput", "Failed to resolve the input parameter for CommitPropertyValueWidget."));
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
		*static_cast<bool*>(RESULT_PARAM) = false;
		return;
	}

	bool bResult = false;
	P_NATIVE_BEGIN;
	bResult = CommitReflectedValue(ValueWidget, ValueProperty, ValuePtr);
	P_NATIVE_END;
	*static_cast<bool*>(RESULT_PARAM) = bResult;
}

bool UBPFunctions_Property::CommitPropertyValueSpawner(UGenericPropertyRowValueSpawner* ValueSpawner, const int32& Value)
{
	return false;
}

DEFINE_FUNCTION(UBPFunctions_Property::execCommitPropertyValueSpawner)
{
	P_GET_OBJECT(UGenericPropertyRowValueSpawner, ValueSpawner);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProperty = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (ValueProperty == nullptr || ValuePtr == nullptr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(EBlueprintExceptionType::AccessViolation, LOCTEXT("CommitPropertyValueSpawnerMissingInput", "Failed to resolve the input parameter for CommitPropertyValueSpawner."));
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
		*static_cast<bool*>(RESULT_PARAM) = false;
		return;
	}

	bool bResult = false;
	P_NATIVE_BEGIN;
	bResult = CommitReflectedValue(ValueSpawner, ValueProperty, ValuePtr);
	P_NATIVE_END;
	*static_cast<bool*>(RESULT_PARAM) = bResult;
}

#undef LOCTEXT_NAMESPACE
