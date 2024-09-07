// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraphUtilities.h"


class BLUEPRINTTOOLEDITOR_API FBTGraphPanelNodeFactory : public FGraphPanelNodeFactory
{
public:
	virtual TSharedPtr<class SGraphNode> CreateNode(class UEdGraphNode* Node) const override;
};

class BLUEPRINTTOOLEDITOR_API FBTGraphPanelPinFactory : public FGraphPanelPinFactory
{
public:
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* Pin) const override;
};

struct BLUEPRINTTOOLEDITOR_API FBTGraphPanelPinConnectionFactory : public FGraphPanelPinConnectionFactory
{
public:
	virtual class FConnectionDrawingPolicy* CreateConnectionPolicy(const class UEdGraphSchema* Schema, int32 InBackLayerID, int32 InFrontLayerID, float ZoomFactor, const class FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;
};

struct BTGraphPanelFactoryUtility
{
	static void RegisterBTGraphPanelFactory();
	static void UnregisterBTGraphPanelFactory();
private:
	void CreateFactory();
	static TSharedPtr<BTGraphPanelFactoryUtility> FactoryUtility;
	TSharedPtr<FBTGraphPanelNodeFactory> NodeFactory;
	TSharedPtr<FBTGraphPanelPinFactory> PinFactory;
	TSharedPtr<FBTGraphPanelPinConnectionFactory> PinConnectionFactory;
};




