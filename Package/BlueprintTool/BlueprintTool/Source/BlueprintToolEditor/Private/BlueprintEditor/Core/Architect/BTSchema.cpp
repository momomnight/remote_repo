
#include "BlueprintEditor/Core/Architect/BTSchema.h"
#include "EdGraph\EdGraphSchema.h"
#include "ToolMenu.h"
#include "EdGraph\EdGraphNode.h"
#include "Layout\SlateRect.h"
#include "Rendering\DrawElements.h"
#include "EdGraph\EdGraph.h"
#include "BlueprintEditor/Core/Architect/BTSchemaAction.h"
#include "BlueprintEditor/GraphNode/BoardGraphNode.h"
#include "Utils\BlueprintSchemaUtils.h"
#include "UObject\Class.h"
#include "SimpleCode.h"
#include "Type/BlueprintTypeEType.h"
#include "BlueprintEditor\Core\Architect\BTSchemaAction.h"
#include "BlueprintEditor\GraphNode\ObjectNode.h"
#include "BlueprintEditor\GraphNode\EventNode.h"
#include "BlueprintEditor/GraphNode/BooleanNode.h"
#include "BlueprintEditor/GraphNode/ByteNode.h"
#include "BlueprintEditor/GraphNode/FloatNode.h"
#include "BlueprintEditor/GraphNode/LocationNode.h"
#include "BlueprintEditor/GraphNode/NameNode.h"
#include "BlueprintEditor/GraphNode/StringNode.h"
#include "BlueprintEditor/GraphNode/TextNode.h"
#include "BlueprintEditor/GraphNode/IntNode.h"

#define LOCTEXT_NAMESPACE "PBToolSchema"

#pragma optimize("", off)

