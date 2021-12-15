#pragma once
#include "Vec3.h"

class Ray {
public:
	Ray()
		: origin(Vec3(0.0f, 0.0f, 0.0f)), direction(Vec3(0.0f, 0.0f, 0.0f)) {}
	Ray(const Vec3& origin, const Vec3& direction)
		: origin(origin), direction(direction) {}
	Point3 at(float t) {
		return origin + direction * t;
	}
public:
	Point3 origin;
	Vec3 direction;
};