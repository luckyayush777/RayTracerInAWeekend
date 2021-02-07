#pragma once

#include"Hittable.h"
#include"Vec3.h"

class Sphere : public Hittable {
public :
	Sphere() {};
	Sphere(Point3 cen, double r) : center(cen), radius(r) {};

	virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const override;

public :
	Point3 center;
	double radius;
};
