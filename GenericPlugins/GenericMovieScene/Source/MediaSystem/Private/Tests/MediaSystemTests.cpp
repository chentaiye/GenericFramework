#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "GenericMediaHandle.h"
#include "GenericMediaSubsystem.h"
#include "FileMediaSource.h"
#include "MediaPlayer.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericMediaHandleDefaultStateTest, "GenericFramework.GenericMovieScene.Media.HandleDefaultState", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericMediaHandleDefaultStateTest::RunTest(const FString& Parameters)
{
	// 验证未注册播放器时媒体句柄会安全拒绝播放控制，并保持默认查询状态。
	UGenericMediaHandle* Handle = NewObject<UGenericMediaHandle>(GetTransientPackage());

	TestNotNull(TEXT("Handle should be created"), Handle);
	AddExpectedError(TEXT("PlayMovieScene Failed: Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayMovieScene should fail without initialized media"), Handle->PlayMovieScene());
	AddExpectedError(TEXT("PlayMovieSceneFromStart Failed: Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayMovieSceneFromStart should fail without initialized media"), Handle->PlayMovieSceneFromStart());
	AddExpectedError(TEXT("PlayLoopingMovieScene Failed: Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayLoopingMovieScene should fail without initialized media"), Handle->PlayLoopingMovieScene(2));
	AddExpectedError(TEXT("PlayReverseMovieScene Failed: Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayReverseMovieScene should fail without initialized media"), Handle->PlayReverseMovieScene());
	TestFalse(TEXT("PauseMovieScene should fail without a player"), Handle->PauseMovieScene());
	TestFalse(TEXT("StopMovieScene should fail without a player"), Handle->StopMovieScene());
	TestFalse(TEXT("SeekMovieScene should fail without initialized media"), Handle->SeekMovieScene(FTimecode()));
	TestFalse(TEXT("Handle should not report playing"), Handle->IsPlaying());
	TestFalse(TEXT("Handle should not report looping"), Handle->IsLooping());
	TestFalse(TEXT("Handle should not report paused"), Handle->IsPaused());
	TestFalse(TEXT("Handle should not report reversed"), Handle->IsReversed());
	TestTrue(TEXT("Handle without player should report closed"), Handle->IsClosed());
	TestEqual(TEXT("Default frame rate numerator should be 30"), Handle->GetFrameRate().Numerator, 30);
	TestEqual(TEXT("Default frame rate denominator should be 1"), Handle->GetFrameRate().Denominator, 1);
	TestEqual(TEXT("Default play rate should be 1"), Handle->GetPlayRate(), 1.f);
	TestNull(TEXT("Media player should be null by default"), Handle->GetMediaPlayer());
	TestNull(TEXT("Media source should be null by default"), Handle->GetMediaSource());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericMediaHandleRegisterLifecycleTest, "GenericFramework.GenericMovieScene.Media.RegisterLifecycle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericMediaHandleRegisterLifecycleTest::RunTest(const FString& Parameters)
{
	// 验证 Register 会保留播放器和媒体源，CloseMovieScene 会清理这两个运行期引用。
	UGenericMediaHandle* Handle = NewObject<UGenericMediaHandle>(GetTransientPackage());
	UMediaPlayer* MediaPlayer = NewObject<UMediaPlayer>(GetTransientPackage());
	UFileMediaSource* MediaSource = NewObject<UFileMediaSource>(GetTransientPackage());

	TestNotNull(TEXT("Handle should be created"), Handle);
	TestNotNull(TEXT("MediaPlayer should be created"), MediaPlayer);
	TestNotNull(TEXT("MediaSource should be created"), MediaSource);

	AddExpectedError(TEXT("Failed to validate media source"), EAutomationExpectedErrorFlags::Contains, 1);
	AddExpectedError(TEXT("OpenMovieScene Failed: Unable to open media source"), EAutomationExpectedErrorFlags::Contains, 1);
	Handle->Register(MediaPlayer, MediaSource, FMediaPlayerOptions());

	TestTrue(TEXT("Handle should keep the registered player"), Handle->GetMediaPlayer() == MediaPlayer);
	TestTrue(TEXT("Handle should keep the registered source"), Handle->GetMediaSource() == MediaSource);

	Handle->CloseMovieScene();

	TestNull(TEXT("Media player should be cleared after CloseMovieScene"), Handle->GetMediaPlayer());
	TestNull(TEXT("Media source should be cleared after CloseMovieScene"), Handle->GetMediaSource());
	TestTrue(TEXT("Closed handle should report closed"), Handle->IsClosed());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericMediaSubsystemRejectsInvalidInputTest, "GenericFramework.GenericMovieScene.Media.SubsystemRejectsInvalidInput", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericMediaSubsystemRejectsInvalidInputTest::RunTest(const FString& Parameters)
{
	// 验证子系统拒绝缺失播放器或媒体源的构造请求，避免产生半初始化句柄。
	UFileMediaSource* MediaSource = NewObject<UFileMediaSource>(GetTransientPackage());
	UMediaPlayer* MediaPlayer = NewObject<UMediaPlayer>(GetTransientPackage());

	AddExpectedError(TEXT("ConstructMediaHandle Failed: Invalid MediaPlayer or MediaSource"), EAutomationExpectedErrorFlags::Contains, 2);
	TestNull(TEXT("Subsystem should reject a null media player"), UGenericMediaSubsystem::ConstructMediaHandle(GetTransientPackage(), nullptr, MediaSource, FMediaPlayerOptions()));
	TestNull(TEXT("Subsystem should reject a null media source"), UGenericMediaSubsystem::ConstructMediaHandle(GetTransientPackage(), MediaPlayer, nullptr, FMediaPlayerOptions()));

	return true;
}

#endif
