// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/WorldWidgetPoint.h"

#include "Base/WorldWidgetComponent.h"

AWorldWidgetPoint::AWorldWidgetPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	WorldWidgetComponent = CreateDefaultSubobject<UWorldWidgetComponent>(TEXT("WorldWidgetComponent"));
	RootComponent = WorldWidgetComponent;
}
