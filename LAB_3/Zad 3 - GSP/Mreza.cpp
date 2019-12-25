#include "Mreza.h"


Mreza & Mreza::operator+=(Gradska_linija * line)
{
	network += line;
	return *this;
}

ostream & operator<<(ostream & out, const Mreza & network)
{
	return out << network;
}
