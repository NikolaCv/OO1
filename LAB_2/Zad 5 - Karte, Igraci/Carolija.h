#ifndef CAROLIJA_H
#define CAROLIJA_H

#include "Karta.h"


class Carolija:public Karta
{
public:
	Carolija(const string& name, int needed_magic_energy);
	Carolija(const Carolija& card) = delete;
	Carolija(Carolija&& card) = delete;
	Carolija& operator=(const Carolija& card) = delete;
	Carolija& operator=(Carolija&& card) = delete;
	KATEGORIJA getCategory() const override;
private:
	Karta::KATEGORIJA category = Karta::KATEGORIJA::BORAC;
};

#endif