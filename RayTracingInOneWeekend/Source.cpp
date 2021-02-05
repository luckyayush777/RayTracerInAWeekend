#include"Vec3.h"
#include"Color.h"
#include"Ray.h"


#include<iostream>

Color RayColor(const Ray& ray)
{
	Vec3 unitDirection = UnitVector(ray.DirectionVector());
	auto t = 0.5 * (unitDirection.Y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
	// IMAGE

	const auto aspectRatio = 16.0 / 9.0;
	const int imageHeight = 400;
	const int imageWidth = static_cast<int>(imageHeight / aspectRatio);

	//CAMERA

	auto viewportHeight = 2.0;
	auto viewportWidth = aspectRatio * viewportHeight;
	auto focalLength = 1.0;

	auto origin = Point3(0.0, 0.0, 0.0);
	auto horizontal = Vec3(viewportWidth, 0.0, 0.0);
	auto vertical = Vec3(0.0, viewportHeight, 0.0);
	auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

	//RENDER

	std::cout << "P3\n" << imageHeight << " " << imageWidth << "\n255\n";

	for (int j = imageWidth - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines Remaining" << j << ' ' << std::flush;
		for (int i = 0; i < imageHeight; ++i)
		{
			auto v = double(i) / (imageHeight- 1);
			auto u = double(j) / (imageWidth - 1);
			Ray r(origin, lowerLeftCorner + v * vertical + u * horizontal - origin);
			Color pixelColor = RayColor(r);
			WriteColor(std::cout, pixelColor);
		}
	}

	std::cerr << "\n Done!";

}