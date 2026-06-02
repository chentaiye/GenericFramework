//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "SlateCefJSDialog.h"
#pragma endregion

#pragma region <Engine Headers>
// Slate/Public/
#include <SlateOptMacros.h>
#include <Widgets/Input/SButton.h>
#include <Widgets/Input/SEditableTextBox.h>
#include <Widgets/Layout/SSpacer.h>
#include <Widgets/Layout/SBorder.h>
#include <Widgets/Layout/SBox.h>
#include <Widgets/Text/STextBlock.h>
// SlateCore/Public/
#include <Widgets/SBoxPanel.h>
#include <Layout/Margin.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#pragma endregion

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void
SlateCefJSDialog::Construct(const FArguments& InArgs)
{
  Type = InArgs._Type;
  Title = InArgs._Title;
  Message = InArgs._Message;
  Prompt = InArgs._Prompt;
  MaskColor = InArgs._MaskColor;
  OnContinueDelegate = InArgs._OnContinue;

  SBorder::FArguments SuperArgs;
  SuperArgs.BorderBackgroundColor(MaskColor);
  SuperArgs.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"));
  SuperArgs.VAlign(VAlign_Center);
  SuperArgs.HAlign(HAlign_Center);
  SBorder::Construct(SuperArgs);

  switch (Type) {
    case EDialogType::ConfirmDialog:
      SetContent(CreateConfirm());
      break;
    case EDialogType::PromptDialog:
      SetContent(CreatePrompt());
      break;
    default:
      SetContent(CreateAlert());
      break;
  }

  SetCursor(EMouseCursor::Type::Default);
}

TSharedRef<SWidget>
SlateCefJSDialog::CreateAlert()
{
  return SNew(SBox)                                                             //
    .WidthOverride(680.0f)                                                      //
      [SNew(SBorder)                                                            //
         .BorderBackgroundColor(FLinearColor::Black)                            //
         .BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))                 //
         .Padding(6)[                                                           //
           /*dialog content*/                                                   //
           SNew(SVerticalBox)                                                   //
           /*dialog title*/                                                     //
           + SVerticalBox::Slot()                                               //
               .Padding(6)                                                      //
               .AutoHeight()[SNew(STextBlock).Text(FText::FromString(Title))]   //
           /*dialog message*/                                                   //
           + SVerticalBox::Slot()                                               //
               .Padding(6)                                                      //
               .AutoHeight()[                                                   //
                 SNew(STextBlock)                                               //
                   .Text(FText::FromString(Message))                            //
                   .AutoWrapText(true)                                          //
                   .WrappingPolicy(ETextWrappingPolicy::DefaultWrapping)]       //
           /*dialog buttons*/                                                   //
           + SVerticalBox::Slot()                                               //
               .Padding(6)                                                      //
               .AutoHeight()[                                                   //
                 SNew(SHorizontalBox)                                           //
                 + SHorizontalBox::Slot()                                       //
                     .FillWidth(1.0f)[SNew(SSpacer)]                            //
                 + SHorizontalBox::Slot()                                       //
                     .Padding(5)                                                //
                     .AutoWidth()[                                              //
                       SNew(SButton)                                            //
                         .Text(FText::FromString(TEXT("OK")))                   //
                         .OnClicked(this, &SlateCefJSDialog::OnOkButtonClicked) //
       ]]]];                                                                    //
}

TSharedRef<SWidget>
SlateCefJSDialog::CreateConfirm()
{
  return SNew(SBox)                                                                 //
    .WidthOverride(680.0f)                                                          //
      [SNew(SBorder)                                                                //
         .BorderBackgroundColor(FLinearColor::Black)                                //
         .BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))                     //
         .Padding(6)[                                                               //
           /*dialog content*/                                                       //
           SNew(SVerticalBox)                                                       //
           /*dialog title*/                                                         //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[SNew(STextBlock).Text(FText::FromString(Title))]       //
           /*dialog message*/                                                       //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[                                                       //
                 SNew(STextBlock)                                                   //
                   .Text(FText::FromString(Message))                                //
                   .AutoWrapText(true)                                              //
                   .WrappingPolicy(ETextWrappingPolicy::DefaultWrapping)]           //
           /*dialog buttons*/                                                       //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[                                                       //
                 SNew(SHorizontalBox)                                               //
                 + SHorizontalBox::Slot()                                           //
                     .FillWidth(1.0f)[SNew(SSpacer)]                                //
                 + SHorizontalBox::Slot()                                           //
                     .Padding(5)                                                    //
                     .AutoWidth()[                                                  //
                       SNew(SButton)                                                //
                         .Text(FText::FromString(TEXT("OK")))                       //
                         .OnClicked(this, &SlateCefJSDialog::OnOkButtonClicked)     //
                        ]                                                            //
                 + SHorizontalBox::Slot()                                           //
                     .Padding(5)                                                    //
                     .AutoWidth()[                                                  //
                       SNew(SButton)                                                //
                         .Text(FText::FromString(TEXT("Cancel")))                   //
                         .OnClicked(this, &SlateCefJSDialog::OnCancelButtonClicked) //
       ]]]];                                                                        //
}

