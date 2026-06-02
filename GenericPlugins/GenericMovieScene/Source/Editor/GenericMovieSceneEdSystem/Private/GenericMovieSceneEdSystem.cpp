#include "GenericMovieSceneEdSystem.h"

#include "ILevelSequenceModule.h"
#include "ISequencerModule.h"
#include "Track/MovieSceneUMGEdTrack.h"
#include "Spawner/MovieSceneUMGEdSpawner.h"

#define LOCTEXT_NAMESPACE "FGenericMovieSceneEdSystemModule"

void FGenericMovieSceneEdSystemModule::StartupModule()
{
	ILevelSequenceModule& LevelSequenceModule = FModuleManager::LoadModuleChecked<ILevelSequenceModule>("LevelSequence");
	EditorUMGSpawnerDelegateHandle = LevelSequenceModule.RegisterObjectSpawner(FOnCreateMovieSceneObjectSpawner::CreateStatic(&FMovieSceneUMGEdSpawner::CreateObjectSpawner));
	ISequencerModule& SequencerModule = FModuleManager::Get().LoadModuleChecked<ISequencerModule>("Sequencer");
	UMGTrackCreateEditorHandle = SequencerModule.RegisterTrackEditor(FOnCreateTrackEditor::CreateStatic(&FMovieSceneUMGEdTrack::CreateTrackEditor));
}

void FGenericMovieSceneEdSystemModule::ShutdownModule()
{
	if (UMGTrackCreateEditorHandle.IsValid())
	{
		if (ISequencerModule* SequencerModule = FModuleManager::GetModulePtr<ISequencerModule>("Sequencer"))
		{
			SequencerModule->UnRegisterTrackEditor(UMGTrackCreateEditorHandle);
		}
		UMGTrackCreateEditorHandle.Reset();
	}

	if (EditorUMGSpawnerDelegateHandle.IsValid())
	{
		if (ILevelSequenceModule* LevelSequenceModule = FModuleManager::GetModulePtr<ILevelSequenceModule>("LevelSequence"))
		{
			LevelSequenceModule->UnregisterObjectSpawner(EditorUMGSpawnerDelegateHandle);
		}
		EditorUMGSpawnerDelegateHandle.Reset();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericMovieSceneEdSystemModule, GenericMovieSceneEdSystem)
