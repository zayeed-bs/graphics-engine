#include "Renderer.h"

Renderer::Renderer(SDL_Window &window) {
	_renderer = SDL_CreateRenderer(&window, NULL);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

vec2 Renderer::ProjectOrthographic(vec3 &v, float scale, int w, int h) {
	return vec2(w/2 + v.x * scale, h/2 + v.y * scale );
}

vec2 Renderer::ProjectIsometric(vec3& p, float scale, int w, int h) {
	float isoX = (p.x - p.z);
	float isoY = (p.x + p.z) * 0.5f - p.y;

	return {
		isoX * scale + w / 2.0f,
		isoY * scale + h / 2.0f
	};
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


