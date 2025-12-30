#include "Renderer.h"

Renderer::Renderer(SDL_Window &window) {
	_renderer = SDL_CreateRenderer(&window, NULL);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

vec2 Renderer::Project(vec3 &v, float scale, int w, int h) {
	return vec2(w/2 + v.x * scale, h/2 + v.y * scale );
}

void Renderer::DrawLine(vec2 p1, vec2 p2) {
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255); // white
	SDL_RenderLine(_renderer, p1.x, p1.y, p2.x, p2.y);
}

void Renderer::Clear() const {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // black background
	SDL_RenderClear(_renderer);
}

void Renderer::Present() const {
	SDL_RenderPresent(_renderer);
}


