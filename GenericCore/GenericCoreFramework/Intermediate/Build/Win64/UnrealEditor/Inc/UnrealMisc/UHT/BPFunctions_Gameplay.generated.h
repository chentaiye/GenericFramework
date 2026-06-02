// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Gameplay.h"

#ifdef UNREALMISC_BPFunctions_Gameplay_generated_h
#error "BPFunctions_Gameplay.generated.h already included, missing '#pragma once' in BPFunctions_Gameplay.h"
#endif
#define UNREALMISC_BPFunctions_Gameplay_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AGameModeBase;
class AGameSession;
class AGameStateBase;
class AHUD;
class APawn;
class APlayerController;
class APlayerState;
class UClass;
class UGameInstance;
class UInterface;
class ULocalPlayer;
class UObject;
class USceneComponent;
struct FHitResult;
struct FUniqueNetIdRepl;

// ********** Begin Class UBPFunctions_Gameplay ****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetComponentDownHitResult); \
	DECLARE_FUNCTION(execGetComponentRightHitResult); \
	DECLARE_FUNCTION(execGetComponentForwardHitResult); \
	DECLARE_FUNCTION(execGetActorDownHitResult); \
	DECLARE_FUNCTION(execGetActorRightHitResult); \
	DECLARE_FUNCTION(execGetActorForwardHitResult); \
	DECLARE_FUNCTION(execSetAllActorsVisibilityWithTag_Interface); \
	DECLARE_FUNCTION(execSetAllActorsVisibilityWithTag_Class); \
	DECLARE_FUNCTION(execSetAllActorsVisibilityWithInterface); \
	DECLARE_FUNCTION(execSetAllActorsVisibility); \
	DECLARE_FUNCTION(execGetIsAIPossessPawn); \
	DECLARE_FUNCTION(execGetIsPlayerPossessPawn); \
	DECLARE_FUNCTION(execGetPlayerUniqueNetIDByPlayerIndex); \
	DECLARE_FUNCTION(execGetPlayerUniqueNetIDByPawn); \
	DECLARE_FUNCTION(execGetPlayerUniqueNetIDByPlayerState); \
	DECLARE_FUNCTION(execGetPlayerUniqueNetID); \
	DECLARE_FUNCTION(execGetPlayerIDByPawn); \
	DECLARE_FUNCTION(execGetPlayerIDByPlayerState); \
	DECLARE_FUNCTION(execGetPlayerID); \
	DECLARE_FUNCTION(execGetPawnByUniqueNetID); \
	DECLARE_FUNCTION(execGetHUDByUniqueNetID); \
	DECLARE_FUNCTION(execGetPlayerStateByUniqueNetID); \
	DECLARE_FUNCTION(execGetLocalPlayerByUniqueNetID); \
	DECLARE_FUNCTION(execGetPlayerControllerByUniqueNetID); \
	DECLARE_FUNCTION(execGetPawnByIndex); \
	DECLARE_FUNCTION(execGetHUDByIndex); \
	DECLARE_FUNCTION(execGetPlayerStateByIndex); \
	DECLARE_FUNCTION(execGetLocalPlayerByIndex); \
	DECLARE_FUNCTION(execGetPlayerControllerByIndex); \
	DECLARE_FUNCTION(execGetGameStateByClass); \
	DECLARE_FUNCTION(execGetGameSessionByClass); \
	DECLARE_FUNCTION(execGetGameModeByClass); \
	DECLARE_FUNCTION(execGetGameInstanceByClass);


struct Z_Construct_UClass_UBPFunctions_Gameplay_Statics;
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Gameplay_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Gameplay(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Gameplay_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UNREALMISC_API UClass* ::Z_Construct_UClass_UBPFunctions_Gameplay_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Gameplay, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealMisc"), Z_Construct_UClass_UBPFunctions_Gameplay_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Gameplay)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UNREALMISC_API UBPFunctions_Gameplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Gameplay(UBPFunctions_Gameplay&&) = delete; \
	UBPFunctions_Gameplay(const UBPFunctions_Gameplay&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UNREALMISC_API, UBPFunctions_Gameplay); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Gameplay); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Gameplay) \
	UNREALMISC_API virtual ~UBPFunctions_Gameplay();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_18_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Gameplay;

// ********** End Class UBPFunctions_Gameplay ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
