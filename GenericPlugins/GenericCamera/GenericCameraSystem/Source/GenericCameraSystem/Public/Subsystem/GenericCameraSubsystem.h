// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CameraPoint/CameraPointBase.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericCameraSubsystem.generated.h"

class ACameraPointBase;

USTRUCT(BlueprintType)
struct GENERICCAMERASYSTEM_API FOnCameraPointRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Camera Point Registered Message")
	TObjectPtr<ACameraPointBase> CameraPoint = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICCAMERASYSTEM_API FOnCameraPointUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Camera Point Unregistered Message")
	TObjectPtr<ACameraPointBase> CameraPoint = nullptr;
};

UCLASS(MinimalAPI)
class UGenericCameraSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static GENERICCAMERASYSTEM_API UGenericCameraSubsystem* Get(const UObject* WorldContextObject);
	static GENERICCAMERASYSTEM_API UGenericCameraSubsystem* Get(const UWorld* World);

	GENERICCAMERASYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICCAMERASYSTEM_API virtual void Deinitialize() override;

protected:
	GENERICCAMERASYSTEM_API virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	virtual void AddCameraPoint(ACameraPointBase* InCameraPoint);
	virtual void RemoveCameraPoint(ACameraPointBase* InCameraPoint);

public:
	GENERICCAMERASYSTEM_API bool CanSwitchToCamera(FGameplayTag InCameraTag) const;
	GENERICCAMERASYSTEM_API ACameraPointBase* GetCameraPoint(FGameplayTag InCameraTag) const;
	GENERICCAMERASYSTEM_API void RefreshAllCameraPoints();

private:
	bool IsCameraPointInWorld(const ACameraPointBase* InCameraPoint) const;
	void RegisterExistingCameraPoints();

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Generic Camera Subsystem")
	TMap<FGameplayTag, ACameraPointBase*> CameraPoints;
};
