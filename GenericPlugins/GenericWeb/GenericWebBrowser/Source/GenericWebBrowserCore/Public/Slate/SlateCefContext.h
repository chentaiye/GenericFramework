//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Templates/PimplPtr.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#include <Slate/SlateCefSettings.h>
#pragma endregion

/** 封装 Slate 层的进程级 CEF 生命周期和共享资源配置。 */
class UCEFVIEW_API FSlateCefContext
{
  friend class SCefViewPrivate;
  class FSlateCefContextPrivate;

  /** 隐藏平台相关的 CEF 初始化、Cookie 和资源映射实现。 */
  TPimplPtr<FSlateCefContextPrivate> m_pImp;

private:
  /** 当前进程唯一的 Slate CEF 上下文实例。 */
  static TSharedPtr<FSlateCefContext> CurrentContext;

  /** 构造空上下文，实际初始化由 Create 传入配置后完成。 */
  FSlateCefContext();

public:
  ~FSlateCefContext();

  /** 创建并初始化全局 CEF 上下文。 */
  static void Create(const FSlateCefSettings& InSettings);

  /** 关闭全局 CEF 上下文并释放进程级资源。 */
  static void Shutdown();

  /** 返回全局 CEF 上下文是否已经创建并可用。 */
  static bool IsInitialized();

  static FSlateCefContext& Get();

public:
  /** 注册本地目录资源映射，使内置 Scheme 可以读取指定目录。 */
  void AddLocalFolderResource(const FString& InPath, const FString& InUrl, int32 InPriority = 0);

  /** 注册归档文件资源映射，使内置 Scheme 可以读取压缩包内容。 */
  void AddArchiveFileResource(const FString& InPath,
                              const FString& InUrl,
                              const FString& InPassword,
                              int32 InPriority = 0);

  /** 向 CEF Cookie 管理器写入指定域名和 URL 下的 Cookie。 */
  bool AddCookie(const FString& InName, const FString& InValue, const FString& InDomain, const FString& InUrl);

  /** 清空 CEF Cookie 管理器中的所有 Cookie。 */
  bool DeleteAllCookies();

  /** 添加跨域白名单条目，允许指定来源访问目标协议和域名。 */
  bool AddCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                    const FString& InTargetSchema,
                                    const FString& InTargetDomain,
                                    bool InAllowTargetSubdomains);

  /** 移除与参数完全匹配的跨域白名单条目。 */
  bool RemoveCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                       const FString& InTargetSchema,
                                       const FString& InTargetDomain,
                                       bool InAllowTargetSubdomains);

  /** 清空当前进程注册的全部跨域白名单条目。 */
  void ClearCrossOriginWhitelistEntry();
};
