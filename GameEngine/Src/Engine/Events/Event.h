#pragma once

#include <string>
#include <functional>

#include "../Core.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class EventType
{
	None = 0,
	WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
	APP_TICK, APP_UPDATE, APP_RENDER,
	KEY_PRESSED, KEY_RELEASED,
	MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum EventCategory
{
	NONE = 0,
	EVENT_APPLICATION	= 1 << 0,
	EVENT_INPUT			= 1 << 1,
	EVENT_KEYBOARD		= 1 << 2,
	EVENT_MOUSE			= 1 << 3,
	EVENT_MOUSE_BUTTON	= 1 << 4
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API Event
{
	friend class EventDispatcher;

public:
	virtual EventType	GetEventType() const = 0;
	virtual std::string	GetName() const = 0;
	virtual int			GetCategoryFlags() const = 0;

	inline bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}

protected:
	bool	m_bHandled;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API EventDispatcher
{
	template<typename T>
	using EventFn = std::function<bool(T&)>;
public:
	EventDispatcher(Event& event)
		: m_Event(event)
	{
	}

	template<typename T>
	bool Dispatch(EventFn<T> func)
	{
		if (m_Event.GetEventType() == T::GetStaticType())
		{
			m_Event.m_Handled = func(*(T*)&m_Event);
			return true;
		}
		return false;
	}
private:
	Event& m_Event;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.GetName();
}

