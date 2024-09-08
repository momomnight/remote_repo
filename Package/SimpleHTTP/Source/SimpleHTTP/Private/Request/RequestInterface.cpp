
#include "Request/RequestInterface.h"
#include "HttpModule.h"


SimpleHTTP::HTTP::IHTTPClientRequest::IHTTPClientRequest()
	:HttpRequest(FHttpModule::Get().CreateRequest())
{
}

SimpleHTTP::HTTP::IHTTPClientRequest&
	SimpleHTTP::HTTP::IHTTPClientRequest::operator<<(const FHttpRequestCompleteDelegate& InDelegate)
{
	// TODO: insert return statement here
	HttpRequest->OnProcessRequestComplete() = InDelegate;
	return *this;
}

SimpleHTTP::HTTP::IHTTPClientRequest&
	SimpleHTTP::HTTP::IHTTPClientRequest::operator<<(const FHttpRequestProgressDelegate& InDelegate)
{
	// TODO: insert return statement here
	HttpRequest->OnRequestProgress() = InDelegate;
	return *this;
}

SimpleHTTP::HTTP::IHTTPClientRequest&
	SimpleHTTP::HTTP::IHTTPClientRequest::operator<<(const FHttpRequestWillRetryDelegate& InDelegate)
{
	// TODO: insert return statement here
	HttpRequest->OnRequestWillRetry() = InDelegate;
	return *this;
}

SimpleHTTP::HTTP::IHTTPClientRequest&
	SimpleHTTP::HTTP::IHTTPClientRequest::operator<<(const FHttpRequestHeaderReceivedDelegate& InDelegate)
{
	// TODO: insert return statement here
	HttpRequest->OnHeaderReceived() = InDelegate;
	return *this;
}

bool SimpleHTTP::HTTP::IHTTPClientRequest::ProcessRequest()
{
	return HttpRequest->ProcessRequest();
}

void SimpleHTTP::HTTP::IHTTPClientRequest::CancelRequest()
{
	HttpRequest->CancelRequest();
}
