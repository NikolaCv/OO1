#include "Karta.h"

unsigned Karta::statID = 0;

Karta::~Karta()
{
}

Karta::Karta(const string & name, int needed_magic_energy):name(name),magic_energy_needed(needed_magic_energy)
{
}

string Karta::getName() const
{
	return name;
}

unsigned Karta::getID() const
{
	return ID;
}

int Karta::getMagicEnergyNeeded() const
{
	return magic_energy_needed;
}

string Karta::toString() const
{
	return "";
}

ostream & operator<<(ostream & out, const Karta & card)
{
	out << "[" << card.ID << "]" << " \"" << card.name << "\" (cena: " << card.magic_energy_needed << ")" <<card.toString();
	return out;
}
