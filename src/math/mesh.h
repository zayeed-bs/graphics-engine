#ifndef GRAPHICS_MESH_H
#define GRAPHICS_MESH_H
#include "tri.h"
#include <vector>

struct mesh {
	std::vector<tri> tris;
};

#endif //GRAPHICS_MESH_H