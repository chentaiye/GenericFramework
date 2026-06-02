// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_EditorWidget.generated.h"

class SLevelViewport;

/** 集中暴露编辑器控件蓝图函数库接口，让蓝图通过稳定入口访问编辑器扩展功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_EditorWidget : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 把编辑器世界坐标投影到视口屏幕坐标，供编辑器 UI 对齐场景对象。 */
	static GENERICEDITORFRAMEWORK_API bool CurrentEditorProjectWorldToScreen(const FVector& WorldPosition, FVector2D& ScreenPosition);

	/** 读取当前编辑器投影数据，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API bool GetCurrentEditorProjectionData(FSceneViewProjectionData& ProjectionData);

	/** 把编辑器世界坐标投影到视口屏幕坐标，供编辑器 UI 对齐场景对象。 */
	static GENERICEDITORFRAMEWORK_API bool EditorProjectWorldToScreen(const FLevelEditorViewportClient* InLevelEditorViewportClient, const FVector& WorldPosition, FVector2D& ScreenPosition);

	/** 读取编辑器投影数据，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API bool GetEditorProjectionData(const FLevelEditorViewportClient* InLevelEditorViewportClient, FSceneViewProjectionData& ProjectionData);

public:
	/** 收集带相机视图的关卡编辑器视口客户端，供投影和覆盖层操作复用。 */
	static GENERICEDITORFRAMEWORK_API TArray<FLevelEditorViewportClient*> GetLevelEditorCameraViewportClients();

	/** 收集当前关卡编辑器中的全部视口客户端，屏蔽编辑器模块查询细节。 */
	static GENERICEDITORFRAMEWORK_API TArray<FLevelEditorViewportClient*> GetLevelEditorViewportClients();

	/** 读取编辑器视口控件，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API TSharedPtr<SLevelViewport> GetEditorViewportWidget(const FLevelEditorViewportClient* InLevelEditorViewportClient);

	/** 把 Slate 控件加入指定编辑器视口覆盖层，用于编辑器内工具界面显示。 */
	static GENERICEDITORFRAMEWORK_API bool AddToEditorViewport(const FLevelEditorViewportClient* InLevelEditorViewportClient, const TSharedRef<SWidget>& InWidget);

	/** 从指定编辑器视口覆盖层移除 Slate 控件，保持工具界面生命周期一致。 */
	static GENERICEDITORFRAMEWORK_API bool RemoveFromEditorViewport(const FLevelEditorViewportClient* InLevelEditorViewportClient, const TSharedRef<SWidget>& InWidget);
};
