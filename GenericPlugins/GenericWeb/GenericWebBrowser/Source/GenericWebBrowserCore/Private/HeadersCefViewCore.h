//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#pragma warning(disable : 4459 4668)
#include <Windows/AllowWindowsPlatformTypes.h>
#endif

#pragma region cef_headers
#include <include/cef_app.h>
#include <include/cef_client.h>
#include <include/cef_parser.h>
#include <include/cef_origin_whitelist.h>
#include <include/wrapper/cef_helpers.h>
#include <include/wrapper/cef_message_router.h>
#include <include/wrapper/cef_resource_manager.h>
#pragma endregion

#pragma region cefviewcore_headers
#include <CefViewCoreGlobal.h>
#include <CefViewCoreProtocol.h>
#include <CefViewBrowserApp.h>
#include <CefViewBrowserAppDelegate.h>
#include <CefViewBrowserClient.h>
#include <CefViewBrowserClientDelegate.h>
#pragma endregion

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#include <Windows/HideWindowsPlatformTypes.h>
#endif
