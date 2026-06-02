// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/GameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameState.h"
#include "GameFramework/HUD.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Gameplay.generated.h"

/** 集中暴露Gameplay蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Gameplay : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/* Gameplay */
public:
	/** 读取游戏实例By类型，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API UGameInstance* GetGameInstanceByClass(const UObject* WorldContextObject, const TSubclassOf<UGameInstance> InClass);

	/** 读取游戏模式By类型，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API AGameModeBase* GetGameModeByClass(const UObject* WorldContextObject, const TSubclassOf<AGameModeBase> InClass);

	/** 读取游戏会话By类型，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API AGameSession* GetGameSessionByClass(const UObject* WorldContextObject, const TSubclassOf<AGameSession> InClass);

	/** 读取游戏状态By类型，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API AGameStateBase* GetGameStateByClass(const UObject* WorldContextObject, const TSubclassOf<AGameStateBase> InClass);

public:
	/** 读取玩家控制器By索引，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APlayerController* GetPlayerControllerByIndex(const UObject* WorldContextObject, const TSubclassOf<APlayerController> InClass, int32 InIndex);

	/** 读取本地玩家By索引，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API ULocalPlayer* GetLocalPlayerByIndex(const UObject* WorldContextObject, const TSubclassOf<ULocalPlayer> InClass, int32 InIndex);

	/** 读取玩家状态By索引，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APlayerState* GetPlayerStateByIndex(const UObject* WorldContextObject, const TSubclassOf<APlayerState> InClass, int32 InIndex);

	/** 读取HUDBy索引，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API AHUD* GetHUDByIndex(const UObject* WorldContextObject, const TSubclassOf<AHUD> InClass, int32 InIndex);

	/** 读取PawnBy索引，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APawn* GetPawnByIndex(const UObject* WorldContextObject, const TSubclassOf<APawn> InClass, int32 InIndex);

public:
	/** 按玩家唯一网络 ID 查找玩家控制器，封装世界遍历和类型转换细节。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APlayerController* GetPlayerControllerByUniqueNetID(const UObject* WorldContextObject, const TSubclassOf<APlayerController> InClass, const FUniqueNetIdRepl& InNetID);

	/** 按玩家唯一网络 ID 查找Local玩家，封装世界遍历和类型转换细节。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API ULocalPlayer* GetLocalPlayerByUniqueNetID(const UObject* WorldContextObject, const TSubclassOf<ULocalPlayer> InClass, const FUniqueNetIdRepl& InNetID);

	/** 按玩家唯一网络 ID 查找玩家状态，封装世界遍历和类型转换细节。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APlayerState* GetPlayerStateByUniqueNetID(const UObject* WorldContextObject, const TSubclassOf<APlayerState> InClass, const FUniqueNetIdRepl& InNetID);

	/** 按玩家唯一网络 ID 查找HUD，封装世界遍历和类型转换细节。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API AHUD* GetHUDByUniqueNetID(const UObject* WorldContextObject, const TSubclassOf<AHUD> InClass, const FUniqueNetIdRepl& InNetID);

	/** 按玩家唯一网络 ID 查找Pawn，封装世界遍历和类型转换细节。 */
	UFUNCTION(BlueprintPure, Category="Gameplay", meta=(WorldContext="WorldContextObject", DeterminesOutputType="InClass"))
	static UNREALMISC_API APawn* GetPawnByUniqueNetID(const UObject* WorldContextObject, const TSubclassOf<APawn> InClass, const FUniqueNetIdRepl& InNetID);

