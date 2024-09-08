
#include "SimpleOSSManage.h"
#include "SimpleOSSMacro.h"
#include "alibabacloud/oss/client/ClientConfiguration.h"
#include <type_traits>
#include <memory>
#include <fstream>
#include <sstream>

#include "Engine/Engine.h"
#include "Async/AsyncWork.h"
#include "Async/TaskGraphInterfaces.h"
#include "Async/TaskGraphFwd.h"

using namespace AlibabaCloud;

class FOssAsyncTask : public FNonAbandonableTask
{
public:
	FOssAsyncTask(TFunction<void()> InFunction) : Function(InFunction){}

	void DoWork()
	{
		Function();
	}

	FORCEINLINE TStatId GetStatId()
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FOssAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

protected:
	TFunction<void()> Function;
};

TSharedPtr<FSimpleOSSManage> FSimpleOSSManage::OssManage = nullptr;

FSimpleOSSManage::FSimpleOSSManage()
{
}

FSimpleOSSManage::~FSimpleOSSManage()
{
}

TSharedRef<FSimpleOSSManage> FSimpleOSSManage::Get()
{
	if (!OssManage.IsValid())
	{
		OssManage = MakeShareable(new FSimpleOSSManage);
		if(!OSS::IsSdkInitialized())
		{
			OSS::InitializeSdk();
		}
	}

	return OssManage.ToSharedRef();
}

void FSimpleOSSManage::Destroy()
{
	if (OssManage.IsValid())
	{
		if (OSS::IsSdkInitialized())
		{
			OSS::ShutdownSdk();
		}	
		OssManage.Reset();
	}
}

