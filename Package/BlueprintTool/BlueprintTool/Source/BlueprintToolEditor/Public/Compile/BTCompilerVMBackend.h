#pragma once

#include "CoreMinimal.h"


class FVM
{
public:
	FVM(class FBTFunctionContext* NewFunctionList);

	void GenerateByteCode();
	void SeriealizeTerminal(class UK3Node* Node);
	~FVM() {}

private:
	void SeriealizeReturnValue(struct FScriptBuilder& ScriptBuilder, class UK3Node* Node);
	void SeriealizePureFunction(struct FScriptBuilder& ScriptBuilder, class UK3Node* Node);

	//trueΪ���������л���false˵���Ѿ����л�����
	bool SeriealizeBPVariable(struct FScriptBuilder& ScriptBuilder, class UK3Node* Node, UEdGraphPin* InPin, class FProperty* Property);
	bool CheckNodeOrder(class UEdGraphNode* NodeA, class UEdGraphNode* NodeB);

	//���ڼ�¼�ѱ����л��Ĵ�����
	TArray<class UK3Node*> NonLinearExectueNode;

private:
	
	class FBTFunctionContext* FunctionList;

};