// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_World.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_World() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_World();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_World_NoRegister();
UNREALMISC_API UEnum* Z_Construct_UEnum_UnrealMisc_EWorldTypeBP();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_World Function GetWorldType *********************************
struct Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics
{
	struct BPFunctions_World_eventGetWorldType_Parms
	{
		const UObject* WorldContextObject;
		EWorldTypeBP ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x96\xe7\x95\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_World.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\x96\xe7\x95\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldType constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldType constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldType Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_World_eventGetWorldType_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_World_eventGetWorldType_Parms, ReturnValue), Z_Construct_UEnum_UnrealMisc_EWorldTypeBP, METADATA_PARAMS(0, nullptr) }; // 2184539054
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::PropPointers) < 2048);
// ********** End Function GetWorldType Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_World, nullptr, "GetWorldType", 	Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::BPFunctions_World_eventGetWorldType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::BPFunctions_World_eventGetWorldType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_World_GetWorldType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_World_GetWorldType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_World::execGetWorldType)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EWorldTypeBP*)Z_Param__Result=UBPFunctions_World::GetWorldType(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_World Function GetWorldType ***********************************

// ********** Begin Class UBPFunctions_World Function IsPartitionedWorld ***************************
struct Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics
{
	struct BPFunctions_World_eventIsPartitionedWorld_Parms
	{
		const UObject* WorldContextObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "World" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadPartitioned\xe4\xb8\x96\xe7\x95\x8c\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_World.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadPartitioned\xe4\xb8\x96\xe7\x95\x8c\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPartitionedWorld constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPartitionedWorld constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPartitionedWorld Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_World_eventIsPartitionedWorld_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
void Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_World_eventIsPartitionedWorld_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_World_eventIsPartitionedWorld_Parms), &Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::PropPointers) < 2048);
// ********** End Function IsPartitionedWorld Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_World, nullptr, "IsPartitionedWorld", 	Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::BPFunctions_World_eventIsPartitionedWorld_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::BPFunctions_World_eventIsPartitionedWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_World::execIsPartitionedWorld)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_World::IsPartitionedWorld(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_World Function IsPartitionedWorld *****************************

// ********** Begin Class UBPFunctions_World *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_World;
UClass* UBPFunctions_World::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_World;
	if (!Z_Registration_Info_UClass_UBPFunctions_World.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_World"),
			Z_Registration_Info_UClass_UBPFunctions_World.InnerSingleton,
			StaticRegisterNativesUBPFunctions_World,
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
	return Z_Registration_Info_UClass_UBPFunctions_World.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_World_NoRegister()
{
	return UBPFunctions_World::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_World_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe4\xb8\x96\xe7\x95\x8c\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_World.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_World.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe4\xb8\x96\xe7\x95\x8c\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_World constinit property declarations ***********************
// ********** End Class UBPFunctions_World constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetWorldType"), .Pointer = &UBPFunctions_World::execGetWorldType },
		{ .NameUTF8 = UTF8TEXT("IsPartitionedWorld"), .Pointer = &UBPFunctions_World::execIsPartitionedWorld },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_World_GetWorldType, "GetWorldType" }, // 1762542092
		{ &Z_Construct_UFunction_UBPFunctions_World_IsPartitionedWorld, "IsPartitionedWorld" }, // 4140951719
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_World>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_World_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_World_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_World_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_World_Statics::ClassParams = {
	&UBPFunctions_World::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_World_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_World_Statics::Class_MetaDataParams)
};
void UBPFunctions_World::StaticRegisterNativesUBPFunctions_World()
{
	UClass* Class = UBPFunctions_World::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_World_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_World()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_World.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_World.OuterSingleton, Z_Construct_UClass_UBPFunctions_World_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_World.OuterSingleton;
}
UBPFunctions_World::UBPFunctions_World(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_World);
UBPFunctions_World::~UBPFunctions_World() {}
// ********** End Class UBPFunctions_World *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_World, UBPFunctions_World::StaticClass, TEXT("UBPFunctions_World"), &Z_Registration_Info_UClass_UBPFunctions_World, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_World), 1346565539U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h__Script_UnrealMisc_1691792743{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
