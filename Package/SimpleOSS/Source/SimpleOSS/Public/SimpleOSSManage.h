#pragma once

#include "CoreMinimal.h"
#include "SimpleOSSType.h"
#include "Misc/Paths.h"
#include <string>

constexpr static int32 SizePerPart = 1024 * 1024 * 1;

class SIMPLEOSS_API FSimpleOSSManage
{
public:
	~FSimpleOSSManage();

	static TSharedRef<FSimpleOSSManage> Get();
	static void Destroy();

public:
	struct SIMPLEOSS_API FOSS
	{
	public:

		void InitializeAccount(const FString& InAccessKeyId, const FString& InAccessKeySecret, const FString& InEndPoint);

		void InitializeConfig(const SimpleOSS::OSS::FClientConfiguration& InClientConfig = {});

		bool CheckAccount() const;
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////Ͱ����////////////////////////////////////////////////////////
#pragma region Bucket

		/**
		* ����Ͱ
		* @InBucketName input oss bucket name
		*/
		bool CreateBucket(const FString& InBucketName, SimpleOSS::OSS::EOssStorageType InStorageType = SimpleOSS::OSS::EOssStorageType::ST_Standard,
			SimpleOSS::OSS::EAcl InAcl = SimpleOSS::OSS::EAcl::Acl_Default);

		/**
		* �о�Ͱ������
		* @OutBucketName output listed oss bucket names
		*/
		bool ListBucket(TArray<FString>& OutBucketName);

		/**
		* ��ȡͰ�ĵ���
		* @InBucketName input oss bucket name
		* @OutBucketLocation output oss bucket location
		*/
		bool GetBucketLocation(const FString& InBucketName, FString& OutBucketLocation);

		/**
		* ɾ��Ͱ
		* @InBucketName input oss bucket name
		*/
		bool DeleteBucket(const FString& InBucketName);

		/**
		* ����Ͱ�Ķ�дȨ��
		* @InBucketName input oss bucket name
		* @InBucketAcl input bucket acl you need
		*/
		bool SetBucketAcl(const FString& InBucketName, SimpleOSS::OSS::EAcl InBucketAcl);

		/**
		* ��ȡͰ�Ķ�дȨ��
		* @InBucketName input oss bucket name
		* @return output bucket acl you need
		*/
		SimpleOSS::OSS::EAcl GetBucketAcl(const FString& InBucketName);
	
		/**
		* ���������߸���ģʽ
		* @InBucketName input oss bucket name
		* @InPayerType input payer type you need
		*/
		bool SetBucketRequestPayment(const FString& InBucketName, SimpleOSS::OSS::ERequestPayerType InPayerType);

		/**
		* ��ȡ�����߸���ģʽ
		* @InBucketName input oss bucket name
		* @return output payer type you need
		*/
		SimpleOSS::OSS::ERequestPayerType GetBucketRequestPayment(const FString& InBucketName);
		
		/**
		* ���÷�����
		* @InBucketName input oss bucket name
		* @URLReferer input Referer list
		* @bAllowEmptyReferer Does allow to exist empty Referer? 
		*/
		bool SetBucketReferer(const FString& InBucketName, const TArray<FString>& URLReferer, bool bAllowEmptyReferer = false);
		
		/**
		* ��ȡ������
		* @InBucketName   input oss bucket name
		* @OutRefererList output referers
		*/
		bool GetBucketReferer(const FString& InBucketName, SimpleOSS::OSS::FRefererList& OutRefererList);
		
		/**
		* ɾ��������
		* @InBucketName input oss bucket name
		* @bAllowEmptyReferer Does allow to exist empty Referer?
		*/
		bool DeleteBucketReferer(const FString& InBucketName, bool bAllowEmptyReferer = true);

		/**
		* ��ѯͰ�Ƿ����
		* @InBucketName input oss bucket name
		*/
		bool DoesBucketExist(const FString& InBucketName);
#pragma endregion
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////�������////////////////////////////////////////////////////////
#pragma region Object			
		/**
		* ��ȡ����Ԫ����
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @OutMeta		output oss object meta
		*/
		bool GetObjectMeta(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::FOssObjectMeta& OutMeta);
		
		//��Щ�ֶ��޷����ã�����鿴�����OSS sdk�ֲ�
		bool GetObjectMeta(const FString& InBucketName, const FString& InObjectName, const FString& InField, FString& OutValue);
		bool SetObjectMeta(const FString& InBucketName, const FString& InObjectName, const FString& InField, const FString& InValue);

