#pragma once
#include "Sphere.h"
#include "Hittable.h"
#include "Vec3.h"

class Sphere : public Hittable {
public:

	Sphere();
	Sphere(Point3 center, float radius);
	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const override;

public:
	Point3 center;
	float radius;





};