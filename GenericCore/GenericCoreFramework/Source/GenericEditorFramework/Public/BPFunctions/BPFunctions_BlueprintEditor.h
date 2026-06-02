// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_BlueprintEditor.generated.h"

class FBlueprintEditor;

/** 集中暴露蓝图编辑器实例蓝图函数库接口，让蓝图通过稳定入口访问编辑器扩展功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_BlueprintEditor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 读取蓝图编辑器实例，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API TSharedPtr<FBlueprintEditor> GetBlueprintEditor(const UBlueprint* InBlueprint);
};
