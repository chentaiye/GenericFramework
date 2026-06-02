#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "UObject/Object.h"
#include "GenericPropertyVisualData.generated.h"

class UGenericProperty;

/** 保存属性视觉匹配规则，供面板按类型、路径、元数据或标签选择专用控件。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable, Transient)
class UGenericPropertyVisualData : public UObject
{
	GENERATED_BODY()

public:
	/** 参与控件解析的视觉规则列表，按规则优先级选择最佳匹配。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TArray<FGenericPropertyVisualRule> Rules;

	/** 追加一条运行时视觉规则。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RegisterRule(const FGenericPropertyVisualRule& InRule);

	/** 清空所有视觉规则，使后续解析回退到默认映射。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void ClearRules();

	/** 根据属性节点状态查找匹配的用户控件类。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TSoftClassPtr<class UUserWidget> ResolveWidgetClass(const UGenericProperty* InViewModel) const;
};
