
#pragma once
#include "CoreMinimal.h"
#include "Request/RequestInterface.h"

namespace SimpleHTTP
{
	namespace HTTP
	{
		struct SIMPLEHTTP_API FileStream{};

		struct SIMPLEHTTP_API FPutObjectRequest : IHTTPClientRequest
		{
			FPutObjectRequest(const FString& URL, const FString& ContentString);
			FPutObjectRequest(const FString& URL, const TArray<uint8>& ContentBytes);
			FPutObjectRequest(const FString& URL, TSharedRef<class FArchive, ESPMode::ThreadSafe>& ContentStream);
			FPutObjectRequest(const FString& URL, FHttpRequestStreamDelegate ContentStreamDelegate);
			FPutObjectRequest(const FString& URL, const FString& FileName, FileStream);
		};

		struct SIMPLEHTTP_API FGetObjectRequest : IHTTPClientRequest
		{
			FGetObjectRequest(const FString& URL);
		};

		struct SIMPLEHTTP_API FDeleteObjectRequest : IHTTPClientRequest
		{
			FDeleteObjectRequest(const FString& URL);
		};
	}
}