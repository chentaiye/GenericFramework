// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldSettings/GenericWorldSettingsSubsystem.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericWorldSettingsSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSubsystem();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettings_NoRegister();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsSubsystem();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericWorldSettingsSubsystem Function GetSettingsCollection ************
struct Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics
{
	struct GenericWorldSettingsSubsystem_eventGetSettingsCollection_Parms
	{
		UGenericWorldSettingsCollection* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe6\x8c\x82\xe8\xbd\xbd\xe5\x88\xb0 AWorldSettings \xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x9b\xe6\xb2\xa1\xe6\x9c\x89\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x87\xe6\x80\xbb\xe9\x9b\x86\xe6\x97\xb6\xe8\xbf\x94\xe5\x9b\x9e\xe7\xa9\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe6\x8c\x82\xe8\xbd\xbd\xe5\x88\xb0 AWorldSettings \xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x9b\xe6\xb2\xa1\xe6\x9c\x89\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x87\xe6\x80\xbb\xe9\x9b\x86\xe6\x97\xb6\xe8\xbf\x94\xe5\x9b\x9e\xe7\xa9\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSettingsCollection constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSettingsCollection constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSettingsCollection Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsSubsystem_eventGetSettingsCollection_Parms, ReturnValue), Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::PropPointers) < 2048);
// ********** End Function GetSettingsCollection Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettingsSubsystem, nullptr, "GetSettingsCollection", 	Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::GenericWorldSettingsSubsystem_eventGetSettingsCollection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::GenericWorldSettingsSubsystem_eventGetSettingsCollection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettingsSubsystem::execGetSettingsCollection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGenericWorldSettingsCollection**)Z_Param__Result=P_THIS->GetSettingsCollection();
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettingsSubsystem Function GetSettingsCollection **************

