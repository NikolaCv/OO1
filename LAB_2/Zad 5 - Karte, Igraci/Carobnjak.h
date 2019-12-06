#ifndef CAROBNJAK_H
#define CAROBNJAK_H

#include "Borac.h"

class Carobnjak:public Borac
{
public:
	Carobnjak(const string name, int needed_magic_energy, int strength);//novi konstruktor
	void upotrebi(Igrac& player2) const override;
	string toString() const override;
};

#endif