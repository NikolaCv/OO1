#include "Slika.h"

Slika::Slika(const string name, int height, int width) :Multimedija(name), width(width), height(height)
{
	bytes = width * height;
	description = "[" + to_string(width) + "x" + to_string(height) + "->" + to_string(bytes) + "]";
}
/*
void Slika::setPixelSize(int pixel_size)
{
	pixel_size = pixel_size;
}*/
