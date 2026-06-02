// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "GenericWorldSettingsCollection.generated.h"

class UGenericWorldSettings;

/** 嵌入 AWorldSettings 的世界设置总集，随地图保存该世界实际使用的一组设置实例。 */
UCLASS(BlueprintType)
class GENERICSETTINGSFRAMEWORK_API UGenericWorldSettingsCollection : public UAssetUserData
{
	GENERATED_BODY()

public:
	virtual UWorld* GetWorld() const override;
	virtual void PostLoad() override;

#if WITH_EDITOR
	virtual void PreSave(FObjectPreSaveContext SaveContext) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/** 按精确类型读取当前世界保存的设置实例；一个 Settings Class 在同一总集中只会返回一份。 */
	UFUNCTION(BlueprintPure, Category="World Settings", meta=(DeterminesOutputType="SettingsClass"))
	UGenericWorldSettings* FindSettings(TSubclassOf<UGenericWorldSettings> SettingsClass) const;

	/** C++ 侧按精确 UClass 查询设置实例，避免父类查询误命中任意派生设置。 */
	UGenericWorldSettings* FindSettingsByExactClass(const UClass* SettingsClass) const;

#if WITH_EDITOR
	/** 编辑器同步缺失设置时使用；如果该类已有实例则复用，不覆盖地图中已保存的数据。 */
	UGenericWorldSettings* FindOrCreateSettings(TSubclassOf<UGenericWorldSettings> SettingsClass);
#endif

	/** 收集当前总集中可用的设置实例；重复类只返回第一份，保证生命周期通知不会重复触发。 */
	void GetAllSettings(TArray<UGenericWorldSettings*>& OutSettings) const;

	/** 移除空指针、不可实例化类型和重复类实例，维护“一种设置类一份”的集合约束。 */
	bool RemoveInvalidSettings();

	/** 保存当前世界下所有设置实例；该数组随地图持久化，运行时只读取不自动创建。 */
	UPROPERTY(EditAnywhere, Instanced, Category="World Settings")
	TArray<TObjectPtr<UGenericWorldSettings>> Settings;
};
