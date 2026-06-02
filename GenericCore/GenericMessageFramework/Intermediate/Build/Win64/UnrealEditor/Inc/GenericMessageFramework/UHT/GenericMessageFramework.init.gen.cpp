// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericMessageFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	GENERICMESSAGEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericMessageFramework_AsyncGameplayMessageDelegate__DelegateSignature();
	GENERICMESSAGEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericMessageFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericMessageFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericMessageFramework.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericMessageFramework_AsyncGameplayMessageDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericMessageFramework",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x03A3EEED,
			0x66AFF43A,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericMessageFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericMessageFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericMessageFramework(Z_Construct_UPackage__Script_GenericMessageFramework, TEXT("/Script/GenericMessageFramework"), Z_Registration_Info_UPackage__Script_GenericMessageFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x03A3EEED, 0x66AFF43A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
