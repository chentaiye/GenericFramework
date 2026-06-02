// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_EditorScene.generated.h"

/** 集中暴露编辑器场景蓝图函数库接口，让蓝图通过稳定入口访问编辑器扩展功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_EditorScene : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 读取已选择Actor 集合，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API TArray<AActor*> GetSelectedActors();

	/** 读取已选择组件集合，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API TArray<UActorComponent*> GetSelectedComponents();

	/** 清空编辑器选择集，并刷新关卡编辑器中的选择状态。 */
	static GENERICEDITORFRAMEWORK_API void SelectNone();

	/** 更新编辑器 Actor 选择状态，并同步关卡视口中的当前选择集。 */
	static GENERICEDITORFRAMEWORK_API void SelectActor(AActor* InActor, bool bInSelected);

	/** 更新编辑器 Actor 选择状态，并同步关卡视口中的当前选择集。 */
	static GENERICEDITORFRAMEWORK_API void SelectActors(TArray<AActor*> InActors, bool bInSelected);

	/** 更新编辑器组件选择状态，并同步关卡视口中的当前选择集。 */
	static GENERICEDITORFRAMEWORK_API void SelectComponent(UActorComponent* InComponent, bool bInSelected);

	/** 更新编辑器组件选择状态，并同步关卡视口中的当前选择集。 */
	static GENERICEDITORFRAMEWORK_API void SelectComponents(TArray<UActorComponent*> InComponents, bool bInSelected);

	/** 刷新选择集，同步编辑器缓存、蓝图状态或控件显示。 */
	static GENERICEDITORFRAMEWORK_API void RefreshSelection();
};
