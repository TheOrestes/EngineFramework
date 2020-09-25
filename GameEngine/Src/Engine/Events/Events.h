#pragma once

#include "GLFW/glfw3.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class EventType
{
	NONE = 0,
	WINDOW_CLOSE,
	WINDOW_RESIZE,
	KEY_PRESSED,
	KEY_RELEASED,
	MOUSE_BUTTON,
	MOUSE_MOVEMENT,
	MOUSE_SCROLLED
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Event
{
public:
	Event() {}
	virtual		~Event() {}

	virtual		EventType	GetEventType() const = 0;
	virtual		void		Dispatch() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventWindowClose : public Event
{
public:
	EventWindowClose(GLFWwindow* pWindow)
		: m_pWindow(pWindow) {}

	virtual ~EventWindowClose() {}

	EventType	GetEventType() const override
	{
		return EventType::WINDOW_CLOSE;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventWindowResize : public Event
{
public:
	EventWindowResize(GLFWwindow* pWindow, uint16_t width, uint16_t height)
		:	m_pWindow(pWindow),
			m_uiWidth(width),
			m_uiHeight(height) {}

	virtual ~EventWindowResize() {}

	EventType	GetEventType() const override
	{
		return EventType::WINDOW_RESIZE;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
	uint16_t	m_uiWidth;
	uint16_t	m_uiHeight;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventKey : public Event
{
public:
	EventKey(GLFWwindow* pWindow, uint32_t key, uint32_t scancode, uint32_t action, uint32_t mods)
		:	m_pWindow(pWindow),
			m_uiKey(key),
			m_uiScanCode(scancode),
			m_uiAction(action),
			m_uiMods(mods) {}

	virtual ~EventKey() {}

	EventType	GetEventType() const override
	{
		return EventType::KEY_PRESSED;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
	uint16_t	m_uiKey;
	uint16_t	m_uiScanCode;
	uint16_t	m_uiAction;
	uint16_t	m_uiMods;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventMouseMovement : public Event
{
public:
	EventMouseMovement(GLFWwindow* pWindow, double xPos, double yPos)
		:	m_pWindow(pWindow),
			m_dPosX(xPos),
			m_dPosY(yPos) {}

	virtual ~EventMouseMovement() {}

	EventType	GetEventType() const override
	{
		return EventType::MOUSE_MOVEMENT;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
	double		m_dPosX;
	double		m_dPosY;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventMouseButton : public Event
{
public:
	EventMouseButton(GLFWwindow* pWindow, uint8_t button, uint8_t action, uint8_t mods)
		:	m_pWindow(pWindow),
			m_uiButton(button),
			m_uiAction(action),
			m_uiMods(mods) {}

	virtual ~EventMouseButton() {}

	EventType	GetEventType() const override
	{
		return EventType::MOUSE_BUTTON;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
	uint8_t		m_uiButton;
	uint8_t		m_uiAction;
	uint8_t		m_uiMods;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EventMouseScroll : public Event
{
public:
	EventMouseScroll(GLFWwindow* pWindow, double xOffset, double yOffset)
		:	m_pWindow(pWindow),
			m_dOffsetX(xOffset),
			m_dOffsetY(yOffset) {}

	virtual ~EventMouseScroll() {}

	EventType	GetEventType() const override
	{
		return EventType::MOUSE_SCROLLED;
	}

	void		Dispatch() override;

private:
	GLFWwindow* m_pWindow;
	double		m_dOffsetX;
	double		m_dOffsetY;
};