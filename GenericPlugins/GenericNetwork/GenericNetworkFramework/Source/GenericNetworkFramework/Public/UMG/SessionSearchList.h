// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericWidget.h"
#include "SessionSearchList.generated.h"

class USessionSettingPanel;
class USessionSearchListItemObject;
class USessionSearchResultViewModel;
class UListView;

/** 会话搜索结果列表控件，负责把搜索面板生成的结果视图模型转换成 ListView 条目并处理选中变化。 */
UCLASS(MinimalAPI)
class USessionSearchList : public UGenericWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	/** 清空旧条目并用新的搜索结果视图模型重建 ListView 项对象。 */
	UFUNCTION(BlueprintCallable, Category="Session Search List")
	GENERICNETWORKFRAMEWORK_API void SetSessionSearchResult(const TArray<USessionSearchResultViewModel*>& InViewModels);

	/** 搜索开始时的蓝图扩展点，列表可在这里切换加载态或清理展示状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Session Search List")
	GENERICNETWORKFRAMEWORK_API void OnFindSessionsStart();

	/** 搜索完成并刷新列表后的蓝图扩展点，列表可在这里恢复交互或展示空结果状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Session Search List")
	GENERICNETWORKFRAMEWORK_API void OnFindSessionsComplete();

protected:
	/** 接收 ListView 选中变化，预留将选中结果同步到会话详情面板的路径。 */
	GENERICNETWORKFRAMEWORK_API virtual void OnItemSelectionChanged(UObject* Item);

private:
	/** 绑定蓝图中的搜索结果 ListView，搜索完成后所有条目都会添加到这里。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search List", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UListView> ListView_SessionSearch;

	// UPROPERTY(BlueprintReadOnly, meta = (BindWidget, BlueprintProtected = true, AllowPrivateAccess = true))
	// TObjectPtr<USessionSettingPanel> SessionSettingPanel;

	/** 持有传给 ListView 的条目对象，避免局部 NewObject 在列表使用期间被回收。 */
	UPROPERTY()
	TArray<TObjectPtr<USessionSearchListItemObject>> SessionSearchListItemObjects;
};
