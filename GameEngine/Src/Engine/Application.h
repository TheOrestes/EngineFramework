#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

class ENGINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};


