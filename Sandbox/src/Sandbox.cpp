#include "SmallEngine.h"
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/scalar_constants.hpp"

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.f, 0.f, 0.f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 Model = glm::scale(glm::mat4(1.f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer : public SmallEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		if (SmallEngine::Input::IsKeyPressed(SE_KEY_TAB))
			SE_CLIENT_INFO("Tab key is pressed!");
	}

	void OnEvent(SmallEngine::Event& e) override
	{
		//SE_CLIENT_TRACE("{0}", e.ToString());
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