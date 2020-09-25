#pragma once

#include "EnginePCH.h"
#include "GLFW/glfw3.h"

class ApplicationWindow
{
public:
	ApplicationWindow() 
	{ 
		m_uiWidth = 1280; 
		m_uiHeight = 800; 
		m_strTitle = "Engine Window"; 
		m_pWindow = nullptr;
	}
	ApplicationWindow(uint16_t width, uint16_t height, const std::string& title)
		:	m_uiWidth(width),
			m_uiHeight(height),
			m_strTitle(title),
			m_pWindow(nullptr) {}

	void				Init();
	void				Shutdown();
	void				Update();

	// GETTERS!
	inline	GLFWwindow* getWindowPtr()		{ return m_pWindow; }
	inline	uint16_t	getWindowWidth()	{ return m_uiWidth; }
	inline	uint16_t	getWindowHeight()	{ return m_uiHeight; }
	inline	std::string	getWindowTitle()	{ return m_strTitle; }

private:
	GLFWwindow*		m_pWindow;
	uint16_t		m_uiWidth;
	uint16_t		m_uiHeight;
	std::string		m_strTitle;
};
