#ifndef CAROBNJAK_H
#define CAROBNJAK_H

#include "Borac.h"

class Carobnjak:public Borac
{
public:
	void upotrebi(Igrac& player1, Igrac& player2) const override;
	string toString() const override;
};

#endif