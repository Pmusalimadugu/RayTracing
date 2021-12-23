#pragma once
#include "Vec3.h"

class Ray {
public:
	Ray();
	Ray(const Point3& origin, const Vec3& direction);

	Point3 getOrigin()  const;
	Vec3 getDirection() const;
	Point3 at(float t) const;
	
public:
	Point3 origin;
	Vec3 direction;
};