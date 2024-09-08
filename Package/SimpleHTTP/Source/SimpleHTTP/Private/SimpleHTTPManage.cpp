
#include "SimpleHTTPManage.h"
#include "Core/SimpleHTTPMacro.h"
#include "Interfaces/IHttpResponse.h"
#include "Misc\Paths.h"
#include "Misc\FileHelper.h"
#include "Engine\Engine.h"

using namespace SimpleHTTP;

TSharedPtr<FSimpleHttpManage> FSimpleHttpManage::HttpManage = nullptr;


FSimpleHttpManage::FSimpleHttpManage()
{
}

FSimpleHttpManage::~FSimpleHttpManage()
{
}

TSharedRef<FSimpleHttpManage> FSimpleHttpManage::Get()
{
	if (!HttpManage.IsValid())
	{
		HttpManage = MakeShareable(new FSimpleHttpManage);
	}
	return HttpManage.ToSharedRef();	
}

void FSimpleHttpManage::Destroy()
{
	if (HttpManage.IsValid())
	{
		HttpManage.Reset();
	}
}

bool FSimpleHttpManage::GetObject(const FString& URL, const FString& SavePath)
{
	TempSavePath = SavePath;//通过保存回调的代理使用
	HTTP::FHttpClient Client;
	HTTP::FGetObjectRequest Request(URL);

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.GetObject(Request);
}

bool FSimpleHttpManage::PutObject(const FString& URL, const TArray<uint8>& Bytes)
{
	HTTP::FHttpClient Client;
	HTTP::FPutObjectRequest Request(URL, Bytes);

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.PutObject(Request);
}

bool FSimpleHttpManage::PutObject(const FString& URL, const FString& String)
{
	HTTP::FHttpClient Client;
	HTTP::FPutObjectRequest Request(URL, String);

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.PutObject(Request);
}

bool FSimpleHttpManage::PutObject(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream)
{
	HTTP::FHttpClient Client;
	HTTP::FPutObjectRequest Request(URL, Stream);

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.PutObject(Request);
}

bool FSimpleHttpManage::PutObject(const FString& URL, FHttpRequestStreamDelegate StreamDelegate)
{
	HTTP::FHttpClient Client;
	HTTP::FPutObjectRequest Request(URL, StreamDelegate);

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.PutObject(Request);
}

bool FSimpleHttpManage::PutObject(const FString& URL, const FString& FileName, SimpleHTTP::HTTP::FileStream)
{
	HTTP::FHttpClient Client;
	HTTP::FPutObjectRequest Request(URL, FileName, SimpleHTTP::HTTP::FileStream());

	FHTTP_BIND_DELEGATE(Request, this, &FSimpleHttpManage::HttpRequestHeaderReceived,
		&FSimpleHttpManage::HttpRequestComplete, &FSimpleHttpManage::HttpRequestProgress,
		&FSimpleHttpManage::HttpRequestWillRetry);

	return Client.PutObject(Request);
}

bool FSimpleHttpManage::DeleteObject(const FString& URL)
{
	HTTP::FHttpClient Client;
	HTTP::FDeleteObjectRequest Request(URL);

	return Client.DeleteObject(Request);
}

void FSimpleHttpManage::HttpRequestComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectSuccessfully)
{
	if (InRequest.IsValid() && InResponse.IsValid() && bConnectSuccessfully 
		&& EHttpResponseCodes::IsOk(InResponse->GetResponseCode()))
	{	
		if (InRequest->GetVerb() == TEXT("GET"))
		{
			FString FileName = FPaths::GetCleanFilename(InRequest->GetURL());
			FFileHelper::SaveArrayToFile(InResponse->GetContent(), *(Get()->TempSavePath / FileName));
		}
		else if (InRequest->GetVerb() == TEXT("PUT"))
		{

		}
		else if (InRequest->GetVerb() == TEXT("DELETE"))
		{

		}
	
	}
}

void FSimpleHttpManage::HttpRequestProgress(FHttpRequestPtr InRequest, int32 BytesSent, int32 BytesReceived)
{
	if (InRequest.IsValid())
	{

	}
}

void FSimpleHttpManage::HttpRequestHeaderReceived(FHttpRequestPtr InRequest, const FString& HeaderName, const FString& NewHeaderValue)
{
}

void FSimpleHttpManage::HttpRequestWillRetry(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, float SecondsToRetry)
{
}

void FSimpleHttpManage::Print(const FString& Msg, float Time, FColor Color)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, Time, Color, Msg);
	}
}
