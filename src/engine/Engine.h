#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H
#include "Renderer.h"
#include "Window.h"
#include "../core/Camera.h"

class Engine {
public:
	Engine();
	~Engine();
	void Run();

private:
	Window window{1280, 720};
	Renderer renderer{*window.get()};
	Camera MainCamera{Object3D{nullptr, Transform{}}, true, vec3{}, vec3{}};

	const int FPS = 60;
	float dt = 0;
	Uint64 prev_tick = 0;
};
#endif //GRAPHICS_ENGINE_H