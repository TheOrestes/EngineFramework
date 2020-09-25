#include "EnginePCH.h"
#include "Events.h"
#include "EngineHeaders.h"
#include "Engine/Log.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventWindowClose::Dispatch()
{
	LOG_ENGINE_DEBUG("WINDOW CLOSE EVENT");
	glfwSetWindowShouldClose(m_pWindow, true);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventWindowResize::Dispatch()
{
	LOG_ENGINE_DEBUG("WINDOW RESIZE EVENT ({0}, {1} )", m_uiWidth, m_uiHeight);
	glfwSetWindowSize(m_pWindow, m_uiWidth, m_uiHeight);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventKey::Dispatch()
{
	switch (m_uiAction)
	{
		case GLFW_PRESS:
		{
			LOG_ENGINE_DEBUG("KEY PRESSED {0}", m_uiKey);
			break;
		}

		case GLFW_RELEASE:
		{
			LOG_ENGINE_DEBUG("KEY RELEASED {0}", m_uiKey);
			break;
		}

		case GLFW_REPEAT:
		{
			LOG_ENGINE_DEBUG("KEY REPEAT {0}", m_uiKey);
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventMouseMovement::Dispatch()
{
	LOG_ENGINE_DEBUG("MOUSE MOVEMENT EVENT POSITION: ({0}, {1} )", m_dPosX, m_dPosY);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventMouseButton::Dispatch()
{
	switch (m_uiButton)
	{
		case GLFW_MOUSE_BUTTON_LEFT:
		{
			if (m_uiAction == GLFW_PRESS)
				LOG_ENGINE_DEBUG("LEFT MOUSE CLICK");

			break;
		}

		case GLFW_MOUSE_BUTTON_RIGHT:
		{
			if (m_uiAction == GLFW_PRESS)
				LOG_ENGINE_DEBUG("RIGHT MOUSE CLICK");

			break;
		}

		case GLFW_MOUSE_BUTTON_MIDDLE:
		{
			if (m_uiAction == GLFW_PRESS)
				LOG_ENGINE_DEBUG("MIDDLE MOUSE CLICK");

			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EventMouseScroll::Dispatch()
{
	LOG_ENGINE_DEBUG("MOUSE SCROLL EVENT: ({0}, {1} )", m_dOffsetX, m_dOffsetY);
}



