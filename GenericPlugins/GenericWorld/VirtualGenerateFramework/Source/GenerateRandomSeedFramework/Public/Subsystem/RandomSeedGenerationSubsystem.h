#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "RandomSeedGenerationSubsystem.generated.h"

/** 在单个 World 生命周期内维护命名随机种子，让每个地图拥有互不串扰的随机状态。 */
UCLASS(MinimalAPI)
class URandomSeedGenerationSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Random Seed", meta=(WorldContext="WorldContextObject"))
	static GENERATERANDOMSEEDFRAMEWORK_API URandomSeedGenerationSubsystem* Get(const UObject* WorldContextObject);

	GENERATERANDOMSEEDFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERATERANDOMSEEDFRAMEWORK_API virtual void Deinitialize() override;

	/** 检查指定 Key 是否已经有子系统维护的种子。 */
	UFUNCTION(BlueprintPure, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API bool HasManagedSeed(FName SeedKey) const;

	/** 读取指定 Key 当前保存的 64 位种子，不存在时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API bool GetManagedSeed(FName SeedKey, int64& OutSeed) const;

	/** 获取指定 Key 的种子；首次访问时按 Key 构造稳定的默认值并保存。 */
	UFUNCTION(BlueprintCallable, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API int64 GetOrCreateManagedSeed(FName SeedKey);

	/** 写入指定 Key 的 64 位种子，后续随机流会基于这个值派生。 */
	UFUNCTION(BlueprintCallable, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API int64 SetManagedSeed(FName SeedKey, int64 Seed);

	/** 为指定 Key 生成新的运行时种子并覆盖保存值，适合刷新一次性随机流程。 */
	UFUNCTION(BlueprintCallable, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API int64 GenerateManagedSeed(FName SeedKey);

	/** 移除指定 Key 的保存值，下次访问会重新走默认种子生成。 */
	UFUNCTION(BlueprintCallable, Category="Random Seed")
	GENERATERANDOMSEEDFRAMEWORK_API bool RemoveManagedSeed(FName SeedKey);

	/** 将 64 位保存种子和调用方盐值折叠成 FRandomStream 可使用的 32 位随机流。 */
	GENERATERANDOMSEEDFRAMEWORK_API FRandomStream MakeRandomStream(FName SeedKey, int32 SaltA=0, int32 SaltB=0);

	/** 根据世界设置初始化默认种子；自定义关闭时仅在尚无默认种子时自动生成。 */
	GENERATERANDOMSEEDFRAMEWORK_API int64 ApplyWorldSeedSettings(bool bUseCustomSeed, int64 CustomSeed);

protected:
	GENERATERANDOMSEEDFRAMEWORK_API virtual void OnWorldBeginPlay(UWorld& InWorld) override;

private:
	/** 从当前世界的 GenericWorldSettingsCollection 读取随机种子设置，覆盖初始化顺序不确定的场景。 */
	void ApplyWorldSeedSettingsFromCurrentWorld();

	/** 把空 Key 归一到默认命名空间，避免调用方传 None 时产生多套默认种子。 */
	static FName NormalizeSeedKey(FName SeedKey);

	/** 按 Key 构造稳定的 64 位默认种子，保证未显式设置时也能重复复现。 */
	static int64 BuildDeterministicSeed(FName SeedKey);

	/** 混合 Key、Guid 和递增计数生成运行时 64 位种子。 */
	int64 BuildGeneratedSeed(FName SeedKey);

private:
	/** 保存命名种子；使用 int64 保留外部系统写入的大范围随机状态。 */
	UPROPERTY(Transient)
	TMap<FName, int64> ManagedSeeds;

	/** 参与运行时生成种子的递增计数，避免同一帧内多次刷新得到同值。 */
	uint64 RuntimeGenerationCounter=0;
};
