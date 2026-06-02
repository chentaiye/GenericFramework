// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "GenericAssetDefinition.generated.h"

/** 描述通用资产定义在编辑器资产系统中的创建、分类和展示信息。 */
UCLASS(Abstract, MinimalAPI)
class UGenericAssetDefinition : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:
	/** 初始化通用资产定义默认展示信息，供资产工具菜单读取。 */
	UGenericAssetDefinition(const FObjectInitializer& ObjectInitializer);
	GENERICEDITORFRAMEWORK_API virtual FText GetAssetDisplayName() const override;
	GENERICEDITORFRAMEWORK_API virtual FText GetAssetDescription(const FAssetData& AssetData) const override;
	GENERICEDITORFRAMEWORK_API virtual FLinearColor GetAssetColor() const override;
	GENERICEDITORFRAMEWORK_API virtual TSoftClassPtr<UObject> GetAssetClass() const override;
	GENERICEDITORFRAMEWORK_API virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;
	GENERICEDITORFRAMEWORK_API virtual FAssetOpenSupport GetAssetOpenSupport(const FAssetOpenSupportArgs& OpenSupportArgs) const override;
	GENERICEDITORFRAMEWORK_API virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& OpenArgs) const override;

protected:
	/** 保存资产Display名称，供当前对象后续同步逻辑读取。 */
	FText AssetDisplayName;

	/** 保存资产Description，供当前对象后续同步逻辑读取。 */
	FText AssetDescription;

	/** 保存资产颜色显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	FLinearColor AssetColor;

	/** 保存资产类型引用，供资源解析、资产创建或控件同步使用。 */
	TSoftClassPtr<UObject> AssetClass;

	/** 保存资产MainCategory，供当前对象后续同步逻辑读取。 */
	FText AssetMainCategory;

	/** 保存资产SubCategory，供当前对象后续同步逻辑读取。 */
	FText AssetSubCategory;
};
