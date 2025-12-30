#ifndef GRAPHICS_VEC3_H
#define GRAPHICS_VEC3_H
#include <iostream>

struct vec3 {
	float x, y, z;

	// Constructors
	vec3() : x {0}, y {0}, z {0} {}
	explicit vec3(float val) : x {val}, y {val}, z {val} {}
	vec3(float _x, float _y, float _z) : x {_x}, y {_y}, z {_z} {};


	vec3 operator+(const vec3& Other) const {
		return vec3 (
			x + Other.x,
			y + Other.y,
			z + Other.z
		);
	}

	vec3 operator-(const vec3& Other) const {
		return vec3 (
			x - Other.x,
			y - Other.y,
			z - Other.z
		);
	}

	vec3 operator*(const float& Other) const {
		return vec3 (
			x * Other,
			y * Other,
			z * Other
		);
	}

	vec3& operator+=(const vec3& Other) {
		x += Other.x;
		y += Other.y;
		z += Other.z;

		return *this;
	}

	vec3& operator-=(const vec3& Other) {
		x -= Other.x;
		y -= Other.y;
		z -= Other.z;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, vec3 const& inter) {
		return os << "Vector3(" << inter.x << "," << inter.y << "," << inter.z << ")\n";
	}

	void rotateX(float angle) {
		float c = cos(angle);
		float s = sin(angle);

		float _y = y * c - z * s;
		float _z = y * s + z * c;

		y = _y;
		z = _z;
	}

	void rotateY(float angle) {
		float c = cos(angle);
		float s = sin(angle);

		float _x = x * c - z * s;
		float _z = x * s + z * c;

		x = _x;
		z = _z;
	}

	void rotateZ(float angle) {
		float c = cos(angle);
		float s = sin(angle);

		float _x = x * c - y * s;
		float _y = x * s + y * c;

		x = _x;
		y = _y;
	}

	void rotate(vec3 angles) {
		rotateY(angles.y);
		rotateX(angles.x);
		rotateZ(angles.z);
	}

};


#endif //GRAPHICS_VEC3_H