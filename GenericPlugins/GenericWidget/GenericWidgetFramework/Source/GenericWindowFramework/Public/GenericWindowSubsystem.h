// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "GenericWindowSubsystem.generated.h"

class APlayerController;
class UGenericWindowDescriptor;
class UGenericWindowWidget;

/** 调度通用窗口子系统运行。 */
UCLASS(MinimalAPI)
class UGenericWindowSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICWINDOWFRAMEWORK_API UGenericWindowSubsystem* Get(const UObject* WorldContextObject);

	GENERICWINDOWFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	GENERICWINDOWFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWINDOWFRAMEWORK_API virtual void Deinitialize() override;

	/** 创建窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowWidget* CreateWindow(APlayerController* InPlayer, UGenericWindowDescriptor* InDescriptor, bool& bResult);

	/** 注册窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool RegisterWindow(UGenericWindowWidget* InWindow);

	/** 取消注册窗口。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool UnregisterWindow(UGenericWindowWidget* InWindow);

	/** 关闭全部Windows。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void CloseAllWindows();

	/** 置顶窗口目标Front，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API bool BringWindowToFront(UGenericWindowWidget* InWindow);

	/** 分配AllocateZOrder，确保运行时对象获得稳定标识或层级。 */
	GENERICWINDOWFRAMEWORK_API int32 AllocateZOrder();

protected:
	/** 持有RegisteredWindows实例，供通用 UI运行时复用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	TArray<TObjectPtr<UGenericWindowWidget>> RegisteredWindows;

private:
	/** 记录下一个ZOrder。 */
	int32 NextZOrder = 100;
};
