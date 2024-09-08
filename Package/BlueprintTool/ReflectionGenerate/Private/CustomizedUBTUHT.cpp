#include "CustomizedUBTUHT.h"
#include "HAL\PlatformFileManager.h"
#include <stack>
#include "UObject\Class.h"
#include "Macro.h"

class FUnrealTypeCollection;
class FUnrealTypeBuilder;


#pragma optimize("", off)


struct PosHelper
{
	int32 RowNumber{ -1 };
	int32 ColumnNumber{ -1 };
	bool IsValid() const { return !(RowNumber == -1 || ColumnNumber == -1); }	
};

struct Helper
{
	static bool Equal(const PosHelper& Lhs, const PosHelper& Rhs)
	{
		return (Lhs.RowNumber == Rhs.RowNumber) && (Lhs.ColumnNumber == Rhs.ColumnNumber);
	}

	static bool Less(const PosHelper& Lhs, const PosHelper& Rhs)
	{
		if (Lhs.RowNumber < Rhs.RowNumber)
		{
			return true;
		}
		else if (Lhs.RowNumber == Rhs.RowNumber)
		{
			if (Lhs.ColumnNumber < Rhs.ColumnNumber)
			{
				return true;
			}
		}
		return false;
	}

	static bool IsUObject(FString TypeName)
	{
		TypeName.TrimStartAndEndInline();
		if (TypeName.IsEmpty())
		{
			return false;
		}

		TCHAR Ch = TypeName[0];

		for (int32 I = 0; I < UETypePrefixNumber; I++)
		{
			if (Ch == UETypePrefix[I])
			{
				return true;
			}
		}
		return false;
	}

	//跳过注释, 默认从头查找, 可以查找*/,但查找位置不能在 /* 或 //之前
	static int32 CheckCommentary(const FString& Codes, int32 Start = -1)
	{
		if (Start == INDEX_NONE)
		{
			Start = 0;
		}

		for(int32 I = Start + 1; I < Codes.Len(); I++)
		{
			TCHAR Ch = Codes[I - 1];
			if (Ch == TEXT('/'))
			{	
				TCHAR TempCh = Codes[I];
				if (TempCh == TEXT('/') || TempCh == TEXT('*'))
				{
					return I - 1;
				}				
			}
		}	
		return -1;
	}

	//如果Pos是合法位置，则什么都不做，否则加行数，如果超出Codes极限则返回false, 如果Pos本身不合法返回false
	static bool Increment(const TArray<FString>& Codes, PosHelper& InPos)
	{
		if (!Helper::IsValidIndex(Codes, InPos))
		{
			return false;
		}

		PosHelper Pos = InPos;
		if (Pos.IsValid())
		{
			Pos.ColumnNumber++;
			if (!Helper::IsValidIndex(Codes, Pos))
			{
				Helper::IncrementRow(Codes, Pos);
				if (!Helper::IsValidIndex(Codes, Pos))
				{
					return false;
				}	
			}
			InPos = Pos;
			return true;
		}
		return false;
	}

