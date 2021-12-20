#pragma once
#include "Hittable.h"
#include "Vec3.h"

class Sphere : public Hittable {
public:

	Sphere() :
		center(Point3(0, 0, 0)), radius(0.5f) {}
	Sphere(Point3 center, float radius) :
		center(center), radius(radius) {}

	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const override;

public:
	Point3 center;
	float radius;





};