struct FAuxiliaryTools
{
	static void Print(const std::string& Msg, float Time = 10.f, FColor Color = FColor::Red)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Time, Color, Msg.c_str());
		}
	}

	static void Print(const FString& Msg, float Time = 10.f, FColor Color = FColor::Red)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Time, Color, *Msg);
		}
	}

	static int64 GetFileSize(const std::string& InFilePath)
	{
		std::fstream fs(InFilePath, std::ios::in | std::ios::binary);
		fs.seekg(0, fs.end);
		int64 ret = fs.tellg();
		fs.close();
		return ret;
	}

	static constexpr AlibabaCloud::OSS::Http::Scheme ConvertToAlibabaScheme(SimpleOSS::OSS::EScheme SimpleScheme)
	{
		switch (SimpleScheme)
		{
		default:
		case SimpleOSS::OSS::EScheme::HTTP:
		{
			return AlibabaCloud::OSS::Http::Scheme::HTTP;
		}
		case SimpleOSS::OSS::EScheme::HTTPS:
		{
			return AlibabaCloud::OSS::Http::Scheme::HTTPS;
		}
		}
	}

	static constexpr AlibabaCloud::OSS::SignatureVersionType ConvertToAlibabaSignatureVersion(SimpleOSS::OSS::ESignatureVersionType SimpleSignatureVersion)
	{
		switch (SimpleSignatureVersion)
		{
		default:
		case SimpleOSS::OSS::ESignatureVersionType::V1:
		{
			return AlibabaCloud::OSS::SignatureVersionType::V1;
		}
		case SimpleOSS::OSS::ESignatureVersionType::V4:
		{
			return AlibabaCloud::OSS::SignatureVersionType::V4;
		}
		}
	}

	static constexpr AlibabaCloud::OSS::CannedAccessControlList ConvertToAlibabaAcl(SimpleOSS::OSS::EAcl SimpleAcl)
	{
		switch (SimpleAcl)
		{
		default:
		case SimpleOSS::OSS::EAcl::Acl_Private:
			return AlibabaCloud::OSS::CannedAccessControlList::Private;
		case SimpleOSS::OSS::EAcl::Acl_PublicRead:
			return AlibabaCloud::OSS::CannedAccessControlList::PublicRead;
		case SimpleOSS::OSS::EAcl::Acl_PublicReadWrite:
			return AlibabaCloud::OSS::CannedAccessControlList::PublicReadWrite;
		case SimpleOSS::OSS::EAcl::Acl_Default:
			return AlibabaCloud::OSS::CannedAccessControlList::Default;
		}
	}

	static constexpr SimpleOSS::OSS::EAcl ConvertToSimpleOssAcl(AlibabaCloud::OSS::CannedAccessControlList AlibabaAcl)
	{
		switch (AlibabaAcl)
		{
		case AlibabaCloud::OSS::Private:
			return SimpleOSS::OSS::EAcl::Acl_Private;
		case AlibabaCloud::OSS::PublicRead:
			return SimpleOSS::OSS::EAcl::Acl_PublicRead;
		case AlibabaCloud::OSS::PublicReadWrite:
			return SimpleOSS::OSS::EAcl::Acl_PublicReadWrite;
		case AlibabaCloud::OSS::Default:
			return SimpleOSS::OSS::EAcl::Acl_Default;
		default:
			return SimpleOSS::OSS::EAcl::Acl_None;
		}
	}

	static constexpr AlibabaCloud::OSS::RequestPayer ConvertToAlibabaPayerType(SimpleOSS::OSS::ERequestPayerType SimplePayerType)
	{
		switch (SimplePayerType)
		{
		default:
		case SimpleOSS::OSS::ERequestPayerType::PT_NotSet:
			return AlibabaCloud::OSS::RequestPayer::NotSet;
		case SimpleOSS::OSS::ERequestPayerType::PT_BucketOwner:
			return AlibabaCloud::OSS::RequestPayer::BucketOwner;
		case SimpleOSS::OSS::ERequestPayerType::PT_Requester:
			return AlibabaCloud::OSS::RequestPayer::Requester;
		}
	}

	static constexpr SimpleOSS::OSS::ERequestPayerType ConvertToSimpleOssPayerType(AlibabaCloud::OSS::RequestPayer AlibabaPayerType)
	{
		switch (AlibabaPayerType)
		{
		case AlibabaCloud::OSS::RequestPayer::NotSet:
			return SimpleOSS::OSS::ERequestPayerType::PT_NotSet;
		case AlibabaCloud::OSS::RequestPayer::BucketOwner:
			return SimpleOSS::OSS::ERequestPayerType::PT_BucketOwner;
		case AlibabaCloud::OSS::RequestPayer::Requester:
			return SimpleOSS::OSS::ERequestPayerType::PT_Requester;
		default:
			return SimpleOSS::OSS::ERequestPayerType::PT_None;
		}
	}
	
	static constexpr AlibabaCloud::OSS::StorageClass ConvertToAlibabaStorageType(SimpleOSS::OSS::EOssStorageType SimpleStorageType)
	{
		switch (SimpleStorageType)
		{
		default:
		case SimpleOSS::OSS::EOssStorageType::ST_Standard:
			return AlibabaCloud::OSS::StorageClass::Standard;
		case SimpleOSS::OSS::EOssStorageType::ST_IA:
			return AlibabaCloud::OSS::StorageClass::IA;
		case SimpleOSS::OSS::EOssStorageType::ST_Archive:
			return AlibabaCloud::OSS::StorageClass::Archive;
		case SimpleOSS::OSS::EOssStorageType::ST_ColdArchive:
			return AlibabaCloud::OSS::StorageClass::ColdArchive;
		}
	}

	static constexpr SimpleOSS::OSS::EOssStorageType ConvertToSimpleOssStorageType(AlibabaCloud::OSS::StorageClass AlibabaStorageType)
	{
		switch (AlibabaStorageType)
		{
		case AlibabaCloud::OSS::Standard:
			return SimpleOSS::OSS::EOssStorageType::ST_Standard;
		case AlibabaCloud::OSS::IA:
			return SimpleOSS::OSS::EOssStorageType::ST_IA;
		case AlibabaCloud::OSS::Archive:
			return SimpleOSS::OSS::EOssStorageType::ST_Archive;
		case AlibabaCloud::OSS::ColdArchive:
			return SimpleOSS::OSS::EOssStorageType::ST_ColdArchive;
		default:
			return SimpleOSS::OSS::EOssStorageType::ST_None;
		}
	}

	template<class Type, ESPMode Mode = ESPMode::ThreadSafe, bool Value = std::is_abstract_v<Type>>
	struct FConvertToStdSharedPtr;

	template<class Type, ESPMode Mode>
	struct FConvertToStdSharedPtr<Type, Mode, false>
	{
		static std::shared_ptr<Type> ConvertToStd(const TSharedPtr<Type, Mode>& UESmartPtr)
		{
			if (UESmartPtr.IsValid())
			{
				return std::shared_ptr<Type>(UESmartPtr->Clone());
			}
			else
			{
				return std::shared_ptr<Type>(nullptr);
			}
		}
	};

	template<class Type, ESPMode Mode>
	struct FConvertToStdSharedPtr<Type, Mode, true>
	{
		static std::shared_ptr<Type> ConvertToStd(const TSharedPtr<Type, Mode>& UESmartPtr)
		{
			return std::shared_ptr<Type>(nullptr);
		}

	};
	
	static void ConvertToAlibabaConfig(const SimpleOSS::OSS::FClientConfiguration & SimpleOssConfig, OSS::ClientConfiguration& AlibabaOssConfig)
	{
		AlibabaOssConfig.isCname = SimpleOssConfig.bCname;
		AlibabaOssConfig.enableCrc64 = SimpleOssConfig.bEnableCrc64;
		AlibabaOssConfig.enableDateSkewAdjustment = SimpleOssConfig.bEnableDateSkewAdjustment;
		AlibabaOssConfig.isPathStyle = SimpleOssConfig.bIsPathStyle;
		AlibabaOssConfig.isVerifyObjectStrict = SimpleOssConfig.bIsVerifyObjectStrict;
		AlibabaOssConfig.verifySSL = SimpleOssConfig.bVerifySSL;

		AlibabaOssConfig.proxyPort = SimpleOssConfig.ProxyPort;
		AlibabaOssConfig.connectTimeoutMs = SimpleOssConfig.ConnectTimeoutMs;
		AlibabaOssConfig.requestTimeoutMs = SimpleOssConfig.RequestTimeoutMs;
		AlibabaOssConfig.maxConnections = SimpleOssConfig.MaxConnections;

		AlibabaOssConfig.caFile = TCHAR_TO_UTF8(*SimpleOssConfig.CaFile);
		AlibabaOssConfig.caPath = TCHAR_TO_UTF8(*SimpleOssConfig.CaPath);
		AlibabaOssConfig.networkInterface = TCHAR_TO_UTF8(*SimpleOssConfig.NetworkInterface);

		AlibabaOssConfig.proxyHost = TCHAR_TO_UTF8(*SimpleOssConfig.ProxyHost);
		AlibabaOssConfig.proxyPassword = TCHAR_TO_UTF8(*SimpleOssConfig.ProxyPassword);
		AlibabaOssConfig.proxyUserName = TCHAR_TO_UTF8(*SimpleOssConfig.ProxyUserName);

		

		AlibabaOssConfig.executor = FConvertToStdSharedPtr<SimpleOSS::OSS::FSimpleOssExecutor>::ConvertToStd(SimpleOssConfig.Executor);
		AlibabaOssConfig.httpClient = FConvertToStdSharedPtr<SimpleOSS::OSS::FSimpleOssHttpClient>::ConvertToStd(SimpleOssConfig.HttpClient);
		AlibabaOssConfig.recvRateLimiter = FConvertToStdSharedPtr<SimpleOSS::OSS::FSimpleOssRateLimiter>::ConvertToStd(SimpleOssConfig.RecvRateLimiter);
		AlibabaOssConfig.sendRateLimiter = FConvertToStdSharedPtr<SimpleOSS::OSS::FSimpleOssRateLimiter>::ConvertToStd(SimpleOssConfig.SendRateLimiter);

		AlibabaOssConfig.proxyScheme = ConvertToAlibabaScheme(SimpleOssConfig.ProxyScheme);
		AlibabaOssConfig.scheme = ConvertToAlibabaScheme(SimpleOssConfig.Scheme);
		AlibabaOssConfig.signatureVersion = ConvertToAlibabaSignatureVersion(SimpleOssConfig.SignatureVersion);
	}
};


void FSimpleOSSManage::FOSS::InitializeAccount(const FString& InAccessKeyId, const FString& InAccessKeySecret, const FString& InEndPoint)
{
	AccessKeyId		= TCHAR_TO_UTF8(*InAccessKeyId);
	AccessKeySecret = TCHAR_TO_UTF8(*InAccessKeySecret);
	EndPoint		= TCHAR_TO_UTF8(*InEndPoint);
}

