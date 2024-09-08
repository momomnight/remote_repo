
#pragma once

#include "CoreMinimal.h"
#include "Client/HTTPClient.h"


class SIMPLEHTTP_API FSimpleHttpManage
{
public:
	~FSimpleHttpManage();

	static TSharedRef<FSimpleHttpManage> Get();
	static void Destroy();

	bool GetObject(const FString& URL, const FString& SavePath);
	bool PutObject(const FString& URL, const TArray<uint8>& Bytes);
	bool PutObject(const FString& URL, const FString& String);
	bool PutObject(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);
	bool PutObject(const FString& URL, FHttpRequestStreamDelegate StreamDelegate);
	bool PutObject(const FString& URL, const FString& FileName, SimpleHTTP::HTTP::FileStream);
	bool DeleteObject(const FString& URL);

private:
	//ªÿµ˜
	void HttpRequestComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectSuccessfully);
	void HttpRequestProgress(FHttpRequestPtr InRequest, int32 BytesSent, int32 BytesReceived);
	void HttpRequestHeaderReceived(FHttpRequestPtr InRequest, const FString& HeaderName, const FString& NewHeaderValue);
	void HttpRequestWillRetry(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, float SecondsToRetry);
	
	//¥Ú”°≤‚ ‘
	void Print(const FString& Msg, float Time = 10.f, FColor Color = FColor::Red);

private:
	FSimpleHttpManage();
	FSimpleHttpManage(const FSimpleHttpManage&) = delete;
	FSimpleHttpManage& operator=(const FSimpleHttpManage&) = delete;

	static TSharedPtr<FSimpleHttpManage> HttpManage;

	FCriticalSection Mutex;
	FString TempSavePath;
};