public:
	/** 读取玩家ID，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerID (PlayerController)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerID(const APlayerController* InPlayer, int32& Result);

	/** 读取玩家IDBy玩家状态，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerID (PlayerState)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerIDByPlayerState(const APlayerState* InPlayerState, int32& Result);

	/** 读取玩家IDByPawn，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerID (Pawn)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerIDByPawn(const APawn* InPawn, int32& Result);

public:
	/** 从玩家状态、Pawn 或玩家索引解析唯一网络 ID，统一蓝图侧多人会话查询入口。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerUniqueNetID (PlayerController)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerUniqueNetID(const APlayerController* InPlayer, FUniqueNetIdRepl& Result);

	/** 从玩家状态、Pawn 或玩家索引解析唯一网络 ID，统一蓝图侧多人会话查询入口。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerUniqueNetID (PlayerState)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerUniqueNetIDByPlayerState(const APlayerState* InPlayerState, FUniqueNetIdRepl& Result);

	/** 从玩家状态、Pawn 或玩家索引解析唯一网络 ID，统一蓝图侧多人会话查询入口。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerUniqueNetID (Pawn)", Category="Gameplay")
	static UNREALMISC_API bool GetPlayerUniqueNetIDByPawn(const APawn* InPawn, FUniqueNetIdRepl& Result);

	/** 从玩家状态、Pawn 或玩家索引解析唯一网络 ID，统一蓝图侧多人会话查询入口。 */
	UFUNCTION(BlueprintPure, DisplayName="GetPlayerUniqueNetID (PlayerIndex)", Category="Gameplay", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API bool GetPlayerUniqueNetIDByPlayerIndex(const UObject* WorldContextObject, int32 InPlayerIndex, FUniqueNetIdRepl& Result);

	/* Pawn */
public:
	/** 读取是否玩家占有Pawn，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Pawn")
	static UNREALMISC_API bool GetIsPlayerPossessPawn(const APawn* InPawn);

	/** 读取是否AI占有Pawn，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Pawn")
	static UNREALMISC_API bool GetIsAIPossessPawn(const APawn* InPawn);

	/* Actor */
public:
	/** 批量写入全部 Actor 可见性，封装世界遍历和隐藏状态同步。 */
	UFUNCTION(BlueprintCallable, Category="Actor", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API void SetAllActorsVisibility(const UObject* WorldContextObject, TSubclassOf<AActor> InClass, bool bIsHiddenInGame);

	/** 按接口过滤 Actor 后批量写入可见性，减少蓝图侧遍历和类型判断。 */
	UFUNCTION(BlueprintCallable, Category="Actor", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API void SetAllActorsVisibilityWithInterface(const UObject* WorldContextObject, TSubclassOf<UInterface> Interface, bool bIsHiddenInGame);

	/** 按标签和类型过滤 Actor 后批量写入可见性。 */
	UFUNCTION(BlueprintCallable, DisplayName="SetAllActorsVisibilityWithTag(Class)", Category="Actor", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API void SetAllActorsVisibilityWithTag_Class(const UObject* WorldContextObject, TSubclassOf<AActor> InClass, FName InTag, bool bIsHiddenInGame);

	/** 按标签和接口过滤 Actor 后批量写入可见性。 */
	UFUNCTION(BlueprintCallable, DisplayName="SetAllActorsVisibilityWithTag(Interface)", Category="Actor", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API void SetAllActorsVisibilityWithTag_Interface(const UObject* WorldContextObject, TSubclassOf<UInterface> Interface, FName InTag, bool bIsHiddenInGame);

public:
	/** 读取Actor前向命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Actor", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetActorForwardHitResult(const AActor* InActor, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);

	/** 读取Actor右向命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Actor", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetActorRightHitResult(const AActor* InActor, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);

	/** 读取Actor下方命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Actor", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetActorDownHitResult(const AActor* InActor, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);

	/* Component */
public:
	/** 读取组件前向命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Component", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetComponentForwardHitResult(const USceneComponent* InComponent, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);

	/** 读取组件右向命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Component", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetComponentRightHitResult(const USceneComponent* InComponent, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);

	/** 读取组件下方命中结果，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Component", meta=(AdvancedDisplay=2))
	static UNREALMISC_API bool GetComponentDownHitResult(const USceneComponent* InComponent, FHitResult& HitResult, ECollisionChannel TraceChannel = ECC_Camera);
};