void FSimpleOSSManage::FOSS::InitializeConfig(const SimpleOSS::OSS::FClientConfiguration& InClientConfig)
{
	ClientConfig = InClientConfig;
}

bool FSimpleOSSManage::FOSS::CheckAccount() const
{
	{
		if (AccessKeyId.empty())
		{
			FAuxiliaryTools::Print(FString(TEXT("AccessKeyId can not be empty.")));
			return false;
		}
		if (AccessKeySecret.empty())
		{
			FAuxiliaryTools::Print(FString(TEXT("AccessKeySecret can not be empty.")));
			return false;
		}
		if (EndPoint.empty())
		{
			FAuxiliaryTools::Print(FString(TEXT("EndPoint can not be empty.")));
			return false;
		}
		return true;
	}
}



//桶操作
bool FSimpleOSSManage::FOSS::CreateBucket(const FString& InBucketName, SimpleOSS::OSS::EOssStorageType InStorageType,
	SimpleOSS::OSS::EAcl InAcl)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	/*指定新创建bucket的名称、存储级别和ACL*/
	OSS::CreateBucketRequest Request(BucketName,FAuxiliaryTools::ConvertToAlibabaStorageType(InStorageType), 
		FAuxiliaryTools::ConvertToAlibabaAcl(InAcl));
	OSS::CreateBucketOutcome Outcome = Client.CreateBucket(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
	return true;
}

bool FSimpleOSSManage::FOSS::ListBucket(TArray<FString>& OutBucketName)
{
	if (!CheckAccount())
	{
		return false;
	}

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ListBucketsRequest Request;
	OSS::ListBucketsOutcome Outcome = Client.ListBuckets(Request);

	if (Outcome.isSuccess())
	{
		for (auto& Temp : Outcome.result().Buckets())
		{
			OutBucketName.Add(FString(Temp.Name().c_str()));
		}
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}	
}

bool FSimpleOSSManage::FOSS::GetBucketLocation(const FString& InBucketName, FString& OutBucketLocation)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetBucketLocationRequest Request(BucketName);
	OSS::GetBucketLocationOutcome Outcome = Client.GetBucketLocation(Request);

	if (Outcome.isSuccess())
	{
		OutBucketLocation = FString(Outcome.result().Location().c_str());

		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
	
}

bool FSimpleOSSManage::FOSS::DeleteBucket(const FString& InBucketName)
{
	if (!CheckAccount())
	{
		return false;
	}
	
	TArray<SimpleOSS::OSS::FMultipartUploadInfo> MultipartPartsUploadsInfo;
	if (ListMultipartUploads(InBucketName, MultipartPartsUploadsInfo))
	{
		for (auto& Temp : MultipartPartsUploadsInfo)
		{
			AbortUploadParts(Temp.UploadId, InBucketName, Temp.Key);
		}

		TArray<SimpleOSS::OSS::FOssObjectInfo> OssObjectInfo;
		if (ListObjects(InBucketName, OssObjectInfo))
		{
			TArray<FString> ObjectNames;
			for (auto& Temp : OssObjectInfo)
			{
				ObjectNames.Add(Temp.ObjectName);
			}
			DeleteObjects(InBucketName, ObjectNames);

			std::string BucketName = TCHAR_TO_UTF8(*InBucketName);

			OSS::ClientConfiguration AlibabaOssConfig;
			FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
			OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

			OSS::DeleteBucketRequest Request(BucketName);
			OSS::VoidOutcome Outcome = Client.DeleteBucket(Request);
			if (Outcome.isSuccess())
			{
				return true;
			}
			else
			{
#if WITH_EDITOR
				SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
			}
		}
	}

	
	return false;
}

