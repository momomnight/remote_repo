#include "Factory/Blueprint/BlueprintToolFactory.h"

#include "EdGraph\EdGraphNode.h"
#include "SGraphNode.h"
#include "EdGraph\EdGraphPin.h"
#include "SGraphPin.h"
#include "EdGraphUtilities.h"
#include "EdGraph\EdGraphSchema.h"
#include "Layout\SlateRect.h"
#include "Rendering\DrawElements.h"
#include "EdGraph\EdGraph.h"
#include "EdGraphUtilities.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "BlueprintEditor/GraphNode/SBoardGraphNode.h"
#include "BlueprintEditor/GraphPin/SBoardGraphPin.h"
#include "BlueprintEditor/Core/Architect/BTSchema.h"
#include "BlueprintEditor/ConnectionDrawingPolicy/BTConnectionDrawingPolicy.h"
#include "BlueprintEditor/GraphNode/BoardGraphNode.h"
#include "BlueprintEditor/GraphNode/ObjectNode.h"
#include "BlueprintEditor/GraphNode/SObjectNode.h"
#include "BlueprintEditor/GraphNode/EventNode.h"
#include "BlueprintEditor/GraphNode/SEventNode.h"
#include "BlueprintEditor/GraphNode/BooleanNode.h"
#include "BlueprintEditor/GraphNode/SBooleanNode.h"
#include "BlueprintEditor/GraphNode/ByteNode.h"
#include "BlueprintEditor/GraphNode/SByteNode.h"
#include "BlueprintEditor/GraphNode/FloatNode.h"
#include "BlueprintEditor/GraphNode/SFloatNode.h"
#include "BlueprintEditor/GraphNode/LocationNode.h"
#include "BlueprintEditor/GraphNode/SLocationNode.h"
#include "BlueprintEditor/GraphNode/NameNode.h"
#include "BlueprintEditor/GraphNode/SNameNode.h"
#include "BlueprintEditor/GraphNode/StringNode.h"
#include "BlueprintEditor/GraphNode/SStringNode.h"
#include "BlueprintEditor/GraphNode/TextNode.h"
#include "BlueprintEditor/GraphNode/STextNode.h"
#include "BlueprintEditor/GraphNode/IntNode.h"
#include "BlueprintEditor/GraphNode/SIntNode.h"
#include "NodeFactory.h"

#pragma optimize("", off)

TSharedPtr<class SGraphNode> FBTGraphPanelNodeFactory::CreateNode(UEdGraphNode* Node) const
{
	if (UBoardGraphNode* K3Node = Cast<UBoardGraphNode>(Node))
	{
		return SNew(SK3Node, K3Node).NodeName(FText::FromString(K3Node->Function->GetName()));
	}

	if (UEventNode* EventNode = Cast<UEventNode>(Node))
	{
		return SNew(SEventNode, EventNode).NodeName(FText::FromString(EventNode->Function->GetName()));
	}

	if (UVariableNode* VariableNode = Cast<UVariableNode>(Node))
	{
		if (UObjectNode* ObjectNode = Cast<UObjectNode>(VariableNode))
		{
			return SNew(SObjectNode, ObjectNode);
		}

		if (UBooleanNode* BooleanNode = Cast<UBooleanNode>(VariableNode))
		{
			return SNew(SBooleanNode, BooleanNode);
		}

		if (UByteNode* ByteNode = Cast<UByteNode>(VariableNode))
		{
			return SNew(SByteNode, ByteNode);
		}

		if (UFloatNode* FloatNode = Cast<UFloatNode>(VariableNode))
		{
			return SNew(SFloatNode, FloatNode);
		}

		if (UDoubleNode* DoubleNode = Cast<UDoubleNode>(VariableNode))
		{
			return SNew(SDoubleNode, DoubleNode);
		}

		if (UIntNode* IntNode = Cast<UIntNode>(VariableNode))
		{
			return SNew(SIntNode, IntNode);
		}

		if (UInt64Node* Int64Node = Cast<UInt64Node>(VariableNode))
		{
			return SNew(SInt64Node, Int64Node);
		}

		if (UVectorNode* VectorNode = Cast<UVectorNode>(VariableNode))
		{
			return SNew(SVectorNode, VectorNode);
		}

		if (URotatorNode* RotatorNode = Cast<URotatorNode>(VariableNode))
		{
			return SNew(SRotatorNode, RotatorNode);
		}

		if (UTransformNode* TransformNode = Cast<UTransformNode>(VariableNode))
		{
			return SNew(STransformNode, TransformNode);
		}

		if (UNameNode* NameNode = Cast<UNameNode>(VariableNode))
		{
			return SNew(SNameNode, NameNode);
		}

		if (UStringNode* StringNode = Cast<UStringNode>(VariableNode))
		{
			return SNew(SStringNode, StringNode);
		}

		if (UTextNode* TextNode = Cast<UTextNode>(VariableNode))
		{
			return SNew(STextNode, TextNode);
		}
	}


	return TSharedPtr<SGraphNode>();
}

