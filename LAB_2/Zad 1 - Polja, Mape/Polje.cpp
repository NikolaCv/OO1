#include "Polje.h"

Polje::Polje() : path_blockage(100), tag('P') {}

Polje::Polje(int a = 100) : path_blockage(a), tag('P')
{
	if (path_blockage > 1000)
		path_blockage = 1000;
	if (path_blockage < 0)
		path_blockage = 0;
}

Polje& Polje::operator++()
{
	if (path_blockage < 1000)
		path_blockage++;
	return *this;
}

Polje& Polje::operator--()
{
	if (path_blockage > 0)
		path_blockage--;
	return *this;
}

Polje& Polje::operator+=(int a)
{
	if (path_blockage + a < 1000)
		path_blockage += a;
	else
		path_blockage = 1000;
	return *this;
}

Polje& Polje::operator-=(int a)
{
	if (path_blockage - a > 0)
		path_blockage -= a;
	else
		path_blockage = 0;
	return *this;
}


int Polje::getPathBlockage()
{
	return path_blockage;
}

string Polje::toString() const
{
	return to_string(path_blockage) + "_" + tag;
}

Polje * Polje::kopija() const
{
	return new Polje(*this);
}

ostream& operator<<(ostream& out, const Polje& p)
{
	out << p.toString();
	return out;
}
