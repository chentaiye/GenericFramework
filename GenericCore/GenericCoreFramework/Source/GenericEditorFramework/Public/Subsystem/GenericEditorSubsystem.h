// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "GenericEditorSubsystem.generated.h"

/** 作为通用编辑器子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	GENERICEDITORFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	GENERICEDITORFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICEDITORFRAMEWORK_API virtual void Deinitialize() override;
};