	static bool IncrementRow(const TArray<FString>& Codes, PosHelper& InPos)
	{
		if (Codes.IsValidIndex(InPos.RowNumber))
		{
			InPos.RowNumber++;
			InPos.ColumnNumber = 0;
			while (true)
			{
				if(Codes.IsValidIndex(InPos.RowNumber))
				{
					if (Codes[InPos.RowNumber].IsEmpty())
					{
						InPos.RowNumber++;
					}
					else
					{			
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}

	static bool IsValidIndex(const TArray<FString>& Codes, const PosHelper& Pos)
	{
		if (Pos.IsValid() && Codes.IsValidIndex(Pos.RowNumber) && Codes[Pos.RowNumber].IsValidIndex(Pos.ColumnNumber))
		{
			return true;
		}
		return false;
	}

	static PosHelper FindString(PosHelper Start, const TArray<FString>& Codes, const FString& InStr)
	{
		
		while (Helper::IsValidIndex(Codes, Start))
		{		
			Start.ColumnNumber = Codes[Start.RowNumber].Find(InStr, ESearchCase::CaseSensitive, ESearchDir::FromStart, Start.ColumnNumber);

			if (Start.IsValid())
			{
				return Start;
			}
			else
			{
				Helper::IncrementRow(Codes, Start);
			}
		}
		return PosHelper();
	}

	static bool FindString(const FString& Substr, const FString& Str, int32& Pos, ESearchCase::Type SearchCast = ESearchCase::CaseSensitive, 
		ESearchDir::Type SearchDir = ESearchDir::FromStart, int32 StartPos = -1)
	{
		Pos = Str.Find(Substr, SearchCast, SearchDir, StartPos);
		return Pos != INDEX_NONE;
	}

	static FString GetStringFromMultirow(PosHelper Start, PosHelper End, const TArray<FString>& Codes)
	{
		if (!ensure(Start.IsValid() && End.IsValid() && Codes.IsValidIndex(Start.RowNumber)
			&& Codes.IsValidIndex(End.RowNumber) && Start.RowNumber <= End.RowNumber))
		{
			return FString();
		}

		FString Result;
		int32 DeltaRow = End.RowNumber - Start.RowNumber;

		if (DeltaRow > 0)
		{
			//加入首行
			Result.Append(&Codes[Start.RowNumber][Start.ColumnNumber]);
			Result.TrimStartAndEndInline();
			Result += TEXT(' ');
			
			//加入中间行
			for (int32 Row = Start.RowNumber + 1; Row < End.RowNumber; Row++)
			{
				FString TempStr = Codes[Row];
				TempStr.TrimStartAndEndInline();
				Result.Append(TempStr) += TEXT(' ');
			}
			//加入尾行
			FString TempStr(End.ColumnNumber, &Codes[End.RowNumber][0]);
			TempStr.TrimStartAndEndInline();
			Result.Append(TempStr);
		}
		else
		{
			Result.Append(&Codes[Start.RowNumber][Start.ColumnNumber], End.ColumnNumber - Start.ColumnNumber);
		}
		Result.TrimStartAndEndInline();
		
		return Result;
	}

	//获得被括号包裹的字符串的前后位置, Start为开始寻找的位置
	static bool GetPositionOfStrWrappedByBraces(PosHelper& Start, PosHelper& End, const TArray<FString>& Codes)
	{
		if (!Helper::IsValidIndex(Codes, Start))
		{
			return false;
		}
		PosHelper CurrentPos = Start;
		std::stack<TCHAR> BracesStack;
		//查找第一个圆括号或花括号的位置
		while (true)
		{
			TCHAR Ch = Codes[CurrentPos.RowNumber][CurrentPos.ColumnNumber];
			if (Ch == TEXT('(') || Ch == TEXT('{'))
			{
				BracesStack.push(Ch);
				break;
			}
			else if(!Helper::Increment(Codes, CurrentPos))
			{
				return false;
			}
		}
		Start = CurrentPos;
		if (!Helper::Increment(Codes, CurrentPos))
		{
			return false;
		}

		//查找与TempStart指向的括号成对的括号的位置
		//int32 LeftBraceNumber = 1;
		while (true)
		{
			TCHAR Ch = Codes[CurrentPos.RowNumber][CurrentPos.ColumnNumber];

			if (Ch == TEXT('(') || Ch == TEXT('{'))
			{
				BracesStack.push(Ch);
			}
			else if (Ch == TEXT(')'))
			{
				if (BracesStack.size() > 0 && BracesStack.top() == TEXT('('))
				{
					BracesStack.pop();
					if (BracesStack.size() == 0)
					{
						End = CurrentPos;
						return true;
					}
				}
				else
				{//括号不匹配
					return false;
				}
			}
			else if (Ch == TEXT('}'))
			{
				if (BracesStack.size() > 0 && BracesStack.top() == TEXT('{'))
				{
					BracesStack.pop();
					if (BracesStack.size() == 0)
					{
						End = CurrentPos;
						return true;
					}
				}
				else
				{//括号不匹配
					return false;
				}
			}

			if (!Helper::Increment(Codes, CurrentPos))
			{
				return false;
			}
		}
	}

	static FString GetLastSubstrWrappedByWSFromString(FString& Str)
	{
		bool bStartRecord = false;
			
		int32 Start = 0;
		int32 End = Str.Len();
		for (int32 I = Str.Len() - 1; I >= 0; I--)
		{
			TCHAR Ch = Str[I];
			if (FChar::IsWhitespace(Ch))
			{
				if (bStartRecord)
				{
					Start = I + 1;
					break;
				}
			}
			else
			{
				if(!bStartRecord)
				{
					bStartRecord = true;
					End = I + 1;
				}
			}
		}

		FString Result(End - Start, &Str[Start]);
		Str.RemoveAt(Start, Str.Len() - Start);
		return Result;
	}

	//给定 子串 某一个字符 的位置即可
	static void RemoveSubstrWrappedByWS(int32 Pos, FString& Str)
	{
		int32 Start = 0;
		int32 End = Str.Len();

		// "a xxxxx b"
		//   ↑     ↑
		// start  end
		for (int32 I = Pos; I >= 0; I--)
		{
			TCHAR Ch = Str[I];
			if (FChar::IsWhitespace(Ch))
			{
				Start = I;
				break;
			}
		}

		for (int32 I = Pos; I < Str.Len(); I++)
		{
			TCHAR Ch = Str[I];
			if (FChar::IsWhitespace(Ch))
			{
				End = I;
				break;
			}
		}

		Str.RemoveAt(Start, End - Start);
	}

	static bool IsSpecifiedStringAtSpecifiedPos(const FString& InStr, PosHelper Start, const TArray<FString>& Codes)
	{
		if (Helper::IsValidIndex(Codes, Start))
		{
			const FString& ComparedStr = Codes[Start.RowNumber];
			int32 I = 0;
			for (; ComparedStr.IsValidIndex(I + Start.ColumnNumber) && I < InStr.Len(); I++)
			{
				if (InStr[I] != ComparedStr[I + Start.ColumnNumber])
				{
					return false;
				}
			}

			if (I < InStr.Len())
			{
				return false;
			}
			return true;
		}
		return false;
	}
	
	constexpr static int32 UETypePrefixNumber = 2;
	static TCHAR UETypePrefix[UETypePrefixNumber];
	
	static bool ResolveFunctionParameter(const FString& ParamStr, FParamElement& ParamElement)
	{
		FString TempStr = ParamStr;
		int32 Pos = -1;

		if (Helper::FindString(TEXT("const"), TempStr, Pos))
		{
			ParamElement.bConst = true;
			TempStr.RemoveAt(Pos, 5);
		}

		if (Helper::FindString(TEXT("*"), TempStr, Pos))
		{
			ParamElement.bPtr = true;
			TempStr.RemoveAt(Pos);
		}

		if (Helper::FindString(TEXT("&"), TempStr, Pos))
		{
			ParamElement.bRef = true;
			TempStr.RemoveAt(Pos);
		}

		FString Left, Right;
		TempStr.TrimStartAndEndInline();
		TempStr.Split(TEXT(" "), &Left, &Right, ESearchCase::CaseSensitive, ESearchDir::FromEnd);

		Right.TrimStartAndEndInline();
		if (Right.IsEmpty())
		{
			ParamElement.Name = TEXT("ReturnValue");
		}
		else
		{
			ParamElement.Name = *Right;
		}
		
		Left.TrimStartAndEndInline();
		if (Left.IsEmpty())
		{
			ParamElement.Type = *TempStr;
			Right = TempStr;
		}
		else
		{
			ParamElement.Type = *Left;
			Right = Left;
		}
		Right.TrimStartAndEndInline();

		bool bUObject = false;
		TCHAR Ch = Right[0];
		for (int32 I = 0; I < UETypePrefixNumber; I++)
		{
			if (Ch == UETypePrefix[I])
			{
				bUObject = true;
			}
		}

		if (bUObject)
		{
			return ParamElement.bPtr;
		}
		else
		{
			return !ParamElement.bPtr;
		}

	}

	static bool ResolveUFunction(PosHelper& StartPos, const TArray<FString>& CppCodes, FClassAnalysis& ClassAnalysis)
	{
		if (!Helper::IsSpecifiedStringAtSpecifiedPos(TEXT("UFUNCTION"), StartPos, CppCodes))
		{
			return false;
		}

		FFunctionAnalysis FunctionAnalysis;
		PosHelper LeftIndex = StartPos;
		PosHelper RightIndex;

		//解析元数据
		{
			FString UFunctionMetaStr;
			if (Helper::GetPositionOfStrWrappedByBraces(LeftIndex, RightIndex, CppCodes))
			{
				UFunctionMetaStr = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);
			}
			else
			{
				return false;
			}

			StartPos = RightIndex;

			if (UFunctionMetaStr.Contains(TEXT("Meta"), ESearchCase::CaseSensitive))//如果包含元数据，则进一步解析
			{
				if (Helper::Increment(CppCodes, LeftIndex))
				{
					if (Helper::GetPositionOfStrWrappedByBraces(LeftIndex, RightIndex, CppCodes))
					{
						UFunctionMetaStr = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);
					}

					if (UFunctionMetaStr.Contains(TEXT("CodeType"), ESearchCase::CaseSensitive))//如果包含CodeType，则进一步解析
					{
						if (UFunctionMetaStr.Contains(TEXT("Description"), ESearchCase::CaseSensitive))
						{
							FunctionAnalysis.CodeType = TEXT("Description");
						}
						else if (UFunctionMetaStr.Contains(TEXT("Event"), ESearchCase::CaseSensitive))
						{
							FunctionAnalysis.CodeType = TEXT("Event");
						}
					}
				}
				else
				{
					return false;
				}

			}	
		}
		
		//当前位置信息
		{
			LeftIndex = StartPos;
			if (!Helper::Increment(CppCodes, LeftIndex))
			{
				return false;
			}

			RightIndex = Helper::FindString(LeftIndex, CppCodes, TEXT(";"));
			if (!RightIndex.IsValid())
			{
				RightIndex = Helper::FindString(LeftIndex, CppCodes, TEXT("{"));
				if (!RightIndex.IsValid())
				{
					return false;
				}
				StartPos = RightIndex;
			}
		}

		//解析函数
		{
			//将多行合为一行
			PosHelper LeftBrace, RightBrace;
			LeftBrace = LeftIndex;

			FString FirstStr, SecondStr, ThirdStr, TempStr;

			if (Helper::GetPositionOfStrWrappedByBraces(LeftBrace, RightBrace, CppCodes))
			{
				//将函数的声明切为三段
				FirstStr = Helper::GetStringFromMultirow(LeftIndex, LeftBrace, CppCodes);
				Helper::Increment(CppCodes, LeftBrace);
				SecondStr = Helper::GetStringFromMultirow(LeftBrace, RightBrace, CppCodes);
				Helper::Increment(CppCodes, RightBrace);
				ThirdStr = Helper::GetStringFromMultirow(RightBrace, RightIndex, CppCodes);
			}
			else
			{
				return false;
			}

			//FirstStr
			{
				if (FirstStr.Contains(TEXT("virtual"), ESearchCase::CaseSensitive))
				{
					FunctionAnalysis.bVirtual = true;
					FirstStr.RemoveFromStart(TEXT("virtual"));
				}
				else
				{//虚函数不能是静态函数
					if (FirstStr.Contains(TEXT("static"), ESearchCase::CaseSensitive))
					{
						FunctionAnalysis.bStatic = true;
						FirstStr.RemoveFromStart(TEXT("static"));
					}
				}

				//移除XXX_API
				int32 TempPos = FirstStr.Find(TEXT("_API"), ESearchCase::CaseSensitive);
				if (TempPos != INDEX_NONE)
				{
					Helper::RemoveSubstrWrappedByWS(TempPos, FirstStr);
				}

				//函数名
				TempStr = Helper::GetLastSubstrWrappedByWSFromString(FirstStr);
				TempStr.TrimStartAndEndInline();
				FunctionAnalysis.FunctionName = FName(TempStr);

				//返回值
				FParamElement ReturnValue;

				if (!Helper::ResolveFunctionParameter(FirstStr, ReturnValue))
				{
					return false;
				}

				FunctionAnalysis.Return = ReturnValue;
			}
			
			//SecondStr
			{
				TArray<FString> ParamsStr;
				SecondStr.ParseIntoArray(ParamsStr, TEXT(","));

				for (auto& TempParamStr : ParamsStr)
				{
					FParamElement Param;
					if (!Helper::ResolveFunctionParameter(TempParamStr, Param))
					{
						return false;
					}
					FunctionAnalysis.Params.Add(MoveTempIfPossible(Param));
				}
			}

			//ThirdStr
			{
				//解析函数声明尾部说明符
				if (ThirdStr.Contains(TEXT("const"), ESearchCase::CaseSensitive))
				{
					FunctionAnalysis.bConst = true;
				}
			}
			
			ClassAnalysis.Functions.Add(MoveTempIfPossible(FunctionAnalysis));
		}

		return true;
	}

	static bool ResolveUProperty(PosHelper& StartPos, const TArray<FString>& CppCodes, FClassAnalysis& ClassAnalysis)
	{
		if (!Helper::IsSpecifiedStringAtSpecifiedPos(TEXT("UPROPERTY"), StartPos, CppCodes))
		{
			return false;
		}
		FVariableAnalysis VariableAnalysis;
		PosHelper LeftIndex = StartPos;
		PosHelper RightIndex;

		//解析元数据
		{
			FString UPropertyStr;
			if (Helper::GetPositionOfStrWrappedByBraces(LeftIndex, RightIndex, CppCodes))
			{
				UPropertyStr = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);
			}
			else
			{
				return false;
			}

			Helper::Increment(CppCodes, LeftIndex);			
			StartPos = RightIndex;
			if (!Helper::Increment(CppCodes, StartPos))
			{
				return false;
			}

			if (UPropertyStr.Contains(TEXT("Meta"), ESearchCase::CaseSensitive))
			{
				UPropertyStr = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);
				if (UPropertyStr.Contains(TEXT("CodeType"), ESearchCase::CaseSensitive) && UPropertyStr.Contains(TEXT("Resources"), ESearchCase::CaseSensitive))
				{
					VariableAnalysis.CodeType = TEXT("Resources");
				}
			}

			
		}

		//解析成员变量
		{
			LeftIndex = StartPos;

			//int a = { 1};
			RightIndex = Helper::FindString(LeftIndex, CppCodes, TEXT(";"));

			if (!RightIndex.IsValid())
			{
				return false;
			}

			FString VariableDeclarationStr = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);

			if (VariableDeclarationStr.Contains(TEXT("static"), ESearchCase::CaseSensitive))
			{
				VariableAnalysis.bStatic = true;
				VariableDeclarationStr.RemoveFromStart(TEXT("static"));
			}

			int32 TempPos = -1;

			if (!VariableDeclarationStr.FindChar(TEXT('='), TempPos))
			{
				VariableDeclarationStr.FindChar(TEXT('{'), TempPos);
			}

			if (TempPos != INDEX_NONE)
			{
				VariableDeclarationStr.RemoveAt(TempPos, VariableDeclarationStr.Len() - TempPos);
			}

			if (!Helper::ResolveFunctionParameter(VariableDeclarationStr, VariableAnalysis))
			{
				return false;
			}
			
		}

