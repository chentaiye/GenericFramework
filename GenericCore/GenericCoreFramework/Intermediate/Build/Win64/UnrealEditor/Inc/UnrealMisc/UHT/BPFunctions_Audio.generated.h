// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Audio.h"

#ifdef UNREALMISC_BPFunctions_Audio_generated_h
#error "BPFunctions_Audio.generated.h already included, missing '#pragma once' in BPFunctions_Audio.h"
#endif
#define UNREALMISC_BPFunctions_Audio_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundWave;

// ********** Begin Class UBPFunctions_Audio *******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConvertAudioDataToSoundWave); \
	DECLARE_FUNCTION(execConvertWavFileToSoundWave);


struct Z_Construct_UClass_UBPFunctions_Audio_Statics;
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Audio_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Audio(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Audio_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UNREALMISC_API UClass* ::Z_Construct_UClass_UBPFunctions_Audio_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Audio, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealMisc"), Z_Construct_UClass_UBPFunctions_Audio_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Audio)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UNREALMISC_API UBPFunctions_Audio(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Audio(UBPFunctions_Audio&&) = delete; \
	UBPFunctions_Audio(const UBPFunctions_Audio&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UNREALMISC_API, UBPFunctions_Audio); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Audio); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Audio) \
	UNREALMISC_API virtual ~UBPFunctions_Audio();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Audio;

// ********** End Class UBPFunctions_Audio *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
