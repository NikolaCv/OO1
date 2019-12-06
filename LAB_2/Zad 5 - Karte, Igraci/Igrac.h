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
	~Igrac();
	string getName() const;
	int getHP() const;
	int getMagicEnergy() const;
	Zbirka* getSpil() const;
	Zbirka* getGroblje() const;
	Zbirka* getRuka() const;
	Zbirka* getAktivirane() const;
	bool sendCardFromSpilToHand(Karta * card);
	bool sendCardFromHandToActivated(Karta * card);
	bool sendCardFromActivatedToGraveyard(Karta * card);
	void decreaseHP(int damage);
	void decreaseMagicEnergy(int energy);
	bool attack(Karta* card, Igrac& player);//igrac1.attack(card1,player2): igrac 1 napada igraca 2 pomocu karte card1, koja mora da bude aktivirana
	friend ostream& operator<<(ostream& out, const Igrac& player);
private:
	string name;
	int hp, magic_energy;
	Zbirka* spil, *groblje, *ruka, *aktivirane;
};

#endif