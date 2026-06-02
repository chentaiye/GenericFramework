//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <HAL/Platform.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Generated Header"
#include "CefViewQuery.generated.h"
#pragma endregion

/** 表示页面脚本发起并等待原生层回复的一次 CEF 查询。 */
UCLASS(MinimalAPI, BlueprintType)
class UCefViewQuery : public UObject
{
  GENERATED_BODY()

public:
  /** 原生层回复给页面时使用的成功标记。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  bool IsSuccess=false;

  /** 原生层回复失败时返回给页面的错误码。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  int32 ErrorCode=0;

  /** 原生层返回给页面脚本的响应文本。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString Response;

public:
  /** 返回 CEF 分配的查询 ID，用于与底层回调匹配。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API int64 GetId() const;

  /** 返回页面脚本传入的查询内容。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API FString GetRequest() const;

  /** 将当前成功标记、错误码和响应文本发送回页面脚本。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void Reply() const;

protected:
  /** 由 UCefView 创建查询对象时写入底层查询 ID 和请求内容。 */
  UCEFVIEW_API void SetIdAndRequest(int64 InId, const FString& InRequest);

  /** 标记查询已经回复，避免同一 CEF 查询重复回调页面。 */
  UCEFVIEW_API void MarkAsReplied() const;

private:
  friend class UCefView;

  /** CEF 查询 ID。 */
  int64 Id;

  /** 页面脚本提交的原始请求内容。 */
  FString Request;

  /** 防止重复回复同一查询的内部标记。 */
  mutable bool Replied = false;
};
