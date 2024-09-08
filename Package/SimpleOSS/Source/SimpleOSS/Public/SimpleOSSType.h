#pragma once
#include "CoreMinimal.h"
#include "alibabacloud/oss/client/RateLimiter.h"
#include "alibabacloud/oss/utils/Executor.h"
#include "alibabacloud/oss/http/HttpClient.h"

namespace SimpleOSS
{
    namespace OSS
    {
        using FSimpleRunnable = AlibabaCloud::OSS::Runnable;
        using FSimpleExecutor = AlibabaCloud::OSS::Executor;
        using FSimpleRateLimiter = AlibabaCloud::OSS::RateLimiter;
        using FSimpleHttpClient = AlibabaCloud::OSS::HttpClient;

        enum EScheme
        {
            HTTP,
            HTTPS,
            None
        };

        enum class ESignatureVersionType
        {
            V1,
            V4,
            None
        };

        enum class EAcl : uint8
        {
            Acl_Private = 0,
            Acl_PublicRead,
            Acl_PublicReadWrite,
            Acl_Default,
            Acl_None
        };

        enum class ERequestPayerType :uint8
        {
            PT_NotSet = 0,
            PT_BucketOwner,
            PT_Requester,
            PT_None
        };

        enum class EOssStorageType : uint8
        {
            ST_Standard = 0,
            ST_IA,
            ST_Archive,
            ST_ColdArchive,
            ST_None
        };

        class SIMPLEOSS_API FSimpleOssRunnable : public FSimpleRunnable
        {
        public:   
            explicit FSimpleOssRunnable(const std::function<void()> f) : Runnable(f), BaseFunction(f){}
            virtual FSimpleOssRunnable* Clone() const
            {
                return new FSimpleOssRunnable(BaseFunction);
            }
            virtual ~FSimpleOssRunnable() {}
        private:
            std::function<void()> BaseFunction;
        };

        class SIMPLEOSS_API FSimpleOssExecutor : public FSimpleExecutor
        {
        public:
            FSimpleOssExecutor(){}
            virtual ~FSimpleOssExecutor() override {}
            virtual void execute(FSimpleRunnable* task) = 0;//可以使用FSimpleOssRunnable指针
            virtual FSimpleOssExecutor* Clone() const = 0;//必须重写，用于适配UE和AlibabaOSS
        };

        class SIMPLEOSS_API FSimpleOssRateLimiter : public FSimpleRateLimiter
        {
            friend struct FAuxiliaryTools;
        public:
            FSimpleOssRateLimiter() :FSimpleRateLimiter(), LimitedRate(0) {}
            virtual ~FSimpleOssRateLimiter() override {};

	        virtual void setRate(int InRate) override { LimitedRate = InRate;}
	        virtual int Rate() const override {return LimitedRate;}

            virtual FSimpleOssRateLimiter* Clone() const
            {
                FSimpleOssRateLimiter* Result = new FSimpleOssRateLimiter();
                Result->setRate(LimitedRate);
                return Result;
            }
        private:
	        int32 LimitedRate;
        };

        class SIMPLEOSS_API FSimpleOssHttpClient : public FSimpleHttpClient
        {
        public:
            FSimpleOssHttpClient() : FSimpleHttpClient(){}
            virtual ~FSimpleOssHttpClient() override {}

            virtual std::shared_ptr<AlibabaCloud::OSS::HttpResponse> makeRequest(const std::shared_ptr<AlibabaCloud::OSS::HttpRequest>& request) = 0;
            
            /* virtual FSimpleOssHttpClient* Clone() const
            {
                FSimpleOssHttpClient* Result = new FSimpleOssHttpClient;
                Result->disable_ = disable_;
                return Result;
            }*/
            virtual FSimpleOssHttpClient* Clone() const = 0;//必须重写，用于适配UE和AlibabaOSS
        };

        class SIMPLEOSS_API FClientConfiguration
        {
        public:
            FClientConfiguration();
            ~FClientConfiguration() = default;
        public:
            /**
            * Http scheme to use. E.g. Http or Https.
            */
            EScheme Scheme;
            /**
            * Max concurrent tcp connections for a single http client to use.
            */
            unsigned MaxConnections;
            /**
            * Socket read timeouts. Default 3000 ms.
            */
            long RequestTimeoutMs;
            /**
            * Socket connect timeout.
            */
            long ConnectTimeoutMs;
            /**
            * The proxy scheme. Default HTTP
            */
            EScheme ProxyScheme;
            /**
            * The proxy host.
            */
            FString ProxyHost;
            /**
            * The proxy port.
            */
            unsigned int ProxyPort;
            /**
            * The proxy username.
            */
            FString ProxyUserName;
            /**
            *  The proxy password
            */
            FString ProxyPassword;
            /**
            * set false to bypass SSL check.
            */
            bool bVerifySSL;
            /**
            * your Certificate Authority path.
            */
            FString CaPath;
            /**
            * your certificate file.
            */
            FString CaFile;
            /**
            * enable or disable cname, default is false.
            */
            bool bCname;
            /**
            * enable or disable crc64 check.
            */
            bool bEnableCrc64;
            /**
            * enable or disable auto correct http request date.
            */
            bool bEnableDateSkewAdjustment;
            /**
            * Rate limit data upload speed.
            */
            TSharedPtr<FSimpleOssRateLimiter> SendRateLimiter;
            /**
            * Rate limit data download speed.
            */
            TSharedPtr<FSimpleOssRateLimiter> RecvRateLimiter;
            /**
            * The interface for outgoing traffic. E.g. eth0 in linux
            */
            FString NetworkInterface;
            /**
            * Your executor's implement
            */
            TSharedPtr<FSimpleOssExecutor> Executor;
            /**
            * Your http client' implement
            */
            TSharedPtr<FSimpleOssHttpClient> HttpClient;
            /**
            * enable or disable path style, default is false.
            */
            bool bIsPathStyle;
            /**
            * enable or disable verify object name strictly. defualt is true
            */
            bool bIsVerifyObjectStrict;

