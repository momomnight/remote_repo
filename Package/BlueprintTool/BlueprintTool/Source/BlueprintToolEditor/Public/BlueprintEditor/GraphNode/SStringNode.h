#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SStringNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SStringNode){}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};