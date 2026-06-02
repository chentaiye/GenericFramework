// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "NetworkType.h"
#include "OnlineSessionSettings.h"
#include "SessionSettingViewModel.generated.h"

/** 面向 MVVM 的会话创建设置视图模型，负责在 UI 字段和底层 FOnlineSessionSettings 之间转接数据。 */
UCLASS(MinimalAPI)
class USessionSettingViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	/** 返回当前视图模型编码后的底层会话设置，供创建会话或详情面板复用。 */
	GENERICNETWORKFRAMEWORK_API const FOnlineSessionSettings& GetSessionSettings() const;

	/** 从外部底层设置回填视图模型字段，使 UI 能展示搜索结果或已有会话配置。 */
	GENERICNETWORKFRAMEWORK_API void SetSessionSettings(const FOnlineSessionSettings& InSettings);

public:
	/** 保存蓝图和 MVVM 可绑定的会话设置字段，实际提交前由结构体编码到底层设置。 */
	UPROPERTY(FieldNotify, EditDefaultsOnly, BlueprintReadWrite, Category="Session Setting View Model")
	FGenericSessionSettings SessionSettings;
};
