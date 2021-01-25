#pragma once
#include<cmath>
#include<iostream>

class Vec3 {
public :
	double e[3];

	Vec3() : e{ 0 , 0 , 0 } {};
	Vec3(double e1, double e2, double e3) : e{ e1, e2, e3 } {};

	double x() const
	{
		return e[0];
	}

	double y() const
	{
		return e[1];
	}

	double z() const
	{
		return e[2];
	}

	Vec3& operator+=(const Vec3& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	Vec3& operator *= (const double scalarMultiplier)
	{
		e[0] *= scalarMultiplier;
		e[1] *= scalarMultiplier;
		e[2] *= scalarMultiplier;
		return *this;
	}

	Vec3& operator /= (const double scalarDivider)
	{
		return *this *= 1 / scalarDivider;
	}

	double Length() const 
	{
		return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

};

using point3 = Vec3;
using color = Vec3;