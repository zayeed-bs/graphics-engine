#ifndef GRAPHICS_CUBE_H
#define GRAPHICS_CUBE_H
#include "mesh.h"

struct cube {
	// Convention -> Clockwise vertices, front to back
	vec3 cubeVertices[8] = {
		{-0.5,-0.5,-0.5}, {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5},
		{-0.5,-0.5,0.5}, {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5},
	};

	mesh cubeMesh {
		{
			// Front face (z = 0)
			{ cubeVertices[0], cubeVertices[1], cubeVertices[2] },
			{ cubeVertices[0], cubeVertices[2], cubeVertices[3] },

			// Back face (z = 1)
			{ cubeVertices[4], cubeVertices[6], cubeVertices[5] },
			{ cubeVertices[4], cubeVertices[7], cubeVertices[6] },

			// Left face (x = 0)
			{ cubeVertices[0], cubeVertices[4], cubeVertices[5] },
			{ cubeVertices[0], cubeVertices[5], cubeVertices[1] },

			// Right face (x = 1)
			{ cubeVertices[3], cubeVertices[2], cubeVertices[6] },
			{ cubeVertices[3], cubeVertices[6], cubeVertices[7] },

			// Top face (y = 1)
			{ cubeVertices[1], cubeVertices[5], cubeVertices[6] },
			{ cubeVertices[1], cubeVertices[6], cubeVertices[2] },

			// Bottom face (y = 0)
			{ cubeVertices[0], cubeVertices[3], cubeVertices[7] },
			{ cubeVertices[0], cubeVertices[7], cubeVertices[4] },
		}
	};
};
#endif //GRAPHICS_CUBE_H