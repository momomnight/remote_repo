#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SVectorNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SVectorNode) {}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};

class SRotatorNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SRotatorNode) {}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};

class STransformNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(STransformNode){}

	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

};