
#include "EnginePCH.h"
#include "Application.h"
#include "../EngineHeaders.h"

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	WindowResizeEvent e(1280, 800);
	if (e.IsInCategory(EVENT_APPLICATION))
	{
		LOG_ENGINE_DEBUG(e);
	}

	while (true);
}
