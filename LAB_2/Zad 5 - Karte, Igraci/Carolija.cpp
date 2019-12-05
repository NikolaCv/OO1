#include "Carolija.h"


Carolija::~Carolija()
{
}

Carolija::Carolija(const string & name, int needed_magic_energy):Karta(name,needed_magic_energy)
{
}
Karta::KATEGORIJA Carolija::getCategory() const
{
	return category;
}
