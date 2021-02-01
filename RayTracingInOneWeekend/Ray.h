#pragma once

#include"Vec3.h"

class Ray {
public :

	Point3 originPoint;
	Vec3 directionVector;
	public :


	Ray() {}
	Ray(const Point3& origin, const Vec3& direction) : originPoint(origin), directionVector(direction) {}

	Point3 OriginPoint() const
	{
		return originPoint;
	}

	Vec3 DirectionVector() const
	{
		return directionVector;
	}

	Point3 At(double t) const
	{
		// A line is a + bx, where a is the origin and b is the direction vector
		// changing x gets you anywhere on that line
		return originPoint + t * directionVector;
	}
};
