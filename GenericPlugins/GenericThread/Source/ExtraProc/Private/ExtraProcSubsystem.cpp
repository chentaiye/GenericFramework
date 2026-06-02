// Copyright ChenTaiye 2025. All Rights Reserved.

#include "ExtraProcSubsystem.h"

#include "ExtraProcSettings.h"
#include "StaticFunctions_ExtraProc.h"
#include "GenericThreadSubsystem.h"
#include "BPFunctions/BPFunctions_Desktop.h"
#include "Async/TaskGraphInterfaces.h"
#include "Async/Async.h"
#include "Type/DebugType.h"

#if PLATFORM_WINDOWS
#include "Platform/WindowsExtraProcHelper.h"
#endif

#if WITH_EDITOR
#include "Editor.h"
#endif

UExtraProcSubsystem* UExtraProcSubsystem::Get()
{
	return GEngine ? GEngine->GetEngineSubsystem<UExtraProcSubsystem>() : nullptr;
}

void UExtraProcSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

#if WITH_EDITOR
	FEditorDelegates::BeginPIE.AddUObject(this, &UExtraProcSubsystem::BeginPIE);
	FEditorDelegates::EndPIE.AddUObject(this, &UExtraProcSubsystem::EndPIE);
#else
	LaunchAllProc();
#endif

	if (!FPaths::DirectoryExists(GetExtraProcPath()))
	{
		UBPFunctions_Desktop::CreateDirectory(GetExtraProcPath());
	}
}

void UExtraProcSubsystem::Deinitialize()
{
	Super::Deinitialize();

#if WITH_EDITOR
	FEditorDelegates::BeginPIE.RemoveAll(this);
	FEditorDelegates::EndPIE.RemoveAll(this);
#else
	DestroyAllProc();
#endif
}

#if WITH_EDITOR

void UExtraProcSubsystem::BeginPIE(bool bIsSimulating)
{
	LaunchAllProc();
}

void UExtraProcSubsystem::EndPIE(bool bIsSimulating)
{
	DestroyAllProc();
}

#endif

void UExtraProcSubsystem::LaunchAllProc()
{
	for (auto ProcInfo : UExtraProcSettings::Get()->AutoStartUpExtraProcList)
	{
		if (!ProcInfo.bAutoLaunch)
		{
			continue;
		}

		FGuid ProcGuid;
		if (!FStaticFunctions_ExtraProc::LaunchExtraProc(ProcInfo.ExtraStartProcInfo, ProcGuid))
		{
			GenericLOG(GenericLogExtraProc, Warning, TEXT("Auto launch extra start proc fail. Execute path : %s"), *ProcInfo.ExtraStartProcInfo.ProcFile.FilePath)
			return;
		}

		ProcGuids.Add(ProcGuid);
	}
}

void UExtraProcSubsystem::DestroyAllProc()
{
	for (auto& ProcGuid : ProcGuids)
	{
		FStaticFunctions_ExtraProc::TerminateExtraProc(ProcGuid);
	}

	ProcGuids.Reset();
}

FString UExtraProcSubsystem::GetExtraProcPath()
{
	return FPaths::Combine(UBPFunctions_Desktop::GetExtrasDir(), TEXT("Proc"));
}

