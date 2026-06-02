// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuthorizationType.h"

class UGenericAuthorizationSubsystem;

/** 为 Pak 挂载流程提供轻量授权门面，把外部传入的子系统和 Pak 路径转交给清单 Scope 校验。 */
class GENERICAUTHORIZATION_API FAuthorizationPakMountGuard
{
public:
	/** 在子系统可用时检查 Pak 路径对应 Scope 是否已授权，并把匹配到的 Scope 与状态回写给调用方。 */
	static bool CanMountPakFile(const UGenericAuthorizationSubsystem* InSubsystem, const FString& PakFilePath, FName* OutScopeId = nullptr, EAuthorizationState* OutState = nullptr);
};
