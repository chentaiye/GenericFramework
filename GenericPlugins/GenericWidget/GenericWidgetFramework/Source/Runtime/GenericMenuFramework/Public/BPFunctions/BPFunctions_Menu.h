// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Menu.generated.h"

class APlayerController;
class UMenuCollection;
class UMenuSubsystem;

/** 作为运行时菜单集合管理能力的蓝图访问函数控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class UBPFunctions_Menu : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取指定玩家控制器对应的菜单子系统。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Subsystem")
	static GENERICMENUFRAMEWORK_API UMenuSubsystem* GetMenuSubsystem(APlayerController* PlayerController);

	/** 注册已存在的菜单集合，并可立即构建菜单 UI。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API bool RegisterMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection, bool bBuildMenu = true);

	/** 创建指定类型的菜单集合并注册到玩家菜单子系统。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Menu|Menu", meta=(DeterminesOutputType="InMenuCollectionClass"))
	static GENERICMENUFRAMEWORK_API UMenuCollection* RegisterMenuCollectionByClass(APlayerController* PlayerController, TSubclassOf<UMenuCollection> InMenuCollectionClass, bool bBuildMenu = true);

	/** 注销指定菜单集合，并可清理由其生成的菜单 UI。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API bool UnregisterMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection, bool bClearMenu = true);

	/** 注销玩家菜单子系统中的全部菜单集合。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API void ClearMenuCollections(APlayerController* PlayerController, bool bClearMenu = true);

	/** 检查指定菜单集合是否已经注册到玩家菜单子系统。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API bool HasMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection);

	/** 按集合名称获取玩家菜单子系统中的菜单集合。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API UMenuCollection* GetMenuCollection(APlayerController* PlayerController, FName InCollectionName);

	/** 按集合名称获取玩家菜单子系统中的菜单集合，保留给蓝图表达更明确的调用名。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API UMenuCollection* GetMenuCollectionByName(APlayerController* PlayerController, FName InCollectionName);

	/** 检查指定集合名称是否存在已注册菜单集合。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API bool HasMenuCollectionByName(APlayerController* PlayerController, FName InCollectionName);

	/** 获取玩家菜单子系统中全部仍然有效的菜单集合。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Menu|Menu")
	static GENERICMENUFRAMEWORK_API TArray<UMenuCollection*> GetAllMenuCollections(APlayerController* PlayerController);
};
