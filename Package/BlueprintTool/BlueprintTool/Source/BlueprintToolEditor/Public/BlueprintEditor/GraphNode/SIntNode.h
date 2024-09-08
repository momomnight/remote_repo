#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SIntNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SIntNode){}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

}; 

class SInt64Node : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SInt64Node) {}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};