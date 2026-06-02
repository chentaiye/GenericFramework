// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actor/GenericActor.h"

#ifdef GENERICCOREFRAMEWORK_GenericActor_generated_h
#error "GenericActor.generated.h already included, missing '#pragma once' in GenericActor.h"
#endif
#define GENERICCOREFRAMEWORK_GenericActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGenericActor ************************************************************
struct Z_Construct_UClass_AGenericActor_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_AGenericActor_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGenericActor(); \
	friend struct ::Z_Construct_UClass_AGenericActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_AGenericActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AGenericActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_AGenericActor_NoRegister) \
	DECLARE_SERIALIZER(AGenericActor)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGenericActor(AGenericActor&&) = delete; \
	AGenericActor(const AGenericActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, AGenericActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGenericActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGenericActor) \
	GENERICCOREFRAMEWORK_API virtual ~AGenericActor();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGenericActor;

// ********** End Class AGenericActor **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Actor_GenericActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
