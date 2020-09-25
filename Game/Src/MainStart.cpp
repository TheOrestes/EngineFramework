
#include "EngineHeaders.h"
#include "Engine/Log.h"

#ifdef PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	LOG_ENGINE_CRITICAL("Critical message from Engine");
	LOG_ENGINE_DEBUG("Debug message from Engine");
	LOG_ENGINE_ERROR("Error message from Engine");
	LOG_ENGINE_INFO("Info message from Engine");

	LOG_GAME_DEBUG("Game error");

	Application* app = new Application();
	app->Run();
	delete app;
}

#endif