		/**
		* ��ȡ����Ķ�дȨ��
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @return		output oss object acl
		*/
		SimpleOSS::OSS::EAcl GetObjcetAcl(const FString& InBucketName, const FString& InObjectName);

		/**
		* ���ö���Ķ�дȨ��
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InAcl		input oss object acl
		*/
		bool SetObjcetAcl(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EAcl InAcl);

		/**
		* �鿴�����Ƿ����
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		*/
		bool DoesObjectExist(const FString& InBucketName, const FString& InObjectName);

		/**
		* �о�Ͱ�����ж��󣬿����趨�޶�
		* @InBucketName input oss bucket name
		* @OutObjectInfo output Info of Objects
		* @MaxNumber	input max number of listed objects
		*/
		bool ListObjects(const FString& InBucketName, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo, int32 MaxNumber = 100);

		/**
		* �о�ӵ��ǰ׺�Ķ������ֵ�DelimiterΪֹ
		* @InBucketName input oss bucket name
		* @InKeyPrefix ���ڲ�ѯ����keyprefix�����ж����ļ��ṹ�����ַ�����
		* @OutObjectInfo output Info of Objects
		* @MaxNumber	input max number of listed objects
		*/
		bool ListObjectsByPrefix(const FString& InBucketName, const FString& InKeyPrefix, const FString& InDelimiter, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo);

		/**
		* ���ö��󴢴�����
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InStorageType storage type of object
		*/
		bool SetObjectStorageType(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EOssStorageType InStorageType);

		/**
		* ��ȡ���󴢴�����
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @return		output storage type of object
		*/
		SimpleOSS::OSS::EOssStorageType GetObjectStorageType(const FString& InBucketName, const FString& InObjectName);

		/**
		* ����������
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InLinkObjectName input symlink name you need
		*/
		bool CreateSymlink(const FString& InBucketName, const FString& InObjectName, const FString& InLinkObjectName);

		/**
		* ��ȡ������
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @return		output name of symlink
		*/
		FString GetSymlink(const FString& InBucketName, const FString& InObjectName);
#pragma endregion	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////ͼ����////////////////////////////////////////////////////////
#pragma region ImageProcess

		/**
		* ����
		* @InWay		input Way that include new size
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByResize(const FVector2D& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* �ü�
		* @InWay		input Way that include pos and new size
		* @Ratio
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByCrop(const FVector4& InWay, int32 Ratio, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* ��
		* @InWay		input Way that include a value
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectBySharpen(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* ˮӡ
		* @InWay		input Way that include a string
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByWaterMark(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* ��ת
		* @InWay		input Way that include a value
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByRotate(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* ʹ��OSS�Զ���ͼƬģ����ʽ
		* @InWay		input Way that include a OssStyleName
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByStyle(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* ��������
		* @InWay		input Way that include a array of cascade commands;
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByCascade(const TArray<FString>& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);
#pragma endregion

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////��Դ�ϴ�////////////////////////////////////////////////////////
#pragma region Upload

		/**
		* ���ڴ��ϴ�
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		* @InContent
		* @InProgress		input a callback about progress bar and can be nullptr
		* @CustomMeta		input your customized meta data and can be default
		* @InOssObjectMeta	default meta data of oss
		*/
		bool PutObjectFromMemroy(const FString& InBucketName, const FString& InObjectName, const FString& InContent,
			ProgressCallback InProgress = nullptr,const TMap<FString, FString>& CustomMeta = {}, 
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta= {});
		
		/**
		* ׷���ϴ�
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		* @InContent
		* @OutPosition		pos of input next time
		* @InPosition		default is 0
		* @CustomMeta		input your customized meta data and can be default
		* @InOssObjectMeta	default meta data of oss
		*/
		bool AppendObjectFromMemroy(const FString& InBucketName, const FString& InObjectName, const FString& InContent,
			int64& OutPosition, int64 InPosition = 0, const TMap<FString, FString>& CustomMeta = {},
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});
		
