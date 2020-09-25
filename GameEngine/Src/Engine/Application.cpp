
#include "EnginePCH.h"
#include "Application.h"
#include "../EngineHeaders.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Application::Application()
{
	m_pAppWindow = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Application::~Application()
{
	Shutdown();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::Init()
{
	m_pAppWindow = new ApplicationWindow();
	m_pAppWindow->Init();

	GLFWwindow* pWindow = m_pAppWindow->getWindowPtr();

	// Register Events! 
	glfwSetWindowCloseCallback(pWindow, EventWindowClosedCallback);
	glfwSetWindowSizeCallback(pWindow, EventWindowResizedCallback);
	glfwSetKeyCallback(pWindow, EventKeyHandlerCallback);
	glfwSetCursorPosCallback(pWindow, EventMousePositionCallback);
	glfwSetMouseButtonCallback(pWindow, EventMouseButtonCallback);
	glfwSetScrollCallback(pWindow, EventMouseScrollCallback);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::Run()
{
	Init();

	m_pAppWindow->Update();
	m_pAppWindow->Shutdown();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::Shutdown()
{
	SAFE_DELETE(m_pAppWindow);
}

//----------------------------------------------------- EVENTS --------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventWindowClosedCallback(GLFWwindow* pWindow)
{
	EventWindowClose closeEvent(pWindow);
	closeEvent.Dispatch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventWindowResizedCallback(GLFWwindow* pWindow, int width, int height)
{
	EventWindowResize resizeEvent(pWindow, width, height);
	resizeEvent.Dispatch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventKeyHandlerCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	EventKey keyEvent(pWindow, key, scancode, action, mods);
	keyEvent.Dispatch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventMousePositionCallback(GLFWwindow* pWindow, double xPos, double yPos)
{
	EventMouseMovement	mouseMovementEvent(pWindow, xPos, yPos);
	mouseMovementEvent.Dispatch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventMouseButtonCallback(GLFWwindow* pWindow, int button, int action, int mods)
{
	EventMouseButton mouseButtonEvent(pWindow, button, action, mods);
	mouseButtonEvent.Dispatch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Application::EventMouseScrollCallback(GLFWwindow* pWindow, double xOffset, double yOffset)
{
	EventMouseScroll mouseScroll(pWindow, xOffset, yOffset);
	mouseScroll.Dispatch();
}
