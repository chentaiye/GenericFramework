#include "Detail/GenericCoordinateCustomization.h"

#include "DetailWidgetRow.h"
#include "PropertyHandle.h"
#include "RealGeoreferencingType.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/Text/STextBlock.h"

TSharedRef<IPropertyTypeCustomization> FGenericCoordinateCustomization::MakeInstance()
{
	return MakeShared<FGenericCoordinateCustomization>();
}

void FGenericCoordinateCustomization::CustomizeHeader(
	TSharedRef<IPropertyHandle> StructPropertyHandle,
	FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	TSharedPtr<IPropertyHandle> LatHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGenericCoordinate, CoordinateLat));
	TSharedPtr<IPropertyHandle> LonHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGenericCoordinate, CoordinateLon));
	TSharedPtr<IPropertyHandle> AltHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGenericCoordinate, CoordinateAlt));

	HeaderRow
	.NameContent()
	[
		StructPropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(480.0f)
	[
		SNew(SHorizontalBox)

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(0.0f, 0.0f, 4.0f, 0.0f)
		[
			SNew(STextBlock)
			.Text(NSLOCTEXT("RealGeoreferencingEdFramework", "GenericCoordinateLatLabel", "Lat"))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		.Padding(0.0f, 0.0f, 8.0f, 0.0f)
		[
			LatHandle.IsValid() ? LatHandle->CreatePropertyValueWidget() : SNullWidget::NullWidget
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(0.0f, 0.0f, 4.0f, 0.0f)
		[
			SNew(STextBlock)
			.Text(NSLOCTEXT("RealGeoreferencingEdFramework", "GenericCoordinateLonLabel", "Lon"))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		.Padding(0.0f, 0.0f, 8.0f, 0.0f)
		[
			LonHandle.IsValid() ? LonHandle->CreatePropertyValueWidget() : SNullWidget::NullWidget
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(0.0f, 0.0f, 4.0f, 0.0f)
		[
			SNew(STextBlock)
			.Text(NSLOCTEXT("RealGeoreferencingEdFramework", "GenericCoordinateAltLabel", "Alt"))
		]

		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			AltHandle.IsValid() ? AltHandle->CreatePropertyValueWidget() : SNullWidget::NullWidget
		]
	];
}

void FGenericCoordinateCustomization::CustomizeChildren(
	TSharedRef<IPropertyHandle> StructPropertyHandle,
	IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}