		/**
		* �Ӵ����ϴ�
		* @InBucketName		input oss bucket name
		* @InLoaclPath		input path of file in disk
		* @InObjectName		input objcet name in oss bucket and can be empty
		* @InProgress		input a callback about progress bar and can be nullptr
		* @CustomMeta		input your customized meta data and can be default
		* @InOssObjectMeta	default meta data of oss
		*/
		bool PutObjectFromDisk(const FString& InBucketName, const FString& InLocalPath, const FString& InObjectName = {},
			ProgressCallback InProgress = nullptr, const TMap<FString, FString>& CustomMeta = {}, 
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});

		void AsyncPutObjectFromDisk(const FString& InBucketName, const FString& InLocalPath, const FString& InObjectName = {},
			ProgressCallback InProgress = nullptr, const TMap<FString, FString>& CustomMeta = {},
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});


		/**
		* �ϵ����������������⵼���ϴ��ж�
		* @InBucketName			input oss bucket name
		* @InObjectName			input objcet name in oss bucket and can be empty
		* @InUploadFilePath		input path of file in disk
		* @InCheckPointFilePath	cache check point of uploaded file
		* @InProgress			input a callback about progress bar and can be nullptr
		* @CustomMeta			input your customized meta data and can be default
		* @InOssObjectMeta		default meta data of oss
		*/
		bool ResumableUploadObject(const FString& InBucketName, const FString& InUploadFilePath, const FString& InObjectName = {},
			const FString& InCheckPointFilePath = FPaths::ProjectSavedDir()/TEXT("OSSCache"), ProgressCallback InProgress = nullptr, 
			const TMap<FString, FString>& CustomMeta = {},const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});

		void AsyncResumableUploadObject(const FString& InBucketName, const FString& InUploadFilePath, const FString& InObjectName = {},
			const FString& InCheckPointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), ProgressCallback InProgress = nullptr,
			const TMap<FString, FString>& CustomMeta = {}, const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});


		/**
		* �����ļ��ķ�Ƭ�ϴ���һ�β��ܳ���5GB
		* @OutUploadId			output upload id by request
		* @InBucketName			input oss bucket name
		* @InObjectName			input objcet name in oss bucket and can be empty
		* @InLocalPath			input path of file in disk
		* @InPartSize			size per part
		* @InProgress			input a callback about progress bar and can be nullptr
		* @CustomMeta			input your customized meta data and can be default
		* @InOssObjectMeta		default meta data of oss
		*/
		bool UploadParts(FString& OutUploadId, const FString& InBucketName, const FString& InObjectName, 
			const FString& InLocalPath, int32 InPartSize = SizePerPart, UploadPartCallback InUploadPartCallback = nullptr,
			ProgressCallback InProgress = nullptr, const TMap<FString, FString>& CustomMeta = {}, 
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});

		void AsyncUploadParts(const FString& InBucketName, const FString& InObjectName,
			const FString& InLocalPath, int32 InPartSize = SizePerPart, UploadPartCallback InUploadPartCallback = nullptr,
			ProgressCallback InProgress = nullptr, const TMap<FString, FString>& CustomMeta = {}, 
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {});

		/**
		* �жϷ�Ƭ�ϴ�
		* @OutUploadId			output upload id by request
		* @InBucketName			input oss bucket name
		* @InObjectName			input objcet name in oss bucket and can be empty
		*/
		bool AbortUploadParts(const FString& InUploadId, const FString& InBucketName, const FString& InObjectName);



#pragma endregion

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////��Դ����////////////////////////////////////////////////////////
#pragma region Download
		/**
		* ���ص��ڴ�
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		* @OutContent		output content from net
		* @InRange			input range of bytes
		* @InProgress		input a callback about progress bar and can be nullptr
		*/
		bool GetObjectToMemory(const FString& InBucketName, const FString& InObjectName, FString& OutContent,
			SimpleOSS::OSS::FRange InRange = {}, ProgressCallback InProgress = nullptr);

		void AsyncGetObjectToMemory(const FString& InBucketName, const FString& InObjectName, FString& OutContent,
			SimpleOSS::OSS::FRange InRange = {}, ProgressCallback InProgress = nullptr);

		/**
		* ���ص�����
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		* @InLocalPath		input path using to store file in disk
		* @InRange			input range of bytes
		* @InProgress		input a callback about progress bar and can be nullptr
		*/
		bool GetObjectToDisk(const FString& InBucketName, const FString& InObjectName, const FString& InLocalPath,
			SimpleOSS::OSS::FRange InRange = {}, ProgressCallback InProgress = nullptr);

		void AsyncGetObjectToDisk(const FString& InBucketName, const FString& InObjectName, const FString& InLocalPath,
			SimpleOSS::OSS::FRange InRange = {}, ProgressCallback InProgress = nullptr);

		/**
		* �ϵ�����
		* @InBucketName			input oss bucket name
		* @InObjectName			input objcet name in oss bucket
		* @InLocalPath			input path using to store file in disk
		* @InCheckPointFilePath cache check point of uploaded file
		* @InProgress			input a callback about progress bar and can be nullptr
		*/
		bool ResumableDownloadObject(const FString& InBucketName, const FString& InObjectName, const FString& InLocalPath, 
			const FString& InCheckPointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange InRange = {},
			ProgressCallback InProgress = nullptr);

		void AsyncResumableDownloadObject(const FString& InBucketName, const FString& InObjectName, const FString& InLocalPath,
			const FString& InCheckPointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange InRange = {},
			ProgressCallback InProgress = nullptr);
		
