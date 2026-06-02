// Copyright ChenTaiye 2025. All Rights Reserved.


#include "Track/MovieSceneUMGEdTrack.h"

#include "ContentBrowserDelegates.h"
#include "ContentBrowserModule.h"
#include "Framework/Application/SlateApplication.h"
#include "IContentBrowserSingleton.h"
#include "LevelSequence.h"
#include "Misc/EngineVersionComparison.h"
#include "MovieScene.h"
#include "SequencerUtilities.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/UserWidgetBlueprint.h"
#include "Section/MovieSceneUMGEdSection.h"
#include "Styling/SlateIconFinder.h"
#include "Track/MovieSceneUMGTrack.h"
#include "Tracks/MovieSceneSpawnTrack.h"

#define LOCTEXT_NAMESPACE "FMovieSceneExtendModule"

FMovieSceneUMGEdTrack::FMovieSceneUMGEdTrack(TSharedRef<ISequencer> InSequencer)
	: FMovieSceneTrackEditor(InSequencer)
{
}

TSharedRef<ISequencerTrackEditor> FMovieSceneUMGEdTrack::CreateTrackEditor(TSharedRef<ISequencer> InSequencer)
{
	return MakeShareable(new FMovieSceneUMGEdTrack(InSequencer));
}

bool FMovieSceneUMGEdTrack::SupportsType(TSubclassOf<UMovieSceneTrack> TrackClass) const
{
	return UMovieSceneUMGTrack::StaticClass() == TrackClass;
}

TSharedRef<ISequencerSection> FMovieSceneUMGEdTrack::MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding)
{
	return MakeShareable(new FMovieSceneUMGEdSection(SectionObject));
}

void FMovieSceneUMGEdTrack::BuildAddTrackMenu(FMenuBuilder& MenuBuilder)
{
	/* 仅在LevelSequence可使用 */
	if (!IsValid(Cast<ULevelSequence>(GetSequencer()->GetFocusedMovieSceneSequence())))
	{
		return;
	}

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddUMGTrack", "UMG Track"),
		LOCTEXT("AddUMGTrackToolTip", "Adds a master UMG track that can spawn preview widgets in Sequencer."),
		FSlateIconFinder::FindIconForClass(UUserWidget::StaticClass()),
		FUIAction(FExecuteAction::CreateSP(this, &FMovieSceneUMGEdTrack::HandleAddUMGTrack))
	);
}

TSharedPtr<SWidget> FMovieSceneUMGEdTrack::BuildOutlinerEditWidget(const FGuid& ObjectBinding, UMovieSceneTrack* Track, const FBuildEditWidgetParams& Params)
{
	return FSequencerUtilities::MakeAddButton(LOCTEXT("AddUMGWidget", "UMG Widget"), FOnGetContent::CreateSP(this, &FMovieSceneUMGEdTrack::CreateUMGAssetPicker), Params.NodeIsHovered, GetSequencer());
}

void FMovieSceneUMGEdTrack::HandleAddUMGTrack()
{
	UMovieScene* MovieScene = GetFocusedMovieScene();
	if (!MovieScene || MovieScene->IsReadOnly() || MovieScene->FindTrack<UMovieSceneUMGTrack>())
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("AddUMGMasterTrack", "Add UMG Track"));
	MovieScene->Modify();
	MovieScene->AddTrack<UMovieSceneUMGTrack>();
	GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
}

