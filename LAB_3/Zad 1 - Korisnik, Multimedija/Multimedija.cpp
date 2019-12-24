#include "Multimedija.h"

Multimedija::Multimedija(const string& name):name(name)
{
}

ostream & operator<<(ostream & out, const Multimedija & multimedia)
{
	return out << multimedia.name << ": " << multimedia.toString();
}