		ClassAnalysis.Variables.Add(MoveTempIfPossible(VariableAnalysis));

		return true;
	}

	static bool ResolveUClassBlock(PosHelper& CurrentPos, const TArray<FString>& CppCodes, FClassAnalysis& ClassAnalysis)
	{
		if (!Helper::IsSpecifiedStringAtSpecifiedPos(TEXT("UCLASS"), CurrentPos, CppCodes))
		{
			return false;
		}
		PosHelper LeftIndex = CurrentPos;
		PosHelper RightIndex;

		//获得类说明符
		{		
			if (!Helper::GetPositionOfStrWrappedByBraces(LeftIndex, RightIndex, CppCodes))
			{
				return false;
			}

			Helper::Increment(CppCodes, LeftIndex);
			ClassAnalysis.ClassDeclarator = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);
			ClassAnalysis.ClassDeclarator.TrimStartAndEndInline();
			LeftIndex = RightIndex;
		}

		//获取的类名及继承类名
		{			
			if (!Helper::Increment(CppCodes, LeftIndex))
			{
				return false;
			}

			RightIndex = Helper::FindString(LeftIndex, CppCodes, TEXT("{"));

			if (!RightIndex.IsValid())
			{
				return false;
			}

			CurrentPos = RightIndex;//记录左花括号位置，以便后续解析

			FString ClassDeclarationBlock = Helper::GetStringFromMultirow(LeftIndex, RightIndex, CppCodes);

			//对类声明块做出处理
			TArray<FString> StrArray;
			int32 StrNum = ClassDeclarationBlock.ParseIntoArray(StrArray, TEXT(":"));		
			{
				//获得类名
				StrArray[0].TrimEndInline();
				int32 ClassNamePos;
				StrArray[0].FindLastChar(TEXT(' '), ClassNamePos);
				ClassAnalysis.ClassName = FName(FString(&StrArray[0][ClassNamePos + 1]));

				if (StrNum == 2)
				{
					//获得类继承父类名
					TArray<FString> InheritName;
					const TCHAR* Delims[1] = { TEXT(",") };
					StrArray[1].ParseIntoArray(InheritName, Delims, 1);

					for (auto& TempName : InheritName)
					{
						TempName.TrimEndInline();
						int32 CharPos;
						TempName.FindLastChar(TEXT(' '), CharPos);
						if (!TempName.IsEmpty())
						{
							ClassAnalysis.ParentName.Add(FName(*TempName + CharPos + 1));
						}
					}
				}
			}

			LeftIndex = RightIndex;
		}

		//找到GENERATED_BT_BODY(...)
		{
			do
			{
				//寻找GENERATED_BT_BODY
				//LeftIndex.ColumnNumber = CppCodes[LeftIndex.RowNumber].Find(TEXT("GENERATED_BT_BODY"),ESearchCase::CaseSensitive,
				//	ESearchDir::FromStart, LeftIndex.ColumnNumber);
				LeftIndex.ColumnNumber = CppCodes[LeftIndex.RowNumber].Find(TEXT("GENERATED_BT_BODY"), ESearchCase::CaseSensitive,
					ESearchDir::FromStart, LeftIndex.ColumnNumber);

				if (LeftIndex.IsValid())
				{
					//没有0行
					ClassAnalysis.CodeLine = LeftIndex.RowNumber + 1;
					return true;
				}

			}while(Helper::IncrementRow(CppCodes, LeftIndex));
		}
		return false;
	}

	static bool ResolveFunctionAndPropertyBlock(PosHelper& StartPos, const TArray<FString>& CppCodes, FClassAnalysis& ClassAnalysis)
	{
		if (!Helper::IsValidIndex(CppCodes, StartPos))
		{
			return false;
		}
	
		if (CppCodes[StartPos.RowNumber].FindChar(TEXT('{'), StartPos.ColumnNumber))
		{
			int32 LeftBracketNumber = 1;

			std::stack<TCHAR> BracketStack;
			BracketStack.push(TEXT('{'));

			PosHelper CurrentPos = StartPos;

			if (!Helper::Increment(CppCodes, CurrentPos))
			{
				return false;
			}

			//while (Helper::IsValidIndex(CppCodes, CurrentPos))
			do
			{
				PosHelper TempPos = CurrentPos;
				const FString& TempStr = CppCodes[TempPos.RowNumber];

				TempPos.ColumnNumber = TempStr.Find(TEXT("UFUNCTION"), ESearchCase::CaseSensitive, 
					ESearchDir::FromStart, CurrentPos.ColumnNumber);

				if(TempPos.IsValid())
				{
					if (Helper::ResolveUFunction(TempPos, CppCodes, ClassAnalysis))
					{
						CurrentPos = TempPos;
						continue;//成功解析，则进行下一轮解析
					}
					else
					{
						return false;
					}
				}

				TempPos.ColumnNumber = TempStr.Find(TEXT("UPROPERTY"), ESearchCase::CaseSensitive, 
					ESearchDir::FromStart, CurrentPos.ColumnNumber);

				if (TempPos.IsValid())
				{			
					if (Helper::ResolveUProperty(TempPos, CppCodes, ClassAnalysis))
					{
						CurrentPos = TempPos;
						continue;//成功解析，则进行下一轮解析
					}
					else
					{
						return false;
					}
				}
				
				TempPos.ColumnNumber = TempStr.Find(TEXT("{"), ESearchCase::CaseSensitive,
					ESearchDir::FromStart, CurrentPos.ColumnNumber);
				
				if (TempPos.IsValid())
				{
					LeftBracketNumber++;
					BracketStack.push(TEXT('{'));
					if (Helper::Increment(CppCodes, TempPos))
					{
						CurrentPos = TempPos;
						continue;//成功解析，则进行下一轮解析
					}
					else
					{
						return false;
					}
				}

				TempPos.ColumnNumber = TempStr.Find(TEXT("}"), ESearchCase::CaseSensitive, 
					ESearchDir::FromStart, CurrentPos.ColumnNumber);
				
				if (TempPos.IsValid())
				{
					if (LeftBracketNumber > 0)
					{
						LeftBracketNumber--;
						if (LeftBracketNumber == 0)
						{
							StartPos = TempPos;
							return true;
						}
						else
						{
							if (Helper::Increment(CppCodes, TempPos))
							{
								CurrentPos = TempPos;
								continue;//成功解析，则进行下一轮解析
							}
						}
					}
					return false;
				}

				Helper::IncrementRow(CppCodes, CurrentPos);

			}while(Helper::IsValidIndex(CppCodes, CurrentPos));
		}

		return false;
	}

};
/*	具有UFUNCTION的合法的参数
*	UObject类及派生类：UObject* UObject*& 其他不合法, 指针只能用于UObject类及派生类
*	其他如FString类: const FString& 等按引用和按值传递
* 
*	具有UPROPERTY的合法的参数
*	和UFUNCTION类似, 但不支持const属性
*/

