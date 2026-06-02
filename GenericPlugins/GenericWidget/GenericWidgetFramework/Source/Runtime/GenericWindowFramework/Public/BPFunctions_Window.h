// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Window.generated.h"

class APlayerController;
class UGenericWindowDescriptor;
class UGenericWindowWidget;
class UUserWidget;

/** 提供窗口蓝图函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Window : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 创建窗口描述。 */
	UFUNCTION(BlueprintCallable, Category="Window", meta=(WorldContext="WorldContextObject", DeterminesOutputType="WindowDescriptorClass"))
	static GENERICWINDOWFRAMEWORK_API UGenericWindowDescriptor* CreateWindowDescriptor(const UObject* WorldContextObject, TSubclassOf<UGenericWindowDescriptor> WindowDescriptorClass);

	/** 创建窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window", meta=(WorldContext="WorldContextObject"))
	static GENERICWINDOWFRAMEWORK_API UGenericWindowWidget* CreateWindow(const UObject* WorldContextObject, APlayerController* InPlayer, UGenericWindowDescriptor* WindowDescriptor, bool& bResult);

	/** 创建窗口带内容类。 */
	UFUNCTION(BlueprintCallable, Category="Window", meta=(WorldContext="WorldContextObject", DeprecatedFunction, DeprecationMessage="UGenericWindowWidget no longer accepts child content. Configure WindowContentClass on the descriptor instead."))
	static GENERICWINDOWFRAMEWORK_API UGenericWindowWidget* CreateWindowWithContentClass(const UObject* WorldContextObject, APlayerController* InPlayer, UGenericWindowDescriptor* WindowDescriptor, TSubclassOf<UUserWidget> ContentClass, bool& bResult);

	/** 执行销毁窗口，并同步当前模块的状态缓存与回调。 */
	UFUNCTION(BlueprintCallable, Category="Window", meta=(WorldContext="WorldContextObject"))
	static GENERICWINDOWFRAMEWORK_API bool DestroyWindow(const UObject* WorldContextObject, UGenericWindowWidget* InWindow);

	/** 置顶窗口目标Front，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window", meta=(WorldContext="WorldContextObject"))
	static GENERICWINDOWFRAMEWORK_API bool BringWindowToFront(const UObject* WorldContextObject, UGenericWindowWidget* InWindow);
};
