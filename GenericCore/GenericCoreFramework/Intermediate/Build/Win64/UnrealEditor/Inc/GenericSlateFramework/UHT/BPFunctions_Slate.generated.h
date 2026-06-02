// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Slate.h"

#ifdef GENERICSLATEFRAMEWORK_BPFunctions_Slate_generated_h
#error "BPFunctions_Slate.generated.h already included, missing '#pragma once' in BPFunctions_Slate.h"
#endif
#define GENERICSLATEFRAMEWORK_BPFunctions_Slate_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBackgroundBlurSlot;
class UBorder;
class UButtonSlot;
class UImage;
class UStackBoxSlot;
class UWidget;
struct FBorderBrush;
struct FImageBrush;
struct FSlateBrush;

// ********** Begin Class UBPFunctions_Slate *******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execBorder_ConvToSlateBrush); \
	DECLARE_FUNCTION(execConvToBorderBrush); \
	DECLARE_FUNCTION(execSetBorderBrush); \
	DECLARE_FUNCTION(execIsValid_BorderBrush); \
	DECLARE_FUNCTION(execImage_ConvToSlateBrush); \
	DECLARE_FUNCTION(execConvToImageBrush); \
	DECLARE_FUNCTION(execSetImageBrush); \
	DECLARE_FUNCTION(execIsValid_ImageBrush); \
	DECLARE_FUNCTION(execSlotAsBackgroundBlurSlot); \
	DECLARE_FUNCTION(execSlotAsButtonSlot); \
	DECLARE_FUNCTION(execSlotAsStackBoxSlot);


struct Z_Construct_UClass_UBPFunctions_Slate_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Slate_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Slate(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Slate_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_UBPFunctions_Slate_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Slate, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_UBPFunctions_Slate_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Slate)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSLATEFRAMEWORK_API UBPFunctions_Slate(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Slate(UBPFunctions_Slate&&) = delete; \
	UBPFunctions_Slate(const UBPFunctions_Slate&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, UBPFunctions_Slate); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Slate); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Slate) \
	GENERICSLATEFRAMEWORK_API virtual ~UBPFunctions_Slate();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_19_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Slate;

// ********** End Class UBPFunctions_Slate *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
