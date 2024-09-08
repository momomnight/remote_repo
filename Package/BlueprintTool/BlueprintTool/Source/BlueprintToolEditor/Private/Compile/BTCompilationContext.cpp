#include "Compile/BTCompilationContext.h"
#include "EdGraph/EdGraphNode.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "Compile\BTBlueprintCompiledStatement.h"
#include "Type/BlueprintTypeEType.h"
#include "Compile/BTCompilerVMBackend.h"
#include "EdGraph\EdGraphPin.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS


void FBTCompilationContext::GetCurrentParamTerminal(TArray<TSharedPtr<FFunctionTerminal>>& Terminals, 
	UEdGraphPin* InPin)
{
	if (InPin->PinType.PinCategory != FPC_Public::PC_Exec)
	{
		TSharedPtr<FFunctionTerminal> FunctionTerminal = MakeShareable(new FFunctionTerminal);
		FunctionTerminal->Direction = InPin->Direction;
		UK3Node* OwningNode = Cast<UK3Node>(InPin->GetOwningNode());

		if (InPin->Direction == EEdGraphPinDirection::EGPD_Input)
		{
			if (!InPin->LinkedTo.Num())
			{
				if (InPin->PinType.PinCategory == FPC_Public::PC_Text)
				{
					FunctionTerminal->DefaultTextValue = InPin->DefaultTextValue;
				}
				else
				{
					FunctionTerminal->DefaultValue = InPin->DefaultValue;
				}	
			}
			else
			{
				FunctionTerminal->bIsLink = true;
				FunctionTerminal->InputPin = InPin->LinkedTo[0];

				if (UK3Node* K3Node = Cast<UK3Node>(FunctionTerminal->InputPin->GetOwningNode()))
				{
					if (K3Node->IsPure() || K3Node->IsA<UVariableNode>())
					{
						//每个节点一个端子数组
						FunctionTerminal->PureNode = K3Node;
						TArray<TSharedPtr<FFunctionTerminal>> TempTerminalArray;
						for (UEdGraphPin* Pin : K3Node->Pins)
						{
							GetCurrentParamTerminal(TempTerminalArray, Pin);
						}
						FunctionTerminal->NodeTerminal = TempTerminalArray;
					}
				}

			}
		}
		else
		{
			if (InPin->LinkedTo.Num())
			{
				if(OwningNode->IsA<UVariableNode>())
				{
					FunctionTerminal->DefaultValue = OwningNode->Pins[0]->DefaultValue;
					FunctionTerminal->bIsBPVariable = true;
				}
				FunctionTerminal->bIsLink = true;
			}
		}

		FunctionTerminal->Name = InPin->PinName;
		FunctionTerminal->Type = InPin->PinType.PinCategory;
		FunctionTerminal->PinId = InPin->PinId;
		Terminals.Add(FunctionTerminal);
	}
	
}


//主逻辑线性执行，函数执行先取值
void FBTCompilationContext::CompileFunction(FBTFunctionContext& FunctionContext)
{
	UEdGraphNode* EndNode = nullptr;

	//第一个节点为事件入口
	if (UK3Node* K3Node = Cast<UK3Node>(FunctionContext.LinearExecutionList[0]))
	{
		FunctionContext.ListVMStatement.Add(K3Node, EVMStatementType::VMS_CallFunc);
		TArray<TSharedPtr<FFunctionTerminal>> TerminalArray;
		for (auto TempPin : K3Node->Pins)
		{
			GetCurrentParamTerminal(TerminalArray, TempPin);
		}

		if (TerminalArray.Num() > 0)
		{
			FunctionContext.TerminalMap.Add(K3Node, TerminalArray);
		}
	}

	TArray<UEdGraphNode*>& LinearNodeList = FunctionContext.LinearExecutionList;

	for (int32 I = 1; I < LinearNodeList.Num(); I++)
	{
		if (UK3Node* K3Node = Cast<UK3Node>(LinearNodeList[I]))
		{
			if (K3Node->Function)
			{
				//编译语句
				FunctionContext.ListVMStatement.Add(K3Node, EVMStatementType::VMS_Next);
				
				//收集Terminial
				TArray<TSharedPtr<FFunctionTerminal>> TerminalArray;
				for (auto TempPin : K3Node->Pins)
				{
					GetCurrentParamTerminal(TerminalArray, TempPin);
				}

				if (TerminalArray.Num() > 0)
				{ 
					FunctionContext.TerminalMap.Add(K3Node, TerminalArray);
				}
			}
		}
	}
	//字节码编译
	FVM VM(&FunctionContext);
	VM.GenerateByteCode();
}

#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS