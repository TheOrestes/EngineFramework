#pragma once

#ifdef PLATFORM_WINDOWS

extern Application* CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hello From Engine...";
	Application* app = CreateApplication();
	app->Run();
	delete app;
}

#endif // PLATFORM_WINDOWS
