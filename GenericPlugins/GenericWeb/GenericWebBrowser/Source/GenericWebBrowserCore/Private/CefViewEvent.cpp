//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CefViewEvent.h"
#pragma endregion

#pragma region <Engine Headers>
// Json/Public/
#include <Serialization/JsonSerializer.h>
#include <Serialization/JsonWriter.h>
#include <Serialization/JsonReader.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

FString
UCefViewEvent::GetArguments() const
{
  //
  FString StrArgs;
  auto StrWriter = TJsonWriterFactory<>::Create(&StrArgs);
  FJsonSerializer::Serialize(Arguments, StrWriter);
  return StrArgs;
}

void
UCefViewEvent::SetArguments(const FString& InArguments)
{
  TSharedPtr<FJsonValue> JsonValue;
  TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InArguments);
  if (true                                               //
      && FJsonSerializer::Deserialize(Reader, JsonValue) //
      && JsonValue.IsValid()                             //
      && JsonValue->Type == EJson::Array                 //
  ) {
    Arguments = JsonValue->AsArray();
  }
}
