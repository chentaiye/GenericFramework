// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultCameraTask.h"

#include "CameraSwitch/GenericCameraSwitchMethod.h"
#include "CameraSwitch/GenericCameraSwitchMethod_Teleport.h"
#include "CameraType.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Misc/EngineVersionComparison.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericCameraLocalPlayerSubsystem.h"
#include "Subsystem/GenericCameraSubsystem.h"

namespace UE::GenericCamera::LoadDefaultCameraTask
{
	static UWorld* ResolveWorld(FStateTreeExecutionContext& Context)
	{
		if (UWorld* World = Context.GetWorld())
		{
			return World;
		}

#if UE_VERSION_OLDER_THAN(5, 7, 0)
		for (const FStateTreeExternalDataDesc& Desc : Context.GetContextDataDescs())
		{
			if (Desc.Name == FName(TEXT("World")))
			{
				return Context.GetExternalDataView(Desc.Handle).GetMutablePtr<UWorld>();
			}
		}
		return nullptr;
#else
		const FStateTreeDataView WorldData = Context.GetContextDataByName(FName(TEXT("World")));
		return WorldData.GetMutablePtr<UWorld>();
#endif
	}

	static UGenericCameraSwitchMethod* CreateRuntimeSwitchMethod(UObject* Outer, const UGenericCameraSwitchMethod* SwitchMethodTemplate)
	{
		if (!Outer)
		{
			return nullptr;
		}

		if (SwitchMethodTemplate)
		{
			return DuplicateObject<UGenericCameraSwitchMethod>(SwitchMethodTemplate, Outer);
		}

		return NewObject<UGenericCameraSwitchMethod_Teleport>(Outer);
	}
}

FLoadDefaultCameraTask::FLoadDefaultCameraTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadDefaultCameraTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UWorld* World = UE::GenericCamera::LoadDefaultCameraTask::ResolveWorld(Context);
	if (!World)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (!DefaultCameraTag.IsValid())
	{
		return EStateTreeRunStatus::Succeeded;
	}

	bool bHasLocalPlayer = false;
	bool bHasFailure = false;
	for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PlayerController = It->Get();
		if (!PlayerController || !PlayerController->IsLocalController())
		{
			continue;
		}

		bHasLocalPlayer = true;

		UGenericCameraLocalPlayerSubsystem* CameraLocalPlayerSubsystem = UGenericCameraLocalPlayerSubsystem::Get(PlayerController);
		if (!CameraLocalPlayerSubsystem)
		{
			bHasFailure = true;
			UE_LOG(GenericLogCamera, Warning, TEXT("LoadDefaultCameraTask failed to find camera subsystem."));
			continue;
		}

		UGenericCameraSubsystem* CameraSubsystem = UGenericCameraSubsystem::Get(World);
		if (!CameraSubsystem)
		{
			bHasFailure = true;
			UE_LOG(GenericLogCamera, Warning, TEXT("LoadDefaultCameraTask failed to find world camera subsystem."));
			continue;
		}

		if (!CameraSubsystem->CanSwitchToCamera(DefaultCameraTag))
		{
			bHasFailure = true;
			UE_LOG(GenericLogCamera, Warning, TEXT("LoadDefaultCameraTask failed to find default camera point. CameraTag: %s"), *DefaultCameraTag.ToString());
			continue;
		}

		UGenericCameraSwitchMethod* RuntimeSwitchMethod = UE::GenericCamera::LoadDefaultCameraTask::CreateRuntimeSwitchMethod(CameraLocalPlayerSubsystem, DefaultCameraSwitchMethod);
		if (!RuntimeSwitchMethod)
		{
			bHasFailure = true;
			UE_LOG(GenericLogCamera, Warning, TEXT("LoadDefaultCameraTask failed to create default camera switch method."));
			continue;
		}

		if (!CameraLocalPlayerSubsystem->SwitchToCamera(DefaultCameraTag, RuntimeSwitchMethod))
		{
			bHasFailure = true;
			UE_LOG(GenericLogCamera, Warning, TEXT("LoadDefaultCameraTask failed to switch default camera. CameraTag: %s"), *DefaultCameraTag.ToString());
		}
	}

	if (!bHasLocalPlayer)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return bHasFailure ? EStateTreeRunStatus::Failed : EStateTreeRunStatus::Succeeded;
}
