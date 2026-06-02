// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/SimpleTextBox.h"

#ifdef GENERICSLATEFRAMEWORK_SimpleTextBox_generated_h
#error "SimpleTextBox.generated.h already included, missing '#pragma once' in SimpleTextBox.h"
#endif
#define GENERICSLATEFRAMEWORK_SimpleTextBox_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESimpleTextBoxType : uint8;
enum class ESlateVisibility : uint8;
enum class ETextOverflowPolicy : uint8;
enum class ETextTransformPolicy : uint8;
enum class ETextWrappingPolicy : uint8;
struct FLinearColor;
struct FMargin;
struct FSlateBrush;
struct FSlateColor;
struct FSlateFontInfo;

// ********** Begin Class USimpleTextBox ***********************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_RPC_WRAPPERS \
	DECLARE_FUNCTION(execSetImageVerticalAlignment); \
	DECLARE_FUNCTION(execGetImageVerticalAlignment); \
	DECLARE_FUNCTION(execSetImageHorizontalAlignment); \
	DECLARE_FUNCTION(execGetImageHorizontalAlignment); \
	DECLARE_FUNCTION(execSetTextVerticalAlignment); \
	DECLARE_FUNCTION(execGetTextVerticalAlignment); \
	DECLARE_FUNCTION(execSetTextHorizontalAlignment); \
	DECLARE_FUNCTION(execGetTextHorizontalAlignment); \
	DECLARE_FUNCTION(execSetPadding); \
	DECLARE_FUNCTION(execGetPadding); \
	DECLARE_FUNCTION(execSetSimpleTextBoxType); \
	DECLARE_FUNCTION(execGetSimpleTextBoxType); \
	DECLARE_FUNCTION(execSetImageVisibility); \
	DECLARE_FUNCTION(execGetImageVisibility); \
	DECLARE_FUNCTION(execSetImageMargin); \
	DECLARE_FUNCTION(execGetImageMargin); \
	DECLARE_FUNCTION(execSetImageColor); \
	DECLARE_FUNCTION(execGetImageColor); \
	DECLARE_FUNCTION(execSetImage); \
	DECLARE_FUNCTION(execGetImage); \
	DECLARE_FUNCTION(execSetSpace); \
	DECLARE_FUNCTION(execGetSpace); \
	DECLARE_FUNCTION(execSetOverflowPolicy); \
	DECLARE_FUNCTION(execGetOverflowPolicy); \
	DECLARE_FUNCTION(execSetTextMargin); \
	DECLARE_FUNCTION(execGetTextMargin); \
	DECLARE_FUNCTION(execSetLineHeightPercentage); \
	DECLARE_FUNCTION(execGetLineHeightPercentage); \
	DECLARE_FUNCTION(execSetMinDesiredWidth); \
	DECLARE_FUNCTION(execGetMinDesiredWidth); \
	DECLARE_FUNCTION(execSetJustification); \
	DECLARE_FUNCTION(execGetJustification); \
	DECLARE_FUNCTION(execSetTransformPolicy); \
	DECLARE_FUNCTION(execGetTransformPolicy); \
	DECLARE_FUNCTION(execSetWrappingPolicy); \
	DECLARE_FUNCTION(execGetWrappingPolicy); \
	DECLARE_FUNCTION(execSetWrapTextAt); \
	DECLARE_FUNCTION(execGetWrapTextAt); \
	DECLARE_FUNCTION(execSetAutoWrapText); \
	DECLARE_FUNCTION(execGetAutoWrapText); \
	DECLARE_FUNCTION(execSetTextHighlightShape); \
	DECLARE_FUNCTION(execGetTextHighlightShape); \
	DECLARE_FUNCTION(execSetHighlightText); \
	DECLARE_FUNCTION(execGetHighlightText); \
	DECLARE_FUNCTION(execSetTextShadowColor); \
	DECLARE_FUNCTION(execGetTextShadowColor); \
	DECLARE_FUNCTION(execSetTextShadowOffset); \
	DECLARE_FUNCTION(execGetTextShadowOffset); \
	DECLARE_FUNCTION(execSetTextStrikeBrush); \
	DECLARE_FUNCTION(execGetTextStrikeBrush); \
	DECLARE_FUNCTION(execSetTextFont); \
	DECLARE_FUNCTION(execGetTextFont); \
	DECLARE_FUNCTION(execSetTextColor); \
	DECLARE_FUNCTION(execGetTextColor); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execGetText);


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_ACCESSORS \
static void GetText_WrapperImpl(const void* Object, void* OutValue); \
static void SetText_WrapperImpl(void* Object, const void* InValue); \
static void GetTextColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextColor_WrapperImpl(void* Object, const void* InValue); \
static void GetTextFont_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextFont_WrapperImpl(void* Object, const void* InValue); \
static void GetTextStrikeBrush_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextStrikeBrush_WrapperImpl(void* Object, const void* InValue); \
static void GetTextShadowOffset_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextShadowOffset_WrapperImpl(void* Object, const void* InValue); \
static void GetTextShadowColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextShadowColor_WrapperImpl(void* Object, const void* InValue); \
static void GetHighlightText_WrapperImpl(const void* Object, void* OutValue); \
static void SetHighlightText_WrapperImpl(void* Object, const void* InValue); \
static void GetTextHighlightShape_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextHighlightShape_WrapperImpl(void* Object, const void* InValue); \
static void GetAutoWrapText_WrapperImpl(const void* Object, void* OutValue); \
static void SetAutoWrapText_WrapperImpl(void* Object, const void* InValue); \
static void GetWrapTextAt_WrapperImpl(const void* Object, void* OutValue); \
static void SetWrapTextAt_WrapperImpl(void* Object, const void* InValue); \
static void GetWrappingPolicy_WrapperImpl(const void* Object, void* OutValue); \
static void SetWrappingPolicy_WrapperImpl(void* Object, const void* InValue); \
static void GetTransformPolicy_WrapperImpl(const void* Object, void* OutValue); \
static void SetTransformPolicy_WrapperImpl(void* Object, const void* InValue); \
static void GetJustification_WrapperImpl(const void* Object, void* OutValue); \
static void SetJustification_WrapperImpl(void* Object, const void* InValue); \
static void GetMinDesiredWidth_WrapperImpl(const void* Object, void* OutValue); \
static void SetMinDesiredWidth_WrapperImpl(void* Object, const void* InValue); \
static void GetLineHeightPercentage_WrapperImpl(const void* Object, void* OutValue); \
static void SetLineHeightPercentage_WrapperImpl(void* Object, const void* InValue); \
static void GetTextMargin_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextMargin_WrapperImpl(void* Object, const void* InValue); \
static void GetOverflowPolicy_WrapperImpl(const void* Object, void* OutValue); \
static void SetOverflowPolicy_WrapperImpl(void* Object, const void* InValue); \
static void GetSpace_WrapperImpl(const void* Object, void* OutValue); \
static void SetSpace_WrapperImpl(void* Object, const void* InValue); \
static void GetImage_WrapperImpl(const void* Object, void* OutValue); \
static void SetImage_WrapperImpl(void* Object, const void* InValue); \
static void GetImageColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetImageColor_WrapperImpl(void* Object, const void* InValue); \
static void GetImageMargin_WrapperImpl(const void* Object, void* OutValue); \
static void SetImageMargin_WrapperImpl(void* Object, const void* InValue); \
static void GetImageVisibility_WrapperImpl(const void* Object, void* OutValue); \
static void SetImageVisibility_WrapperImpl(void* Object, const void* InValue); \
static void GetSimpleTextBoxType_WrapperImpl(const void* Object, void* OutValue); \
static void SetSimpleTextBoxType_WrapperImpl(void* Object, const void* InValue); \
static void GetPadding_WrapperImpl(const void* Object, void* OutValue); \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void GetTextHorizontalAlignment_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextHorizontalAlignment_WrapperImpl(void* Object, const void* InValue); \
static void GetTextVerticalAlignment_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextVerticalAlignment_WrapperImpl(void* Object, const void* InValue); \
static void GetImageHorizontalAlignment_WrapperImpl(const void* Object, void* OutValue); \
static void SetImageHorizontalAlignment_WrapperImpl(void* Object, const void* InValue); \
static void GetImageVerticalAlignment_WrapperImpl(const void* Object, void* OutValue); \
static void SetImageVerticalAlignment_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_USimpleTextBox_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USimpleTextBox_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUSimpleTextBox(); \
	friend struct ::Z_Construct_UClass_USimpleTextBox_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_USimpleTextBox_NoRegister(); \
public: \
	DECLARE_CLASS2(USimpleTextBox, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_USimpleTextBox_NoRegister) \
	DECLARE_SERIALIZER(USimpleTextBox)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSLATEFRAMEWORK_API USimpleTextBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimpleTextBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, USimpleTextBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimpleTextBox); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USimpleTextBox(USimpleTextBox&&) = delete; \
	USimpleTextBox(const USimpleTextBox&) = delete; \
	GENERICSLATEFRAMEWORK_API virtual ~USimpleTextBox();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_14_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_RPC_WRAPPERS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_ACCESSORS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_INCLASS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USimpleTextBox;

// ********** End Class USimpleTextBox *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
