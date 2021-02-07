#include "Sphere.h"

bool Sphere::hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const
{
    Vec3 oc = ray.OriginPoint() - center;
    auto a = ray.DirectionVector().length_squared();
    auto halfB = dot(oc, ray.DirectionVector());
    auto c = oc.length_squared() - radius * radius;


    auto discriminant = halfB * halfB - a * c;
    if (discriminant < 0)
        return false;
    auto sqrtd = sqrt(discriminant);

    auto root = (-halfB - sqrtd) / a;

    if (root < tMin || root > tMax)
    {
        root = (-halfB + sqrtd) / a;
        if (root < tMin || root > tMax)
            return false;

    }

    hitRecord.t = root;
    hitRecord.p = ray.At(hitRecord.t);
    hitRecord.normal = (hitRecord.p - center) / radius;
}
