#include "Engine.h"
#include <iostream>

#include "../math/cube.h"

Engine::Engine() {
	std::cout << "Successfully initialized engine" << std::endl;
}

Engine::~Engine() {
	std::cout << "Shut down Engine" << std::endl;
}

void Engine::Run() {
	bool isRunning = true;
	SDL_Event Event;

	cube testCube;
	cube testCube2;

	for (auto &t : testCube.tris) {
		t.p[0] = t.p[0] + vec3(0,0,1);
		t.p[1] = t.p[1] + vec3(0,0,1);
		t.p[2] = t.p[2] + vec3(0,0,1);
	}

	while (isRunning) {
		while (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		renderer.Clear();

		// Looping rotation
		float angle = SDL_GetTicks() / 1000.0f;

		for (auto const &t : testCube.tris) {
			vec3 v0 = t.p[0];
			vec3 v1 = t.p[1];
			vec3 v2 = t.p[2];

			// Rotate by the ticks
			// v0.rotate(vec3(angle));
			// v1.rotate(vec3(angle));
			// v2.rotate(vec3(angle));

			// Project into 2d screen
			vec2 p0 = renderer.ProjectIsometric(v0, 100, window.width, window.height);
			vec2 p1 = renderer.ProjectIsometric(v1, 100, window.width, window.height);
			vec2 p2 = renderer.ProjectIsometric(v2, 100, window.width, window.height);

			// Draw wireframe
			renderer.DrawLine(p0, p1);
			renderer.DrawLine(p1, p2);
			renderer.DrawLine(p2, p0);
		}

		renderer.Present();
	}
}
