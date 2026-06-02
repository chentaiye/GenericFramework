#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Section/MovieSceneUMGSection.h"
#include "Track/MovieSceneUMGTrack.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMovieSceneUMGTrackSectionManagementTest, "GenericFramework.GenericMovieScene.UMGTrack.SectionManagement", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FMovieSceneUMGTrackSectionManagementTest::RunTest(const FString& Parameters)
{
	UMovieSceneUMGTrack* Track = NewObject<UMovieSceneUMGTrack>(GetTransientPackage());
	UMovieSceneSection* Section = Track ? Track->CreateNewSection() : nullptr;

	TestNotNull(TEXT("Track should be created"), Track);
	TestNotNull(TEXT("Section should be created"), Section);

	if (!Track || !Section)
	{
		return false;
	}

	Track->AddSection(*Section);
	Track->AddSection(*Section);

	TestEqual(TEXT("Adding the same section twice should not duplicate it"), Track->GetAllSections().Num(), 1);

	Track->RemoveSectionAt(5);
	TestEqual(TEXT("Removing an invalid section index should be ignored"), Track->GetAllSections().Num(), 1);

	Track->RemoveSectionAt(0);
	TestTrue(TEXT("Track should be empty after removing the only section"), Track->IsEmpty());

	return true;
}

#endif
