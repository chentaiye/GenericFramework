// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayMessageType.h"

#ifdef GENERICMESSAGEFRAMEWORK_GameplayMessageType_generated_h
#error "GameplayMessageType.generated.h already included, missing '#pragma once' in GameplayMessageType.h"
#endif
#define GENERICMESSAGEFRAMEWORK_GameplayMessageType_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h

// ********** Begin Enum EGameplayMessageMatch *****************************************************
#define FOREACH_ENUM_EGAMEPLAYMESSAGEMATCH(op) \
	op(EGameplayMessageMatch::ExactMatch) \
	op(EGameplayMessageMatch::PartialMatch) 

enum class EGameplayMessageMatch : uint8;
template<> struct TIsUEnumClass<EGameplayMessageMatch> { enum { Value = true }; };
template<> GENERICMESSAGEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGameplayMessageMatch>();
// ********** End Enum EGameplayMessageMatch *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
