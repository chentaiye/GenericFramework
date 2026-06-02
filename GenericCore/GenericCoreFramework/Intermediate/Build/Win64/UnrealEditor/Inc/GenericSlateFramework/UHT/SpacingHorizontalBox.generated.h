// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/SpacingHorizontalBox.h"

#ifdef GENERICSLATEFRAMEWORK_SpacingHorizontalBox_generated_h
#error "SpacingHorizontalBox.generated.h already included, missing '#pragma once' in SpacingHorizontalBox.h"
#endif
#define GENERICSLATEFRAMEWORK_SpacingHorizontalBox_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHorizontalBoxSlot;
class UWidget;

// ********** Begin Class USpacingHorizontalBox ****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetInnerSlotPadding); \
	DECLARE_FUNCTION(execSetInnerSlotPadding); \
	DECLARE_FUNCTION(execAddChildToSpacingHorizontalBox);


struct Z_Construct_UClass_USpacingHorizontalBox_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USpacingHorizontalBox_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSpacingHorizontalBox(); \
	friend struct ::Z_Construct_UClass_USpacingHorizontalBox_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_USpacingHorizontalBox_NoRegister(); \
public: \
	DECLARE_CLASS2(USpacingHorizontalBox, UHorizontalBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_USpacingHorizontalBox_NoRegister) \
	DECLARE_SERIALIZER(USpacingHorizontalBox)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSLATEFRAMEWORK_API USpacingHorizontalBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USpacingHorizontalBox(USpacingHorizontalBox&&) = delete; \
	USpacingHorizontalBox(const USpacingHorizontalBox&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, USpacingHorizontalBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpacingHorizontalBox); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpacingHorizontalBox) \
	GENERICSLATEFRAMEWORK_API virtual ~USpacingHorizontalBox();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_13_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USpacingHorizontalBox;

// ********** End Class USpacingHorizontalBox ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SpacingHorizontalBox_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
