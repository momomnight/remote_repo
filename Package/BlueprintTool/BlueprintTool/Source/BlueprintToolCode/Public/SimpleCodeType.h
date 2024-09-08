#pragma once


namespace UE5Code_Public
{
	struct FCodeType
	{
		const char* NameUtf;
	};

	enum ECodeType
	{
		Resource = 0,
		Event = 1,
		Description = 2,
	};
}

struct FBlueprintToolCode
{
	static const UE5Code_Public::FCodeType Meta_Data[];
};

const UE5Code_Public::FCodeType FBlueprintToolCode::Meta_Data[] =
{
	{"Resource"},
	{"Event"},
	{"Description"},
};