#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"


// Bind 绑定延迟时间和协程代理，由FThreadManage去Tick
// Create 直接绑定协程代理，由FThreadManage去Tick，但没有延迟时间
struct SIMPLETHREAD_API FCoRoutinesManage
	: TThreadTemplateBase<ICoroutinesContainer, FCoroutineHandle>
{
private:
	FCoRoutinesManage();
	FCoRoutinesManage(const FCoRoutinesManage&) = delete;
	FCoRoutinesManage& operator=(const FCoRoutinesManage&) = delete;

	static TSharedPtr<FCoRoutinesManage> CoRoutinesManage;

public:

	static TSharedRef<FCoRoutinesManage> Get();
	static void Destroy();

	void Tick(float);


	template <class UserClass, class... VarTypes>
	void BindRaw(float InTotalTime, UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateRaw(InUserObject, InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindRaw(float InTotalTime, const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateRaw<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...);
	}

	//Static
	template <class... VarTypes>
	void BindStatic(float InTotalTime, typename TIdentity<void(*)(std::decay_t<VarTypes>...)>::Type InMethod,
		VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateStatic<VarTypes...>(InMethod,
			Forward<VarTypes>(Vars)...);
	}

	//Lambda
	template <class FunctorType, class... VarTypes>
	void BindLambda(float InTotalTime, FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateLambda<FunctorType, VarTypes...>(Forward<FunctorType>(InFunctor),
			Forward<VarTypes>(Vars)...);
	}

	//UObject
	template <class UserClass, class... VarTypes>
	void BindUObject(float InTotalTime, UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindUObject(float InTotalTime, TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<false, 
		UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindUObject(float InTotalTime, const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindUObject(float InTotalTime, TObjectPtr<UserClass> InUserObject, typename TMemFunPtrType<true, 
		UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUObject<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	//UFunction
	template <class UObjectTemplate, class... VarTypes>
	void BindUFunction(float InTotalTime, UObjectTemplate* InUserObject, const FName& InFunctionName, 
		VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject,
			InFunctionName, Forward<VarTypes>(Vars)...);
	}

	template <class UObjectTemplate, class... VarTypes>
	void BindUFunction(float InTotalTime, TObjectPtr<UObjectTemplate> InUserObject, const FName& InFunctionName, 
		VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateUFunction<UObjectTemplate, VarTypes...>(InUserObject,
			InFunctionName, Forward<VarTypes>(Vars)...);
	}

	//SP
	template <class UserClass, class... VarTypes>
	void BindSP(float InTotalTime, UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	void BindSP(float InTotalTime, const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<false, 
		UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindSP(float InTotalTime, const UserClass* InUserObject, typename TMemFunPtrType<true, UserClass, 
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSP<UserClass, VarTypes...>(InUserObject, InMethod,
			Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, ESPMode Mode, class... VarTypes>
	void BindSP(float InTotalTime, const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<true, 
		UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSP<UserClass, Mode, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	//SPLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	void BindSPLambda(float InTotalTime, UserClass* InUserObject, FunctorType&& Functor, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSPLambda<UserClass, FunctorType, VarTypes...>(InUserObject,
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, ESPMode Mode, class FunctorType, class... VarTypes>
	void BindSPLambda(float InTotalTime, const TSharedRef<UserClass, Mode>& InUserObjectRef, 
		FunctorType&& Functor, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateSPLambda<UserClass, Mode, FunctorType, VarTypes...>(InUserObjectRef,
			Forward<FunctorType>(Functor), Forward<VarTypes>(Vars)...);
	}

	//SafeSP
	template <class UserClass, class... VarTypes>
	void BindThreadSafeSP(float InTotalTime, UserClass* InUserObject, typename TMemFunPtrType<false, UserClass,
		void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindThreadSafeSP(float InTotalTime, const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef,
		typename TMemFunPtrType<false, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindThreadSafeSP(float InTotalTime, const UserClass* InUserObject, typename TMemFunPtrType<true,
		UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObject,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	template <class UserClass, class... VarTypes>
	void BindThreadSafeSP(float InTotalTime, const TSharedRef<UserClass, ESPMode::ThreadSafe>& InUserObjectRef, 
		typename TMemFunPtrType<true, UserClass, void(std::decay_t<VarTypes>...)>::Type InMethod, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateThreadSafeSP<UserClass, VarTypes...>(InUserObjectRef,
			InMethod, Forward<VarTypes>(Vars)...);
	}

	//WeakLambda
	template <class UserClass, class FunctorType, class... VarTypes>
	void BindWeakLambda(float InTotalTime, UserClass* InUserObject, FunctorType&& InFunctor, VarTypes&&... Vars)
	{
		*this << InTotalTime << FSimpleDelegate::CreateWeakLambda<UserClass, FunctorType, VarTypes...>(InUserObject,
			Forward<FunctorType>(InFunctor), Forward<VarTypes>(Vars)...);
	}

};