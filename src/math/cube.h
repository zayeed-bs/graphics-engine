#ifndef GRAPHICS_CUBE_H
#define GRAPHICS_CUBE_H
#include "mesh.h"

struct cube : mesh {
	// Convention -> Clockwise vertices, front to back
	vec3 cubeVerts[8] = {
		{-0.5,-0.5,-0.5}, {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5},
		{-0.5,-0.5,0.5}, {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5},
	};

	cube() {
		tris = {
			// Front face (z = 0)
			{ cubeVerts[0], cubeVerts[1], cubeVerts[2] },
			{ cubeVerts[0], cubeVerts[2], cubeVerts[3] },

			// Back face (z = 1)
			{ cubeVerts[4], cubeVerts[6], cubeVerts[5] },
			{ cubeVerts[4], cubeVerts[7], cubeVerts[6] },

			// Left face (x = 0)
			{ cubeVerts[0], cubeVerts[4], cubeVerts[5] },
			{ cubeVerts[0], cubeVerts[5], cubeVerts[1] },

			// Right face (x = 1)
			{ cubeVerts[3], cubeVerts[2], cubeVerts[6] },
			{ cubeVerts[3], cubeVerts[6], cubeVerts[7] },

			// Top face (y = 1)
			{ cubeVerts[1], cubeVerts[5], cubeVerts[6] },
			{ cubeVerts[1], cubeVerts[6], cubeVerts[2] },

			// Bottom face (y = 0)
			{ cubeVerts[0], cubeVerts[3], cubeVerts[7] },
			{ cubeVerts[0], cubeVerts[7], cubeVerts[4] },
		};
	}

};
#endif //GRAPHICS_CUBE_H