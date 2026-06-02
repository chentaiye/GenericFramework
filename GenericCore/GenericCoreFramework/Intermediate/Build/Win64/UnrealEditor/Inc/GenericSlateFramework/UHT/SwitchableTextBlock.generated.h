// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/SwitchableTextBlock.h"

#ifdef GENERICSLATEFRAMEWORK_SwitchableTextBlock_generated_h
#error "SwitchableTextBlock.generated.h already included, missing '#pragma once' in SwitchableTextBlock.h"
#endif
#define GENERICSLATEFRAMEWORK_SwitchableTextBlock_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESwitchableTextBlockMode : uint8;
enum class ETextOverflowPolicy : uint8;
enum class ETextTransformPolicy : uint8;
struct FLinearColor;
struct FSlateBrush;
struct FSlateColor;
struct FSlateFontInfo;

// ********** Begin Delegate FOnSwitchableTextChangedEvent *****************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_15_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnSwitchableTextChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& OnSwitchableTextChangedEvent, FText const& Text);


// ********** End Delegate FOnSwitchableTextChangedEvent *******************************************

// ********** Begin Delegate FOnSwitchableTextCommittedEvent ***************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_16_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnSwitchableTextCommittedEvent_DelegateWrapper(const FMulticastScriptDelegate& OnSwitchableTextCommittedEvent, FText const& Text, ETextCommit::Type CommitMethod);


// ********** End Delegate FOnSwitchableTextCommittedEvent *****************************************

// ********** Begin Class USwitchableTextBlock *****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetIsReadOnly); \
	DECLARE_FUNCTION(execGetIsReadOnly); \
	DECLARE_FUNCTION(execSetJustification); \
	DECLARE_FUNCTION(execGetJustification); \
	DECLARE_FUNCTION(execSetTextTransformPolicy); \
	DECLARE_FUNCTION(execGetTextTransformPolicy); \
	DECLARE_FUNCTION(execSetTextOverflowPolicy); \
	DECLARE_FUNCTION(execGetTextOverflowPolicy); \
	DECLARE_FUNCTION(execSetMinDesiredWidth); \
	DECLARE_FUNCTION(execGetMinDesiredWidth); \
	DECLARE_FUNCTION(execSetStrikeBrush); \
	DECLARE_FUNCTION(execGetStrikeBrush); \
	DECLARE_FUNCTION(execSetShadowColorAndOpacity); \
	DECLARE_FUNCTION(execGetShadowColorAndOpacity); \
	DECLARE_FUNCTION(execSetShadowOffset); \
	DECLARE_FUNCTION(execGetShadowOffset); \
	DECLARE_FUNCTION(execSetColorAndOpacity); \
	DECLARE_FUNCTION(execGetColorAndOpacity); \
	DECLARE_FUNCTION(execSetFont); \
	DECLARE_FUNCTION(execGetFont); \
	DECLARE_FUNCTION(execSetMode); \
	DECLARE_FUNCTION(execGetMode); \
	DECLARE_FUNCTION(execSetHintText); \
	DECLARE_FUNCTION(execGetHintText); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execGetText);


struct Z_Construct_UClass_USwitchableTextBlock_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USwitchableTextBlock_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSwitchableTextBlock(); \
	friend struct ::Z_Construct_UClass_USwitchableTextBlock_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_USwitchableTextBlock_NoRegister(); \
public: \
	DECLARE_CLASS2(USwitchableTextBlock, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_USwitchableTextBlock_NoRegister) \
	DECLARE_SERIALIZER(USwitchableTextBlock)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	USwitchableTextBlock(USwitchableTextBlock&&) = delete; \
	USwitchableTextBlock(const USwitchableTextBlock&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, USwitchableTextBlock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USwitchableTextBlock); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USwitchableTextBlock) \
	GENERICSLATEFRAMEWORK_API virtual ~USwitchableTextBlock();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_19_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USwitchableTextBlock;

// ********** End Class USwitchableTextBlock *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
