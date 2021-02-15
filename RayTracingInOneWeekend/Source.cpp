#include"RtWeekend.h"

#include"Color.h"
#include"HittableList.h"
#include"Sphere.h"


#include<iostream>


Color RayColor(const Ray& ray, const Hittable& world)
{
	HitRecord hitRecord;

	if (world.hit(ray, 0, infinity, hitRecord))
	{
		return 0.5 * (hitRecord.normal + Color(1, 1, 1));
	}

	Vec3 unitDirection = unit_vector(ray.DirectionVector());

	auto t = 0.5 * (unitDirection.y() + 1.0);

	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}



int main()
{
	// IMAGE

	const auto aspectRatio = 16.0 / 9.0;
	const int imageWidth = 400;
	const int imageHeight = static_cast<int>(imageWidth/ aspectRatio);

	//WORLD

	HittableList world;
	world.Add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.Add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

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
			Color pixelColor = RayColor(r, world);
			WriteColor(std::cout, pixelColor);
		}
	}

	std::cerr << "\n Done!";

}