// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "GenericLayoutSubsystem.generated.h"

class APlayerController;
class UGenericLayout;

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnLayoutRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Layout Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layout Registered Message")
	TObjectPtr<UGenericLayout> Layout = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnLayoutUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Layout Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layout Unregistered Message")
	TObjectPtr<UGenericLayout> Layout = nullptr;
};

/** Local-player registry for the single active GenericLayout. */
UCLASS(MinimalAPI)
class UGenericLayoutSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericLayoutSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericLayoutSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** Register an existing layout. */
	GENERICWIDGETFRAMEWORK_API bool RegisterLayout(UGenericLayout* InLayout);

	/** Create and register a layout class for this local player. */
	GENERICWIDGETFRAMEWORK_API UGenericLayout* RegisterLayout(TSubclassOf<UGenericLayout> InLayoutClass, bool bAddToScreen = true, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible, int32 ZOrder = 0);

	/** Unregister the current layout. */
	GENERICWIDGETFRAMEWORK_API bool UnregisterLayout(UGenericLayout* InLayout);

	/** Return the current layout. */
	GENERICWIDGETFRAMEWORK_API UGenericLayout* GetLayout() const;

	/** Return whether a live layout is currently registered. */
	GENERICWIDGETFRAMEWORK_API bool HasLayout() const;

public:
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	bool IsLayoutOwnedByThisSubsystem(const UGenericLayout* InLayout) const;

private:
	UPROPERTY()
	TObjectPtr<UGenericLayout> Layout = nullptr;

	UPROPERTY()
	bool bLayoutAddedToScreenBySubsystem = false;
};
