
#pragma once

#include "CoreMinimal.h"
#include "Request/HTTPClientRequest.h"

namespace SimpleHTTP
{
	namespace HTTP
	{
		struct SIMPLEHTTP_API FHttpClient 
		{
			FHttpClient();

			bool GetObject(FGetObjectRequest& InRequest) const;
			bool DeleteObject(FDeleteObjectRequest& InRequest) const;
			bool PutObject(FPutObjectRequest& InRequest) const;

			void AbortRequest(IHTTPClientRequest& InRequest) const;
		};
	}
}