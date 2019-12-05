#ifndef IGRAC_H
#define IGRAC_H

#include "Zbirka.h"

//pretpostavka: igrac ne moze da se kopira, nema smisla
class Igrac
{
public:
	Igrac(const string name, int hp, int magic_energy, Zbirka* collection);
	Igrac(const Igrac& player) = delete;
	Igrac(Igrac&& player) = delete;
	Igrac& operator=(const Igrac& player) = delete;
	Igrac& operator=(Igrac&& player) = delete;
	string getName() const;
	int getHP() const;
	int getMagicEnergy() const;
	Zbirka* getSpil() const;
	Zbirka* getGroblje() const;
	Zbirka* getRuka() const;
	Zbirka* getAktivirane() const;
	bool operator[](Karta * card);
	bool deleteCard(Karta * card);//isto radi kao operator[]
	bool sendCardToGraveyard(Karta * card);
	void decreaseHP(int damage);
private:
	string name;
	int hp, magic_energy;
	Zbirka* spil, *groblje, *ruka, *aktivirane;
};

#endif