#pragma once
#include "RayTracing.h"
class Camera {
public:

	Camera();

	Ray getRay(float u, float v) const;

private:
	Point3 origin;
	Point3 lowerLeftCorner;
	Vec3 horizontal;
	Vec3 vertical;

};