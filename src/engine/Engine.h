#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H
#include "Renderer.h"
#include "Window.h"

class Engine {
public:
	Engine();
	~Engine();
	void Run();

private:
	Window window{1280, 720};
	Renderer renderer{*window.get()};

	const int FPS = 60;
	float dt;
	Uint64 prev_tick;
};
#endif //GRAPHICS_ENGINE_H