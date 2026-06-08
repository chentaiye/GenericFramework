// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericButtonGroup.h"
#include "Base/MenuContainer.h"
#include "Base/MenuWidget.h"
#include "ButtonType.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Group/SingleSelectionButtonGroup.h"
#include "NativeGameplayTags.h"
#include "Styling/SlateBrush.h"
#include "UObject/SoftObjectPtr.h"
#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif
#include "MenuType.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnMenuCollectionRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnMenuCollectionUnRegister);

/** 描述菜单节点在数据表和运行时事件中的业务标识。 */
USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FMenuIDTableRow : public FTableRowBase
{
	GENERATED_BODY()

	static const FString& GetMenuIDRootPath();
	static FString MakeMenuID(const FString& InEditableMenuIDPath);
	static FString GetEditableMenuIDPath(const FString& InMenuID);
	static bool SplitMenuIDPath(const FString& InMenuID, TArray<FString>& OutEditableSegments, FText* OutError = nullptr);

	/** 记录Menu标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu", meta=(Categories="GameplayUI.Button"))
	FGameplayTag MenuTag;

	/** 记录MenuID。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FString MenuID = TEXT("GameplayUI.Button");

	virtual void OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems) override;
	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif

	/** 将有效的菜单标签写回文本标识，保证表格导入后的 ID 与标签一致。 */
	void SyncMenuIDFromTag();

	/** 将文本标识整理成固定根路径下的菜单 ID，供详情面板和表格导入共用。 */
	void NormalizeMenuID();

	/** 获取运行时实际使用的菜单标识，优先使用固定根路径下的文本 MenuID。 */
	FString GetResolvedMenuID() const;
};

/** 保存通用 UI流程中的MenuDescriptionTableRow数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FMenuDescriptionTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** 记录Primary名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FText PrimaryName;

	/** 记录Secondary名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FText SecondaryName;

	/** 保存上一个名称列表列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	TArray<FText> PreviousNames;

	/** 记录Tooltip。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FText Tooltip;

	/** 记录Icon。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FSlateBrush Icon;
};

/** 描述由菜单节点生成按钮控件时需要应用的控件类型和交互状态。 */
USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FMenuEntryTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** 记录Button控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	TSoftClassPtr<UMenuWidget> ButtonWidgetClass;

	/** 记录Visibility。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	ESlateVisibility Visibility = ESlateVisibility::Visible;

	/** 标记按钮业务上是否可用，不直接依赖 UMG Enabled 状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	bool bButtonEnabled = true;

	/** 标记按钮是否允许响应点击、悬停等交互事件。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	bool bInteractionEnabled = true;

	/** 标记按钮是否可以进入选中状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	bool bSelectable = true;

	/** 标记已选中按钮再次触发时是否允许取消选中。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	bool bToggleable = false;

	/** 标记菜单层级构建完成后是否默认选中该按钮。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	bool bDefaultSelected = false;
};

/** 描述由菜单节点生成子层级容器时使用的容器、按钮组和槽位配置。 */
USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FMenuContainerEntryTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** 记录ButtonContainer类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	TSoftClassPtr<UMenuContainer> ButtonContainerClass;

	/** 记录ButtonGroup类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	TSoftClassPtr<UGenericButtonGroup> ButtonGroupClass = USingleSelectionButtonGroup::StaticClass();

	/** 记录ButtonContainerSlot标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu", meta=(Categories="GameplayUI.Slot"))
	FGameplayTag ButtonContainerSlotTag;
};

/** 聚合一个菜单节点需要的标识、展示、按钮和子层级容器配置。 */
USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FMenuTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** 记录MenuID。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuIDTableRow MenuID;

	/** 记录Description。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuDescriptionTableRow Description;

	/** 记录Entry。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuEntryTableRow Entry;

	/** 记录ContainerEntry。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuContainerEntryTableRow ContainerEntry;

	virtual void OnPostDataImport(const UDataTable* InDataTable, const FName InRowName, TArray<FString>& OutCollectedImportProblems) override;
	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif
};
