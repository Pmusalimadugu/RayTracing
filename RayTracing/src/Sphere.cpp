#include "Sphere.h"
#include "Vec3.h"


Sphere::Sphere() :
    center(Point3(0, 0, 0)), radius(0.5f) {}
Sphere::Sphere(Point3 center, float radius) :
    center(center), radius(radius) {}


bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& record) const {
    Vec3 oc = r.getOrigin() - center;
    auto a = r.getDirection().length_squared();
    auto half_b = dot(oc, r.getDirection());
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-half_b + sqrtd) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    record.t = root;
    record.p = r.at(record.t);
    record.normal = (record.p - center) / radius;

    Vec3 outWardNormal = (record.p - center) / radius;
    record.setFaceNormal(r, outWardNormal);

    return true;
}

