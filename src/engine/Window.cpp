#include "Window.h"

Window::Window(int w, int h) {
	width = w;
	height = h;

	_window = SDL_CreateWindow("Engine", w, h, SDL_WINDOW_RESIZABLE);
}

Window::~Window() {
	SDL_DestroyWindow(_window);
}