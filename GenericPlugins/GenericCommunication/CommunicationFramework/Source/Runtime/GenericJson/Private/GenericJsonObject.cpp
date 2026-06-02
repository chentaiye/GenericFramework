// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericJsonObject.h"

#include "BPFunctions_Json.h"
#include "JsonType.h"
#include "BPFunctions/BPFunctions_Desktop.h"
#include "StaticFunctions/StaticFunctions_Convert.h"

// TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> 紧凑Json策略，无多余空格和换行
// TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> 格式化Json策略，有缩进和换行

typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FJsonWriterFactory;
typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FJsonWriter;

UGenericJsonObject::UGenericJsonObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Reset();
}

UGenericJsonObject* UGenericJsonObject::ConstructJsonObject(UObject* WorldContextObject)
{
	return NewObject<UGenericJsonObject>(WorldContextObject);
}

void UGenericJsonObject::Reset()
{
	if (JsonObject.IsValid())
	{
		JsonObject.Reset();
	}

	SetJsonObject(MakeShareable(new FJsonObject()));
}

bool UGenericJsonObject::EncodeJsonToFile(FString FileName)
{
	FString EncodedJsonString;
	return EncodeJson(EncodedJsonString) && UBPFunctions_Desktop::WriteStringToFile(EncodedJsonString, FileName);
}

FString UGenericJsonObject::EncodeJsonToString()
{
	FString EncodedJsonString;
	return EncodeJson(EncodedJsonString) ? EncodedJsonString : FString();
}

bool UGenericJsonObject::EncodeJson(FString& OutJsonString)
{
	if (!JsonObject.IsValid())
	{
		Reset();

		GenericLOG(GenericLogJson, Error, TEXT("Invalid Json Object"));
		return false;
	}

	if (FJsonSerializer::Serialize(JsonObject.ToSharedRef(), FJsonWriterFactory::Create(&JsonString)))
	{
		OutJsonString = JsonString;
		return true;
	}

	return false;
}

bool UGenericJsonObject::DecodeJsonFromFile(FString FileName)
{
	FString DecodeJsonString;
	if (UBPFunctions_Desktop::ReadStringFromFile(FileName, DecodeJsonString))
	{
		return DecodeJson(DecodeJsonString);
	}

	return false;
}

bool UGenericJsonObject::DecodeJsonFromString(FString InJsonString)
{
	bool Result;
	TSharedPtr<FJsonObject> NewJsonObject = UBPFunctions_Json::ConstructJsonObject(InJsonString, Result);

	if (Result)
	{
		JsonString = InJsonString;
		JsonObject = NewJsonObject;
	}

	return Result;
}

bool UGenericJsonObject::DecodeJson(const FString& InJsonString)
{
	if (!JsonObject.IsValid())
	{
		Reset();

		GenericLOG(GenericLogJson, Error, TEXT("Invalid Json Object"));
		return false;
	}

	return DecodeJsonFromString(InJsonString);
}

TArray<FString> UGenericJsonObject::GetFieldNames() const
{
	TArray<FString> Result;

	if (JsonObject.IsValid())
	{
		JsonObject->Values.GetKeys(Result);
	}

	return Result;
}

bool UGenericJsonObject::HasField(FString FieldName) const
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->HasField(FieldName);
}

bool UGenericJsonObject::HasTypedField(FString FieldName, const EJsonFieldTypeBP JsonFieldType) const
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	switch (ConvertToJsonFieldType(JsonFieldType))
	{
	case EJson::None:
		return JsonObject->HasField(FieldName);
	case EJson::Null:
		return JsonObject->HasTypedField<EJson::Null>(FieldName);
	case EJson::String:
		return JsonObject->HasTypedField<EJson::String>(FieldName);
	case EJson::Number:
		return JsonObject->HasTypedField<EJson::Number>(FieldName);
	case EJson::Boolean:
		return JsonObject->HasTypedField<EJson::Boolean>(FieldName);
	case EJson::Array:
		return JsonObject->HasTypedField<EJson::Array>(FieldName);
	case EJson::Object:
		return JsonObject->HasTypedField<EJson::Object>(FieldName);
	}

	return false;
}

void UGenericJsonObject::RemoveField(FString FieldName)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return;
	}

	JsonObject->RemoveField(FieldName);
}

bool UGenericJsonObject::TryGetBoolValue(FString FieldName, bool& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetBoolField(FieldName, OutputValue);
}

