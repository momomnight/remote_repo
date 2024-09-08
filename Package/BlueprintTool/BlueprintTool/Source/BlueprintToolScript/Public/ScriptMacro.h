#pragma once

#define BT_VM_Func_Declaration(Func) static void Func(UObject* Context, struct FBTFrame& Stack, void const* RefData)
#define BT_VM_Func_Definition(Class, Func) void Class::Func(UObject* Context, struct FBTFrame& Stack, void const* RefData)


#define Add_VM_Function(ByteCodeIndex)\
static uint8 ByteCodeIndex##_Native = BTRegisterNative((int32)EVMCommand::ByteCodeIndex\
	, &UBTScriptObject::ByteCodeIndex)

#define BODY_MACRO_COMBINE_INNER_BT(A,B,C,D) A##B##C##D
#define BODY_MACRO_COMBINE_BT(A,B,C,D) BODY_MACRO_COMBINE_INNER_BT(A,B,C,D)

#define GENERATED_BT_BODY(...) BODY_MACRO_COMBINE_BT(CURRENT_FILE_ID_BT, _, NEWLINE, _GENERATED_BODY_BT)