TSharedPtr<class SGraphPin> FBTGraphPanelPinFactory::CreatePin(UEdGraphPin* Pin) const
{
	TSharedPtr<SGraphPin> NewPin = nullptr;
	if (UK3Node* Node = Cast<UK3Node>(Pin->GetOwningNode()))
	{

		if (const UBlueprintToolSchema* Schema = Cast<const UBlueprintToolSchema>(Pin->GetSchema()))
		{
			NewPin = FNodeFactory::CreateK2PinWidget(Pin);
		}

		if (!NewPin.IsValid())
		{
			NewPin = SNew(SBTGraphPin, Pin).PinName(FText::FromString(Pin->GetName()));
		}
	}
	return NewPin;
}

FConnectionDrawingPolicy* FBTGraphPanelPinConnectionFactory::CreateConnectionPolicy(const UEdGraphSchema* Schema, 
	int32 InBackLayerID, int32 InFrontLayerID, float ZoomFactor, const FSlateRect& InClippingRect, 
	FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj) const
{
	if (Schema->IsA(UBlueprintToolSchema::StaticClass()))
	{
		return new FBTConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, ZoomFactor, InClippingRect, InDrawElements, InGraphObj);
	}

	return nullptr;
}


TSharedPtr<BTGraphPanelFactoryUtility> BTGraphPanelFactoryUtility::FactoryUtility = nullptr;

void BTGraphPanelFactoryUtility::RegisterBTGraphPanelFactory()
{
	if(!FactoryUtility.IsValid())
	{
		FactoryUtility = MakeShareable(new BTGraphPanelFactoryUtility);
		FactoryUtility->CreateFactory();
		FEdGraphUtilities::RegisterVisualNodeFactory(FactoryUtility->NodeFactory);
		FEdGraphUtilities::RegisterVisualPinFactory(FactoryUtility->PinFactory);
		FEdGraphUtilities::RegisterVisualPinConnectionFactory(FactoryUtility->PinConnectionFactory);
	}
}

void BTGraphPanelFactoryUtility::UnregisterBTGraphPanelFactory()
{
	if (FactoryUtility)
	{
		if (FactoryUtility->NodeFactory)
		{
			FEdGraphUtilities::UnregisterVisualNodeFactory(FactoryUtility->NodeFactory);
			FactoryUtility->NodeFactory.Reset();
		}
		if (FactoryUtility->PinFactory)
		{
			FEdGraphUtilities::UnregisterVisualPinFactory(FactoryUtility->PinFactory);
			FactoryUtility->PinFactory.Reset();
		}
		if (FactoryUtility->PinConnectionFactory)
		{
			FEdGraphUtilities::UnregisterVisualPinConnectionFactory(FactoryUtility->PinConnectionFactory);
			FactoryUtility->PinConnectionFactory.Reset();
		}
		FactoryUtility.Reset();
	}
}

void BTGraphPanelFactoryUtility::CreateFactory()
{
	NodeFactory = MakeShareable(new FBTGraphPanelNodeFactory);
	PinFactory = MakeShareable(new FBTGraphPanelPinFactory);
	PinConnectionFactory = MakeShareable(new FBTGraphPanelPinConnectionFactory);
}


#pragma optimize("", on)