bool FSimpleOSSManage::FOSS::SetBucketAcl(const FString& InBucketName, SimpleOSS::OSS::EAcl InBucketAcl)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::SetBucketAclRequest Request(BucketName,FAuxiliaryTools::ConvertToAlibabaAcl(InBucketAcl));
	OSS::VoidOutcome Outcome = Client.SetBucketAcl(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

SimpleOSS::OSS::EAcl FSimpleOSSManage::FOSS::GetBucketAcl(const FString& InBucketName)
{
	if (!CheckAccount())
	{
		return SimpleOSS::OSS::EAcl::Acl_None;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetBucketAclRequest Request(BucketName);
	OSS::GetBucketAclOutcome Outcome = Client.GetBucketAcl(Request);

	if (Outcome.isSuccess())
	{
		return FAuxiliaryTools::ConvertToSimpleOssAcl(Outcome.result().Acl());
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return SimpleOSS::OSS::EAcl::Acl_None;
	}
}

bool FSimpleOSSManage::FOSS::SetBucketRequestPayment(const FString& InBucketName, SimpleOSS::OSS::ERequestPayerType InPayerType)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);
	
	OSS::SetBucketRequestPaymentRequest Request(BucketName, FAuxiliaryTools::ConvertToAlibabaPayerType(InPayerType));
	OSS::VoidOutcome Outcome = Client.SetBucketRequestPayment(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

SimpleOSS::OSS::ERequestPayerType FSimpleOSSManage::FOSS::GetBucketRequestPayment(const FString& InBucketName)
{
	if (!CheckAccount())
	{
		return SimpleOSS::OSS::ERequestPayerType::PT_None;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetBucketRequestPaymentRequest Request(BucketName);
	OSS::GetBucketPaymentOutcome Outcome = Client.GetBucketRequestPayment(Request);

	if (Outcome.isSuccess())
	{
		return FAuxiliaryTools::ConvertToSimpleOssPayerType(Outcome.result().Payer());
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return SimpleOSS::OSS::ERequestPayerType::PT_None;;
	}
}

bool FSimpleOSSManage::FOSS::SetBucketReferer(const FString& InBucketName, const TArray<FString>& URLReferer, bool bAllowEmptyReferer)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::RefererList List;
	for (auto& Temp : URLReferer)
	{
		List.push_back(TCHAR_TO_UTF8(*Temp));
	}

	OSS::SetBucketRefererRequest Request(BucketName, List, bAllowEmptyReferer);
	OSS::VoidOutcome Outcome = Client.SetBucketReferer(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::GetBucketReferer(const FString& InBucketName, SimpleOSS::OSS::FRefererList& OutRefererList)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetBucketRefererRequest Request(BucketName);
	OSS::GetBucketRefererOutcome Outcome = Client.GetBucketReferer(Request);

	if (Outcome.isSuccess())
	{
		auto& Result = Outcome.result();
		
		TArray<FString> Referers;
		for (auto& Temp : Result.RefererList())
		{
			Referers.Add(FString(Temp.c_str()));
		}
		OutRefererList.bAllowEmptyRefer = Result.AllowEmptyReferer();
		OutRefererList.RequestId = Result.RequestId().c_str();
		OutRefererList.RefererList = MoveTempIfPossible(Referers);
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::DeleteBucketReferer(const FString& InBucketName, bool bAllowEmptyReferer)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::SetBucketRefererRequest Request(BucketName, OSS::RefererList(), bAllowEmptyReferer);
	OSS::VoidOutcome Outcome = Client.SetBucketReferer(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::DoesBucketExist(const FString& InBucketName)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	return Client.DoesBucketExist(BucketName);
}



//对象操作
bool FSimpleOSSManage::FOSS::GetObjectMeta(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::FOssObjectMeta& OutMeta)
{
	if (!CheckAccount())
	{
		return false;
	}
	
	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ObjectMetaDataOutcome Outcome = Client.HeadObject(BucketName, ObjectName);

	if (Outcome.isSuccess())
	{
		auto& Result = Outcome.result();

		OutMeta.CacheControl		= Result.CacheControl().c_str();
		OutMeta.LastModified		= Result.LastModified().c_str();
		OutMeta.ExpirationTime		= Result.ExpirationTime().c_str();
		OutMeta.ContentLength		= Result.ContentLength();
		OutMeta.ContentType			= Result.ContentType().c_str();
		OutMeta.ContentEncoding		= Result.ContentEncoding().c_str();
		OutMeta.ContentDisposition	= Result.ContentDisposition().c_str();
		OutMeta.ETag				= Result.ETag().c_str();
		OutMeta.ContentMd5			= Result.ContentMd5().c_str();
		OutMeta.ObjectType			= Result.ObjectType().c_str();
		
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}

bool FSimpleOSSManage::FOSS::GetObjectMeta(const FString& InBucketName, const FString& InObjectName, 
	const FString& InField, FString& OutValue)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string Field = TCHAR_TO_UTF8(*InField);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ObjectMetaDataOutcome Outcome = Client.HeadObject(BucketName, ObjectName);

	if (Outcome.isSuccess())
	{
		if (Outcome.result().hasHeader(Field))
		{
			OutValue = Outcome.result().HttpMetaData()[Field].c_str();
		}
		else
		{
			if (Outcome.result().hasUserHeader(Field))
			{
				OutValue = Outcome.result().UserMetaData()[Field].c_str();
			}
		}

		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::SetObjectMeta(const FString& InBucketName, const FString& InObjectName, 
	const FString& InField, const FString& InValue)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	//GetObjectMeta内容比较少
	OSS::ObjectMetaDataOutcome MetaOutcome = Client.HeadObject(BucketName, ObjectName);
	
	if (!MetaOutcome.isSuccess())
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, MetaOutcome);
#endif
		return false;
	}

	std::string Field = TCHAR_TO_UTF8(*InField);
	std::string Value = TCHAR_TO_UTF8(*InValue);

	OSS::ObjectMetaData& MetaData = MetaOutcome.result();
	
	if (MetaData.hasHeader(Field))
	{
		MetaData.HttpMetaData()[Field] = Value;
	}
	else
	{
		MetaData.UserMetaData()[Field] = Value;
	}
	
	OSS::CopyObjectOutcome Outcome = Client.ModifyObjectMeta(BucketName, ObjectName, MetaData);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

SimpleOSS::OSS::EAcl FSimpleOSSManage::FOSS::GetObjcetAcl(const FString& InBucketName, const FString& InObjectName)
{
	if (!CheckAccount())
	{
		return SimpleOSS::OSS::EAcl::Acl_None;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetObjectAclRequest Request(BucketName, ObjectName);
	OSS::GetObjectAclOutcome Outcome =  Client.GetObjectAcl(Request);

	if (Outcome.isSuccess())
	{
		return FAuxiliaryTools::ConvertToSimpleOssAcl(Outcome.result().Acl());
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return SimpleOSS::OSS::EAcl::Acl_None;
	}

}

bool FSimpleOSSManage::FOSS::SetObjcetAcl(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EAcl InAcl)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::SetObjectAclRequest Request(BucketName, ObjectName, FAuxiliaryTools::ConvertToAlibabaAcl(InAcl));
	OSS::SetObjectAclOutcome Outcome = Client.SetObjectAcl(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}

bool FSimpleOSSManage::FOSS::DoesObjectExist(const FString& InBucketName, const FString& InObjectName)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	return Client.DoesObjectExist(BucketName, ObjectName);
}

bool FSimpleOSSManage::FOSS::ListObjects(const FString& InBucketName, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo, int32 MaxNumber)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ListObjectsRequest Request(BucketName);
	OSS::ListObjectOutcome Outcome = Client.ListObjects(Request);

	if (Outcome.isSuccess())
	{
		auto& Result = Outcome.result().ObjectSummarys();
		for (int32 i = 0; i < MaxNumber && i < Result.size(); i++)
		{
			auto& Temp = Result[i];
			OutObjectInfo.Emplace(
				Temp.Key().c_str(),
				Temp.Size(),
				Temp.LastModified().c_str()
				);
		}
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}

bool FSimpleOSSManage::FOSS::ListObjectsByPrefix(const FString& InBucketName, const FString& InKeyPrefix,
	const FString& InDelimiter, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo)
{
	if (!CheckAccount())
	{
		return false;
	}
	bool bSuccess = true;

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string KeyPrefix = TCHAR_TO_UTF8(*InKeyPrefix);
	std::string Delimiter = TCHAR_TO_UTF8(*InDelimiter);
	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	std::string nextMarker = "";
	OSS::ListObjectOutcome Outcome;

	do
	{
		OSS::ListObjectsRequest Request(BucketName);
		Request.setDelimiter(Delimiter);
		Request.setPrefix(KeyPrefix);
		Request.setMarker(nextMarker);

		Outcome = Client.ListObjects(Request);

		if (Outcome.isSuccess())
		{
			for (auto& Temp : Outcome.result().ObjectSummarys())
			{
				OutObjectInfo.Emplace(
					Temp.Key().c_str(),
					Temp.Size(),
					Temp.LastModified().c_str()
				);
			}
#if WITH_EDITOR
			for (auto& Temp : Outcome.result().CommonPrefixes())
			{
				FAuxiliaryTools::Print(Temp);
			}
#endif
		}
		else
		{
#if WITH_EDITOR
			SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
			bSuccess = false;
			break;
		}

		nextMarker = Outcome.result().NextMarker();

	} while (Outcome.result().IsTruncated());

	return bSuccess;
}

bool FSimpleOSSManage::FOSS::SetObjectStorageType(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EOssStorageType InStorageType)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	auto StorageTypeToString = [](SimpleOSS::OSS::EOssStorageType StorageType) -> std::string
		{
			switch (StorageType)
			{
			case SimpleOSS::OSS::EOssStorageType::ST_Standard:
				return "Standard";
			case SimpleOSS::OSS::EOssStorageType::ST_IA:
				return "IA";
			case SimpleOSS::OSS::EOssStorageType::ST_Archive:
				return "Archive";
			case SimpleOSS::OSS::EOssStorageType::ST_ColdArchive:
				return "ColdArchive";
			default:
				return "";
			}
		};
	
	//首先判断是否是归档类型
	OSS::RestoreObjectOutcome RestoreOutcome = Client.RestoreObject(BucketName, ObjectName);
	if (RestoreOutcome.isSuccess())
	{
		std::string OnGoingRestore("ongoing-request=\"false\"");
		int32 MaxWaitTimeInSeconds = 600;
		while (MaxWaitTimeInSeconds > 0)
		{
			OSS::ObjectMetaDataOutcome MetaOutcome= Client.HeadObject(BucketName, ObjectName);
			std::string RestoreStatus = MetaOutcome.result().HttpMetaData()["x-oss-restore"];
			std::transform(RestoreStatus.begin(), RestoreStatus.end(), RestoreStatus.begin(), ::tolower);
			
			if (!RestoreStatus.empty() && RestoreStatus.compare(0, OnGoingRestore.size(), OnGoingRestore) == 0)
			{
#if WITH_EDITOR
				//成功解冻
				FAuxiliaryTools::Print(RestoreStatus);
#endif
				break;
			}

			std::this_thread::sleep_for(std::chrono::seconds(10));
			MaxWaitTimeInSeconds--;
		}

	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, RestoreOutcome);
#endif
	}

	OSS::ObjectMetaData MetaData;
	MetaData.addHeader("x-oss-storage-class", StorageTypeToString(InStorageType));
	OSS::CopyObjectRequest Request(BucketName, ObjectName, MetaData);
	Request.setCopySource(BucketName, ObjectName);

	OSS::CopyObjectOutcome CopyOutcome = Client.CopyObject(Request);

	if (CopyOutcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, CopyOutcome);
#endif
		return false;
	}
}

SimpleOSS::OSS::EOssStorageType FSimpleOSSManage::FOSS::GetObjectStorageType(const FString& InBucketName, const FString& InObjectName)
{
	if (!CheckAccount())
	{
		return SimpleOSS::OSS::EOssStorageType::ST_None;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	auto StringToStorageType = [](const std::string& StorageType)
		{
			if (StorageType == "Standard")
			{
				return SimpleOSS::OSS::EOssStorageType::ST_Standard;
			}
			else if (StorageType == "IA")
			{
				return SimpleOSS::OSS::EOssStorageType::ST_IA;
			}
			else if (StorageType == "Archive")
			{
				return SimpleOSS::OSS::EOssStorageType::ST_Archive;
			}
			else if (StorageType == "ColdArchive")
			{
				return SimpleOSS::OSS::EOssStorageType::ST_ColdArchive;
			}
			else
			{
				return SimpleOSS::OSS::EOssStorageType::ST_None;
			}
		};

	//注：HeadObject可以获得全部的元数据
	OSS::ObjectMetaDataOutcome MetaOutcome = Client.HeadObject(BucketName, ObjectName);

	if (MetaOutcome.isSuccess())
	{
		//注：对于非自定义元数据，使用HttpMetaData
		return StringToStorageType(MetaOutcome.result().HttpMetaData()["x-oss-storage-class"]);
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, MetaOutcome);
#endif
		return SimpleOSS::OSS::EOssStorageType::ST_None;
	}

}

bool FSimpleOSSManage::FOSS::CreateSymlink(const FString& InBucketName, const FString& InObjectName, const FString& InLinkObjectName)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string SymLinkName = TCHAR_TO_UTF8(*InLinkObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ObjectMetaData Meta;
	Meta.addUserHeader("IsSymlink", "true");
	OSS::CreateSymlinkRequest Request(BucketName, ObjectName, Meta);
	Request.SetSymlinkTarget(SymLinkName);

	OSS::CreateSymlinkOutcome Outcome = Client.CreateSymlink(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}

FString FSimpleOSSManage::FOSS::GetSymlink(const FString& InBucketName, const FString& InObjectName)
{
	if (!CheckAccount())
	{
		return "";
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetSymlinkRequest Request(BucketName, ObjectName);
	OSS::GetSymlinkOutcome Outcome = Client.GetSymlink(Request);

	if (Outcome.isSuccess())
	{
		return Outcome.result().SymlinkTarget().c_str();
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return "";
	}

}


//图片处理
bool FSimpleOSSManage::FOSS::GetImageObjectByResize(const FVector2D& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("image/resize,m_fixed,w_%i,h_%i"), (int32)InWay.X, (int32)InWay.Y);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}

bool FSimpleOSSManage::FOSS::GetImageObjectByCrop(const FVector4& InWay, int32 Ratio, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("image/crop,w_%i,h_%i,x_%i,y_%i, r_%i"), (int32)InWay.X, (int32)InWay.Y, (int32)InWay.Z, (int32)InWay.W, Ratio);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}

bool FSimpleOSSManage::FOSS::GetImageObjectBySharpen(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("image/sharpen,%d"), InWay);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}

bool FSimpleOSSManage::FOSS::GetImageObjectByWaterMark(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("image/watermark,%s"), *InWay);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}

