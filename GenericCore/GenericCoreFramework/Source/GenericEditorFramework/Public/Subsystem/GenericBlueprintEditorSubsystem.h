// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericEditorSubsystem.h"
#include "GenericBlueprintEditorSubsystem.generated.h"

/** 作为通用蓝图编辑器子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericBlueprintEditorSubsystem : public UGenericEditorSubsystem
{
	GENERATED_BODY()

public:
	static GENERICEDITORFRAMEWORK_API UGenericBlueprintEditorSubsystem* Get();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	/** 按蓝图 CDO 查找已打开的蓝图编辑器，避免重复打开同一资产。 */
	GENERICEDITORFRAMEWORK_API UBlueprint* FindOpenedBlueprintByCDO(UObject* InObject);

private:
	/** 缓存已打开蓝图编辑器集合，供资产关闭和 CDO 查询复用。 */
	TArray<TObjectPtr<UBlueprint>> OpenedBlueprints;

	/** 响应资产编辑器打开事件，缓存蓝图编辑器实例用于后续查询。 */
	void OnAssetEditorOpened(UObject* InObject);

	/** 响应资产编辑器请求关闭回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	void OnAssetEditorRequestClose(UObject* InObject, EAssetEditorCloseReason Reason);
};
