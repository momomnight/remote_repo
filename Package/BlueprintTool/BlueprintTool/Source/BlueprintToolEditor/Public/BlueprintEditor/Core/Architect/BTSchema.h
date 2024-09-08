#pragma once


#include "EdGraph\EdGraphSchema.h"
#include "BTSchema.generated.h"

// 管理 可视化的类
// 管理 如：右键菜单的action，节点的连接规则，Pin的绘制测量
UCLASS()
class UBlueprintToolSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()

public:
	void InitVariable(FGraphContextMenuBuilder& ContextMenuBuilder) const;

	void InitVariable(TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions) const;

	//Graph右键的菜单
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const;

	//对节点右键的菜单
	virtual void GetContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const;

	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const;

	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;

	void GetActionList(TArray<TSharedPtr<struct FEdGraphSchemaAction>>& OutActions) const;

	virtual bool TryCreateConnection(class UEdGraphPin* A, class UEdGraphPin* B) const override;


};