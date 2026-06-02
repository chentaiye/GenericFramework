// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UWidget/GenericVisualAttachment.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVisualAttachment() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVisualAttachment();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVisualAttachment_NoRegister();
UMG_API UClass* Z_Construct_UClass_USizeBox();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericVisualAttachment Function GetContentAnchor ***********************
struct Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics
{
	struct GenericVisualAttachment_eventGetContentAnchor_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Visual Attachment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericVisualAttachment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetContentAnchor constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetContentAnchor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetContentAnchor Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVisualAttachment_eventGetContentAnchor_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::PropPointers) < 2048);
// ********** End Function GetContentAnchor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVisualAttachment, nullptr, "GetContentAnchor", 	Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::GenericVisualAttachment_eventGetContentAnchor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::GenericVisualAttachment_eventGetContentAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVisualAttachment::execGetContentAnchor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetContentAnchor();
	P_NATIVE_END;
}
// ********** End Class UGenericVisualAttachment Function GetContentAnchor *************************

// ********** Begin Class UGenericVisualAttachment Function SetContentAnchor ***********************
struct Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics
{
	struct GenericVisualAttachment_eventSetContentAnchor_Parms
	{
		FVector2D InAnchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Visual Attachment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericVisualAttachment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetContentAnchor constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InAnchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetContentAnchor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetContentAnchor Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::NewProp_InAnchor = { "InAnchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVisualAttachment_eventSetContentAnchor_Parms, InAnchor), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::NewProp_InAnchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::PropPointers) < 2048);
// ********** End Function SetContentAnchor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVisualAttachment, nullptr, "SetContentAnchor", 	Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::GenericVisualAttachment_eventSetContentAnchor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::GenericVisualAttachment_eventSetContentAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVisualAttachment::execSetContentAnchor)
{
	P_GET_STRUCT(FVector2D,Z_Param_InAnchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetContentAnchor(Z_Param_InAnchor);
	P_NATIVE_END;
}
// ********** End Class UGenericVisualAttachment Function SetContentAnchor *************************

// ********** Begin Class UGenericVisualAttachment *************************************************
void UGenericVisualAttachment::GetContentAnchor_WrapperImpl(const void* Object, void* OutValue)
{
	const UGenericVisualAttachment* Obj = (const UGenericVisualAttachment*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetContentAnchor();
}
void UGenericVisualAttachment::SetContentAnchor_WrapperImpl(void* Object, const void* InValue)
{
	UGenericVisualAttachment* Obj = (UGenericVisualAttachment*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetContentAnchor(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericVisualAttachment;
UClass* UGenericVisualAttachment::GetPrivateStaticClass()
{
	using TClass = UGenericVisualAttachment;
	if (!Z_Registration_Info_UClass_UGenericVisualAttachment.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericVisualAttachment"),
			Z_Registration_Info_UClass_UGenericVisualAttachment.InnerSingleton,
			StaticRegisterNativesUGenericVisualAttachment,
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
	return Z_Registration_Info_UClass_UGenericVisualAttachment.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericVisualAttachment_NoRegister()
{
	return UGenericVisualAttachment::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericVisualAttachment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe5\x8f\xaf\xe8\xa7\x86\xe9\x99\x84\xe7\x9d\x80 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "UWidget/GenericVisualAttachment.h" },
		{ "ModuleRelativePath", "Public/UWidget/GenericVisualAttachment.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe5\x8f\xaf\xe8\xa7\x86\xe9\x99\x84\xe7\x9d\x80 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentAnchor_MetaData[] = {
		{ "BlueprintGetter", "GetContentAnchor" },
		{ "BlueprintSetter", "SetContentAnchor" },
		{ "Category", "Visual Attachment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x99\x84\xe7\x9d\x80\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe5\x86\xb3\xe5\xae\x9a\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x9c\xa8\xe7\x9b\xae\xe6\xa0\x87\xe5\x8c\xba\xe5\x9f\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\xaf\xb9\xe9\xbd\x90\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericVisualAttachment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x99\x84\xe7\x9d\x80\xe5\x86\x85\xe5\xae\xb9\xe9\x94\x9a\xe7\x82\xb9\xef\xbc\x8c\xe5\x86\xb3\xe5\xae\x9a\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x9c\xa8\xe7\x9b\xae\xe6\xa0\x87\xe5\x8c\xba\xe5\x9f\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\xaf\xb9\xe9\xbd\x90\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericVisualAttachment constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContentAnchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericVisualAttachment constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetContentAnchor"), .Pointer = &UGenericVisualAttachment::execGetContentAnchor },
		{ .NameUTF8 = UTF8TEXT("SetContentAnchor"), .Pointer = &UGenericVisualAttachment::execSetContentAnchor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericVisualAttachment_GetContentAnchor, "GetContentAnchor" }, // 344470252
		{ &Z_Construct_UFunction_UGenericVisualAttachment_SetContentAnchor, "SetContentAnchor" }, // 2788218107
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericVisualAttachment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericVisualAttachment_Statics

// ********** Begin Class UGenericVisualAttachment Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericVisualAttachment_Statics::NewProp_ContentAnchor = { "ContentAnchor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UGenericVisualAttachment::SetContentAnchor_WrapperImpl, &UGenericVisualAttachment::GetContentAnchor_WrapperImpl, 1, STRUCT_OFFSET(UGenericVisualAttachment, ContentAnchor), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentAnchor_MetaData), NewProp_ContentAnchor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericVisualAttachment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericVisualAttachment_Statics::NewProp_ContentAnchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVisualAttachment_Statics::PropPointers) < 2048);
// ********** End Class UGenericVisualAttachment Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UGenericVisualAttachment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USizeBox,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVisualAttachment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericVisualAttachment_Statics::ClassParams = {
	&UGenericVisualAttachment::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGenericVisualAttachment_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVisualAttachment_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVisualAttachment_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericVisualAttachment_Statics::Class_MetaDataParams)
};
void UGenericVisualAttachment::StaticRegisterNativesUGenericVisualAttachment()
{
	UClass* Class = UGenericVisualAttachment::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericVisualAttachment_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericVisualAttachment()
{
	if (!Z_Registration_Info_UClass_UGenericVisualAttachment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericVisualAttachment.OuterSingleton, Z_Construct_UClass_UGenericVisualAttachment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericVisualAttachment.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericVisualAttachment);
UGenericVisualAttachment::~UGenericVisualAttachment() {}
// ********** End Class UGenericVisualAttachment ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericVisualAttachment, UGenericVisualAttachment::StaticClass, TEXT("UGenericVisualAttachment"), &Z_Registration_Info_UClass_UGenericVisualAttachment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericVisualAttachment), 515190533U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h__Script_GenericSlateFramework_3627752192{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericVisualAttachment_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
