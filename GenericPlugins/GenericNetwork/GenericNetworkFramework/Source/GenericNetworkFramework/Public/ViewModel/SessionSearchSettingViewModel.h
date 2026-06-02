// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "NetworkType.h"
#include "OnlineSessionSettings.h"
#include "SessionSearchSettingViewModel.generated.h"

class USessionSearchResultViewModel;

/** 面向 MVVM 的会话搜索设置视图模型，保存 UI 查询条件并暴露底层搜索对象给搜索面板。 */
UCLASS(MinimalAPI)
class USessionSearchSettingViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	/** 返回当前搜索对象，搜索面板会把它提交给会话子系统并在回调中读取结果。 */
	GENERICNETWORKFRAMEWORK_API TSharedRef<FOnlineSessionSearch> GetSessionSearchSettings() const;

	/** 替换搜索对象并同步查询字段，允许外部搜索流程接管面板当前条件。 */
	GENERICNETWORKFRAMEWORK_API void SetSessionSearchSettings(const TSharedRef<FOnlineSessionSearch>& InSessionSettings);

public:
	/** 保存蓝图和 MVVM 可绑定的查询条件，刷新列表前会编码为 FOnlineSessionSearch。 */
	UPROPERTY(FieldNotify, EditDefaultsOnly, BlueprintReadOnly, Category="Session Search Setting View Model")
	FGenericSessionSearchSettings SessionSearchSettings;
};
