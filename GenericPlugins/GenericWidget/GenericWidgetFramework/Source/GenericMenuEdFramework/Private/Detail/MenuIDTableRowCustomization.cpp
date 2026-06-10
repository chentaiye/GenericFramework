// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Detail/MenuIDTableRowCustomization.h"

#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "MenuType.h"
#include "PropertyHandle.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "FMenuIDTableRowCustomization"

TSharedRef<IPropertyTypeCustomization> FMenuIDTableRowCustomization::MakeInstance()
{
	return MakeShared<FMenuIDTableRowCustomization>();
}

void FMenuIDTableRowCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	MenuIDHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMenuIDTableRow, MenuID));

	HeaderRow
	.NameContent()
	[
		StructPropertyHandle->CreatePropertyNameWidget()
	];
}

void FMenuIDTableRowCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	TSharedPtr<IPropertyHandle> MenuTagHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMenuIDTableRow, MenuTag));
	if (MenuTagHandle.IsValid())
	{
		StructBuilder.AddProperty(MenuTagHandle.ToSharedRef());
	}

	if (MenuIDHandle.IsValid())
	{
		StructBuilder.AddCustomRow(LOCTEXT("MenuIDFilterText", "Menu ID"))
			.NameContent()
			[
				MenuIDHandle->CreatePropertyNameWidget()
			]
			.ValueContent()
			.MinDesiredWidth(320.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.IsEnabled(false)
					.Text(FText::FromString(FMenuIDTableRow::GetMenuIDRootPath()))
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(2.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("MenuIDSeparator", "."))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(SEditableTextBox)
					.Text(this, &FMenuIDTableRowCustomization::GetEditableMenuIDText)
					.ToolTipText(LOCTEXT("MenuIDEditableTooltip", "Input the path after GameplayUI.Button. Empty values fail menu validation."))
					.SelectAllTextWhenFocused(true)
					.OnTextCommitted(this, &FMenuIDTableRowCustomization::HandleEditableMenuIDCommitted)
				]
			];
	}
}

FText FMenuIDTableRowCustomization::GetEditableMenuIDText() const
{
	FString MenuIDValue;
	if (MenuIDHandle.IsValid() && MenuIDHandle->GetValue(MenuIDValue) == FPropertyAccess::Success)
	{
		return FText::FromString(FMenuIDTableRow::GetEditableMenuIDPath(MenuIDValue));
	}

	return FText::GetEmpty();
}

void FMenuIDTableRowCustomization::HandleEditableMenuIDCommitted(const FText& InText, ETextCommit::Type InCommitType) const
{
	if (!MenuIDHandle.IsValid())
	{
		return;
	}

	MenuIDHandle->SetValue(FMenuIDTableRow::MakeMenuID(InText.ToString()));
}

#undef LOCTEXT_NAMESPACE
