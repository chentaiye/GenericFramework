// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Support/AuthorizationUiProcessState.h"

namespace AuthorizationUiProcessState
{
	namespace
	{
		bool GStartupPromptVisible = false;
		bool GProcessExitRequested = false;
	}

	bool IsStartupPromptVisible()
	{
		return GStartupPromptVisible;
	}

	void SetStartupPromptVisible(const bool bVisible)
	{
		GStartupPromptVisible = bVisible;
	}

	bool IsProcessExitRequested()
	{
		return GProcessExitRequested;
	}

	void RequestProcessExit()
	{
		GProcessExitRequested = true;
	}

	void ResetProcessExitRequest()
	{
		GProcessExitRequested = false;
	}
}