TCHAR Helper::UETypePrefix[] = {TEXT('A'), TEXT('U')};


class FUnrealTypeCollection : public IUTC
{
public:
	virtual bool Collect(const FString& Path, TArray<FClassAnalysis>& ClassAnalysis) override
	{
		// 读取源文件
		if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Path))
		{
			return false;
		}
		TArray<FString> CodeArray;
		FFileHelper::LoadANSITextFileToStrings(*Path, nullptr, CodeArray);

		//先把注释和空行处理了		
		{
			for (int32 I = 0; I < CodeArray.Num(); I++)
			{
				//if (!CodeArray.IsValidIndex(I))//有时是非法字符串？
				//{
				//	continue;
				//}

				FString& Str = CodeArray[I];
				if (Str.IsEmpty())
				{
					continue;
				}

				//检查是否有注释符号
				int32 CommentaryPos = Helper::CheckCommentary(Str);
				if (CommentaryPos != INDEX_NONE)
				{
					if (Str.Find(TEXT("//"), ESearchCase::CaseSensitive, ESearchDir::FromStart, CommentaryPos) != INDEX_NONE)
					{
						Str.RemoveAt(CommentaryPos, Str.Len() - CommentaryPos);
					}
					else
					{
						PosHelper TempEnd = Helper::FindString(PosHelper{ I, CommentaryPos }, CodeArray, TEXT("*/"));
						if (TempEnd.RowNumber == CommentaryPos)
						{
							Str.RemoveAt(CommentaryPos, TempEnd.ColumnNumber - CommentaryPos + 2);
						}
						else
						{
							//移除第一行
							Str.RemoveAt(CommentaryPos, Str.Len() - CommentaryPos);
							I++;

							for (; I < TempEnd.RowNumber; I++)
							{
								CodeArray[I].Empty();
							}

							//移除最后一行
							Str.RemoveAt(0, TempEnd.ColumnNumber);
						}
					}
				}
			}
			
			CodeArray.RemoveAll([](const FString& Str) -> bool {return Str.IsEmpty(); });
		}
		
		//开始解析
		{
			PosHelper CurrentPos{ 0,0 };//重要信息, 定位当前解析的位置

			do
			{
				const FString& CurrentRowStr = CodeArray[CurrentPos.RowNumber];

				//找到UCLASS的位置, 每找到一个直接处理完
				CurrentPos.ColumnNumber = CurrentRowStr.Find(TEXT("UCLASS"), ESearchCase::CaseSensitive,
					ESearchDir::FromStart, CurrentPos.ColumnNumber);

				if (CurrentPos.IsValid())
				{
					FClassAnalysis ClassAnalysisTemp;

					//ResolveUClassBlock解析UCLASS(...)和GENERATED_BT_BODY(...)
					//ResolveFunctionAndPropertyBlock(...)解析UFUNCTION和UPROPERTY(...)
					if (Helper::ResolveUClassBlock(CurrentPos, CodeArray, ClassAnalysisTemp))
					{
						//解析失败,说明源码编写有问题,没有属性和方法不会导致失败
						if (Helper::ResolveFunctionAndPropertyBlock(CurrentPos, CodeArray, ClassAnalysisTemp))
						{
							if (CodeArray[CurrentPos.RowNumber][CurrentPos.ColumnNumber] == TEXT('}'))
							{
								PosHelper TempPos = Helper::FindString(CurrentPos, CodeArray, TEXT(";"));
								Helper::Increment(CodeArray, TempPos);
								if (TempPos.IsValid())
								{
									CurrentPos = TempPos;
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}

							ClassAnalysis.Add(MoveTempIfPossible(ClassAnalysisTemp));
							continue;
						}
					}

					return false;
				}
				Helper::IncrementRow(CodeArray, CurrentPos);
			} while (Helper::IsValidIndex(CodeArray, CurrentPos));
		}
		return true;
	}
};