bool FSimpleOSSManage::FOSS::GetImageObjectByRotate(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("image/rotate,%i"), InWay);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);

}

bool FSimpleOSSManage::FOSS::GetImageObjectByStyle(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = FString::Printf(TEXT("style/%s"), *InWay);
	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}

bool FSimpleOSSManage::FOSS::GetImageObjectByCascade(const TArray<FString>& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath)
{
	FString Command = "image";
	for (auto& Temp : InWay)
	{
		Command/=Temp;
	}

	return GetImageObject(InBucketName, InObjectName, InSavePath, Command);
}


//对象上传
bool FSimpleOSSManage::FOSS::PutObjectFromMemroy(const FString& InBucketName, const FString& InObjectName, 
	const FString& InContent, ProgressCallback InProgress, const TMap<FString, FString>& CustomMeta,
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	std::shared_ptr<std::iostream> Content = std::make_shared<std::stringstream>();
	*Content << TCHAR_TO_UTF8(*InContent);

	/*设置元数据*/
	SIMPLE_OSS_SET_META(MetaData);

	OSS::PutObjectRequest Request(BucketName, ObjectName, Content, MetaData);

	/*设置进度条*/
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);

	OSS::PutObjectOutcome Outcome = Client.PutObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::AppendObjectFromMemroy(const FString& InBucketName, const FString& InObjectName, 
	const FString& InContent, int64& OutPosition, int64 InPosition,
	const TMap<FString, FString>& CustomMeta, const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	std::shared_ptr<std::iostream> Content = std::make_shared<std::stringstream>();
	*Content << TCHAR_TO_UTF8(*InContent);

	SIMPLE_OSS_SET_META(MetaData);
	
	OSS::AppendObjectRequest Request(BucketName, ObjectName, Content, MetaData);
	Request.setPosition(InPosition);

	OSS::AppendObjectOutcome Outcome = Client.AppendObject(Request);

	if (Outcome.isSuccess())
	{
		OutPosition = Outcome.result().Length();
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::PutObjectFromDisk(const FString& InBucketName, const FString& InLocalPath,
	const FString& InObjectName, ProgressCallback InProgress, const TMap<FString, FString>& CustomMeta, 
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = InObjectName.IsEmpty() ? TCHAR_TO_UTF8(*FPaths::GetCleanFilename(InLocalPath)) 
		: TCHAR_TO_UTF8(*InObjectName);
	std::string LocalPath = TCHAR_TO_UTF8(*InLocalPath);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	using Ios = std::ios;

	std::shared_ptr<std::iostream> Content = std::make_shared<std::fstream>(LocalPath, Ios::in | Ios::binary);


	/*设置元数据*/
	SIMPLE_OSS_SET_META(MetaData);

	OSS::PutObjectRequest Request(BucketName, ObjectName, Content, MetaData);

	/*设置进度条*/
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);

	OSS::PutObjectOutcome Outcome = Client.PutObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncPutObjectFromDisk(const FString& InBucketName, const FString& InLocalPath,
	const FString& InObjectName, ProgressCallback InProgress, const TMap<FString, FString>& CustomMeta, 
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			PutObjectFromDisk(InBucketName, InLocalPath, InObjectName,
				InProgress, CustomMeta, InOssObjectMeta);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::ResumableUploadObject(const FString& InBucketName, const FString& InUploadFilePath, 
	const FString& InObjectName, const FString& InCheckPointFilePath, ProgressCallback InProgress,
	const TMap<FString, FString>& CustomMeta, const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = InObjectName.IsEmpty() ? TCHAR_TO_UTF8(*FPaths::GetCleanFilename(InUploadFilePath)) : TCHAR_TO_UTF8(*InObjectName);
	std::string UploadFilePath = TCHAR_TO_UTF8(*InUploadFilePath);
	std::string CheckPointFilePath = TCHAR_TO_UTF8(*InCheckPointFilePath);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	/*设置元数据*/
	SIMPLE_OSS_SET_META(MetaData);

	OSS::UploadObjectRequest Request(BucketName, ObjectName, UploadFilePath, CheckPointFilePath, MetaData);
	/*设置进度条*/
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);

	OSS::PutObjectOutcome Outcome = Client.ResumableUploadObject(Request);
	
	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncResumableUploadObject(const FString& InBucketName, const FString& InObjectName,
	const FString& InUploadFilePath, const FString& InCheckPointFilePath, ProgressCallback InProgress, 
	const TMap<FString, FString>& CustomMeta, const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			ResumableUploadObject(InBucketName, InObjectName, InUploadFilePath, InCheckPointFilePath,
				InProgress, CustomMeta, InOssObjectMeta);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::UploadParts(FString& OutUploadId, const FString& InBucketName, 
	const FString& InObjectName, const FString& InLocalPath, int32 InPartSize, UploadPartCallback InUploadPartCallback, 
	ProgressCallback InProgress, const TMap<FString, FString>& CustomMeta, 
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return false;
	}

	auto Lambda = [&InUploadPartCallback](FString UploadId, uint32 PartCount, uint64 PartSize, uint64 TotalSize, bool bSuccessfulPart, bool bComplete)
		{
			if(InUploadPartCallback)
			{
				FGraphEventRef Handle = FFunctionGraphTask::CreateAndDispatchWhenReady(
					[=]()
					{
						InUploadPartCallback(UploadId, PartCount, PartSize, TotalSize, bSuccessfulPart, bComplete);
					}, TStatId(), nullptr, ENamedThreads::GameThread
						);
				FTaskGraphInterface::Get().WaitUntilTaskCompletes(Handle);
			}
		};

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = InObjectName.IsEmpty() ? TCHAR_TO_UTF8(*FPaths::GetCleanFilename(InLocalPath)) : TCHAR_TO_UTF8(*InObjectName);
	std::string LocalPath = TCHAR_TO_UTF8(*InLocalPath);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);
	
	OSS::InitiateMultipartUploadRequest InitiateRequest(BucketName, ObjectName);
	OSS::InitiateMultipartUploadOutcome InitiateOutcome = Client.InitiateMultipartUpload(InitiateRequest);
	const std::string& UploadId = InitiateOutcome.result().UploadId();
	OutUploadId = UploadId.c_str();

	//计算分片
	OSS::PartList PartETagList;
	int64 FileSize = FAuxiliaryTools::GetFileSize(LocalPath);
	int32 PartCount = FileSize/ InPartSize;
	if (FileSize % InPartSize != 0)
	{
		PartCount++;
	}

	//上传分片
	for (int32 i = 1; i <= PartCount; i++)
	{
		int32 SkipBytes = InPartSize*(i-1);
		int32 SizePerTime = (InPartSize < FileSize - SkipBytes) ? InPartSize : (FileSize - SkipBytes);
		std::shared_ptr<std::iostream> Content = std::make_shared<std::fstream>(LocalPath, std::ios::in | std::ios::binary);
		
		OSS::UploadPartRequest UploadRequest(BucketName, ObjectName, Content);
		UploadRequest.setContentLength(SizePerTime);
		UploadRequest.setUploadId(UploadId);
		UploadRequest.setPartNumber(i);

		OSS::PutObjectOutcome Outcome = Client.UploadPart(UploadRequest);
		if (Outcome.isSuccess())
		{
			PartETagList.push_back(OSS::Part(i, Outcome.result().ETag()));
			Lambda(OutUploadId, PartCount, SizePerTime, FileSize, true, false);
		}
		else
		{
#if WITH_EDITOR
			SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
			Lambda(OutUploadId, PartCount, SizePerTime, FileSize, false, false);
			return false;
		}
	}

	//合并分片
	OSS::CompleteMultipartUploadRequest CompleteRequest(BucketName, ObjectName, PartETagList, UploadId);
	
	/*设置元数据*/
	SIMPLE_OSS_SET_META_BY_REF(CompleteRequest);
	/*设置进度条*/
	SIMPLE_OSS_SET_PROGRESS(CompleteRequest, InProgress);
	
	OSS::CompleteMultipartUploadOutcome CompleteOutcome = Client.CompleteMultipartUpload(CompleteRequest);
	
	if(CompleteOutcome.isSuccess())
	{
		Lambda(OutUploadId, 0, 0, FileSize, true, true);
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, CompleteOutcome);
#endif
		Lambda(OutUploadId, 0, 0, FileSize, false, false);
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncUploadParts(const FString& InBucketName, const FString& InObjectName, 
	const FString& InLocalPath, int32 InPartSize, UploadPartCallback InUploadPartCallback,
	ProgressCallback InProgress, const TMap<FString, FString>& CustomMeta, 
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			FString UploadId;
			UploadParts(UploadId, InBucketName, InObjectName, InLocalPath, InPartSize,
				InUploadPartCallback, InProgress, CustomMeta, InOssObjectMeta);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::AbortUploadParts(const FString& InUploadId, const FString& InBucketName, 
	const FString& InObjectName)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string UploadId = TCHAR_TO_UTF8(*InUploadId);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::AbortMultipartUploadRequest AbortRequest(BucketName, ObjectName, UploadId);
	OSS::VoidOutcome Outcome = Client.AbortMultipartUpload(AbortRequest);
	
	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}


//对象下载
bool FSimpleOSSManage::FOSS::GetObjectToMemory(const FString& InBucketName, const FString& InObjectName, 
	FString& OutContent, SimpleOSS::OSS::FRange InRange, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::GetObjectRequest Request(BucketName, ObjectName);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	SIMPLE_OSS_SET_RANGE(Request, InRange);
	OSS::GetObjectOutcome Outcome = Client.GetObject(Request);

	if (Outcome.isSuccess())
	{
		std::string Temp;
		*(Outcome.result().Content()) >> Temp;
		OutContent = Temp.c_str();
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncGetObjectToMemory(const FString& InBucketName, const FString& InObjectName, FString& OutContent
	, SimpleOSS::OSS::FRange InRange, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=,&OutContent, this]()
		{
			GetObjectToMemory( InBucketName, InObjectName, OutContent,
				InRange, InProgress);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::GetObjectToDisk(const FString& InBucketName, const FString& InObjectName, 
	const FString& InLocalPath, SimpleOSS::OSS::FRange InRange, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string LocalPath = TCHAR_TO_UTF8(*InLocalPath);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	using Ios = std::ios;

	OSS::GetObjectRequest Request(BucketName, ObjectName);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	SIMPLE_OSS_SET_RANGE(Request, InRange);

	Request.setResponseStreamFactory(
		[=]()->std::shared_ptr<std::iostream>
		{
			return std::make_shared<std::fstream>(LocalPath, Ios::in | Ios::out | Ios::trunc| Ios::binary);
		}
	);

	OSS::GetObjectOutcome Outcome = Client.GetObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}

}

void FSimpleOSSManage::FOSS::AsyncGetObjectToDisk(const FString& InBucketName, const FString& InObjectName, 
	const FString& InLocalPath, SimpleOSS::OSS::FRange InRange, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			GetObjectToDisk(InBucketName, InObjectName, InLocalPath, InRange, InProgress);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::ResumableDownloadObject(const FString& InBucketName, const FString& InObjectName, 
	const FString& InLocalPath, const FString& InCheckPointFilePath, SimpleOSS::OSS::FRange InRange,
	ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string LocalPath = TCHAR_TO_UTF8(*InLocalPath);
	std::string CheckPointFilePath = TCHAR_TO_UTF8(*InCheckPointFilePath);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	using Ios = std::ios;

	OSS::DownloadObjectRequest Request(BucketName, ObjectName, LocalPath, CheckPointFilePath);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	SIMPLE_OSS_SET_RANGE(Request, InRange);
	Request.setResponseStreamFactory(
		[=]()
		{
			return std::make_shared<std::fstream>(LocalPath, Ios::in | Ios::out | Ios::trunc | Ios::binary);
		}
	);

	OSS::GetObjectOutcome Outcome = Client.ResumableDownloadObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncResumableDownloadObject(const FString& InBucketName, const FString& InObjectName,
	const FString& InLocalPath, const FString& InCheckPointFilePath, SimpleOSS::OSS::FRange InRange, 
	ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			ResumableDownloadObject(InBucketName, InObjectName, InLocalPath, InCheckPointFilePath, 
				InRange, InProgress);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}



//对象的复制删除
bool FSimpleOSSManage::FOSS::CopyObject(const FString& InSourceBucket, const FString& InSourceObject, 
	const FString& InTargetBucket, const FString& InTargetObject, const TMap<FString, FString>& CustomMeta,
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string SourceBucket = TCHAR_TO_UTF8(*InSourceBucket);
	std::string SourceObject = TCHAR_TO_UTF8(*InSourceObject);
	std::string TargetBucket = TCHAR_TO_UTF8(*InTargetBucket);
	std::string TargetObject = TCHAR_TO_UTF8(*InTargetObject);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	SIMPLE_OSS_SET_META(MetaData);
	OSS::CopyObjectRequest Request(TargetBucket, TargetObject, MetaData);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	Request.setCopySource(SourceBucket, SourceObject);
	OSS::CopyObjectOutcome Outcome = Client.CopyObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

void FSimpleOSSManage::FOSS::AsyncCopyObject(const FString& InSourceBucket, const FString& InSourceObject, 
	const FString& InTargetBucket, const FString& InTargetObject, const TMap<FString, FString>& CustomMeta,
	const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return;
	}

	auto Lambda = [=, this]()
		{
			CopyObject(InSourceBucket, InSourceObject, InTargetBucket, InTargetObject,
				CustomMeta, InOssObjectMeta,  InProgress);
		};

	(new FAutoDeleteAsyncTask<FOssAsyncTask>(Lambda))->StartBackgroundTask();
}

bool FSimpleOSSManage::FOSS::DeleteObject(const FString& InBucketName, const FString& InObjectName,
	ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}
	
	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);
	
	OSS::DeleteObjectRequest Request(BucketName, ObjectName);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	OSS::DeleteObjectOutcome Outcome = Client.DeleteObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::DeleteObjects(const FString& InBucketName, const TArray<FString>& InObjectNames, 
	ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	//std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::DeleteObjectsRequest Request(BucketName);
	SIMPLE_OSS_SET_PROGRESS(Request, InProgress);
	OSS::DeletedKeyList KeyList;
	for (auto& Temp : InObjectNames)
	{
		KeyList.emplace_back(TCHAR_TO_UTF8(*Temp));
	}
	Request.setKeyList(KeyList);
	OSS::DeleteObjecstOutcome Outcome = Client.DeleteObjects(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}

bool FSimpleOSSManage::FOSS::ListParts(const FString& InUploadId, const FString& InBucketName, const FString& InObjectName,
	TArray<SimpleOSS::OSS::FPartsInfo>& OutPartsInfo, int32 MaxParts, ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}
	
	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string UploadId = TCHAR_TO_UTF8(*InUploadId);


	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);


	/*列举已上传的分片*/
	OSS::ListPartsRequest ListRequest(BucketName, ObjectName, UploadId);
	ListRequest.setMaxParts(MaxParts);//设置每页多少最大多少分片
	SIMPLE_OSS_SET_PROGRESS(ListRequest, InProgress);

	bool IsTrucnated = true;
	do
	{
		OSS::ListPartsOutcome ListOutcome = Client.ListParts(ListRequest);
		if (ListOutcome.isSuccess())
		{	
			for (auto& Temp : ListOutcome.result().PartList())
			{
				OutPartsInfo.Emplace(Temp.PartNumber(), Temp.Size(), 
					Temp.ETag().c_str(), Temp.LastModified().c_str());
			};
		}
		else
		{
#if WITH_EDITOR
			SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, ListOutcome);
#endif
			return false;
		}
	
		ListRequest.setPartNumberMarker(ListOutcome.result().NextPartNumberMarker());
		IsTrucnated = ListOutcome.result().IsTruncated();
	} while (IsTrucnated);


	return true;
}

bool FSimpleOSSManage::FOSS::ListMultipartUploads(const FString& InBucketName, 
	TArray<SimpleOSS::OSS::FMultipartUploadInfo>& MultipartUploadInfo, int32 MaxParts, 
	ProgressCallback InProgress)
{
	if (!CheckAccount())
	{
		return false;
	}
	bool bSuccess = true;
	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	OSS::ListMultipartUploadsRequest ListRequest(BucketName);
	ListRequest.setMaxUploads(MaxParts);
	SIMPLE_OSS_SET_PROGRESS(ListRequest, InProgress);
	bool IsTruncated = true;

	do
	{
		OSS::ListMultipartUploadsOutcome ListOutcome = Client.ListMultipartUploads(ListRequest);

		if (ListOutcome.isSuccess())
		{
			for (auto& Temp : ListOutcome.result().MultipartUploadList())
			{
				MultipartUploadInfo.Emplace(Temp.Key.c_str(), Temp.UploadId.c_str(), Temp.Initiated.c_str());
			}
		}
		else
		{
#if WITH_EDITOR
			SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, ListOutcome);
#endif
			return false;
		}

		ListRequest.setKeyMarker(ListOutcome.result().NextKeyMarker());
		ListRequest.setUploadIdMarker(ListOutcome.result().NextUploadIdMarker());
		IsTruncated = ListOutcome.result().IsTruncated();
	} while (IsTruncated);

	return true;
}


bool FSimpleOSSManage::FOSS::GetImageObject(const FString& InBucketName, const FString& InObjectName, const FString& InSavePath, const FString& InCommand)
{
	if (!CheckAccount())
	{
		return false;
	}

	std::string BucketName = TCHAR_TO_UTF8(*InBucketName);
	std::string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	std::string SavePath = TCHAR_TO_UTF8(*InSavePath);
	std::string Process = TCHAR_TO_UTF8(*InCommand);

	OSS::ClientConfiguration AlibabaOssConfig;
	FAuxiliaryTools::ConvertToAlibabaConfig(ClientConfig, AlibabaOssConfig);
	OSS::OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, AlibabaOssConfig);

	using Ios = std::ios;
	OSS::GetObjectRequest Request(BucketName, ObjectName, Process);
	Request.setResponseStreamFactory(
		[=]() 
		{
			return std::make_shared<std::fstream>(
				SavePath, Ios::in | Ios::out | Ios::trunc | Ios::binary
			);
		}
	);
	OSS::GetObjectOutcome Outcome = Client.GetObject(Request);

	if (Outcome.isSuccess())
	{
		return true;
	}
	else
	{
#if WITH_EDITOR
		SIMPLE_OSS_ERROR(FAuxiliaryTools::Print, Outcome);
#endif
		return false;
	}
}
