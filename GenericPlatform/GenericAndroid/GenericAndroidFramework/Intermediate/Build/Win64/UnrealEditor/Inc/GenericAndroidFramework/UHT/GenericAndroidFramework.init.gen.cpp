// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericAndroidFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature();
	GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature();
	GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature();
	GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericAndroidFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericAndroidFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericAndroidFramework.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericAndroidFramework",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x60D95AC8,
			0xE0E26A5A,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericAndroidFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericAndroidFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericAndroidFramework(Z_Construct_UPackage__Script_GenericAndroidFramework, TEXT("/Script/GenericAndroidFramework"), Z_Registration_Info_UPackage__Script_GenericAndroidFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x60D95AC8, 0xE0E26A5A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
