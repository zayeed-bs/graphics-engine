#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H
#include <vector>
#include "Object3D.h"

struct Scene {
	std::vector<Object3D*> objects;
};

#endif //GRAPHICS_SCENE_H