UBlueprintToolSchema::UBlueprintToolSchema(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UBlueprintToolSchema::InitVariable(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UObjectNode	>("Object",		"Variable",LOCTEXT("NewObject",		"a object    variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UBooleanNode	>("Boolean",	"Variable",LOCTEXT("NewBoolean",	"a boolean   variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UByteNode		>("Byte",		"Variable",LOCTEXT("NewByte",		"a byte      variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UFloatNode	>("Float",		"Variable",LOCTEXT("NewFloat",		"a float     variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UDoubleNode	>("Double",		"Variable",LOCTEXT("NewDouble",		"a double    variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UIntNode		>("Int",		"Variable",LOCTEXT("NewIntt",		"a int       variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UInt64Node	>("Int64",		"Variable",LOCTEXT("NewInt64",		"a int64     variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UVectorNode	>("Vector",		"Variable",LOCTEXT("NewVector",		"a vector    variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<URotatorNode	>("Rotator",	"Variable",LOCTEXT("NewRotator",	"a rotator   variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UTransformNode>("Transform",	"Variable",LOCTEXT("NewTransform",	"a transform variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UNameNode		>("Name",		"Variable",LOCTEXT("NewName",		"a name      variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UStringNode	>("String",		"Variable",LOCTEXT("NewString",		"a string    variable"), FFieldParam()));
	ContextMenuBuilder.AddAction(FBPToolSchemaUtils::CreateAction<UTextNode		>("Text",		"Variable",LOCTEXT("NewText",		"a text		 variable"), FFieldParam()));
	
}

void UBlueprintToolSchema::InitVariable(TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions) const
{
	FBPToolSchemaUtils::CreateAction<UObjectNode	>("Object",		"Variable", LOCTEXT("NewObject",	"a object    variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UBooleanNode	>("Boolean",	"Variable", LOCTEXT("NewBoolean",	"a boolean   variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UByteNode		>("Byte",		"Variable", LOCTEXT("NewByte",		"a byte      variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UFloatNode		>("Float",		"Variable", LOCTEXT("NewFloat",		"a float     variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UDoubleNode	>("Double",		"Variable", LOCTEXT("NewDouble",	"a double    variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UIntNode		>("Int",		"Variable", LOCTEXT("NewIntt",		"a int       variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UInt64Node		>("Int64",		"Variable", LOCTEXT("NewInt64",		"a int64     variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UVectorNode	>("Vector",		"Variable", LOCTEXT("NewVector",	"a vector    variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<URotatorNode	>("Rotator",	"Variable", LOCTEXT("NewRotator",	"a rotator   variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UTransformNode	>("Transform",	"Variable", LOCTEXT("NewTransform", "a transform variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UNameNode		>("Name",		"Variable", LOCTEXT("NewName",		"a name      variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UStringNode	>("String",		"Variable", LOCTEXT("NewString",	"a string    variable"), OutActions, FFieldParam());
	FBPToolSchemaUtils::CreateAction<UTextNode		>("Text",		"Variable", LOCTEXT("NewText",		"a text		 variable"), OutActions, FFieldParam());
}

//右键调用
void UBlueprintToolSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TArray<UClass*> CodeClassArray;
	GetDerivedClasses(USimpleCode::StaticClass(), CodeClassArray, true);
	for (UClass* TempCode : CodeClassArray)//遍历派生类
	{
		for (TFieldIterator<UFunction> I(TempCode); I; ++I)
		{
			UFunction* Function = *I;
			if (Function)
			{
				if (Function->GetMetaData(TEXT("CodeType")) == TEXT("Event"))
				{
					TSharedPtr<FEdGraphSchemaAction> Action = FBPToolSchemaUtils::CreateAction<UEventNode>(Function->GetName(), Function->GetMetaData(TEXT("Group")), Function->GetToolTipText(), FFieldParam(Function));
					ContextMenuBuilder.AddAction(Action);
				}
				else
				{
					TSharedPtr<FEdGraphSchemaAction> Action = FBPToolSchemaUtils::CreateAction<UBoardGraphNode>(Function->GetName(), Function->GetMetaData(TEXT("Group")), Function->GetToolTipText(), FFieldParam(Function));
					ContextMenuBuilder.AddAction(Action);
				}

			}
		}
		for (TFieldIterator<FProperty> I(TempCode); I; ++I)
		{
			FProperty* Property = *I;
			if (Property)
			{
				TSharedPtr<FEdGraphSchemaAction> Action = FBPToolSchemaUtils::CreateAction<UBoardGraphNode>(Property->GetName(), Property->GetMetaData(TEXT("Group")), Property->GetToolTipText(), FFieldParam(Property));
				ContextMenuBuilder.AddAction(Action);
			}
		}
	}

	InitVariable(ContextMenuBuilder);
}

void UBlueprintToolSchema::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	if (Menu)
	{
		FToolMenuSection& Section = Menu->FindOrAddSection("MyGraphNode");
		{
			Section.AddSeparator(TEXT("MenuSeparator"));
			Section.AddMenuEntry("MyGraphNodeMenuEntry", LOCTEXT("Label", "MyLabel"),
				LOCTEXT("ToolTip", "MyToolTip"), FSlateIcon(), FToolUIActionChoice());

			Section.AddEntry(FToolMenuEntry::InitWidget(TEXT("TextName1"), SNew(SEditableTextBox), LOCTEXT("Label1", "MyLabel1")));
			Section.AddEntry(FToolMenuEntry::InitWidget(TEXT("TextName2"), SNew(SEditableTextBox), LOCTEXT("Label2", "MyLabel2")));
		}
	}
}

const FPinConnectionResponse UBlueprintToolSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	struct EqualCategoryHelpr
	{
		bool operator()(const UEdGraphPin* L, const UEdGraphPin* R)
		{
			return L->PinType.PinCategory == R->PinType.PinCategory;
		}
	}EqualCategory;


	ECanCreateConnectionResponse Response = CONNECT_RESPONSE_MAKE;

	if (A->GetOwningNode() == B->GetOwningNode() || A->Direction == B->Direction)//是否是自己连接自己、方向是否相同
	{
		Response = CONNECT_RESPONSE_DISALLOW;
	}
	else
	{
		if (EqualCategory(A, B))
		{
			if (A->PinType.PinCategory == FPC_Public::PC_Exec)
			{
				if (A->Direction == EGPD_Input)
				{
					Response = CONNECT_RESPONSE_BREAK_OTHERS_B;
				}
				else if(A->Direction == EGPD_Output)
				{
					Response = CONNECT_RESPONSE_BREAK_OTHERS_A;
				}
			}
		}
		else
		{
			Response = CONNECT_RESPONSE_DISALLOW;
		}
	}

	return FPinConnectionResponse(Response, TEXT("Not implemented by this schema"));

}

FConnectionDrawingPolicy* UBlueprintToolSchema::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, 
	float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj) const
{
	return nullptr;
}


//void UBlueprintToolSchema::GetActionList(UEdGraph* OwnerBpGraph, TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions) const
//打开资产调用
void UBlueprintToolSchema::GetActionList(TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions) const
{
	TArray<UClass*> CodeClassArray;
	GetDerivedClasses(USimpleCode::StaticClass(), CodeClassArray, true);

	for (UClass* TempCode : CodeClassArray)//遍历派生类
	{
		for (TFieldIterator<UFunction> I(TempCode); I; ++I)
		{
			UFunction* Function = *I;
			if (Function)
			{
				if (Function->GetMetaData(TEXT("CodeType")) == TEXT("Event"))
				{
					FBPToolSchemaUtils::CreateAction<UEventNode>(Function->GetName(), Function->GetMetaData(TEXT("Group")),
						Function->GetToolTipText(), OutActions, FFieldParam(Function));
				}
				else
				{
					FBPToolSchemaUtils::CreateAction<UBoardGraphNode>(Function->GetName(), Function->GetMetaData(TEXT("Group")),
						Function->GetToolTipText(), OutActions, FFieldParam(Function));
				}
			}
		}
		for (TFieldIterator<FProperty> I(TempCode); I; ++I)
		{
			FProperty* Property = *I;
			if (Property)
			{
				FBPToolSchemaUtils::CreateAction<UBoardGraphNode>(Property->GetName(), Property->GetMetaData(TEXT("Group")), 
					Property->GetToolTipText(), OutActions, FFieldParam(Property));
			}
		}
	}

	InitVariable(OutActions);
}



bool UBlueprintToolSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
	

	return Super::TryCreateConnection(A, B);
}
#pragma optimize("", on)

#undef LOCTEXT_NAMESPACE