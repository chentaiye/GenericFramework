//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Convert.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <limits>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "HeadersCefViewCore.h"
#include "Common/Log.h"
#pragma endregion

namespace Common::Convert {

void
CefValueToJsonValue(TSharedPtr<FJsonValue>& jValue, CefValue* cValue)
{
  if (!cValue) {
    logWarn() << "Invalid arguments";
    return;
  }

  auto type = cValue->GetType();
  switch (type) {
    case CefValueType::VTYPE_INVALID:
    case CefValueType::VTYPE_NULL: {
      jValue = MakeShared<FJsonValueNull>();
    } break;
    case CefValueType::VTYPE_BOOL: {
      jValue = MakeShared<FJsonValueBoolean>(cValue->GetBool());
    } break;
    case CefValueType::VTYPE_INT: {
      jValue = MakeShared<FJsonValueNumber>(cValue->GetInt());
    } break;
    case CefValueType::VTYPE_DOUBLE: {
      jValue = MakeShared<FJsonValueNumber>(cValue->GetDouble());
    } break;
    case CefValueType::VTYPE_STRING: {
      jValue = MakeShared<FJsonValueString>(StringC2F(cValue->GetString()));
    } break;
    case CefValueType::VTYPE_DICTIONARY: {
      auto cDict = cValue->GetDictionary();
      CefDictionaryValue::KeyList cKeys;
      if (!cDict->GetKeys(cKeys)) {
        logWarn() << "Failed to get cef dictionary keys";
      }
      auto jObj = MakeShared<FJsonObject>();
      for (auto& key : cKeys) {
        auto cVal = cDict->GetValue(key);
        TSharedPtr<FJsonValue> jVal;
        CefValueToJsonValue(jVal, cVal.get());

        auto jKey = StringC2F(key);
        jObj->SetField(jKey, jVal);
      }
      jValue = MakeShared<FJsonValueObject>(jObj);
    } break;
    case CefValueType::VTYPE_LIST: {
      auto cList = cValue->GetList();
      auto cCount = cList->GetSize();

      TArray<TSharedPtr<FJsonValue>> jArray;
      for (int i = 0; i < cCount; i++) {
        auto cVal = cList->GetValue(i);
        TSharedPtr<FJsonValue> jVal;
        CefValueToJsonValue(jVal, cVal.get());
        jArray.Add(jVal);
      }
      jValue = MakeShared<FJsonValueArray>(jArray);
    } break;
    default:
      logWarn() << "Unsupported CefValueType conversion: " << (int)type;
  }
}

void
JsonValueToCefValue(CefValue* cValue, const TSharedPtr<FJsonValue>& jValue)
{
  if (!cValue) {
    logWarn() << "Invalid arguments";
    return;
  }

  auto type = jValue->Type;
  switch (type) {
    case EJson::Null: {
      cValue->SetNull();
    } break;
    case EJson::Boolean: {
      cValue->SetBool(jValue->AsBool());
    } break;
    case EJson::Number: {
      int32 i32Val = 0;
      if (jValue->TryGetNumber(i32Val)) {
        cValue->SetInt(i32Val);
      } else {
        cValue->SetDouble(jValue->AsNumber());
      }
      break;
    }
    case EJson::String: {
      cValue->SetString(StringF2C(jValue->AsString()));
    } break;
    case EJson::Object: {
      auto cDict = CefDictionaryValue::Create();
      cValue->SetDictionary(cDict);

      auto jObj = jValue->AsObject();
      for (auto& el : jObj->Values) {
        auto cVal = CefValue::Create();
        JsonValueToCefValue(cVal.get(), el.Value);

        CefString cKey = StringF2C(el.Key);
        cDict->SetValue(cKey, cVal);
      }
    } break;
    case EJson::Array: {
      auto cList = CefListValue::Create();
      cValue->SetList(cList);

      auto jArray = jValue->AsArray();
      for (int i = 0; i < jArray.Num(); i++) {
        auto cVal = CefValue::Create();
        JsonValueToCefValue(cVal.get(), jArray[i]);
        cList->SetValue(i, cVal);
      }
    } break;
    default:
      logWarn() << "Unsupported JsonValueType conversion: " << (int)type;
      break;
  }
}
} // namespace Common::Convert
