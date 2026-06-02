// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SWidget/SGenericAnimatedSwitcher.h"

#ifdef GENERICSLATEFRAMEWORK_SGenericAnimatedSwitcher_generated_h
#error "SGenericAnimatedSwitcher.generated.h already included, missing '#pragma once' in SGenericAnimatedSwitcher.h"
#endif
#define GENERICSLATEFRAMEWORK_SGenericAnimatedSwitcher_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h

// ********** Begin Enum EGenericSwitcherTransition ************************************************
#define FOREACH_ENUM_EGENERICSWITCHERTRANSITION(op) \
	op(EGenericSwitcherTransition::FadeOnly) \
	op(EGenericSwitcherTransition::Horizontal) \
	op(EGenericSwitcherTransition::Vertical) \
	op(EGenericSwitcherTransition::Zoom) 

enum class EGenericSwitcherTransition : uint8;
template<> struct TIsUEnumClass<EGenericSwitcherTransition> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericSwitcherTransition>();
// ********** End Enum EGenericSwitcherTransition **************************************************

// ********** Begin Enum EGenericTransitionCurve ***************************************************
#define FOREACH_ENUM_EGENERICTRANSITIONCURVE(op) \
	op(EGenericTransitionCurve::Linear) \
	op(EGenericTransitionCurve::QuadIn) \
	op(EGenericTransitionCurve::QuadOut) \
	op(EGenericTransitionCurve::QuadInOut) \
	op(EGenericTransitionCurve::CubicIn) \
	op(EGenericTransitionCurve::CubicOut) \
	op(EGenericTransitionCurve::CubicInOut) 

enum class EGenericTransitionCurve : uint8;
template<> struct TIsUEnumClass<EGenericTransitionCurve> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericTransitionCurve>();
// ********** End Enum EGenericTransitionCurve *****************************************************

// ********** Begin Enum EGenericSwitcherTransitionFallbackStrategy ********************************
#define FOREACH_ENUM_EGENERICSWITCHERTRANSITIONFALLBACKSTRATEGY(op) \
	op(EGenericSwitcherTransitionFallbackStrategy::None) \
	op(EGenericSwitcherTransitionFallbackStrategy::Previous) \
	op(EGenericSwitcherTransitionFallbackStrategy::Next) \
	op(EGenericSwitcherTransitionFallbackStrategy::First) \
	op(EGenericSwitcherTransitionFallbackStrategy::Last) 

enum class EGenericSwitcherTransitionFallbackStrategy : uint8;
template<> struct TIsUEnumClass<EGenericSwitcherTransitionFallbackStrategy> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericSwitcherTransitionFallbackStrategy>();
// ********** End Enum EGenericSwitcherTransitionFallbackStrategy **********************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
