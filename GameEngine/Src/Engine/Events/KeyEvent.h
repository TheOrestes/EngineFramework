#pragma once

#include <sstream>

#include "Event.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API KeyEvent : public Event
{
public:
	inline int GetKeyCode() const { return m_iKeyCode; }

	virtual int GetCategoryFlags() { return EVENT_KEYBOARD | EVENT_INPUT; }

protected:
	KeyEvent(int keycode) : m_iKeyCode(keycode) {}

	int		m_iKeyCode;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int keycode, int repeatCount)
		: KeyEvent(keycode),
		  m_iRepeatCount(repeatCount) {}

	inline	int GetRepeatCount() const { m_iRepeatCount; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_iKeyCode << " (" << m_iRepeatCount << " repeats)";
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::KEY_PRESSED;
	}

	static EventType	GetStaticType() { return EventType::KEY_PRESSED; }

private:
	int	m_iRepeatCount;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int keycode)
		: KeyEvent(keycode) {}

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_iKeyCode;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::KEY_RELEASED;
	}

	static EventType	GetStaticType() { return EventType::KEY_RELEASED; }
};
