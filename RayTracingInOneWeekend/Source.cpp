#include"Vec3.h"
#include"Color.h"
#include"Ray.h"


#include<iostream>
double HitSphere(const Point3& center, double radius, const Ray& ray)
{
	Vec3 oc = ray.OriginPoint() - center;
	auto a = ray.DirectionVector().length_squared();
	auto halfB = dot(oc, ray.DirectionVector());
	auto c = oc.length_squared() - radius * radius;
	auto discriminant = halfB * halfB - a * c;
	if (discriminant < 0)
		return -1.0;
	else
	{
		return (-halfB - sqrt(discriminant)) /  a;
	}
	
}

Color RayColor(const Ray& ray)
{
	auto t = (HitSphere(Point3(0, 0, -1), 0.5, ray));
	if (t > 0.0)
	{
		Vec3 N = unit_vector(ray.At(t) - Vec3(0, 0, -1));
		return 0.5 * Color(N.x() + 1, N.y() + 1,  N.z() + 1);
	}


	Vec3 unitDirection = unit_vector(ray.DirectionVector());
	t = 0.5 * (unitDirection.y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}



int main()
{
	// IMAGE

	const auto aspectRatio = 16.0 / 9.0;
	const int imageWidth = 400;
	const int imageHeight = static_cast<int>(imageWidth/ aspectRatio);

	//CAMERA

	auto viewportHeight = 2.0;
	auto viewportWidth = aspectRatio * viewportHeight;
	auto focalLength = 1.0;

	auto origin = Point3(0.0, 0.0, 0.0);
	auto horizontal = Vec3(viewportWidth, 0.0, 0.0);
	auto vertical = Vec3(0.0, viewportHeight, 0.0);
	auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

	//RENDER

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

	for (int j = imageHeight- 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines Remaining" << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			auto v = double(i) / (imageWidth- 1);
			auto u = double(j) / (imageHeight - 1);
			Ray r(origin, lowerLeftCorner + u * vertical + v * horizontal  - origin);
			Color pixelColor = RayColor(r);
			WriteColor(std::cout, pixelColor);
		}
	}

	std::cerr << "\n Done!";

}