#include <iostream>
#include <SDL3/SDL.h>
#include "engine/Engine.h"

int main(int, char**) {
	// Initialize Engine
	SDL_Init(SDL_INIT_VIDEO);
	std::cout << "Successfully initialized SDL3" << std::endl;
	auto engine = Engine();
	engine.Run();

	// Shut down SDL
	SDL_Quit();
	return 0;
}