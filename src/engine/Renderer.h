#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H
#include <SDL3/SDL_render.h>
#include "../math/vec2.h"
#include "../math/vec3.h"

class Renderer {
public:
	// Constructor & Destructor
	Renderer(SDL_Window &window);
	~Renderer();

	// Utility Functions
	void Clear() const;
	void Present() const;

	// Rendering Functions
	vec2 Project(vec3& v, float scale, int w, int h);
	void DrawLine(vec2 p1, vec2 p2);

	// Getter to expose SDL_Renderer
	SDL_Renderer* get() const { return _renderer; }

private:
	SDL_Renderer* _renderer;

};


#endif //GRAPHICS_RENDERER_H