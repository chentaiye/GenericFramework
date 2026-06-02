// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericWidget.h"
#include "GenericLoadingProgressBar.generated.h"

class UTextBlock;
class USpinBox;
class UGenericLoadingViewModel;

/** 作为加载ProgressBar能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class UGenericLoadingProgressBar : public UGenericWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

public:
	/** 更新Performance。 */
	UFUNCTION(BlueprintCallable, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API virtual void UpdatePerformance();

	/** 获取加载视图模型。 */
	UFUNCTION(BlueprintPure, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API UGenericLoadingViewModel* GetLoadingViewModel();

	/** 设置加载视图模型。 */
	UFUNCTION(BlueprintCallable, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API void SetLoadingViewModel(UGenericLoadingViewModel* InViewModel);

protected:
	/** 响应当前LoadingNum变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API void OnCurrentLoadingNumChanged(int32 InCurrentLoadingNum);

	/** 响应TotalLoadingNum变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API void OnTotalLoadingNumChanged(int32 InCurrentLoadingNum);

	/** 获取加载文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Loading Progress Bar")
	GENERICASSETLOADSYSTEM_API void GetLoadingText(float InValue, FText& Result);

	/** 加载视图模型。 */
	UPROPERTY()
	TObjectPtr<UGenericLoadingViewModel> LoadingViewModel=nullptr;

private:
	/** 持有SpinBoxLoading实例，供当前模块运行时复用。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Loading Progress Bar", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<USpinBox> SpinBox_Loading;

	/** 文本加载。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Loading Progress Bar", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UTextBlock> Text_Loading;
};
