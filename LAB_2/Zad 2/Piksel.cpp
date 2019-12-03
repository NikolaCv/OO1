#include "Piksel.h"

Piksel::Piksel(int a = 0, int b = 0, int c = 0) :r(a), g(b), b(c)
{
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;

	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;

	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
}

int Piksel::getRed() const
{
	return r;
}

int Piksel::getGreen() const
{
	return g;
}

int Piksel::getBlue() const
{
	return b;
}

Piksel Piksel::operator+(const Piksel & p) const
{
	Piksel n;
	n.r = (r + p.r) / 2;
	n.g = (g + p.g) / 2;
	n.b = (b + p.b) / 2;
	return n;
}

bool Piksel::operator==(const Piksel & p) const
{
	if (r == p.r && g == p.g && b == p.b)
		return true;
	return false;
}

bool Piksel::operator!=(const Piksel & p) const
{
	if (r == p.r && g == p.g && b == p.b)
		return false;
	return true;
}

Piksel * Piksel::kopija()
{
	return new Piksel(*this);
}

int Piksel::aritmetickaSredina() const
{
	return (r + g + b) / 3;
}

ostream & operator<<(ostream & out, const Piksel & p)
{
	out << "(" << p.r << "," << p.g << "," << p.b << ")";
	return out;
}
