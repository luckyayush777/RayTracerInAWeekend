#pragma once

#include<cmath>
#include<limits>
#include<memory>

#include"Ray.h"
#include"Vec3.h"

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double DegreeToRadians(double degree)
{
	return degree * pi / 180;
}


