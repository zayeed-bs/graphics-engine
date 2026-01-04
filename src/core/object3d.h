#ifndef GRAPHICS_OBJECT3D_H
#define GRAPHICS_OBJECT3D_H
#include "../math/mesh.h"
#include "../math/transform.h"

struct Object3D {
	mesh* geometry = nullptr;
	Transform transform = Transform{};
};

#endif //GRAPHICS_OBJECT3D_H