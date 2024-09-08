
#pragma once
#include "Interfaces/IHttpRequest.h"

#define DEFINE_HTTP_TYPE(HttpRequest, Verb, URL, Content)\
HttpRequest->SetVerb(TEXT(Verb));\
HttpRequest->SetURL(URL);\
HttpRequest->SetHeader(TEXT("Content-Type"), TEXT(Content))

#define FHTTP_BIND_DELEGATE(Request, Object, Func1, Func2, Func3, Func4)\
Request\
<< FHttpRequestHeaderReceivedDelegate::CreateRaw(Object, Func1)\
<< FHttpRequestCompleteDelegate::CreateRaw(Object, Func2)\
<< FHttpRequestProgressDelegate::CreateRaw(Object, Func3)\
<< FHttpRequestWillRetryDelegate::CreateRaw(Object, Func4)
