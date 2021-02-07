#pragma once

#include"Ray.h"

struct HitRecord {
	Point3 p;
	double t;
	Vec3 normal;
};

class Hittable {
public :
	virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const = 0;
};
