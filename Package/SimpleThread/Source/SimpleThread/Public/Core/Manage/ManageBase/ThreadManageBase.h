
#pragma once

#include "CoreMinimal.h"
#include <type_traits>

/// <summary>
/// Bind	同步绑定, 阻塞调用线程
/// Create	异步绑定, 任务完成后自动销毁
/// </summary>
/// <typeparam name="FTask"></typeparam>
/// <typeparam name="ReturnType"></typeparam>

template <class FTask, class ReturnType = void>
class TThreadTemplateBase : public FTask
{
public:
	static_assert(std::is_same<ReturnType, void>::value || std::is_same < ReturnType, decltype(static_cast<FTask*>(nullptr)->FTask::operator>>(FSimpleDelegate())) > ::value,
		"Please be careful of ReturnType");

	TThreadTemplateBase() : FTask(){}

	//Raw
	template <class UserClass, class... VarTypes>
	ReturnType CreateRaw(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateRaw<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateRaw(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		
		return (ReturnType)(*this >> FSimpleDelegate::CreateRaw<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	//Static
	template <class... VarTypes>
	ReturnType CreateStatic(typename TIdentity<void(*)(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateStatic<VarTypes...>(InMethod,
			Forward<VarTypes>(Vars)...));
	}

	//Lambda
	template <class FunctorType, class... VarTypes>
	ReturnType CreateLambda(FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateLambda<FunctorType, VarTypes...>(Forward<FunctorType>(InFunctor),
			Forward<VarTypes>(Vars)...));
	}

	//UObject
	template <class UserClass, class... VarTypes>
	ReturnType CreateUObject(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateUObject(TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateUObject(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateUObject(TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	//UFunction
	template <class UObjectTemplate, class... VarTypes>
	ReturnType CreateUFunction(UObjectTemplate* InUserObject, const FName& InFunctionName, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject, InFunctionName,
			Forward<VarTypes>(Vars)...));
	}

	template <class UObjectTemplate, class... VarTypes>
	ReturnType CreateUFunction(TObjectPtr<UObjectTemplate> InUserObject, const FName& InFunctionName, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject, InFunctionName,
			Forward<VarTypes>(Vars)...));
	}

	//SP
	template <class UserClass, class... VarTypes>
	ReturnType CreateSP(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	ReturnType CreateSP(const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateSP(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{		
		return (ReturnType)(*this >> FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	ReturnType CreateSP(const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	//SPLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	ReturnType CreateSPLambda(UserClass* InUserObject, FunctorType&& Functor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateSPLambda<UserClass, FunctorType, VarTypes...>(InUserObject,
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class FunctorType, class... VarTypes>
	ReturnType CreateSPLambda(const TSharedRef<UserClass, Mode>& InUserObjectRef, FunctorType&& Functor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateSPLambda<UserClass, Mode, FunctorType, VarTypes...>(InUserObjectRef,
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...));
	}

	//SafeSP
	template <class UserClass, class... VarTypes>
	ReturnType CreateThreadSafeSP(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateThreadSafeSP(const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		static_assert(!TIsConst<UserClass>::Value, "Attempting to bind a delegate with a const object pointer and non-const member function.");
		return (ReturnType)(*this >> FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateThreadSafeSP(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType CreateThreadSafeSP(const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef, InMethod,
			Forward<VarTypes>(Vars)...));
	}

	//WeakLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	ReturnType CreateWeakLambda(UserClass* InUserObject, FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this >> FSimpleDelegate::CreateWeakLambda<UserClass, FunctorType, VarTypes...>(InUserObject,
			Forward<FunctorType>(InFunctor), Forward<VarTypes>(Vars)...));
	}
};



template <class FTask, class ReturnType = void>
class TThreadTemplate : public TThreadTemplateBase<FTask, ReturnType>
{
public:
	static_assert(std::is_same<ReturnType, void>::value || std::is_same < ReturnType, decltype(static_cast<FTask*>(nullptr)->FTask::operator>>(FSimpleDelegate()))>::value,
		"Please be careful of ReturnType");
	
	TThreadTemplate() : TThreadTemplateBase<FTask, ReturnType>(){}

	//Raw
	template <class UserClass, class... VarTypes>
	ReturnType BindRaw(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateRaw<UserClass, VarTypes...>(InUserObject, InMethod, 
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindRaw(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateRaw<UserClass, VarTypes...>(InUserObject, InMethod, 
			Forward<VarTypes>(Vars)...));
	}

	//Static
	template <class... VarTypes>
	ReturnType BindStatic(typename TIdentity<void(*)(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateStatic<VarTypes...>(InMethod, 
			Forward<VarTypes>(Vars)...));
	}

	//Lambda
	template <class FunctorType, class... VarTypes>
	ReturnType BindLambda(FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateLambda<FunctorType, VarTypes...>(Forward<FunctorType>(InFunctor), 
			Forward<VarTypes>(Vars)...));
	}

	//UObject
	template <class UserClass, class... VarTypes>
	ReturnType BindUObject(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindUObject(TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindUObject(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindUObject(TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	//UFunction
	template <class UObjectTemplate, class... VarTypes>
	ReturnType BindUFunction(UObjectTemplate* InUserObject, const FName& InFunctionName, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject,
			InFunctionName, Forward<VarTypes>(Vars)...));
	}

	template <class UObjectTemplate, class... VarTypes>
	ReturnType BindUFunction(TObjectPtr<UObjectTemplate> InUserObject, const FName& InFunctionName, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject,
			InFunctionName, Forward<VarTypes>(Vars)...));
	}

	//SP
	template <class UserClass, class... VarTypes>
	ReturnType BindSP(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod, 
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	ReturnType BindSP(const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindSP(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod, 
			Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	ReturnType BindSP(const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	//SPLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	ReturnType BindSPLambda(UserClass* InUserObject, FunctorType&& Functor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSPLambda<UserClass, FunctorType, VarTypes...>(InUserObject, 
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, ESPMode Mode, class FunctorType, class... VarTypes>
	ReturnType BindSPLambda(const TSharedRef<UserClass, Mode>& InUserObjectRef, FunctorType&& Functor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateSPLambda<UserClass, Mode, FunctorType, VarTypes...>(InUserObjectRef, 
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...));
	}

	//SafeSP
	template <class UserClass, class... VarTypes>
	ReturnType BindThreadSafeSP(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindThreadSafeSP(const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef, typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindThreadSafeSP(const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject, 
			InMethod, Forward<VarTypes>(Vars)...));
	}

	template <class UserClass, class... VarTypes>
	ReturnType BindThreadSafeSP(const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef, typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...));
	}

	//WeakLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	ReturnType BindWeakLambda(UserClass* InUserObject, FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		return (ReturnType)(*this << FSimpleDelegate::CreateWeakLambda<UserClass, FunctorType, VarTypes...>(InUserObject, 
			Forward<FunctorType>(InFunctor), Forward<VarTypes>(Vars)...));
	}


	
};