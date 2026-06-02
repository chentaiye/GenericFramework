// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Slate/GenericButtonStyle.h"

#include "Base/GenericButtonWidget.h"

namespace
{
	FSlateBrush MakeTransparentBrush()
	{
		FSlateBrush Brush;
		Brush.DrawAs = ESlateBrushDrawType::NoDrawType;
		Brush.TintColor = FSlateColor(FLinearColor::Transparent);
		return Brush;
	}
}

FButtonStyle UGenericButtonStyle::ToButtonStyle() const
{
	FButtonStyle ButtonStyle;
	ButtonStyle
		.SetNormal(Normal)
		.SetHovered(Hovered)
		.SetPressed(Pressed)
		.SetDisabled(Normal)
		.SetNormalForeground(NormalForeground)
		.SetHoveredForeground(HoveredForeground)
		.SetPressedForeground(PressedForeground)
		.SetDisabledForeground(NormalForeground)
		.SetNormalPadding(NormalPadding)
		.SetPressedPadding(PressedPadding)
		.SetHoveredSound(HoveredSlateSound)
		.SetPressedSound(PressedSlateSound);

	return ButtonStyle;
}

FButtonStyle UGenericButtonStyle::MakeTransparentButtonStyle()
{
	const FSlateBrush TransparentBrush = MakeTransparentBrush();
	const FSlateColor TransparentForeground(FLinearColor::Transparent);

	FButtonStyle ButtonStyle;
	ButtonStyle
		.SetNormal(TransparentBrush)
		.SetHovered(TransparentBrush)
		.SetPressed(TransparentBrush)
		.SetDisabled(TransparentBrush)
		.SetNormalForeground(TransparentForeground)
		.SetHoveredForeground(TransparentForeground)
		.SetPressedForeground(TransparentForeground)
		.SetDisabledForeground(TransparentForeground)
		.SetNormalPadding(FMargin())
		.SetPressedPadding(FMargin());

	return ButtonStyle;
}

#if WITH_EDITOR
void UGenericButtonStyle::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	for (UObject* OuterObject = GetOuter(); OuterObject; OuterObject = OuterObject->GetOuter())
	{
		if (UGenericButtonWidget* OwnerButtonWidget = Cast<UGenericButtonWidget>(OuterObject))
		{
			OwnerButtonWidget->RefreshButtonState(true);
			break;
		}
	}
}
#endif
