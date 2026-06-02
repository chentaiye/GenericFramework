// Copyright ChenTaiye 2025. All Rights Reserved.

#include "MenuType.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

#define LOCTEXT_NAMESPACE "MenuType"

UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_UI_OnMenuCollectionRegister, "GameplayMessage.Channel.UI.OnMenuCollectionRegister");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_UI_OnMenuCollectionUnRegister, "GameplayMessage.Channel.UI.OnMenuCollectionUnRegister");

namespace
{
bool IsMenuIDEmpty(const FString& InMenuID)
{
	return InMenuID.TrimStartAndEnd().IsEmpty();
}
}

void FMenuIDTableRow::OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems)
{
	SyncMenuIDFromTag();

	if (IsMenuIDEmpty(GetResolvedMenuID()))
	{
		OutCollectedImportProblems.Add(FString::Printf(TEXT("MenuID is empty for row '%s'."), *InRowName.ToString()));
	}
}

void FMenuIDTableRow::OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName)
{
	SyncMenuIDFromTag();
}

#if WITH_EDITOR
EDataValidationResult FMenuIDTableRow::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = EDataValidationResult::Valid;

	if (MenuTag.IsValid() && !MenuTag.MatchesTag(TAG_GameplayUI_Button))
	{
		Context.AddError(LOCTEXT("InvalidMenuTag", "MenuTag must be under GameplayUI.Button."));
		Result = EDataValidationResult::Invalid;
	}

	if (IsMenuIDEmpty(GetResolvedMenuID()))
	{
		Context.AddError(LOCTEXT("EmptyMenuID", "MenuID must not be empty."));
		Result = EDataValidationResult::Invalid;
	}

	return Result;
}
#endif

void FMenuIDTableRow::SyncMenuIDFromTag()
{
	if (MenuTag.IsValid())
	{
		MenuID = MenuTag.ToString();
	}
}

FString FMenuIDTableRow::GetResolvedMenuID() const
{
	return MenuTag.IsValid() ? MenuTag.ToString() : MenuID;
}

void FMenuTableRow::OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems)
{
	MenuID.OnPostDataImport(InDataTable, InRowName, OutCollectedImportProblems);
}

void FMenuTableRow::OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName)
{
	MenuID.OnDataTableChanged(InDataTable, InRowName);
}

#if WITH_EDITOR
EDataValidationResult FMenuTableRow::IsDataValid(FDataValidationContext& Context) const
{
	return MenuID.IsDataValid(Context);
}
#endif

#undef LOCTEXT_NAMESPACE
