// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowSubsystem.h"

#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowType.h"
#include "GenericWindowWidget.h"
#include "Engine/Engine.h"
#include "WidgetType.h"

UGenericWindowSubsystem* UGenericWindowSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericWindowSubsystem>();
		}
	}

	return nullptr;
}

bool UGenericWindowSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer) && !IsRunningDedicatedServer();
}

void UGenericWindowSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UGenericWindowSubsystem::Deinitialize()
{
	CloseAllWindows();
	Super::Deinitialize();
}

UGenericWindowWidget* UGenericWindowSubsystem::CreateWindow(APlayerController* InPlayer, UGenericWindowDescriptor* InDescriptor, bool& bResult)
{
	bResult = false;

	if (!IsValid(InPlayer))
	{
		UE_LOG(GenericLogUI, Error, TEXT("CreateWindow failed because player is invalid."));
		return nullptr;
	}

	UGenericWindowWidget* NewWindow = NewObject<UGenericWindowWidget>(InPlayer);
	if (!IsValid(NewWindow))
	{
		UE_LOG(GenericLogUI, Error, TEXT("CreateWindow failed because window object could not be created."));
		return nullptr;
	}

	NewWindow->InitializeWindow(InPlayer, InDescriptor);
	NewWindow->OpenWindow();

	bResult = IsValid(NewWindow) && NewWindow->IsWindowOpen();

	return NewWindow;
}

bool UGenericWindowSubsystem::RegisterWindow(UGenericWindowWidget* InWindow)
{
	if (!IsValid(InWindow))
	{
		return false;
	}

	if (!RegisteredWindows.Contains(InWindow))
	{
		RegisteredWindows.Add(InWindow);

		if (UGenericWindowRuntimeState* RuntimeState = InWindow->GetWindowRuntimeState())
		{
			if (RuntimeState->ZOrder <= 0)
			{
				RuntimeState->ZOrder = AllocateZOrder();
			}
			else
			{
				NextZOrder = FMath::Max(NextZOrder, RuntimeState->ZOrder + 1);
			}
		}
	}

	return true;
}

bool UGenericWindowSubsystem::UnregisterWindow(UGenericWindowWidget* InWindow)
{
	if (!IsValid(InWindow))
	{
		return false;
	}

	return RegisteredWindows.Remove(InWindow) > 0;
}

void UGenericWindowSubsystem::CloseAllWindows()
{
	TArray<TObjectPtr<UGenericWindowWidget>> WindowsToClose = RegisteredWindows;
	for (UGenericWindowWidget* Window : WindowsToClose)
	{
		if (IsValid(Window))
		{
			Window->CloseWindow();
		}
	}

	RegisteredWindows.Reset();
}

bool UGenericWindowSubsystem::BringWindowToFront(UGenericWindowWidget* InWindow)
{
	if (!IsValid(InWindow))
	{
		return false;
	}

	if (!RegisteredWindows.Contains(InWindow))
	{
		RegisterWindow(InWindow);
	}

	if (UGenericWindowRuntimeState* RuntimeState = InWindow->GetWindowRuntimeState())
	{
		RuntimeState->ZOrder = AllocateZOrder();
		InWindow->RefreshWindowLayout();
		return true;
	}

	return false;
}

int32 UGenericWindowSubsystem::AllocateZOrder()
{
	return NextZOrder++;
}
