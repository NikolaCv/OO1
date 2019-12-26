#include "Ruta.h"



Ruta::Ruta()
{
}

Ruta & Ruta::operator+=(Deonica * section)
{
	sections += section;
	return *this;
}

double Ruta::operator()(double consumption)
{
	double s = 0;
	sections.moveCurrentAtStart();
	while (sections.doesCurrentExist())
	{
		s += ~(*(sections.getCurrentData()));
		sections.moveCurrent();
	}
	
	return s * consumption / 100;
}

double Ruta::operator()(Deonica::KATEGORIJA_VOZILA category)
{
	double s = 0;
	sections.moveCurrentAtStart();

	while (sections.doesCurrentExist())
	{
		s += (*sections.getCurrentData())(category);
		sections.moveCurrent();
	}

	return s;
}

ostream & operator<<(ostream & out, const Ruta & route)
{
	return out << route.sections;
}
