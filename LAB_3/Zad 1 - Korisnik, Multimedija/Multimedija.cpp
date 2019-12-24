#include "Multimedija.h"

Multimedija::Multimedija(const string name):name(name),bytes(0),description("")
{
}

int Multimedija::getSize() const
{
	return bytes;
}

string Multimedija::getDescription() const
{
	return description;
}

string Multimedija::toString() const
{
	return name + ": " + description;
}

ostream & operator<<(ostream & out, const Multimedija & multimedia)
{
	return out << multimedia.toString();
}
