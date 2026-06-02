#pragma once

#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

#define GenericLOG(CategoryName, Verbosity, Format, ...) \
UE_LOG(CategoryName, Type::Verbosity, TEXT("[Line:%d %s] %s"), __LINE__, ANSI_TO_TCHAR(__FUNCTION__), *FString::Printf(Format, ##__VA_ARGS__))

#define GenericPRINT(Verbosity, Format, ...) \
if(IsValid(GEngine)){ \
	if (::ELogVerbosity::Verbosity == ::ELogVerbosity::Error) \
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(Format, ##__VA_ARGS__)); \
	else if (::ELogVerbosity::Verbosity == ::ELogVerbosity::Warning) \
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, FString::Printf(Format, ##__VA_ARGS__)); \
	else \
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(Format, ##__VA_ARGS__)); \
}

#define GenericNOTIFY(Format, ...) \
{ \
	FNotificationInfo NotificationInfo(FText::FromString(FString::Printf(TEXT("%s"),ANSI_TO_TCHAR(__FUNCTION__)))); \
	NotificationInfo.SubText = FText::FromString(FString::Printf(Format, ##__VA_ARGS__)); \
	NotificationInfo.FadeInDuration = 0.5f; \
	NotificationInfo.FadeOutDuration = 0.5f; \
	NotificationInfo.ExpireDuration = 10.f; \
	FSlateNotificationManager::Get().AddNotification(NotificationInfo); \
}

#define GenericEnsureLOG(CategoryName, InExpression, ...) \
if (!ensure(InExpression)){ \
GenericLOG(CategoryName, Warning, TEXT("Expression : (%s) Result Is Fail"), #InExpression, ##__VA_ARGS__) \
return; \
}

#define GenericEnsureAlwaysLOG(CategoryName, InExpression, ...) \
if (!ensureAlways(InExpression)){ \
GenericLOG(CategoryName, Warning, TEXT("Expression : (%s) Result Is Fail, %s"), ##InExpression, ##__VA_ARGS__) \
return; \
}

/* FNotificationInfo :
	TSharedPtr＜INotificationWidget＞ContentWidget;
	TAttribute＜FText＞Text;
	TAttribute＜FText＞ SubText;
	TArray<FNotificationButtonInfo> ButtonDetails;
	const FSlateBrush* Image;
	float FadeInDuration;
	float FadeOutDuration;
	float ExpireDuration;
	bool bUseThrobber;
	bool bUseSuccessFailIcons;
	bool bUseLargeFont;
	FOptionalSize WidthOverride;
	bool bFireAndForget;
	TAttribute<ECheckBoxState> CheckBoxState;
	FOnCheckStateChanged CheckBoxStateChanged;
	TAttribute<FText> CheckBoxText;
	FSimpleDelegate Hyperlink;
	TAttribute<FText> HyperlinkText;
	TSharedPtr<SWindow> ForWindow;
	bool bAllowThrottleWhenFrameRateIsLow;
*/
