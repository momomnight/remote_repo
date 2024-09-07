#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SFloatNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SFloatNode){}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};

class SDoubleNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SDoubleNode) {}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};