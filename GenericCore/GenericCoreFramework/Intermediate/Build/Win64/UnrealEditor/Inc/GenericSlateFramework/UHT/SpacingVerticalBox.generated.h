// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/SpacingVerticalBox.h"

#ifdef GENERICSLATEFRAMEWORK_SpacingVerticalBox_generated_h
#error "SpacingVerticalBox.generated.h already included, missing '#pragma once' in SpacingVerticalBox.h"
#endif
#define GENERICSLATEFRAMEWORK_SpacingVerticalBox_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UVerticalBoxSlot;
class UWidget;

// ********** Begin Class USpacingVerticalBox ******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetInnerSlotPadding); \
	DECLARE_FUNCTION(execSetInnerSlotPadding); \
	DECLARE_FUNCTION(execAddChildToSpacingVerticalBox);


struct Z_Construct_UClass_USpacingVerticalBox_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USpacingVerticalBox_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSpacingVerticalBox(); \
	friend struct ::Z_Construct_UClass_USpacingVerticalBox_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_USpacingVerticalBox_NoRegister(); \
public: \
	DECLARE_CLASS2(USpacingVerticalBox, UVerticalBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_USpacingVerticalBox_NoRegister) \
	DECLARE_SERIALIZER(USpacingVerticalBox)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSLATEFRAMEWORK_API USpacingVerticalBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USpacingVerticalBox(USpacingVerticalBox&&) = delete; \
	USpacingVerticalBox(const USpacingVerticalBox&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, USpacingVerticalBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpacingVerticalBox); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpacingVerticalBox) \
	GENERICSLATEFRAMEWORK_API virtual ~USpacingVerticalBox();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_13_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USpacingVerticalBox;

// ********** End Class USpacingVerticalBox ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingVerticalBox_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
