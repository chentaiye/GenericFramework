#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Type/DesktopType.h"
#include "DesktopDialogAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopDialogCompleted, const FDesktopDialogResult&, Result);

/** 提供桌面对话框异步动作能力。 */
UCLASS(MinimalAPI)
class UDesktopDialogAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICDESKTOPFRAMEWORK_API virtual void Activate() override;

	/** 处理异步打开目录对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopDialogAsyncAction* AsyncOpenDirectoryDialog();

	/** 处理异步打开文件对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopDialogAsyncAction* AsyncOpenFileDialog(const FString& FileType);

	/** 处理异步保存文件对话框。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopDialogAsyncAction* AsyncSaveFileDialog(const FString& FileName, const FString& FileType);

	/** 保存On已完成。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopDialogCompleted OnCompleted;

private:
	/** 定义对话框模式取值。 */
	enum class EDialogMode : uint8
	{
		/** 表示打开目录选项。 */
		OpenDirectory,
		/** 表示打开文件选项。 */
		OpenFile,
		/** 表示保存文件选项。 */
		SaveFile
	};

	/** 保存对话框模式。 */
	EDialogMode DialogMode = EDialogMode::OpenDirectory;
	/** 保存缓存文件名称。 */
	FString CachedFileName;
	/** 保存缓存文件类型。 */
	FString CachedFileType;
};
