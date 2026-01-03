#ifndef GRAPHICS_TRANSFORM_H
#define GRAPHICS_TRANSFORM_H
#include "vec3.h"

struct Transform {
	vec3 position {0};
	vec3 rotation {0};
	vec3 scale {1};
};

inline vec3 applyTransform(vec3 v, const Transform &t){
	// Apply Scale
	v.x *= t.scale.x;
	v.y *= t.scale.y;
	v.z *= t.scale.z;

	// Apply Rotation
	v = rotate(v, t.rotation);

	// Apply Position
	v += t.position;

	return v;
}

#endif //GRAPHICS_TRANSFORM_H