#include "Mesto.h"

Mesto::Mesto(const string & name, double width, double length):name(name),width(width),length(length)
{
}

double Mesto::getWidth() const
{
	return width;
}

double Mesto::getLength() const
{
	return length;
}

string Mesto::getName() const
{
	return name;
}

ostream & operator<<(ostream & out, const Mesto & place)
{
	return out << "(" << place.length << ", " << place.width << ")";
}
