#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SmallEngine
{
	class SMALLENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log ºê
#define SE_CORE_TRACE(...) ::SmallEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)  ::SmallEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)  ::SmallEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...) ::SmallEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...) ::SmallEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log ºê
#define SE_CLIENT_TRACE(...) ::SmallEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_CLIENT_INFO(...)  ::SmallEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_CLIENT_WARN(...)  ::SmallEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_CLIENT_ERROR(...) ::SmallEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_CLIENT_FATAL(...) ::SmallEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)