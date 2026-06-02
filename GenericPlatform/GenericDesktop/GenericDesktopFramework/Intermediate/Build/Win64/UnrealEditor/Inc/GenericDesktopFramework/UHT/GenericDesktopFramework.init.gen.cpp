// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericDesktopFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature();
	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature();
	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDialogCompleted__DelegateSignature();
	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopHardwareSnapshotFailed__DelegateSignature();
	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopHardwareSnapshotReady__DelegateSignature();
	GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericDesktopFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericDesktopFramework.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDialogCompleted__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopHardwareSnapshotFailed__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopHardwareSnapshotReady__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericDesktopFramework",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x5AAB20BD,
			0xBD8148C0,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericDesktopFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericDesktopFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericDesktopFramework(Z_Construct_UPackage__Script_GenericDesktopFramework, TEXT("/Script/GenericDesktopFramework"), Z_Registration_Info_UPackage__Script_GenericDesktopFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5AAB20BD, 0xBD8148C0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
