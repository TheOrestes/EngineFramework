#pragma once

#include "EnginePCH.h"
#include "Event.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(float x, float y)
		: m_MouseX(x), m_MouseY(y) {}

	inline float GetX() const { return m_MouseX; }
	inline float GetY() const { return m_MouseY; }

	virtual int GetCategoryFlags() { return EVENT_MOUSE | EVENT_INPUT; }
	
	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::MOUSE__MOVED;
	}

	static EventType	GetStaticType() { return EventType::MOUSE__MOVED; }

private:
	float m_MouseX, m_MouseY;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(float xOffset, float yOffset)
		: m_xOffset(xOffset), m_yOffset(yOffset) {}

	inline float GetXOffset() const { return m_xOffset; }
	inline float GetYOffset() const { return m_yOffset; }

	virtual int GetCategoryFlags() { return EVENT_MOUSE | EVENT_INPUT; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::MOUSE_SCROLLED;
	}

	static EventType	GetStaticType() { return EventType::MOUSE_SCROLLED; }

private:
	float m_xOffset, m_yOffset;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API MouseButtonEvent : public Event
{
public:
	inline int GetMouseButton() const { return m_iButton; }

	virtual int GetCategoryFlags() { return EVENT_MOUSE | EVENT_INPUT; }

protected:
	MouseButtonEvent(int button)
		: m_iButton(button) {}

	int m_iButton;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(int button)
		: MouseButtonEvent(button) {}

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_iButton;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::MOUSE_BUTTON_PRESSED;
	}

	static EventType	GetStaticType() { return EventType::MOUSE_BUTTON_PRESSED; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(int button)
		: MouseButtonEvent(button) {}

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_iButton;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::MOUSE_BUTTON_RELEASED;
	}

	static EventType	GetStaticType() { return EventType::MOUSE_BUTTON_RELEASED; }
};