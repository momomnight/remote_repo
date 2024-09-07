#include "SimpleOSSType.h"

SimpleOSS::OSS::FClientConfiguration::FClientConfiguration()
	:Scheme(SimpleOSS::OSS::EScheme::HTTP),
	 MaxConnections(16), RequestTimeoutMs(10000),
	 ConnectTimeoutMs(5000), ProxyScheme(SimpleOSS::OSS::EScheme::HTTP),
	 ProxyPort(0), bVerifySSL(false), bCname(false), bEnableCrc64(true),
	 bEnableDateSkewAdjustment(true), SendRateLimiter(nullptr),
	 RecvRateLimiter(nullptr), Executor(nullptr),HttpClient(nullptr),
	 bIsPathStyle(false),bIsVerifyObjectStrict(true),SignatureVersion(SimpleOSS::OSS::ESignatureVersionType::V1)
{
}
