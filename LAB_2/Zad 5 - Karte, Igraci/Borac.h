#ifndef BORAC_H
#define BORAC_H

#include "Karta.h"

class Borac:public Karta
{
public:
	Borac(const string name, int needed_magic_energy, int strength);
	int getStrength() const override;
	bool operator<(const Borac& fighter);
	bool operator>(const Borac& fighter);
	string toString() const override;
	KATEGORIJA getCategory() const override;
private:
	enum Karta::KATEGORIJA category = Karta::KATEGORIJA::BORAC;
	int strength;
	bool activated = false;
};

#endif