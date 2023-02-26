#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SmallEngine::Application* SmallEngine::CreateApplication();

int main(int argc, char** argv)
{
	SmallEngine::Log::Init();
	SE_CORE_WARN("Initialized Log!");
	int a = 5;
	SE_CLIENT_INFO("Hello! Var={0}", a);

	auto app = SmallEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif
