#include "HittableList.h"

bool HittableList::hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const
{
    HitRecord tempRecord;
    bool hitAnything = false;
    auto closestSoFar = tMax;

    for (const auto& object : objects)
    {
        if (object->hit(ray, tMin, closestSoFar, tempRecord))
        {
            hitAnything = true;
            closestSoFar = tempRecord.t;
            hitRecord = tempRecord;
        }
    }

    return hitAnything;
}
