#pragma once

#include"Ray.h"

struct HitRecord {
	Point3 p;
	double t;
	Vec3 normal;
	bool frontFace;

	inline void SetFaceNormal(const Ray& ray, const Vec3& outwardNormal)
	{
		frontFace = dot(ray.DirectionVector(), outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable {
public :
	virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const = 0;
};
