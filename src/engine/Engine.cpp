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

		// Update DeltaTime & Set Delay for Framerate
		dt = static_cast<float>(SDL_GetTicks() - prev_tick);
		prev_tick = SDL_GetTicks();

		const int frameDelay = 1000 / FPS;
		std::cout << "FPS: " << 1000 / dt << std::endl;

		renderer.Clear();

		// Looping rotation
		float angle = SDL_GetTicks() / 1000.0f;

		cubeTransform.rotation.y = angle;
		cubeTransform2.rotation.y = -angle;

		for (auto const &e : testCube.edges) {
			vec3 v0 = applyTransform(testCube.cubeVerts[e.first], cubeTransform);
			vec3 v1 = applyTransform(testCube.cubeVerts[e.second], cubeTransform);

			vec2 p0 = renderer.ProjectIsometric(v0, 50, window.width, window.height);
			vec2 p1 = renderer.ProjectIsometric(v1, 50, window.width, window.height);

			renderer.DrawLine(p0, p1);
		}

		renderer.Present();

		// Time taken to render this frame

		// Delay to maintain consistent FPS
		if (const Uint32 frameTime = SDL_GetTicks() > prev_tick; frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
