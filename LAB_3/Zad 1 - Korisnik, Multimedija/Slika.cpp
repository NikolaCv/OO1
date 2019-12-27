#include "Slika.h"

Slika::Slika(const string& name, unsigned height, unsigned width, unsigned pixel_size) :Multimedija(name), width(width), height(height), pixel_size(pixel_size)
{
	size = width * height * pixel_size;
	description = "[ " + to_string(width) + " x " + to_string(height) + " -> " + to_string(size) + " B]";
}

string Slika::getDescription() const
{
	return description;
}

unsigned Slika::getSize() const
{
	return size;
}

Slika * Slika::copy() const
{
	return new Slika(*this);
}

string Slika::toString() const
{
	return description;
}
