#ifndef CAROLIJA_H
#define CAROLIJA_H

#include "Karta.h"


class Carolija:public Karta
{
public:
	Carolija(const string name, int needed_magic_energy);
	Carolija(const Carolija& card) = delete;
	Carolija(Carolija&& card) = delete;
	Carolija& operator=(const Carolija& card) = delete;
	Carolija& operator=(Carolija&& card) = delete;
	KATEGORIJA getCategory() const override;
	//virtual void upotrebi(Igrac& player2) const override;		//BILO JE POTREBNO ZA TESTIRANJE KLASE CAROLIJA, JER JE BEZ OVOGA APSTRAKTNA
	//virtual int getStrength() const override;
private:
	Karta::KATEGORIJA category = Karta::KATEGORIJA::CAROLIJA;
};

#endif