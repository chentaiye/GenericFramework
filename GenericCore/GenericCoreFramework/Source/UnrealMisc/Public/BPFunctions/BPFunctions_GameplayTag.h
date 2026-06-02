// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_GameplayTag.generated.h"

/** 集中暴露Gameplay标签蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_GameplayTag : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 读取Gameplay标签Children，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag")
	static UNREALMISC_API FGameplayTagContainer GetGameplayTagChildren(FGameplayTag InTag, bool bIsContainOriginal = false);

	/** 读取DirectGameplay标签Children，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag")
	static UNREALMISC_API FGameplayTagContainer GetDirectGameplayTagChildren(FGameplayTag InTag, bool bIsContainOriginal = false);

	/** 读取Gameplay标签Parents，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag")
	static UNREALMISC_API FGameplayTagContainer GetGameplayTagParents(FGameplayTag InTag, bool bIsContainOriginal = false);

	/** 读取DirectGameplay标签Parent，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag")
	static UNREALMISC_API FGameplayTag GetDirectGameplayTagParent(FGameplayTag InTag);

public:
	/** 转换GameplayTagTo字符串，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag", meta=(DisplayName="To String(FGameplayTag)", CompactNodeTitle="->", BlueprintAutocast))
	static UNREALMISC_API FString Conv_GameplayTagToString(FGameplayTag InTag);

	/** 转换字符串ToGameplayTag，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag", meta=(DisplayName="To GameplayTag(String)", CompactNodeTitle="->", BlueprintAutocast))
	static UNREALMISC_API FGameplayTag Conv_StringToGameplayTag(const FString& TagName);

	/** 转换GameplayTagTo名称，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag", meta=(DisplayName="To Name(FGameplayTag)", CompactNodeTitle="->", BlueprintAutocast))
	static UNREALMISC_API FName Conv_GameplayTagToName(FGameplayTag InTag);

	/** 转换名称ToGameplayTag，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
	UFUNCTION(BlueprintPure, Category="GameplayTag", meta=(DisplayName="To GameplayTag(Name)", CompactNodeTitle="->", BlueprintAutocast))
	static UNREALMISC_API FGameplayTag Conv_NameToGameplayTag(FName TagName);
};
