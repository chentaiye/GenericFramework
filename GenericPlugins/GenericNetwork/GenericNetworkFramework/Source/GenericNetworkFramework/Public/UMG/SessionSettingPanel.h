// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "Base/GenericWidget.h"
#include "SessionSettingPanel.generated.h"

/** 会话设置面板，预留将 FGenericSessionSettings 映射到属性代理或表单控件的 UI 承载点。 */
UCLASS(MinimalAPI)
class USessionSettingPanel : public UGenericWidget
{
	GENERATED_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICNETWORKFRAMEWORK_API virtual void NativeDestruct() override;

protected:
	/** 属性代理注册时用于把会话设置字段接入面板，后续启用属性框架时在这里建立绑定。 */
	// virtual void OnPropertyProxyRegister(FGameplayTag InProxyTag, UPropertyProxy* InProxy);

	/** 响应属性Proxy取消注册，清理会话设置面板中的绑定状态。 */
	// virtual void OnPropertyProxyUnRegister(FGameplayTag InProxyTag, UPropertyProxy* InProxy);

	/** 刷新会话设置数据源集合，用于重新生成设置表单。 */
	// virtual void RefreshSessionSettingDataSourceCollection();

public:
	// UFUNCTION(BlueprintPure)
	// const FGenericSessionSettings& GetSessionSettings() const;

	// UFUNCTION(BlueprintCallable)
	//  void SetSessionSettings(const FGenericSessionSettings& InSessionSettings);

protected:
	/** 保存当前面板编辑或展示的会话设置，后续属性代理启用时会作为数据源。 */
	UPROPERTY()
	FGenericSessionSettings SessionSettings;

	// UPROPERTY(EditAnywhere, BlueprintReadOnly)
	// TObjectPtr<UPropertyCollectionAsset> SessionSettingCollectionAsset = nullptr;

	// UPROPERTY()
	// TArray<TObjectPtr<UPropertyProxy>> SessionSettingProxies;

private:
};
