#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Engine/Engine.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/World.h"
#include "Misc/PackageName.h"
#include "Subsystem/GenericLevelStreamingSubsystem.h"

#include "Handle/LoadLevelStreamingHandle.h"
#include "Handle/SetLevelStreamingVisibilityHandle.h"
#include "Handle/UnLoadLevelStreamingHandle.h"

namespace
{
TSoftObjectPtr<UWorld> MakeTestLevel(const FName& PackageName)
{
	const FString PackageNameString = PackageName.ToString();
	const FString AssetName = FPackageName::GetShortName(PackageNameString);
	return TSoftObjectPtr<UWorld>(FSoftObjectPath(FString::Printf(TEXT("%s.%s"), *PackageNameString, *AssetName)));
}

void ResetGenericLevelStreamingSubsystem(UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem)
{
	if (!GenericLevelStreamingSubsystem)
	{
		return;
	}

	if (UWorld* World = GenericLevelStreamingSubsystem->GetWorld())
	{
		World->GetTimerManager().ClearTimer(GenericLevelStreamingSubsystem->GetNextTickTimerHandleForTests());
	}

	GenericLevelStreamingSubsystem->GetNextTickTimerHandleForTests().Invalidate();
	GenericLevelStreamingSubsystem->GetTargetLevelStreamingHandlesForTests().Reset();
	GenericLevelStreamingSubsystem->GetLevelStreamingHandlesForTests().Reset();
}

struct FScopedTestWorld
{
	UWorld* World = nullptr;

	FScopedTestWorld()
	{
		World = UWorld::CreateWorld(EWorldType::Game, false);
	}

	~FScopedTestWorld()
	{
		if (World)
		{
			ResetGenericLevelStreamingSubsystem(UGenericLevelStreamingSubsystem::Get(World));
			World->DestroyWorld(false);
		}
	}
};

struct FScopedTestStreamingLevel
{
	UWorld* World = nullptr;
	ULevelStreamingDynamic* StreamingLevel = nullptr;

	FScopedTestStreamingLevel(UWorld* InWorld, const FName& PackageName)
		: World(InWorld)
	{
		if (!World)
		{
			return;
		}

		StreamingLevel = NewObject<ULevelStreamingDynamic>(World);
		StreamingLevel->SetWorldAssetByPackageName(PackageName);
		StreamingLevel->PackageNameToLoad = PackageName;
		StreamingLevel->SetShouldBeVisible(false);
		World->AddStreamingLevel(StreamingLevel);
	}

