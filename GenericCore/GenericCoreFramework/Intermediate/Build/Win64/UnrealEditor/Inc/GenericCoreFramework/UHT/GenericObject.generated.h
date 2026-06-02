// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Obect/GenericObject.h"

#ifdef GENERICCOREFRAMEWORK_GenericObject_generated_h
#error "GenericObject.generated.h already included, missing '#pragma once' in GenericObject.h"
#endif
#define GENERICCOREFRAMEWORK_GenericObject_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericObject ***********************************************************
struct Z_Construct_UClass_UGenericObject_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericObject_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericObject(); \
	friend struct ::Z_Construct_UClass_UGenericObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericObject, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UGenericObject_NoRegister) \
	DECLARE_SERIALIZER(UGenericObject)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericObject(UGenericObject&&) = delete; \
	UGenericObject(const UGenericObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UGenericObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericObject); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericObject) \
	GENERICCOREFRAMEWORK_API virtual ~UGenericObject();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericObject;

// ********** End Class UGenericObject *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
