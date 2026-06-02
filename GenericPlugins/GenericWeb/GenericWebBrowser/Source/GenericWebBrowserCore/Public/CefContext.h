//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Templates/PimplPtr.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
// Engine/Public/
#include <Subsystems/SubsystemCollection.h>
#include <Subsystems/EngineSubsystem.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefSettings.h>
#pragma endregion

#pragma region "Generated Header"
#include "CefContext.generated.h"
#pragma endregion

/** 管理进程级 CEF 上下文，负责初始化、资源映射、Cookie 和跨域白名单。 */
UCLASS(MinimalAPI, BlueprintType)
class UCefContext : public UEngineSubsystem
{
  GENERATED_BODY()

#pragma region Properties
public:
  /** 当前 CEF 上下文使用的项目级配置对象。 */
  UPROPERTY(//
    BlueprintReadOnly, //
    Category="Default")
  UCefSettings* Settings=GetMutableDefault<UCefSettings>();
#pragma endregion

#pragma region Overrides
protected:
  UCEFVIEW_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
  UCEFVIEW_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
  UCEFVIEW_API virtual void Deinitialize() override;
#pragma endregion

public:
#pragma region Methods
  /** 返回 CEF 运行时是否已经完成初始化。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool bIsCefInitialized() const;

  /** 在首次使用前触发 CEF 初始化，并返回初始化是否可用。 */
  UCEFVIEW_API bool EnsureCefInitialized();

  /** 注册本地目录资源映射，使内置 Scheme 可以读取指定目录。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void AddLocalFolderResource(const FString& InPath, const FString& InUrl, int32 InPriority = 0);

  /** 注册归档文件资源映射，使内置 Scheme 可以读取压缩包内容。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void AddArchiveFileResource(const FString& pInPathath,
                              const FString& InUrl,
                              const FString& InPassword,
                              int32 InPriority = 0);

  /** 向 CEF Cookie 管理器写入指定域名和 URL 下的 Cookie。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool AddCookie(const FString& InName, const FString& InValue, const FString& InDomain, const FString& InUrl);

  /** 清空 CEF Cookie 管理器中的所有 Cookie。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool DeleteAllCookies();

  /** 添加跨域白名单条目，允许指定来源访问目标协议和域名。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool AddCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                    const FString& InTargetSchema,
                                    const FString& InTargetDomain,
                                    bool InAllowTargetSubdomains);

  /** 移除与参数完全匹配的跨域白名单条目。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool RemoveCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                       const FString& InTargetSchema,
                                       const FString& InTargetDomain,
                                       bool InAllowTargetSubdomains);

  /** 清空当前进程注册的全部跨域白名单条目。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void ClearCrossOriginWhitelistEntry();
#pragma endregion
};