class FUnrealTypeBuilder : public IUTB
{
private:

	void GenerateVMFunction(TArray<FString>& AnalysisRaw, const FClassAnalysis& ClassAnalysis, const FString& FileID, TArray<FString>& StaticRegistration)
	{
		FStringFormatOrderedArguments FormatArgs;

		// Z_BT_USimpleCodeLibrary
		FString MClassName = TEXT("Z_BT_") + ClassAnalysis.ClassName.ToString();

		// " #define Z_BT_USimpleCodeLibrary \ ", 没有函数则不需要反斜杠
		AnalysisRaw.Add(TEXT("#define ") + MClassName + ((ClassAnalysis.Functions.Num() > 0) ? TEXT(" \\") : TEXT("")));

		//类名, 去除U、A等
		FString PureClassName = ClassAnalysis.ClassName.ToString();
		{
			PureClassName.TrimStartAndEndInline();
			PureClassName.RemoveAt(0);
		}

		if (ClassAnalysis.Functions.Num() > 0)
		{
			for (const auto& Function : ClassAnalysis.Functions)
			{
				if (!Function.bStatic)
				{
					continue;
				}
				if (Function.CodeType == TEXT("Event"))
				{
					continue;
				}

				//BT_VM_Func_Declaration(Func)
				//BT_VM_Func_Definition(Class, Func) 
				FString VMCFunctionName = TEXT("VMC_") + Function.FunctionName.ToString();
				AnalysisRaw.Add(TEXT("BT_VM_Func_Declaration(") + VMCFunctionName + TEXT(") \\"));
				AnalysisRaw.Add(TEXT("{ \\"));

				//1.有返回值
				//2.有参数
				//3.有返回值也有参数

				FString FuncReturn;

				if (Function.Return.Type != TEXT("void"))
				{
					FuncReturn = Function.Return.Type.ToString() + TEXT("*");
					if (Function.Return.bPtr && Function.Return.bRef)		// UObject*& -> *(UObject**)RefData
					{
						//直接拷贝
						FuncReturn = (TEXT("*(") + FuncReturn + TEXT("*)"));
					}
					else if (!Function.Return.bPtr && !Function.Return.bRef)
					{
						FuncReturn = (TEXT("*(") + FuncReturn + TEXT(")"));
					}
					else
					{
						if (Function.Return.bRef)
						{
							// FString& -> *(FString*)RefData
							FuncReturn = (TEXT("*(") + FuncReturn + TEXT(")"));
						}
						else
						{
							FuncReturn = (TEXT("*(") + FuncReturn + TEXT("*)"));
						}
					}

					FuncReturn += TEXT(" RefData = ");
				}

				if (Function.bStatic)
				{
					FuncReturn = TEXT("\t") + FuncReturn +
						(ClassAnalysis.ClassName.ToString() + TEXT("::") + Function.FunctionName.ToString() + TEXT("("));
				}

				if (Function.Params.Num() > 0)
				{
					for (const auto& Variable : Function.Params)
					{
						FString ParamType = Variable.Type.ToString();
						FString CastType;
						bool bUObject = false;
						if (Helper::IsUObject(ParamType))
						{
							bUObject = true;
						}

						if (Variable.bPtr && Variable.bRef)
						{
							ParamType += TEXT("**");
							CastType = TEXT("(") + ParamType + TEXT(")");
						}
						else if (!Variable.bPtr && !Variable.bRef)
						{
							CastType += (TEXT("*(") + ParamType + TEXT("*)"));
						}
						else
						{
							ParamType += TEXT("*");

							CastType = FString(bUObject ? TEXT("*(") : TEXT("(")) + ParamType
								+ (bUObject ? TEXT("*)") : TEXT(")"));
						}

						FString ParamName = TEXT("Z_") + Variable.Name.ToString() + TEXT("_Name");

						FString StackFunc = TEXT(" Stack.GetParamAddr(); \\");

						// (UObject*) Z_Context_Name =  *(UObject*)
						AnalysisRaw.Add(
							FString(TEXT("\t")) +
							ParamType +
							TEXT(" ") +
							ParamName +
							TEXT(" = ") +
							CastType +
							StackFunc
						);

						if (Variable.bRef)
						{
							//*Z_Context_Name
							ParamName = TEXT("*") + ParamName;
						}

						// \t*(FString*) RefData = &USimpleLibrary::Hello1(*Z_Context_Name, 
						FuncReturn += (ParamName + TEXT(", "));
					}

					// \t*(FString*) RefData = USimpleLibrary::Hello1(Z_Context_Name, Z_A_Name, Z_B_Name, Z_C_Name	
					// Z_Context_Name, Z_A_Name, Z_B_Name, Z_C_Name	
					FuncReturn.RemoveAt(FuncReturn.Find(TEXT(","), ESearchCase::CaseSensitive, ESearchDir::FromEnd));
					FuncReturn.TrimEndInline();
				}

				FuncReturn += TEXT("); \\");
				AnalysisRaw.Add(MoveTempIfPossible(FuncReturn));

				AnalysisRaw.Add(TEXT("} \\"));

				FormatArgs.Empty(FormatArgs.Max());//不至于重复去除
				FormatArgs.Add(PureClassName);
				FormatArgs.Add(Function.FunctionName.ToString());
				FormatArgs.Add(ClassAnalysis.ClassName.ToString());
				FormatArgs.Add(VMCFunctionName);

				if (Function.CodeType == TEXT("Description"))
				{
					StaticRegistration.Add(
						FString::Format(TEXT("\tFFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT(\"{0}\"), TEXT(\"{1}\"), {2}::{3}));"),
							FormatArgs)
					);
				}
			}
			AnalysisRaw[AnalysisRaw.Num() - 1].RemoveFromEnd(TEXT("\\"));
		}

		AnalysisRaw.Add(TEXT(""));
		AnalysisRaw.Add(FString::Printf(TEXT("#define %s_%s_GENERATED_BODY_BT \\"), *FileID, *FString::FromInt(ClassAnalysis.CodeLine)));
		AnalysisRaw.Add(TEXT("Z_BT_") + ClassAnalysis.ClassName.ToString());
		AnalysisRaw.Add(TEXT(""));
	}

