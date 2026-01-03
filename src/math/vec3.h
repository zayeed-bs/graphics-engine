#ifndef GRAPHICS_VEC3_H
#define GRAPHICS_VEC3_H
#include <iostream>
#include <cmath>

struct vec3 {
	float x, y, z;

	// Constructors
	vec3() : x {0}, y {0}, z {0} {}
	explicit vec3(const float val) : x {val}, y {val}, z {val} {}
	vec3(const float _x, const float _y, const float _z) : x {_x}, y {_y}, z {_z} {};


	vec3 operator+(const vec3& Other) const {
		return vec3 {
			x + Other.x,
			y + Other.y,
			z + Other.z
		};
	}

	vec3 operator-(const vec3& Other) const {
		return vec3 {
			x - Other.x,
			y - Other.y,
			z - Other.z
		};
	}

	vec3 operator*(const float& Other) const {
		return vec3 {
			x * Other,
			y * Other,
			z * Other
		};
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
};


inline vec3 rotateX(const vec3 &v, const float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	return vec3 {
		v.x,
		v.y * c - v.z * s,
		v.y * s + v.z * c
	};
}

inline vec3 rotateY(const vec3 &v, const float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	return vec3 {
		v.x * c - v.z * s,
		v.y,
		v.x * s + v.z * c
	};
}

inline vec3 rotateZ(const vec3 &v, const float angle) {
	float c = std::cos(angle);
	float s = std::sin(angle);

	return vec3 {
		v.x * c - v.y * s,
		v.x * s + v.y * c,
		v.z
	};
}

inline vec3 rotate(vec3 v, const vec3 angles) {
	// Here the order of Operation matters
	// By convention set as Pitch -> Roll -> Yaw
	v = rotateY(v, angles.y);
	v = rotateX(v, angles.x);
	v = rotateZ(v, angles.z);

	return v;
}

inline vec3 rotate(vec3 v, const vec3 angles, const vec3 pivot) {
	// Here the order of Operation matters
	// By convention set as Pitch -> Roll -> Yaw
	v -= pivot;
	v = rotateY(v, angles.y);
	v = rotateX(v, angles.x);
	v = rotateZ(v, angles.z);
	v += pivot;
	return v;
}

#endif //GRAPHICS_VEC3_H