	~FScopedTestStreamingLevel()
	{
		if (World && StreamingLevel)
		{
			World->RemoveStreamingLevel(StreamingLevel);
		}
	}
};
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLevelStreamingHandleOnceFinishBroadcastsCompletedLevelTest, "GenericFramework.GenericWorld.LevelStreaming.HandleOnceFinishBroadcastsCompletedLevel", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FLevelStreamingHandleOnceFinishBroadcastsCompletedLevelTest::RunTest(const FString& Parameters)
{
	UUnLoadLevelStreamingHandle* Handle = NewObject<UUnLoadLevelStreamingHandle>(GetTransientPackage());
	const TSoftObjectPtr<UWorld> ExpectedLevel = TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Test/Maps/L_TestLevel.L_TestLevel")));
	UFunction* OnceFinishFunction = Handle->FindFunction(TEXT("OnOnceFinish"));

	int32 OnceFinishCount = 0;
	int32 FinishCount = 0;
	TSoftObjectPtr<UWorld> BroadcastLevel = nullptr;

	TestNotNull(TEXT("OnOnceFinish UFunction should be available"), OnceFinishFunction);

	Handle->GetHandleOnceFinishEvent().AddLambda([this, Handle, &OnceFinishCount, &BroadcastLevel](ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel)
	{
		++OnceFinishCount;
		BroadcastLevel = InLevel;
		TestTrue(TEXT("Once finish should broadcast the same handle"), InHandle == Handle);
	});

	Handle->GetHandleFinishEvent().AddLambda([this, Handle, &FinishCount](ULevelStreamingHandle* InHandle)
	{
		++FinishCount;
		TestTrue(TEXT("Finish should broadcast the same handle"), InHandle == Handle);
	});

	Handle->Initialize(FUnloadLevelStreamingSetting(ExpectedLevel, false), FOnHandleLevelStreamingOnceFinish(), FOnHandleLevelStreamingFinish());
	Handle->ProcessEvent(OnceFinishFunction, nullptr);

	TestEqual(TEXT("Once finish should fire exactly once"), OnceFinishCount, 1);
	TestEqual(TEXT("Finish should fire exactly once"), FinishCount, 1);
	TestEqual(TEXT("Once finish should broadcast the completed level"), BroadcastLevel.ToString(), ExpectedLevel.ToString());
	TestEqual(TEXT("Level index should reset after finish"), Handle->GetLevelIndex(), 0);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSetLevelVisibilityHiddenUnloadedSkipsLoadHandleTest, "GenericFramework.GenericWorld.LevelStreaming.HiddenUnloadedSkipsLoadHandle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FSetLevelVisibilityHiddenUnloadedSkipsLoadHandleTest::RunTest(const FString& Parameters)
{
	FScopedTestWorld ScopedWorld;
	UWorld* World = ScopedWorld.World;
	UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = World ? UGenericLevelStreamingSubsystem::Get(World) : nullptr;

	TestNotNull(TEXT("A non-partitioned automation world should be available"), World);
	TestNotNull(TEXT("LevelStreaming subsystem should be available"), GenericLevelStreamingSubsystem);

	if (!World || !GenericLevelStreamingSubsystem)
	{
		return false;
	}

	const FName PackageName(TEXT("/Game/Test/Maps/L_LevelStreamingVisibilityHidden"));
	const TSoftObjectPtr<UWorld> TestLevel = MakeTestLevel(PackageName);
	FScopedTestStreamingLevel ScopedStreamingLevel(World, PackageName);

	TestNotNull(TEXT("Transient streaming level should be registered"), ScopedStreamingLevel.StreamingLevel);
	if (!ScopedStreamingLevel.StreamingLevel)
	{
		return false;
	}

	USetLevelStreamingVisibilityHandle* Handle = NewObject<USetLevelStreamingVisibilityHandle>(GenericLevelStreamingSubsystem);
	int32 LoadHandleRegisterCount = 0;
	int32 OnceFinishCount = 0;
	int32 FinishCount = 0;

	Handle->GetHandleOnceFinishEvent().AddLambda([&OnceFinishCount](ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel)
	{
		++OnceFinishCount;
	});

	Handle->GetHandleFinishEvent().AddLambda([&FinishCount](ULevelStreamingHandle* InHandle)
	{
		++FinishCount;
	});

	Handle->Initialize(FSetLevelStreamingVisibilitySetting(TestLevel, false), FOnHandleLevelStreamingOnceFinish(), FOnHandleLevelStreamingFinish());
	Handle->ExecuteHandle(0);

	LoadHandleRegisterCount = GenericLevelStreamingSubsystem->GetTargetLevelStreamingHandlesForTests().Num();
	ResetGenericLevelStreamingSubsystem(GenericLevelStreamingSubsystem);

	TestEqual(TEXT("Hidden unloaded level should not register a load handle"), LoadHandleRegisterCount, 0);
	TestEqual(TEXT("Hidden unloaded level should complete once immediately"), OnceFinishCount, 1);
	TestEqual(TEXT("Hidden unloaded level should finish immediately"), FinishCount, 1);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSetLevelVisibilityVisibleUnloadedRequestsLoadHandleTest, "GenericFramework.GenericWorld.LevelStreaming.VisibleUnloadedRequestsLoadHandle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FSetLevelVisibilityVisibleUnloadedRequestsLoadHandleTest::RunTest(const FString& Parameters)
{
	FScopedTestWorld ScopedWorld;
	UWorld* World = ScopedWorld.World;
	UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = World ? UGenericLevelStreamingSubsystem::Get(World) : nullptr;

	TestNotNull(TEXT("A non-partitioned automation world should be available"), World);
	TestNotNull(TEXT("LevelStreaming subsystem should be available"), GenericLevelStreamingSubsystem);

	if (!World || !GenericLevelStreamingSubsystem)
	{
		return false;
	}

	const FName PackageName(TEXT("/Game/Test/Maps/L_LevelStreamingVisibilityVisible"));
	const TSoftObjectPtr<UWorld> TestLevel = MakeTestLevel(PackageName);
	FScopedTestStreamingLevel ScopedStreamingLevel(World, PackageName);

	TestNotNull(TEXT("Transient streaming level should be registered"), ScopedStreamingLevel.StreamingLevel);
	if (!ScopedStreamingLevel.StreamingLevel)
	{
		return false;
	}

	USetLevelStreamingVisibilityHandle* Handle = NewObject<USetLevelStreamingVisibilityHandle>(GenericLevelStreamingSubsystem);
	int32 LoadHandleRegisterCount = 0;
	int32 OnceFinishCount = 0;
	int32 FinishCount = 0;

	Handle->GetHandleOnceFinishEvent().AddLambda([&OnceFinishCount](ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel)
	{
		++OnceFinishCount;
	});

	Handle->GetHandleFinishEvent().AddLambda([&FinishCount](ULevelStreamingHandle* InHandle)
	{
		++FinishCount;
	});

	Handle->Initialize(FSetLevelStreamingVisibilitySetting(TestLevel, true), FOnHandleLevelStreamingOnceFinish(), FOnHandleLevelStreamingFinish());
	Handle->ExecuteHandle(0);

	LoadHandleRegisterCount = GenericLevelStreamingSubsystem->GetTargetLevelStreamingHandlesForTests().Num();
	ResetGenericLevelStreamingSubsystem(GenericLevelStreamingSubsystem);

	TestEqual(TEXT("Visible unloaded level should register one load handle"), LoadHandleRegisterCount, 1);
	TestEqual(TEXT("Visible unloaded level should not finish synchronously"), OnceFinishCount, 0);
	TestEqual(TEXT("Visible unloaded level should not broadcast finish synchronously"), FinishCount, 0);

	return true;
}

#endif
