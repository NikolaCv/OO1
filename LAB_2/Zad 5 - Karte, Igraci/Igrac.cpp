#include "Igrac.h"

Igrac::Igrac(const string name, int hp, int magic_energy, Zbirka* collection):name(name),hp(hp),magic_energy(magic_energy),spil(collection)
{
	ruka = new Zbirka;
	aktivirane = new Zbirka;
	groblje = new Zbirka;
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

bool Igrac::sendCardFromSpilToHand(Karta * card)
{
	if ((*spil)[card->getID()] == nullptr)//nema karte u spilu
		return false;

	(*spil)(card->getID());
	(*ruka) += card;

	return true;
}

bool Igrac::sendCardFromHandToActivated(Karta * card)
{
	if ((*ruka)[card->getID()] == nullptr)//nema karte u rukama
		return false;

	if (card->getMagicEnergyNeeded() > magic_energy)//nema dovoljno energije
		return false;

	(*ruka)(card->getID());
	(*aktivirane) += card;
	decreaseMagicEnergy(card->getMagicEnergyNeeded());

	return true;
}

bool Igrac::sendCardFromActivatedToGraveyard(Karta * card)
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

void Igrac::decreaseMagicEnergy(int energy)
{
	magic_energy -= energy;
}

bool Igrac::attack(Karta * card, Igrac& player)
{
	if ((*aktivirane)[card->getID()] == nullptr)//nema karte u aktiviranim
		return false;
	
	(*card).upotrebi(player);
}

ostream & operator<<(ostream & out, const Igrac & player)
{
	out << "****************************************" << endl;
	out << player.name << ": HP - " << player.hp << " Magic Energy - " << player.magic_energy << endl;
	if (player.spil != nullptr)
		out << "Spil:" << endl << *player.spil << endl;
	if (player.ruka != nullptr)
		out << "Ruka:" << endl << *player.ruka << endl;
	if (player.aktivirane != nullptr)
		out << "Aktivirane:" << endl << *player.aktivirane << endl;
	if (player.groblje != nullptr)
		out << "Groblje:" << endl << *player.groblje << endl;

	return out;
}
