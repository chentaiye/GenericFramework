#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "BinkMediaPlayer.h"
#include "BinkMediaTexture.h"
#include "GenericBinkMediaHandle.h"
#include "GenericBinkMediaSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericBinkMediaHandleDefaultStateTest, "GenericFramework.GenericMovieScene.BinkMedia.HandleDefaultState", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericBinkMediaHandleDefaultStateTest::RunTest(const FString& Parameters)
{
	UGenericBinkMediaHandle* Handle = NewObject<UGenericBinkMediaHandle>(GetTransientPackage());

	TestNotNull(TEXT("Handle should be created"), Handle);
	AddExpectedError(TEXT("PlayMovieScene Failed: Bink Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayMovieScene should fail without initialized media"), Handle->PlayMovieScene());
	AddExpectedError(TEXT("PlayMovieSceneFromStart Failed: Bink Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayMovieSceneFromStart should fail without initialized media"), Handle->PlayMovieSceneFromStart());
	AddExpectedError(TEXT("PlayLoopingMovieScene Failed: Bink Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayLoopingMovieScene should fail without initialized media"), Handle->PlayLoopingMovieScene(2));
	AddExpectedError(TEXT("PlayReverseMovieScene Failed: Bink Media Is Not Ready"), EAutomationExpectedErrorFlags::Contains, 1);
	TestFalse(TEXT("PlayReverseMovieScene should fail without initialized media"), Handle->PlayReverseMovieScene());
	TestFalse(TEXT("PauseMovieScene should fail without a player"), Handle->PauseMovieScene());
	TestFalse(TEXT("StopMovieScene should fail without a player"), Handle->StopMovieScene());
	TestFalse(TEXT("SeekMovieScene should fail without initialized media"), Handle->SeekMovieScene(FTimecode()));
	TestFalse(TEXT("Handle should not report playing"), Handle->IsPlaying());
	TestFalse(TEXT("Handle should not report looping"), Handle->IsLooping());
	TestFalse(TEXT("Handle should not report paused"), Handle->IsPaused());
	TestFalse(TEXT("Handle should not report reversed"), Handle->IsReversed());
	TestFalse(TEXT("Handle should not report ready"), Handle->IsReady());
	TestTrue(TEXT("Handle without player should report closed"), Handle->IsClosed());
	TestEqual(TEXT("Default frame rate numerator should be 30"), Handle->GetFrameRate().Numerator, 30);
	TestEqual(TEXT("Default frame rate denominator should be 1"), Handle->GetFrameRate().Denominator, 1);
	TestEqual(TEXT("Default play rate should be 1"), Handle->GetPlayRate(), 1.f);
	TestEqual(TEXT("Default dimensions should be zero"), Handle->GetDimensions(), FIntPoint::ZeroValue);
	TestNull(TEXT("Bink media player should be null by default"), Handle->GetBinkMediaPlayer());
	TestNull(TEXT("Bink media texture should be null by default"), Handle->GetBinkMediaTexture());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericBinkMediaHandleRegisterLifecycleTest, "GenericFramework.GenericMovieScene.BinkMedia.RegisterLifecycle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericBinkMediaHandleRegisterLifecycleTest::RunTest(const FString& Parameters)
{
	UGenericBinkMediaHandle* Handle = NewObject<UGenericBinkMediaHandle>(GetTransientPackage());
	UBinkMediaPlayer* BinkMediaPlayer = NewObject<UBinkMediaPlayer>(GetTransientPackage());
	UBinkMediaTexture* BinkMediaTexture = NewObject<UBinkMediaTexture>(GetTransientPackage());

	TestNotNull(TEXT("Handle should be created"), Handle);
	TestNotNull(TEXT("BinkMediaPlayer should be created"), BinkMediaPlayer);
	TestNotNull(TEXT("BinkMediaTexture should be created"), BinkMediaTexture);

	BinkMediaPlayer->URL = TEXT("Movies/DoesNotExist.bk2");

	AddExpectedError(TEXT("UBinkMediaPlayer::Open: Failed! BinkPluginOpen failed. Invalid bnk."), EAutomationExpectedErrorFlags::Contains, 2);
	AddExpectedError(TEXT("OpenMovieScene Failed: Unable to open bink media source"), EAutomationExpectedErrorFlags::Contains, 1);
	Handle->Register(BinkMediaPlayer, BinkMediaTexture);

	TestTrue(TEXT("Handle should keep the registered player"), Handle->GetBinkMediaPlayer() == BinkMediaPlayer);
	TestTrue(TEXT("Handle should keep the registered texture"), Handle->GetBinkMediaTexture() == BinkMediaTexture);
	TestTrue(TEXT("Texture should keep the registered player"), BinkMediaTexture->MediaPlayer == BinkMediaPlayer);

	Handle->CloseMovieScene();

	TestNull(TEXT("Bink media player should be cleared after CloseMovieScene"), Handle->GetBinkMediaPlayer());
	TestNull(TEXT("Bink media texture should be cleared after CloseMovieScene"), Handle->GetBinkMediaTexture());
	TestTrue(TEXT("Closed handle should report closed"), Handle->IsClosed());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericBinkMediaSubsystemRejectsInvalidInputTest, "GenericFramework.GenericMovieScene.BinkMedia.SubsystemRejectsInvalidInput", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGenericBinkMediaSubsystemRejectsInvalidInputTest::RunTest(const FString& Parameters)
{
	AddExpectedError(TEXT("ConstructBinkMediaHandle Failed: Invalid BinkMediaPlayer"), EAutomationExpectedErrorFlags::Contains, 1);
	TestNull(TEXT("Subsystem should reject a null bink media player"), UGenericBinkMediaSubsystem::ConstructBinkMediaHandle(GetTransientPackage(), nullptr, nullptr));

	return true;
}

#endif
