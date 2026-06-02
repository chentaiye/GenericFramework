// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions_Json.h"

#include "GenericJsonObject.h"
#include "JsonObjectConverter.h"
#include "JsonType.h"
#include "JsonValueBinary.h"
#include "Misc/EngineVersionComparison.h"
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
#include "Blueprint/BlueprintExceptionInfo.h"
#else
#include "UObject/Script.h"
#endif
#include "StaticFunctions/StaticFunctions_Convert.h"

typedef TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriterFactory;
typedef TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FCondensedJsonStringWriter;

#define LOCTEXT_NAMESPACE "FGenericJsonModule"

FJsonObjectConverter::CustomExportCallback EnumOverrideExportCallback;

namespace
{
	int32 GetJsonPropertyElementSize(const FProperty& InProperty)
	{
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
		return InProperty.GetElementSize();
#else
		return InProperty.ElementSize;
#endif
	}
}

bool UBPFunctions_Json::GetJsonField(UGenericJsonObject* JsonObject, const FString& FieldName, int32& OutValue)
{
	if (!IsValid(JsonObject))
	{
		return false;
	}

	if (FieldName.IsEmpty())
	{
		return false;
	}

	return true;
}

DEFINE_FUNCTION(UBPFunctions_Json::execGetJsonField)
{
	P_GET_OBJECT_REF(UGenericJsonObject, JsonObject);
	P_GET_PROPERTY(FStrProperty, FieldName);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProp = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!ValueProp || !ValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(EBlueprintExceptionType::AccessViolation,LOCTEXT("GetJsonField_MissingOutputProperty", "Failed to resolve the output parameter for GetJsonField."));
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	bool bResult;
	if (FieldName.IsEmpty())
	{
		const FStructProperty* StructProperty = static_cast<FStructProperty*>(ValueProp);
		if (!StructProperty)
		{
			bResult = false;
			*StaticCast<bool*>(RESULT_PARAM) = bResult;
			return;
		}

		P_NATIVE_BEGIN
			bResult = FJsonObjectConverter::JsonObjectToUStruct(JsonObject->GetJsonObject().ToSharedRef(), StructProperty->Struct, ValuePtr);
		P_NATIVE_END
		*StaticCast<bool*>(RESULT_PARAM) = bResult;
		return;
	}

	P_NATIVE_BEGIN
		bResult = JsonFieldToProperty(FieldName, JsonObject, ValueProp, ValuePtr);
	P_NATIVE_END

	*static_cast<bool*>(RESULT_PARAM) = bResult;
}

bool UBPFunctions_Json::SetJsonField(UGenericJsonObject* JsonObject, const FString& FieldName, const int32& Value)
{
	if (!IsValid(JsonObject))
	{
		return false;
	}

	if (FieldName.IsEmpty())
	{
		return false;
	}

	return true;
}

