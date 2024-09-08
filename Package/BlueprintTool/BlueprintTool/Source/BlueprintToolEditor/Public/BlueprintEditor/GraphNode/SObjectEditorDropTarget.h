#pragma once

#include "CoreMinimal.h"
#include "SAssetDropTarget.h"

class SObjectEditorDropTarget : public SAssetDropTarget
{

public:

	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;

	EVisibility GetOverlayVisibility();

	FVector2D GetPanelCoordinate() const {return PanelCoordinate;}

private:
	FVector2D PanelCoordinate;
};