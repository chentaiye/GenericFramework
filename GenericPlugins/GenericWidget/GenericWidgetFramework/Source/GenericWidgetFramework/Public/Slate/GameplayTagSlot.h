// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/NamedSlot.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "NativeGameplayTags.h"
#include "GameplayTagSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotContentChanged, UWidget*, Widget);

/** Gameplay-tagged slot that auto-registers with the local slot subsystem at runtime. */
UCLASS(MinimalAPI)
class UGameplayTagSlot : public UNamedSlot, public IGenericRouteInterface
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return NSLOCTEXT("GenericFramework", "WidgetPaletteCategory", "GenericFramework"); }
	GENERICWIDGETFRAMEWORK_API virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif
	GENERICWIDGETFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICWIDGETFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	GENERICWIDGETFRAMEWORK_API virtual void OnSlotAdded(UPanelSlot* InSlot) override;
	GENERICWIDGETFRAMEWORK_API virtual void OnSlotRemoved(UPanelSlot* InSlot) override;

private:
	void RegisterToSlotSubsystem();
	void UnregisterFromSlotSubsystem();

public:
	GENERICWIDGETFRAMEWORK_API UGameplayTagSlot(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAutoRegister = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayTag Slot", meta=(Categories="GameplayUI.Slot"))
	FGameplayTag SlotTag;

	UFUNCTION(BlueprintCallable, Category="GameplayTag Slot")
	GENERICWIDGETFRAMEWORK_API void SetSlotVisibility(ESlateVisibility InVisibility);

	GENERICWIDGETFRAMEWORK_API virtual FGameplayTag GetRouteTag_Implementation() const override;
	GENERICWIDGETFRAMEWORK_API virtual ULocalPlayer* GetRouteOwnerPlayer_Implementation() const override;

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnSlotContentChanged OnSlotContentAdded;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnSlotContentChanged OnSlotContentRemoved;
};
