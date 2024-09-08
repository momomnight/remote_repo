#pragma once

#include "CoreMinimal.h"

//参数
struct FParamElement
{

	FName Name;
	bool bConst{ false };
	bool bPtr{ false };
	bool bRef{ false };
	FName Type; 
};

//变量
struct FVariableAnalysis : public FParamElement
{
	FString CodeType; //是Resource还是其他
	bool bStatic{ false };
};

//函数
struct FFunctionAnalysis
{
	TArray<FParamElement> Params;
	FParamElement Return;

	FName FunctionName;
	bool bStatic{ false };
	bool bVirtual{ false };
	bool bConst{ false };
	FString CodeType;
};

//类
struct FClassAnalysis
{
	TArray<FVariableAnalysis> Variables;
	TArray<FFunctionAnalysis> Functions;

	FName ClassName;
	TArray<FName> ParentName;
	FName CodeCppName;

	FString ClassDeclarator;

	int32 CodeLine;

	FString Include;
};

//文件
struct FFileInfo
{
	TArray<FClassAnalysis> ClassAnalysis;
	FString HeadInclude;
	FString FileID;

	FString ReflectionDataSourcePaths;
	FString ReflectionDataHeadPaths;
	FString CodePaths;
};


enum ECollectionParamType
{
	Type_Return,
	Type_Param
};

//TypeCollection
class IUTC
{
public:
	//virtual ~IUTC() = 0;
	//收集类信息
	virtual bool Collect(const FString& Paths, TArray<FClassAnalysis>& ClassAnalysis) = 0;
};

//TypeBuilder
class IUTB
{
public:
	//virtual ~IUTB() = 0;
	//构建反射信息
	virtual bool Build(FFileInfo& FileInfo) = 0;
};

class FConstructionManagement
{
public:
	//执行总逻辑
	void Build(const FString& ProjectPath);
};