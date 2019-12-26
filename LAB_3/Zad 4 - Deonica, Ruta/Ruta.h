#ifndef RUTA_H
#define RUTA_H

#include "myExceptions.h"
#include "Mesto.h"
#include "Lista.h"
#include "Deonica.h"

class Ruta
{
public:
	Ruta();
	Ruta(const Ruta& line) = default;
	Ruta(Ruta&& line) = default;
	Ruta& operator=(const Ruta& line) = default;
	Ruta& operator=(Ruta&& line) = default;
	~Ruta() = default;

	Ruta& operator+=(Deonica* section);
	double operator()(double consumption);
	double operator()(Deonica::KATEGORIJA_VOZILA category);

	friend ostream& operator<<(ostream& out, const Ruta& route);

private:
	Lista<Deonica*> sections;

};
#endif