// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "Types/GenericVersionTypes.h"
#include "GenericVersionSettings.generated.h"

/** 项目级版本设置，集中声明当前项目会使用到的业务数据版本定义。 */
UCLASS(MinimalAPI)
class UGenericVersionSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	static GENERICVERSIONFRAMEWORK_API UGenericVersionSettings* Get();

	virtual FName GetSectionName() const override { return TEXT("VersionSettings"); }
#if WITH_EDITOR
	virtual FText GetSectionText() const override { return NSLOCTEXT("GenericVersion", "VersionSettingsSectionText", "VersionSettings"); }
#endif

public:
	/** 中央版本定义表，运行时由 UGenericVersionDataSubsystem 初始化时自动注册。 */
	UPROPERTY(Config, EditAnywhere, Category="Version")
	TArray<FGenericVersionDefinition> VersionDefinitions;
};
