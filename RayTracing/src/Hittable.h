#pragma once

#include "Ray.h"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    float t;
};

class Hittable {
public:
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const = 0;
};