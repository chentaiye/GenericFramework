#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "GenericLevelSequenceHandle.h"
#include "GenericLevelSequenceSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericLevelSequenceHandleDefaultStateTest, "GenericFramework.GenericMovieScene.LevelSequence.HandleDefaultState", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericLevelSequenceHandleDefaultStateTest::RunTest(const FString& Parameters)
{
	// 验证空句柄在没有 Player 的情况下会安全失败并保持默认状态。
	UGenericLevelSequenceHandle* Handle = NewObject<UGenericLevelSequenceHandle>(GetTransientPackage());

	TestNotNull(TEXT("Handle should be created"), Handle);
	TestFalse(TEXT("PlayMovieScene should fail without a player"), Handle->PlayMovieScene());
	TestFalse(TEXT("PlayMovieSceneFromStart should fail without a player"), Handle->PlayMovieSceneFromStart());
	TestFalse(TEXT("PlayLoopingMovieScene should fail without a player"), Handle->PlayLoopingMovieScene(2));
	TestFalse(TEXT("PlayReverseMovieScene should fail without a player"), Handle->PlayReverseMovieScene());
	TestFalse(TEXT("PauseMovieScene should fail without a player"), Handle->PauseMovieScene());
	TestFalse(TEXT("StopMovieScene should fail without a player"), Handle->StopMovieScene());
	TestFalse(TEXT("SeekMovieScene should fail without a player"), Handle->SeekMovieScene(FTimecode()));
	TestFalse(TEXT("Handle should not report playing"), Handle->IsPlaying());
	TestFalse(TEXT("Handle should not report looping"), Handle->IsLooping());
	TestFalse(TEXT("Handle should not report paused"), Handle->IsPaused());
	TestFalse(TEXT("Handle should not report reversed"), Handle->IsReversed());
	TestEqual(TEXT("Default play rate should be 1"), Handle->GetPlayRate(), 1.f);
	TestNull(TEXT("LevelSequenceActor should be null by default"), Handle->GetLevelSequenceActor());
	TestNull(TEXT("LevelSequencePlayer should be null by default"), Handle->GetULevelSequencePlayer());
	TestNull(TEXT("LevelSequence should be null by default"), Handle->GetSequence());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericLevelSequenceSubsystemRejectsInvalidSequenceTest, "GenericFramework.GenericMovieScene.LevelSequence.SubsystemRejectsInvalidSequence", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericLevelSequenceSubsystemRejectsInvalidSequenceTest::RunTest(const FString& Parameters)
{
	// 验证子系统拒绝空 LevelSequence，避免创建无效 Player/Actor 组合。
	AddExpectedError(TEXT("ConstructLevelSequenceHandle Failed: Invalid LevelSequence"), EAutomationExpectedErrorFlags::Contains, 1);
	TestNull(TEXT("Subsystem should reject a null level sequence"), UGenericLevelSequenceSubsystem::ConstructLevelSequenceHandle(GetTransientPackage(), nullptr, FMovieSceneSequencePlaybackSettings()));
	return true;
}

#endif
