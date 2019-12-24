#include "Slika.h"

Slika::Slika(const string name, unsigned height, unsigned width, unsigned pixel_size) :Multimedija(name), width(width), height(height), pixel_size(pixel_size)
{
	bytes = width * height * pixel_size;
	description = "[" + to_string(width) + "x" + to_string(height) + "->" + to_string(bytes) + "]";
}

