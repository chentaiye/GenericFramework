// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Audio.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Audio() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Audio();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Audio_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Audio Function ConvertAudioDataToSoundWave ******************
struct Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics
{
	struct BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms
	{
		TArray<uint8> RawData;
		FString OutputAssetName;
		FString PackagePath;
		USoundWave* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AzSpeech" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe9\x9f\xb3\xe9\xa2\x91\xe6\x95\xb0\xe6\x8d\xaeTo\xe5\xa3\xb0\xe9\x9f\xb3Wave\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_PackagePath", "" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Audio.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe9\x9f\xb3\xe9\xa2\x91\xe6\x95\xb0\xe6\x8d\xaeTo\xe5\xa3\xb0\xe9\x9f\xb3Wave\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawData_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputAssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvertAudioDataToSoundWave constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_RawData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RawData;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputAssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvertAudioDataToSoundWave constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvertAudioDataToSoundWave Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_RawData_Inner = { "RawData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_RawData = { "RawData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms, RawData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawData_MetaData), NewProp_RawData_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_OutputAssetName = { "OutputAssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms, OutputAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputAssetName_MetaData), NewProp_OutputAssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackagePath_MetaData), NewProp_PackagePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms, ReturnValue), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_RawData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_RawData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_OutputAssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::PropPointers) < 2048);
// ********** End Function ConvertAudioDataToSoundWave Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Audio, nullptr, "ConvertAudioDataToSoundWave", 	Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::BPFunctions_Audio_eventConvertAudioDataToSoundWave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Audio::execConvertAudioDataToSoundWave)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_RawData);
	P_GET_PROPERTY(FStrProperty,Z_Param_OutputAssetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USoundWave**)Z_Param__Result=UBPFunctions_Audio::ConvertAudioDataToSoundWave(Z_Param_Out_RawData,Z_Param_OutputAssetName,Z_Param_PackagePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Audio Function ConvertAudioDataToSoundWave ********************

// ********** Begin Class UBPFunctions_Audio Function ConvertWavFileToSoundWave ********************
struct Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics
{
	struct BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms
	{
		FString FileName;
		FString OutputAssetName;
		FString PackagePath;
		USoundWave* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AzSpeech|Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2WAV\xe6\x96\x87\xe4\xbb\xb6To\xe5\xa3\xb0\xe9\x9f\xb3Wave\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_PackagePath", "" },
		{ "DisplayName", "Convert .wav file to USoundWave" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Audio.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2WAV\xe6\x96\x87\xe4\xbb\xb6To\xe5\xa3\xb0\xe9\x9f\xb3Wave\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputAssetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvertWavFileToSoundWave constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputAssetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvertWavFileToSoundWave constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvertWavFileToSoundWave Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_OutputAssetName = { "OutputAssetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms, OutputAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputAssetName_MetaData), NewProp_OutputAssetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackagePath_MetaData), NewProp_PackagePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms, ReturnValue), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_OutputAssetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::PropPointers) < 2048);
// ********** End Function ConvertWavFileToSoundWave Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Audio, nullptr, "ConvertWavFileToSoundWave", 	Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::BPFunctions_Audio_eventConvertWavFileToSoundWave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Audio::execConvertWavFileToSoundWave)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY(FStrProperty,Z_Param_OutputAssetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USoundWave**)Z_Param__Result=UBPFunctions_Audio::ConvertWavFileToSoundWave(Z_Param_FileName,Z_Param_OutputAssetName,Z_Param_PackagePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Audio Function ConvertWavFileToSoundWave **********************

// ********** Begin Class UBPFunctions_Audio *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Audio;
UClass* UBPFunctions_Audio::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Audio;
	if (!Z_Registration_Info_UClass_UBPFunctions_Audio.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Audio"),
			Z_Registration_Info_UClass_UBPFunctions_Audio.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Audio,
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
	return Z_Registration_Info_UClass_UBPFunctions_Audio.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Audio_NoRegister()
{
	return UBPFunctions_Audio::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Audio_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe9\x9f\xb3\xe9\xa2\x91\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Audio.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Audio.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe9\x9f\xb3\xe9\xa2\x91\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Audio constinit property declarations ***********************
// ********** End Class UBPFunctions_Audio constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ConvertAudioDataToSoundWave"), .Pointer = &UBPFunctions_Audio::execConvertAudioDataToSoundWave },
		{ .NameUTF8 = UTF8TEXT("ConvertWavFileToSoundWave"), .Pointer = &UBPFunctions_Audio::execConvertWavFileToSoundWave },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Audio_ConvertAudioDataToSoundWave, "ConvertAudioDataToSoundWave" }, // 886896823
		{ &Z_Construct_UFunction_UBPFunctions_Audio_ConvertWavFileToSoundWave, "ConvertWavFileToSoundWave" }, // 964092013
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Audio>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Audio_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Audio_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Audio_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Audio_Statics::ClassParams = {
	&UBPFunctions_Audio::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Audio_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Audio_Statics::Class_MetaDataParams)
};
void UBPFunctions_Audio::StaticRegisterNativesUBPFunctions_Audio()
{
	UClass* Class = UBPFunctions_Audio::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Audio_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Audio()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Audio.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Audio.OuterSingleton, Z_Construct_UClass_UBPFunctions_Audio_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Audio.OuterSingleton;
}
UBPFunctions_Audio::UBPFunctions_Audio(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Audio);
UBPFunctions_Audio::~UBPFunctions_Audio() {}
// ********** End Class UBPFunctions_Audio *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Audio, UBPFunctions_Audio::StaticClass, TEXT("UBPFunctions_Audio"), &Z_Registration_Info_UClass_UBPFunctions_Audio, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Audio), 250496559U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h__Script_UnrealMisc_3579431587{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Audio_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
