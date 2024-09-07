// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReflectionGenerate.h"
#include "RequiredProgramMainCPPInclude.h"
#include "CustomizedUBTUHT.h"
#include "Macro.h"

IMPLEMENT_APPLICATION(ReflectionGenerate, "ReflectionGenerate");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	FTaskTagScope Scope(ETaskTag::EGameThread);
	ON_SCOPE_EXIT
	{ 
		LLM(FLowLevelMemTracker::Get().UpdateStatsPerFrame());
		RequestEngineExit(TEXT("Exiting"));
		FEngineLoop::AppPreExit();
		FModuleManager::Get().UnloadModulesAtShutdown();
		FEngineLoop::AppExit();
	};

	if (int32 Ret = GEngineLoop.PreInit(ArgC, ArgV))
	{
		return Ret;
	}

	FString ProjectPath;
	for (int32 i = 0; i < ArgC; i++)
	{
		FString Args = ArgV[i];
		FString Left, Right;

		Args.Split(TEXT("="), &Left, &Right);

		if (Left == TEXT("ProjectPath"))
		{
			ProjectPath = Right;
		}
		UE_LOG(LogReflectionGenerate, Display, TEXT("%s"), ArgV[i]);
	}

	if (ProjectPath.IsEmpty())
	{
		UE_LOG(LogReflectionGenerate, Error, TEXT("Need Project Path."));
	}
	else
	{
		FConstructionManagement ConstructionManagement;
		ConstructionManagement.Build(ProjectPath);
	}

	return 0;
}
