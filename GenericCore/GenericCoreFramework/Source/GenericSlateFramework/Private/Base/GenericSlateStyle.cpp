#include "Base/GenericSlateStyle.h"

#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

FName FGenericSlateStyle::StyleSetName = TEXT("GenericSlateStyle");
TSharedPtr<FGenericSlateStyle::FStyle> FGenericSlateStyle::Instance = nullptr;
bool FGenericSlateStyle::bIsRegistered = false;

void FGenericSlateStyle::Initialize()
{
	FSlateApplication::InitializeCoreStyle();

	if (!Instance)
	{
		Instance = Create();
	}

	if (!bIsRegistered)
	{
		FSlateStyleRegistry::RegisterSlateStyle(*Instance.Get());
		bIsRegistered = true;
	}
}

void FGenericSlateStyle::ShoutDown()
{
	if (Instance)
	{
		if (bIsRegistered)
		{
			FSlateStyleRegistry::UnRegisterSlateStyle(*Instance.Get());
			bIsRegistered = false;
		}
		Instance.Reset();
	}
}

const ISlateStyle& FGenericSlateStyle::Get()
{
	Initialize();
	return *Instance.Get();
}

void FGenericSlateStyle::Set(const FName& PropertyName, FSlateBrush* Brush)
{
	Initialize();
	Instance->Set(PropertyName, Brush);
}

FGenericSlateStyle::FStyle::FStyle()
	: FSlateStyleSet(FGenericSlateStyle::StyleSetName)
{
}

FGenericSlateStyle::FStyle::~FStyle()
{
}

void FGenericSlateStyle::FStyle::Initialize()
{
	SetParentStyleName("CoreStyle");
}

TSharedRef<FGenericSlateStyle::FStyle> FGenericSlateStyle::Create()
{
	TSharedRef<class FGenericSlateStyle::FStyle> NewStyle = MakeShareable(new FGenericSlateStyle::FStyle());
	NewStyle->Initialize();
	return NewStyle;
}
