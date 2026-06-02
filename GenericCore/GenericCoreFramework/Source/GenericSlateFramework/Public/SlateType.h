// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Slate/SlateBrushAsset.h"
#include "Slate/SlateTextureAtlasInterface.h"
#include "Materials/MaterialInterface.h"
#include "Engine/Texture2D.h"
#include "Engine/Texture2DDynamic.h"
#include "NativeGameplayTags.h"
#include "SlateType.generated.h"

GENERICSLATEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogSlate, Log, All);

class ISlateTextureAtlasInterface;
class USlateBrushAsset;

/** 定义E图片画刷Resource枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EImageBrushResource :uint8
{
	/** 表示Slate画刷。 */
	SlateBrush,

	/** 表示Slate画刷资产。 */
	SlateBrushAsset,

	/** 表示Slate纹理图集接口。 */
	SlateTextureAtlasInterface,

	/** 表示材质接口。 */
	MaterialInterface,

	/** 表示软引用材质接口。 */
	SoftMaterialInterface,

	/** 表示Texture2D。 */
	Texture2D,

	/** 表示软引用Texture2D。 */
	SoftTexture2D,

	/** 表示Texture2DDynamic。 */
	Texture2DDynamic,

	/** 表示资源对象。 */
	ResourceObject
};

/** 汇总图片画刷包装数据，便于 Slate、UMG 或蓝图在同一结构中传递配置。 */
USTRUCT(BlueprintType)
struct GENERICSLATEFRAMEWORK_API FImageBrush
{
	GENERATED_BODY()

public:
	FImageBrush();

	/** 从指定资源构造图片画刷包装，并记录资源来源类型。 */
	FImageBrush(const FSlateBrush& InSlateBrush);

	/** 从指定资源构造图片画刷包装，并记录资源来源类型。 */
	FImageBrush(USlateBrushAsset* InSlateBrushAsset);

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(TScriptInterface<ISlateTextureAtlasInterface> InSlateTextureAtlasInterface, bool InMatchSize = false, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(UMaterialInterface* InMaterialInterface, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(const TSoftObjectPtr<UMaterialInterface>& InSoftMaterialInterface, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(UTexture2D* InTexture2D, bool InMatchSize = false, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(const TSoftObjectPtr<UTexture2D>& InSoftTexture2D, bool InMatchSize = false, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	FImageBrush(UTexture2DDynamic* InTexture2DDynamic, bool InMatchSize = false, FVector2D InSize = FVector2D(32.f, 32.f));

	/** 从指定资源构造图片画刷包装，并记录资源来源类型。 */
	FImageBrush(UObject* InResourceObject);

public:
	/** 记录图片画刷当前使用的资源来源，驱动编辑器条件显示和解析分支。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush")
	EImageBrushResource ImageBrushResource = EImageBrushResource::SlateBrush;

	/** 保存原生 Slate 画刷数据，供无需资源转换的路径直接使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SlateBrush"))
	FSlateBrush SlateBrush;

	/** 保存 Slate 画刷资产引用，解析时读取其内部画刷配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SlateBrushAsset"))
	USlateBrushAsset* SlateBrushAsset = nullptr;

	/** 保存 Slate 纹理图集接口，支持从图集区域创建图片画刷。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SlateTextureAtlasInterface"))
	TScriptInterface<ISlateTextureAtlasInterface> SlateTextureAtlasInterface = nullptr;

	/** 保存材质接口引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::MaterialInterface"))
	UMaterialInterface* MaterialInterface = nullptr;

	/** 保存软引用材质接口引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SoftMaterialInterface"))
	TSoftObjectPtr<UMaterialInterface> SoftMaterialInterface = nullptr;

	/** 保存 Texture2D 资源引用，供画刷解析时生成 Slate 资源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::Texture2D"))
	UTexture2D* Texture2D = nullptr;

	/** 保存软引用 Texture2D，解析画刷时按需加载实际资源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SoftTexture2D"))
	TSoftObjectPtr<UTexture2D> SoftTexture2D = nullptr;

	/** 保存动态 Texture2D 资源引用，供运行时画刷解析使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::Texture2DDynamic"))
	UTexture2DDynamic* Texture2DDynamic = nullptr;

	/** 保存资源对象引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::ResourceObject"))
	UObject* ResourceObject = nullptr;

	/** 记录匹配尺寸，用于在生命周期、同步或输入流程中选择后续路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush", meta=(EditConditionHides, EditCondition="ImageBrushResource == EImageBrushResource::SlateTextureAtlasInterface || ImageBrushResource == EImageBrushResource::Texture2D || ImageBrushResource == EImageBrushResource::SoftTexture2D || ImageBrushResource == EImageBrushResource::Texture2DDynamic"))
	bool MatchSize = false;

	/** 保存画刷目标尺寸，供资源无法自动匹配尺寸时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Image Brush")
	FVector2D Size = FVector2D(32.f);
};

/** 定义E边框画刷Resource枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EBorderBrushResource : uint8
{
	/** 表示Slate画刷。 */
	SlateBrush,

	/** 表示Slate画刷资产。 */
	SlateBrushAsset,

	/** 表示材质接口。 */
	MaterialInterface,

	/** 表示Texture2D。 */
	Texture2D
};

/** 汇总边框画刷包装数据，便于 Slate、UMG 或蓝图在同一结构中传递配置。 */
USTRUCT(BlueprintType)
struct GENERICSLATEFRAMEWORK_API FBorderBrush
{
	GENERATED_BODY()

public:
	FBorderBrush();

	/** 从指定资源构造边框画刷包装，并记录资源来源类型。 */
	FBorderBrush(const FSlateBrush& InSlateBrush);

	/** 从指定资源构造边框画刷包装，并记录资源来源类型。 */
	FBorderBrush(USlateBrushAsset* InSlateBrushAsset);

	/** 从指定资源构造边框画刷包装，并记录资源来源类型。 */
	FBorderBrush(UMaterialInterface* InMaterialInterface);

	/** 从指定资源构造边框画刷包装，并记录资源来源类型。 */
	FBorderBrush(UTexture2D* InTexture2D);

public:
	/** 记录边框画刷当前使用的资源来源，驱动编辑器条件显示和解析分支。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Border Brush")
	EBorderBrushResource BoderBrushResource = EBorderBrushResource::SlateBrush;

	/** 保存原生 Slate 画刷数据，供无需资源转换的路径直接使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Border Brush", meta=(EditConditionHides, EditCondition="BoderBrushResource == EBorderBrushResource::SlateBrush"))
	FSlateBrush SlateBrush;

	/** 保存 Slate 画刷资产引用，解析时读取其内部画刷配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Border Brush", meta=(EditConditionHides, EditCondition="BoderBrushResource == EBorderBrushResource::SlateBrushAsset"))
	USlateBrushAsset* SlateBrushAsset = nullptr;

	/** 保存材质接口引用，供资源解析、资产创建或控件同步使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Border Brush", meta=(EditConditionHides, EditCondition="BoderBrushResource == EBorderBrushResource::MaterialInterface"))
	UMaterialInterface* MaterialInterface = nullptr;

	/** 保存 Texture2D 资源引用，供画刷解析时生成 Slate 资源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Border Brush", meta=(EditConditionHides, EditCondition="BoderBrushResource == EBorderBrushResource::Texture2D"))
	UTexture2D* Texture2D = nullptr;
};
