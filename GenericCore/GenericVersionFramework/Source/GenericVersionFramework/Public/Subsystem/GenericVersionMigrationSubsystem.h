// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "Types/GenericVersionTypes.h"
#include "GenericVersionMigrationSubsystem.generated.h"

class FGenericVersionMigrationObject;
class FGenericVersionObject;

/** 执行对象版本迁移的轻量入口，只调用迁移接口并分发结果处理。 */
UCLASS(MinimalAPI)
class UGenericVersionMigrationSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICVERSIONFRAMEWORK_API UGenericVersionMigrationSubsystem* Get(const UObject* WorldContextObject);

	/** 使用中心版本缓存构造上下文并执行一次对象迁移；不会自动校验、刷新或保存对象。 */
#if CPP
	GENERICVERSIONFRAMEWORK_API FGenericVersionMigrationResult MigrateObject(FGenericVersionObject* TargetObject, UObject* ContextObject = nullptr);
#endif

	/** 根据迁移状态调用对象的成功或失败处理函数；未实现接口时仅返回 false。 */
#if CPP
	GENERICVERSIONFRAMEWORK_API bool HandleMigrationResult(FGenericVersionMigrationObject* TargetObject, const FGenericVersionMigrationResult& Result);
#endif

	/** 构造迁移成功结果，供业务层复用统一结构。 */
	UFUNCTION(BlueprintPure, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionMigrationResult MakeMigrationSuccess(const FGenericVersionInfo& SourceVersion, const FGenericVersionInfo& TargetVersion, const FText& Message) const;

	/** 构造迁移失败结果，失败后的后续处理由业务层决定。 */
	UFUNCTION(BlueprintPure, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionMigrationResult MakeMigrationFailed(const FGenericVersionInfo& SourceVersion, const FGenericVersionInfo& TargetVersion, FName ErrorCode, const FText& Message) const;

private:
	/** 从中心版本缓存读取数据并组装调用上下文。 */
#if CPP
	bool BuildVersionContext(FGenericVersionObject* TargetObject, UObject* ContextObject, FGenericVersionContext& OutContext) const;
#endif
};
