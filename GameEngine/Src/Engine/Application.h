#pragma once

#include "Core.h"
#include "ApplicationWindow.h"
#include "Events/Events.h"

class ENGINE_API Application
{
public:
	Application();
	virtual ~Application();

	void	Init();
	void	Run();
	void	Shutdown();

	//-- EVENTS
	static void			EventWindowClosedCallback(GLFWwindow* pWindow);
	static void			EventWindowResizedCallback(GLFWwindow* pWindow, int width, int height);
	static void			EventKeyHandlerCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods);
	static void			EventMousePositionCallback(GLFWwindow* pWindow, double xPos, double yPos);
	static void			EventMouseButtonCallback(GLFWwindow* pWindow, int button, int action, int mods);
	static void			EventMouseScrollCallback(GLFWwindow* pWindow, double xOffset, double yOffset);

private:
	ApplicationWindow*	m_pAppWindow;
};


