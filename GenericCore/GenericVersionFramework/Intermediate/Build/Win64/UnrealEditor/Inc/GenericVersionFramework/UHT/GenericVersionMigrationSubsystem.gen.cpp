// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericVersionMigrationSubsystem.h"
#include "Engine/GameInstance.h"
#include "Types/GenericVersionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVersionMigrationSubsystem() {}

// ********** Begin Cross Module References ********************************************************
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGameInstanceSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionMigrationSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionMigrationSubsystem_NoRegister();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionInfo();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionMigrationResult();
UPackage* Z_Construct_UPackage__Script_GenericVersionFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericVersionMigrationSubsystem Function MakeMigrationFailed ***********
struct Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics
{
	struct GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms
	{
		FGenericVersionInfo SourceVersion;
		FGenericVersionInfo TargetVersion;
		FName ErrorCode;
		FText Message;
		FGenericVersionMigrationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9e\x84\xe9\x80\xa0\xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe5\x90\x8e\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe5\xa4\x84\xe7\x90\x86\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x86\xb3\xe5\xae\x9a\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionMigrationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9e\x84\xe9\x80\xa0\xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe5\x90\x8e\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe5\xa4\x84\xe7\x90\x86\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x86\xb3\xe5\xae\x9a\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceVersion_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetVersion_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeMigrationFailed constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetVersion;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeMigrationFailed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeMigrationFailed Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_SourceVersion = { "SourceVersion", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms, SourceVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceVersion_MetaData), NewProp_SourceVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_TargetVersion = { "TargetVersion", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms, TargetVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetVersion_MetaData), NewProp_TargetVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionMigrationResult, METADATA_PARAMS(0, nullptr) }; // 3667212279
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_SourceVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_TargetVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::PropPointers) < 2048);
// ********** End Function MakeMigrationFailed Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionMigrationSubsystem, nullptr, "MakeMigrationFailed", 	Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::GenericVersionMigrationSubsystem_eventMakeMigrationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionMigrationSubsystem::execMakeMigrationFailed)
{
	P_GET_STRUCT_REF(FGenericVersionInfo,Z_Param_Out_SourceVersion);
	P_GET_STRUCT_REF(FGenericVersionInfo,Z_Param_Out_TargetVersion);
	P_GET_PROPERTY(FNameProperty,Z_Param_ErrorCode);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionMigrationResult*)Z_Param__Result=P_THIS->MakeMigrationFailed(Z_Param_Out_SourceVersion,Z_Param_Out_TargetVersion,Z_Param_ErrorCode,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionMigrationSubsystem Function MakeMigrationFailed *************

// ********** Begin Class UGenericVersionMigrationSubsystem Function MakeMigrationSuccess **********
struct Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics
{
	struct GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms
	{
		FGenericVersionInfo SourceVersion;
		FGenericVersionInfo TargetVersion;
		FText Message;
		FGenericVersionMigrationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9e\x84\xe9\x80\xa0\xe8\xbf\x81\xe7\xa7\xbb\xe6\x88\x90\xe5\x8a\x9f\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe4\xbe\x9b\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xa4\x8d\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionMigrationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9e\x84\xe9\x80\xa0\xe8\xbf\x81\xe7\xa7\xbb\xe6\x88\x90\xe5\x8a\x9f\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe4\xbe\x9b\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xa4\x8d\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceVersion_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetVersion_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeMigrationSuccess constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetVersion;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeMigrationSuccess constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeMigrationSuccess Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_SourceVersion = { "SourceVersion", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms, SourceVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceVersion_MetaData), NewProp_SourceVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_TargetVersion = { "TargetVersion", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms, TargetVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetVersion_MetaData), NewProp_TargetVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionMigrationResult, METADATA_PARAMS(0, nullptr) }; // 3667212279
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_SourceVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_TargetVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::PropPointers) < 2048);
// ********** End Function MakeMigrationSuccess Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionMigrationSubsystem, nullptr, "MakeMigrationSuccess", 	Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::GenericVersionMigrationSubsystem_eventMakeMigrationSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionMigrationSubsystem::execMakeMigrationSuccess)
{
	P_GET_STRUCT_REF(FGenericVersionInfo,Z_Param_Out_SourceVersion);
	P_GET_STRUCT_REF(FGenericVersionInfo,Z_Param_Out_TargetVersion);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionMigrationResult*)Z_Param__Result=P_THIS->MakeMigrationSuccess(Z_Param_Out_SourceVersion,Z_Param_Out_TargetVersion,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionMigrationSubsystem Function MakeMigrationSuccess ************

// ********** Begin Class UGenericVersionMigrationSubsystem ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem;
UClass* UGenericVersionMigrationSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericVersionMigrationSubsystem;
	if (!Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericVersionMigrationSubsystem"),
			Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericVersionMigrationSubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericVersionMigrationSubsystem_NoRegister()
{
	return UGenericVersionMigrationSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\xa7\xe8\xa1\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\x8f\xaa\xe8\xb0\x83\xe7\x94\xa8\xe8\xbf\x81\xe7\xa7\xbb\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xb9\xb6\xe5\x88\x86\xe5\x8f\x91\xe7\xbb\x93\xe6\x9e\x9c\xe5\xa4\x84\xe7\x90\x86\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericVersionMigrationSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionMigrationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xa7\xe8\xa1\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\x8f\xaa\xe8\xb0\x83\xe7\x94\xa8\xe8\xbf\x81\xe7\xa7\xbb\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xb9\xb6\xe5\x88\x86\xe5\x8f\x91\xe7\xbb\x93\xe6\x9e\x9c\xe5\xa4\x84\xe7\x90\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericVersionMigrationSubsystem constinit property declarations ********
// ********** End Class UGenericVersionMigrationSubsystem constinit property declarations **********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("MakeMigrationFailed"), .Pointer = &UGenericVersionMigrationSubsystem::execMakeMigrationFailed },
		{ .NameUTF8 = UTF8TEXT("MakeMigrationSuccess"), .Pointer = &UGenericVersionMigrationSubsystem::execMakeMigrationSuccess },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationFailed, "MakeMigrationFailed" }, // 1163253779
		{ &Z_Construct_UFunction_UGenericVersionMigrationSubsystem_MakeMigrationSuccess, "MakeMigrationSuccess" }, // 440008522
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericVersionMigrationSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::ClassParams = {
	&UGenericVersionMigrationSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::Class_MetaDataParams)
};
void UGenericVersionMigrationSubsystem::StaticRegisterNativesUGenericVersionMigrationSubsystem()
{
	UClass* Class = UGenericVersionMigrationSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericVersionMigrationSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.OuterSingleton, Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem.OuterSingleton;
}
UGenericVersionMigrationSubsystem::UGenericVersionMigrationSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericVersionMigrationSubsystem);
UGenericVersionMigrationSubsystem::~UGenericVersionMigrationSubsystem() {}
// ********** End Class UGenericVersionMigrationSubsystem ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h__Script_GenericVersionFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericVersionMigrationSubsystem, UGenericVersionMigrationSubsystem::StaticClass, TEXT("UGenericVersionMigrationSubsystem"), &Z_Registration_Info_UClass_UGenericVersionMigrationSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericVersionMigrationSubsystem), 3007756013U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h__Script_GenericVersionFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h__Script_GenericVersionFramework_1740478873{
	TEXT("/Script/GenericVersionFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
