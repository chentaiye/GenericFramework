// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericWorldSettingsSubsystem.generated.h"

class UGenericWorldSettings;
class UGenericWorldSettingsCollection;

/** 在运行时读取当前世界已保存的设置总集，并为其他世界子系统提供强类型查询入口。 */
UCLASS(MinimalAPI)
class UGenericWorldSettingsSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	/** 通过世界上下文取得运行时设置子系统，便于蓝图和跨模块 C++ 调用统一入口。 */
	UFUNCTION(BlueprintPure, Category="World Settings", meta=(WorldContext="WorldContextObject"))
	static GENERICSETTINGSFRAMEWORK_API UGenericWorldSettingsSubsystem* GetWorldSettingsSubsystem(const UObject* WorldContextObject);

	/** 返回当前世界挂载到 AWorldSettings 的设置总集；没有保存过总集时返回空。 */
	UFUNCTION(BlueprintPure, Category="World Settings")
	GENERICSETTINGSFRAMEWORK_API UGenericWorldSettingsCollection* GetSettingsCollection() const;

	/** 读取当前世界中指定类型的设置实例；不会创建缺失对象。 */
	UFUNCTION(BlueprintPure, Category="World Settings", meta=(DeterminesOutputType="SettingsClass"))
	GENERICSETTINGSFRAMEWORK_API UGenericWorldSettings* GetWorldSetting(TSubclassOf<UGenericWorldSettings> SettingsClass) const;

	template <typename SettingsType>
	SettingsType* GetWorldSetting() const
	{
		return Cast<SettingsType>(GetWorldSetting(SettingsType::StaticClass()));
	}

protected:
	GENERICSETTINGSFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICSETTINGSFRAMEWORK_API virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	GENERICSETTINGSFRAMEWORK_API virtual void OnWorldMatchStarting() override;
	GENERICSETTINGSFRAMEWORK_API virtual void OnWorldPostBeginPlay() override;
	GENERICSETTINGSFRAMEWORK_API virtual void OnWorldBeginTearDown(UWorld* InWorld) override;
	GENERICSETTINGSFRAMEWORK_API virtual void Deinitialize() override;
	GENERICSETTINGSFRAMEWORK_API virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	/** 从当前世界的 AWorldSettings 中读取总集，并通知设置实例完成运行时加载。 */
	void LoadSettingsCollection();

	/** 收集当前总集中仍然有效的设置实例。 */
	void GetLoadedSettings(TArray<UGenericWorldSettings*>& OutSettings) const;

	/** 调用每个设置实例的运行时加载钩子，确保其他子系统读取前有稳定初始化机会。 */
	void NotifySettingsLoaded();

	/** 调用每个设置实例的 BeginPlay 钩子。 */
	void NotifySettingsBeginPlay();

	/** 在 Actor BeginPlay 完成后通知依赖世界对象注册结果的设置实例。 */
	void NotifySettingsMatchStarting();

	/** 在世界 BeginPlay 广播完成后通知需要最终运行时联动的设置实例。 */
	void NotifySettingsPostBeginPlay();

	/** 调用每个设置实例的 TearDown 钩子。 */
	void NotifySettingsBeginTearDown();

	/** 调用每个设置实例的运行时卸载钩子。 */
	void NotifySettingsUnloaded();

private:
	/** 缓存当前世界的设置总集引用，生命周期由地图的 AWorldSettings 持有。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericWorldSettingsCollection> SettingsCollection = nullptr;

	/** 标记本世界的设置实例是否已经触发过运行时加载通知。 */
	bool bSettingsLoadedNotified = false;

	/** 标记本世界的设置实例是否已经触发过 BeginPlay 通知。 */
	bool bSettingsBeginPlayNotified = false;

	/** 记录本世界的设置实例是否已经触发过 MatchStarting 通知。 */
	bool bSettingsMatchStartingNotified = false;

	/** 记录本世界的设置实例是否已经触发过 PostBeginPlay 通知。 */
	bool bSettingsPostBeginPlayNotified = false;

	/** 标记本世界的设置实例是否已经触发过 TearDown 通知。 */
	bool bSettingsTearDownNotified = false;

	/** 标记本世界的设置实例是否已经触发过运行时卸载通知。 */
	bool bSettingsUnloadedNotified = false;
};