TSharedRef<SWidget> FMovieSceneUMGEdTrack::CreateUMGAssetPicker()
{
	UMovieSceneSequence* Sequence = GetSequencer().IsValid() ? GetSequencer()->GetFocusedMovieSceneSequence() : nullptr;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	FAssetPickerConfig AssetPickerConfig;
	{
		AssetPickerConfig.SelectionMode = ESelectionMode::Single;
		AssetPickerConfig.OnAssetSelected = FOnAssetSelected::CreateRaw(this, &FMovieSceneUMGEdTrack::OnUMGAssetSelected);
		AssetPickerConfig.OnAssetEnterPressed = FOnAssetEnterPressed::CreateRaw(this, &FMovieSceneUMGEdTrack::OnUMGAssetEnterPressed);
		AssetPickerConfig.bAllowNullSelection = false;
		AssetPickerConfig.bAddFilterUI = true;
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::Tile;
		AssetPickerConfig.Filter.bRecursiveClasses = true;
		AssetPickerConfig.Filter.ClassPaths.Add(UUserWidgetBlueprint::StaticClass()->GetClassPathName());
		AssetPickerConfig.SaveSettingsName = TEXT("SequencerAssetPicker");
		if (Sequence)
		{
			AssetPickerConfig.AdditionalReferencingAssets.Add(FAssetData(Sequence));
		}
	}

	/* 创建资产筛选器，选择UMG添加进Sequence */
	return SNew(SBox)
		.WidthOverride(300.0f)
		.HeightOverride(300.f)
		[
			ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
		];
}

void FMovieSceneUMGEdTrack::OnUMGAssetSelected(const FAssetData& InAssetData)
{
	/* 关闭所有菜单 */
	FSlateApplication::Get().DismissAllMenus();
	UUserWidgetBlueprint* SelectedUMGAsset = Cast<UUserWidgetBlueprint>(InAssetData.GetAsset());
	UMovieScene* MovieScene = GetFocusedMovieScene();

	if (!SelectedUMGAsset || !MovieScene)
	{
		return;
	}

	if (MovieScene->IsReadOnly())
	{
		return;
	}

	/* 当UMG Binding存在时，不再重复绑定 */
	if (const FGuid ExistingBinding = FindExistingUMGBinding(SelectedUMGAsset); ExistingBinding.IsValid())
	{
		GetSequencer()->EmptySelection();
		GetSequencer()->SelectObject(ExistingBinding);
		return;
	}

	/* 添加一个UMG Binding */
	AddUMGBinding(SelectedUMGAsset);
}

void FMovieSceneUMGEdTrack::OnUMGAssetEnterPressed(const TArray<FAssetData>& InAssetData)
{
	if (InAssetData.Num() > 0)
	{
		OnUMGAssetSelected(InAssetData[0]);
	}
}

bool FMovieSceneUMGEdTrack::IsUMGBindingExist(UUserWidgetBlueprint* InUserWidgetBP)
{
	return FindExistingUMGBinding(InUserWidgetBP).IsValid();
}

FGuid FMovieSceneUMGEdTrack::FindExistingUMGBinding(UUserWidgetBlueprint* InUserWidgetBP) const
{
	if (!InUserWidgetBP || !GetSequencer().IsValid())
	{
		return FGuid();
	}

	UMovieSceneSequence* Sequence = GetSequencer()->GetFocusedMovieSceneSequence();
	if (!Sequence)
	{
		return FGuid();
	}

#if UE_VERSION_OLDER_THAN(5, 7, 0)
	UMovieScene* MovieScene = Sequence->GetMovieScene();
#else
	const UMovieScene* MovieScene = Sequence->GetMovieScene();
#endif

	if (!MovieScene)
	{
		return FGuid();
	}

	for (const FMovieSceneBinding& MovieSceneBinding : MovieScene->GetBindings())
	{
		if (UUserWidget* BindingWidget = Cast<UUserWidget>(GetSequencer()->FindSpawnedObjectOrTemplate(MovieSceneBinding.GetObjectGuid())))
		{
			if (BindingWidget->GetClass() == InUserWidgetBP->GeneratedClass)
			{
				return MovieSceneBinding.GetObjectGuid();
			}
		}
	}

	return FGuid();
}

void FMovieSceneUMGEdTrack::AddUMGBinding(UUserWidgetBlueprint* InUserWidgetBP)
{
	if (!InUserWidgetBP)
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("AddTrackDescription", "Add UMG Track"));

	/* 从Movie Scene UMG Spawner创建UMG */
	GetFocusedMovieScene()->Modify();
	GetSequencer()->MakeNewSpawnable(*InUserWidgetBP);
	GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
}

#undef LOCTEXT_NAMESPACE
