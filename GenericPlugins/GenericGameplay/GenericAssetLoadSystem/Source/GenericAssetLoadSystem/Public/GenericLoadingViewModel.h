// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GenericLoadingViewModel.generated.h"

/** 承载加载视图模型职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class UGenericLoadingViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	/** 获取加载值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Loading View Model")
	GENERICASSETLOADSYSTEM_API float GetLoadingValue();

	/** 获取加载Percentage。 */
	UFUNCTION(BlueprintCallable, Category="Generic Loading View Model")
	GENERICASSETLOADSYSTEM_API float GetLoadingPercentage();

public:
	/** 记录当前LoadingNum。 */
	UPROPERTY(FieldNotify, EditAnywhere, BlueprintReadWrite, Category="Generic Loading View Model")
	int32 CurrentLoadingNum=0;

	/** 记录TotalLoadingNum。 */
	UPROPERTY(FieldNotify, EditAnywhere, BlueprintReadWrite, Category="Generic Loading View Model")
	int32 TotalLoadingNum=0;
};
