#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SMALLENGINE_API _declspec(dllexport)
	#else
		#define SMALLENGINE_API _declspec(dllimport)
	#endif
#else
	#error SmallEngine only support Windows!

#endif

#ifdef SE_ENABLE_ASSERTS
	#define SE_ASSERT(x, ...) { if(!(x)) { SE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SE_CORE_ASSERT(x, ...) { if(!(x)) { SE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define SE_ASSERT(x, ...)
	#define SE_CORE_ASSERT(x, ...)
#endif // SE_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define SE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
