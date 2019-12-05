#include "Igrac.h"

Igrac::Igrac(const string name, int hp, int magic_energy, Zbirka* collection):name(name),hp(hp),magic_energy(magic_energy),spil(collection)
{
}

string Igrac::getName() const
{
	return name;
}

int Igrac::getHP() const
{
	return hp;
}

int Igrac::getMagicEnergy() const
{
	return magic_energy;
}

Zbirka* Igrac::getSpil() const
{
	return spil;
}

Zbirka* Igrac::getGroblje() const
{
	return groblje;
}

Zbirka * Igrac::getRuka() const
{
	return ruka;
}

Zbirka * Igrac::getAktivirane() const
{
	return aktivirane;
}

bool Igrac::operator[](Karta * card)
{
	if ((*ruka)[card->getID()] == nullptr)//nema karte u rukama
		return false;

	if (card->getMagicEnergyNeeded() > magic_energy)//nema dovoljno energije
		return false;

	(*ruka)(card->getID());
	(*aktivirane) += card;
	magic_energy -= card->getMagicEnergyNeeded();

	return true;
}

bool Igrac::deleteCard(Karta * card)
{
	return (*this)[card];
}

bool Igrac::sendCardToGraveyard(Karta * card)
{
	if ((*aktivirane)[card->getID()] == nullptr)//nema karte u aktiviranim
		return false;

	(*aktivirane)(card->getID());
	(*groblje) += card;

	return true;
}

void Igrac::decreaseHP(int damage)
{
	hp -= damage;
	if (hp < 0)
		hp = 0;
}
