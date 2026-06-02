// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "CameraType.generated.h"

class APlayerController;
class ACameraPointBase;
class UGenericCameraSwitchMethod;

GENERICCAMERASYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogCamera, Log, All);

GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera);
GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera_OnCameraPointRegister);
GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera_OnCameraPointUnRegister);
GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera_OnCameraSwitchBegin);
GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera_OnCameraSwitchReset);
GENERICCAMERASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Camera_OnCameraSwitchFinish);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCamera);

USTRUCT(BlueprintType)
struct GENERICCAMERASYSTEM_API FOnHandleCameraSwitchMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Camera Switch Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Camera Switch Message")
	TObjectPtr<ACameraPointBase> CameraPoint = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Camera Switch Message")
	TObjectPtr<UGenericCameraSwitchMethod> SwitchMethod = nullptr;
};

/** 决定一次相机切换使用新建方法对象，还是复用外部传入的可编辑方法实例。 */
UENUM(BlueprintType)
enum class ECameraSwitchMethodType : uint8
{
	/** 运行时按类创建独立切换方法，适合默认配置和可重复调用的蓝图节点。 */
	UseMethodClass,

	/** 运行时复制或直接使用已有方法实例，适合携带已配置参数的内联对象。 */
	UseMethodRef
};

/** 描述相机切换方法的通用选择参数，供按标签、按变换等请求复用同一套方法配置。 */
USTRUCT(BlueprintType)
struct FSwitchToCameraParameter
{
	GENERATED_BODY()

public:
	/** 指示相机子系统从类创建切换方法，还是从对象引用取得切换参数。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCamera")
	ECameraSwitchMethodType CameraSwitchMethodType = ECameraSwitchMethodType::UseMethodClass;

	/** 在按类创建模式下使用的切换方法类型，每次请求都会得到独立运行时实例。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera", meta=(EditConditionHides, EditCondition="CameraSwitchMethodType==ECameraSwitchMethodType::UseMethodClass"))
	TSubclassOf<UGenericCameraSwitchMethod> CameraSwitchMethodClass=nullptr;

	/** 在对象引用模式下作为参数模板的切换方法实例，适合在世界设置中直接编辑。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera", meta=(EditConditionHides, EditCondition="CameraSwitchMethodType==ECameraSwitchMethodType::UseMethodRef"))
	TObjectPtr<UGenericCameraSwitchMethod> CameraSwitchMethodRef=nullptr;
};

/** 描述临时相机点的世界变换，相机子系统会据此生成一次性 CameraPoint 后执行切换。 */
USTRUCT(BlueprintType)
struct FSwitchToCameraByTransform : public FSwitchToCameraParameter
{
	GENERATED_BODY()

public:
	/** 临时相机点的世界位置，切换完成后若没有标签会随临时相机点一起清理。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	FVector Location=FVector::ZeroVector;

	/** 临时相机点的世界朝向，用于驱动最终 PlayerCameraManager 视角。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	FRotator Rotation=FRotator::ZeroRotator;
};

/** 描述按 GameplayTag 查找已注册 CameraPoint 的切换请求。 */
USTRUCT(BlueprintType)
struct FSwitchToCameraByTag : public FSwitchToCameraParameter
{
	GENERATED_BODY()

public:
	/** 目标相机点标签，必须已经由当前玩家的相机子系统索引到可用 CameraPoint。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera", meta=(Categories="GameplayCamera"))
	FGameplayTag CameraTag;
};