	//暂时只能处理单文件单个类
	void GenerateHeaderFile(TArray<FString>& AnalysisRaw, const FFileInfo& FileInfo, TArray<FString>& StaticRegistration)
	{
		check(FileInfo.ClassAnalysis.Num() <= 1);

		// 头文件预处理
		{
			AnalysisRaw.Add(TEXT("#pragma once"));
			AnalysisRaw.Add(TEXT(" "));
			AnalysisRaw.Add(TEXT("#include \"ScriptMacro.h\""));
			AnalysisRaw.Add(TEXT("#include \"BTScript.h\""));
			AnalysisRaw.Add(TEXT(" "));
		}

		for (auto& Temp : FileInfo.ClassAnalysis)
		{
			GenerateVMFunction(AnalysisRaw, Temp, FileInfo.FileID, StaticRegistration);
		}

		AnalysisRaw.Add(FString("#undef CURRENT_FILE_ID_BT"));
		AnalysisRaw.Add(FString("#define CURRENT_FILE_ID_BT ") + FileInfo.FileID);


		AnalysisRaw.Add(FString("#undef NEWLINE"));
		if(FileInfo.ClassAnalysis.Num())
		{
			AnalysisRaw.Add(FString("#define ") + TEXT("NEWLINE ") + FString::FromInt(FileInfo.ClassAnalysis[0].CodeLine));
		}
		else
		{
			AnalysisRaw.Add(FString("#define ") + TEXT("NEWLINE "));
		}
	}

private:

