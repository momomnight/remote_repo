#pragma once
#if !(__cplusplus<202002L)

#include <coroutine>
#include <iostream>


namespace CustomizeCoroutine
{
	/// <summary>
	/// As template parameters, The class of callback that FCoRoutine uses
	/// </summary>
	struct FCoRoutineCallback
	{
		static constexpr void OnAwaitReady()		noexcept	{}
		static constexpr void OnAwaitSuspend()		noexcept	{}
		static constexpr void OnAwaitResume()		noexcept	{}

		static constexpr void OnInitialSuspend()	noexcept	{}
		static constexpr void OnReturn()			noexcept	{}
		static constexpr void OnYieldValue()		noexcept	{}
		static constexpr void OnFinalSuspend()		noexcept	{}
		static constexpr void OnException()			noexcept	{}
	};

	template<class CallBackClass>
	struct FSuspendNever
	{
		constexpr bool await_ready() const noexcept { CallBackClass::OnAwaitReady(); return true;}
		constexpr void await_suspend(std::coroutine_handle<>) const noexcept { CallBackClass::OnAwaitSuspend(); }
		constexpr void await_resume() const noexcept { CallBackClass::OnAwaitResume(); }
	};

	template<class CallBackClass>
	struct FSuspendAlways
	{
		constexpr bool await_ready() const noexcept { CallBackClass::OnAwaitReady(); return false; }
		constexpr void await_suspend(std::coroutine_handle<>) const noexcept { CallBackClass::OnAwaitSuspend(); }
		constexpr void await_resume() const noexcept { CallBackClass::OnAwaitResume(); }
	};

	enum class ECoRoutineType : unsigned char
	{
		CRT_Default			= 0,	//Suspend and Return_Void
		CRT_NoInitialSuspend= 1,
		CRT_ReturnValue		= 2,
		CRT_AllNoThread		= CRT_NoInitialSuspend | CRT_ReturnValue,
		CRT_UseThread		= 4,
		CRT_All				= CRT_AllNoThread | CRT_UseThread
	};

	template <class ReturnType, class CoRoutineClass, ECoRoutineType CoRoutineType, class CallbackClass>
	struct FPromiseType;

	template <class ReturnType>
	struct FReturnValue
	{
		ReturnType Result;
	};

	template <class ReturnType, ECoRoutineType CoRoutineType = ECoRoutineType::CRT_Default, class CallbackClass = FCoRoutineCallback>
	struct FPromiseTypeBase : FReturnValue<ReturnType>
	{
		using Super = FReturnValue<ReturnType>;
		using Super::Result;

		FSuspendAlways<CallbackClass> initial_suspend() noexcept
		{
			CallbackClass::OnInitialSuspend();
			return {};
		}

		void return_void()
		{
			CallbackClass::OnReturn();
		}
	};

	template<class ReturnType, class CallbackClass>
	struct FPromiseTypeBase<ReturnType, ECoRoutineType::CRT_ReturnValue, CallbackClass>
		: FReturnValue<ReturnType>
	{
		using Super = FReturnValue<ReturnType>;
		using Super::Result;

		FSuspendAlways<CallbackClass> initial_suspend() noexcept
		{
			CallbackClass::OnInitialSuspend();
			return {};
		}

		void return_value(ReturnType Ret)
		{
			CallbackClass::OnReturn();
			Result = Ret;
		}
	};

	template<class ReturnType, class CallbackClass>
	struct FPromiseTypeBase<ReturnType, ECoRoutineType::CRT_NoInitialSuspend, CallbackClass>
		: FReturnValue<ReturnType>
	{
		using Super = FReturnValue<ReturnType>;
		using Super::Result;

		FSuspendNever<CallbackClass> initial_suspend() noexcept
		{
			CallbackClass::OnInitialSuspend();
			return {};
		}

		void return_void()
		{
			CallbackClass::OnReturn();
		}
	};

	template<class ReturnType, class CallbackClass>
	struct FPromiseTypeBase<ReturnType, ECoRoutineType::CRT_AllNoThread, CallbackClass>
		: FReturnValue<ReturnType>
	{
		using Super = FReturnValue<ReturnType>;
		using Super::Result;

		FSuspendNever<CallbackClass> initial_suspend() noexcept
		{
			CallbackClass::OnInitialSuspend();
			return {};
		}

		void return_value(ReturnType Ret)
		{
			CallbackClass::OnReturn();
			Result = Ret;
		}
	};
	
