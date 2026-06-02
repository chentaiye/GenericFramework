#include "AsyncFunctions/AcquireAndroidPermissionAsyncAction.h"

#if PLATFORM_ANDROID
#include "AndroidPermissionCallbackProxy.h"
#include "AndroidPermissionFunctionLibrary.h"
#endif

void UAcquireAndroidPermissionAsyncAction::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (Permissions.IsEmpty())
	{
		FFrame::KismetExecutionMessage(TEXT("AsyncAcquireAndroidPermission requires at least one permission string."), ELogVerbosity::Error);
		OnFail.Broadcast(Permissions);
		return;
	}

	for (const FString& Permission : Permissions)
	{
		if (!UAndroidPermissionFunctionLibrary::CheckPermission(Permission))
		{
			PermissionsNotAcquired.Add(Permission);
		}
	}

	if (PermissionsNotAcquired.IsEmpty())
	{
		OnSuccess.Broadcast();
		return;
	}

	UAndroidPermissionCallbackProxy::GetInstance()->OnPermissionsGrantedDelegate.AddUObject(this, &UAcquireAndroidPermissionAsyncAction::OnPermissionsGranted);
	UAndroidPermissionFunctionLibrary::AcquirePermissions(PermissionsNotAcquired);
#else
	OnFail.Broadcast(Permissions);
#endif
}

UAcquireAndroidPermissionAsyncAction* UAcquireAndroidPermissionAsyncAction::AsyncAcquireAndroidPermission(const FString& InPermission)
{
	UAcquireAndroidPermissionAsyncAction* NewAction = NewObject<UAcquireAndroidPermissionAsyncAction>();
	NewAction->Permissions.Add(InPermission);
	return NewAction;
}

UAcquireAndroidPermissionAsyncAction* UAcquireAndroidPermissionAsyncAction::AsyncAcquireAndroidPermissions(const TArray<FString>& InPermissions)
{
	UAcquireAndroidPermissionAsyncAction* NewAction = NewObject<UAcquireAndroidPermissionAsyncAction>();
	NewAction->Permissions = InPermissions;
	return NewAction;
}

void UAcquireAndroidPermissionAsyncAction::OnPermissionsGranted(const TArray<FString>& InPermissions, const TArray<bool>& InGrantResults)
{
#if PLATFORM_ANDROID
	UAndroidPermissionCallbackProxy::GetInstance()->OnPermissionsGrantedDelegate.RemoveAll(this);

	for (int32 Index = 0; Index < InGrantResults.Num(); ++Index)
	{
		if (!InGrantResults[Index] && InPermissions.IsValidIndex(Index))
		{
			FailPermissions.Add(InPermissions[Index]);
		}
	}

	if (FailPermissions.IsEmpty())
	{
		OnSuccess.Broadcast();
	}
	else
	{
		OnFail.Broadcast(FailPermissions);
	}
#endif
}