	void GenerateClassSource(TArray<FString>& AnalysisRaw, const FClassAnalysis& ClassAnalysis)
	{
		FStringFormatOrderedArguments FormatArgs;
		if (ClassAnalysis.Functions.Num() > 0)
		{
			for (const auto& Function : ClassAnalysis.Functions)
			{
				if (Function.CodeType == "Event")
				{
					//Name_Hello
					FString FunctionName = TEXT("Name_") + Function.FunctionName.ToString();

					//TArray<FString> Params;
					auto GetParamStr = [&Function]()->FString
						{
							FString Result;

							for (auto& Param : Function.Params)
							{
								FString TempStr;
								if (Param.bConst)
								{
									TempStr = TEXT("const ");
								}
								TempStr += Param.Type.ToString();
								if (Param.bPtr)
								{
									TempStr += TEXT("*");
								}
								if (Param.bRef)
								{
									TempStr += TEXT("&");
								}
								Result += (TempStr + TEXT(" ") + Param.Name.ToString() + TEXT(", "));
							}
							Result.TrimStartAndEndInline();
							Result.RemoveFromEnd(TEXT(","));

							return Result;
						};

					FormatArgs.Empty(FormatArgs.Max());
					FormatArgs.Add(FunctionName);
					FormatArgs.Add(Function.FunctionName.ToString());
					AnalysisRaw.Add(FString::Format(TEXT("static FName {0} = FName(TEXT(\"{1}\"));"), FormatArgs));

					FormatArgs.Empty(FormatArgs.Max());
					FormatArgs.Add(ClassAnalysis.ClassName.ToString());
					FormatArgs.Add(Function.FunctionName.ToString());
					FormatArgs.Add(GetParamStr());

					AnalysisRaw.Add(FString::Format(TEXT("void {0}::{1}({2})"), FormatArgs));

					AnalysisRaw.Add(TEXT("{"));

					if (Function.Params.Num() > 0)
					{
						AnalysisRaw.Add(TEXT("\tTSharedPtr<FFunctionParameter> FunctionParameter = nullptr;"));

						for (auto& Temp : Function.Params)
						{
							FString AddParam;
							AddParam = Temp.Name.ToString();
							AnalysisRaw.Add(TEXT("\tAddParam(") + FString(TEXT("&")) + AddParam + TEXT(", FunctionParameter);"));
						}
					}
					AnalysisRaw.Add(TEXT("\tExecuteScript(FindScriptFunction(") + FunctionName + TEXT("), ") +
						TEXT("&FunctionParameter);"));
					AnalysisRaw.Add(TEXT("}"));

				}
				else if (Function.CodeType == "Description")
				{

				}
				else
				{
					return;
				}
			}
		}
	}

	void GenerateClassStatic(TArray<FString>& AnalysisRaw, const FClassAnalysis& ClassAnalysis, TArray<FString>& StaticRegistration)
	{
		//uint8 Register_USimpleCodeLibrary()
		FString RegisterFunctionStr = TEXT("Register_") + ClassAnalysis.ClassName.ToString() + TEXT("()");
		AnalysisRaw.Add(TEXT("uint8 ") + RegisterFunctionStr);
		AnalysisRaw.Add(TEXT("{"));
		{
			AnalysisRaw.Append(StaticRegistration);
			AnalysisRaw.Add(TEXT(""));
			AnalysisRaw.Add(TEXT("\treturn 0;"));
		}
		AnalysisRaw.Add(TEXT("}"));

		AnalysisRaw.Add(TEXT("static uint8 ") + ClassAnalysis.ClassName.ToString() + TEXT("_Index = ") + RegisterFunctionStr + TEXT(";"));
		AnalysisRaw.Add(TEXT(""));
	}

	void GenerateSourceFile(TArray<FString>& AnalysisRaw, const FFileInfo& FileInfo, TArray<FString>& StaticRegistration)
	{
		//定义头
		{
			AnalysisRaw.Add(TEXT("// Copyright Epic Games, Inc. All Rights Reserved."));
			AnalysisRaw.Add(TEXT("/*==========================================================================="));
			AnalysisRaw.Add(TEXT("	Generated code exported from UnrealHeaderTool."));
			AnalysisRaw.Add(TEXT("	DO NOT modify this manually! Edit the corresponding .h files instead!"));
			AnalysisRaw.Add(TEXT("===========================================================================*/"));
			AnalysisRaw.Add(TEXT(""));
			AnalysisRaw.Add(FString::Printf(TEXT("#include \"%s\""), *FileInfo.HeadInclude));
			AnalysisRaw.Add(TEXT("#include \"FunctionManage.h\""));
			AnalysisRaw.Add(TEXT("#include \"UObject/GeneratedCppIncludes.h\""));
			AnalysisRaw.Add(TEXT(""));
			AnalysisRaw.Add(TEXT("#ifdef _MSC_VER"));
			AnalysisRaw.Add(TEXT("#pragma warning (push)"));
			AnalysisRaw.Add(TEXT("#pragma warning (disable : 4883)"));
			AnalysisRaw.Add(TEXT("#endif"));
			AnalysisRaw.Add(TEXT(""));
			AnalysisRaw.Add(TEXT("PRAGMA_DISABLE_DEPRECATION_WARNINGS"));
		}

		for (auto& ClassAnalysis : FileInfo.ClassAnalysis)
		{
			//入口事件定义
			GenerateClassSource(AnalysisRaw, ClassAnalysis);
		}

		AnalysisRaw.Add(TEXT(""));
		AnalysisRaw.Add(TEXT("/* As an executable function pointer for global registration, we skip the UE"));
		AnalysisRaw.Add(TEXT("   UFunction local function registration because there is no bytecode in it.*/"));
		
		for (auto& ClassAnalysis : FileInfo.ClassAnalysis)
		{
			//静态注册
			GenerateClassStatic(AnalysisRaw, ClassAnalysis, StaticRegistration);
		}

		AnalysisRaw.Add(TEXT("PRAGMA_ENABLE_DEPRECATION_WARNINGS"));
		AnalysisRaw.Add(TEXT("#ifdef _MSC_VER"));
		AnalysisRaw.Add(TEXT("#pragma warning(pop)"));
		AnalysisRaw.Add(TEXT("#endif"));
	}
public:
	virtual bool Build(FFileInfo& FileInfo) override
	{
		TArray<FString> AnalysisRaw_HeaderFile;
		TArray<FString> AnalysisRaw_SourceFile;
		TArray<FString> StaticRegistration;

		GenerateHeaderFile(AnalysisRaw_HeaderFile, FileInfo, StaticRegistration);
		GenerateSourceFile(AnalysisRaw_SourceFile, FileInfo, StaticRegistration);

		
		FFileHelper::SaveStringArrayToFile(AnalysisRaw_HeaderFile, *(FileInfo.ReflectionDataHeadPaths));
		FFileHelper::SaveStringArrayToFile(AnalysisRaw_SourceFile, *(FileInfo.ReflectionDataSourcePaths));
	
		return true;
	}
};