	template <class ReturnType, class CoRoutineClass, ECoRoutineType CoRoutineType = ECoRoutineType::CRT_Default, class CallbackClass = FCoRoutineCallback>
	struct FPromiseType : FPromiseTypeBase<ReturnType, CoRoutineType, CallbackClass>
	{
		using Super = FPromiseTypeBase<ReturnType, CoRoutineType, CallbackClass>;
		using Super::Result;
		using promise_type = FPromiseType<ReturnType, CoRoutineClass, CoRoutineType, CallbackClass>;
		using FCoRoutineHandle = std::coroutine_handle<promise_type>;

		std::exception_ptr Exception;

		//1
		CoRoutineClass get_return_object()
		{
			CallbackClass::OnInitialSuspend();
			return { CoRoutineClass(FCoRoutineHandle::from_promise(*this)) };
		}

		FSuspendAlways<CallbackClass> final_suspend() noexcept
		{
			CallbackClass::OnFinalSuspend();
			return {};
		}

		template <std::convertible_to<ReturnType> From>
		FSuspendAlways<CallbackClass> yield_value(From&& Ret)
		{
			CallbackClass::OnYieldValue();
			Result = std::forward<From>(Ret);
			return {};
		}

		void unhandled_exception()
		{
			CallbackClass::OnException();
			Exception = std::current_exception();
		}
	};

	template <class ReturnType, ECoRoutineType CoRoutineType = ECoRoutineType::CRT_Default, class CallbackClass = FCoRoutineCallback>
	struct FCoRoutine
	{
		using promise_type = FPromiseType<ReturnType, FCoRoutine, CoRoutineType, CallbackClass>;
		using FCoRoutineHandle = promise_type::FCoRoutineHandle;

		//2
		FCoRoutine(FCoRoutineHandle Handle) : Promise(Handle){}
		~FCoRoutine() noexcept { CoRoutineHandle.destroy(); }
		
		//3
		FCoRoutineHandle CoRoutineHandle;
		promise_type Promise;
	public:
		explicit operator bool()
		{
			return !Promise.CoRoutineHandle.done();
		}

		void Resume()
		{
			if(!Promise.CoRoutineHandle.done())
			{
				Promise.CoRoutineHandle();
			}
		}
	
	};


	//the custom way
	template <class ReturnType, ECoRoutineType CoRoutineType = ECoRoutineType::CRT_Default, class CallbackClass = FCoRoutineCallback>
	struct FCoRoutineCustomize
	{
		
		explicit operator bool()
		{
			Fill();
			return !CoRoutineHandle.done();
		}
		
		ReturnType operator()()
		{
			Fill();
			bFull = false;
			return std::move(CoRoutineHandle.promise().Result);
		}

	private:
		bool bFull = false;

		void Fill()
		{
			if (!bFull)
			{
				CoRoutineHandle();
				if (CoRoutineHandle.promise().Exception)
				{
					std::rethrow_exception(CoRoutineHandle.promise().Exception);
				}
				bFull = true;
			}
		}
	public:
		//necessary
		using promise_type = FPromiseType<ReturnType, FCoRoutineCustomize, CoRoutineType, CallbackClass>;
		using FCoRoutineHandle = promise_type::FCoRoutineHandle;

		FCoRoutineCustomize(FCoRoutineHandle Handle) :CoRoutineHandle(Handle) {}
		~FCoRoutineCustomize() noexcept {CoRoutineHandle.destroy(); }
		
		FCoRoutineHandle CoRoutineHandle;
		promise_type Promise;
	};




	//#define	COROUTINE_CPP20(ReturnType, CoRoutineType, CallbackClass) \
		//FCoRoutine<ReturnType, CoRoutineType, CallbackClass>

	//#define COROUTINE_DELEGATE(DelegateName, CoRoutineClass, ...) \
		//FUNC_DECLARE_DELEGATE(DelegateName, CoRoutineClass, __VA_ARGS__) 

	//#define COROUTINE_DELEGATE_DEFAULT(ReturnType, ...) \
		//COROUTINE_DELEGATE(FCoroutineDelegateDefault, COROUTINE_CPP20(ReturnType, ECoRoutineType::CRT_Default, FCoRoutineCallback), __VA_ARGS__)
	
	//COROUTINE_DELEGATE(FCoroutineDelegateDefault, COROUTINE_CPP20(int, ECoRoutineType::CRT_Default, FCoRoutineCallback))
	//COROUTINE_DELEGATE_DEFAULT(int);
	//typedef TDelegate<FCoRoutine<int, ECoRoutineType::CRT_Default, FCoRoutineCallback>()> DelegateName;
	//FCoroutineDelegateDefault x;



	//FCoRoutine<int> gun()
	//{
		//co_return;
	//}

	//void fun()
	//{
		//x.BindStatic(&gun);
		//FSimpleDelegate;
	//}
}

#endif

	
