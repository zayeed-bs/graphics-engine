#include "Engine.h"
#include <iostream>
#include "../math/cube.h"
#include "../math/transform.h"

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

	Transform cubeTransform {vec3{0,0,0},
			vec3{0,0,0},
			vec3{1,1,1}};

	Transform cubeTransform2 {vec3{5,0,0},
			vec3{0,0,0},
			vec3{1,1,1}};


	while (isRunning) {
		while (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		renderer.Clear();

		// Looping rotation
		float angle = SDL_GetTicks() / 1000.0f;

		cubeTransform.rotation.y = angle;
		cubeTransform2.rotation.y = -angle;


		for (auto const &t : testCube.tris) {
			vec3 v0 = applyTransform(t.p[0], SDL_GetTicks() > 5000 ? cubeTransform2 : cubeTransform);
			vec3 v1 = applyTransform(t.p[1], SDL_GetTicks() > 5000 ? cubeTransform2 : cubeTransform);
			vec3 v2 = applyTransform(t.p[2], SDL_GetTicks() > 5000 ? cubeTransform2 : cubeTransform);

			// Project into 2d screen
			vec2 p0 = renderer.ProjectIsometric(v0, 50, window.width, window.height);
			vec2 p1 = renderer.ProjectIsometric(v1, 50, window.width, window.height);
			vec2 p2 = renderer.ProjectIsometric(v2, 50, window.width, window.height);

			// Draw wireframe
			renderer.DrawLine(p0, p1);
			renderer.DrawLine(p1, p2);
			renderer.DrawLine(p2, p0);
		}

		renderer.Present();
	}
}
