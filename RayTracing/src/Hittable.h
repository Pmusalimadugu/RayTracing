#pragma once

#include "Ray.h"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    double t;
};

class AbstractHittable {
public:
    virtual bool hit(const Ray& r, double tMin, double tMax, HitRecord& record) const = 0;
};