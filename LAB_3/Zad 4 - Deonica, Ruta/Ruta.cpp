#include "Ruta.h"



Ruta::Ruta()
{
}

double Ruta::operator()(double consumption)
{
	double s = 0;
	sections.moveCurrentAtStart();
	while (sections.doesCurrentExist())
	{
		s += ~(*sections.getCurrentData());
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
		if((sections.getCurrentData())->getCategory() == Deonica::LAKO)
			s += ~(*sections.getCurrentData()) * 12;
		else if ((sections.getCurrentData())->getCategory() == Deonica::TESKO)
			s += ~(*sections.getCurrentData()) * 22;
		sections.moveCurrent();
	}

	return s;
}


Ruta::~Ruta()
{
}

ostream & operator<<(ostream & out, const Ruta & route)
{
	return out << route.sections;
}
