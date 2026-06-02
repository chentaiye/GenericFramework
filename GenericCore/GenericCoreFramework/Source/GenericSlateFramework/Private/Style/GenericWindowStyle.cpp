// Copyright ChenTaiye 2025. All Rights Reserved. 

#include "Style/GenericWindowStyle.h"

#include "Style/DevSlateButtonStyle.h"
#include "Style/GenericTextBlockStyle.h"
#include "Misc/EngineVersionComparison.h"

void UGenericWindowStyle::GetWindowStyle(FWindowStyle& OutWindowStyle) const
{
#if !PLATFORM_MAC
	FButtonStyle WindowMinimizeButtonStyle;
	if (IsValid(MinimizeButtonStyleClass))
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UDevSlateButtonStyle* StyleCDO = Cast<UDevSlateButtonStyle>(MinimizeButtonStyleClass->ClassDefaultObject);
#else
		const UDevSlateButtonStyle* StyleCDO = GetDefault<UDevSlateButtonStyle>(MinimizeButtonStyleClass);
#endif
		if (StyleCDO)
		{
			StyleCDO->GetButtonStyle(WindowMinimizeButtonStyle);
		}
	}
	
	FButtonStyle WindowMaximizeButtonStyle;
	if (IsValid(MaximizeButtonStyle))
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UDevSlateButtonStyle* StyleCDO = Cast<UDevSlateButtonStyle>(MaximizeButtonStyle->ClassDefaultObject);
#else
		const UDevSlateButtonStyle* StyleCDO = GetDefault<UDevSlateButtonStyle>(MaximizeButtonStyle);
#endif
		if (StyleCDO)
		{
			StyleCDO->GetButtonStyle(WindowMaximizeButtonStyle);
		}
	}

	FButtonStyle WindowRestoreButtonStyle;
	if (IsValid(RestoreButtonStyle))
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UDevSlateButtonStyle* StyleCDO = Cast<UDevSlateButtonStyle>(RestoreButtonStyle->ClassDefaultObject);
#else
		const UDevSlateButtonStyle* StyleCDO = GetDefault<UDevSlateButtonStyle>(RestoreButtonStyle);
#endif
		if (StyleCDO)
		{
			StyleCDO->GetButtonStyle(WindowRestoreButtonStyle);
		}
	}

	FButtonStyle WindowCloseButtonStyle;
	if (IsValid(CloseButtonStyle))
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UDevSlateButtonStyle* StyleCDO = Cast<UDevSlateButtonStyle>(CloseButtonStyle->ClassDefaultObject);
#else
		const UDevSlateButtonStyle* StyleCDO = GetDefault<UDevSlateButtonStyle>(CloseButtonStyle);
#endif
		if (StyleCDO)
		{
			StyleCDO->GetButtonStyle(WindowCloseButtonStyle);
		}
	}
#endif

	FTextBlockStyle WindowTitleTextStyle;
	if (IsValid(TitleTextStyle))
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UGenericTextBlockStyle* StyleCDO = Cast<UGenericTextBlockStyle>(TitleTextStyle->ClassDefaultObject);
#else
		const UGenericTextBlockStyle* StyleCDO = GetDefault<UGenericTextBlockStyle>(TitleTextStyle);
#endif
		if (StyleCDO)
		{
			StyleCDO->GetTextBlockStyle(WindowTitleTextStyle);
		}
	}

	OutWindowStyle
#if !PLATFORM_MAC
		.SetMinimizeButtonStyle(WindowMinimizeButtonStyle)
		.SetMaximizeButtonStyle(WindowMaximizeButtonStyle)
		.SetRestoreButtonStyle(WindowRestoreButtonStyle)
		.SetCloseButtonStyle(WindowCloseButtonStyle)
#endif
		.SetTitleTextStyle(WindowTitleTextStyle)
		.SetActiveTitleBrush(ActiveTitleBrush)
		.SetInactiveTitleBrush(InactiveTitleBrush)
		.SetFlashTitleBrush(FlashTitleBrush)
		.SetBackgroundBrush(BackgroundBrush)
		.SetBorderBrush(BorderBrush)
		.SetOutlineBrush(OutlineBrush)
		.SetChildBackgroundBrush(ChildBackgroundBrush)
		.SetCornerRadius(CornerRadius)
		.SetBorderPadding(BorderPadding);
}
