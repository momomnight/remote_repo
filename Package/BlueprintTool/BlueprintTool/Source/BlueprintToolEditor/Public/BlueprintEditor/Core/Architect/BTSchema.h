#pragma once


#include "EdGraph\EdGraphSchema.h"
#include "BTSchema.generated.h"

// ���� ���ӻ�����
// ���� �磺�Ҽ��˵���action���ڵ�����ӹ���Pin�Ļ��Ʋ���
UCLASS()
class UBlueprintToolSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()

public:
	void InitVariable(FGraphContextMenuBuilder& ContextMenuBuilder) const;

	void InitVariable(TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions) const;

	//Graph�Ҽ��Ĳ˵�
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const;

	//�Խڵ��Ҽ��Ĳ˵�
	virtual void GetContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const;

	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const;

	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;

	void GetActionList(TArray<TSharedPtr<struct FEdGraphSchemaAction>>& OutActions) const;

	virtual bool TryCreateConnection(class UEdGraphPin* A, class UEdGraphPin* B) const override;


};