// Copyright ChenTaiye 2025. All Rights Reserved.

#include "ThreadType.h"

DEFINE_LOG_CATEGORY(GenericLogThread);

FThreadHandle::FThreadHandle()
{
}

FThreadHandle::FThreadHandle(const FGuid InThreadGuid)
	: ThreadGuid(InThreadGuid)
{
}

FThreadExecutionResult::FThreadExecutionResult()
	: State(EThreadExecutionState::Invalid),
	  Duration(FTimespan::Zero()),
	  bHasExitCode(false),
	  ExitCode(0)
{
}
