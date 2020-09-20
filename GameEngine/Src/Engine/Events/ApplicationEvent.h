#pragma once

#include "EnginePCH.h"
#include "Event.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int width, unsigned int height)
		: m_uiWidth(width), m_uiHeight(height) {}

	inline unsigned int GetWidth() const { return m_uiWidth; }
	inline unsigned int GetHeight() const { return m_uiHeight; }

	virtual int GetCategoryFlags() const override { return EVENT_APPLICATION; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_uiWidth << ", " << m_uiHeight;
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::WINDOW_RESIZE;
	}

	static EventType	GetStaticType() { return EventType::WINDOW_RESIZE; }

private:
	unsigned int m_uiWidth, m_uiHeight;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() {}
	
	virtual int GetCategoryFlags() { return EVENT_APPLICATION; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "WindowCloseEvent";
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::WINDOW_CLOSE;
	}

	static EventType	GetStaticType() { return EventType::WINDOW_CLOSE; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API AppTickEvent : public Event
{
public:
	AppTickEvent() {}

	virtual int GetCategoryFlags() { return EVENT_APPLICATION; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "AppTickEvent";
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::APP_TICK;
	}

	static EventType	GetStaticType() { return EventType::APP_TICK; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() {}

	virtual int GetCategoryFlags() { return EVENT_APPLICATION; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "AppUpdateEvent";
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::APP_UPDATE;
	}

	static EventType	GetStaticType() { return EventType::APP_UPDATE; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ENGINE_API AppRenderEvent : public Event
{
public:
	AppRenderEvent() {}

	virtual int GetCategoryFlags() { return EVENT_APPLICATION; }

	virtual std::string GetName() const override
	{
		std::stringstream ss;
		ss << "AppRenderEvent";
		return ss.str();
	}

	virtual EventType	GetEventType() const override
	{
		return EventType::APP_RENDER;
	}

	static EventType	GetStaticType() { return EventType::APP_RENDER; }
};