#pragma endregion

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////����ɾ������////////////////////////////////////////////////////
#pragma region CopyObject
		
		/**
		* ���ص��ڴ�
		* @InSourceBucket	input oss bucket name that represents the bucket, used to copy object from this bucket
		* @InSourceObject	input objcet name in oss bucket that represents needed object
		* @InTargetBucket	input oss bucket name that represents the bucket, used to copy object to this bucket
		* @InTargetObject	input objcet name in oss bucket, can be customized
		* @InProgress		input a callback about progress bar and can be nullptr
		*/
		bool CopyObject(const FString& InSourceBucket, const FString& InSourceObject, const FString& InTargetBucket,
			const FString& InTargetObject, const TMap<FString, FString>& CustomMeta = {},
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {}, ProgressCallback InProgress = nullptr);
		
		void AsyncCopyObject(const FString& InSourceBucket, const FString& InSourceObject, const FString& InTargetBucket,
			const FString& InTargetObject, const TMap<FString, FString>& CustomMeta = {},
			const SimpleOSS::OSS::FOssObjectMeta& InOssObjectMeta = {}, ProgressCallback InProgress = nullptr);

		
		/**
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		*/
		bool DeleteObject(const FString& InBucketName, const FString& InObjectName, ProgressCallback InProgress = nullptr);

		/**
		* @InBucketName		input oss bucket name
		* @InObjectNames	input multiple objcet names in some bucket
		*/
		bool DeleteObjects(const FString& InBucketName, const TArray<FString>& InObjectNames, ProgressCallback InProgress = nullptr);

#pragma endregion

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////��Ƭ����////////////////////////////////////////////////////////
#pragma region OperateParts
		
		/**
		* �оٷ�Ƭ
		* @InUploadId		all parts belonging to a object share a UploadId 
		* @InBucketName		input oss bucket name
		* @InObjectName		input objcet name in oss bucket
		* @OutPartsInfo		output all info of part belonging to a object
		* @MaxParts			Max Number of parts
		* @InProgress		input a callback about progress bar and can be nullptr
		*/
		bool ListParts(const FString& InUploadId, const FString& InBucketName, const FString& InObjectName,
			TArray<SimpleOSS::OSS::FPartsInfo>& OutPartsInfo, int32 MaxParts = 500, ProgressCallback InProgress = nullptr);
		/**
		* �о�Ͱ�ڷ�Ƭ�ϴ��¼�
		* @InBucketName			input oss bucket name
		* @MultipartPartsInfo	output info of object processed parts 
		* @MaxParts				Max Number of MultipartPartsInfo
		* @InProgress			input a callback about progress bar and can be nullptr
		*/
		bool ListMultipartUploads(const FString& InBucketName, TArray<SimpleOSS::OSS::FMultipartUploadInfo>& MultipartPartsInfo,
			int32 MaxParts = 500, ProgressCallback InProgress = nullptr);

#pragma endregion


	private:
		/**
		* �����ص�ͼ����г�����ͨ�ýӿ�
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		* @InCommand	input command that is used to process image
		*/
		bool GetImageObject(const FString& InBucketName, const FString& InObjectName, const FString& InSavePath, const FString& InCommand);

	private:
		std::string AccessKeyId;
		std::string AccessKeySecret;
		std::string EndPoint;
		FCriticalSection Mutex;
		SimpleOSS::OSS::FClientConfiguration ClientConfig;
	};



	static FOSS& GetOSS(){
		return FSimpleOSSManage::Get()->Oss;
	}

private:
	FOSS Oss;


private:
	FSimpleOSSManage();
	FSimpleOSSManage(const FSimpleOSSManage&) = delete;
	FSimpleOSSManage& operator=(const FSimpleOSSManage&) = delete;

	static TSharedPtr<FSimpleOSSManage> OssManage;

};

#define Simple_Oss_Default_Init(InAccessKeyId, InAccessKeySecret, InEndPoint)\
FSimpleOSSManage::Get()->GetOSS().InitializeAccount(InAccessKeyId,\
	InAccessKeySecret, InEndPoint);\
FSimpleOSSManage::Get()->GetOSS().InitializeConfig()