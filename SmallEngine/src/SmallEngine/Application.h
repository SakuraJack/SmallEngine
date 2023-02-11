#pragma once

#include "Core.h"

namespace SmallEngine {

	class SMALLENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
