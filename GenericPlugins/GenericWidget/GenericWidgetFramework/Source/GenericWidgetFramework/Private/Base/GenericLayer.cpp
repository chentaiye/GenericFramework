// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericLayer.h"

#include "Subsystem/GenericLayerSubsystem.h"
#include "WidgetType.h"

#if WITH_EDITOR
#include "Editor/WidgetCompilerLog.h"
#endif

UGenericLayer::UGenericLayer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	LayerTag = TAG_GameplayUI_Layer;
	bIsVariable = true;
}

void UGenericLayer::SetLayerVisibility(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

FGameplayTag UGenericLayer::GetRouteTag_Implementation() const
{
	return TAG_GameplayUI_Route_Layer;
}

ULocalPlayer* UGenericLayer::GetRouteOwnerPlayer_Implementation() const
{
	return GetOwningLocalPlayer();
}

#if WITH_EDITOR
void UGenericLayer::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!LayerTag.IsValid() || !LayerTag.MatchesTag(TAG_GameplayUI_Layer))
	{
		CompileLog.Error(FText::FromString(TEXT("Layer Tag Must Match GameplayUI.Layer")));
	}
}
#endif

TSharedRef<SWidget> UGenericLayer::RebuildWidget()
{
	TSharedRef<SWidget> RebuiltWidget = Super::RebuildWidget();

	if (!IsDesignTime() && bAutoRegister)
	{
		RegisterToLayerSubsystem();
	}

	return RebuiltWidget;
}

void UGenericLayer::ReleaseSlateResources(bool bReleaseChildren)
{
	if (!IsDesignTime())
	{
		UnregisterFromLayerSubsystem();
	}

	Super::ReleaseSlateResources(bReleaseChildren);
}

void UGenericLayer::RegisterToLayerSubsystem()
{
	if (UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(GetOwningLocalPlayer()))
	{
		LayerSubsystem->RegisterLayerAutomatically(this);
	}
}

void UGenericLayer::UnregisterFromLayerSubsystem()
{
	if (UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(GetOwningLocalPlayer()))
	{
		LayerSubsystem->UnregisterLayerAutomatically(this);
	}
}
