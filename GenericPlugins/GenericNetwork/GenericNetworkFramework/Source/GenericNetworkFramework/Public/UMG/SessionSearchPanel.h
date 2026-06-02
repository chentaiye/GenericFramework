// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericWidget.h"
#include "SessionSearchPanel.generated.h"

class USessionSearchResultViewModel;
class USessionSearchSettingViewModel;
class USessionSearchList;

/** 会话搜索面板，负责创建搜索设置视图模型、发起 FindSessions，并把结果转换为列表可绑定的视图模型。 */
UCLASS(MinimalAPI)
class USessionSearchPanel : public UGenericWidget
{
	GENERATED_BODY()

protected:
	GENERICNETWORKFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICNETWORKFRAMEWORK_API virtual void NativeDestruct() override;
#if WITH_EDITOR
	GENERICNETWORKFRAMEWORK_API virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif

protected:
	/** 确保搜索设置视图模型存在，编码查询条件并向会话子系统发起一次列表刷新。 */
	UFUNCTION(BlueprintCallable, Category="Session Search Panel")
	GENERICNETWORKFRAMEWORK_API void RefreshSessionSearchList();

	/** 搜索发起前的蓝图扩展点，同时把开始事件传递给子列表控件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Session Search Panel")
	GENERICNETWORKFRAMEWORK_API void OnFindSessionsStart();

	/** 搜索完成后把底层 SearchResults 包装成视图模型数组，并刷新子列表控件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Session Search Panel")
	GENERICNETWORKFRAMEWORK_API void OnFindSessionsComplete(bool bWasSuccessful);

public:
	/** 允许外部注入搜索设置视图模型；设置成功后立即使用新条件刷新列表。 */
	UFUNCTION(BlueprintCallable, Category="Session Search Panel")
	GENERICNETWORKFRAMEWORK_API void SetSessionSearchSettingsViewModel(USessionSearchSettingViewModel* InViewModel);

protected:
	/** 指定面板默认创建的搜索设置视图模型类型，编辑器校验会确保该类已配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Session Search Panel")
	TSubclassOf<USessionSearchSettingViewModel> SessionSearchSettingsViewModelClass=nullptr;

	/** 当前搜索条件视图模型，刷新列表时从这里取得并编码查询参数。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search Panel")
	TObjectPtr<USessionSearchSettingViewModel> SessionSearchSettingsViewModel=nullptr;

	/** 保存本次搜索生成的结果视图模型，确保列表显示期间对象保持有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search Panel")
	TArray<TObjectPtr<USessionSearchResultViewModel>> SessionSearchResultViewModels;

private:
	/** 绑定蓝图中的搜索结果列表，搜索开始和完成事件都会转发给它。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search Panel", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<USessionSearchList> SessionSearchList;
};
