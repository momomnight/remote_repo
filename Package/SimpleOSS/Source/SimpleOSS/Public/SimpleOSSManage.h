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
///////////////////////////////////////////////////////桶操作////////////////////////////////////////////////////////
#pragma region Bucket

		/**
		* 创建桶
		* @InBucketName input oss bucket name
		*/
		bool CreateBucket(const FString& InBucketName, SimpleOSS::OSS::EOssStorageType InStorageType = SimpleOSS::OSS::EOssStorageType::ST_Standard,
			SimpleOSS::OSS::EAcl InAcl = SimpleOSS::OSS::EAcl::Acl_Default);

		/**
		* 列举桶的名字
		* @OutBucketName output listed oss bucket names
		*/
		bool ListBucket(TArray<FString>& OutBucketName);

		/**
		* 获取桶的地域
		* @InBucketName input oss bucket name
		* @OutBucketLocation output oss bucket location
		*/
		bool GetBucketLocation(const FString& InBucketName, FString& OutBucketLocation);

		/**
		* 删除桶
		* @InBucketName input oss bucket name
		*/
		bool DeleteBucket(const FString& InBucketName);

		/**
		* 设置桶的读写权限
		* @InBucketName input oss bucket name
		* @InBucketAcl input bucket acl you need
		*/
		bool SetBucketAcl(const FString& InBucketName, SimpleOSS::OSS::EAcl InBucketAcl);

		/**
		* 获取桶的读写权限
		* @InBucketName input oss bucket name
		* @return output bucket acl you need
		*/
		SimpleOSS::OSS::EAcl GetBucketAcl(const FString& InBucketName);
	
		/**
		* 设置请求者付费模式
		* @InBucketName input oss bucket name
		* @InPayerType input payer type you need
		*/
		bool SetBucketRequestPayment(const FString& InBucketName, SimpleOSS::OSS::ERequestPayerType InPayerType);

		/**
		* 获取请求者付费模式
		* @InBucketName input oss bucket name
		* @return output payer type you need
		*/
		SimpleOSS::OSS::ERequestPayerType GetBucketRequestPayment(const FString& InBucketName);
		
		/**
		* 设置防盗链
		* @InBucketName input oss bucket name
		* @URLReferer input Referer list
		* @bAllowEmptyReferer Does allow to exist empty Referer? 
		*/
		bool SetBucketReferer(const FString& InBucketName, const TArray<FString>& URLReferer, bool bAllowEmptyReferer = false);
		
		/**
		* 获取防盗链
		* @InBucketName   input oss bucket name
		* @OutRefererList output referers
		*/
		bool GetBucketReferer(const FString& InBucketName, SimpleOSS::OSS::FRefererList& OutRefererList);
		
		/**
		* 删除防盗链
		* @InBucketName input oss bucket name
		* @bAllowEmptyReferer Does allow to exist empty Referer?
		*/
		bool DeleteBucketReferer(const FString& InBucketName, bool bAllowEmptyReferer = true);

		/**
		* 查询桶是否存在
		* @InBucketName input oss bucket name
		*/
		bool DoesBucketExist(const FString& InBucketName);
#pragma endregion
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////对象操作////////////////////////////////////////////////////////
#pragma region Object			
		/**
		* 获取对象元数据
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @OutMeta		output oss object meta
		*/
		bool GetObjectMeta(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::FOssObjectMeta& OutMeta);
		
		//有些字段无法设置，具体查看阿里的OSS sdk手册
		bool GetObjectMeta(const FString& InBucketName, const FString& InObjectName, const FString& InField, FString& OutValue);
		bool SetObjectMeta(const FString& InBucketName, const FString& InObjectName, const FString& InField, const FString& InValue);

		/**
		* 获取对象的读写权限
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @return		output oss object acl
		*/
		SimpleOSS::OSS::EAcl GetObjcetAcl(const FString& InBucketName, const FString& InObjectName);

		/**
		* 设置对象的读写权限
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InAcl		input oss object acl
		*/
		bool SetObjcetAcl(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EAcl InAcl);

		/**
		* 查看对象是否存在
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		*/
		bool DoesObjectExist(const FString& InBucketName, const FString& InObjectName);

		/**
		* 列举桶下所有对象，可以设定限度
		* @InBucketName input oss bucket name
		* @OutObjectInfo output Info of Objects
		* @MaxNumber	input max number of listed objects
		*/
		bool ListObjects(const FString& InBucketName, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo, int32 MaxNumber = 100);

		/**
		* 列举拥有前缀的对象，名字到Delimiter为止
		* @InBucketName input oss bucket name
		* @InKeyPrefix 用于查询带有keyprefix的所有对象（文件结构都是字符串）
		* @OutObjectInfo output Info of Objects
		* @MaxNumber	input max number of listed objects
		*/
		bool ListObjectsByPrefix(const FString& InBucketName, const FString& InKeyPrefix, const FString& InDelimiter, TArray<SimpleOSS::OSS::FOssObjectInfo>& OutObjectInfo);

		/**
		* 设置对象储存类型
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InStorageType storage type of object
		*/
		bool SetObjectStorageType(const FString& InBucketName, const FString& InObjectName, SimpleOSS::OSS::EOssStorageType InStorageType);

		/**
		* 获取对象储存类型
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @return		output storage type of object
		*/
		SimpleOSS::OSS::EOssStorageType GetObjectStorageType(const FString& InBucketName, const FString& InObjectName);

		/**
		* 创建软链接
		* @InBucketName input oss bucket name
		* @InObjectName input oss object name
		* @InLinkObjectName input symlink name you need
		*/
		bool CreateSymlink(const FString& InBucketName, const FString& InObjectName, const FString& InLinkObjectName);

		/**
		* 获取软链接
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
/////////////////////////////////////////////////////图像处理////////////////////////////////////////////////////////
#pragma region ImageProcess

		/**
		* 缩放
		* @InWay		input Way that include new size
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByResize(const FVector2D& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 裁剪
		* @InWay		input Way that include pos and new size
		* @Ratio
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByCrop(const FVector4& InWay, int32 Ratio, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 锐化
		* @InWay		input Way that include a value
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectBySharpen(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 水印
		* @InWay		input Way that include a string
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByWaterMark(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 旋转
		* @InWay		input Way that include a value
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByRotate(int32 InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 使用OSS自定义图片模板样式
		* @InWay		input Way that include a OssStyleName
		* @InBucketName input oss bucket name
		* @InObjectName input objcet name in oss bucket
		* @InSavePath	input path in disk
		*/
		bool GetImageObjectByStyle(const FString& InWay, const FString& InBucketName, const FString& InObjectName, const FString& InSavePath);

		/**
		* 级联处理
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
/////////////////////////////////////////////////////资源上传////////////////////////////////////////////////////////
#pragma region Upload

		/**
		* 从内存上传
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
		* 追加上传
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
		* 从磁盘上传
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
		* 断点续传，用于因意外导致上传中断
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
		* 大型文件的分片上传，一次不能超过5GB
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
		* 中断分片上传
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
/////////////////////////////////////////////////////资源下载////////////////////////////////////////////////////////
#pragma region Download
		/**
		* 下载到内存
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
		* 下载到磁盘
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
		* 断点续传
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
/////////////////////////////////////////////////////拷贝删除对象////////////////////////////////////////////////////
#pragma region CopyObject
		
		/**
		* 下载到内存
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
/////////////////////////////////////////////////////分片操作////////////////////////////////////////////////////////
#pragma region OperateParts
		
		/**
		* 列举分片
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
		* 列举桶内分片上传事件
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
		* 对下载的图像进行出来的通用接口
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