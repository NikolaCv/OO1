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

double operator-(const Mesto & place1, const Mesto & place2)
{
	return 12742 * asin(sqrt(pow(sin(M_PI*(place1.width - place2.width) / 360), 2)
		+ cos(M_PI*place1.width/180) * cos(M_PI*place2.width / 180) * pow(sin(M_PI*(place1.length - place2.length) / 360), 2)));
}

ostream & operator<<(ostream & out, const Mesto & place)
{
	return out << place.name << " (" << place.width << ", " << place.length << ")";
}
