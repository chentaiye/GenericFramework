// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/SubtitleTextBlock.h"

#ifdef GENERICSLATEFRAMEWORK_SubtitleTextBlock_generated_h
#error "SubtitleTextBlock.generated.h already included, missing '#pragma once' in SubtitleTextBlock.h"
#endif
#define GENERICSLATEFRAMEWORK_SubtitleTextBlock_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ETextOverflowPolicy : uint8;
enum class ETextTransformPolicy : uint8;
struct FLinearColor;
struct FSlateColor;
struct FSlateFontInfo;

// ********** Begin Delegate FOnSubtitleLineAdded **************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_14_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnSubtitleLineAdded_DelegateWrapper(const FMulticastScriptDelegate& OnSubtitleLineAdded, FText const& AddedLine);


// ********** End Delegate FOnSubtitleLineAdded ****************************************************

// ********** Begin Class USubtitleTextBlock *******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetPauseExpiration); \
	DECLARE_FUNCTION(execSetDefaultLineLifetimeSeconds); \
	DECLARE_FUNCTION(execSetMaxStoredLines); \
	DECLARE_FUNCTION(execSetLineOpacityStep); \
	DECLARE_FUNCTION(execSetGradientLineCount); \
	DECLARE_FUNCTION(execSetMaxDisplayHeight); \
	DECLARE_FUNCTION(execSetTailVisibleLineCount); \
	DECLARE_FUNCTION(execSetTextOverflowPolicy); \
	DECLARE_FUNCTION(execGetTextOverflowPolicy); \
	DECLARE_FUNCTION(execSetTextTransformPolicy); \
	DECLARE_FUNCTION(execGetTextTransformPolicy); \
	DECLARE_FUNCTION(execSetMinDesiredWidth); \
	DECLARE_FUNCTION(execGetMinDesiredWidth); \
	DECLARE_FUNCTION(execSetShadowColorAndOpacity); \
	DECLARE_FUNCTION(execGetShadowColorAndOpacity); \
	DECLARE_FUNCTION(execSetShadowOffset); \
	DECLARE_FUNCTION(execGetShadowOffset); \
	DECLARE_FUNCTION(execSetColorAndOpacity); \
	DECLARE_FUNCTION(execGetColorAndOpacity); \
	DECLARE_FUNCTION(execSetFont); \
	DECLARE_FUNCTION(execGetFont); \
	DECLARE_FUNCTION(execAddTextWithLifetime); \
	DECLARE_FUNCTION(execAddText); \
	DECLARE_FUNCTION(execClearLines); \
	DECLARE_FUNCTION(execAppendLines); \
	DECLARE_FUNCTION(execSetLines); \
	DECLARE_FUNCTION(execGetLines); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execGetText);


struct Z_Construct_UClass_USubtitleTextBlock_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USubtitleTextBlock_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSubtitleTextBlock(); \
	friend struct ::Z_Construct_UClass_USubtitleTextBlock_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_USubtitleTextBlock_NoRegister(); \
public: \
	DECLARE_CLASS2(USubtitleTextBlock, UTextLayoutWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_USubtitleTextBlock_NoRegister) \
	DECLARE_SERIALIZER(USubtitleTextBlock)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	USubtitleTextBlock(USubtitleTextBlock&&) = delete; \
	USubtitleTextBlock(const USubtitleTextBlock&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, USubtitleTextBlock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubtitleTextBlock); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USubtitleTextBlock) \
	GENERICSLATEFRAMEWORK_API virtual ~USubtitleTextBlock();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_17_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USubtitleTextBlock;

// ********** End Class USubtitleTextBlock *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
