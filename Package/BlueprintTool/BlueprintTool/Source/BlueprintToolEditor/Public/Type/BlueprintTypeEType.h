#pragma once

#include "CoreMinimal.h"

struct FPC_Public
{
	static const FName PC_Default;
	static const FName PC_Exec;
	static const FName PC_Boolean;
	static const FName PC_Byte;
	static const FName PC_Class;    // SubCategoryObject is the MetaClass of the Class passed thru this pin, or SubCategory can be 'self'. The DefaultValue string should always be empty, use DefaultObject.
	static const FName PC_SoftClass;
	static const FName PC_Int;
	static const FName PC_Int64;
	static const FName PC_Float;
	static const FName PC_Double;
	static const FName PC_Real;
	static const FName PC_Name;
	static const FName PC_Delegate;    // SubCategoryObject is the UFunction of the delegate signature
	static const FName PC_MCDelegate;  // SubCategoryObject is the UFunction of the delegate signature
	static const FName PC_Object;    // SubCategoryObject is the Class of the object passed thru this pin, or SubCategory can be 'self'. The DefaultValue string should always be empty, use DefaultObject.
	static const FName PC_Interface;	// SubCategoryObject is the Class of the object passed thru this pin.
	static const FName PC_SoftObject;		// SubCategoryObject is the Class of the AssetPtr passed thru this pin.
	static const FName PC_String;
	static const FName PC_Text;
	static const FName PC_Struct;    // SubCategoryObject is the ScriptStruct of the struct passed thru this pin, 'self' is not a valid SubCategory. DefaultObject should always be empty, the DefaultValue string may be used for supported structs.
	static const FName PC_Wildcard;    // Special matching rules are imposed by the node itself
	static const FName PC_Enum;    // SubCategoryObject is the UEnum object passed thru this pin
	static const FName PC_FieldPath;		// SubCategoryObject is the Class of the property passed thru this pin.

	// Common PinType.PinSubCategory values
	static const FName PSC_Self;    // Category=PC_Object or PC_Class, indicates the class being compiled

	static const FName PSC_Index;	// Category=PC_Wildcard, indicates the wildcard will only accept Int, Bool, Byte and Enum pins (used when a pin represents indexing a list)
	static const FName PSC_Bitmask;	// Category=PC_Byte or PC_Int, indicates that the pin represents a bitmask field. SubCategoryObject is either NULL or the UEnum object to which the bitmap is linked for bitflag name specification.

	// Pin names that have special meaning and required types in some contexts (depending on the node type)
	static const FName PN_Execute;    // Category=PC_Exec, singleton, input
	static const FName PN_Then;    // Category=PC_Exec, singleton, output
	static const FName PN_Completed;    // Category=PC_Exec, singleton, output
	static const FName PN_DelegateEntry;    // Category=PC_Exec, singleton, output; entry point for a dynamically bound delegate
	static const FName PN_EntryPoint;	// entry point to the ubergraph
	static const FName PN_Self;    // Category=PC_Object, singleton, input
	static const FName PN_Else;    // Category=PC_Exec, singleton, output
	static const FName PN_Loop;    // Category=PC_Exec, singleton, output
	static const FName PN_After;    // Category=PC_Exec, singleton, output
	static const FName PN_ReturnValue;		// Category=PC_Object, singleton, output
	static const FName PN_ObjectToCast;    // Category=PC_Object, singleton, input
	static const FName PN_Condition;    // Category=PC_Boolean, singleton, input
	static const FName PN_Start;    // Category=PC_Int, singleton, input
	static const FName PN_Stop;    // Category=PC_Int, singleton, input
	static const FName PN_Index;    // Category=PC_Int, singleton, output
	static const FName PN_Item;    // Category=PC_Int, singleton, output
	static const FName PN_CastSucceeded;    // Category=PC_Exec, singleton, output
	static const FName PN_CastFailed;    // Category=PC_Exec, singleton, output
	static const FString PN_CastedValuePrefix;    // Category=PC_Object, singleton, output; actual pin name varies depending on the type to be casted to, this is just a prefix

	// construction script function names
	static const FName FN_UserConstructionScript;
	static const FName FN_ExecuteUbergraphBase;
};


#define StaticIndex(Type) static int32 Type##VariableIndex = 0
#define Increase(Type) Type##VariableIndex++


class FBPHelperWriter : public FArchiveUObject
{
public:
	TArray<uint8>& ScriptBuffer;
	uint32 Pos;

public:
	FBPHelperWriter(TArray<uint8> Buffer) : ScriptBuffer(Buffer), Pos(0)
	{
		ScriptBuffer.Empty();
	}

	virtual void Serialize(void* V, int64 Length) override
	{
		int32 Start = ScriptBuffer.AddUninitialized(Length);
		FMemory::Memcpy(&(ScriptBuffer[Start]), V, Length);
		Pos += Length;
	}

	using FArchiveUObject::operator<<;

	virtual FArchive& operator<<(FName& Name) override
	{
		FArchive& Ar = *this;

		uint32 DisplayIndex = Name.GetDisplayIndex().ToUnstableInt();
		uint32 ComparisonIndex = Name.GetComparisonIndex().ToUnstableInt();
		int32 Number = Name.GetNumber();
		return Ar;
	}

	virtual FArchive& operator<<(UObject*& Object) override
	{
		ScriptPointerType ObjPtr = (ScriptPointerType)Object;
		(*this) << ObjPtr;
		return *this;
	}

	virtual FArchive& operator<<(FProperty* Property)
	{
		ScriptPointerType ObjPtr = (ScriptPointerType)Property;
		(*this) << ObjPtr;
		return *this;
	}

	virtual FArchive& operator<<(TCHAR* Str)
	{
		Serialize(Str, FCString::Strlen(Str) + 1);
		return *this;
	}

};