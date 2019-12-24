#ifndef MREZA_H
#define MREZA_H

#include "myExceptions.h"
#include "Lista.h"
#include "Gradska_linija.h"


class Mreza
{
public:
	Mreza() = default;
	Mreza(const Mreza& network) = default;
	Mreza(Mreza&& network) = default;				//moze default???
	Mreza& operator=(const Mreza& network) = default;
	Mreza& operator=(Mreza&& network) = default;
	~Mreza() = default;

	Mreza& operator+=(Gradska_linija* line);

	friend ostream& operator<<(ostream& out, const Mreza& network);

private:
	Lista<Gradska_linija*> network;
};

#endif