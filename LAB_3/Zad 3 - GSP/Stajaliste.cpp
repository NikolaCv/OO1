#include "Stajaliste.h"

Stajaliste::Stajaliste(int tag, const string & name, int zone):tag(tag),zone(zone),name(name)
{
}

int Stajaliste::getTag() const
{
	return tag;
}

int Stajaliste::getZone() const
{
	return zone;
}

string Stajaliste::getName() const
{
	return name;
}

bool operator==(const Stajaliste & station1, const Stajaliste & station2)
{
	return (station1.tag == station2.tag) ? true : false;
}

bool operator!=(const Stajaliste & station1, const Stajaliste & station2)
{
	return (station1.tag != station2.tag) ? true : false;
}

ostream & operator<<(ostream & out, const Stajaliste & station)
{
	return out << "[" << station.zone << "] #" << station.tag << " - " << station.name;
}
