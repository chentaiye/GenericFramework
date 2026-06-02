// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/GenericVersionTypes.h"

#ifdef GENERICVERSIONFRAMEWORK_GenericVersionTypes_generated_h
#error "GenericVersionTypes.generated.h already included, missing '#pragma once' in GenericVersionTypes.h"
#endif
#define GENERICVERSIONFRAMEWORK_GenericVersionTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FGenericVersionInfo ***********************************************
struct Z_Construct_UScriptStruct_FGenericVersionInfo_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionInfo_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionInfo;
// ********** End ScriptStruct FGenericVersionInfo *************************************************

// ********** Begin ScriptStruct FGenericVersionDefinition *****************************************
struct Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_67_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionDefinition;
// ********** End ScriptStruct FGenericVersionDefinition *******************************************

// ********** Begin ScriptStruct FGenericVersionData ***********************************************
struct Z_Construct_UScriptStruct_FGenericVersionData_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_92_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionData;
// ********** End ScriptStruct FGenericVersionData *************************************************

// ********** Begin ScriptStruct FGenericVersionValidationResult ***********************************
struct Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_127_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionValidationResult;
// ********** End ScriptStruct FGenericVersionValidationResult *************************************

// ********** Begin ScriptStruct FGenericVersionMigrationResult ************************************
struct Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_155_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionMigrationResult;
// ********** End ScriptStruct FGenericVersionMigrationResult **************************************

// ********** Begin ScriptStruct FGenericVersionContext ********************************************
struct Z_Construct_UScriptStruct_FGenericVersionContext_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h_185_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGenericVersionContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGenericVersionContext;
// ********** End ScriptStruct FGenericVersionContext **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h

// ********** Begin Enum EGenericVersionValidationStatus *******************************************
#define FOREACH_ENUM_EGENERICVERSIONVALIDATIONSTATUS(op) \
	op(EGenericVersionValidationStatus::Success) \
	op(EGenericVersionValidationStatus::Warning) \
	op(EGenericVersionValidationStatus::Failed) 

enum class EGenericVersionValidationStatus : uint8;
template<> struct TIsUEnumClass<EGenericVersionValidationStatus> { enum { Value = true }; };
template<> GENERICVERSIONFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericVersionValidationStatus>();
// ********** End Enum EGenericVersionValidationStatus *********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
