#include "Mreza.h"


Mreza::Mreza()
{
}

Mreza & Mreza::operator+=(Gradska_linija& line)
{
	network += line;
	return *this;
}

ostream & operator<<(ostream & out, const Mreza & net)
{
	return out << net.network;
}