TSharedRef<SWidget>
SlateCefJSDialog::CreatePrompt()
{
  auto InputWidget = SNew(SEditableTextBox)                                          //
                       .MinDesiredWidth(250)                                         //
                       .Text(FText::FromString(Prompt))                              //
                       .OnTextChanged(this, &SlateCefJSDialog::OnPromptTextChanged); //

  return SNew(SBox)                                                                 //
    .WidthOverride(680.0f)                                                          //
      [SNew(SBorder)                                                                //
         .BorderBackgroundColor(FLinearColor::Black)                                //
         .BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))                     //
         .Padding(6)[                                                               //
           /*dialog content*/                                                       //
           SNew(SVerticalBox)                                                       //
           /*dialog title*/                                                         //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[SNew(STextBlock).Text(FText::FromString(Title))]       //
           /*dialog message*/                                                       //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[                                                       //
                 SNew(STextBlock)                                                   //
                   .Text(FText::FromString(Message))                                //
                   .AutoWrapText(true)                                              //
                   .WrappingPolicy(ETextWrappingPolicy::DefaultWrapping)]           //
           /*dialog input*/                                                         //
           + SVerticalBox::Slot()                                                   //
               .Padding(FMargin(10, 5))                                             //
               .AutoHeight()[InputWidget]                                           //
           /*dialog buttons*/                                                       //
           + SVerticalBox::Slot()                                                   //
               .Padding(6)                                                          //
               .AutoHeight()[                                                       //
                 SNew(SHorizontalBox)                                               //
                 + SHorizontalBox::Slot()                                           //
                     .FillWidth(1.0f)[SNew(SSpacer)]                                //
                 + SHorizontalBox::Slot()                                           //
                     .Padding(5)                                                    //
                     .AutoWidth()[                                                  //
                       SNew(SButton)                                                //
                         .Text(FText::FromString(TEXT("OK")))                       //
                         .OnClicked(this, &SlateCefJSDialog::OnOkButtonClicked)     //
                        ]                                                            //
                 + SHorizontalBox::Slot()                                           //
                     .Padding(5)                                                    //
                     .AutoWidth()[                                                  //
                       SNew(SButton)                                                //
                         .Text(FText::FromString(TEXT("Cancel")))                   //
                         .OnClicked(this, &SlateCefJSDialog::OnCancelButtonClicked) //
       ]]]];                                                                        //
}

FReply
SlateCefJSDialog::OnOkButtonClicked()
{
  OnContinueDelegate.ExecuteIfBound(true, Prompt);
  return FReply::Handled();
}

FReply
SlateCefJSDialog::OnCancelButtonClicked()
{
  OnContinueDelegate.ExecuteIfBound(false, "");
  return FReply::Handled();
}

void
SlateCefJSDialog::OnPromptTextChanged(const FText& NewText)
{
  Prompt = NewText.ToString();
}

bool
SlateCefJSDialog::SupportsKeyboardFocus() const
{
  return true;
}

FReply
SlateCefJSDialog::OnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
  if (InKeyEvent.GetKey() == EKeys::Enter) {
    return OnOkButtonClicked();
  } else if (InKeyEvent.GetKey() == EKeys::Escape) {
    return OnCancelButtonClicked();
  }

  return FReply::Unhandled();
}

SlateCefJSDialog::FOnContinueDelegate&
SlateCefJSDialog::GetOnContinueDelegate()
{
  return OnContinueDelegate;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
