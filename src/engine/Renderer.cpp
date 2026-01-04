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

void Renderer::RenderObject(const Object3D& obj, int s, int w, int h) {
	for (auto const& t : obj.geometry->tris) {
		vec3 v0 = applyTransform(t.p[0], obj.transform);
		vec3 v1 = applyTransform(t.p[1], obj.transform);
		vec3 v2 = applyTransform(t.p[2], obj.transform);

		vec2 p0 = ProjectIsometric(v0, s, w, h);
		vec2 p1 = ProjectIsometric(v1, s, w, h);
		vec2 p2 = ProjectIsometric(v2, s, w, h);

		DrawLine(p0, p1);
		DrawLine(p1, p2);
		DrawLine(p2, p0);
	}
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


