#pragma once

#include "CoreMinimal.h"

struct FFunctionTerminal : public TSharedFromThis<FFunctionTerminal>
{
	FName Name;
	FName Type;

	FString DefaultValue;
	UObject* DefaultObject;
	FText DefaultTextValue;

	//一个属性可能有输入和输出端子
	TEnumAsByte<enum EEdGraphPinDirection> Direction;

	FGuid PinId;
	bool bIsLink;
	bool bIsBPVariable;

	class UEdGraphPin* InputPin;
	TArray<UEdGraphPin*> OutPin;
	UEdGraphNode* PureNode;
	TArray<TSharedPtr<FFunctionTerminal>> NodeTerminal;

	FORCEINLINE bool IsReturnValue() const { return Name == SpecifiedName; }
	FORCEINLINE bool IsLink() const {return bIsLink;}
	FORCEINLINE bool IsBPVariable() const { return bIsBPVariable; }
	FFunctionTerminal():DefaultObject(nullptr), bIsLink(false), bIsBPVariable(false), InputPin(nullptr), PureNode(nullptr){}


	static FName SpecifiedName;
};
