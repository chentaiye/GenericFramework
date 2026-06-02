// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPIUtilities.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/PackageName.h"
#include "NativeAPILog.h"
#include "Type/DebugType.h"

#define NATIVE_API_ENTITY_CLASS_FIELD TEXT("EntityClass")
#define NATIVE_API_WORLD_PATH_FIELD TEXT("WorldPath")
#define NATIVE_API_ENTITY_PATH_FIELD TEXT("EntityPath")
#define NATIVE_API_ENTITY_FIELD TEXT("Entity")
#define NATIVE_API_PREFIX TEXT("API_")

bool FNativeAPIUtilities::IsNativeAPIJson(const TSharedPtr<FJsonObject>& Json)
{
	if (Json.IsValid())
	{
		return Json->HasTypedField<EJson::String>(NATIVE_API_ENTITY_CLASS_FIELD);
	}

	return false;
}

bool FNativeAPIUtilities::IsNativeAPIFunctionName(const FName& InName)
{
	return InName.ToString().StartsWith(NATIVE_API_PREFIX);
}

bool FNativeAPIUtilities::ConvertNativeAPIJsonToPayload(const TSharedPtr<FJsonObject>& InJson, FNativeAPIPayload& OutPayload)
{
	check(InJson.IsValid())

	if (!IsNativeAPIJson(InJson))
	{
		return false;
	}

	/** 先解析 NativeAPI Payload 的实体类型；后续任务分发必须依赖确定的 ClassType。 */
	{
		FString EntityClass;
		if (!InJson->TryGetStringField(NATIVE_API_ENTITY_CLASS_FIELD, EntityClass) || EntityClass.IsEmpty())
		{
			return false;
		}

		FSoftClassPath ClassPath;

		/** 非 Shipping 环境下兼容短类名输入，把蓝图生成类名转换为完整资产路径。 */
		if (FPackageName::IsShortPackageName(EntityClass))
		{
#if !UE_BUILD_SHIPPING
			FTopLevelAssetPath ClassAsset;
			/** 短类名存在跨插件重名风险，例如 `/A/BP_Test.BP_Test_C` 与 `/B/BP_Test.BP_Test_C` 同名时，TryConvertShortTypeNameToPathName 只能按挂载顺序返回第一个匹配结果。 */
			ClassAsset = UClass::TryConvertShortTypeNameToPathName<UStruct>(EntityClass, ELogVerbosity::Warning, TEXT("NativeAPIImpl"));

			GenericLOG(LogNativeAPI, Warning, TEXT("在处理 EntityClass 时, 检测到使用了短包名. 请修改为使用完整的类包名进行访问!"))

			ClassPath.SetPath(ClassAsset);
#endif
		}
		else
		{
			ClassPath.SetPath(EntityClass);
		}

		if (!ClassPath.IsAsset())
		{
			GenericLOG(LogNativeAPI, Error, TEXT("EntityClass 无法确定执行对象的类型!"));
			return false;
		}

		OutPayload.EntityClassPath = ClassPath;

		/** Entity 字段缺省时使用类型资产名，保证任务仍有稳定的执行对象标识。 */
		FString Entity;
		InJson->TryGetStringField(NATIVE_API_ENTITY_FIELD, Entity);
		OutPayload.Entity = Entity.IsEmpty() ? ClassPath.GetAssetFName() : FName(Entity);
	}

	/** 解析所有 `API_` 前缀任务；没有可执行任务时该 Payload 不具备调度意义。 */
	{
		TArray<FNativeAPITask> APITaskList;
		for (auto It = InJson->Values.CreateConstIterator(); It; ++It)
		{
			FString Key = It.Key();
			TSharedPtr<FJsonValue> Value = It.Value();

			if (IsNativeAPIFunctionName(*Key))
			{
				FName APIName = FName(Key);
				TSharedPtr<FJsonObject>* JsonObject;
				if (Value->TryGetObject(JsonObject) && JsonObject->IsValid())
				{
					FNativeAPITask NewTask;
					NewTask.FuncName = APIName;
					NewTask.ParamJson = *JsonObject;
					APITaskList.Add(NewTask);
				}
				else
				{
					/** `API_` 字段必须是对象，非对象值无法转换为函数参数表。 */
					GenericLOG(LogNativeAPI, Error, TEXT(" 'API_' 字段必须是  JsonObject 对象. "))
				}
			}
		}

		if (APITaskList.IsEmpty())
		{
			GenericLOG(LogNativeAPI, Error, TEXT("没有分析出任何有效的 NativeAPI 任务!"))
			return false;
		}

		OutPayload.TaskList = APITaskList;
	}

	/** EntityPath 可选；存在时必须指向子对象路径，用于定位具体实例而不是只按类型执行。 */
	FString EntityPath;
	{
		if (InJson->TryGetStringField(NATIVE_API_ENTITY_PATH_FIELD, EntityPath) && !EntityPath.IsEmpty())
		{
			FSoftObjectPath SoftPath(EntityPath);

			if (!SoftPath.IsSubobject())
			{
				GenericLOG(LogNativeAPI, Warning, TEXT("invalid entity path : %s, entity path subobjectstring is can not empty"), *EntityPath);
				return false;
			}

#if WITH_EDITOR
			/** PIE 下把编辑器对象路径修正到当前 Play World，避免请求落到编辑器原始世界。 */
			SoftPath.FixupForPIE();
#endif

			/** 子对象路径的顶级资源路径就是实体所在的 UWorld 路径。 */
			OutPayload.WorldPath = SoftPath.GetWithoutSubPath();
			OutPayload.EntityObjectPath = SoftPath;

			/** 校验 EntityClass 与 EntityPath 是否共同指向可执行实体。 */
			if (!OutPayload.IsValidEntityPath())
			{
				GenericLOG(LogNativeAPI, Error, TEXT("EntityClass 存在字段, 但无法处理这个可执行对象路径!"));
				return false;
			}
		}
	}

	/** WorldPath 可选；存在时必须与 EntityPath 推导出的世界保持一致。 */
	FString WorldPath;
	{
		if (InJson->TryGetStringField(NATIVE_API_WORLD_PATH_FIELD, WorldPath) && !WorldPath.IsEmpty())
		{
			FSoftObjectPath SoftPath(WorldPath);

			if (SoftPath.IsAsset())
			{
				if (!OutPayload.GetWorldPath().IsValid())
				{
					OutPayload.WorldPath = SoftPath;
				}
				else if (OutPayload.GetWorldPath() != WorldPath)
				{
					GenericLOG(LogNativeAPI, Error, TEXT("EntityPath 和 WorldPath 所在世界路径不一致!"))
					return false;
				}
			}
		}
	}

	return true;
}

#undef NATIVE_API_ENTITY_CLASS_FIELD
#undef NATIVE_API_ENTITY_PATH_FIELD
#undef NATIVE_API_ENTITY_FIELD
#undef NATIVE_API_PREFIX
