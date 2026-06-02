// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/GenericVisualAttachment.h"

#ifdef GENERICSLATEFRAMEWORK_GenericVisualAttachment_generated_h
#error "GenericVisualAttachment.generated.h already included, missing '#pragma once' in GenericVisualAttachment.h"
#endif
#define GENERICSLATEFRAMEWORK_GenericVisualAttachment_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericVisualAttachment *************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetContentAnchor); \
	DECLARE_FUNCTION(execGetContentAnchor);


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_ACCESSORS \
static void GetContentAnchor_WrapperImpl(const void* Object, void* OutValue); \
static void SetContentAnchor_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UGenericVisualAttachment_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVisualAttachment_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericVisualAttachment(); \
	friend struct ::Z_Construct_UClass_UGenericVisualAttachment_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericVisualAttachment_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericVisualAttachment, USizeBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_UGenericVisualAttachment_NoRegister) \
	DECLARE_SERIALIZER(UGenericVisualAttachment)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericVisualAttachment(UGenericVisualAttachment&&) = delete; \
	UGenericVisualAttachment(const UGenericVisualAttachment&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, UGenericVisualAttachment); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericVisualAttachment); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericVisualAttachment) \
	GENERICSLATEFRAMEWORK_API virtual ~UGenericVisualAttachment();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_7_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_ACCESSORS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericVisualAttachment;

// ********** End Class UGenericVisualAttachment ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
