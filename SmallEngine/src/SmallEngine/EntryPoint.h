#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SmallEngine::Application* SmallEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SmallEngine::CreateApplication();
	app->Run();
	delete app;
}

#else
#error SmallEngine only support Windows!

#endif
