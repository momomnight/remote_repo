#pragma once
#include "alibabacloud/oss/OssClient.h"
#include "CoreMinimal.h"

#define STR_COMBINE_INNER(A, B) A##B
#define STR_COMBINE(A, B) STR_COMBINE_INNER(A, B)

#define TO_STR_INNER(A) #A
#define TO_STR(A) TO_STR_INNER(A)

#define SIMPLE_OSS_ERROR_CODE(Outcome) Outcome.error().Code()
#define SIMPLE_OSS_ERROR_MSG(Outcome) Outcome.error().Message()
#define SIMPLE_OSS_ERROR_REQ_ID(Outcome) Outcome.error().RequestId()
#define SIMPLE_OSS_ERROR_HOST(Outcome) Outcome.error().Host()

#define SIMPLE_OSS_ERROR(PrintFunction, Outcome)\
PrintFunction(SIMPLE_OSS_ERROR_MSG(Outcome));\
PrintFunction(SIMPLE_OSS_ERROR_CODE(Outcome));\
PrintFunction(SIMPLE_OSS_ERROR_REQ_ID(Outcome));\
PrintFunction(SIMPLE_OSS_ERROR_HOST(Outcome))

#define SIMPLE_OSS_SET_META(MetaDataName)\
OSS::ObjectMetaData MetaDataName;\
{\
	if (!InOssObjectMeta.ContentType.IsEmpty())\
	{\
		MetaDataName.setContentType(TCHAR_TO_UTF8(*InOssObjectMeta.ContentType));\
	}\
	if (!InOssObjectMeta.CacheControl.IsEmpty())\
	{\
		MetaDataName.setCacheControl(TCHAR_TO_UTF8(*InOssObjectMeta.CacheControl));\
	}\
	if (!InOssObjectMeta.ContentDisposition.IsEmpty())\
	{\
		MetaDataName.setContentDisposition(TCHAR_TO_UTF8(*InOssObjectMeta.ContentDisposition));\
	}\
	if (!InOssObjectMeta.ContentEncoding.IsEmpty())\
	{\
		MetaDataName.setContentEncoding(TCHAR_TO_UTF8(*InOssObjectMeta.ContentEncoding));\
	}\
	if (!InOssObjectMeta.ContentMd5.IsEmpty())\
	{\
		MetaDataName.setContentMd5(TCHAR_TO_UTF8(*InOssObjectMeta.ContentMd5));\
	}\
	if (!InOssObjectMeta.ExpirationTime.IsEmpty())\
	{\
		MetaDataName.setExpirationTime(TCHAR_TO_UTF8(*InOssObjectMeta.ExpirationTime));\
	}\
}\
for (auto& Temp : CustomMeta)\
{\
	MetaDataName.UserMetaData()[TCHAR_TO_UTF8(*Temp.Key)] = TCHAR_TO_UTF8(*Temp.Value);\
}

#define SIMPLE_OSS_SET_META_BY_REF(Request)\
OSS::ObjectMetaData& MetaDataName = Request.MetaData();\
{\
	if (!InOssObjectMeta.ContentType.IsEmpty())\
	{\
		MetaDataName.setContentType(TCHAR_TO_UTF8(*InOssObjectMeta.ContentType));\
	}\
	if (!InOssObjectMeta.CacheControl.IsEmpty())\
	{\
		MetaDataName.setCacheControl(TCHAR_TO_UTF8(*InOssObjectMeta.CacheControl));\
	}\
	if (!InOssObjectMeta.ContentDisposition.IsEmpty())\
	{\
		MetaDataName.setContentDisposition(TCHAR_TO_UTF8(*InOssObjectMeta.ContentDisposition));\
	}\
	if (!InOssObjectMeta.ContentEncoding.IsEmpty())\
	{\
		MetaDataName.setContentEncoding(TCHAR_TO_UTF8(*InOssObjectMeta.ContentEncoding));\
	}\
	if (!InOssObjectMeta.ContentMd5.IsEmpty())\
	{\
		MetaDataName.setContentMd5(TCHAR_TO_UTF8(*InOssObjectMeta.ContentMd5));\
	}\
	if (!InOssObjectMeta.ExpirationTime.IsEmpty())\
	{\
		MetaDataName.setExpirationTime(TCHAR_TO_UTF8(*InOssObjectMeta.ExpirationTime));\
	}\
}\
for (auto& Temp : CustomMeta)\
{\
	MetaDataName.UserMetaData()[TCHAR_TO_UTF8(*Temp.Key)] = TCHAR_TO_UTF8(*Temp.Value);\
}

#define SIMPLE_OSS_SET_PROGRESS(Request, InProgress)\
if (InProgress)\
{\
	OSS::TransferProgress ProgressCallback{ InProgress, nullptr };\
	Request.setTransferProgress(ProgressCallback);\
}

#define SIMPLE_OSS_SET_RANGE(Request, FRange)\
if (FRange.IsValid())\
{\
	Request.setRange(FRange.Start, FRange.End);\
}