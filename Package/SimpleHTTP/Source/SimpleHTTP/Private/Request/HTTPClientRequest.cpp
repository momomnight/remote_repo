
#include "Request/HTTPClientRequest.h"
#include "Core/SimpleHTTPMacro.h"
#include "Interfaces\IHttpRequest.h"
#include "Serialization\Archive.h"

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString& URL, const FString& ContentString)
{
	//Verb	URL	 HttpVersion
	//host: 域名
	//Content-Type: Body中的数据格式、字符集
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

//GET:从服务器获取资源
//POST:在服务器新建一个资源
//PUT:在服务器更新资源（客户端提供改变后的完整资源）
//PATCH:在服务器更新资源（客户端提供改变的属性）
//DELETE:从服务器删除资源
//HEAD:获取资源的元数据
//OPTIONS:获取信息，关于资源的那些属性是客户端可以改变的
SimpleHTTP::HTTP::FGetObjectRequest::FGetObjectRequest(const FString& URL)
{
	//"application/x-www-from-urlencoded"设置通用请求属性为浏览器默认的编码类型
	DEFINE_HTTP_TYPE(HttpRequest, "GET", URL, "application/x-www-from-urlencoded");
}

SimpleHTTP::HTTP::FDeleteObjectRequest::FDeleteObjectRequest(const FString& URL)
{
	DEFINE_HTTP_TYPE(HttpRequest, "DELETE", URL, "application/x-www-from-urlencoded");
}
