#include "Multimedija.h"

Multimedija::Multimedija(const string name):name(name),bytes(0),description("")
{
}

ostream & operator<<(ostream & out, const Multimedija & multimedia)
{
	return out << multimedia.name << ": " << multimedia.description;
}
