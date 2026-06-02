//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "SlateCefDragDropOperation.h"
#pragma endregion

#pragma region <Engine Headers>
// Engine/Classes/
#include <Engine/Texture2D.h>
// Engine/Public/
#include <ImageUtils.h>
// Slate/Public/
#include <Framework/Application/SlateApplication.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Convert.h"
#pragma endregion

using namespace Common::Convert;

FCefDragDropOperation::FCefDragDropOperation()
  : FGameDragDropOperation()
{
  bCreateNewWindow = false;
}

FCefDragDropOperation::~FCefDragDropOperation()
{
  DragData.reset();
}

CefRefPtr<CefDragData>
FCefDragDropOperation::GetCefDragData() const
{
  return DragData;
}

TSharedPtr<SWidget>
FCefDragDropOperation::GetDefaultDecorator() const
{
  return DecoratorWidget;
}

FVector2D
FCefDragDropOperation::GetDecoratorPosition() const
{
  return DecoratorPosition;
}

void
FCefDragDropOperation::OnDragged(const class FDragDropEvent& DragDropEvent)
{
  FDragDropOperation::OnDragged(DragDropEvent);

  DecoratorPosition = DragDropEvent.GetScreenSpacePosition() - DecoratorHotspot;
}

void
FCefDragDropOperation::OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent)
{
  FDragDropOperation::OnDrop(bDropWasHandled, MouseEvent);

  OnDragSourceEnd.ExecuteIfBound(bDropWasHandled, MouseEvent);
}

EMouseCursor::Type
MapCefDragDropOperationToEMouseCursorType(const CefRenderHandler::DragOperation& InOps)
{
  switch (InOps) {
    case DRAG_OPERATION_NONE:
      return EMouseCursor::Type::SlashedCircle;
    case DRAG_OPERATION_MOVE:
      return EMouseCursor::Type::CardinalCross;
    case DRAG_OPERATION_COPY:
    case DRAG_OPERATION_LINK:
    case DRAG_OPERATION_GENERIC:
    case DRAG_OPERATION_PRIVATE:
    case DRAG_OPERATION_DELETE:
      return EMouseCursor::Type::Default;
    default:
      break;
  }
  return EMouseCursor::Type::SlashedCircle;
}

TSharedPtr<FCefDragDropOperation>
CreateFCefDragDropOperation(CefRefPtr<CefDragData>& InCefDragData)
{
  /** CEF 提供拖拽预览图时，将 PNG 数据转换成 Slate 可显示的装饰控件。 */
  TStrongObjectPtr<UTexture2D> DecoratorTexture;
  TSharedPtr<SWidget> DecoratorWidget;
  if (auto CefDragDataImage = InCefDragData->GetImage()) {
    int DragImageWidth = 0;
    int DragImageHeight = 0;
    if (auto DecoratorImageDataBuffer = CefDragDataImage->GetAsPNG(1.0, true, DragImageWidth, DragImageHeight)) {
      TArray<uint8> PNGBuffer;
      PNGBuffer.SetNum(DecoratorImageDataBuffer->GetSize());
      DecoratorImageDataBuffer->GetData(PNGBuffer.GetData(), PNGBuffer.Num(), 0);
      DecoratorTexture = TStrongObjectPtr<UTexture2D>(FImageUtils::ImportBufferAsTexture2D(PNGBuffer));
      if (DecoratorTexture) {
        FSlateBrush* CursorBrush = new FSlateBrush();
        CursorBrush->SetResourceObject(DecoratorTexture.Get());
        CursorBrush->ImageSize = FVector2D(DecoratorTexture->GetSizeX(), DecoratorTexture->GetSizeY());
        CursorBrush->DrawAs = ESlateBrushDrawType::Image;
        DecoratorWidget = SNew(SImage) //
                            .Visibility(EVisibility::HitTestInvisible)
                            .Image(CursorBrush);
      }
    }
  }

  /** 保留 CEF 给出的热点偏移，让 Slate 拖拽预览跟随鼠标的位置一致。 */
  CefPoint DecoratorHotspot = InCefDragData->GetImageHotspot();

  /** Slate 拖拽操作持有原始 CEF 拖拽数据，Drop 结束后再回传给 CEF。 */
  auto Operation = TSharedPtr<FCefDragDropOperation>(new FCefDragDropOperation());
  Operation->DecoratorTexture = DecoratorTexture;
  Operation->DecoratorWidget = DecoratorWidget;
  Operation->DecoratorHotspot = FVector2D(DecoratorHotspot.x, DecoratorHotspot.y);
  Operation->DragData = InCefDragData;
  Operation->Construct();
  return Operation;
}

bool
IsCefAcceptableDragData(TSharedPtr<FDragDropOperation>& InDragOperation)
{
  bool bIsAcceptable = false;

  if (!InDragOperation.IsValid()) {
    return bIsAcceptable;
  }

  if (InDragOperation->IsOfType<FCefDragDropOperation>()) {
    auto Operation = StaticCastSharedPtr<FCefDragDropOperation>(InDragOperation);
    if (Operation->GetCefDragData()) {
      bIsAcceptable = true;
    }
  } else if (InDragOperation->IsOfType<FExternalDragOperation>()) {
    bIsAcceptable = true;
  }

  return bIsAcceptable;
}

CefRefPtr<CefDragData>
CreateCefDragData(TSharedPtr<FDragDropOperation>& InDragOperation)
{
  CefRefPtr<CefDragData> OutDragData;

  if (!InDragOperation.IsValid()) {
    return OutDragData;
  }

  if (InDragOperation->IsOfType<FCefDragDropOperation>()) {
    auto Operation = StaticCastSharedPtr<FCefDragDropOperation>(InDragOperation);

    /** 浏览器内部发起的拖拽复用 CEF 数据，但清掉文件内容避免重复持有大块数据。 */
    if (Operation->GetCefDragData()) {
      OutDragData = Operation->GetCefDragData()->Clone();
      OutDragData->ResetFileContents();
    }
  } else if (InDragOperation->IsOfType<FExternalDragOperation>()) {
    auto Operation = StaticCastSharedPtr<FExternalDragOperation>(InDragOperation);

    /** 外部系统拖进 Slate 的数据需要重新封装成 CEF 可识别的 DragData。 */
    OutDragData = CefDragData::Create();

    /** 文本片段直接进入 CEF fragment text。 */
    if (Operation->HasText()) {
      OutDragData->SetFragmentText(StringF2C(Operation->GetText()));
    }

    /** 文件拖拽只传路径和展示名，文件内容仍由 CEF 后续按路径读取。 */
    if (Operation->HasFiles()) {
      for (const auto& FileName : Operation->GetFiles()) {
        OutDragData->AddFile(StringF2C(FileName), StringF2C(FPaths::GetCleanFilename(FileName)));
      }
    }
  }

  return OutDragData;
}
