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

	//true为进行了序列化，false说明已经序列化过了
	bool SeriealizeBPVariable(struct FScriptBuilder& ScriptBuilder, class UK3Node* Node, UEdGraphPin* InPin, class FProperty* Property);
	bool CheckNodeOrder(class UEdGraphNode* NodeA, class UEdGraphNode* NodeB);

	//用于记录已被序列化的纯函数
	TArray<class UK3Node*> NonLinearExectueNode;

private:
	
	class FBTFunctionContext* FunctionList;

};