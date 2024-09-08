
#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"



namespace SimpleHTTP
{
	namespace HTTP
	{
		struct IHTTPClientRequest
		{
			friend struct FHttpClient;

			IHTTPClientRequest();

			IHTTPClientRequest& operator<<(const FHttpRequestCompleteDelegate& InDelegate);
			IHTTPClientRequest& operator<<(const FHttpRequestProgressDelegate& InDelegate);
			IHTTPClientRequest& operator<<(const FHttpRequestHeaderReceivedDelegate& InDelegate);
			IHTTPClientRequest& operator<<(const FHttpRequestWillRetryDelegate& InDelegate);

			

		protected:
			TSharedPtr<class IHttpRequest> HttpRequest;
			

			bool ProcessRequest();
			void CancelRequest();
		};
	}
}