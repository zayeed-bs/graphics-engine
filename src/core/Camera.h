#ifndef GRAPHICS_CAMERA_H
#define GRAPHICS_CAMERA_H
#include "Object3D.h"

struct Camera {
	Object3D object = Object3D{};
	bool isCurrent = false;

	vec3 nearPlane;
	vec3 farPlane;
	vec3 zoom;
};

#endif //GRAPHICS_CAMERA_H