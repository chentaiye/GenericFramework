//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/Array.h>
#include <Containers/UnrealString.h>
#include <Templates/PimplPtr.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
// JsonJson/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Generated Header"
#include "CefViewEvent.generated.h"
#pragma endregion

/** 表示从宿主层广播到页面脚本的一次自定义 CEF 事件。 */
UCLASS(MinimalAPI, BlueprintType)
class UCefViewEvent : public UObject
{
  GENERATED_BODY()

public:
  /** 页面脚本监听的事件名称。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString Name;

  /** 将内部 JSON 参数数组序列化为脚本可读字符串。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API FString GetArguments() const;

  /** 从字符串解析事件参数，供后续广播时传给页面脚本。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void SetArguments(const FString& InArguments);

  /** 缓存已解析的 JSON 参数，避免每次广播前重复解析。 */
  TArray<TSharedPtr<FJsonValue>> Arguments;
};
