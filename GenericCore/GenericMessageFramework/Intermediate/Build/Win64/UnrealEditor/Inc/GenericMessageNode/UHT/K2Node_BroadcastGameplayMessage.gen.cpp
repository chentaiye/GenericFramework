// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "K2Node_BroadcastGameplayMessage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeK2Node_BroadcastGameplayMessage() {}

// ********** Begin Cross Module References ********************************************************
BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_AsyncAction();
GENERICMESSAGENODE_API UClass* Z_Construct_UClass_UK2Node_BroadcastGameplayMessage();
GENERICMESSAGENODE_API UClass* Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericMessageNode();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UK2Node_BroadcastGameplayMessage *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage;
UClass* UK2Node_BroadcastGameplayMessage::GetPrivateStaticClass()
{
	using TClass = UK2Node_BroadcastGameplayMessage;
	if (!Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("K2Node_BroadcastGameplayMessage"),
			Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.InnerSingleton,
			StaticRegisterNativesUK2Node_BroadcastGameplayMessage,
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
	return Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.InnerSingleton;
}
UClass* Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_NoRegister()
{
	return UK2Node_BroadcastGameplayMessage::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x9c\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe4\xb8\xad\xe6\x8f\x90\xe4\xbe\x9b\xe4\xb8\x93\xe7\x94\xa8\xe7\x9a\x84 GameplayMessage \xe5\xb9\xbf\xe6\x92\xad\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe4\xbb\xbb\xe6\x84\x8f\xe7\xbb\x93\xe6\x9e\x84\xe4\xbd\x93\xe8\xbd\xbd\xe8\x8d\xb7\xe5\x86\x99\xe5\x85\xa5\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xb6\x88\xe6\x81\xaf\xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "K2Node_BroadcastGameplayMessage.h" },
		{ "ModuleRelativePath", "Public/K2Node_BroadcastGameplayMessage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe4\xb8\xad\xe6\x8f\x90\xe4\xbe\x9b\xe4\xb8\x93\xe7\x94\xa8\xe7\x9a\x84 GameplayMessage \xe5\xb9\xbf\xe6\x92\xad\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe4\xbb\xbb\xe6\x84\x8f\xe7\xbb\x93\xe6\x9e\x84\xe4\xbd\x93\xe8\xbd\xbd\xe8\x8d\xb7\xe5\x86\x99\xe5\x85\xa5\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xb6\x88\xe6\x81\xaf\xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UK2Node_BroadcastGameplayMessage constinit property declarations *********
// ********** End Class UK2Node_BroadcastGameplayMessage constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UK2Node_BroadcastGameplayMessage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics
UObject* (*const Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UK2Node_AsyncAction,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericMessageNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::ClassParams = {
	&UK2Node_BroadcastGameplayMessage::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::Class_MetaDataParams), Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::Class_MetaDataParams)
};
void UK2Node_BroadcastGameplayMessage::StaticRegisterNativesUK2Node_BroadcastGameplayMessage()
{
}
UClass* Z_Construct_UClass_UK2Node_BroadcastGameplayMessage()
{
	if (!Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.OuterSingleton, Z_Construct_UClass_UK2Node_BroadcastGameplayMessage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage.OuterSingleton;
}
UK2Node_BroadcastGameplayMessage::UK2Node_BroadcastGameplayMessage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UK2Node_BroadcastGameplayMessage);
UK2Node_BroadcastGameplayMessage::~UK2Node_BroadcastGameplayMessage() {}
// ********** End Class UK2Node_BroadcastGameplayMessage *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_BroadcastGameplayMessage_h__Script_GenericMessageNode_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UK2Node_BroadcastGameplayMessage, UK2Node_BroadcastGameplayMessage::StaticClass, TEXT("UK2Node_BroadcastGameplayMessage"), &Z_Registration_Info_UClass_UK2Node_BroadcastGameplayMessage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UK2Node_BroadcastGameplayMessage), 1535559517U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_BroadcastGameplayMessage_h__Script_GenericMessageNode_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_BroadcastGameplayMessage_h__Script_GenericMessageNode_2586783586{
	TEXT("/Script/GenericMessageNode"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_BroadcastGameplayMessage_h__Script_GenericMessageNode_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_BroadcastGameplayMessage_h__Script_GenericMessageNode_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
