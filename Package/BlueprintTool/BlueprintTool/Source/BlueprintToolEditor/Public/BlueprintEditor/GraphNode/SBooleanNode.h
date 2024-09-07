#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SBooleanNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SBooleanNode){}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};