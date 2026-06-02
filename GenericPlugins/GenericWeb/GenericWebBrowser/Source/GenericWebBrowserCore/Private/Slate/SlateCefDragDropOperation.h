//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// CoreUObject/Public/
#include <UObject/StrongObjectPtr.h>
// SlateCore/Public/
#include <Input/DragAndDrop.h>
#include <Widgets/Images/SImage.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
#pragma endregion

#pragma region <Project Public Headers>
#include <Slate/SCefView.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "Details/CCefClientDelegate.h"
#pragma endregion

DECLARE_DELEGATE_TwoParams(FOnDragSourceEnd, bool bDropWasHandled, const FPointerEvent& MouseEvent);

/** 将 CEF 拖拽数据包装为 Slate 拖放操作。 */
class FCefDragDropOperation : public FGameDragDropOperation
{
public:
  /** CEF 拖拽源结束时通知浏览器结果。 */
  FOnDragSourceEnd OnDragSourceEnd;

public:
  DRAG_DROP_OPERATOR_TYPE(FCefDragDropOperation, FGameDragDropOperation)

  FCefDragDropOperation();

  ~FCefDragDropOperation();

  /** 返回原始 CEF 拖拽数据。 */
  CefRefPtr<CefDragData> GetCefDragData() const;

protected:
  TSharedPtr<SWidget> GetDefaultDecorator() const override;
  FVector2D GetDecoratorPosition() const override;
  void OnDragged(const class FDragDropEvent& DragDropEvent) override;
  void OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent) override;

private:
  /** CEF 提供的拖拽数据。 */
  CefRefPtr<CefDragData> DragData;

  /** 拖拽装饰图使用的临时纹理。 */
  TStrongObjectPtr<UTexture2D> DecoratorTexture;

  /** 拖拽过程中显示的装饰控件。 */
  TSharedPtr<SWidget> DecoratorWidget;

  /** 装饰控件当前显示位置。 */
  FVector2D DecoratorPosition = FVector2D::Zero();

  /** CEF 提供的拖拽热点偏移。 */
  FVector2D DecoratorHotspot = FVector2D::Zero();

  friend TSharedPtr<FCefDragDropOperation> CreateFCefDragDropOperation(CefRefPtr<CefDragData>& InCefDragData);
};

/** 将 CEF 拖拽操作映射为 Unreal 鼠标光标类型。 */
EMouseCursor::Type
MapCefDragDropOperationToEMouseCursorType(const CefRenderHandler::DragOperation& InOps);

/** 从 CEF 拖拽数据创建 Slate 拖放操作。 */
TSharedPtr<FCefDragDropOperation>
CreateFCefDragDropOperation(CefRefPtr<CefDragData>& InCefDragData);

/** 判断 Slate 拖放操作是否可以转换为 CEF 拖拽数据。 */
bool
IsCefAcceptableDragData(TSharedPtr<FDragDropOperation>& InDragOperation);

/** 将 Slate 拖放操作转换为 CEF 拖拽数据。 */
CefRefPtr<CefDragData>
CreateCefDragData(TSharedPtr<FDragDropOperation>& InDragOperation);
