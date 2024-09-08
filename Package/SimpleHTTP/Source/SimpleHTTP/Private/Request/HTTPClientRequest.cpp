
#include "Request/HTTPClientRequest.h"
#include "Core/SimpleHTTPMacro.h"
#include "Interfaces\IHttpRequest.h"
#include "Serialization\Archive.h"

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, const FString& ContentString)
{
	//Verb	URL	 HttpVersion
	//host: ����
	//Content-Type: Body�е����ݸ�ʽ���ַ���
	DEFINE_HTTP_TYPE(HttpRequest, "PUT", URL, "application/x-www-from-urlencoded");
	HttpRequest->SetContentAsString(ContentString);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, const TArray<uint8>& ContentBytes)
{
	DEFINE_HTTP_TYPE(HttpRequest, "PUT", URL, "application/x-www-from-urlencoded");
	HttpRequest->SetContent(ContentBytes);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, TSharedRef<FArchive, ESPMode::ThreadSafe>& ContentStream)
{
	DEFINE_HTTP_TYPE(HttpRequest, "PUT", URL, "application/x-www-from-urlencoded");
	HttpRequest->SetContentFromStream(ContentStream);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, FHttpRequestStreamDelegate ContentStreamDelegate)
{
	DEFINE_HTTP_TYPE(HttpRequest, "PUT", URL, "application/x-www-from-urlencoded");
	HttpRequest->SetContentFromStreamDelegate(ContentStreamDelegate);
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, const FString& FileName, FileStream)
{
	DEFINE_HTTP_TYPE(HttpRequest, "PUT", URL, "application/x-www-from-urlencoded");
	HttpRequest->SetContentAsStreamedFile(FileName);
}

//GET:�ӷ�������ȡ��Դ
//POST:�ڷ������½�һ����Դ
//PUT:�ڷ�����������Դ���ͻ����ṩ�ı���������Դ��
//PATCH:�ڷ�����������Դ���ͻ����ṩ�ı�����ԣ�
//DELETE:�ӷ�����ɾ����Դ
//HEAD:��ȡ��Դ��Ԫ����
//OPTIONS:��ȡ��Ϣ��������Դ����Щ�����ǿͻ��˿��Ըı��
SimpleHTTP::HTTP::FGetObjectRequest::FGetObjectRequest(const FString& URL)
{
	//"application/x-www-from-urlencoded"����ͨ����������Ϊ�����Ĭ�ϵı�������
	DEFINE_HTTP_TYPE(HttpRequest, "GET", URL, "application/x-www-from-urlencoded");
}

SimpleHTTP::HTTP::FDeleteObjectRequest::FDeleteObjectRequest(const FString& URL)
{
	DEFINE_HTTP_TYPE(HttpRequest, "DELETE", URL, "application/x-www-from-urlencoded");
}
