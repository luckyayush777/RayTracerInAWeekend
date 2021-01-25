#include<iostream>

int main()
{
	int imageWidth = 256;
	int imageHeight = 256;
	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = imageHeight - 1; i >= 0; i--)
	{
		std::cerr << "\rScanlines Remaining :" << i << ' '<< std::flush;
		for (int j = 0; j < imageWidth; j++)
		{
			float r = float(i) / float(imageWidth);
			float g = float(j) / float(imageHeight);
			float b = 0.25;
			int ir = int(256.99 * r);
			int ig = int(256.99 * g);
			int ib = int(256.99 * b);
			std::cout << ir << " " << ig << " " << ib << "\n";

		}
	}
	std::cerr << "\nDone!.\n";
	return 0;
}