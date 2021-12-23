#include "HittableList.h"


HittableList::HittableList(std::shared_ptr<Hittable> object) { add(object); }

void HittableList::clear() { objects.clear(); }
void HittableList::add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

bool HittableList::hit(const Ray& r, float tMin, float tMax, HitRecord& record) const {
    HitRecord tempRecord;
    bool hitAnything = false;
    auto closestSoFar = tMax;

    for (const auto& object : objects) {
        if (object->hit(r, tMax, closestSoFar, tempRecord)) {
            hitAnything = true;
            closestSoFar = tempRecord.t;
            record = tempRecord;
        }
    }

    return hitAnything;
}
