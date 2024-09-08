#include "Style/BlueprintToolGraphStyle.h"
#include "Styling\SlateStyleRegistry.h"
#include "Interfaces\IPluginManager.h"
#include "Styling\SlateStyleMacros.h"

TSharedPtr<class FSlateStyleSet> FBPGraphStyle::StyleInstance = nullptr;

void FBPGraphStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FBPGraphStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

void FBPGraphStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

FName FBPGraphStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("BlueprintToolGraphStyleSet"));
	return StyleSetName;
}

const ISlateStyle& FBPGraphStyle::Get()
{
	return *StyleInstance;
}

const FVector2D Icon64x64(64.f, 64.f);
const FVector2D Icon32x32(32.f, 32.f);

TSharedRef<class FSlateStyleSet> FBPGraphStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("BlueprintTool")->GetBaseDir() / TEXT("Resources"));

	return Style;
}