bool CheckCode(const FString& Name)
{
	return Name.Contains(TEXT(".h"));
}
bool CheckFile(const FString& FileName)
{
	return FileName != "Intermediate";
}

void FindFileRecursive(TArray<FString>& CodePath, const FString& Paths, IFileManager& FileManager = IFileManager::Get())
{
	TArray<FString> FileName;
	FileManager.FindFiles(FileName, *(Paths/TEXT("*")), true, true);
	for (const FString& Name : FileName)
	{
		if (CheckCode(Name))
		{
			CodePath.Add(Paths/Name);
		}
		else if(CheckFile(Name))
		{
			FindFileRecursive(CodePath, Paths/Name);
		}
	}
}


void FConstructionManagement::Build(const FString& ProjectPath)
{
	//1.搜索所有的.h(项目内的）
	FString ProjectSourcePath = ProjectPath / TEXT("Source");
	FString ProjectPluginPath = ProjectPath / TEXT("Plugins");

	TArray<FString> AllCodePaths;
	FindFileRecursive(AllCodePaths, ProjectSourcePath);
	FindFileRecursive(AllCodePaths, ProjectPluginPath);

	//2.筛选符合条件的代码
	TArray<FString> QualifiedPaths;

	for (const FString& Path : AllCodePaths)
	{
		bool bIncludeReflectionPath = false;
		bool bInheritSimpleCode = false;
		bool bIncludeGeneratedMacro = false;
		bool bFunctionMeta = false;

		{
			TArray<FString> StatementArray;
			FFileHelper::LoadANSITextFileToStrings(*(Path), nullptr, StatementArray);
			for (auto& Statement : StatementArray)
			{
				if (Statement.Contains(".Reflect.h"))
				{
					bIncludeReflectionPath = true;
				}

				if (Statement.Contains("GENERATED_BT_BODY()"))
				{
					bIncludeGeneratedMacro = true;
				}

				if ("public USimpleCode")
				{
					bInheritSimpleCode = true;
				}

				if (Statement.Contains("UFUNCTION"))
				{
					if (Statement.Contains("Event") || Statement.Contains("Description") || Statement.Contains("PureDescription"))
					{
						bFunctionMeta = true;
					}
				}
			}
		}

		if (bIncludeReflectionPath && bInheritSimpleCode && bIncludeGeneratedMacro && bFunctionMeta)
		{
			QualifiedPaths.Add(Path);
		}
	
	}

	//3.生成反射数据的路径
	TArray<FFileInfo> FileInfos;

	for (FString& Path : QualifiedPaths)
	{
		Path.ReplaceCharInline(TEXT('\\'), TEXT('/'));
		//"D:/UEProject/TestSlate/EditorExtension/Plugins/BlueprintTool/Source/BlueprintToolCode/Public/SimpleCodeLibrary.h"
		FString Left, Right;
		if (Path.Contains(TEXT("/Public/")))
		{
			Path.Split(TEXT("/Public/"), &Left, &Right);
		}
		else
		{
			continue;
		}

		FFileInfo FileInfoElem;
		FileInfoElem.CodePaths = Path;

		//用于 #include "SimpleCodeLibrary.h"
		FileInfoElem.HeadInclude = Right;

		FileInfoElem.FileID = Path;
		FileInfoElem.FileID.RemoveAt(0, 3);
		FileInfoElem.FileID = TEXT("BT_FileID_") + FileInfoElem.FileID;
		FileInfoElem.FileID.ReplaceCharInline(TEXT('/'), TEXT('_'));
		FileInfoElem.FileID.ReplaceCharInline(TEXT('.'), TEXT('_'));

		FString L1, R1;
		Path.Split(TEXT("/"), &L1, &R1, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

		FString L2, R2;
		R1.Split(TEXT("."), &L2, &R2, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

		FileInfoElem.ReflectionDataSourcePaths = Left / TEXT("Public/ReflectionData") / L2 + TEXT(".Ref.cpp");
		FileInfoElem.ReflectionDataHeadPaths = Left / TEXT("Public/ReflectionData") / L2 + TEXT(".Reflect.h");
		FileInfos.Add(FileInfoElem);
		UE_LOG(LogReflectionGenerate, Display, TEXT("%s"), *FileInfoElem.CodePaths);
	}

	//4.生成反射数据的代码
	for (auto& FilePath : FileInfos)
	{
		FUnrealTypeCollection TypeCollection;
		TypeCollection.Collect(FilePath.CodePaths, FilePath.ClassAnalysis);

		FUnrealTypeBuilder TypeBuilder;
		TypeBuilder.Build(FilePath);
	}
	
}

#pragma optimize("", on)