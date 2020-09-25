#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

class ENGINE_API Log
{
public:
	static Log& getInstance()
	{
		static Log instance;
		return instance;
	}

	~Log();

	inline std::shared_ptr<spdlog::logger> EngineLogger() { return m_pEngineLogger; }
	inline std::shared_ptr<spdlog::logger> GameLogger() { return m_pGameLogger; }

private:
	Log();				
	Log(const Log&);				// prevent copies
	void operator=(const Log&);		// prevent assignments

	std::shared_ptr<spdlog::logger> m_pEngineLogger;
	std::shared_ptr<spdlog::logger> m_pGameLogger;
};

