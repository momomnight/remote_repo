
#pragma once

#include "CoreMinimal.h"
#include "SGraphNode.h"


class SK3Node : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SK3Node) {}

	SLATE_ATTRIBUTE(FText, NodeName)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, class UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

	virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd);

private:
	//void OnTextCommitted(const FText&, ETextCommit::Type);


protected:
	//TSharedPtr<class SBox> PinBox;

	TAttribute<FText> NodeName;
};