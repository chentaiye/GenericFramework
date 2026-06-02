// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "RandomSeedWorldSettings.generated.h"

/** 保存当前世界的默认随机种子策略，运行时由 GenerateRandomSeedFramework 子系统读取并应用到该世界。 */
UCLASS(MinimalAPI)
class URandomSeedWorldSettings : public UGenericWorldSettings
{
	GENERATED_BODY()

public:
	/** 是否使用下方固定种子；关闭时如果当前世界还没有默认种子，会在加载设置时自动生成一次。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Random Seed")
	bool bUseCustomSeed = false;

	/** 当前世界的固定默认种子，仅在启用自定义种子时参与初始化。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Random Seed", meta=(EditCondition="bUseCustomSeed"))
	int64 CustomSeed = 0;

protected:
#if WITH_EDITOR
	virtual FName GetSettingsCategory_Implementation() const override;
#endif

	virtual void OnWorldSettingsLoaded_Implementation(UWorld* World) override;
};
