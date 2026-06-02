// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "Types/GenericVersionTypes.h"
#include "UObject/ObjectKey.h"
#include "GenericVersionDataSubsystem.generated.h"

class FGenericVersionObject;

/** 版本数据中心，统一保存版本定义，并缓存对象当前解析后的版本快照。 */
UCLASS(MinimalAPI)
class UGenericVersionDataSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICVERSIONFRAMEWORK_API UGenericVersionDataSubsystem* Get(const UObject* WorldContextObject);

	GENERICVERSIONFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 从项目设置读取版本定义并注册到中心表，已存在的 VersionKey 会被设置中的定义覆盖。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API int32 RegisterVersionDefinitionsFromSettings();

	/** 写入中央版本定义，后续对象版本数据会通过 VersionKey 合并这里的最新版本和最低支持版本。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API bool SetVersionDefinition(const FGenericVersionDefinition& VersionDefinition);

	/** 读取中央版本定义，不会读取或刷新任何具体业务对象。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API bool GetVersionDefinition(FGameplayTag VersionKey, FGenericVersionDefinition& OutVersionDefinition) const;

	/** 移除指定版本键的中央定义，不会删除已经缓存的对象版本快照。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API bool RemoveVersionDefinition(FGameplayTag VersionKey);

	/** 清空所有中央版本定义，不会删除已经缓存的对象版本快照。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API void ClearVersionDefinitions();

	/** 校验对象版本数据是否能在中央定义表中找到对应版本策略。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API bool ResolveVersionData(const FGenericVersionData& SourceVersionData, FGenericVersionData& OutVersionData) const;

	/** 将调用方传入的对象版本数据写入中心缓存；写入前会先与中央版本定义合并。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
#if CPP
	GENERICVERSIONFRAMEWORK_API bool RefreshVersionData(FGenericVersionObject* TargetObject, const FGenericVersionData& VersionData, FGenericVersionData& OutVersionData);
#endif
	GENERICVERSIONFRAMEWORK_API bool RefreshVersionData(UObject* TargetObject, const FGenericVersionData& VersionData, FGenericVersionData& OutVersionData);

	/** 读取指定对象当前缓存的版本快照，不会主动调用对象接口刷新。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
#if CPP
	GENERICVERSIONFRAMEWORK_API bool GetVersionData(FGenericVersionObject* TargetObject, FGenericVersionData& OutVersionData) const;
#endif
	GENERICVERSIONFRAMEWORK_API bool GetVersionData(UObject* TargetObject, FGenericVersionData& OutVersionData) const;

	/** 手动写入指定对象的版本数据，写入前会先和中央定义合并。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
#if CPP
	GENERICVERSIONFRAMEWORK_API bool SetVersionData(FGenericVersionObject* TargetObject, const FGenericVersionData& VersionData);
#endif
	GENERICVERSIONFRAMEWORK_API bool SetVersionData(UObject* TargetObject, const FGenericVersionData& VersionData);

	/** 移除指定对象的版本缓存。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
#if CPP
	GENERICVERSIONFRAMEWORK_API bool RemoveVersionData(FGenericVersionObject* TargetObject);
#endif
	GENERICVERSIONFRAMEWORK_API bool RemoveVersionData(UObject* TargetObject);

	/** 移除指定版本键对应的所有对象版本缓存。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API bool RemoveVersionDataByKey(FGameplayTag VersionKey);

	/** 清空中心对象版本缓存，不会清空中央版本定义。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API void ClearVersionData();

private:
	/** 中央版本定义表，统一保存各 VersionKey 的当前版本策略。 */
	TMap<FGameplayTag, FGenericVersionDefinition> VersionDefinitionByKey;

	/** 按对象实例缓存已经和中央定义合并后的版本快照。 */
	TMap<FObjectKey, FGenericVersionData> VersionDataByObject;
#if CPP
	TMap<const FGenericVersionObject*, FGenericVersionData> VersionDataByVersionObject;
#endif
};