            /**
            * signature version. default is V1.
            */
            ESignatureVersionType SignatureVersion;
        };

        //防盗链
        struct SIMPLEOSS_API FRefererList
        {
            //FRefererList() : RequestId(TEXT("")) {}
            
            FORCEINLINE bool IsValid(){return !RequestId.IsEmpty(); }

            bool bAllowEmptyRefer;
            TArray<FString> RefererList;    //有可能是空的防盗链
            FString RequestId;
        };

        //元数据
        struct SIMPLEOSS_API FOssObjectMeta
        {
            FOssObjectMeta() = default;
            FOssObjectMeta(const FOssObjectMeta&) noexcept = default;
            FOssObjectMeta(FOssObjectMeta&& Other) noexcept = default;
            FOssObjectMeta& operator=(const FOssObjectMeta&) noexcept = default;
            FOssObjectMeta& operator=(FOssObjectMeta&& Other) noexcept = default;

            FString Print() const
            {
                return (
                FString::Printf(TEXT("ContentType: %s\n")       ,   *ContentType)       + 
                FString::Printf(TEXT("ContentEncoding: %s\n")   ,   *ContentEncoding)   +
                FString::Printf(TEXT("CacheControl: %s\n")      ,   *CacheControl)      +
                FString::Printf(TEXT("ContentDisposition: %s\n"),   *ContentDisposition)+
                FString::Printf(TEXT("ContentLength: %d\n")     ,   ContentLength)      +
                FString::Printf(TEXT("LastModified: %s\n")      ,   *LastModified)      +
                FString::Printf(TEXT("ExpirationTime: %s\n")    ,   *ExpirationTime)    +
                FString::Printf(TEXT("ContentMd5: %s\n")        ,   *ContentMd5)        +
                FString::Printf(TEXT("ObjectType: %s\n")        ,   *ObjectType)        +
                FString::Printf(TEXT("ETag: %s\n")              ,   *ETag));

            }

            FString ContentType;
            FString ContentEncoding;       
            FString CacheControl;
            FString ContentDisposition;
            int64   ContentLength;
            FString LastModified;
            FString ExpirationTime;
            FString ContentMd5;
            FString ObjectType;
            FString ETag;
        };

        //对象信息
        struct SIMPLEOSS_API FOssObjectInfo
        {

            FString ObjectName;
            int64 Size;
            FString LastModifiedTime;
        };

        struct SIMPLEOSS_API FRange
        {
            uint64 Start{1};
            uint64 End{0};
            FORCEINLINE bool IsValid(){return Start < End && End != 0;}
            FORCEINLINE void Invalidate() { Start = 1; End = 0; }
        };

        struct SIMPLEOSS_API FMultipartUploadInfo
        {
            FString Key;
            FString UploadId;
            FString Initiated;
            FString Print()
            {
                return (
                    FString::Printf(TEXT("Key: %s\n"), *Key)            +
                    FString::Printf(TEXT("UploadId: %s\n"), *UploadId)  +
                    FString::Printf(TEXT("Initiated: %s\n"), *Initiated));
            }
        };

        struct SIMPLEOSS_API FPartsInfo
        {
            int32   PartNumber;
            int64   Size;
            FString ETag;
            FString LastModify;
            FString Print()
            {
                return (
                    FString::Printf(TEXT("PartNumber: %d\n"), PartNumber)   +
                    FString::Printf(TEXT("Size: %d\n"), Size)               +
                    FString::Printf(TEXT("ETag: %s\n"), *ETag)              +
                    FString::Printf(TEXT("LastModify: %s\n"), *LastModify));
            }
        };
    }
}

//uint64 increment, int64 transferred, int64 total, void* userData
typedef void(*ProgressCallback)(uint64, int64, int64, void*);
//FString UploadId, uint32 PartCount, int64 PartSize, uint64 TotalSize, bool bSuccessfulPart, bool bComplete
typedef void(*UploadPartCallback)(FString, uint32, uint64, uint64, bool, bool);
