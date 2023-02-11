#include "SmallEngine.h"

class Sandbox : public SmallEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

SmallEngine::Application* SmallEngine::CreateApplication()
{
	return new Sandbox();
}