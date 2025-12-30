#ifndef GRAPHICS_VEC2_H
#define GRAPHICS_VEC2_H
#include <iostream>
struct vec2 {
	float x, y;

	vec2 operator+(const vec2& Other) const {
		return vec2 (
			x + Other.x,
			y + Other.y
		);
	}

	vec2 operator-(const vec2& Other) const {
		return vec2 (
			x - Other.x,
			y - Other.y
		);
	}

	vec2 operator*(const float& Other) const {
		return vec2 (
			x * Other,
			y * Other
		);
	}

	vec2& operator+=(const vec2& Other) {
		x += Other.x;
		y += Other.y;

		return *this;
	}

	vec2& operator-=(const vec2& Other) {
		x -= Other.x;
		y -= Other.y;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, vec2 const& inter) {
		return os << "Vector2(" << inter.x << "," << inter.y << ")\n";
	}
};

#endif //GRAPHICS_VEC2_H