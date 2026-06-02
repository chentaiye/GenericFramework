// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "Types/GenericVersionTypes.h"
#include "GenericVersionValidationSubsystem.generated.h"

class FGenericVersionObject;
class FGenericVersionValidationObject;

/** 执行对象版本校验的轻量入口，先做中心版本比较，再交给业务对象补充规则。 */
UCLASS(MinimalAPI)
class UGenericVersionValidationSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICVERSIONFRAMEWORK_API UGenericVersionValidationSubsystem* Get(const UObject* WorldContextObject);

	/** 使用中心版本缓存构造上下文并执行一次对象校验；不会刷新版本数据或触发迁移。 */
#if CPP
	GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult ValidateObject(FGenericVersionObject* TargetObject, UObject* ContextObject = nullptr);
#endif

	/** 比较对象版本和中央版本定义，不调用业务接口。 */
	UFUNCTION(BlueprintCallable, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult ValidateVersionContext(const FGenericVersionContext& Context) const;

	/** 根据校验状态调用对象的成功或失败处理函数；未实现接口时仅返回 false。 */
#if CPP
	GENERICVERSIONFRAMEWORK_API bool HandleValidationResult(FGenericVersionValidationObject* TargetObject, const FGenericVersionValidationResult& Result);
#endif

	/** 构造校验成功结果，供业务层复用统一结构。 */
	UFUNCTION(BlueprintPure, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult MakeValidationSuccess(const FText& Message) const;

	/** 构造校验警告结果，警告不阻断业务层后续流程。 */
	UFUNCTION(BlueprintPure, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult MakeValidationWarning(FName ErrorCode, const FText& Message) const;

	/** 构造校验失败结果，失败是否阻断由业务层根据返回值决定。 */
	UFUNCTION(BlueprintPure, Category="Generic Version")
	GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult MakeValidationFailed(FName ErrorCode, const FText& Message) const;

private:
	/** 从中心版本缓存读取数据并组装调用上下文。 */
#if CPP
	bool BuildVersionContext(FGenericVersionObject* TargetObject, UObject* ContextObject, FGenericVersionContext& OutContext) const;
#endif
};
