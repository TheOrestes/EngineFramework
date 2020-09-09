#pragma once

#include "Core.h"

class ENGINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};

// To be defined in Game
Application* CreateApplication();
