//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Misc/EngineVersionComparison.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

#define UE_VERSION_EQUAL_OR_GREATER(MajorVersion, MinorVersion, PatchVersion)                                          \
  UE_GREATER_SORT(                                                                                                     \
    ENGINE_MAJOR_VERSION,                                                                                              \
    MajorVersion,                                                                                                      \
    UE_GREATER_SORT(ENGINE_MINOR_VERSION, MinorVersion, UE_GREATER_SORT(ENGINE_PATCH_VERSION, PatchVersion, true)))
