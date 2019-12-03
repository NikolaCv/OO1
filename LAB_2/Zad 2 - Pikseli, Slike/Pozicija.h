#ifndef POZICIJA_H
#define POZICIJA_H

#include <math.h>

class Pozicija
{
public:
	Pozicija(int red, int kol);
	int operator-(const Pozicija& p) const;
	int getRow() const;
	int getColumn() const;
private:
	int row, column;
};

#endif