#include "Ray.h"

Ray::Ray()
	: origin(Vec3(0.0f, 0.0f, 0.0f)), direction(Vec3(0.0f, 0.0f, 0.0f)) {}
Ray::Ray(const Point3& origin, const Vec3& direction)
	: origin(origin), direction(direction) {}

Point3 Ray::getOrigin()  const { return origin; }
Vec3 Ray::getDirection() const { return direction; }

Point3 Ray::at(float t) const {
	return origin + direction * t;
}