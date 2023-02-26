#pragma once

#include "sepzh.h"

#include "SmallEngine/Core.h"
#include "SmallEngine/Events/Event.h"

namespace SmallEngine {
	
	//窗口属性
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Small Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}
	};

	//界面
	class SMALLENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}
