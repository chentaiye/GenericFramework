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
FString JoinMenuIDSegments(const TArray<FString>& InSegments)
{
	FString Result;
	for (int32 SegmentIndex = 0; SegmentIndex < InSegments.Num(); ++SegmentIndex)
	{
		if (SegmentIndex > 0)
		{
			Result += TEXT(".");
		}
		Result += InSegments[SegmentIndex];
	}
	return Result;
}
}

const FString& FMenuIDTableRow::GetMenuIDRootPath()
{
	static const FString MenuIDRootPath(TEXT("GameplayUI.Button"));
	return MenuIDRootPath;
}

FString FMenuIDTableRow::MakeMenuID(const FString& InEditableMenuIDPath)
{
	FString EditableMenuIDPath = InEditableMenuIDPath.TrimStartAndEnd();
	const FString RootPath = GetMenuIDRootPath();
	const FString RootPrefix = RootPath + TEXT(".");

	if (EditableMenuIDPath.StartsWith(RootPrefix))
	{
		return EditableMenuIDPath;
	}

	if (EditableMenuIDPath == RootPath)
	{
		return RootPath;
	}

	while (EditableMenuIDPath.StartsWith(TEXT(".")))
	{
		EditableMenuIDPath.RightChopInline(1);
	}

	if (EditableMenuIDPath.IsEmpty())
	{
		return RootPath;
	}

	return RootPrefix + EditableMenuIDPath;
}

FString FMenuIDTableRow::GetEditableMenuIDPath(const FString& InMenuID)
{
	const FString MenuIDPath = InMenuID.TrimStartAndEnd();
	const FString RootPath = GetMenuIDRootPath();
	const FString RootPrefix = RootPath + TEXT(".");

	if (MenuIDPath.StartsWith(RootPrefix))
	{
		return MenuIDPath.RightChop(RootPrefix.Len());
	}

	if (MenuIDPath == RootPath)
	{
		return FString();
	}

	return MenuIDPath;
}

bool FMenuIDTableRow::SplitMenuIDPath(const FString& InMenuID, TArray<FString>& OutEditableSegments, FText* OutError)
{
	OutEditableSegments.Reset();

	const FString MenuIDPath = MakeMenuID(GetEditableMenuIDPath(InMenuID));
	const FString RootPath = GetMenuIDRootPath();
	const FString RootPrefix = RootPath + TEXT(".");

	if (MenuIDPath == RootPath)
	{
		if (OutError)
		{
			*OutError = LOCTEXT("MenuIDMissingEditablePath", "MenuID must add a value after GameplayUI.Button.");
		}
		return false;
	}

	if (!MenuIDPath.StartsWith(RootPrefix))
	{
		if (OutError)
		{
			*OutError = LOCTEXT("MenuIDInvalidRootPath", "MenuID must start with GameplayUI.Button.");
		}
		return false;
	}

	const FString EditablePath = MenuIDPath.RightChop(RootPrefix.Len()).TrimStartAndEnd();
	EditablePath.ParseIntoArray(OutEditableSegments, TEXT("."), false);
	if (OutEditableSegments.IsEmpty())
	{
		if (OutError)
		{
			*OutError = LOCTEXT("MenuIDEmptyEditablePath", "MenuID must add a non-empty value after GameplayUI.Button.");
		}
		return false;
	}

	for (FString& Segment : OutEditableSegments)
	{
		Segment = Segment.TrimStartAndEnd();
		if (Segment.IsEmpty())
		{
			if (OutError)
			{
				*OutError = LOCTEXT("MenuIDEmptySegment", "MenuID must not contain empty path segments.");
			}
			return false;
		}
	}

	if (JoinMenuIDSegments(OutEditableSegments) != EditablePath)
	{
		if (OutError)
		{
			*OutError = LOCTEXT("MenuIDInvalidSeparator", "MenuID must use single dots between path segments.");
		}
		return false;
	}

	return true;
}

void FMenuIDTableRow::OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems)
{
	SyncMenuIDFromTag();

	TArray<FString> MenuIDSegments;
	FText MenuIDError;
	if (!SplitMenuIDPath(MenuID, MenuIDSegments, &MenuIDError))
	{
		OutCollectedImportProblems.Add(FString::Printf(TEXT("%s Row: '%s'."), *MenuIDError.ToString(), *InRowName.ToString()));
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

	TArray<FString> MenuIDSegments;
	FText MenuIDError;
	if (!SplitMenuIDPath(MenuID, MenuIDSegments, &MenuIDError))
	{
		Context.AddError(MenuIDError);
		Result = EDataValidationResult::Invalid;
	}

	return Result;
}
#endif

void FMenuIDTableRow::SyncMenuIDFromTag()
{
	if (MenuTag.IsValid() && MenuID.TrimStartAndEnd() == GetMenuIDRootPath())
	{
		MenuID = MenuTag.ToString();
	}

	NormalizeMenuID();
}

void FMenuIDTableRow::NormalizeMenuID()
{
	MenuID = MakeMenuID(GetEditableMenuIDPath(MenuID));
}

FString FMenuIDTableRow::GetResolvedMenuID() const
{
	const FString NormalizedMenuID = MakeMenuID(GetEditableMenuIDPath(MenuID));
	TArray<FString> MenuIDSegments;
	if (SplitMenuIDPath(NormalizedMenuID, MenuIDSegments))
	{
		return NormalizedMenuID;
	}

	return MenuTag.IsValid() ? MakeMenuID(GetEditableMenuIDPath(MenuTag.ToString())) : NormalizedMenuID;
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
