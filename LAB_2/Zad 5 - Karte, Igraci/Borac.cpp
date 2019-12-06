#include "Borac.h"

Borac::Borac(const string name, int needed_magic_energy, int strength):Karta(name,needed_magic_energy),strength(strength)
{
}

int Borac::getStrength() const
{
	return strength;
}

bool Borac::operator<(const Borac & fighter)
{
	if (strength < fighter.strength)
		return true;
	return false;
}

bool Borac::operator>(const Borac & fighter)
{
	if (strength > fighter.strength)
		return true;
	return false;
}

string Borac::toString() const
{
	return "(snaga: " + to_string(strength) +")";
}

Karta::KATEGORIJA Borac::getCategory() const
{
	return category;
}
