#include "Engine.h"
#include <iostream>

#include "../core/Object3D.h"
#include "../math/cube.h"
#include "../core/Transform.h"

Engine::Engine() {
	std::cout << "Successfully initialized engine" << std::endl;
}

Engine::~Engine() {
	std::cout << "Shut down Engine" << std::endl;
}

void Engine::Run() {
	bool isRunning = true;
	SDL_Event Event;

	mesh cubeMesh = cube{}.cubeMesh;
	Scene scene {};

	Transform cubeTransform {vec3{0,0,0},
			vec3{0,0,0},
			vec3{1,1,1}};

	Transform cubeTransform2 {vec3{2,0,0},
			vec3{0,0,0},
			vec3{1,1,1}};

	Transform cubeTransform3 {vec3{4,0,0},
			vec3{0,0,0},
			vec3{1,1,1}};

	Object3D cube1 {&cubeMesh, cubeTransform};
	Object3D cube2 {&cubeMesh, cubeTransform2};
	Object3D cube3 {&cubeMesh, cubeTransform3};

	scene.objects.push_back(&cube1);
	scene.objects.push_back(&cube2);
	scene.objects.push_back(&cube3);

	while (isRunning) {
		while (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

			if (Event.type == SDL_EVENT_KEY_UP && Event.key.key == SDLK_Q) {
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

		// if (angle < 2*3.14156) {
			cube1.transform.rotation.y = angle;
			cube2.transform.rotation.x = angle;
			cube3.transform.rotation.z = angle;

			renderer.RenderScene(scene, MainCamera, 100, window.width, window.height);

			renderer.Present();

		// }

		// Time taken to render this frame
		// Delay to maintain consistent FPS
		if (const Uint32 frameTime = SDL_GetTicks() > prev_tick; frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
