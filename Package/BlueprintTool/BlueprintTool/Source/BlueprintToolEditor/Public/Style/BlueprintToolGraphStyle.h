#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FBPGraphStyle
{
public:
	static void Initialize();
	static void ShutDown();
	static void ReloadTextures();
	static FName GetStyleSetName();
	static const class ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<class FSlateStyleSet> StyleInstance;

};
