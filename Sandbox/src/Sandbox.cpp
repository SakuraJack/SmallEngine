#include "SmallEngine.h"

class ExampleLayer : public SmallEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		SE_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(SmallEngine::Event& e) override
	{
		SE_CLIENT_TRACE("{0}", e.ToString());
	}
};

class Sandbox : public SmallEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SmallEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

SmallEngine::Application* SmallEngine::CreateApplication()
{
	return new Sandbox();
}