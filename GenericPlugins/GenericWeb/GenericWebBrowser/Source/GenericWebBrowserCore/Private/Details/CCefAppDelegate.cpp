//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CCefAppDelegate.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Convert.h"
#include "Common/Log.h"
#pragma endregion

using namespace Common;

CCefAppDelegate::CCefAppDelegate(const TMap<FString, FString>& args, const CefMessageLoopSchedulerCallback& cb)
  : commandLineArgs_(args)
  , cefMessageLoopSchedulerCallback_(cb)
{
}

CCefAppDelegate::~CCefAppDelegate()
{
  logDebug() << "CCefAppDelegate is being destructed";
}

void
CCefAppDelegate::onBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
  for (auto& kv : commandLineArgs_) {
    if (!kv.Key.IsEmpty()) {
      if (!kv.Value.IsEmpty())
        command_line->AppendSwitchWithValue(Convert::StringF2C(kv.Key), Convert::StringF2C(kv.Value));
      else
        command_line->AppendSwitch(Convert::StringF2C(kv.Key));
    }
  }
}

void
CCefAppDelegate::onBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line)
{
  for (auto& kv : commandLineArgs_) {
    if (!kv.Key.IsEmpty()) {
      if (!kv.Value.IsEmpty())
        command_line->AppendSwitchWithValue(Convert::StringF2C(kv.Key), Convert::StringF2C(kv.Value));
      else
        command_line->AppendSwitch(Convert::StringF2C(kv.Key));
    }
  }
}

void
CCefAppDelegate::onScheduleMessageLoopWork(int64_t delay_ms)
{
  if (cefMessageLoopSchedulerCallback_) {
    cefMessageLoopSchedulerCallback_(delay_ms);
  }
}
