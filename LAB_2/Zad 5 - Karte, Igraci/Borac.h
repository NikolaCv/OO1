#ifndef BORAC_H
#define BORAC_H

#include "Karta.h"

class Borac:public Karta
{
public:
	Borac(const string name, int needed_magic_energy, int strength);//novi konstruktor, dodatno strength
	int getStrength() const override;
	bool operator<(const Borac& fighter);
	bool operator>(const Borac& fighter);
	string toString() const override;//ovde vraca dodatno (snaga: strength) zbog ispisa
	KATEGORIJA getCategory() const override;
private:
	enum Karta::KATEGORIJA category = Karta::KATEGORIJA::BORAC;
	int strength;
	bool activated = false;
};

#endif