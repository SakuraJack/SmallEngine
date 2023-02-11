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
