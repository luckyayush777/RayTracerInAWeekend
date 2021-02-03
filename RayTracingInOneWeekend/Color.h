#pragma once

#include"Vec3.h"

#include<iostream>

void WriteColor(std::ostream& out, Color pixelColor)
{
	//Writing the translates 0 - 255 value of each component
	out << static_cast<int>(pixelColor.X() * 255.99) << ' '
		<< static_cast<int>(pixelColor.Y() * 255.99) << ' '
		<< static_cast<int>(pixelColor.Z() * 255.99) << '\n';
}		   