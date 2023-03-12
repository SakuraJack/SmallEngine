#pragma once

#include "SmallEngine/Layer.h"
#include "SmallEngine/Events/ApplicationEvent.h"
#include "SmallEngine/Events/KeyEvent.h";
#include "SmallEngine/Events/MouseEvent.h"

namespace SmallEngine
{
	class SMALLENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}