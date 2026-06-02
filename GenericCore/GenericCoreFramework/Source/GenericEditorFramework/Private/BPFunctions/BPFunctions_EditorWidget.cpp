// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_EditorWidget.h"

#include "ILevelEditor.h"
#include "LevelEditorViewport.h"
#include "SceneView.h"
#include "SceneViewExtension.h"
#include "SceneViewExtensionContext.h"
#include "SLevelViewport.h"

bool UBPFunctions_EditorWidget::CurrentEditorProjectWorldToScreen(const FVector& WorldPosition, FVector2D& ScreenPosition)
{
	return EditorProjectWorldToScreen(GCurrentLevelEditingViewportClient, WorldPosition, ScreenPosition);
}

bool UBPFunctions_EditorWidget::GetCurrentEditorProjectionData(FSceneViewProjectionData& ProjectionData)
{
	return GetEditorProjectionData(GCurrentLevelEditingViewportClient, ProjectionData);
}

bool UBPFunctions_EditorWidget::EditorProjectWorldToScreen(const FLevelEditorViewportClient* InLevelEditorViewportClient, const FVector& WorldPosition, FVector2D& ScreenPosition)
{
	FSceneViewProjectionData ProjectionData;
	if (GetEditorProjectionData(InLevelEditorViewportClient, ProjectionData))
	{
		FMatrix const ViewProjectionMatrix = ProjectionData.ComputeViewProjectionMatrix();
		return FSceneView::ProjectWorldToScreen(WorldPosition, ProjectionData.GetConstrainedViewRect(), ViewProjectionMatrix, ScreenPosition);
	}
	return false;
}

bool UBPFunctions_EditorWidget::GetEditorProjectionData(const FLevelEditorViewportClient* InLevelEditorViewportClient, FSceneViewProjectionData& ProjectionData)
{
	if (InLevelEditorViewportClient)
	{
		FViewport* Viewport = InLevelEditorViewportClient->Viewport;
		if (!Viewport)
		{
			return false;
		}

		if ((Viewport->GetSizeXY().X == 0) || (Viewport->GetSizeXY().Y == 0))
		{
			return false;
		}

		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(Viewport, InLevelEditorViewportClient->GetScene(), InLevelEditorViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(InLevelEditorViewportClient->IsRealtime()));
		FLevelEditorViewportClient* MutableViewportClient = const_cast<FLevelEditorViewportClient*>(InLevelEditorViewportClient);
		FSceneView* SceneView = MutableViewportClient->CalcSceneView(&ViewFamily);
		if (!SceneView)
		{
			return false;
		}

		ProjectionData.SetViewRectangle(SceneView->UnscaledViewRect);
		ProjectionData.SetConstrainedViewRectangle(SceneView->CameraConstrainedViewRect.Area() > 0 ? SceneView->CameraConstrainedViewRect : SceneView->UnscaledViewRect);
		ProjectionData.ViewOrigin = SceneView->ViewMatrices.GetViewOrigin();
		ProjectionData.ViewRotationMatrix = SceneView->ViewMatrices.GetViewMatrix().RemoveTranslation();
		ProjectionData.ProjectionMatrix = SceneView->ViewMatrices.GetProjectionMatrix();

		return ProjectionData.IsValidViewRectangle();
	}
	return false;
}

TArray<FLevelEditorViewportClient*> UBPFunctions_EditorWidget::GetLevelEditorCameraViewportClients()
{
	TArray<FLevelEditorViewportClient*> LevelEditorViewportClients;

	for (const auto& LevelEditorViewportClient : GEditor->GetLevelViewportClients())
	{
		FLevelViewportActorLock& ActorLock = LevelEditorViewportClient->GetActorLock();
		const AActor* Actor = ActorLock.GetLockedActor();
		if (IsValid(Actor))
		{
			LevelEditorViewportClients.Add(LevelEditorViewportClient);
		}
	}

	return LevelEditorViewportClients;
}

TArray<FLevelEditorViewportClient*> UBPFunctions_EditorWidget::GetLevelEditorViewportClients()
{
	TArray<FLevelEditorViewportClient*> LevelEditorViewportClients;

	for (const auto& LevelEditorViewportClient : GEditor->GetLevelViewportClients())
	{
		FLevelViewportActorLock& ActorLock = LevelEditorViewportClient->GetActorLock();
		const AActor* Actor = ActorLock.GetLockedActor();
		if (IsValid(Actor))
		{
			continue;
		}

		LevelEditorViewportClients.Add(LevelEditorViewportClient);
	}

	return LevelEditorViewportClients;
}

TSharedPtr<SLevelViewport> UBPFunctions_EditorWidget::GetEditorViewportWidget(const FLevelEditorViewportClient* InLevelEditorViewportClient)
{
	if (InLevelEditorViewportClient && InLevelEditorViewportClient->ParentLevelEditor.IsValid())
	{
		const TWeakPtr<ILevelEditor> ParentLevelEditor = InLevelEditorViewportClient->ParentLevelEditor;
		if (ParentLevelEditor.IsValid())
		{
			const TSharedPtr<ILevelEditor> LevelEditor = ParentLevelEditor.Pin();
			if (LevelEditor.IsValid())
			{
				for (auto Viewport : LevelEditor->GetViewports())
				{
					if (Viewport == InLevelEditorViewportClient->GetEditorViewportWidget())
					{
						return Viewport;
					}
				}
			}
		}
	}
	return nullptr;
}

bool UBPFunctions_EditorWidget::AddToEditorViewport(const FLevelEditorViewportClient* InLevelEditorViewportClient, const TSharedRef<SWidget>& InWidget)
{
	if (InLevelEditorViewportClient)
	{
		const TSharedPtr<SLevelViewport> LevelViewport = GetEditorViewportWidget(InLevelEditorViewportClient);
		if (LevelViewport.IsValid())
		{
			LevelViewport->AddOverlayWidget(InWidget);
			return true;
		}
	}

	return false;
}

bool UBPFunctions_EditorWidget::RemoveFromEditorViewport(const FLevelEditorViewportClient* InLevelEditorViewportClient, const TSharedRef<SWidget>& InWidget)
{
	if (InLevelEditorViewportClient)
	{
		const TSharedPtr<SLevelViewport> LevelViewport = GetEditorViewportWidget(InLevelEditorViewportClient);
		if (LevelViewport.IsValid())
		{
			LevelViewport->RemoveOverlayWidget(InWidget);
			return true;
		}
	}

	return false;
}