// ********** Begin Class UGenericWorldSettingsSubsystem Function GetWorldSetting ******************
struct Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics
{
	struct GenericWorldSettingsSubsystem_eventGetWorldSetting_Parms
	{
		TSubclassOf<UGenericWorldSettings> SettingsClass;
		UGenericWorldSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\xad\xe6\x8c\x87\xe5\xae\x9a\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\x9b\xe5\xbb\xba\xe7\xbc\xba\xe5\xa4\xb1\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "SettingsClass" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\xad\xe6\x8c\x87\xe5\xae\x9a\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\x9b\xe5\xbb\xba\xe7\xbc\xba\xe5\xa4\xb1\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldSetting constinit property declarations ***********************
	static const UECodeGen_Private::FClassPropertyParams NewProp_SettingsClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldSetting constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldSetting Property Definitions **********************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::NewProp_SettingsClass = { "SettingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsSubsystem_eventGetWorldSetting_Parms, SettingsClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UGenericWorldSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsSubsystem_eventGetWorldSetting_Parms, ReturnValue), Z_Construct_UClass_UGenericWorldSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::NewProp_SettingsClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::PropPointers) < 2048);
// ********** End Function GetWorldSetting Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettingsSubsystem, nullptr, "GetWorldSetting", 	Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::GenericWorldSettingsSubsystem_eventGetWorldSetting_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::GenericWorldSettingsSubsystem_eventGetWorldSetting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettingsSubsystem::execGetWorldSetting)
{
	P_GET_OBJECT(UClass,Z_Param_SettingsClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGenericWorldSettings**)Z_Param__Result=P_THIS->GetWorldSetting(Z_Param_SettingsClass);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettingsSubsystem Function GetWorldSetting ********************

// ********** Begin Class UGenericWorldSettingsSubsystem Function GetWorldSettingsSubsystem ********
struct Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics
{
	struct GenericWorldSettingsSubsystem_eventGetWorldSettingsSubsystem_Parms
	{
		const UObject* WorldContextObject;
		UGenericWorldSettingsSubsystem* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x80\x9a\xe8\xbf\x87\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xe5\x8f\x96\xe5\xbe\x97\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe8\xb7\xa8\xe6\xa8\xa1\xe5\x9d\x97 C++ \xe8\xb0\x83\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x80\x9a\xe8\xbf\x87\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xe5\x8f\x96\xe5\xbe\x97\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe8\xb7\xa8\xe6\xa8\xa1\xe5\x9d\x97 C++ \xe8\xb0\x83\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldSettingsSubsystem constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldSettingsSubsystem constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldSettingsSubsystem Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsSubsystem_eventGetWorldSettingsSubsystem_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsSubsystem_eventGetWorldSettingsSubsystem_Parms, ReturnValue), Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::PropPointers) < 2048);
// ********** End Function GetWorldSettingsSubsystem Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettingsSubsystem, nullptr, "GetWorldSettingsSubsystem", 	Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::GenericWorldSettingsSubsystem_eventGetWorldSettingsSubsystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::GenericWorldSettingsSubsystem_eventGetWorldSettingsSubsystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettingsSubsystem::execGetWorldSettingsSubsystem)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGenericWorldSettingsSubsystem**)Z_Param__Result=UGenericWorldSettingsSubsystem::GetWorldSettingsSubsystem(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettingsSubsystem Function GetWorldSettingsSubsystem **********

// ********** Begin Class UGenericWorldSettingsSubsystem *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem;
UClass* UGenericWorldSettingsSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericWorldSettingsSubsystem;
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericWorldSettingsSubsystem"),
			Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericWorldSettingsSubsystem,
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
	return Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister()
{
	return UGenericWorldSettingsSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x9c\xa8\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe5\xb7\xb2\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xba\xe5\x85\xb6\xe4\xbb\x96\xe4\xb8\x96\xe7\x95\x8c\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe6\x8f\x90\xe4\xbe\x9b\xe5\xbc\xba\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "WorldSettings/GenericWorldSettingsSubsystem.h" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe5\xb7\xb2\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xba\xe5\x85\xb6\xe4\xbb\x96\xe4\xb8\x96\xe7\x95\x8c\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe6\x8f\x90\xe4\xbe\x9b\xe5\xbc\xba\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SettingsCollection_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x93\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe7\x94\xb1\xe5\x9c\xb0\xe5\x9b\xbe\xe7\x9a\x84 AWorldSettings \xe6\x8c\x81\xe6\x9c\x89\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x93\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe7\x94\xb1\xe5\x9c\xb0\xe5\x9b\xbe\xe7\x9a\x84 AWorldSettings \xe6\x8c\x81\xe6\x9c\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericWorldSettingsSubsystem constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SettingsCollection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericWorldSettingsSubsystem constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSettingsCollection"), .Pointer = &UGenericWorldSettingsSubsystem::execGetSettingsCollection },
		{ .NameUTF8 = UTF8TEXT("GetWorldSetting"), .Pointer = &UGenericWorldSettingsSubsystem::execGetWorldSetting },
		{ .NameUTF8 = UTF8TEXT("GetWorldSettingsSubsystem"), .Pointer = &UGenericWorldSettingsSubsystem::execGetWorldSettingsSubsystem },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetSettingsCollection, "GetSettingsCollection" }, // 1395838967
		{ &Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSetting, "GetWorldSetting" }, // 4065165511
		{ &Z_Construct_UFunction_UGenericWorldSettingsSubsystem_GetWorldSettingsSubsystem, "GetWorldSettingsSubsystem" }, // 2333262527
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericWorldSettingsSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics

// ********** Begin Class UGenericWorldSettingsSubsystem Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::NewProp_SettingsCollection = { "SettingsCollection", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWorldSettingsSubsystem, SettingsCollection), Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SettingsCollection_MetaData), NewProp_SettingsCollection_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::NewProp_SettingsCollection,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UGenericWorldSettingsSubsystem Property Definitions ************************
UObject* (*const Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::ClassParams = {
	&UGenericWorldSettingsSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::Class_MetaDataParams)
};
void UGenericWorldSettingsSubsystem::StaticRegisterNativesUGenericWorldSettingsSubsystem()
{
	UClass* Class = UGenericWorldSettingsSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericWorldSettingsSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.OuterSingleton, Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem.OuterSingleton;
}
UGenericWorldSettingsSubsystem::UGenericWorldSettingsSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericWorldSettingsSubsystem);
UGenericWorldSettingsSubsystem::~UGenericWorldSettingsSubsystem() {}
// ********** End Class UGenericWorldSettingsSubsystem *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h__Script_GenericSettingsFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericWorldSettingsSubsystem, UGenericWorldSettingsSubsystem::StaticClass, TEXT("UGenericWorldSettingsSubsystem"), &Z_Registration_Info_UClass_UGenericWorldSettingsSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericWorldSettingsSubsystem), 1211293425U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h__Script_GenericSettingsFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h__Script_GenericSettingsFramework_879131914{
	TEXT("/Script/GenericSettingsFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h__Script_GenericSettingsFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h__Script_GenericSettingsFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