bool UGenericJsonObject::TryGetBoolValues(FString FieldName, TArray<bool>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonValues;
	if (JsonObject->TryGetArrayField(FieldName, JsonValues))
	{
		for (auto& JsonValue : *JsonValues)
		{
			OutputValues.Add(JsonValue->AsBool());
		}

		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetBoolValue(FString FieldName, const bool InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Boolean))
	{
		JsonObject->SetBoolField(FieldName, InputValue);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetBoolValues(FString FieldName, const TArray<bool>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			JsonValues.Add(UBPFunctions_Json::ToJsonValue(InputValue));
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetInt32Value(FString FieldName, int32& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetNumberField(FieldName, OutputValue);
}

bool UGenericJsonObject::TryGetInt32Values(FString FieldName, TArray<int32>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonValues;
	if (JsonObject->TryGetArrayField(FieldName, JsonValues))
	{
		for (auto& JsonValue : *JsonValues)
		{
			OutputValues.Add(FStaticFunctions_Convert::ToInt32(JsonValue->AsNumber()));
		}

		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetInt32Value(FString FieldName, const int32 InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Number))
	{
		JsonObject->SetNumberField(FieldName, FStaticFunctions_Convert::ToDouble(InputValue));
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetInt32Values(FString FieldName, const TArray<int32>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			JsonValues.Add(UBPFunctions_Json::ToJsonValue(InputValue));
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetInt64Value(FString FieldName, int64& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetNumberField(FieldName, OutputValue);
}

bool UGenericJsonObject::TryGetInt64Values(FString FieldName, TArray<int64>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonValues;
	if (JsonObject->TryGetArrayField(FieldName, JsonValues))
	{
		for (auto& JsonValue : *JsonValues)
		{
			OutputValues.Add(FStaticFunctions_Convert::ToInt64(JsonValue->AsNumber()));
		}

		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetInt64Value(FString FieldName, const int64 InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Number))
	{
		JsonObject->SetNumberField(FieldName, FStaticFunctions_Convert::ToDouble(InputValue));
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetInt64Values(FString FieldName, const TArray<int64>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			JsonValues.Add(UBPFunctions_Json::ToJsonValue(InputValue));
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetDoubleValue(FString FieldName, double& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetNumberField(FieldName, OutputValue);
}

bool UGenericJsonObject::TryGetDoubleValues(FString FieldName, TArray<double>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonValues;
	if (JsonObject->TryGetArrayField(FieldName, JsonValues))
	{
		for (auto& JsonValue : *JsonValues)
		{
			OutputValues.Add(JsonValue->AsNumber());
		}

		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetDoubleValue(FString FieldName, const double InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Number))
	{
		JsonObject->SetNumberField(FieldName, InputValue);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetDoubleValues(FString FieldName, const TArray<double>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			JsonValues.Add(UBPFunctions_Json::ToJsonValue(InputValue));
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetStringValue(FString FieldName, FString& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetStringField(FieldName, OutputValue);
}

bool UGenericJsonObject::TryGetStringValues(FString FieldName, TArray<FString>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	return JsonObject->TryGetStringArrayField(FieldName, OutputValues);
}

bool UGenericJsonObject::TrySetStringValue(FString FieldName, const FString InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::String))
	{
		JsonObject->SetStringField(FieldName, InputValue);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetStringValues(FString FieldName, const TArray<FString>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			JsonValues.Add(UBPFunctions_Json::ToJsonValue(InputValue));
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetObjectValue(FString FieldName, UGenericJsonObject*& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TSharedPtr<FJsonObject>* NewRawJsonObject = nullptr;
	bool Result = JsonObject->TryGetObjectField(FieldName, NewRawJsonObject);

	if (Result)
	{
		OutputValue->SetJsonObject(NewRawJsonObject->ToSharedRef());
	}

	return Result;
}

bool UGenericJsonObject::TryGetObjectValues(FString FieldName, TArray<UGenericJsonObject*>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonValues;
	if (JsonObject->TryGetArrayField(FieldName, JsonValues))
	{
		for (auto& JsonValue : *JsonValues)
		{
			const TSharedPtr<FJsonObject>& NewRawJsonObject = JsonValue->AsObject();

			UGenericJsonObject* NewJsonObject = NewObject<UGenericJsonObject>(this);
			NewJsonObject->SetJsonObject(NewRawJsonObject.ToSharedRef());

			OutputValues.Add(NewJsonObject);
		}

		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetObjectValue(FString FieldName, UGenericJsonObject* InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (IsValid(InputValue))
	{
		GenericLOG(GenericLogJson, Error, TEXT("InputValue Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Object))
	{
		JsonObject->SetObjectField(FieldName, InputValue->GetJsonObject());
		return true;
	}

	return false;
}

bool UGenericJsonObject::TrySetObjectValues(FString FieldName, const TArray<UGenericJsonObject*>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	if (HasTypedField(FieldName, EJsonFieldTypeBP::Array))
	{
		TArray<TSharedPtr<FJsonValue>> JsonValues;

		for (auto& InputValue : InputValues)
		{
			TSharedPtr<FJsonValue> NewJsonValue = UBPFunctions_Json::ToJsonValue(InputValue);
			if (NewJsonValue.IsValid())
			{
				JsonValues.Add(NewJsonValue);
			}
		}

		JsonObject->SetArrayField(FieldName, JsonValues);
		return true;
	}

	return false;
}

bool UGenericJsonObject::TryGetBoolValueRecursive(FString FieldName, bool& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetBoolValue(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetBoolValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetBoolValuesRecursive(FString FieldName, TArray<bool>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetBoolValues(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetBoolValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetBoolValueRecursive(FString FieldName, bool InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetBoolValue(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetBoolValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetBoolValuesRecursive(FString FieldName, const TArray<bool>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetBoolValues(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetBoolValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetInt32ValueRecursive(FString FieldName, int32& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetInt32Value(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetInt32ValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetInt32ValuesRecursive(FString FieldName, TArray<int32>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetInt32Values(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetInt32ValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetInt32ValueRecursive(FString FieldName, int32 InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetInt32Value(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetInt32ValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetInt32ValuesRecursive(FString FieldName, const TArray<int32>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetInt32Values(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetInt32ValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetInt64ValueRecursive(FString FieldName, int64& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetInt64Value(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetInt64ValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetInt64ValuesRecursive(FString FieldName, TArray<int64>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetInt64Values(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetInt64ValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetInt64ValueRecursive(FString FieldName, int64 InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetInt64Value(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetInt64ValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetInt64ValuesRecursive(FString FieldName, const TArray<int64>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetInt64Values(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetInt64ValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetDoubleValueRecursive(FString FieldName, double& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetDoubleValue(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetDoubleValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetDoubleValuesRecursive(FString FieldName, TArray<double>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetDoubleValues(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetDoubleValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetDoubleValueRecursive(FString FieldName, double InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetDoubleValue(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetDoubleValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetDoubleValuesRecursive(FString FieldName, const TArray<double>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetDoubleValues(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetDoubleValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetStringValueRecursive(FString FieldName, FString& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetStringValue(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetStringValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetStringValuesRecursive(FString FieldName, TArray<FString>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetStringValues(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetStringValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetStringValueRecursive(FString FieldName, FString InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetStringValue(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetStringValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetStringValuesRecursive(FString FieldName, const TArray<FString>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetStringValues(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetStringValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetObjectValueRecursive(FString FieldName, UGenericJsonObject*& OutputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetObjectValue(FieldName, OutputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetObjectValueRecursive(FieldName, OutputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TryGetObjectValuesRecursive(FString FieldName, TArray<UGenericJsonObject*>& OutputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TryGetObjectValues(FieldName, OutputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TryGetObjectValuesRecursive(FieldName, OutputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetObjectValueRecursive(FString FieldName, UGenericJsonObject* InputValue)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetObjectValue(FieldName, InputValue))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetObjectValueRecursive(FieldName, InputValue))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

bool UGenericJsonObject::TrySetObjectValuesRecursive(FString FieldName, const TArray<UGenericJsonObject*>& InputValues)
{
	if (!JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Error, TEXT("JsonObject Is InValid"));
		return false;
	}

	if (FieldName.IsEmpty())
	{
		GenericLOG(GenericLogJson, Error, TEXT("FieldName Is InValid"));
		return false;
	}

	TSharedRef<FJsonObject> RawJsonObject = JsonObject.ToSharedRef();
	for (auto& JsonField : JsonObject->Values)
	{
		/* Check If There Is a Bool Value Under This JsonObject */
		if (TrySetObjectValues(FieldName, InputValues))
		{
			return true;
		}

		/* Check If There Is a Child JsonObject Under This JsonObject That Contains The Bool Value */
		UGenericJsonObject* SubJsonObject = nullptr;
		if (TryGetObjectValue(JsonField.Key, SubJsonObject))
		{
			if (SubJsonObject->TrySetObjectValuesRecursive(FieldName, InputValues))
			{
				return true;
			}
		}

		/* Continue To Traverse The Next Element */
	}

	return false;
}

TSharedPtr<FJsonObject> UGenericJsonObject::GetJsonObject()
{
	return JsonObject;
}

void UGenericJsonObject::SetJsonObject(const TSharedRef<FJsonObject>& InJsonObject)
{
	JsonObject = InJsonObject;
	JsonString = UBPFunctions_Json::ToJsonString(JsonObject);
}

