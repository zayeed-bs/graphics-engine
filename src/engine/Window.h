#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H
#include <SDL3/SDL.h>

class Window {
public:
	int width;
	int height;

	// Constructor & Destructor
	Window(int w, int h);
	~Window();

	// Getter to expose SDL_Window
	SDL_Window* get() const { return _window; }
private:
	SDL_Window* _window = nullptr;
};

#endif //GRAPHICS_WINDOW_H