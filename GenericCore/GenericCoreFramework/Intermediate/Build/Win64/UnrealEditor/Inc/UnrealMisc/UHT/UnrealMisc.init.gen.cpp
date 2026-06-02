// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealMisc_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealMisc;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealMisc()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealMisc.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/UnrealMisc",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x4900500D,
			0xE416DF5A,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealMisc.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_UnrealMisc.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealMisc(Z_Construct_UPackage__Script_UnrealMisc, TEXT("/Script/UnrealMisc"), Z_Registration_Info_UPackage__Script_UnrealMisc, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4900500D, 0xE416DF5A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
