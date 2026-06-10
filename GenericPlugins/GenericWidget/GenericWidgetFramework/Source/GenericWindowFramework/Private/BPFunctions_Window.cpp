// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions_Window.h"

#include "Blueprint/UserWidget.h"
#include "GenericWindowDescriptor.h"
#include "GenericWindowSubsystem.h"
#include "GenericWindowWidget.h"
#include "WidgetType.h"

UGenericWindowDescriptor* UBPFunctions_Window::CreateWindowDescriptor(const UObject* WorldContextObject, TSubclassOf<UGenericWindowDescriptor> WindowDescriptorClass)
{
	UClass* DescriptorClass = WindowDescriptorClass ? WindowDescriptorClass.Get() : UGenericWindowDescriptor::StaticClass();
	UObject* Outer = WorldContextObject ? const_cast<UObject*>(WorldContextObject) : GetTransientPackage();
	return NewObject<UGenericWindowDescriptor>(Outer, DescriptorClass);
}

UGenericWindowWidget* UBPFunctions_Window::CreateWindow(const UObject* WorldContextObject, APlayerController* InPlayer, UGenericWindowDescriptor* WindowDescriptor, bool& bResult)
{
	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(WorldContextObject))
	{
		return WindowSubsystem->CreateWindow(InPlayer, WindowDescriptor, bResult);
	}

	bResult = false;
	return nullptr;
}

UGenericWindowWidget* UBPFunctions_Window::CreateWindowWithContentClass(const UObject* WorldContextObject, APlayerController* InPlayer, UGenericWindowDescriptor* WindowDescriptor, TSubclassOf<UUserWidget> ContentClass, bool& bResult)
{
	if (ContentClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("CreateWindowWithContentClass ignored ContentClass because UGenericWindowWidget no longer accepts child content. Configure WindowContentClass on the descriptor instead."));
	}

	return CreateWindow(WorldContextObject, InPlayer, WindowDescriptor, bResult);
}

bool UBPFunctions_Window::DestroyWindow(const UObject* WorldContextObject, UGenericWindowWidget* InWindow)
{
	if (!IsValid(InWindow))
	{
		return false;
	}

	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(WorldContextObject))
	{
		InWindow->CloseWindow();
		WindowSubsystem->UnregisterWindow(InWindow);
		return true;
	}

	return false;
}

bool UBPFunctions_Window::BringWindowToFront(const UObject* WorldContextObject, UGenericWindowWidget* InWindow)
{
	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(WorldContextObject))
	{
		return WindowSubsystem->BringWindowToFront(InWindow);
	}

	return false;
}
