#ifndef GRAPHICS_CAMERA_H
#define GRAPHICS_CAMERA_H
#include "Object3D.h"

struct Camera {
	Transform transform = Transform{};
};

inline vec3 WorldToView(vec3 p, Camera& cam) {
	// Reverse position
	p -= cam.transform.position;

	// Reverse Rotation
	p = rotateZ(p, -cam.transform.rotation.z);
	p = rotateX(p, -cam.transform.rotation.x);
	p = rotateY(p, -cam.transform.rotation.y);

	return p;
}
#endif //GRAPHICS_CAMERA_H