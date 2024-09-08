#include "BlueprintEditor/GraphNode/SObjectEditorDropTarget.h"


FReply SObjectEditorDropTarget::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
    PanelCoordinate = MyGeometry.AbsoluteToLocal(DragDropEvent.GetScreenSpacePosition());

    return SAssetDropTarget::OnDrop(MyGeometry, DragDropEvent);
}

EVisibility SObjectEditorDropTarget::GetOverlayVisibility()
{
    return GetDragOverlayVisibility();;
}


