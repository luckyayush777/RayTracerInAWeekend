#include"Vec3.h"
#include"Color.h"


#include<iostream>

int main()
{
	//IMAGE
	
	const int imageWidth = 256;
	const int imageHeight = 256;

	//RENDER


	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";


	for (int i = imageHeight - 1; i >= 0; i--)
	{
		std::cerr << "\rScanlines Remaining :" << i << ' '<< std::flush;


		for (int j = 0; j < imageWidth; j++)
		{
			Color pixelColor(double(j) / (imageWidth - 1), double(i) / (imageHeight - 1), 0.25);
			WriteColor(std::cout, pixelColor);
		}
	}
	std::cerr << "\nDone!.\n";
	return 0;
}