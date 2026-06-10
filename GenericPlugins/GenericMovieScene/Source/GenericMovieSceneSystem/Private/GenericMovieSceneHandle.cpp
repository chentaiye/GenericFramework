// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericMovieSceneHandle.h"

void UGenericMovieSceneHandle::NativeOnCreate()
{
	IStateInterface::NativeOnCreate();
}

void UGenericMovieSceneHandle::NativeOnDestroy()
{
	IStateInterface::NativeOnDestroy();
	CloseMovieScene();
}

void UGenericMovieSceneHandle::OnMovieScenePlay()
{
	IGenericMovieSceneInterface::OnMovieScenePlay();
}

void UGenericMovieSceneHandle::OnMovieScenePlayReverse()
{
	IGenericMovieSceneInterface::OnMovieScenePlayReverse();
}

void UGenericMovieSceneHandle::OnMovieScenePause()
{
	IGenericMovieSceneInterface::OnMovieScenePause();
}

void UGenericMovieSceneHandle::OnMovieSceneStop()
{
	IGenericMovieSceneInterface::OnMovieSceneStop();
}

void UGenericMovieSceneHandle::OnMovieSceneSeek()
{
	IGenericMovieSceneInterface::OnMovieSceneSeek();
}

void UGenericMovieSceneHandle::OnMovieScenePlayFinish()
{
	IGenericMovieSceneInterface::OnMovieScenePlayFinish();
}
