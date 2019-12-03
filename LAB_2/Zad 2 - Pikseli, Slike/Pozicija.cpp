#include "Pozicija.h"

Pozicija::Pozicija(int a, int b):row(a),column(b)
{
	if (row < 0)
		row = 0;
	if (column < 0)
		column = 0;
}


int Pozicija::operator-(const Pozicija & p) const
{
	return abs(row - p.row) + abs(column - p.column);
}

int Pozicija::getRow() const
{
	return row;
}

int Pozicija::getColumn() const
{
	return column;
}
