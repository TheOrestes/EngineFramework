
#include "EnginePCH.h"
#include "Log.h"

Log::Log()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	m_pEngineLogger = spdlog::stdout_color_mt("ENGINE");
	m_pEngineLogger->set_level(spdlog::level::trace);

	m_pGameLogger = spdlog::stderr_color_mt("GAME  ");
	m_pGameLogger->set_level(spdlog::level::trace);
}

Log::~Log()
{

}

