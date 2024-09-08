
#include "Client/HTTPClient.h"

SimpleHTTP::HTTP::FHttpClient::FHttpClient()
{
}

bool SimpleHTTP::HTTP::FHttpClient::GetObject(FGetObjectRequest& InRequest) const
{
	return InRequest.ProcessRequest();
}

bool SimpleHTTP::HTTP::FHttpClient::DeleteObject(FDeleteObjectRequest& InRequest) const
{
	return InRequest.ProcessRequest();
}

bool SimpleHTTP::HTTP::FHttpClient::PutObject(FPutObjectRequest& InRequest) const
{
	return InRequest.ProcessRequest();
}

void SimpleHTTP::HTTP::FHttpClient::AbortRequest(IHTTPClientRequest& InRequest) const
{
	InRequest.CancelRequest();
}
