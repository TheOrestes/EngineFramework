#pragma once

// For use by Game!
#include "Engine/Application.h"
#include "Engine/Log.h"

//--- MACROS!
// ENGINE LOG RELATED MACROS
#define LOG_ENGINE_CRITICAL(...)	Log::getInstance().EngineLogger().get()->critical(__VA_ARGS__)
#define LOG_ENGINE_ERROR(...)		Log::getInstance().EngineLogger().get()->error(__VA_ARGS__)
#define LOG_ENGINE_WARNING(...)		Log::getInstance().EngineLogger().get()->warning(__VA_ARGS__)
#define LOG_ENGINE_INFO(...)		Log::getInstance().EngineLogger().get()->info(__VA_ARGS__)
#define LOG_ENGINE_DEBUG(...)		Log::getInstance().EngineLogger().get()->debug(__VA_ARGS__)

// GAME LOG RELATED MACROS
#define LOG_GAME_CRITICAL(...)		Log::getInstance().GameLogger().get()->critical(__VA_ARGS__)
#define LOG_GAME_ERROR(...)			Log::getInstance().GameLogger().get()->error(__VA_ARGS__)
#define LOG_GAME_WARNING(...)		Log::getInstance().GameLogger().get()->warning(__VA_ARGS__)
#define LOG_GAME_INFO(...)			Log::getInstance().GameLogger().get()->info(__VA_ARGS__)
#define LOG_GAME_DEBUG(...)			Log::getInstance().GameLogger().get()->debug(__VA_ARGS__)