
#include "EnginePCH.h"
#include "Log.h"
#include "EngineHeaders.h"
#include "ApplicationWindow.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicationWindow::Init()
{
	if (!glfwInit())
	{
		LOG_ENGINE_CRITICAL("GLFW Init failed");
		return;
	}

	glfwWindowHint(GLFW_RESIZABLE, true);

	// Create Window
	m_pWindow = glfwCreateWindow(m_uiWidth, m_uiHeight, m_strTitle.c_str(), nullptr, nullptr);

	if (!m_pWindow)
	{
		LOG_ENGINE_ERROR("Creating Window {0} ({1}, {2}) Failed!", m_strTitle, m_uiWidth, m_uiHeight);
		return;
	}
	else
	{
		LOG_ENGINE_INFO("Creating Window {0} ({1}, {2}) Successful!", m_strTitle, m_uiWidth, m_uiHeight);
	}

	// Create context for the same window
	glfwMakeContextCurrent(m_pWindow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicationWindow::Shutdown()
{
	glfwDestroyWindow(m_pWindow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicationWindow::Update()
{
	while (!glfwWindowShouldClose(m_pWindow))
	{
		glfwPollEvents();
		glfwSwapBuffers(m_pWindow);
	}
}
