// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Widget/GenericRotatorBox.h"

#ifdef GENERICSLATEFRAMEWORK_GenericRotatorBox_generated_h
#error "GenericRotatorBox.generated.h already included, missing '#pragma once' in GenericRotatorBox.h"
#endif
#define GENERICSLATEFRAMEWORK_GenericRotatorBox_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FOnElementRotated *****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_12_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnElementRotated_DelegateWrapper(const FMulticastScriptDelegate& OnElementRotated, int32 SelectedIndex, FText const& SelectedText);


// ********** End Delegate FOnElementRotated *******************************************************

// ********** Begin Class UGenericRotatorBox *******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	GENERICSLATEFRAMEWORK_API virtual void OnSelectedIndexChanged_Implementation(int32 Index); \
	DECLARE_FUNCTION(execOnSelectedIndexChanged); \
	DECLARE_FUNCTION(execGetNextValidIndex); \
	DECLARE_FUNCTION(execGetPreviousValidIndex); \
	DECLARE_FUNCTION(execSetSelectedIndex); \
	DECLARE_FUNCTION(execRemoveTextLabel); \
	DECLARE_FUNCTION(execAddTextLabel); \
	DECLARE_FUNCTION(execRotateRight); \
	DECLARE_FUNCTION(execRotateLeft); \
	DECLARE_FUNCTION(execOnButtonRightClicked); \
	DECLARE_FUNCTION(execOnButtonLeftClicked);


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UGenericRotatorBox_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericRotatorBox_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericRotatorBox(); \
	friend struct ::Z_Construct_UClass_UGenericRotatorBox_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericRotatorBox_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericRotatorBox, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_UGenericRotatorBox_NoRegister) \
	DECLARE_SERIALIZER(UGenericRotatorBox)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSLATEFRAMEWORK_API UGenericRotatorBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericRotatorBox(UGenericRotatorBox&&) = delete; \
	UGenericRotatorBox(const UGenericRotatorBox&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, UGenericRotatorBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericRotatorBox); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericRotatorBox) \
	GENERICSLATEFRAMEWORK_API virtual ~UGenericRotatorBox();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_15_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_CALLBACK_WRAPPERS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericRotatorBox;

// ********** End Class UGenericRotatorBox *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
