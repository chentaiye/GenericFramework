// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldSettings/GenericWorldSettingsCollection.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericWorldSettingsCollection() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAssetUserData();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettings_NoRegister();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsCollection();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericWorldSettingsCollection Function FindSettings ********************
struct Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics
{
	struct GenericWorldSettingsCollection_eventFindSettings_Parms
	{
		TSubclassOf<UGenericWorldSettings> SettingsClass;
		UGenericWorldSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\xb2\xbe\xe7\xa1\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\x80\xe4\xb8\xaa Settings Class \xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe6\x80\xbb\xe9\x9b\x86\xe4\xb8\xad\xe5\x8f\xaa\xe4\xbc\x9a\xe8\xbf\x94\xe5\x9b\x9e\xe4\xb8\x80\xe4\xbb\xbd\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "SettingsClass" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsCollection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\xb2\xbe\xe7\xa1\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\x80\xe4\xb8\xaa Settings Class \xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe6\x80\xbb\xe9\x9b\x86\xe4\xb8\xad\xe5\x8f\xaa\xe4\xbc\x9a\xe8\xbf\x94\xe5\x9b\x9e\xe4\xb8\x80\xe4\xbb\xbd\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindSettings constinit property declarations **************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_SettingsClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindSettings constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindSettings Property Definitions *************************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::NewProp_SettingsClass = { "SettingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsCollection_eventFindSettings_Parms, SettingsClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UGenericWorldSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettingsCollection_eventFindSettings_Parms, ReturnValue), Z_Construct_UClass_UGenericWorldSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::NewProp_SettingsClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::PropPointers) < 2048);
// ********** End Function FindSettings Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettingsCollection, nullptr, "FindSettings", 	Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::GenericWorldSettingsCollection_eventFindSettings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::GenericWorldSettingsCollection_eventFindSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettingsCollection::execFindSettings)
{
	P_GET_OBJECT(UClass,Z_Param_SettingsClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGenericWorldSettings**)Z_Param__Result=P_THIS->FindSettings(Z_Param_SettingsClass);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettingsCollection Function FindSettings **********************

// ********** Begin Class UGenericWorldSettingsCollection ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericWorldSettingsCollection;
UClass* UGenericWorldSettingsCollection::GetPrivateStaticClass()
{
	using TClass = UGenericWorldSettingsCollection;
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsCollection.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericWorldSettingsCollection"),
			Z_Registration_Info_UClass_UGenericWorldSettingsCollection.InnerSingleton,
			StaticRegisterNativesUGenericWorldSettingsCollection,
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
	return Z_Registration_Info_UClass_UGenericWorldSettingsCollection.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister()
{
	return UGenericWorldSettingsCollection::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericWorldSettingsCollection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb5\x8c\xe5\x85\xa5 AWorldSettings \xe7\x9a\x84\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x8c\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe4\xbf\x9d\xe5\xad\x98\xe8\xaf\xa5\xe4\xb8\x96\xe7\x95\x8c\xe5\xae\x9e\xe9\x99\x85\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe4\xb8\x80\xe7\xbb\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "WorldSettings/GenericWorldSettingsCollection.h" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsCollection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb5\x8c\xe5\x85\xa5 AWorldSettings \xe7\x9a\x84\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xef\xbc\x8c\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe4\xbf\x9d\xe5\xad\x98\xe8\xaf\xa5\xe4\xb8\x96\xe7\x95\x8c\xe5\xae\x9e\xe9\x99\x85\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe4\xb8\x80\xe7\xbb\x84\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_Inner_MetaData[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe6\x89\x80\xe6\x9c\x89\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe8\xaf\xa5\xe6\x95\xb0\xe7\xbb\x84\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\xaa\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x8d\xe8\x87\xaa\xe5\x8a\xa8\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsCollection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe6\x89\x80\xe6\x9c\x89\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe8\xaf\xa5\xe6\x95\xb0\xe7\xbb\x84\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\xaa\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x8d\xe8\x87\xaa\xe5\x8a\xa8\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "Category", "World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe6\x89\x80\xe6\x9c\x89\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe8\xaf\xa5\xe6\x95\xb0\xe7\xbb\x84\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\xaa\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x8d\xe8\x87\xaa\xe5\x8a\xa8\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsCollection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe6\x89\x80\xe6\x9c\x89\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe8\xaf\xa5\xe6\x95\xb0\xe7\xbb\x84\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\xaa\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x8d\xe8\x87\xaa\xe5\x8a\xa8\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericWorldSettingsCollection constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Settings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericWorldSettingsCollection constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindSettings"), .Pointer = &UGenericWorldSettingsCollection::execFindSettings },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericWorldSettingsCollection_FindSettings, "FindSettings" }, // 631684429
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericWorldSettingsCollection>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericWorldSettingsCollection_Statics

// ********** Begin Class UGenericWorldSettingsCollection Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::NewProp_Settings_Inner = { "Settings", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UGenericWorldSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_Inner_MetaData), NewProp_Settings_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0114008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWorldSettingsCollection, Settings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::NewProp_Settings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::NewProp_Settings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::PropPointers) < 2048);
// ********** End Class UGenericWorldSettingsCollection Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetUserData,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::ClassParams = {
	&UGenericWorldSettingsCollection::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::Class_MetaDataParams)
};
void UGenericWorldSettingsCollection::StaticRegisterNativesUGenericWorldSettingsCollection()
{
	UClass* Class = UGenericWorldSettingsCollection::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericWorldSettingsCollection()
{
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsCollection.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericWorldSettingsCollection.OuterSingleton, Z_Construct_UClass_UGenericWorldSettingsCollection_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericWorldSettingsCollection.OuterSingleton;
}
UGenericWorldSettingsCollection::UGenericWorldSettingsCollection(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericWorldSettingsCollection);
UGenericWorldSettingsCollection::~UGenericWorldSettingsCollection() {}
// ********** End Class UGenericWorldSettingsCollection ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h__Script_GenericSettingsFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericWorldSettingsCollection, UGenericWorldSettingsCollection::StaticClass, TEXT("UGenericWorldSettingsCollection"), &Z_Registration_Info_UClass_UGenericWorldSettingsCollection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericWorldSettingsCollection), 2047389096U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h__Script_GenericSettingsFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h__Script_GenericSettingsFramework_2697832848{
	TEXT("/Script/GenericSettingsFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h__Script_GenericSettingsFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h__Script_GenericSettingsFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