DEFINE_FUNCTION(UBPFunctions_Json::execSetJsonField)
{
	P_GET_OBJECT_REF(UGenericJsonObject, JsonObject);
	P_GET_PROPERTY(FStrProperty, FieldName);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* SourceProperty = Stack.MostRecentProperty;
	void* SourceValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!SourceProperty || !SourceValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("SetField_MissingInputProperty", "Failed to resolve the input parameter for SetField.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	bool bResult = true;

	TSharedPtr<FJsonValue> JsonValue = WriteValue(SourceProperty, SourceValuePtr, nullptr);
	JsonObject->GetJsonObject()->SetField(FieldName, JsonValue);

	P_NATIVE_BEGIN

		FString JsonString;
		if (!JsonObject->EncodeJson(JsonString))
		{
			FFrame::KismetExecutionMessage(TEXT("Error serializing JSON Object."), ELogVerbosity::Error);
			bResult = false;
		}

	P_NATIVE_END

	*StaticCast<bool*>(RESULT_PARAM) = bResult;
}

void UBPFunctions_Json::SaveStructToJsonFile(bool& Result, const FString& FilePath, const int32& Value)
{
}

DEFINE_FUNCTION(UBPFunctions_Json::execSaveStructToJsonFile)
{
	P_GET_UBOOL_REF(Result);
	P_GET_PROPERTY(FStrProperty, FilePath);

	Stack.StepCompiledIn<FStructProperty>(nullptr);
	FProperty* Property = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	Result = false;

	if (!Property || !ValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("SetField_MissingInputProperty", "Failed to resolve the input parameter.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	const FStructProperty* StructProperty = CastField<FStructProperty>(Property);
	if (!StructProperty)
	{
		GenericLOG(GenericLogJson, Error, TEXT("Invalid Struct Property"));
		return;
	}

	P_NATIVE_BEGIN;
		if (StructToJsonFile(FilePath, StructProperty->Struct, ValuePtr))
		{
			Result = true;
		}
		else
		{
			Result = false;
		}
	P_NATIVE_END;
}

void UBPFunctions_Json::LoadJsonFileToStruct(bool& Result, const FString& FilePath, int32& Value)
{
}

DEFINE_FUNCTION(UBPFunctions_Json::execLoadJsonFileToStruct)
{
	P_GET_UBOOL_REF(Result);
	P_GET_PROPERTY(FStrProperty, FilePath);

	Stack.StepCompiledIn<FStructProperty>(nullptr);
	FProperty* Property = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	Result = false;

	if (!Property || !ValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("SetField_MissingInputProperty", "Failed to resolve the input parameter.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	const FStructProperty* StructProperty = CastField<FStructProperty>(Property);
	if (!StructProperty)
	{
		GenericLOG(GenericLogJson, Error, TEXT("Invalid Struct Property"));
		return;
	}

	P_NATIVE_BEGIN;
		if (JsonFileToStruct(FilePath, StructProperty->Struct, ValuePtr))
		{
			Result = true;
		}
		else
		{
			Result = false;
		}
	P_NATIVE_END;
}

TSharedPtr<FJsonObject> UBPFunctions_Json::ConstructJsonObject()
{
	return MakeShareable(new FJsonObject);
}

TSharedPtr<FJsonObject> UBPFunctions_Json::ConstructJsonObject(const FString& JsonString, bool& Result)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	Result = FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(*JsonString), JsonObject);
	return JsonObject;
}

FString UBPFunctions_Json::ToJsonString(const TSharedPtr<FJsonObject>& JsonObject)
{
	FString OutputString;
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), FCondensedJsonStringWriterFactory::Create(&OutputString));
	return OutputString;
}

FString UBPFunctions_Json::ToJsonString(const TSharedPtr<FJsonValue>& JsonValue)
{
	if (JsonValue->Type == EJson::None)
	{
		return FString();
	}
	else if (JsonValue->Type == EJson::Null)
	{
		return FString();
	}
	else if (JsonValue->Type == EJson::String)
	{
		return JsonValue->AsString();
	}
	else if (JsonValue->Type == EJson::Number)
	{
		return FString::Printf(TEXT("%f"), JsonValue->AsNumber());
	}
	else if (JsonValue->Type == EJson::Boolean)
	{
		return FString::Printf(TEXT("%d"), JsonValue->AsBool());
	}
	else if (JsonValue->Type == EJson::Array)
	{
		return ToJsonString(JsonValue->AsArray());
	}
	else if (JsonValue->Type == EJson::Object)
	{
		return ToJsonString(JsonValue->AsObject());
	}
	else
	{
		return FString();
	}
}

FString UBPFunctions_Json::ToJsonString(const TArray<TSharedPtr<FJsonValue>>& JsonValueArray)
{
	FString OutputString;
	FJsonSerializer::Serialize(JsonValueArray, FCondensedJsonStringWriterFactory::Create(&OutputString));
	return OutputString;
}

void UBPFunctions_Json::ReadStruct(const TSharedPtr<FJsonObject>& JsonObject, const UStruct* Struct, void* Instance, UObject* Owner)
{
	FString TypeName;
	JsonObject->TryGetStringField(TEXT("$type"), TypeName);

	if (!TypeName.IsEmpty() && !ensureAlwaysMsgf(Struct->GetName().Equals(TypeName), TEXT("Type name mismatch in FEditorConfig::ReadUObject. Expected: %s, Actual: %s"), *Struct->GetName(), *TypeName))
	{
		return;
	}

	for (TFieldIterator<FProperty> It(Struct); It; ++It)
	{
		const FProperty* Property = *It;

		void* DataPtr = Property->ContainerPtrToValuePtr<void>(Instance);

		TSharedPtr<FJsonValue> Value = JsonObject->TryGetField(Property->GetName());
		if (Value.IsValid())
		{
			ReadValue(Value, Property, DataPtr, Owner);
		}
	}
}

void UBPFunctions_Json::ReadValue(const TSharedPtr<FJsonValue>& JsonValue, const FProperty* Property, void* DataPtr, UObject* Owner)
{
	if (Property->IsA<FStrProperty>())
	{
		FString* Value = (FString*)DataPtr;
		JsonValue->TryGetString(*Value);
		return;
	}

	if (Property->IsA<FNameProperty>())
	{
		FString TempValue;
		JsonValue->TryGetString(TempValue);

		*(FName*)DataPtr = *TempValue;
		return;
	}

	if (Property->IsA<FTextProperty>())
	{
		FString TempValue;
		JsonValue->TryGetString(TempValue);

		*(FText*)DataPtr = FText::FromString(TempValue);
		return;
	}

	if (Property->IsA<FBoolProperty>())
	{
		bool Value = ((FBoolProperty*)Property)->GetDefaultPropertyValue();
		if (JsonValue->TryGetBool(Value))
		{
			((FBoolProperty*)Property)->SetPropertyValue(DataPtr, Value);
		}
		return;
	}

	if (Property->IsA<FFloatProperty>())
	{
		float* Value = (float*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FDoubleProperty>())
	{
		double* Value = (double*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FInt8Property>())
	{
		int8* Value = (int8*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FInt16Property>())
	{
		int16* Value = (int16*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FIntProperty>())
	{
		int32* Value = (int32*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FInt64Property>())
	{
		int64* Value = (int64*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FByteProperty>())
	{
		uint8* Value = (uint8*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FUInt16Property>())
	{
		uint16* Value = (uint16*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FUInt32Property>())
	{
		uint32* Value = (uint32*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FUInt64Property>())
	{
		uint64* Value = (uint64*)DataPtr;
		JsonValue->TryGetNumber(*Value);
		return;
	}

	if (Property->IsA<FEnumProperty>())
	{
		UEnum* Enum = ((FEnumProperty*)Property)->GetEnum();
		FString ValueString;
		if (JsonValue->TryGetString(ValueString))
		{
			int64 Index = Enum->GetIndexByNameString(ValueString);
			if (Index != INDEX_NONE)
			{
				int64 Value = Enum->GetValueByIndex(Index);
				((FEnumProperty*)Property)->GetUnderlyingProperty()->SetIntPropertyValue(DataPtr, Value);
			}
		}
		return;
	}

	if (Property->IsA<FObjectPropertyBase>())
	{
		FString PathString;
		if (JsonValue->TryGetString(PathString))
		{
			Property->ImportText_Direct(*PathString, DataPtr, Owner, 0);
		}
		return;
	}

	if (Property->IsA<FStructProperty>())
	{
		const TSharedPtr<FJsonObject>* ObjectJsonValue;
		if (JsonValue->TryGetObject(ObjectJsonValue))
		{
			ReadStruct(*ObjectJsonValue, ((FStructProperty*)Property)->Struct, DataPtr, Owner);
		}
		else if (JsonValue->Type == EJson::String)
		{
			FString ImportTextString;
			if (JsonValue->TryGetString(ImportTextString))
			{
				Property->ImportText_Direct(*ImportTextString, DataPtr, Owner, 0);
			}
		}
		return;
	}

	if (Property->IsA<FArrayProperty>())
	{
		const TArray<TSharedPtr<FJsonValue>>* ArrayJsonValue;
		if (JsonValue->TryGetArray(ArrayJsonValue))
		{
			FProperty* InnerProperty = ((FArrayProperty*)Property)->Inner;
			FScriptArrayHelper ArrayHelper((FArrayProperty*)Property, DataPtr);

			ArrayHelper.EmptyAndAddValues(ArrayJsonValue->Num());

			for (int32 Idx = 0; Idx < ArrayHelper.Num(); ++Idx)
			{
				TSharedPtr<FJsonValue> Value = (*ArrayJsonValue)[Idx];
				ReadValue(Value, InnerProperty, ArrayHelper.GetRawPtr(Idx), Owner);
			}
		}
		return;
	}

	if (Property->IsA<FSetProperty>())
	{
		const TArray<TSharedPtr<FJsonValue>>* SetJsonValue;
		if (JsonValue->TryGetArray(SetJsonValue))
		{
			const FProperty* InnerProperty = ((FSetProperty*)Property)->ElementProp;
			FScriptSetHelper SetHelper((FSetProperty*)Property, DataPtr);
			SetHelper.EmptyElements(SetJsonValue->Num());

			TArray<uint8> TempBuffer;
			TempBuffer.AddUninitialized(GetJsonPropertyElementSize(*InnerProperty));

			for (int32 Idx = 0; Idx < SetJsonValue->Num(); ++Idx)
			{
				InnerProperty->InitializeValue(TempBuffer.GetData());

				TSharedPtr<FJsonValue> Value = (*SetJsonValue)[Idx];
				ReadValue(Value, InnerProperty, TempBuffer.GetData(), Owner);

				SetHelper.AddElement(TempBuffer.GetData());

				InnerProperty->DestroyValue(TempBuffer.GetData());
			}
		}
		return;
	}

	if (Property->IsA<FMapProperty>())
	{
		FMapProperty* MapProperty = (FMapProperty*)Property;
		const FProperty* KeyProperty = MapProperty->KeyProp;
		const FProperty* ValueProperty = MapProperty->ValueProp;

		FScriptMapHelper MapHelper(MapProperty, DataPtr);
		const TSharedPtr<FJsonObject>* JsonObjectValue;
		if (JsonValue->TryGetObject(JsonObjectValue))
		{
			MapHelper.EmptyValues((*JsonObjectValue)->Values.Num());

			/** 使用临时缓冲区承接反序列化出的 Map 键和值，再交给 FScriptMapHelper 写入目标容器。 */
			TArray<uint8> TempKey;
			TempKey.AddZeroed(GetJsonPropertyElementSize(*KeyProperty));

			TArray<uint8> TempValue;
			TempValue.AddZeroed(GetJsonPropertyElementSize(*ValueProperty));

			for (const TPair<FString, TSharedPtr<FJsonValue>>& JsonPair : (*JsonObjectValue)->Values)
			{
				KeyProperty->InitializeValue(TempKey.GetData());
				KeyProperty->ImportText_Direct(*JsonPair.Key, TempKey.GetData(), Owner, 0);

				ValueProperty->InitializeValue(TempValue.GetData());
				ReadValue(JsonPair.Value, ValueProperty, TempValue.GetData(), Owner);

				MapHelper.AddPair(TempKey.GetData(), TempValue.GetData());

				KeyProperty->DestroyValue(TempKey.GetData());
				ValueProperty->DestroyValue(TempValue.GetData());
			}

			return;
		}

		const TArray<TSharedPtr<FJsonValue>>* JsonArrayPtr = nullptr;
		if (JsonValue->TryGetArray(JsonArrayPtr))
		{
			MapHelper.EmptyValues(JsonArrayPtr->Num());

			TArray<uint8> TempKey;
			TempKey.AddUninitialized(GetJsonPropertyElementSize(*KeyProperty));

			TArray<uint8> TempValue;
			TempValue.AddUninitialized(GetJsonPropertyElementSize(*ValueProperty));

			for (const TSharedPtr<FJsonValue>& JsonElement : *JsonArrayPtr)
			{
				TSharedPtr<FJsonObject>* JsonObject = nullptr;
				if (JsonElement->TryGetObject(JsonObject))
				{
					TSharedPtr<FJsonValue> JsonKeyField = (*JsonObject)->TryGetField(TEXT("$key"));
					TSharedPtr<FJsonValue> JsonValueField = (*JsonObject)->TryGetField(TEXT("$value"));

					if (JsonKeyField.IsValid() && JsonValueField.IsValid())
					{
						KeyProperty->InitializeValue(TempKey.GetData());
						ReadValue(JsonKeyField, KeyProperty, TempKey.GetData(), Owner);

						ValueProperty->InitializeValue(TempValue.GetData());
						ReadValue(JsonValueField, ValueProperty, TempValue.GetData(), Owner);

						MapHelper.AddPair(TempKey.GetData(), TempValue.GetData());

						KeyProperty->DestroyValue(TempKey.GetData());
						ValueProperty->DestroyValue(TempValue.GetData());
					}
				}
			}

			return;
		}
	}

	ensureAlwaysMsgf(false, TEXT("Property type is unsupported: %s, type: %s"), *Property->GetPathName(), *Property->GetClass()->GetName());
}

TSharedPtr<FJsonValue> UBPFunctions_Json::WriteArray(const FArrayProperty* ArrayProperty, const void* DataPtr)
{
	const FProperty* InnerProperty = ArrayProperty->Inner;
	FScriptArrayHelper ArrayHelper(ArrayProperty, DataPtr);

	TArray<TSharedPtr<FJsonValue>> JsonValuesArray;
	JsonValuesArray.Reserve(ArrayHelper.Num());

	for (int32 Idx = 0; Idx < ArrayHelper.Num(); ++Idx)
	{
		if (ArrayHelper.IsValidIndex(Idx))
		{
			TSharedPtr<FJsonValue> ElementValue = WriteValue(InnerProperty, ArrayHelper.GetRawPtr(Idx), nullptr);
			check(ElementValue.IsValid());
			JsonValuesArray.Add(ElementValue);
		}
	}

	return MakeShared<FJsonValueArray>(JsonValuesArray);
}

TSharedPtr<FJsonValue> UBPFunctions_Json::WriteSet(const FSetProperty* SetProperty, const void* DataPtr)
{
	const FProperty* InnerProperty = SetProperty->ElementProp;
	FScriptSetHelper SetHelper(SetProperty, DataPtr);

	TArray<TSharedPtr<FJsonValue>> JsonValuesArray;
	JsonValuesArray.Reserve(SetHelper.Num());

	for (int32 Idx = 0; Idx < SetHelper.Num(); ++Idx)
	{
		if (SetHelper.IsValidIndex(Idx))
		{
			TSharedPtr<FJsonValue> ElementValue = WriteValue(InnerProperty, SetHelper.GetElementPtr(Idx), nullptr);
			check(ElementValue.IsValid());
			JsonValuesArray.Add(ElementValue);
		}
	}

	return MakeShared<FJsonValueArray>(JsonValuesArray);
}

TSharedPtr<FJsonValue> UBPFunctions_Json::WriteMap(const FMapProperty* MapProperty, const void* DataPtr)
{
	TSharedPtr<FJsonValue> ResultValue;

	const FProperty* KeyProperty = MapProperty->KeyProp;
	const FProperty* ValueProperty = MapProperty->ValueProp;

	FScriptMapHelper MapHelper(MapProperty, DataPtr);

	if (MapHelper.Num() == 0)
	{
		ResultValue = MakeShared<FJsonValueObject>(MakeShared<FJsonObject>());
	}
	else
	{
		TArray<TSharedPtr<FJsonValue>> JsonKeysArray;
		JsonKeysArray.Reserve(MapHelper.Num());

		TArray<TSharedPtr<FJsonValue>> JsonValuesArray;
		JsonValuesArray.Reserve(MapHelper.Num());

		for (int32 Idx = 0; Idx < MapHelper.Num(); ++Idx)
		{
			if (MapHelper.IsValidIndex(Idx))
			{
				TSharedPtr<FJsonValue> JsonKey = WriteValue(KeyProperty, MapHelper.GetKeyPtr(Idx), nullptr);
				check(JsonKey.IsValid());
				JsonKeysArray.Add(JsonKey);

				TSharedPtr<FJsonValue> JsonValue = WriteValue(ValueProperty, MapHelper.GetValuePtr(Idx), nullptr);
				check(JsonValue.IsValid());
				JsonValuesArray.Add(JsonValue);
			}
		}

		/** Map 可以按 `$key`/`$value` 数组保存，也可以在键能安全表示为字符串时保存为 JSON 对象；首个键值决定本次输出形态。 */
		const EJson KeyType = JsonKeysArray[0]->Type;
		if (KeyType == EJson::Object)
		{
			TArray<TSharedPtr<FJsonValue>> ResultArray;
			ResultArray.Reserve(MapHelper.Num());

			for (int32 Idx = 0; Idx < MapHelper.Num(); ++Idx)
			{
				if (MapHelper.IsValidIndex(Idx))
				{
					TSharedPtr<FJsonObject> ElementObject = MakeShared<FJsonObject>();
					ElementObject->SetField(TEXT("$key"), JsonKeysArray[Idx]);
					ElementObject->SetField(TEXT("$value"), JsonValuesArray[Idx]);

					ResultArray.Add(MakeShared<FJsonValueObject>(ElementObject));
				}
			}

			ResultValue = MakeShared<FJsonValueArray>(ResultArray);
		}
		else if (KeyType == EJson::Boolean ||
			KeyType == EJson::Number ||
			KeyType == EJson::String)
		{
			TSharedPtr<FJsonObject> ResultObject = MakeShared<FJsonObject>();

			for (int32 Idx = 0; Idx < MapHelper.Num(); ++Idx)
			{
				if (MapHelper.IsValidIndex(Idx))
				{
					FString KeyString;
					const bool bGetStringSuccess = JsonKeysArray[Idx]->TryGetString(KeyString);
					check(bGetStringSuccess);

					ResultObject->SetField(KeyString, JsonValuesArray[Idx]);
				}
			}

			ResultValue = MakeShared<FJsonValueObject>(ResultObject);
		}

		ensureMsgf(ResultValue.IsValid(), TEXT("Map key type is invalid."));
	}

	return ResultValue;
}

TSharedPtr<FJsonValue> UBPFunctions_Json::WriteValue(const FProperty* Property, const void* DataPtr, const void* DefaultPtr)
{
	TSharedPtr<FJsonValue> ResultValue;

	/* 默认值过滤逻辑暂未启用；保留旧判断以便后续恢复时参考。
	if (DefaultPtr != nullptr && Property->Identical(DataPtr, DefaultPtr))
	{
		return ResultValue;
	}*/

	if (const FStrProperty* StrProperty = CastField<FStrProperty>(Property))
	{
		FString* Value = (FString*)DataPtr;
		ResultValue = MakeShared<FJsonValueString>(*Value);
	}
	else if (const FNameProperty* NameProperty = CastField<FNameProperty>(Property))
	{
		const FName* Value = (FName*)DataPtr;
		ResultValue = MakeShared<FJsonValueString>(Value->ToString());
	}
	else if (const FTextProperty* TextProperty = CastField<FTextProperty>(Property))
	{
		const FText* Value = (FText*)DataPtr;
		ResultValue = MakeShared<FJsonValueString>(Value->ToString());
	}
	else if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
	{
		bool Value = BoolProperty->GetPropertyValue(DataPtr);
		ResultValue = MakeShared<FJsonValueBoolean>(Value);
	}
	else if (const FFloatProperty* FloatProperty = CastField<FFloatProperty>(Property))
	{
		float* Value = (float*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FDoubleProperty* DoubleProperty = CastField<FDoubleProperty>(Property))
	{
		double* Value = (double*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FInt8Property* Int8Property = CastField<FInt8Property>(Property))
	{
		int8* Value = (int8*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FInt16Property* Int16Property = CastField<FInt16Property>(Property))
	{
		int16* Value = (int16*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FIntProperty* Int32Property = CastField<FIntProperty>(Property))
	{
		int32* Value = (int32*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FInt64Property* Int64Property = CastField<FInt64Property>(Property))
	{
		int64* Value = (int64*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FByteProperty* ByteProperty = CastField<FByteProperty>(Property))
	{
		uint8* Value = (uint8*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FUInt16Property* Uint16Property = CastField<FUInt16Property>(Property))
	{
		uint16* Value = (uint16*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FUInt32Property* Uint32Property = CastField<FUInt32Property>(Property))
	{
		uint32* Value = (uint32*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FUInt64Property* Uint64Property = CastField<FUInt64Property>(Property))
	{
		uint64* Value = (uint64*)DataPtr;
		ResultValue = MakeShared<FJsonValueNumber>(*Value);
	}
	else if (const FEnumProperty* EnumProperty = CastField<FEnumProperty>(Property))
	{
		const UEnum* Enum = EnumProperty->GetEnum();
		const int64 Value = EnumProperty->GetUnderlyingProperty()->GetSignedIntPropertyValue(DataPtr);
		const FName ValueName = Enum->GetNameByValue(Value);
		ResultValue = MakeShared<FJsonValueString>(ValueName.ToString());
	}
	else if (const FObjectPropertyBase* ObjectProperty = CastField<FObjectPropertyBase>(Property))
	{
		if (UGenericJsonObject* JsonObject = Cast<UGenericJsonObject>(ObjectProperty->GetObjectPropertyValue(DataPtr)))
		{
			TSharedPtr<FJsonValueObject> JsonValueObject = MakeShareable(new FJsonValueObject(JsonObject->GetJsonObject()));
			ResultValue = JsonValueObject;
		}
		else
		{
			FString ObjectPath;
			ObjectProperty->ExportTextItem_Direct(ObjectPath, DataPtr, nullptr, nullptr, PPF_None, nullptr);
			ResultValue = MakeShared<FJsonValueString>(ObjectPath);
		}
	}
	else if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
	{
		ResultValue = MakeShared<FJsonValueObject>(WriteStruct(StructProperty->Struct, DataPtr, DefaultPtr));
	}
	else if (const FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Property))
	{
		ResultValue = WriteArray(ArrayProperty, DataPtr);
	}
	else if (const FSetProperty* SetProperty = CastField<FSetProperty>(Property))
	{
		ResultValue = WriteSet(SetProperty, DataPtr);
	}
	else if (const FMapProperty* MapProperty = CastField<FMapProperty>(Property))
	{
		ResultValue = WriteMap(MapProperty, DataPtr);
	}

	ensureAlwaysMsgf(ResultValue.IsValid(), TEXT("Property type is unsupported: %s, type: %s"), *Property->GetPathName(), *Property->GetClass()->GetName());
	return ResultValue;
}

TSharedPtr<FJsonObject> UBPFunctions_Json::WriteStruct(const UStruct* Struct, const void* Instance, const void* Defaults)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(TEXT("$type"), Struct->GetName());

	/** 未传入默认实例时先构造一份结构体默认值，避免丢失 C++ 成员初始化器中保存但 FProperty 自身不记录的默认值。 */

	if (Defaults == nullptr)
	{
		TArray<uint8> TempDefaults;
		TempDefaults.AddZeroed(Struct->GetStructureSize());
		Struct->InitializeStruct(TempDefaults.GetData());

		Defaults = TempDefaults.GetData();
	}

	bool bAnyWritten = false;

	for (TFieldIterator<FProperty> It(Struct); It; ++It)
	{
		const FProperty* Property = *It;

		bAnyWritten = true;

		const void* ValuePtr = Property->ContainerPtrToValuePtr<void>(Instance);
		const void* PropertyDefaultPtr = Property->ContainerPtrToValuePtr<void>(Defaults);

		TSharedPtr<FJsonValue> PropertyValue = WriteValue(Property, ValuePtr, PropertyDefaultPtr);
		if (PropertyValue.IsValid())
		{
			JsonObject->SetField(Property->GetName(), PropertyValue);
		}
	}

	ensureAlwaysMsgf(bAnyWritten, TEXT("Struct type has no properties to serialize: %s"), *Struct->GetName());

	return JsonObject;
}

TSharedPtr<FJsonObject> UBPFunctions_Json::WriteUObject(const UClass* Class, const UObject* Instance)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(TEXT("$type"), Class->GetName());

	const UObject* Defaults = Class->GetDefaultObject();

	bool bAnyWritten = false;

	for (TFieldIterator<FProperty> It(Class); It; ++It)
	{
		const FProperty* Property = *It;

		bAnyWritten = true;

		const void* ValuePtr = Property->ContainerPtrToValuePtr<void>(Instance);
		const void* PropertyDefaultPtr = Property->ContainerPtrToValuePtr<void>(Defaults);

		TSharedPtr<FJsonValue> PropertyValue = WriteValue(Property, ValuePtr, PropertyDefaultPtr);
		if (PropertyValue.IsValid())
		{
			JsonObject->SetField(Property->GetName(), PropertyValue);
		}
	}

	ensureAlwaysMsgf(bAnyWritten, TEXT("UObject type has no properties to serialize: %s"), *Class->GetName());

	return JsonObject;
}

TSharedPtr<FJsonObject> UBPFunctions_Json::WriteFunction(const UFunction* Function, const void* Defaults)
{
	const TSharedPtr<FJsonObject> Json = MakeShared<FJsonObject>();

	/** 未传入默认实例时先构造一份函数参数默认值，避免丢失 C++ 成员初始化器中保存但 FProperty 自身不记录的默认值。 */

	if (Defaults == nullptr)
	{
		TArray<uint8> TempDefaults;
		TempDefaults.AddZeroed(Function->GetStructureSize());
		Function->InitializeStruct(TempDefaults.GetData());

		Defaults = TempDefaults.GetData();
	}

	FStructOnScope FuncParams(Function);

	for (TFieldIterator<FProperty> It(Function); It; ++It)
	{
		const FProperty* Property = *It;

		const void* ValuePtr = Property->ContainerPtrToValuePtr<void>(FuncParams.GetStructMemory());
		const void* PropertyDefaultPtr = Property->ContainerPtrToValuePtr<void>(Defaults);

		TSharedPtr<FJsonValue> PropertyValue = WriteValue(Property, ValuePtr, PropertyDefaultPtr);

		if (PropertyValue.IsValid())
		{
			Json->SetField(Property->GetName(), PropertyValue);
		}
	}

	return Json;
}

bool UBPFunctions_Json::JsonObjectToStruct(const TSharedPtr<FJsonObject>& JsonObject, const UStruct* Struct, void* StructPtr)
{
	return FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), Struct, StructPtr);
}

bool UBPFunctions_Json::StructToJsonObject(const UStruct* Struct, const void* StructPtr, const TSharedRef<FJsonObject>& OutJsonObject)
{
	return FJsonObjectConverter::UStructToJsonObject(Struct, StructPtr, OutJsonObject);
}

bool UBPFunctions_Json::JsonFileToStruct(const FString& FilePath, const UStruct* Struct, void* StructPtr)
{
	FString JsonString;
	if (!FFileHelper::LoadFileToString(JsonString, *FilePath) || JsonString.IsEmpty())
	{
		GenericLOG(GenericLogJson, Warning, TEXT("Json data load fail, invalid jons file : %s"), *FilePath)
		return false;
	}

	TSharedPtr<FJsonObject> JsonObject;
	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
	{
		GenericLOG(GenericLogJson, Warning, TEXT("Json data serializer fail, invalid jons file : %s"), *FilePath)
		return false;
	}

	if (!FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), Struct, StructPtr))
	{
		GenericLOG(GenericLogJson, Warning, TEXT("Json converter fail, invalid jons file : %s"), *FilePath)
		return false;
	}

	return true;
}

bool UBPFunctions_Json::StructToJsonFile(const FString& FilePath, const UStruct* Struct, const void* StructPtr)
{
	FString JsonString;
	ensure(FJsonObjectConverter::UStructToJsonObjectString(Struct, StructPtr, JsonString) || JsonString.IsEmpty());
	return FFileHelper::SaveStringToFile(JsonString, *FilePath);
}

bool UBPFunctions_Json::JsonFieldToProperty(const FString& FieldName, UGenericJsonObject* SourceObject, FProperty* TargetProperty, void* TargetValuePtr)
{
	check(SourceObject->GetJsonObject().IsValid());
	check(TargetProperty && TargetValuePtr);

	// Check that field with name exists
	const TSharedPtr<FJsonValue> JsonValue = SourceObject->GetJsonObject()->TryGetField(FieldName);
	if (!JsonValue.IsValid())
	{
		FFrame::KismetExecutionMessage(*FString::Printf(TEXT("Field '%s' was not found on the provided JSON object."), *FieldName), ELogVerbosity::Warning);
		return false;
	}

	return FJsonObjectConverter::JsonValueToUProperty(JsonValue, TargetProperty, TargetValuePtr);
}

bool UBPFunctions_Json::PropertyToJsonField(const FString& FieldName, FProperty* SourceProperty, const void* SourceValuePtr, UGenericJsonObject*& TargetObject)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}

	check(SourceProperty && SourceValuePtr);

	if (!TargetObject->GetJsonObject().IsValid())
	{
		TargetObject->GetJsonObject() = MakeShared<FJsonObject>();
	}

	TargetObject->GetJsonObject()->SetField(FieldName, FJsonObjectConverter::UPropertyToJsonValue(SourceProperty, SourceValuePtr));
	return true;
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(const TArray<uint8>& InValue)
{
	return MakeShareable(new FJsonValueBinary(InValue));
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(bool InValue)
{
	return MakeShareable(new FJsonValueBoolean(InValue));
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(int32 InValue)
{
	return MakeShareable(new FJsonValueNumber(FStaticFunctions_Convert::ToDouble(InValue)));
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(int64 InValue)
{
	return MakeShareable(new FJsonValueNumber(FStaticFunctions_Convert::ToDouble(InValue)));
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(double InValue)
{
	return MakeShareable(new FJsonValueNumber(InValue));
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(const FString& InValue)
{
	//Null
	if (InValue.IsEmpty())
	{
		return MakeShareable(new FJsonValueNull);
	}

	//Number
	if (InValue.IsNumeric())
	{
		return MakeShareable(new FJsonValueNumberString(InValue));
	}

	//Object
	if (InValue.StartsWith(FString(TEXT("{"))))
	{
		bool Result;
		TSharedPtr<FJsonObject> JsonObject = ConstructJsonObject(InValue, Result);

		if (Result)
		{
			return MakeShareable(new FJsonValueObject(JsonObject));
		}
		else
		{
			GenericLOG(GenericLogJson, Error, TEXT("Fail To Convert JsonString To JsonObject"));
			return nullptr;
		}
	}

	//Array
	if (InValue.StartsWith(FString(TEXT("["))))
	{
		TArray<TSharedPtr<FJsonValue>> RawJsonValueArray;
		if (FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(*InValue), RawJsonValueArray))
		{
			return MakeShareable(new FJsonValueArray(RawJsonValueArray));
		}
	}

	//Bool
	if (InValue == TEXT("true") || InValue == TEXT("false"))
	{
		const bool BooleanValue = (InValue == TEXT("true"));
		return MakeShareable(new FJsonValueBoolean(BooleanValue));
	}

	//String
	return MakeShareable(new FJsonValueString(InValue));
}

TArray<TSharedPtr<FJsonValue>> UBPFunctions_Json::ToJsonValues(const FString& InValue)
{
	TArray<TSharedPtr<FJsonValue>> RawJsonValueArray;
	FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(*InValue), RawJsonValueArray);

	return RawJsonValueArray;
}

TArray<TSharedPtr<FJsonValue>> UBPFunctions_Json::ToJsonValues(const TArray<FString>& InValue)
{
	TArray<TSharedPtr<FJsonValue>> RawJsonValueArray;

	for (auto& Value : InValue)
	{
		RawJsonValueArray.Add(ToJsonValue(Value));
	}

	return RawJsonValueArray;
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(const TSharedPtr<FJsonObject>& InValue)
{
	return MakeShareable(new FJsonValueObject(InValue));
}

TArray<TSharedPtr<FJsonValue>> UBPFunctions_Json::ToJsonValues(const TArray<TSharedPtr<FJsonObject>>& InValue)
{
	TArray<TSharedPtr<FJsonValue>> RawJsonValueArray;

	for (auto& Value : InValue)
	{
		RawJsonValueArray.Add(ToJsonValue(Value));
	}

	return RawJsonValueArray;
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(UGenericJsonObject* InValue)
{
	if (!IsValid(InValue))
	{
		return nullptr;
	}

	return MakeShareable(new FJsonValueObject(InValue->GetJsonObject()));
}

TArray<TSharedPtr<FJsonValue>> UBPFunctions_Json::ToJsonValues(const TArray<UGenericJsonObject*>& InValue)
{
	TArray<TSharedPtr<FJsonValue>> RawJsonValueArray;

	for (auto& Value : InValue)
	{
		RawJsonValueArray.Add(ToJsonValue(Value));
	}

	return RawJsonValueArray;
}

TSharedPtr<FJsonValue> UBPFunctions_Json::ToJsonValue(const TArray<TSharedPtr<FJsonValue>>& InValue)
{
	return MakeShareable(new FJsonValueArray(InValue));
}

#undef LOCTEXT_NAMESPACE
